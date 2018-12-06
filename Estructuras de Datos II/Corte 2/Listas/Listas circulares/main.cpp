#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

void menu();
void insertar(nodo *&, int);
void mostrarLista(nodo *&);
void buscarLista(nodo *&, int);
void eliminarLista(nodo *&);
void eliminarElemento(nodo *&, int);
void almacenarVector(nodo *&);
void ordenarBurbuja();
void mostrarListaOrdenada();

int contador, *c;

int main(){

    menu();

    return 0;
}

void menu(){
    system("color 0a");
    nodo *lista=NULL;
    int opcion, x;
    do{
        printf("MENU DE LISTAS CIRCULARES\n");
        printf("1. Insertar\n");
        printf("2. Mostrar Lista\n");
        printf("3. Buscar\n");
        printf("4. Eliminar Elemento\n");
        printf("5. Eliminar Lista\n");
        printf("6. Ordenar Lista y Mostrar\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("Ingrese un numero: "); scanf("%d",&x);
            insertar(lista,x);
            printf("Se agrego el numero %d correctamente a la lista circular...\n", x);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(lista==NULL){
                printf("La lista circular se encuentra vacia...\n");
            }else{
            printf("Mostrando Lista...\n");
            mostrarLista(lista);
            }
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(lista==NULL){
                printf("La lista circular esta vacia...\n");
            }else{
            printf("Buscando en lista...\n");
            printf("Ingrese el numero a buscar: ");
            scanf("%d",&x);
            buscarLista(lista,x);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(lista==NULL){
                printf("La lista circular esta vacia...\n");
            }else{
            printf("Ingrese elemento a eliminar: ");
            scanf("%d",&x);
            eliminarElemento(lista,x);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(lista==NULL){
                printf("La lista circular esta vacia...\n");
            }else{
            eliminarLista(lista);
            printf("Se elimino correctamente la lista circular...\n");
            }
            system("pause");
            system("cls");
            break;

        case 6:
            if(lista==NULL){
                printf("La lista circular esta vacia...\n");
            }else{
                printf("\n");
                printf("Mostrando la lista circular ordenada...\n");
                almacenarVector(lista);
                ordenarBurbuja();
                mostrarListaOrdenada();
            }
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 0:
            exit(0);

            default: printf("Opcion Invalida...\n");
        }
    }while(opcion!=0);
}

void insertar(nodo *&lista, int x){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();
    nuevo_nodo->dato = x;

    if(lista==NULL){
        lista = nuevo_nodo;
    }else{
        nuevo_nodo->siguiente = lista->siguiente;
    }
    lista->siguiente=nuevo_nodo;
}

void mostrarLista(nodo *&lista){
    nodo *aux;
    aux = lista;

    do{
        printf("%d -> ", aux->dato);
        aux=aux->siguiente;
    }while(aux!=lista);
}

void buscarLista(nodo *&lista, int x){
    bool bandera=false;
    nodo *aux;
    aux=lista;

    do{
        if(aux->dato==x){
            bandera = true;
        }
        aux=aux->siguiente;
    }while(aux!=lista);

    if(bandera==true){
        printf("Se encontro el elemento %d \n", x);
    }else{
        printf("No se encontro el elemento %d \n", x);
    }
}

void eliminarLista(nodo *&lista){
    nodo *aux;

    while((lista->siguiente)!=lista){
        aux=lista->siguiente;
        lista->siguiente = aux->siguiente;
        delete aux;
    }
    delete lista;
    lista = NULL;
}

void eliminarElemento(nodo *&lista, int x){
    nodo *aux;
    aux=lista;

    do{
        if(lista->siguiente->dato != x){
            lista=lista->siguiente;
        }
    }while((lista->siguiente->dato)!=x && lista!=aux);

    if((lista)->siguiente->dato==x){
        if(lista == lista->siguiente){
            delete lista;
            lista=NULL;
        }else{
            aux = lista->siguiente;
            lista->siguiente=aux->siguiente;
            delete aux;
        }
    }
}

void almacenarVector(nodo *&lista){
    nodo *aux;
    aux = lista;
    contador=0;

    c = new int[contador];

    do{
        c[contador] = aux->dato;
        aux = aux->siguiente;
        contador++;
    }while(aux!=lista);
}

void ordenarBurbuja(){
    int i,j,aux;

    for(i=0; i<contador; i++){
        for(j=0; j<contador-1; j++){
            if(c[j]>c[j+1]){
                aux=c[j];
                c[j]=c[j+1];
                c[j+1]=aux;
            }
        }
    }
}

void mostrarListaOrdenada(){
    for(int i=0; i<contador; i++){
        printf("%d -> ", c[i]);
    }
}


