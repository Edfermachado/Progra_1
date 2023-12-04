#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500

void CrearMatriz(char Matriz[MAX][MAX],int n, int m){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			Matriz[i][j] = '0';
			}
		}


}

void Fila_Columna(char Matriz[MAX][MAX], int *fila, int *columna){
	int i;
	i = 0;
	*fila = 0;
	*columna = 0;

	for(i=0;i<MAX;i++){
		if(Matriz[i][0] == '0'){
			(*fila)++;
			}
	}
	for(i=0;i<MAX;i++){
		if(Matriz[0][i] == '0'){
			(*columna)++;
			}
	}


}
void ImprimirMatriz(char Matriz[MAX][MAX], int fila, int columna){
		int i, j;
		for(i=0; i<fila; i++){
			for(j=0; j<columna; j++){

				printf("%c ", Matriz[i][j]);
				}
			printf("\n");
			}
	printf("\n");
}

void Inicializar(char Matriz[MAX][MAX],int n, int m, char *elemento){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			Matriz[i][j] = *elemento;
			}
		}


}

void RandomMatriz(char Matriz[MAX][MAX], int n, int m){

	int i, j;
	srand(time(NULL));

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//Mayusculas
			//Matriz[i][j] = (char)(rand()%26+65);
			//Minusculas
			Matriz[i][j] = (char)(rand()%26+97);
			}
		}
}
