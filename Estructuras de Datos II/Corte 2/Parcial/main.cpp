#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodo{
    char nombre[30];
    int dato;
    struct nodo *siguiente;
};

char nombre[30];
nodo *delante=NULL;
nodo *atras=NULL;

void menu();
void listar(nodo *&, int);
void mostrarLista(nodo *&);
void eliminarLista(nodo *&);
void encolar(nodo *&, nodo *&, int, char[]);
void mostrarCola(nodo *&);
void eliminarCola(nodo *&);

int main(){
    menu();

    return 0;
}

void menu(){
int opcion, x;
nodo *lista=NULL;

    do{
        printf("\tMENU DE GESTION\n");
        printf("\t1. Listar\n");
        printf("\t2. Mostrar Lista\n");
        printf("\t3. Eliminar Lista\n");
        printf("\t4. Mostrar Cola\n");
        printf("\t5. Eliminar Cola\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("\tIngrese su nombre: ");
            fflush(stdin);
            fgets(nombre,30,stdin);
            printf("\tIngrese su edad: ");
            scanf("%d",&x);
            listar(lista, x);
            printf("\tSe ingresaron correctamente Los Datos...\n");
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                mostrarLista(lista);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                eliminarLista(lista);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(delante==NULL){
                printf("\tLa Cola esta vacia...\n");
            }else{
                mostrarCola(delante);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(delante==NULL){
                printf("\tLa Cola esta vacia...\n");
            }else{
                eliminarCola(delante);
            }
            system("pause");
            system("cls");
            break;

        case 0:
            exit(0);
            break;

            default: printf("\tOpcion Invalida...\n");
        }
    }while(opcion!=0);
}

void listar(nodo *&lista, int edad){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();

    nuevo_nodo->dato=edad;
    strcpy(nuevo_nodo->nombre,nombre);

    if(nuevo_nodo->dato>30){
        encolar(delante, atras, nuevo_nodo->dato, nuevo_nodo->nombre);
    }

    nodo *aux1=lista;
    nodo *aux2;

    while((aux1!=NULL)&&(aux1->dato>edad)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
        lista=nuevo_nodo;
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
}

void mostrarLista(nodo *&lista){
    int w=1;
    nodo *aux = new struct nodo();
    aux=lista;

    while(aux!=NULL){
        printf("\t%d. Nombre: %s ", w, aux->nombre);
        printf("\tEdad: %d\n", aux->dato);
        printf("\n");
        aux=aux->siguiente;
        w++;
    }
}

void eliminarLista(nodo *&lista){
    nodo *aux;

    while(lista!=NULL){
        aux=lista;
        lista=lista->siguiente;
        delete aux;
    }
    printf("\tSe elimino la Lista...\n");
}

void encolar(nodo *&delante, nodo *&atras, int edad, char nombre[]){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();

    nuevo_nodo->dato=edad;
    strcpy(nuevo_nodo->nombre, nombre);
    nuevo_nodo->siguiente=NULL;

    if(delante==NULL){
        delante=nuevo_nodo;
    }else{
        atras->siguiente=nuevo_nodo;
    }
    atras=nuevo_nodo;
}

void mostrarCola(nodo *&delante){
    int w=1;
    nodo *aux;
    aux=delante;

    while(aux!=NULL){
        printf("\t%d. Nombre: %s ", w, aux->nombre);
        printf("\tEdad: %d\n", aux->dato);
        printf("\n");
        aux=aux->siguiente;
        w++;
    }
}

void eliminarCola(nodo *&delante){
    nodo *aux;

    while(delante!=NULL){
        aux=delante;
        delante=delante->siguiente;
        delete aux;
    }
    printf("\tSe elimino la cola Correctamente...\n");
}
