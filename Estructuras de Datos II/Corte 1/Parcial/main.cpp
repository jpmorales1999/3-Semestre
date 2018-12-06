#include <stdlib.h>
#include <stdio.h>

//Creacion de la estructura
struct datos{
    char nombre[30];
    int edad;
}personas[3], *pPersonas = personas;

//Prototipos de funciones
void pedirDatos();
void mostrarDatos();
void determinarEscala();
void mostrarDatosClasificados();
void menuMayor();
void cambioNombreMayor();

//Variables globales
int i, mayor=-999999, menor=999999, mediano;
int baseMayor, baseMenor, baseMediano;

int main()
{
    pedirDatos();
    mostrarDatos();
    determinarEscala();
    mostrarDatosClasificados();
    menuMayor();

    return 0;
}

void pedirDatos(){
    //Pedimos datos para los 3 encuentados
    for(i=0; i<3; i++){
        printf("Persona No. %d\n\n", i+1);
        printf("Ingrese Nombre: "); fflush(stdin); fgets((pPersonas+i)->nombre,30,stdin);
        printf("Ingrese Edad: "); scanf("%d",&(pPersonas+i)->edad);
        printf("\n\n");
        system("cls");
    }
}

void mostrarDatos(){
    //Mostramos datos ingresados
    printf("Mostrando Datos \n\n");
    for(i=0; i<3; i++){
        printf("Persona No. %d\n\n", i+1);
        printf("Nombre: %s", (pPersonas+i)->nombre);
        printf("Edad: %d", (pPersonas+i)->edad);
        printf("\n\n");
    }
    system("pause");
    system("cls");
}

void determinarEscala(){
    //En esta funcion determinaremos el mayor, menor y mediano de los ingresados

    //Edad mayor
    for(i=0; i<3; i++){
        if((pPersonas+i)->edad > mayor){
            mayor = (pPersonas+i)->edad;
            //Guardamos la posicion de la edad mayor en una variable
            baseMayor = i;
        }
    }

    //Edad menor
    for(i=0; i<3; i++){
        if((pPersonas+i)->edad < menor){
            menor = (pPersonas+i)->edad;
             //Guardamos la posicion de la edad menor en una variable
            baseMenor = i;
        }
    }

    //Sacamos la edad mediana si se encuentra entre el mayor y el menor
    for(i=0; i<3; i++){
        if((pPersonas+i)->edad < mayor && (pPersonas+i)->edad > menor){
            mediano = (pPersonas+i)->edad;
             //Guardamos la posicion de la edad mediano en una variable
            baseMediano = i;
        }
    }
}

void mostrarDatosClasificados(){
    //Persona Mayor
    printf("Persona Mayor: \n\n");
    printf("Nombre: %s", (pPersonas+baseMayor)->nombre);
    printf("Edad: %d", (pPersonas+baseMayor)->edad);
    printf("\n\n");

     //Persona Mediana
    printf("Persona Mediana: \n\n");
    printf("Nombre: %s", (pPersonas+baseMediano)->nombre);
    printf("Edad: %d", (pPersonas+baseMediano)->edad);
    printf("\n\n");

    //Persona Menor
    printf("Persona Menor: \n\n");
    printf("Nombre: %s", (pPersonas+baseMenor)->nombre);
    printf("Edad: %d", (pPersonas+baseMenor)->edad);
    printf("\n\n");

    system("pause");
    system("cls");
}

void menuMayor(){
    //Menu de opciones
    int opcion;
    do{
        printf("Menu de opciones Persona Mayor\n\n");
        printf("Hola %s", (pPersonas+i)->nombre);
        printf("Deseas cambiar tu nombre?\n");
        printf("Elige una opcion: \n");
        printf("1. Cambiar Nombre\n");
        printf("0. Salir\n");
        printf("Ingres su opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1: system("cls");
        cambioNombreMayor();
        system("pause");
        system("cls");
        break;
        case 0: exit(0);
        default: printf("La opcion no es valida\n");
        }
    }while(opcion!=0);
}

void cambioNombreMayor(){
    printf("Ingrese su nuevo nombre: "); fflush(stdin); fgets((pPersonas+baseMayor)->nombre,30,stdin);
    printf("Nombre registrado con exito...\n");
    system("pause");
    system("cls");
    printf("Saludando a tu nuevo nombre...\n\n");
    printf("Hola %s", (pPersonas+baseMayor)->nombre);
}
