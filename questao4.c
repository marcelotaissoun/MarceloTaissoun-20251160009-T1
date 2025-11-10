#include <stdio.h>

char normalizar(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

void encontrarOcorrencias(char texto[], char palavra[]) {
    int i, j, k;
    int t = 0, p = 0;

    while (texto[t] != '\0') t++;

    while (palavra[p] != '\0') p++;

    for (i = 0; i <= t - p; i++) {
        k = i;

        for (j = 0; j < p; j++) {
            if (texto[k] != palavra[j]) break;
            k++;
        }

        if (j == p) {
            printf("Ocorrência encontrada: início %d, fim %d\n", i, i + p - 1);
        }
    }
}

void testQ4() {
    printf("TESTE 1:\n");
    encontrarOcorrencias("banana na banheira", "na");

    printf("\nTESTE 2:\n");
    encontrarOcorrencias("abc abc abc", "abc");

    printf("\nTESTE 3:\n");
    encontrarOcorrencias("AAAAA", "AA");

    printf("\nTESTE 4:\n");
    encontrarOcorrencias("texto sem nada parecido", "xyz");

    printf("\nTESTE 5:\n");
    encontrarOcorrencias("hoje é um bom dia", "dia");
}

int main() {
    testQ4();
    return 0;
}
