#include <stdio.h>

char *rot13(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = ((s[i] - 'a' + 13) % 26) + 'a';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = ((s[i] - 'A' + 13) % 26) + 'A';
        }
    }
    return s;
}

int main()
{
    char s[] =
	"Fvzcyvpvgl naq ryrtnapr ner hacbchyne orpnhfr gurl erdhver uneq jbex naq "
	"qvfpvcyvar gb npuvrir naq rqhpngvba gb or nccerpvngrq. -- Rqftre Qvwxfgen";
    printf("%s\n", rot13(s));
    return 0;
}
