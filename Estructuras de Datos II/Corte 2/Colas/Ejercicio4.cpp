/* Genere un programa que permita crear una cola que almacene “n” números y calcular su suma y promedio. */

/* Reutilizamos codigo usando el mismo codigo del ejercicio 1 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

void encolar(nodo *&, nodo *&, int);
int desencolar(nodo *&);
bool colaVacia(nodo *&);
void mostrarCola(nodo *&);
void vaciarCola(nodo *&, nodo *&);
void sumaPromedio();
void menu();

/*Varibles globales*/
int suma=0, contador=0;

int main()
{
    system("color 0a");
    int numero, opcion;
    nodo *delante = NULL;
    nodo *atras = NULL;

    do{
        menu(); scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("\tIngrese un numero a encolar: ");
                scanf("%d",&numero);
                encolar(delante,atras,numero);
                printf("\tSe encolo correctamente el numero %d\n\n", numero);
                system("pause");
                system("cls");
                break;

            case 2:
                if(colaVacia(delante)==true){
                    printf("\tLa pila esta vacia...\n\n");
                }else{
                   numero = desencolar(delante);
                   printf("\tSe desencolo el numero: %d\n\n", numero);
                }
                system("pause");
                system("cls");
                break;

            case 3:
                if(colaVacia(delante)==true){
                    printf("\tLa cola esta vacia...\n\n");
                }else{
                      printf("\tMOSTRANDO COLA...\n\n");
                      mostrarCola(delante);
                }
                system("pause");
                system("cls");
                break;

            case 4:
                if(colaVacia(delante)==true){
                    printf("\tLa cola esta vacia...\n\n");
                }else{
                    printf("\tVaciando la cola...\n");
                    vaciarCola(delante , atras);
                }
                system("pause");
                system("cls");
                break;

            case 5:
                sumaPromedio();
                system("pause");
                system("cls");
                break;

            case 6:
                exit(0);

                default: printf("\tOpcion invalida...\n");
        }
    }while(opcion!=6);


    return 0;
}

void menu(){
    printf("\tMENU DE COLAS\n\n");
    printf("\t1. Encolar\n");
    printf("\t2. Desencolar\n");
    printf("\t3. Mostrar Cola\n");
    printf("\t4. Vaciar Cola\n");
    printf("\t5. Suma y Promedio\n");
    printf("\t6. Salir\n");
    printf("\n\n\tIngrese opcion: ");
}

bool colaVacia(nodo*& delante){
    if(delante==NULL){
        return true;
    }else{
        return false;
    }
}

void encolar(nodo*& delante, nodo*& atras, int numero){
    nodo *nueva_cola;
    nueva_cola = new(struct nodo);
    nueva_cola->dato=numero;
    //Sumamos el numero a encolar
    suma+=numero;
    nueva_cola->siguiente=NULL;
    //Aumentamos contador
    contador++;

    if(delante==NULL){
        delante = nueva_cola;
    }else{
        atras->siguiente = nueva_cola;
    }
    atras = nueva_cola;
}

int desencolar(nodo*& delante){
    int n;
    nodo *p_aux;

    p_aux = delante;
    n = p_aux->dato;
    /*Si desencola se le resta a la variable suma*/
    suma-=p_aux->dato;
    contador--;
    delante = (delante)->siguiente;
    delete(p_aux);
    return n;
}

void mostrarCola(nodo *& delante){
    nodo *p_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        printf("\t %d \n", p_aux->dato);
        p_aux = p_aux->siguiente;
    }
}

void vaciarCola(nodo *& delante, nodo *& atras){
    nodo *p_aux, *r_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        r_aux = p_aux;
        p_aux=p_aux->siguiente;
        delete(r_aux);
    }
    suma=0;
    contador=0;
    delante = NULL;
    atras = NULL;
}

void sumaPromedio(){
    printf("\n");
    printf("\tLa suma total de los numeros en la cola es: %d\n", suma);
    printf("\tEl promedio total es: %d\n", suma/contador);
}
