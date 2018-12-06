#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

FILE *archivo;
char direccion[] = "D:\\proyectoII.txt";

struct nodo{
    int dato;
    struct nodo *siguiente;
};

//Prototipos de funciones
void menuDatos(); //Escoger los datos a generar
void generarDatos(); //Genera los datos dependiendo de que se busca gestionar (pila, cola, lista)
void menu();
void menuPila();
void menuCola();
void menuLista();
void menuOrdenamiento();

//Prototipos de funciones pila
nodo *cima=NULL;
void apilar(nodo *&, int);
void mostrarPila(nodo *&);
void buscarPila(nodo *&, int);
void editarPila(nodo *&, int);
int eliminarDatoPila(nodo *&);
void eliminarPila(nodo *&);

//Prototipos de funciones Cola
nodo *delante=NULL;
nodo *atras=NULL;
void encolar(nodo *&, nodo *&, int);
void mostrarCola(nodo *&);
void buscarCola(nodo *&, int);
void editarCola(nodo *&, int);
int eliminarDatoCola(nodo *&);
void eliminarCola(nodo *&, nodo *&);

////Prototipos de funciones Lista
nodo *lista=NULL;
void listar(nodo *&, int);
void mostrarLista(nodo *&);
void buscarLista(nodo *&, int);
void editarLista(nodo *&, int);
void borrarDatoLista(nodo *&, int);
void eliminarLista(nodo *&);

void guardarArchivo(nodo *&);
void cargarArchivo();
void guardarDatosVec(nodo *&);

//Metodos de Ordenamiento
void burbuja();
void insercion();
void seleccion();
void shell();
void mostrarOrdenamiento();
void InsercionBinaria();

//Variables globales
int validacion, numero, almacen;
//Vector dinámico - almacena los datos para posteriormente ordenarlos
int vect[3000], contador;

int main(){
    system("color f1");
    menu();

    return 0;
}

void menu(){
    int opcion;
    do{
        printf("\tMENU DE GESTION\n");
        printf("\t1. Gestionar Pila\n");
        printf("\t2. Gestionar Cola\n");
        printf("\t3. Gestionar Lista\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            validacion=1; //Validacion guardara que se desea gestionar para poder darle vida a la funcion generar datos
            menuPila();
            break;

        case 2:
            system("cls");
            validacion=2; //Validacion guardara que se desea gestionar para poder darle vida a la funcion generar datos
            menuCola();
            break;

        case 3:
            system("cls");
            validacion=3; //Validacion guardara que se desea gestionar para poder darle vida a la funcion generar datos
            menuLista();
            break;

        case 0:
            exit(0);

            default: printf("Opcion invalida...\n");
        }
    }while(opcion!=0);
}

void menuPila(){
    int opcion;
    do{
        printf("\tMENU PILA\n");
        printf("\t1. Generar Datos\n");
        printf("\t2. Ver Datos\n");
        printf("\t3. Buscar Dato\n");
        printf("\t4. Editar Dato\n");
        printf("\t5. Eliminar Dato\n");
        printf("\t6. Eliminar Pila\n");
        printf("\t7. Guardar Datos\n");
        printf("\t8. Cargar Datos\n");
        printf("\t9. Ordenar Datos\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            menuDatos();
            generarDatos();
            printf("\tSe insertaron correctamente en la pila...\n");
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
            printf("\tMOSTRANDO PILA...\n\n");
            mostrarPila(cima);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
                printf("\tIngrese el elemento a buscar: ");
                scanf("%d",&numero);
                buscarPila(cima,numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
                printf("\tIngrese el elemento a buscar: ");
                scanf("%d",&numero);
                editarPila(cima,numero);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
                numero=eliminarDatoPila(cima);
                printf("\tSe elimino el numero %d correctamente...\n", numero);
            }
            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
                eliminarPila(cima);
                printf("\tSe elimino la pila correctamente...\n");
            }
            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
                guardarArchivo(cima);
            }
            system("pause");
            system("cls");
            break;

        case 8:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
            cargarArchivo();
            }
            system("pause");
            system("cls");
            break;

            case 9:
            system("cls");
            if(cima==NULL){
                printf("\tLa pila esta vacia...\n");
            }else{
            guardarDatosVec(cima);
            menuOrdenamiento();
            }
            system("cls");
            break;

        case 0:
            system("cls");
            menu();

            default: printf("\tOpcion Invalida...\n");
        }
    }while(opcion!=0);
}

void menuDatos(){
    int opcion;

        printf("\tMENU DATOS\n");
        printf("\t1. 100 Datos\n");
        printf("\t2. 200 Datos\n");
        printf("\t3. 500 Datos\n");
        printf("\t4. 1000 Datos\n");
        printf("\t5. 1500 Datos\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            almacen=100;
            break;
        case 2:
            almacen=200;
            break;
        case 3:
            almacen=500;
            break;
        case 4:
            almacen=1000;
            break;
        case 5:
            almacen=1500;
            break;
        case 0:
            system("cls");
            menu();
            break;

            default: printf("\tOpcion Invalida...\n");
        }
}

void generarDatos(){
    int i;
    srand(time(NULL));
    for(i=0; i<almacen; i++){
        numero = rand()%2000; //Genera numeros entre 0 - 5000
        if(validacion==1){
            apilar(cima,numero);
        }else if(validacion==2){
            encolar(delante,atras,numero);
        }else if(validacion==3){
            listar(lista,numero);
        }
    }
}

void apilar(nodo *&cima, int numero){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();

    nuevo_nodo->dato=numero;
    nuevo_nodo->siguiente=cima;
    cima=nuevo_nodo;
}

void mostrarPila(nodo *&cima){
    int c=1;
    nodo *aux;
    aux=cima;

    while(aux!=NULL){
        printf("\t%d. %d\n", c, aux->dato);
        aux=aux->siguiente;
        c++;
    }
}

void buscarPila(nodo *&cima, int numero){
    nodo *aux;
    aux=cima;
    bool bandera=false;

    while(aux!=NULL){
        if(aux->dato==numero){
            bandera=true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("\tSe encontro el numero %d en la pila\n", numero);
    }else if(bandera==false){
        printf("\tNo se encontro el numero en la pila\n");
    }
}

void editarPila(nodo *&cima, int numero){
    nodo *aux;
    aux=cima;
    bool bandera=false;

    while(aux!=NULL){
        if(aux->dato==numero){
            printf("\tIngrese el nuevo numero: ");
            scanf("%d",&numero);
            aux->dato=numero;
            printf("\tSe edito el numero correctamente...\n");
            system("pause");
            system("cls");
            menuPila();
        }
        aux=aux->siguiente;
    }

    if(bandera==false){
        printf("\tNo se encontro el numero en la pila\n");
    }
}

int eliminarDatoPila(nodo *&cima){
    int n;
    nodo *aux;
    aux=cima;

    n=aux->dato;
    cima=(cima)->siguiente;
    delete(aux);

    return n;
}

void eliminarPila(nodo *&cima){
    nodo *aux;

    while(cima!=NULL){
        aux=cima;
        cima=cima->siguiente;
        delete aux;
    }
}

void guardarArchivo(nodo *&inicio){
    nodo *aux;
    aux=inicio;

    archivo = fopen(direccion,"w");
    if(archivo==NULL){
        printf("\tError al abrir el archivo...\n");
        menuPila();
    }else{
        while(aux!=NULL){
            fprintf(archivo, "%d\n", aux->dato);
            aux=aux->siguiente;
        }
    }
    fclose(archivo);
    printf("\tSe guardo en el archivo correctamente...\n");
}

void cargarArchivo(){
    printf("\tCARGANDO ARCHIVO...\n\n");

    archivo = fopen(direccion,"r");

    if(archivo==NULL){
        printf("\tError al abrir el archivo...\n");
        menuPila();
    }else{
        while(!feof(archivo)){ //Leer archivo hasta el final
            fscanf(archivo, "%d\n", &numero);
            printf("\t%d\n", numero);
        }
    }
    fclose(archivo);
}

void menuCola(){
    int opcion;
    do{
        printf("\tMENU COLA\n");
        printf("\t1. Generar Datos\n");
        printf("\t2. Ver Datos\n");
        printf("\t3. Buscar Dato\n");
        printf("\t4. Editar Dato\n");
        printf("\t5. Eliminar Dato\n");
        printf("\t6. Eliminar Cola\n");
        printf("\t7. Guardar Datos\n");
        printf("\t8. Cargar Datos\n");
        printf("\t9. Ordenar Datos\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            menuDatos();
            generarDatos();
            printf("\tSe insertaron los datos correctamente...\n");
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(delante==NULL){
                printf("\tLa cola esta vacia...\n");
            }else{
                printf("\tMOSTRANDO COLA...\n\n");
                mostrarCola(delante);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(delante==NULL){
                printf("\tLa cola esta vacia...\n");
            }else{
                printf("\tIngrese el elemento a buscar: ");
                scanf("%d",&numero);
                buscarCola(delante,numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(delante==NULL){
                printf("\tLa cola esta vacia...\n");
            }else{
                printf("\tIngrese el numero a buscar: ");
                scanf("%d",&numero);
                editarCola(delante,numero);
            }

        case 5:
            system("cls");
            if(delante==NULL){
                printf("\tLa cola esta vacia...\n");
            }else{
                numero=eliminarDatoPila(delante);
                printf("\tSe elimino correctamente el elemento %d de la Cola\n", numero);
            }
            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");
            if(delante==NULL){
                printf("\tLa cola esta vacia...\n");
            }else{
                eliminarCola(delante,atras);
                printf("\tSe elimino la Cola Correctamente...\n");
            }
            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");
            if(delante==NULL){
                printf("\nLa cola esta vacia...\n");
            }else{
                guardarArchivo(delante);
            }
            system("pause");
            system("cls");
            break;

        case 8:
            system("cls");
            if(delante==NULL){
                printf("\nLa cola esta vacia...\n");
            }else{
                cargarArchivo();
            }
            system("pause");
            system("cls");
            break;

            case 9:
            system("cls");
            if(delante==NULL){
                printf("\tLa Cola esta vacia...\n");
            }else{
            guardarDatosVec(delante);
            menuOrdenamiento();
            }
            system("cls");
            break;

        case 0:
            system("cls");
            menu();

            default: printf("Opcion Invalida...\n");
        }
    }while(opcion!=0);
}

void encolar(nodo *&delante, nodo *&atras, int numero){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();

    nuevo_nodo->dato=numero;
    nuevo_nodo->siguiente=NULL;

    if(delante==NULL){
        delante=nuevo_nodo;
    }else{
        atras->siguiente=nuevo_nodo;
    }
    atras=nuevo_nodo;
}

void mostrarCola(nodo *&delante){
    int c=1;
    nodo *aux;
    aux=delante;

    while(aux!=NULL){
        printf("\t%d. %d\n", c, aux->dato);
        aux=aux->siguiente;
        c++;
    }
}

void buscarCola(nodo *&delante, int numero){
    nodo *aux;
    aux=delante;
    bool bandera=false;

    while(aux!=NULL){
        if(aux->dato==numero){
            bandera=true;
        }
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("\tSe encontro el numero %d en la cola...\n", numero);
    }else if(bandera==false){
        printf("\tNo se encontro el numero en la cola\n");
    }
}

void editarCola(nodo *&delante, int numero){
    nodo *aux;
    aux=delante;
    bool bandera=false;

    while(aux!=NULL){
        if(aux->dato==numero){
            printf("\tIngrese el nuevo numero: ");
            scanf("%d",&numero);
            aux->dato=numero;
            printf("\tSe edito el numero correctamente...\n");
            system("pause");
            system("cls");
            menuCola();
        }
        aux=aux->siguiente;
    }

    if(bandera==false){
        printf("\tNo se encontro el numero en la pila\n");
    }
}

int eliminarDatoCola(nodo *&delante){
    int x;
    nodo *aux;

    aux=delante;
    x=aux->dato;
    delante=delante->siguiente;
    delete aux;

    return x;
}

void eliminarCola(nodo *&delante, nodo *&atras){
    nodo *aux;

    while(delante!=NULL){
        aux=delante;
        delante=delante->siguiente;
        delete aux;
    }

    delante=NULL;
    atras=NULL;
}

void menuLista(){
    int opcion;
    do{
        printf("\tMENU LISTA\n");
        printf("\t1. Generar Datos\n");
        printf("\t2. Ver Datos\n");
        printf("\t3. Buscar Dato\n");
        printf("\t4. Editar Dato\n");
        printf("\t5. Eliminar Dato\n");
        printf("\t6. Eliminar Lista\n");
        printf("\t7. Guardar Datos\n");
        printf("\t8. Cargar Datos\n");
        printf("\t9. Ordenar Datos\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            system("cls");
            menuDatos();
            generarDatos();
            printf("\tSe generaron los Numeros Correctamente...\n");
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                printf("\tMOSTRANDO LISTA...\n\n");
                mostrarLista(lista);
            }
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                printf("\tIngrese el numero a buscar: ");
                scanf("%d",&numero);
                buscarLista(lista, numero);
            }
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                printf("\tIngrese el numero a buscar: ");
                scanf("%d",&numero);
                editarLista(lista, numero);
            }
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                printf("\tIngrese el numero a Borrar: ");
                scanf("%d",&numero);
                borrarDatoLista(lista, numero);
            }
            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                eliminarLista(lista);
            }
            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                guardarArchivo(lista);
            }
            system("pause");
            system("cls");
            break;

        case 8:
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
                cargarArchivo();
            }
            system("pause");
            system("cls");
            break;

            case 9:
            system("cls");
            if(lista==NULL){
                printf("\tLa lista esta vacia...\n");
            }else{
            guardarDatosVec(lista);
            menuOrdenamiento();
            }
            system("cls");
            break;

        case 0:
            system("cls");
            menu();
            break;

            default: printf("Opcion Invalida...\n");
        }
    }while(opcion!=0);
}

void listar(nodo *&lista, int numero){
    nodo *nuevo_nodo;
    nuevo_nodo = new struct nodo();
    nuevo_nodo->dato = numero;

    //Siempre nos referencia al ultimo elemento de la lista y es siempre NULL para los condicionales de insertar
    nodo *aux1=lista; //En el primer paso lista es igual a NULL entonces aux1 sera NULL
    nodo *aux2;

    //Mientras aux1 sea diferente NULL y aux1 apuntando dato sea menor que el valor ingresado entra al WHILE
    //Si no entra el WHILE aux1 siempre sera igual a LISTA como declaramos arriba
    while((aux1!=NULL)&&(aux1->dato<numero)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    //Si lista es igual a aux1, NULL=NULL entonces
    if(lista==aux1){
        lista=nuevo_nodo;
        //Si no, aux2 apuntando a siguiente es igual al nuevo nodo
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    //Siempre se ejecuta, nuevo nodo apuntando a siguiente siempre sera NULL osea aux1
    nuevo_nodo->siguiente=aux1;
}

void mostrarLista(nodo *&lista){
    nodo *aux = new nodo();
    aux=lista;

    while(aux!=NULL){
        printf("%d -> ", aux->dato);
        aux=aux->siguiente;
    }
}

void buscarLista(nodo *&lista, int numero){
    bool bandera=false;
    //puntero auxiliar de tipo nodo
    nodo *aux = new struct nodo();
    aux=lista;

    //Mientras aux sea diferente de NULL y aux->dato sea menor o igual al numero
    while((aux!=NULL)&&(aux->dato<=numero)){
            //Pregunte, aux->dato es igual al numero
        if(aux->dato==numero){
            bandera=true;
        }
        //aux = aux apuntando a siguiente
        aux=aux->siguiente;
    }

    if(bandera==true){
        printf("\tSe encontro el numero %d en la Lista\n", numero);
    }else{
        printf("\tNo se encontro el numero en la Lista\n");
    }
}

void editarLista(nodo *&lista, int numero){
    bool bandera=false;
    //puntero auxiliar de tipo nodo
    nodo *aux = new struct nodo();
    aux=lista;

    //Mientras aux sea diferente de NULL y aux->dato sea menor o igual al numero
    while((aux!=NULL)&&(aux->dato<=numero)){
            //Pregunte, aux->dato es igual al numero
        if(aux->dato==numero){
            printf("\tIngrese el nuevo numero: ");
            scanf("%d",&numero);
            aux->dato=numero;
            printf("\tSe edito el numero correctamente...\n");
            system("pause");
            system("cls");
            menuLista();
        }
        //aux = aux apuntando a siguiente
        aux=aux->siguiente;
    }

    if(bandera==false){
        printf("\tNo se encontro el numero en la Lista\n");
    }
}

void borrarDatoLista(nodo *&lista, int numero){
    int x;

    if(lista!=NULL){
        nodo *aux1;
        nodo *aux2=NULL;
        aux1=lista;

        //Mientras aux1 sea diferente de NULL y aux1 sea diferente del numero entra al WHILE
        while((aux1!=NULL)&&(aux1->dato!=numero)){
            aux2=aux1;
            aux1=aux1->siguiente;
        }

        //Si aux1 es igual a NULL es porque no se encuentro el elemento
        if(aux1==NULL){
            printf("\tEl elemento no existe\n");
            //Si aux2 es igual a NULL es porque se encontro en el primer elemento
        }else if(aux2==NULL){
            lista=lista->siguiente;
            printf("\tElemento %d eliminado\n", numero);
            delete aux1;
        }else{
            /*Aux2 apuntara a siguiente y sera igual a aux1 que apunta a siguiente y esto eliminara el nodo que esta en medio osea aux1
            y tambien se puede presentar que aux1 apuntando a siguiente sea NULL que haria referencia al ulimo elemento de la lista
            entonces aux2->siguiente quedaria apuntando a NULL*/
            aux2->siguiente=aux1->siguiente;
            printf("\tElemento %d eliminado\n", numero);
            delete aux1;
        }
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

void menuOrdenamiento(){
    int opcion;
        printf("\tMENU DE ORDENAMIENTO...\n");
        printf("\t1. Ordenamiento Burbuja\n");
        printf("\t2. Ordenamiento Insercion\n");
        printf("\t3. Ordenamiento Seleccion\n");
        printf("\t4. Ordenamiento Shell\n");
        printf("\t5. Ordenamiento Insercion Binaria\n");
        printf("\t0. Salir\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("cls");
                burbuja();
                mostrarOrdenamiento();
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                insercion();
                mostrarOrdenamiento();
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                seleccion();
                mostrarOrdenamiento();
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                shell();
                mostrarOrdenamiento();
                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                InsercionBinaria();
                mostrarOrdenamiento();
                system("pause");
                system("cls");
                break;

            default: printf("\tOpcion Invalida...\n");
        }
}

void guardarDatosVec(nodo *&inicio){
    contador=0;
    nodo *aux;
    aux=inicio;

    while(aux!=NULL){
        vect[contador] = aux->dato;
        aux = aux->siguiente;
        contador++;
    }
}

//Metodo de ordenacion burbuja
void burbuja(){
    int aux, i, j;
    for(i=0; i<contador; i++){
        for(j=0; j<contador-1; j++){
            if(vect[j]>vect[j+1]){
                aux=vect[j];
                vect[j]=vect[j+1];
                vect[j+1]=aux;
            }
        }
    }
}

//Metodo de ordenacion insercion
void insercion(){
    int i, pos, aux;

    for(i=0; i<contador; i++){
        //Posicion actual del vector
        pos=i;
        //Elemento actual del vector
        aux=vect[i];

        //Mientras posicion sea mayor que 0 y pos -1 sea mayor que aux entra al WHILE
        while((pos>0)&&(vect[pos-1]>aux)){
            //Posicion actual guarda posicion -1
            vect[pos] = vect[pos-1];
            //Pos-- Nos permite guardar el elemento menor al comienzo del vector
            pos--;
        }
        //Pos actual será igual al aux que estaba intercambiando de posicion
        vect[pos]=aux;
    }
}

void seleccion(){
    int i, j, aux, mini;

    for(i=0; i<contador; i++){
        //Igualamos mini con la posicion i
        mini=i;
        //For desde j en la posicion i + 1
        for(j=i+1; j<contador; j++){
            //Comprobamos quien es el verdadero mini del arreglo
            if(vect[j] < vect[mini]){
                mini = j;
            }
        }
        //aux sera igual al arreglo en la posicion i
        aux = vect[i];
        //arreglo en la posicion i sera igual a mini
        vect[i] = vect[mini];
        //arreglo en la posicion mini sera igual al aux
        vect[mini] = aux;
    }
}

void shell(){
    int particion, i, aux;
    bool band;

    particion=contador;

    while(particion>1){
        particion=(particion/2);
        band=true;

    while(band==true){
        band=false;
        i=0;
        while((i+particion)<=contador){
            if(vect[i]>vect[i+particion]){
                aux = vect[i];
                vect[i] = vect[i+particion];
                vect[i+particion] = aux;
                band=true;
            }
            i++;
        }
     }
   }
}

void InsercionBinaria() {
  int i, y, m, tmp, izq, der;

  for(i = 1; i < contador; i++) {
    tmp = vect[i];
    izq = 0;
    der = i - 1;

    while (izq <= der) {
      m = (izq + der) / 2;
      if(tmp < vect[m]) {
        der = m - 1;
      } else {
        izq = m + 1;
      }
    }

    y = i - 1;
    while (y >= izq) {
      vect[y+1] = vect[y];
      y = y - 1;
    }
    vect[izq] = tmp;
  }
}

void mostrarOrdenamiento(){
    int i;

    printf("\tMOSTRANDO ASCENDENTE...\n");
    for(i=0; i<contador; i++){
        printf("%d -> ", vect[i]);
    }

    printf("\n\n\tMOSTRANDO DESCENDENTE...\n");
    for(i=contador-1; i>=0; i--){
        printf("%d -> ", vect[i]);
    }
    printf("\n");
}
