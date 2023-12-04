#ifndef FUNC_MATRIZ_H
#define FUNC_MATRIZ_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500

void CrearMatriz(char Matriz[MAX][MAX],int n, int m);
void Fila_Columna(char Matriz[MAX][MAX], int *fila, int *columna);
void ImprimirMatriz(char Matriz[MAX][MAX], int fila, int columna);
void Inicializar(char Matriz[MAX][MAX],int n, int m, char *elemento);
void RandomMatriz(char Matriz[MAX][MAX], int n, int m);

#endif