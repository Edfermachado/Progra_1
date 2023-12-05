#include <stdio.h>

void Parentesis(char combinacion[], int apertura, int cierre, int n);
void imprimirCombinaciones(char combinacion[], int n);

int main(void) {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    char combinacion[2 * n + 1];
    Parentesis(combinacion, 0, 0, n);

    return 0;
}

void Parentesis(char combinacion[], int apertura, int cierre, int n){
   	//Las alternativas vienen inicializadas desde la primera llamada

	//Si es solucion
	if(cierre == n){
        imprimirCombinaciones(combinacion, 2 * n);
        return;
    }

	//Y las siguientes alternativas vienen dadas por las llamadas posteriores
	/*El borrar paso se omite ya que si una llamada pone un parentesis y por ahí no hay solucion lo quita
	cuando termina la llamada */
    if (apertura < n){
        combinacion[apertura + cierre] = '(';
        Parentesis(combinacion, apertura + 1, cierre, n);
    }

    if (apertura > cierre){
        combinacion[apertura + cierre] = ')';
        Parentesis(combinacion, apertura, cierre + 1, n);
    }
}

void imprimirCombinaciones(char combinacion[], int n){
    combinacion[n] = '\0';
    printf("%s\n", combinacion);
}
