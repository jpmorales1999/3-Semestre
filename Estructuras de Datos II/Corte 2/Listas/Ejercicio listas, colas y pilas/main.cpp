#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

void menu();
void menuPila();
void apilar(nodo *&, int);
int desapilar(nodo *&);
void mostrarPila(nodo *&);
void buscarPila(nodo *&, int);
void borrarPila(nodo *&);
void menuCola();
void encolar(nodo *&, nodo *&, int);
void mostrarCola(nodo *&);
void buscarCola(nodo *&, int);
int desencolar(nodo *&);
void borrarCola(nodo *&, nodo*&);
void menuLista();
void listar(nodo *&, int);
void mostrarLista(nodo *&);
void buscarLista(nodo *&, int);
void eliminarElementoLista(nodo *&, int);
void vaciarLista(nodo *&);

int main(){
    system("color 0a");
    menu();

    return 0;
}

void menu(){
    system("cls");
    int opcion;
    do{
        printf("MENU DE LISTAS ENLAZADAS\n\n");
        printf("1. Gestionar Pila\n");
        printf("2. Gestionar Cola\n");
        printf("3. Gestionar Lista Enlazada\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            menuPila();
            break;

        case 2:
            system("cls");
            menuCola();
            break;

        case 3:
            system("cls");
            menuLista();
            break;

        case 0:
            exit(0);

            default: printf("Opcion invalida\n");
        }
    }while(opcion!=0);
}

void menuPila(){
    int opcion, numero;
    nodo *cima = NULL;
     do{
        printf("MENU DE PILAS\n\n");
        printf("1. Apilar\n");
        printf("2. Mostrar Pila\n");
        printf("3. Buscar en Pila\n");
        printf("4. Desapilar\n");
        printf("5. Borrar Pila\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("Ingrese un numero a apilar: "); scanf("%d",&numero);
            apilar(cima,numero);
            printf("Se agrego correctamente el numero %d a la pila...\n", numero);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(cima==NULL){
                printf("La pila esta vacia...\n");
            }else{
            printf("Mostrando Pila...\n\n");
            mostrarPila(cima);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(cima==NULL){
                printf("La pila esta vacia...\n");
            }else{
            printf("Ingrese numero a buscar: "); scanf("%d",&numero);
            buscarPila(cima,numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(cima==NULL){
                printf("La pila esta vacia...\n");
            }else{
            numero = desapilar(cima);
            printf("Se borro el numero %d correctamente de la pila...\n", numero);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(cima==NULL){
                printf("La pila esta vacia...\n");
            }else{
                borrarPila(cima);
            }
            system("pause");
            system("cls");
            break;

        case 0:
            menu();

            default: printf("Opcion Invalida...\n\n");
        }
     }while(opcion!=0);
}

void apilar(nodo *&cima, int n){
    nodo *nuevo_nodo;
    nuevo_nodo = new nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=cima;
    cima=nuevo_nodo;
}

void mostrarPila(nodo *&cima){
    nodo *aux;
    aux=cima;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux=aux->siguiente;
    }
}

void buscarPila(nodo *&cima, int n){
    bool bandera=false;
    nodo *aux;
    aux = cima;

    while(aux!=NULL){
        if(aux->dato==n){
            bandera=true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("Se encontro el numero %d en la pila \n", n);
    }else{
        printf("No se encontro el numero %d en la pila \n", n);
    }
}

int desapilar(nodo *&cima){
    int n;
    nodo *aux;
    aux = cima;
    n = aux->dato;
    cima = (cima)->siguiente;
    delete (aux);
    return n;
}

void borrarPila(nodo *&cima){
    nodo *aux;
    while(cima!=NULL){
        aux=cima;
        cima=(cima)->siguiente;
        delete (aux);
    }
    printf("Se borro la pila correctamente...\n");
}

void menuCola(){
    int opcion, numero;
    nodo *delante = NULL;
    nodo *atras = NULL;
     do{
        printf("MENU DE COLAS\n\n");
        printf("1. Encolar\n");
        printf("2. Mostrar Cola\n");
        printf("3. Buscar en Cola\n");
        printf("4. Desencolar\n");
        printf("5. Borrar Cola\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("Ingrese un numero a Encolar: "); scanf("%d",&numero);
            encolar(delante,atras,numero);
            printf("Se agrego correctamente el numero %d a la cola...\n", numero);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(delante==NULL){
                printf("La cola esta vacia...\n");
            }else{
            printf("Mostrando Cola...\n\n");
            mostrarCola(delante);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(delante==NULL){
                printf("La cola esta vacia...\n");
            }else{
            printf("Ingrese numero a buscar: "); scanf("%d",&numero);
            buscarCola(delante,numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(delante==NULL){
                printf("La cola esta vacia...\n");
            }else{
                numero = desencolar(delante);
            printf("Se borro el numero %d correctamente de la cola...\n", numero);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(delante==NULL){
                printf("La cola esta vacia...\n");
            }else{
                borrarCola(delante,atras);
            }
            system("pause");
            system("cls");
            break;

        case 0:
            menu();

            default: printf("Opcion Invalida...\n\n");
        }
     }while(opcion!=0);
}

void encolar(nodo *&delante, nodo *&atras, int n){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(delante==NULL){
        delante = nuevo_nodo;
    }else{
        atras->siguiente=nuevo_nodo;
    }
    atras = nuevo_nodo;
}

void mostrarCola(nodo *&delante){
    nodo *aux;
    aux=delante;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux=aux->siguiente;
    }
}

void buscarCola(nodo *&delante, int n){
    bool bandera = false;
    nodo *aux;
    aux = delante;

    while(aux!=NULL){
        if(aux->dato==n){
            bandera=true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("Se encontro el numero %d en la cola\n", n);
    }else{
        printf("No se encontro el numero %d en la cola\n", n);
    }
}

int desencolar(nodo *&delante){
    int n;
    nodo *aux;
    aux=delante;
    n = aux->dato;
    delante = (delante)->siguiente;
    delete (aux);
    return n;
}

void borrarCola(nodo *&delante, nodo *&atras){
    nodo *aux;
    while(delante!=NULL){
        aux=delante;
        delante=(delante)->siguiente;
        delete(aux);
    }
    printf("Se borro la cola correctamente...\n");
    delante=NULL;
    atras=NULL;
}

void menuLista(){
    int opcion, numero;
    nodo *lista = NULL;
     do{
        printf("MENU DE LISTAS\n\n");
        printf("1. Listar\n");
        printf("2. Mostrar Lista\n");
        printf("3. Buscar en Lista\n");
        printf("4. Borrar elemento de la Lista\n");
        printf("5. Borrar Lista\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            printf("Ingrese un numero a Listar: "); scanf("%d",&numero);
            listar(lista, numero);
            printf("Se agrego correctamente el numero %d a la lista...\n", numero);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(lista==NULL){
                printf("La lista esta vacia...\n");
            }else{
            printf("Mostrando lista...\n\n");
            mostrarLista(lista);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(lista==NULL){
                printf("La lista esta vacia...\n");
            }else{
            printf("Ingrese numero a buscar: "); scanf("%d",&numero);
            buscarLista(lista,numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(lista==NULL){
                printf("La lista esta vacia...\n");
            }else{
            printf("Ingrese numero a borrar: "); scanf("%d",&numero);
            eliminarElementoLista(lista, numero);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(lista==NULL){
                printf("La lista esta vacia...\n");
            }else{
                vaciarLista(lista);
            }
            system("pause");
            system("cls");
            break;

        case 0:
            menu();

            default: printf("Opcion Invalida...\n\n");
        }
     }while(opcion!=0);
}

void listar(nodo *&lista, int n){
    nodo *nuevo_nodo;
    nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;

    nodo *aux1=lista;
    nodo *aux2;

    while((aux1!=NULL)&&(aux1->dato<n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
}

void mostrarLista(nodo *&lista){
    nodo *aux;
    aux = lista;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux=aux->siguiente;
    }
}

void buscarLista(nodo *&lista, int n){
    bool bandera=false;
    nodo *aux = lista;

    while((aux!=NULL)&&(aux->dato<=n)){
        if(aux->dato==n){
            bandera=true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("Se encontro el numero %d en la lista\n", n);
    }else{
        printf("No se encontro el numero %d en la lista\n", n);
    }
}

void eliminarElementoLista(nodo *&lista, int n){
    nodo *aux_borrar = lista;
    nodo *anterior = NULL;

    while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
        anterior=aux_borrar;
        aux_borrar=aux_borrar->siguiente;
    }

    if(aux_borrar==NULL){
        printf("No se encontro el numero en la lista\n");
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

void vaciarLista(nodo *&lista){
    nodo *aux;
    while(lista!=NULL){
        aux=lista;
        lista=lista->siguiente;
        delete(aux);
    }
    printf("Se vacio correctamente la lista\n");
}
