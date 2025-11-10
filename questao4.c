#include <stdio.h>
#include <ctype.h>

char normalizar(char c) {
    c = tolower(c);
    if (c == 'á' || c == 'à' || c == 'ã' || c == 'â') return 'a';
    if (c == 'é' || c == 'ê') return 'e';
    if (c == 'í') return 'i';
    if (c == 'ó' || c == 'õ' || c == 'ô') return 'o';
    if (c == 'ú') return 'u';
    return c;
}

void testQ4() {
    printf("Testes da busca de palavra:\n");

    struct caso {
        char texto[251];
        char palavra[251];
    };

    struct caso testes[] = {
        {"Programacao em C", "cao"},
        {"Programacao em C", "cão"},
        {"Banana madura", "na"},
        {"Computação é massa", "cao"},
        {"Computação é massa", "ção"},
        {"Teste simples", "zzz"},
        {"aaaaa", "aa"},
        {"Casa com acento: maçã", "maca"},
        {"", "ola"},
        {"Texto normal", ""}
    };

    int total = sizeof(testes) / sizeof(testes[0]);

    for (int t = 0; t < total; t++) {
        printf("Teste %d:\n", t + 1);
        printf("Texto: \"%s\"\n", testes[t].texto);
        printf("Palavra: \"%s\"\n", testes[t].palavra);

        int achou_algum = 0;

        int i, j, k, achou;

        for (i = 0; testes[t].palavra[i] != '\0'; i++) {
            if (testes[t].palavra[i] == '\n') {
                testes[t].palavra[i] = '\0';
                break;
            }
        }

        for (i = 0; testes[t].texto[i] != '\0'; i++) {
            achou = 1;
            for (j = 0; testes[t].palavra[j] != '\0'; j++) {
                if (normalizar(testes[t].texto[i + j]) != normalizar(testes[t].palavra[j])) {
                    achou = 0;
                    break;
                }
            }

            if (achou && testes[t].palavra[0] != '\0') {
                printf("  Achou da pos %d ate %d\n", i + 1, i + j);
                achou_algum = 1;
            }
        }

        if (!achou_algum) {
            printf("  Nenhuma ocorrencia encontrada.\n");
        }
    }

    printf("Fim dos testes.\n");
}

int main() {
    testQ4();
    return 0;
}
