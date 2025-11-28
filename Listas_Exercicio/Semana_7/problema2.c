#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ehBrasileiro(const char *p) {
    
    if (strlen(p) != 8)
        return 0;

    return (isupper(p[0]) && isupper(p[1]) && isupper(p[2]) &&
            p[3] == '-' &&
            isdigit(p[4]) && isdigit(p[5]) && isdigit(p[6]) && isdigit(p[7]));
}

int ehMercosul(const char *p) {
   
    if (strlen(p) != 7)
        return 0;

    return (isupper(p[0]) && isupper(p[1]) && isupper(p[2]) &&
            isdigit(p[3]) &&
            isupper(p[4]) &&
            isdigit(p[5]) && isdigit(p[6]));
}

int main() {
    char placa[20];
    printf("Digite a placa (formato brasileiro (LLL-AAAA) ou mercosul (LLLALAA): ");
    scanf("%s", placa);

    if (ehBrasileiro(placa)) {
        printf("brasileiro\n");
    } else if (ehMercosul(placa)) {
        printf("mercosul\n");
    } else {
        printf("invalido\n");
    }

    return 0;
}
