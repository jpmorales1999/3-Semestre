#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

void apilar(nodo*&, int);
int desapilar(nodo*&);
void cima(nodo*&);
bool pilaVacia(nodo *&);
void mostrarPila(nodo*&);
void destruirPila(nodo*&);
void menu();

int main(){
    system("color 0a");
    nodo *Cima = NULL;

    int x, opcion;
    do{
        menu(); scanf("%d",&opcion);
        switch(opcion){
        case 1:
            printf("\n\n\t\tINGRESE UN NUMERO A APILAR: ");
            scanf("%d",&x);
            apilar(Cima, x);
            system("pause");
            system("cls");
            break;

        case 2:
            if(pilaVacia(Cima)!=true){
                x=desapilar(Cima);
                printf("\n\n\t\tNumero %d desapilado\n\n", x);
            }else{
                printf("\n\n\t\tLa pila esta vacia...\n\n");
            }
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\n\n\t\tMOSTRANDO PILA\n\n");
            if(pilaVacia(Cima)!=true){
                mostrarPila(Cima);
            }else{
                printf("\n\n\t\tLa pila esta vacia...\n\n");
            }
            system("pause");
            system("cls");
            break;

        case 4:
            destruirPila(Cima);
            printf("\n\n\t\tLa pila esta destruida...\n\n");
            system("pause");
            system("cls");
            break;

        case 5:
            printf("\n\n\t\tMOSTRANDO CIMA\n\n");
            cima(Cima);
            system("pause");
            system("cls");
            break;
        }
    }while(opcion!=6);

    return 0;
}

void menu(){
    printf("\tIMPLEMENTACION DE UNA PILA\n\n");
    printf("\t1. Apilar\n");
    printf("\t2. Desapilar\n");
    printf("\t3. Mostrar Pila\n");
    printf("\t4. Destruir Pila\n");
    printf("\t5. Mostrar Cima\n");
    printf("\t6. Salir\n");
    printf("\t Ingrese opcion: ");
}

void apilar(nodo *&Cima, int x){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato=x;
    nuevo_nodo->siguiente=Cima;
    Cima=nuevo_nodo;
    printf("\n\n\t\tEl dato %d se agrego correctamente a la pila\n", x);
}

bool pilaVacia(nodo *&Cima){
    if(Cima==NULL){
        return true;
    }else{
        return false;
    }
}

void mostrarPila(nodo *&Cima){
    nodo *aux;
    aux=Cima;

    while(aux!=NULL){
        printf("\t\t %d\n", aux->dato);
        aux=aux->siguiente;
    }
}

void cima(nodo*&Cima){
    int x;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        x = Cima->dato;
        printf("\t %d\n", x);
    }
}

int desapilar(nodo*&Cima){
    int x;
    nodo *aux;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        aux=Cima;
        x=aux->dato;
        Cima=Cima->siguiente;
        delete(aux);
    }
    return x;
}

void destruirPila(nodo*&Cima){
    nodo *aux;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        while(Cima!=NULL){
            aux=Cima;
            Cima=Cima->siguiente;
            delete(aux);
        }
    }
}
