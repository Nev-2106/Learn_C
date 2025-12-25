#include <stdio.h>

typedef struct {
    double data[3][3];
} Mat3;

typedef struct {
    double data[3][1];
}Vec3;

void Vec3_print(Vec3 V) {
    printf("{ %f, %f, %f }\n", V.data[0][0], V.data[1][0], V.data[2][0]);
}

void Mat3_mulMat3(Mat3 A, Mat3 B, Mat3 *C) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C->data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C->data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
}

void Mat3_mulVec3(Mat3 M, Vec3 V, Vec3 *P) {
    for (int i = 0; i < 3; i++) {
        P->data[i][0] = 0;
        for (int j = 0; j < 3; j++) {
            P->data[i][0] += M.data[i][j] * V.data[j][0];
        }
    }
}

int main() {
    printf("Original vector:\n");
    Vec3 V = {{ 3, 4, 1 }};
    Vec3_print(V);
    
    printf("After scaling:\n");
    Mat3 S = {{ { 3, 0, 0 }, { 0, 2, 0 }, { 0, 0, 1 } }};
    Vec3 SV;
    Mat3_mulVec3(S, V, &SV);
    Vec3_print(SV);
    
    printf("After translation:\n");
    Mat3 T = {{ { 1, 0, 5 }, { 0, 1, 7 }, { 0, 0, 1 } }};
    Vec3 TV;
    Mat3_mulVec3(T, V, &TV);
    Vec3_print(TV);

    printf("After combined transformation (T * S):\n");
    Mat3 TS;
    Mat3_mulMat3(T, S, &TS);
    Vec3 TSV;
    Mat3_mulVec3(TS, V, &TSV);
    Vec3_print(TSV);
    return 0;
}
