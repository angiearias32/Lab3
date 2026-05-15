#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

int contar_unos_fila(int m[][SIZE], int fila);
int contar_unos_columna(int m[][SIZE], int col);
int es_identidad(int m[][SIZE]);
int tiene_fila_completa(int m[][SIZE]);
int tiene_columna_completa(int m[][SIZE]) ;

int main(void) {    // programa principal que trabaja con matrices binarias
    int m[SIZE][SIZE] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    // su implementacion

    int aleatoria[SIZE][SIZE];  // busca una matriz aleatoria para imprimir

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {


        for (int j = 0; j < SIZE ; j++) {

            aleatoria[i][j] = rand() % 2;

        }

    }

    printf("Matriz ingresada:\n");

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {


            printf("%d ", m[i][j]);

        }

        printf("\n");

    }

    if (es_identidad(m)) {

        printf("Es la matriz identidad: si\n");

    } else {

        printf("Es la matriz identidad: no\n");

    }

    if (tiene_fila_completa(m)) {

        printf("Tiene fila completa de unos: si\n");

    } else {

        printf("Tiene fila completa de unos: no\n");

    }

    if (tiene_columna_completa(m)) {

        printf("Tiene columna completa de unos: si\n");

    } else {

        printf("Tiene columna completa de unos: no\n");

    }


    printf("\ncantidad de unos en fila 0: %d\n",
           contar_unos_fila(m, 0));

    printf("cantidad de unos en columna 0: %d\n",
           contar_unos_columna(m, 0));  

    printf("\nMatriz aleatoria:\n");

    for (int i = 0; i < SIZE ; i++) {

        for (int j = 0; j < SIZE; j++) {

            printf("%d ", aleatoria[i][j]);

        }

        printf("\n");

    }

    return 0 ;
}

int contar_unos_fila(int m[][SIZE], int fila) {  // cuenta la ccantidad de unos presentes en las  filas

    int contador = 0;

    for (int i = 0;  i < SIZE; i++) {

        if (m[fila][i] == 1) {
            contador++;

        }

    }
    return contador;

}


int contar_unos_columna(int m[][SIZE], int col) {  // cuenta la cantidad de unos presentes en las columnas

    int contador = 0;

    for (int i = 0; i < SIZE; i++) {

        if (m[i][col] == 1) {

            contador++;

        }

    }

    return contador;

}

int es_identidad(int m[][SIZE]) {  // revissa si la  matriz es una atrriz identidad

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            if (i == j && m[i][j] != 1) {
                return 0;
            }

            if (i != j && m[i][j] != 0) {
                return 0;
            }

        }

    }

    return 1;

}


int tiene_fila_completa(int m[][SIZE]) {  // comprueba si al menos una fila esta compuesta por solo unos

    for (int i = 0; i < SIZE; i++) {

        int completa = 1;

        for (int j = 0; j < SIZE ; j++) {

            if (m[i][j] != 1) {

                completa = 0;

            }

        }

        if (completa == 1) {
            return 1;

        }
    }

    return 0;

} 


int tiene_columna_completa(int m[][SIZE]) {  // compureba si al menos una columna esta compuesta por unos

    for (int j = 0; j < SIZE; j++) {

        int completa = 1;

        for (int i = 0; i < SIZE; i++) {

            if (m[i][j] != 1) {

                completa = 0;

            }

        }

        if (completa == 1) {

            return 1;

        }
    }

    return 0; 

}
