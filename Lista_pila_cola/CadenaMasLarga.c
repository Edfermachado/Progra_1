#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib_pila.h"
#define MAX 500

void secuenciaBalanceadaMasLarga(char *expresion);

int main(void) {
    char expresion[MAX];
    printf("Ingrese la expresion\n");
    scanf("%s", expresion);

    secuenciaBalanceadaMasLarga(expresion);

    return 0;
}

void secuenciaBalanceadaMasLarga(char *expresion) {
    int longitudMax = 0;
    int inicioMax = -1;
    int longitudActual = 0;
    int inicioActual = -1;
    PILA pila;
    create_p(&pila);

    for (int i = 0; i < strlen(expresion); i++) {
        if (expresion[i] == '(') {
            if (empty_p(&pila)) {
                inicioActual = i;
            }
            push_p(&pila, expresion[i]);
        } else if (expresion[i] == ')') {
            if (empty_p(&pila)) {
                longitudActual = 0;
                inicioActual = -1;
            } else {
                pop_p(&pila);
                longitudActual += 2;
                if (empty_p(&pila)) {
                    if (longitudActual > longitudMax) {
                        longitudMax = longitudActual;
                        inicioMax = inicioActual;
                    }
                }
            }
        }
    }

    if (longitudMax > 0) {
        printf("La secuencia balanceada más larga es: ");
        for (int i = inicioMax; i < inicioMax + longitudMax; i++) {
            printf("%c", expresion[i]);
        }
        printf("\n");
    } else {
        printf("No se encontró ninguna secuencia balanceada.\n");
    }
}
