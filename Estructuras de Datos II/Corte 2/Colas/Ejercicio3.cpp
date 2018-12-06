/*Banco - Cola - Juan Pablo Morales Tames*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cliente{
    int id;
    char nombre[30];
    int cedula;
    int tipo;
}clientes[100];

struct nodo{
    int nro;
    struct nodo *siguiente;
};

//Variables nodo
nodo *delante=NULL;
nodo *atras=NULL;

//Funciones
void menu();
void cliente();
void tipoTransaccion();
void mostrarCliente();
void comprobacion();
void encolar();
void mostrarCola();
void mostrarClientes();
void desencolar();
void eliminarCliente();

//Variables
float tiempoTotal=0;
int cantClientes=0;
const float retiro=4;
const float deposito=2;
const float consulta=3.5;
const float actualizacion=5;
const float pago=2;

int main(){
    system("color 0a");

    menu();

    return 0;
}

void menu(){
    int opcion;
    do{
       printf("\n\tMENU CLIENTES\n\n");
       printf("\t1. Cliente\n");
       printf("\t2. Mostrar Clientes (En Cola)\n");
       printf("\t3. Mostrar Cola\n");
       printf("\t4. Tiempo de espera Cola\n");
       printf("\t5. Desencolar\n");
       printf("\t0. Salir\n");
       printf("\tIngrese una opcion: ");
       scanf("%d",&opcion);
       printf("\n\n");
       switch(opcion){
           case 1:
               system("cls");
               cliente();
               system("\tpause");
               system("cls");
               break;

           case 2:
               system("cls");
               mostrarClientes();
               system("\tpause");
               system("cls");
               break;

           case 3:
                system("cls");
                if(delante==NULL){
                    printf("\n\n\tLa cola esta vacia...\n\n");
                }else{
                    printf("\n\n");
                    printf("\tCliente Registro = 1 - 4 min\n\n");
                    printf("\tCliente Deposito = 2 - 2 min\n\n");
                    printf("\tCliente Consulta = 3 - 3,5 min\n\n");
                    printf("\tCliente Actualizacion = 4 - 5 min\n\n");
                    printf("\tCliente Pago = 5 - 2 min\n\n");
                    printf("\n\tMOSTRAR COLA\n\n");
                    mostrarCola();
                }
                system("\tpause");
                system("cls");
                break;

           case 4:
               printf("\n\tTiempo total de espera Cola...\n\n");
               printf("\tTiempo: %.1f min\n", tiempoTotal);
               system("\tpause");
               system("cls");
               break;

           case 5:
               system("cls");
               if(delante==NULL){
                printf("\n\n\tLa cola esta vacia...\n\n");
               }else{
                   desencolar();
                   printf("\n\n\tSe desencolo y elimino el cliente de manera satisfacctoria...\n\n");
               }
               system("pause");
               system("cls");
               break;

           case 0:
               exit(0);

               default: printf("\tOpcion invalida...\n\n");
       }
    }while(opcion!=0);
}

void cliente(){
    printf("\n\n");
    clientes[cantClientes].id=cantClientes;
    printf("\tNombre: ");
    fflush(stdin);
    fgets(clientes[cantClientes].nombre,30,stdin);
    printf("\tCedula: ");
    scanf("%d",&clientes[cantClientes].cedula);
    tipoTransaccion();
    mostrarCliente();
    encolar();
    cantClientes++;
}

void tipoTransaccion(){
    system("cls");
    printf("\n\n");
    printf("\tTIPO DE TRANSACCIONES\n\n");
    printf("\t1. Retiro\n");
    printf("\t2. Deposito\n");
    printf("\t3. Consulta\n");
    printf("\t4. Actualizacion\n");
    printf("\t5. Pagos\n");
    printf("\tTipo de transaccion a realizar: ");
    do{
        scanf("%d",&clientes[cantClientes].tipo);
    }while(clientes[cantClientes].tipo<0||clientes[cantClientes].tipo>5);
    system("cls");
}

void mostrarCliente(){
    system("cls");
    printf("\n\n");
    printf("\tMostrando Cliente\n\n");
    printf("\tNombre Cliente: %s", clientes[cantClientes].nombre);
    printf("\tCedula Cliente: %d\n", clientes[cantClientes].cedula);
    comprobacion();
}

void comprobacion(){
    if(clientes[cantClientes].tipo==1){
        printf("\tTipo de Transaccion: Retiro\n");
        printf("\tTiempo Transaccion: %.1f min\n", retiro);
        tiempoTotal+=retiro;
    }else if(clientes[cantClientes].tipo==2){
        printf("\tTipo de Transaccion: Deposito\n");
        printf("\tTiempo Transaccion: %.1f min\n", deposito);
        tiempoTotal+=deposito;
    }else if(clientes[cantClientes].tipo==3){
        printf("\tTipo de Transaccion: Consulta\n");
        printf("\tTiempo Transaccion: %.1f min\n", consulta);
        tiempoTotal+=consulta;
    }else if(clientes[cantClientes].tipo==4){
        printf("\tTipo de Transaccion: Actualizacion\n");
        printf("\tTiempo Transaccion: %.1f min\n", actualizacion);
        tiempoTotal+=actualizacion;
    }else if(clientes[cantClientes].tipo==5){
        printf("\tTipo de Transaccion: Pago\n");
        printf("\tTiempo Transaccion: %.1f min\n", pago);
        tiempoTotal+=pago;
    }
}

void encolar(){
    nodo *nueva_cola = new (struct nodo);
    nueva_cola->nro = clientes[cantClientes].tipo;
    nueva_cola->siguiente = NULL;

    if(delante==NULL){
        delante=nueva_cola;
    }else{
        atras->siguiente=nueva_cola;
    }
    atras=nueva_cola;
    printf("\tSe encolo perfectamente en la cola...\n\n");
}

void mostrarCola(){
    nodo *p_aux;
    p_aux = delante;

    while(p_aux!=NULL){
        printf("\t %d \n", p_aux->nro);
        p_aux=p_aux->siguiente;
    }
}

void mostrarClientes(){
    system("cls");
    printf("\n\tMOSTRANDO CLIENTES...\n\n");
    for(int i=0; i<cantClientes; i++){
        printf("\tNombre Cliente: %s", clientes[i].nombre);
        printf("\tCedula Cliente: %d\n", clientes[i].cedula);
        printf("\tTipo Transaccion Cliente #: %d\n", clientes[i].tipo);
        printf("\n\n");
    }
}

void desencolar(){
    nodo *p_aux;
    p_aux=delante;
    delante = (delante)->siguiente;
    delete(p_aux);
    eliminarCliente();
}

void eliminarCliente(){
    int idCli=0;
    for(int i=idCli; i<cantClientes; i++){
            clientes[i+1].id=idCli;
            strcpy(clientes[i].nombre,clientes[i+1].nombre);
            clientes[i].cedula=clientes[i+1].cedula;
            clientes[i].tipo=clientes[i+1].tipo;
        }
    cantClientes--;
}
