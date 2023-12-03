#include <stdio.h>
#include <stdbool.h>
#define MAX 500
#define FILA 5
#define COLUMNA 5
void print_laberinto(char laberinto[][COLUMNA]);
void buscar_camino(char laberinto[][COLUMNA],int fila, int columna, bool *solucion);


int main(void){;
	char laberinto[FILA][COLUMNA] = {{'0','0','0','#','S'},
		    			{'0','#','#','#','0'},
		    			{'0','0','0','#','0'},
		    			{'0','#','0','0','0'},
					{'0','#','0','0','0'}
					};
	printf("El laberinto insertado es:\n");
	print_laberinto(laberinto);
	bool solucion = false;
	buscar_camino(laberinto, 4, 0, &solucion);

return 0;
}

void buscar_camino(char laberinto[][COLUMNA], int fila, int columna, bool *solucion){

		//Inicializar_alternativa
		
		if(fila>=0 && fila< FILA && columna >= 0 && columna<COLUMNA && laberinto [fila][columna]!= '#'){
		//alternativa_valida
		if(laberinto[fila][columna]=='0' || laberinto[fila][columna] == 'S'){
		//Almacenar_paso
			if(laberinto[fila][columna] != 'S'){
			laberinto[fila][columna] = 'C';
			}
			//Es_solucion
			if(laberinto[fila][columna]=='S'){
			*solucion = true;
			laberinto[fila][columna] = 'E';
			printf("La solucion del laberinto es:\n");
			print_laberinto(laberinto);
			}else{
				buscar_camino(laberinto, fila+1, columna, solucion);
				buscar_camino(laberinto, fila, columna+1, solucion);
				buscar_camino(laberinto, fila-1, columna, solucion);
				buscar_camino(laberinto, fila, columna-1, solucion);
				if(!(*solucion)){
					laberinto[fila][columna] = '0';
				}
			}
		}

			}
}


void print_laberinto(char laberinto[][COLUMNA]){

	int i, j;
	printf("\n");
	for(i=0;i<FILA;i++){
		for(j=0;j<COLUMNA;j++){
			printf("%c ",laberinto[i][j]);
			}
			printf("\n");
		}
	printf("\n");
}
