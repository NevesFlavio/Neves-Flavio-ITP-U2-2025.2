#include <stdio.h>

int main() {
    int m, n;

    printf("Digite a quantidade de dezenas apostadas e a quanidade de dezenas sorteadas, separadas por um espaco: ");
    scanf("%d %d", &m, &n);                                                                                                            // Lê a quantidade de dezenas apostadas e a quantidade de dezenas sorteadas

    int sorteadas[m];
    int aposta[n];

    printf("Digite as dezenas apostadas: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &sorteadas[i]);

    printf("Digite as dezenas soerteadas: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &aposta[i]);

    
    int acertos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (aposta[i] == sorteadas[j]) {
                acertos++;
                break;
            }
        }
    }

    printf(" Voce acertou: %d\n", acertos);

    return 0;
}
