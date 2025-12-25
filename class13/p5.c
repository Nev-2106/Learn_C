#include <stdio.h>

typedef struct {
    double data[3][3];
} Mat3;

void Mat3_print(Mat3 M) {
    printf("{ ");
    for (int i = 0; i < 3; i++) {
        printf("{ ");
        for (int j = 0; j < 3; j++) {
            printf("%f", M.data[i][j]);
            if (j < 2) printf(", ");
        }
        printf(" }");
        if (i < 2) printf(",\n  ");
    }
    printf(" }\n");
}

void Mat3_mulMat3(Mat3 A, Mat3 B, Mat3 *P) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            P->data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                P->data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
}

int main() {
    Mat3 mat3 = { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } };
    printf("Original Matrix:\n");
    Mat3_print(mat3);
    
    Mat3 A = { { { 2, 1, 5 }, { 2, 10, 5 }, { 3, 1, 4 } } };
    Mat3 B = { { { 8, 7, 1 }, { 4, 2, 7 }, { 2, 3, 5 } } };
    Mat3 P;
    Mat3_mulMat3(A, B, &P);
    printf("Result of A * B:\n");
    Mat3_print(P);
    
    return 0;
}