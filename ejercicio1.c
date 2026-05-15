#include <stdio.h>

int potencia(int base, int exp) {
    int resultado = 1;


    while (exp > 0) {
        resultado = resultado * base;
        exp--;
    }

    return resultado;

}

int es_par(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;

    }
}

int main(void) {

    int base; // En esta variable se guarda la base
    int exp; // Variable para guardar exponente
    int resultado; // 

    do {
       printf("Ingresar base distinta de 0: ");
       scanf("%d", &base); //pide una base al ususario, %d significa entero 

       if (base == 0) {  // revisa si la base no es valida
           printf("error: base no puede ser 0.\n");
       } // muestra un error si se ingresa 0

    } while (base == 0); // se repte hasta que se ingrese una base valida

    do {
        printf("Ingresar un exponente positivo: ");
        scanf("%d", &exp);

        if (exp < 0) {   // muestra error cuando se ingresa exp negativo
            printf("error: exponente no puede ser negativo.\n");

        }

    } while (exp < 0);

    resultado = potencia(base, exp);

    printf("resultado: %d\n", resultado);

    if (es_par(resultado)) {
        printf("Resultado es par.\n");

    } else {
        printf("resultado es impar.\n");

} 

    return 0;

} 
