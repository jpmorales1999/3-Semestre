#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct nodo{
    int dato;
    nodo *siguiente;
};

void insertarLista(nodo*&,int);
void mostrarLista(nodo*&);
void eliminarNodo(nodo*&, int);
void menu();
void vaciarLista(nodo*&);
void buscar(nodo*&, int);

int main()
{
    system("color 0a");
    menu();

    return 0;
}

void menu(){
    nodo *lista=NULL;
    int dato;
    int opcion;
    do{
        printf("MENU DE LISTAS ENLAZADAS\n\n");
        printf("1. Insertar\n");
        printf("2. Mostrar\n");
        printf("3. Buscar\n");
        printf("4. Borrar elemento\n");
        printf("5. Borrar todo\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("Ingrese un numero: ");
            scanf("%d",&dato);
            insertarLista(lista,dato);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            mostrarLista(lista);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            printf("Ingrese el dato a buscar: ");
            scanf("%d",&dato);
            buscar(lista,dato);
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            printf("Ingrese el dato a eliminar: ");
            scanf("%d",&dato);
            eliminarNodo(lista, dato);
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            vaciarLista(lista);
            printf("Se borro la lista correctamente...\n\n");
            system("pause");
            system("cls");
            break;
        }
    }while(opcion!=0);
}

void insertarLista(nodo *&lista, int n){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato=n;
    nodo *aux1=lista;
    nodo *aux2;

    while((aux1!=NULL)&&(aux1->dato<n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
        lista=nuevo_nodo;
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    printf("Dato %d insertado correctamente\n", n);
}

void mostrarLista(nodo *&lista){
    nodo *actual = new nodo();
    actual=lista;
    while(actual!=NULL){
        printf("%d\n", actual->dato);
        actual=actual->siguiente;
    }
}

void eliminarNodo(nodo *&lista, int n){
    if(lista!=NULL){
        nodo *aux_borrar;
        nodo *anterior=NULL;
        aux_borrar=lista;


    while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
        anterior=aux_borrar;
        aux_borrar=aux_borrar->siguiente;
    }

    if(aux_borrar==NULL){
        printf("El elemento no existe\n");
    }else if(anterior==NULL){
        lista=lista->siguiente;
        printf("Elemento %d eliminado\n", n);
        delete aux_borrar;
    }else{
        anterior->siguiente=aux_borrar->siguiente;
        printf("Elemento %d eliminado \n", n);
        delete aux_borrar;
      }
   }
}

void vaciarLista(nodo *&lista){
    nodo *aux;
    while(lista!=NULL){
        aux=lista;
        lista = lista->siguiente;
        delete aux;
    }
}

void buscar(nodo *&lista, int n){
    bool bandera = false;
    nodo *aux;
    aux=lista;

    while((aux!=NULL)&&(aux->dato<=n)){
        if(aux->dato==n){
            bandera = true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("Se encontro el numero %d en la lista\n", n);
    }else{
        printf("No se encontro el numero %d en la lista\n", n);
    }
}
