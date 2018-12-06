#include <stdlib.h>
#include <stdio.h>

#define ASCENDENTE 1
#define DESCENDENTE 0

struct nodo{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
};

void insertarLista(nodo *&, int);
void MostrarLista(nodo *&, int);
void BorrarLista(nodo *&);
void Borrar(nodo *&lista, int);
int valorActual(nodo *&lista);
int primero(nodo *&);
int ultimo(nodo *&);

int main(){
    nodo *lista=NULL;

    insertarLista(lista, 50);
    insertarLista(lista, 12);
    insertarLista(lista, 31);
    insertarLista(lista, 45);

    MostrarLista(lista, ASCENDENTE);
    MostrarLista(lista, DESCENDENTE);
    printf("\n\n");

    printf("Primero: %d\n", primero(lista));
    printf("Ultimo: %d\n\n", ultimo(lista));

    Borrar(lista, 12);
    Borrar(lista, 15);
    Borrar(lista, 45);
    Borrar(lista, 40);

    MostrarLista(lista, ASCENDENTE);
    MostrarLista(lista, DESCENDENTE);

    BorrarLista(lista);

    return 0;
}

void insertarLista(nodo *&lista, int numero){
    nodo *nuevo, *actual;

   nuevo = new struct nodo();
   nuevo->dato = numero;
   actual = lista;

   if(actual) while(actual->anterior) actual = actual->anterior;
   if(!actual || actual->dato > numero) {
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!lista) lista = nuevo;
   }
   else {
      while(actual->siguiente &&actual->siguiente->dato <= numero)
      actual = actual->siguiente;
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void MostrarLista(nodo *&lista, int orden) {
   nodo *nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;

   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      printf("Orden ascendente: ");
      while(nodo) {
         printf("%d -> ", nodo->dato);
         nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while(nodo) {
         printf("%d -> ", nodo->dato);
         nodo = nodo->anterior;
      }
   }

   printf("\n");
}

void BorrarLista(nodo *&lista) {
   nodo *nodo, *actual;
   actual = lista;

   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      delete (nodo);
   }
   lista = NULL;
   printf("\nSe borro correctamente la lista\n");
}

void Borrar(nodo *&lista, int numero) {
   nodo *nodo;
   nodo = lista;

   while(nodo && nodo->dato < numero) nodo = nodo->siguiente;
   while(nodo && nodo->dato > numero) nodo = nodo->anterior;

   if(!nodo || nodo->dato != numero) return;

   if(nodo->anterior)
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente)
      nodo->siguiente->anterior = nodo->anterior;

    delete nodo;
}

int valorActual(nodo *&lista){
    return lista->dato;
}

int primero(nodo *&lista){
    nodo *plista;
    plista=lista;
    while(plista&&plista->anterior) plista=plista->anterior;
    return plista->dato;
}

int ultimo(nodo *&lista){
    nodo *plista;
    plista=lista;
    while(plista&&plista->siguiente) plista=plista->siguiente;
    return plista->dato;
}

