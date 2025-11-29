#include <stdio.h>
#include <string.h>

int main() {
    int chuva[12];
    char meses[12][20] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    printf("Digite a chuva de cada mes: ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }

   
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (chuva[j] > chuva[i]) {  
                int temp = chuva[i];
                chuva[i] = chuva[j];
                chuva[j] = temp;

                char tempMes[20];
                strcpy(tempMes, meses[i]);
                strcpy(meses[i], meses[j]);
                strcpy(meses[j], tempMes);
            }
        }
    }

 
    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i], chuva[i]);
    }

    return 0;
}
