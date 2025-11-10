#include<stdio.h>

#include "marcelotaissoun20251160009.h"

int ano_bissexto(int ano) {
    if (ano % 400 == 0) return 1;
    if (ano % 100 == 0) return 0;
    if (ano % 4 == 0) return 1;
    return 0;
}

int dias_no_mes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ano_bissexto(ano) ? 29 : 28;
    }
    return 0;
}

int validar(int diaa, int mess, int anoo) {
    if (anoo < 1) return 0;
    if (mess < 1 || mess > 12) return 0;
    if (diaa < 1 || diaa > dias_no_mes(mess, anoo)) return 0;
    return 1;
}

void testQ1() {
    printf("Testes da funcao validar:\n");

    printf("01) 10/10/2020: %s\n", validar(10,10,2020) ? "1" : "0");
    printf("02) 29/02/2020 (bissexto): %s\n", validar(29,2,2020) ? "1" : "0");
    printf("03) 31/12/1999: %s\n", validar(31,12,1999) ? "1" : "0");

    printf("04) 31/02/2021: %s\n", !validar(31,2,2021) ? "1" : "0");
    printf("05) 29/02/2021 (nao bissexto): %s\n", !validar(29,2,2021) ? "1" : "0");
    printf("06) mes 13: %s\n", !validar(10,13,2020) ? "1" : "0");
    printf("07) dia 0: %s\n", !validar(0,5,2020) ? "1" : "0");
    printf("08) ano 0: %s\n", !validar(10,10,0) ? "1" : "0");
    printf("09) dia maior que o mes permite: %s\n", !validar(31,4,2020) ? "1" : "0");

    printf("Fim dos testes.\n\n");
}

int main() {
    testQ1();
    return 0;
}
