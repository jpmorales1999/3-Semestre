#include <stdio.h>
#include <stdlib.h>

void pedirdatos();
void mostrarDatos(int **, int, int);

int numFilas, numColumnas, **p_matriz;

int main()
{
    int i;
    pedirdatos();
    mostrarDatos(p_matriz, numFilas, numColumnas);
    for(i=0; i<numColumnas; i++){
        free(*(p_matriz+i));
    }
    free(p_matriz);

    return 0;
}

void pedirdatos(){
    printf("Ingrese la cantidad de filas\n");
    scanf("%d",&numFilas);
    printf("Ingrese la cantidad de columnas\n");
    scanf("%d",&numColumnas);

    p_matriz = (int**)malloc(numFilas*sizeof(int *));
    for(int i=0; i<numColumnas; i++){
        p_matriz[i] = (int *)malloc(numColumnas * sizeof(int));
    }
    if(p_matriz==NULL){
        printf("Error reservando memoria\n");
        exit(0);
    }else{
        printf("Llenando matriz aleatoriamente\n");
        for(int f=0; f<numFilas; f++){
            for(int c=0; c<numColumnas; c++){
                (*(*(p_matriz+f)+c)) = rand()%100;
            }
        }
    }
}

void mostrarDatos(int **p_matriz, int numFilas, int numColumnas){
    printf("Mostrando matriz\n");
     for(int f=0; f<numFilas; f++){
            for(int c=0; c<numColumnas; c++){
                printf("Dato posicion [%d, %d] = %d \n", f, c, *(*(p_matriz+f)+c));
            }
        }
}
