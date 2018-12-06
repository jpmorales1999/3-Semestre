#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //Incluir booleanos en c

//Struct nodo que nos sirve para el manejo de Pila
struct nodo{
    int dato;
    struct nodo *siguiente;
};

typedef struct nodo *Puntero;

//Class pila
class Pila{
    //Public hara referencia a las acciones del objeto
public:
    Pila(void); //Constructor - Nos servira para inicializar la pila
    void Apilar(int );
    int Desapilar(void );
    void Cima(void);
    bool PilaVacia(void);
    void MostrarPila(void);
    void DestruirPila(void);

    //Private hara referencia a los atributos o caracteristicas del objeto
private:
    //Creamos una variable de tipo puntero llamada cima
    Puntero cima;
};

//Constructor nos sirve para inicializar los atributos (PRIVATE)
Pila::Pila(void){
    cima=NULL;
}

//Nos sirve para comprobar si una pila esta llena o no por medio de su cima
bool Pila::PilaVacia(void){
    if(cima==NULL){
        return true;
    }else{
        return false;
    }
}

void Pila::Apilar(int x){
    //Creamos un aux de tipo puntero
    Puntero p_aux;
    //Reservamos en memoria
    p_aux=new(struct nodo);
    //En el dato de la struct nodo guardamos x
    p_aux->dato=x;
    //El siguiente nodo se le asigna cima que es NULL
    p_aux->siguiente=cima;
    //Le asignamos el numero actualmente ingresado
    cima=p_aux;
}

void Pila::Cima(void){
    int x;
    if(cima==NULL){
        printf("\n\n\tPila Vacia...!");
    }else{
        x=cima->dato;
        printf("\n\tLa cima es: %d\n", x);
    }
}

int Pila::Desapilar(void){
    int x;
    Puntero p_aux;
    if(cima==NULL){
        printf("\n\n\tPila Vacia...!");
    }else{
        p_aux=cima;
        x=p_aux->dato;
        cima=cima->siguiente;
        delete(p_aux);
    }
    return x;
}

void Pila::MostrarPila(void){
    Puntero p_aux;
    p_aux=cima;

    while(p_aux!=NULL){
        printf("\t %d\n", p_aux->dato);
        p_aux=p_aux->siguiente;
    }
}

void Pila::DestruirPila(void){
    Puntero p_aux;

    while(cima!=NULL){
        p_aux=cima;
        cima=cima->siguiente;
        delete(p_aux);
    }
}

void menu(void){
    printf("\tIMPLEMENTACION DE UNA PILA\n\n");
    printf("\t1. Apilar\n");
    printf("\t2. Desapilar\n");
    printf("\t3. Mostrar Pila\n");
    printf("\t4. Destruir Pila\n");
    printf("\t5. Mostrar Cima\n");
    printf("\t6. Salir\n");
    printf("\t Ingrese opcion: ");
}

int main(void){
    system("color 0a");
    //Se crea un objeto de tipo Clase Pila
    Pila pilaOb;
    int x;
    int op;
    do{
        menu(); scanf("%d",&op);
        switch(op){
            case 1:
            printf("\n\t INGRESE NUMERO A APILAR: "); scanf("%d",&x);
            /*Se le envia como parametro x a la funcion apilar*/
            pilaOb.Apilar(x);
            printf("\n\n\t\tNumero %d apilado...\n\n", x);
            system("pause");
            system("cls");
            break;

            case 2:
                //Comprueba si la pila esta vacia
                if(pilaOb.PilaVacia()==true){
                    printf("\n\n\tPila vacia...");
                }else{
                    //Retorna numero desapilado
                    x = pilaOb.Desapilar();
                    printf("\n\n\tNumero %d desapilado\n", x);
                }
                system("pause");
                system("cls");
                break;

            case 3:
                printf("\n\n\tMOSTRANDO PILA\n\n");
                //Comprueba de que la pila posea elementos
                if(pilaOb.PilaVacia()!=true){
                    pilaOb.MostrarPila();
                }else{
                    printf("\n\n\tPila vacia...\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 4:
                pilaOb.DestruirPila();
                printf("\n\n\t\tPila eliminada...\n\n");
                system("pause");
                system("cls");
                break;

            case 5:
                pilaOb.Cima();
                system("pause");
                system("cls");
                break;
        }
    }while(op!=6);
}
