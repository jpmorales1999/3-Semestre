#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

//Creamos punteros de tipoNodo
typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

//Prototipo de funciones
void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);

void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));


void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void Mostrar(int *d);

int main()
{
    //Variable de tipp arbol que apunta a NULL
   Arbol ArbolInt=NULL;
   //Variable opcion para el menu y variable dato para almacenar el numero a gestionar
   int opcion, dato;
   int altura, nnodos;

   do{
        printf("Menu Arbol...\n");
        printf("1. Insertar en Arbol\n");
        printf("2. Altura Arbol\n");
        printf("3. Mostrar Arbol Inorden\n");
        printf("4. Mostrar Arbol Preorden\n");
        printf("5. Mostrar Arbol Postorden\n");
        printf("6. Numero Nodos del Arbol\n");
        printf("7. Borrar Elemento de Arbol\n");
        printf("8. Altura de 1\n");
        printf("9. Altura de 10\n");
        printf("10. Podar Arbol\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            printf("Numero a Insertar: ");
            scanf("%d",&dato);
            Insertar(&ArbolInt, dato);
            printf("Se Inserto Correctamente el Numero\n");
            break;

        case 2:
            printf("La altura del arbol es: %d\n", AlturaArbol(ArbolInt, &altura));
            break;

        case 3:
            printf("Inorden: ");
            InOrden(ArbolInt, Mostrar);
            printf("\n");
            break;

        case 4:
            printf("Preorden: ");
            PreOrden(ArbolInt, Mostrar);
            printf("\n");
            break;

        case 5:
            printf("Posorden: ");
            PostOrden(ArbolInt, Mostrar);
            printf("\n");
            break;

        case 6:
            printf("Numero de Nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
            break;

        case 7:
            printf("Ingrese el numero a Borrar: ");
            scanf("%d",&dato);
            Borrar(&ArbolInt, dato);
            printf("Se borro el dato Correctamente...\n");
            break;

        case 8:
            printf("Altura de 1 Arbol: %d\n", Altura(ArbolInt, 1));
            break;

        case 9:
            printf("Altura de 10 Arbol: %d\n", Altura(ArbolInt, 10));
            break;

        case 10:
            Podar(&ArbolInt);
            printf("Se podo el arbol Correctamente\n");
            break;

        case 0:
            exit(0);

            default: printf("Opcion Invalida\n");
        }
        system("pause");
        system("cls");
   }while(opcion!=0);

   return 0;
}

void Podar(Arbol *a)
{
   if(*a) {
      Podar(&(*a)->izquierdo);
      Podar(&(*a)->derecho);
      free(*a);
      *a = NULL;
   }
}

void Insertar(Arbol *a, int dat)
{
    //Variable padre de tipo pnodo sera igual a NULL
    //Actual sera igual a la posicion actual del arbol
   pNodo padre = NULL;
   pNodo actual = *a;

   //Mientras arbol no este vacio  y el dato ingresado sea diferente al valor del dato del arbol
   while(!Vacio(actual) && dat != actual->dato) {
        //Padre igual a actual = arbol
      padre = actual;
      //Si dato es menor que el dato del arbol entonces actual es igual a actual apuntando a la izquierda
      if(dat < actual->dato) actual = actual->izquierdo;
      //Si no si sera todo igual pero al lado derecho
      else if(dat > actual->dato) actual = actual->derecho;
   }

   //Si arbol no esta vacio return
   if(!Vacio(actual)) return;

   //Si padre esta vacio
   if(Vacio(padre)) {
        //Se crea un nuevo nodo
      *a = (Arbol)malloc(sizeof(tipoNodo));
      //El nuevo nodo apuntando a dato sera igual al dato ingresado
      (*a)->dato = dat;
      //El puntero izq y derecho seran igual a NULL
      (*a)->izquierdo = (*a)->derecho = NULL;
   }

   //Si no si el dato es menor que el padre apuntando a dato entonces
   //Se almacena el dato al lado izq
   else if(dat < padre->dato) {
        //Creamos nuevo nodo
      actual = (Arbol)malloc(sizeof(tipoNodo));
      //Padre apuntando a izq sera igual a actual
      padre->izquierdo = actual;
      //Actual apuntando a dato sera igual al dato
      actual->dato = dat;
      //El puntero izq y derecho seran igual a NULL
      actual->izquierdo = actual->derecho = NULL;
   }

   //Será para el caso donde el dato sea mayor que el padre apuntanto a dato
   //Se almacena el dato al lado der
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;

   //Mientras el arbol no este vacio
   while(!Vacio(actual)) {
        //Si el dato se encuentra en el arbol (dato es igual a arbol apuntando a dato)
      if(dat == actual->dato) {
          //Si es un nodo hoja
         if(EsHoja(actual)) {
             //Si padre
            if(padre)
            //Si padre apuntando a derecha es igual a actual entonces apuntara a NULL
               if(padre->derecho == actual) padre->derecho = NULL;
   //Si no si caso contrario al lado izquierdo
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
               //Se libera el nodo actual
            free(actual);
            //y Sera igual a NULL
            actual = NULL;
            return;
         }
         else {
                //Si no padre sera igual a actual
            padre = actual;

            //Si actual apuntando a derecho
            if(actual->derecho) {
                    //entonces nodo es igual actual apuntando a derecho
               nodo = actual->derecho;
            //Mientras nodo apuntando a izq
               while(nodo->izquierdo) {
                    //padre sera igual a nodo
                  padre = nodo;
               // nodo sera igual a nodo apuntando siguiente
                  nodo = nodo->izquierdo;
               }
            }

            //Si no mismo proceso pero de tomando direcciones diferentes
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }

            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else {
            //Si no padre sera igual a actual
         padre = actual;
      //si dato es mayor que actual apuntando a dato entonces actual sera igual a actual apuntando a derecho
         if(dat > actual->dato) actual = actual->derecho;
         //si dato es menor que actual apuntando a dato entonces actual sera igual a actual apuntando a izq
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

//Organiza el arbol de forma inorden
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

//Organiza el arbol de forma preorden
void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}

//Organiza el arbol de forma postorden
void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

//Busca que el numero ingresado si exista dentro del arbol
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

//Mientras arbol no este vacio
   while(!Vacio(actual)) {
   	//Pregunta si dato es igual a actual->dato
      if(dat == actual->dato) return TRUE;
      //Mueve hacia la izq
      else if(dat < actual->dato) actual = actual->izquierdo;
      //Mueve hacia la der
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE;
}

//Retorna la altura del nivel del nodo que deseemos
int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura;
      else {
         altura++;
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1;
}

//Retorna el numero de nodos del arbol
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador);
   return *contador;
}

//Cuenta uno a uno los nodos del arbol
void auxContador(Arbol nodo, int *c)
{
   (*c)++;

   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

//Determina la altura del arbol
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   //Llama a la funcion auxAltura y le pasamos como parametro el arbol el o y la variable altura
   auxAltura(a, 0, altura);

   //return altura
   return *altura;
}

//Nos suma la altura total del arbol y nos la devuelve por medio de la variable altura
void auxAltura(pNodo nodo, int a, int *altura)
{
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);

   if(EsHoja(nodo) && a > *altura) *altura = a;
}

//Return null si arbol esta vacio
int Vacio(Arbol r)
{
   return r==NULL;
}

//Determina si es hoja
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

void Mostrar(int *d)
{
   printf("%d, ", *d);
}

