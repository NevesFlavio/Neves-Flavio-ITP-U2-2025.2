#include <stdio.h>

int main() {
    int n;

    printf("Digite a quantidade de pilotos: ");
    scanf("%d", &n);

    int largada[21], chegada[21];
    int posLargada[21];  
    
    printf("Digite a ordem de largada: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &largada[i]);
        posLargada[ largada[i] ] = i;  
    }

    printf("Digite a ordem de chegada: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &chegada[i]);
    }

    int melhorGanho = 0;
    int melhorPiloto = -1;
    int empate = 0;

    
    for (int posChegada = 1; posChegada <= n; posChegada++) {
        int piloto = chegada[posChegada];
        int posInicial = posLargada[piloto];

        int ganho = posInicial - posChegada;  

        if (ganho > melhorGanho) {
            melhorGanho = ganho;
            melhorPiloto = piloto;
            empate = 0;  
        } 
        else if (ganho == melhorGanho && ganho > 0) {
            empate = 1; 
        }
    }

    if (melhorGanho <= 0 || empate)
        printf("empate\n");
    else
        printf("%d\n", melhorPiloto);

    return 0;
}
