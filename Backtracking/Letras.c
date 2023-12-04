#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "func_matriz.h"
#define MAX 500


bool esValido(int x, int y, int fila, int col);;
bool buscarSecuencia(char matriz[MAX][MAX],char solucion[MAX][MAX], char* secuencia, int x, int y, int index, int fila, int col);
void encontrarSecuencia(char matriz[MAX][MAX], char solucion[MAX][MAX], char* secuencia, int tam_fila, int tam_col);
int main(void){
	char letras[MAX][MAX];
	char solucion[MAX][MAX];
	char secuencia[MAX];
	int fila, columna;
	printf("Ingrese la cantidad de filas: ");
	scanf("%d", &fila);

	printf("Ingrese la cantidad de columnas: ");
	scanf("%d", &columna);
	CrearMatriz(solucion, fila, columna);
	CrearMatriz(letras, fila, columna);
	RandomMatriz(letras, fila, columna);
	ImprimirMatriz(letras, fila, columna);
	printf("Ingrese la secuencia a buscar\n");
	scanf("%s", &secuencia);
	encontrarSecuencia(letras,solucion, secuencia, fila, columna);

    return 0;
}
bool esValido(int x, int y, int fila, int col){
    return (x >= 0 && x < fila && y >= 0 && y < col);
}

bool buscarSecuencia(char matriz[MAX][MAX],char solucion[MAX][MAX], char* secuencia, int x, int y, int index, int fila, int col){
    if (index == strlen(secuencia)){
        return true;
    }

    if(esValido(x, y, fila, col) && matriz[x][y] == secuencia[index]){
	solucion[x][y] = secuencia[index];
        char temp = matriz[x][y];
        matriz[x][y] = '#';

        bool encontrado = buscarSecuencia(matriz,solucion, secuencia, x + 1, y, index + 1, fila, col) ||
                          buscarSecuencia(matriz,solucion, secuencia, x - 1, y, index + 1, fila, col) ||
                          buscarSecuencia(matriz,solucion, secuencia, x, y + 1, index + 1, fila, col) ||
                          buscarSecuencia(matriz,solucion, secuencia, x, y - 1, index + 1, fila, col);
        matriz[x][y] = temp;

        return encontrado;
    }

    return false;
}

void encontrarSecuencia(char matriz[MAX][MAX], char solucion[MAX][MAX], char* secuencia, int tam_fila, int tam_col){
    bool encontrado = false;

    for(int i = 0; i < tam_fila; i++){
        for(int j = 0; j < tam_col; j++){
            if(matriz[i][j] == secuencia[0]){
		solucion[i][j] = secuencia[0];
                encontrado = buscarSecuencia(matriz,solucion,secuencia, i, j, 0, tam_fila, tam_col);
                if(encontrado){
                    ImprimirMatriz(solucion, tam_fila, tam_col);
                    return;
                }
            }
        }
    }

    printf("La secuencia no esta en la matriz\n");
}
