#include <stdio.h>
#include <math.h>
#define MAX_SENSORES 10

typedef enum { NORMAL, ALERTA, FALLO } EstadoSensor;

typedef struct {
    int   id;
    float valor;
    EstadoSensor estado;
} Lectura;

EstadoSensor clasificar(float valor);
int          contar_estado(Lectura s[], int n, EstadoSensor e);
int          lectura_extrema(Lectura s[], int n);

EstadoSensor clasificar(float valor) {

    if (valor >= 40.0 && valor <= 60.0) { // verifica si el valor esta en un rango normal
        return NORMAL;

    }

    else if ((valor >= 20.0 && valor < 40.0) ||

             (valor > 60.0 && valor <= 80.0)) {  // verifica si el valor esta en un rango de alerta
        return ALERTA;

    }

    else {

        return FALLO;  // si no cumple con lo anterior es un fallo

    }
}


    // vamos a contar sensores segun el estado

int contar_estado(Lectura lecturas[], int n, EstadoSensor e) {

    int i;
    int contador = 0;

    // Recorrer lecturas

    for (i = 0; i < n; i++) {

        // Verificamos si el estado coincide

        if (lecturas[i].estado == e) {

            contador++;

        }

    }
    return contador;
}


// funcion para  encontrar la lectura mas alejada de 50
int lectura_extrema(Lectura lecturas[], int n) {

    int i;
    int indice = 0;

    float mayor_distancia =
        fabs(lecturas[0].valor - 50.0);

    // recorrer todas llas lecturas

    for (i = 1; i < n; i++) {

        float distancia =

            fabs(lecturas[i].valor - 50.0);

        // verifica si la distancia actual es mayor
        if (distancia > mayor_distancia) {

            mayor_distancia = distancia;

            indice = i;

        }
    }
    return indice;

}


int main(void) {
    // su implementacion

    Lectura lecturas[MAX_SENSORES];

    int i;

    // leer datos de sensores

    for (i = 0; i < MAX_SENSORES; i++) {

        printf("Ingresar ID del sensor %d: ", i + 1);
        scanf("%d", &lecturas[i].id);

        printf("Ingrese valor del sensor %d: ", i + 1);
        scanf("%f", &lecturas[i].valor);
    }


        // clasificar e sensor automaticamente

        lecturas[i].estado = clasificar(lecturas[i].valor);


    // vamos a imprimir la tabla de resultados

    printf("\nTabla de lecturas:\n");
    printf("ID\tValor\tEstado\n");

    for (i = 0; i < MAX_SENSORES; i++) {

        printf("%d\t%.2f\t", lecturas[i].id, lecturas[i].valor);

        if (lecturas[i].estado == NORMAL) {

            printf("NORMAL");

        }

        else if (lecturas[i].estado == ALERTA) {

            printf("ALERTA");

        }

        else {
            printf("FALLO");

        }
        printf("\n");
    }

    // imprimir cantidaad de sensores por estado

    printf("\nCantidad de sensores NORMAL: %d\n",
        contar_estado(lecturas, MAX_SENSORES, NORMAL));

    printf("Cantidad de sensores ALERTA: %d\n",
        contar_estado(lecturas, MAX_SENSORES, ALERTA));

    printf("Cantidad de sensores FALLO: %d\n",
        contar_estado(lecturas, MAX_SENSORES, FALLO));

    int extrema;

    extrema = lectura_extrema(lecturas, MAX_SENSORES);

    printf("\nLectura mas extrema:\n");
    printf("ID: %d\n", lecturas[extrema].id);
    printf("Valor: %.2f\n", lecturas[extrema].valor);
    return 0;
}
