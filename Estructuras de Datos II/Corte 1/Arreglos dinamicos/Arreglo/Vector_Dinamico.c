#include <stdio.h>
#include <stdlib.h>

//Funciones prototipo
void pedirDatos();
void imprimirDatos();

//Variables
int numCalificaciones;
int *calificaciones;

int main()
{
    pedirDatos();
    imprimirDatos();

    free(calificaciones); //Liberar memoria
    return 0;
}

void pedirDatos(){
    printf("Ingrese cantidad de calificaciones: \n"); //Se pide total de calificaciones
    scanf("%d",&numCalificaciones);

    /*if(calificaciones == NULL){
        printf("Aun no se ha reservado memoria\n"); //Si calificaciones es igual a NULL no se ha reservado memoria
    }*/

    calificaciones = (int *)malloc(numCalificaciones * sizeof(int)); //Vector dinamico, usamos la cantidad de memoria necesaria no desperdiciamos

    if(calificaciones!=NULL){
        printf("Error al reservar memoria ya se encuentra reservada\n"); //Ya se utiliza memoria
        exit(0);
    }else{

    /*if(calificaciones != NULL){
        printf("Ya se ha reservado memoria\n"); //Si calificaciones no apunta a NULL memoria llena
    }*/

    for(int i=0; i<numCalificaciones; i++){
        printf("Ingrese calificacion [%d]\n", i);
        scanf("%d",&(*(calificaciones+i))); //Ingresamos calificaciones al vector &califaciones[i]
    }
  }
}

void imprimirDatos(){
    //Imprimir datos
    for(int i=0; i<numCalificaciones; i++){
        printf("Calificacion [%d] = %d\n", i, *(calificaciones+i)); //Mostrar calificaciones
    }
}
