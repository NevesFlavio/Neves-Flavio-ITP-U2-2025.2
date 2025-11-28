#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char aluno[20];
    char linha[1000];
    printf("Digite o nome do aluno e a sua frequencia: ");              // Lê o nome do aluno e as datas de presença
    scanf("%s", aluno);

    scanf(" %[^\n]", linha);

    int faltas = 0;

    int i = 0, len = strlen(linha);

    while (i < len)
    {

        if (i + 4 >= len)
            break;

        char data[6];
        strncpy(data, linha + i, 5);
        data[5] = '\0';

        i += 5;

        if (i < len && linha[i] == ' ')
            i++;

        int presente = 0;

        while (i < len)
        {

            if (isdigit(linha[i]) &&
                i + 4 < len &&
                isdigit(linha[i + 1]) &&
                linha[i + 2] == '/' &&
                isdigit(linha[i + 3]) &&
                isdigit(linha[i + 4]))
            {

                break;
            }

            char nome[20];
            int j = 0;

            while (i < len && linha[i] != ' ' && j < 19)
            {
                nome[j++] = linha[i++];
            }

            nome[j] = '\0';

            if (strcmp(nome, aluno) == 0)
            {
                presente = 1;
            }

            if (i < len && linha[i] == ' ')
                i++;
        }

        if (!presente)
            faltas++;
    }

    printf("%d\n", faltas);

    return 0;
}
