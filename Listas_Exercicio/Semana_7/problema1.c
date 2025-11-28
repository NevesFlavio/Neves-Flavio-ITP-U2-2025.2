#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20                                              // Tamanho definido
#define BOMBAS 10                                           // Quantidade de bombas

void gerarCampo(char campo[TAM]) {
    
    for (int i = 0; i < TAM; i++) {
        campo[i] = '.';
    }

    
    int colocadas = 0;                                      // Mesmo esquema do meu projeto, pra gerar as bombas aleatórias
    while (colocadas < BOMBAS) {
        int pos = rand() % TAM;
        if (campo[pos] == '.') {
            campo[pos] = 'x';
            colocadas++;
        }
    }
}

void esconderCampo(char oculto[TAM]) {
    for (int i = 0; i < TAM; i++) {
        oculto[i] = '-';
    }
}

void mostrar(char vetor[TAM]) {
    for (int i = 0; i < TAM; i++) {
        printf("%c ", vetor[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char campo[TAM];   
    char oculto[TAM];  

    gerarCampo(campo);
    esconderCampo(oculto);

    int jogoAtivo = 1;
    int jogadasSeguras = 0;

    printf("**** CAMPO MINADO 1D ****\n");

    while (jogoAtivo) {
        printf("\nCampo atual: ");
        mostrar(oculto);

        printf("Escolha uma posicao (0 a %d): ", TAM - 1);
        int pos;
        scanf("%d", &pos);

        if (pos < 0 || pos >= TAM) {
            printf("Posicao invalida!\n");
            continue;
        }

        if (oculto[pos] != '-') {
            printf("Voce ja jogou nessa posicao!\n");
            continue;
        }

        if (campo[pos] == 'x') {
            printf("\nBUM!!! MORREUU!\n");
            printf("Campo real era: ");
            mostrar(campo);
            jogoAtivo = 0;
        } else {
            oculto[pos] = '.';
            jogadasSeguras++;

            if (jogadasSeguras == TAM - BOMBAS) {
                printf("\nParabéns! Infelizmente, você ganhou! \n");
                printf("Campo real era: ");
                mostrar(campo);
                jogoAtivo = 0;
            }
        }
    }

    return 0;
}