#include <stdlib.h>
#include <stdio.h>

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertar(Nodo *&, int);
void borrarpila(Nodo *&);
void mostrarElementos(Nodo *&);

int main()
{
    // Creamos un puntero llamado pila de tipo nodo que estara vacio
    Nodo *pila=NULL;
    // Creamos una variable que almacena el dato ingresado
    int dato;
    printf("Ingrese un numero\n"); scanf("%d",&dato);
    //Mandamos a la funcion insertar la pila vacia y el dato
    insertar(pila,dato);

    printf("Ingrese otro numero\n"); scanf("%d",&dato);
    insertar(pila,dato);


    //Llamamos funcion mostrar
    printf("Mostrando la pila\n\n");
    mostrarElementos(pila);
    printf("Sacar elementos de la pila\n");
    //Llamamos funcion borrar
    borrarpila(pila);
    return 0;
}

void insertar(Nodo *&pila, int n){
    //Creamos un puntero de tipo nodo y utilizamos el new para reservar memoria
    Nodo *nuevo_nodo=new Nodo(); //Nodo
    //nuevo_nodo tomara el valor del dato ingresado
    nuevo_nodo->dato=n;
    //nuevo nodo en la posicion siguiente va a ser igual a pila que en este momento seria NULL
    nuevo_nodo->siguiente=pila;
    //Y pila va a almacenar el nuevo_nodo que tiene el dato ingresado por teclado /*se genera un cambio*/
    pila=nuevo_nodo;
    printf("El dato %d se agrego correctamente a la pila\n", n);
}

void borrarpila(Nodo *&pila){
    //Mientras la pila no este vacia haga esto
    while(pila!=NULL){
            //Creamos un auxiliar que almacena el valor actual de la pila
        Nodo *aux=pila;
        //n=aux->dato
        //Pila va a ser igual a vacio
        pila=aux->siguiente;
        printf("Borrando el dato %d\n", aux->dato);
        //Liberamos memoria
        delete aux;
    }
}

void mostrarElementos(Nodo *&pila){
    //Creamos un puntero llamado nueva pila que almacena el valor de la pila
    Nodo *Nueva_pila = pila;
    //Si la pila apunta a NULL es porque la pila esta vacia
    if(pila==NULL){
        printf("La pila esta vacia\n");
        //Pero si no apunta a NULL es porque tiene un elemento
    }else if(Nueva_pila!=NULL){
        //Mientras la pila sea diferente a NULL HAGA:
        while(Nueva_pila!=NULL){
                //Mostrar elementos de la pila
            printf("%d\n", Nueva_pila->dato);
            //Despues de imprimir un elemento la pila apunta al siguiente nodo o elemento para ser mostrado
            Nueva_pila=Nueva_pila->siguiente;
        }
    }
    printf("\n");
}
