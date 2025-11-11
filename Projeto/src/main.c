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

void gerarMinas(int lin, int col, int minas[lin][col], int qtd) {           //Função de gerar as minas usando 'srand' para gerá-los de forma aleatória
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

int contarMinasAdjacentes(int i, int j, int lin, int col, int minas[lin][col]) { 
    int cont = 0;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 1 && x < lin && y >= 1 && y < col && minas[x][y] == 1) {
                cont++;
            }
        }
    }
    return cont;
}

int revelarCelula(int i, int j, int lin, int col, char mapa[lin][col], int minas[lin][col]) {
    if (i < 1 || i >= lin || j < 1 || j >= col) {
        return 0;
    }
    if (mapa[i][j] != '-') {
        return 0;
    }
    if (minas[i][j] == 1) {
        mapa[i][j] = '*';
        return;
    }
    int adj = contarMinasAdjacentes(i, j, lin, col, minas);
    mapa[i][j] = adj + '0';

    if (adj == 0) {
        for (int x = i - 1; x <= i + 1; x++) {
            for (int y = j - 1; y <= j + 1; y++) {
                if (x != i || y != j) {
                    revelarCelula(x, y, lin, col, mapa, minas);
                }
            }
        }
    }
}

void lerJogada(int *linha, int *coluna, int linMax, int colMax) {           //Função de ler a jogada do usuário
    do {
        printf("Digite o numero da linha: ");
        scanf("%d", linha);
        printf("Digite o numero da coluna: ");
        scanf("%d", coluna);

        if (*linha < 1 || *linha > linMax || *coluna < 1 || *coluna > colMax) {
            printf("Jogada invalida. Tente novamente.\n");
        }
    } while (*linha < 1 || *linha > linMax || *coluna < 1 || *coluna > colMax);
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
    int qtdMinas = (opcao == 1 ? 10 : (opcao == 2 ? 40 : 99));
    int linhaJog, colunaJog;                                                      //Quantidade de minas para cada dificuldade - 10, 40, 99.

    inicializarJogo(lin, col, mapa);
    colocarMinas(lin, col, minas);
    gerarMinas(lin, col, minas, qtdMinas);                                  //Chamada da função de gerar minas, 10;
    mostrarJogo(lin, col, mapa);
    lerJogada(&linhaJog, &colunaJog, lin, col);

    return 0;
    
}
