#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include "marcelotaissoun20251160009.h"

char normalizar(char c) {
    c = tolower(c);

    if (c == 'á' || c == 'à' || c == 'ã' || c == 'â') return 'a';
    if (c == 'é' || c == 'ê') return 'e';
    if (c == 'í') return 'i';
    if (c == 'ó' || c == 'õ' || c == 'ô') return 'o';
    if (c == 'ú') return 'u';

    return c;
}

void testQ3() {
    printf("Testes da funcao normalizar:\n");

    printf("1) 'a' -> a: %s\n", normalizar('a') == 'a' ? "OK" : "ERRO");
    printf("2) 'Á' -> a: %s\n", normalizar('Á') == 'a' ? "OK" : "ERRO");
    printf("3) 'ã' -> a: %s\n", normalizar('ã') == 'a' ? "OK" : "ERRO");
    printf("4) 'Ê' -> e: %s\n", normalizar('Ê') == 'e' ? "OK" : "ERRO");
    printf("5) 'é' -> e: %s\n", normalizar('é') == 'e' ? "OK" : "ERRO");
    printf("6) 'Í' -> i: %s\n", normalizar('Í') == 'i' ? "OK" : "ERRO");
    printf("7) 'õ' -> o: %s\n", normalizar('õ') == 'o' ? "OK" : "ERRO");
    printf("8) 'Ú' -> u: %s\n", normalizar('Ú') == 'u' ? "OK" : "ERRO");

    printf("9) 'b' -> b (sem acento mesmo): %s\n", normalizar('b') == 'b' ? "OK" : "ERRO");
    printf("10) '?' -> ? (não altera): %s\n", normalizar('?') == '?' ? "OK" : "ERRO");

    printf("\nFim dos testes.\n");
}

int main() {
    char texto[251] = "Programação é incrível e especial";
    char letra = "a";
    int i, cont = 0;

    letra = normalizar(letra);

    for (i = 0; texto[i] != '\0'; i++) {
        if (normalizar(texto[i]) == letra) {
            cont++;
        }
    }

    printf("Quantidade de '%c' normalizado no texto: %d\n", letra, cont);
  
    return 0;
}
