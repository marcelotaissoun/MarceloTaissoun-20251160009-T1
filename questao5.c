#include <stdio.h>

int inverterNumero(int n) {
    int invertido = 0;

    while (n != 0) {
        invertido = invertido * 10 + (n % 10);
        n = n / 10;
    }

    return invertido;
}

void testQ5() {
    printf("TESTE 1: 456 -> %d\n", inverterNumero(456));
    printf("TESTE 2: 5430 -> %d\n", inverterNumero(5430));
    printf("TESTE 3: 100 -> %d\n", inverterNumero(100));
    printf("TESTE 4: 7 -> %d\n", inverterNumero(7));
    printf("TESTE 5: 908070 -> %d\n", inverterNumero(908070));
}

int main() {
    testQ5();
    return 0;
}
