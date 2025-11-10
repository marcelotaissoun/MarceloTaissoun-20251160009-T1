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

void testar_datas() {
    printf("Testando ano_bissexto:\n");

    printf("1) 2000 (bissexto): %s\n", ano_bissexto(2000) ? "1" : "0");
    printf("2) 1900 (nao bissexto): %s\n", !ano_bissexto(1900) ? "1" : "0");
    printf("3) 2020 (bissexto): %s\n", ano_bissexto(2020) ? "1" : "0");
    printf("4) 2021 (nao bissexto): %s\n", !ano_bissexto(2021) ? "1" : "0");

    printf("\nTestando dias_no_mes:\n");

    printf("5) Janeiro 2023 = 31: %s\n", dias_no_mes(1,2023) == 31 ? "1" : "0");
    printf("6) Fevereiro 2020 (bissexto) = 29: %s\n", dias_no_mes(2,2020) == 29 ? "1" : "0");
    printf("7) Fevereiro 2021 (normal) = 28: %s\n", dias_no_mes(2,2021) == 28 ? "1" : "0");
    printf("8) Abril 2022 = 30: %s\n", dias_no_mes(4,2022) == 30 ? "1" : "0");
    printf("9) Mes invalido = 0: %s\n", dias_no_mes(15,2022) == 0 ? "1" : "0");

    printf("\nFim dos testes.\n");
}

int main() {
    testar_datas();
    return 0;
}
