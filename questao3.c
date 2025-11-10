#include<stdio.h>

char normalizar(char c) {
    if (c >= 'A' && c <= 'Z')
        c = c + 32;

    if (c == 'á' || c == 'à' || c == 'ã' || c == 'â' || c == 'ä') return 'a';
    if (c == 'é' || c == 'è' || c == 'ê' || c == 'ë') return 'e';
    if (c == 'í' || c == 'ì' || c == 'î' || c == 'ï') return 'i';
    if (c == 'ó' || c == 'ò' || c == 'ô' || c == 'õ' || c == 'ö') return 'o';
    if (c == 'ú' || c == 'ù' || c == 'û' || c == 'ü') return 'u';
    if (c == 'ç') return 'c';

    return c;
}

int contarLetra(char texto[], char letra) {
    int i = 0, cont = 0;
    char alvo = normalizar(letra);

    while (texto[i] != '\0') {
        if (normalizar(texto[i]) == alvo)
            cont++;
        i++;
    }

    return cont;
}

void testQ3() {
    printf("TESTE 1:\n");
    printf("Resultado: %d\n", contarLetra("O Vitória ganhou hoje", 'a'));

    printf("\nTESTE 2:\n");
    printf("Resultado: %d\n", contarLetra("Renato me passou um trabalho", 'a'));

    printf("\nTESTE 3:\n");
    printf("Resultado: %d\n", contarLetra("FÉRIAS NO NORDESTE", 'e'));

    printf("\nTESTE 4:\n");
    printf("Resultado: %d\n", contarLetra("O rato roeu a roupa do rei de Roma", 'o'));

    printf("\nTESTE 5:\n");
    printf("Resultado: %d\n", contarLetra("Texto sem nada parecido", 'x'));
}

int main() {
    testQ3();
    return 0;
}
