#include <stdlib.h>
#include <stdio.h>

FILE *archivo;
char direccion[] = "D:\\ejercicio_cola.txt";

struct nodo{
    int numero;
    struct nodo *siguiente;
};

void menu();
void encolar(nodo *&, nodo *&, int);
int desencolar(nodo *&);
void mostrarCola(nodo *&);
void guardarArchivo(nodo *&);
void cargarArchivo();
void guardarDatosV(nodo *&);
void burbuja();
void mostrarDescendente();
void mostrarAscendente();

//Variables globales
int contador, *c;

int main()
{
    system("color 0a");
    int opcion, numero;
    nodo *delante=NULL;
    nodo *atras=NULL;

    do{
    printf("\tMENU DE COLAS\n\n");
    printf("\t1. Encolar\n");
    printf("\t2. Desencolar\n");
    printf("\t3. Mostrar Cola\n");
    printf("\t4. Guardar en Archivo\n");
    printf("\t5. Cargar desde Archivo\n");
    printf("\t6. Mostrar Datos de forma Descendente\n");
    printf("\t7. Mostrar Datos de forma Ascendente\n");
    printf("\t0. Salir\n");
    printf("\n\n\tIngrese opcion: ");
    scanf("%d",&opcion);
    switch(opcion){
    case 1:
        printf("\n\tIngrese un numero: "); scanf("%d",&numero);
        encolar(delante,atras,numero);
        printf("\tSe encolo el numero %d de manera satisfacctoria...\n\n", numero);
        system("\tpause");
        system("cls");
        break;

    case 2:
        if(delante==NULL){
            printf("\n\tLa cola esta vacia...\n\n");
        }else{
        numero = desencolar(delante);
        printf("\n\tEl numero %d se desencolo perfectamente...\n", numero);
        }
        system("\tpause");
        system("cls");
        break;

    case 3:
        if(delante==NULL){
            printf("\n\tLa cola esta vacia...\n");
        }else{
        mostrarCola(delante);
        }
        system("\tpause");
        system("cls");
        break;

    case 4:
        if(delante==NULL){
            printf("\n\tLa cola esta vacia...\n");
        }else{
        printf("\n\tGuardando en archivo...\n\n");
        guardarArchivo(delante);
        printf("\tSe guardo correctamente en el archivo...\n\n");
        }
        system("\tpause");
        system("cls");
        break;

    case 5:
        printf("\n\tCargando archivo...\n\n");
        cargarArchivo();
        printf("\n\tSe cargo el archivo correctamente...\n");
        system("\tpause");
        system("cls");
        break;

    case 6:
        if(delante==NULL){
            printf("\n\tLa cola esta vacia...\n");
        }else{
        guardarDatosV(delante);
        printf("\n\tOrdenando datos con Burbuja...\n\n");
        burbuja();
        mostrarDescendente();
        }
        system("\tpause");
        system("cls");
        break;

    case 7:
        if(delante==NULL){
            printf("\n\tLa pila esta vacia...\n");
        }else{
        guardarDatosV(delante);
        printf("\n\tOrdenando datos con Burbuja...\n\n");
        burbuja();
        mostrarAscendente();
        }
        system("\tpause");
        system("cls");
        break;

    case 0:
        exit(0);

        default: printf("\n\tOpcion invalida...\n");
        system("\tpause");
        system("cls");
       }
    }while(opcion!=0);

    return 0;
}

void encolar(nodo *&delante, nodo *&atras, int numero){
    nodo *nueva_cola = new (struct nodo);
    nueva_cola->numero=numero;
    nueva_cola->siguiente=NULL;

    if(delante==NULL){
        delante=nueva_cola;
    }else{
        atras->siguiente=nueva_cola;
    }
    atras=nueva_cola;
}

int desencolar(nodo *&delante){
    int n;
    nodo *p_aux;
    p_aux=delante;
    n=p_aux->numero;
    delante=(delante)->siguiente;
    delete(p_aux);
    return n;
}

void mostrarCola(nodo *&delante){
    nodo *p_aux;
    p_aux=delante;
    printf("\n\tMostrando cola...\n\n");
    while(p_aux!=NULL){
        printf("\t %d\n", p_aux->numero);
        p_aux=p_aux->siguiente;
    }
}

void guardarArchivo(nodo *&delante){
    nodo *p_aux;
    p_aux = delante;
    archivo = fopen(direccion,"w"); //Crear archivo o abrir archivo
    if(archivo==NULL){ //No se pudo abrir el archivo
        printf("\tError al crear o abrir el archivo...\n\n");
    }else{
        while(p_aux!=NULL){
            fprintf(archivo, "%d\n", p_aux->numero);
            p_aux=p_aux->siguiente;
        }
    }
    fclose(archivo);
}

void cargarArchivo(){
    int dato;
    archivo = fopen(direccion,"r"); //Leer el archivo
    if(archivo==NULL){
        printf("\tError al tratar de leer el archivo...\n\n");
    }else{
        while(!feof(archivo)){ //Leer numero a numero hasta el final del Archivo
            fscanf(archivo,"%d\n",&dato);
            printf("\t%d\n", dato);
        }
    }
    fclose(archivo);
}

//Funcion para guardar datos en el vector dinamico para despues utilizarlo en el metodo burbuja
void guardarDatosV(nodo *&delante){
    contador=0;
    nodo *p_aux;
    p_aux = delante;
    c = new int[contador];
    while(p_aux!=NULL){
        c[contador] = p_aux->numero;
        p_aux=p_aux->siguiente;
        contador++;
    }
}

void burbuja(){
    int i,j,aux;
    for(i=0; i<contador; i++){
        for(j=0; j<contador-1; j++){
            if(c[j]<c[j+1]){
                aux = c[j];
                c[j] = c[j+1];
                c[j+1] = aux;
            }
        }
    }
    printf("\n\tSe ordeno por burbuja correctamente...\n\n");
}

void mostrarDescendente(){
    int i;
    printf("\n\n\tMostrando datos en forma Descendente\n");
    for(i=0; i<contador; i++){
        printf("\t%d\n", c[i]);
    }
    printf("\n\tSe mostraron los datos correctamente...\n");
}

void mostrarAscendente(){
    int i;
    printf("\n\n\tMostrando datos en forma Ascendente\n");
    for(i=contador-1; i>=0; i--){
        printf("\t%d\n", c[i]);
    }
    printf("\n\tSe mostraron los datos correctamente...\n");
}



