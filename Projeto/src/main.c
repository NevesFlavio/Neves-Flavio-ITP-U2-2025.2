#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inicializarJogo(int lin, int col, char mapa[lin][col]) {               //Função de inicializar o mapa
    for (int i = 1; i < lin; i++) {
        for (int j = 1; j < col; j++) {
            mapa[i][j] = '-';  
        }
    }
}

void mostrarJogo(int lin, int col, char mapa[lin][col]) {                   //Função de mostrar o mapa para o usuário
    printf("    ");
    for (int j = 1; j < col; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 1; i < lin; i++) {
        printf("%2d  ", i);
        for (int j = 1; j < col; j++) {
            printf("%2c ", mapa[i][j]);
        }
        printf("\n");
    }
}

void colocarMinas(int lin, int col, int minas[lin][col]) {                //Função de colocar as minas - em construção
    for (int i = 1; i < lin; i++) {
        for (int j = 1; j < col; j++) {
            minas[i][j] = 0; 
        }
    }
}

void gerarMinas(int lin, int col, int minas[lin][col], int qtd) {           //Função de gerar as minas - em construção
    srand(time(NULL));                                                      
    int colocadas = 0;  

    while (colocadas < qtd) {
        int x = rand() % (lin-1) + 1;
        int y = rand() % (col-1) + 1;
        if (minas[x][y] == 0) {
            minas[x][y] = 1;
            colocadas++;
        }
    }
}

int main() {
    int lin, col;
    int opcao;

do                                                                          //Estrutura para o menu de dificuldade
    {
    printf("Escolha o nivel de dificuldade:\n");
    printf("1 - Basico (9x9)\n");
    printf("2 - Intermediario (16x16)\n");
    printf("3 - Avancado (24x24)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    
        if (opcao == 1) {                                                   //Tamanho do básico 9x9
        lin = 10;
        col = 10;
    } else if (opcao == 2) {                                                //Tamanho do intermediário 16x16
        lin = 17;
        col = 17;
    } else if (opcao == 3)                                                  //Tamanho do avançado 24x24
    {
        lin = 25;
        col = 25;
    } else {
        printf("Opcao invalida. Escolha novamente:\n");
       
    }
    
    } while (opcao != 1 && opcao != 2 && opcao != 3);                       //Tratamento para só continuar se escolher uma das opções corretas
    
    

  
    char mapa[lin][col];
    int minas[lin][col];

    inicializarJogo(lin, col, mapa);
    colocarMinas(lin, col, minas);
    mostrarJogo(lin, col, mapa);

    return 0;
}
