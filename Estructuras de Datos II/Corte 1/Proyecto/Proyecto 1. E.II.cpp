#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//Estructuras con Punteros

struct entradas{
    int cedulaCliente;
    char nombrePelicula[30];
    int cantidad;
}entrada[100], *pentrada = entrada;

struct cliente{
    int id;
    char nombre[30];
    int cedula;
    char direccion[45];
    int telefono;
}clientes[100], *pclientes = clientes;

struct pelicula{
    int id;
    char nombre[30];
    int referencia;
    float valor;
    int sillas;
    int escogeSilla[10][5];
    char hora[10];
}peliculas[100], *ppeliculas = peliculas;

//Prototipo de Funciones
void gotoxy(int, int);
void menu();
void menuCliente();
void crearCliente();
void mostrarClientes();
void editarCliente();
int buscarCliente();
void mostrarCliente(int);
void cambioNombre(int *);
void cambioDireccion(int *);
void cambioTelefono(int *);
void eliminarCliente();
void margen();
void dibujo();
void menuPeliculas();
void agregarPelicula();
void mostrarPeliculas();
int buscarPelicula();
void mostrarPelicula(int);
void eliminarPelicula();
void editarPelicula();
void peliculaCambioNombre(int *);
void peliculaCambioValor(int *);
void peliculaCambioSillas(int *);
void peliculaCambioHora(int *);
void menuEntradas();
void comprarTiquete();
void mostrarTiquete(int, int);
void margenTiquete();
void escogerSilla(int, int);
void llenarMatriz();
void mostrarAsientos(int);
void numeracionAsientos();
void mostrarEntradasCliente();
void mostrarEntradasPelicula();

//Variables Globales
int nClientes=0;
int nPeliculas=0;
int nEntrada=0;

int main()
{
    //dibujo(); system("pause"); system("cls");

    //Menu Principal
    system("color 71");
    menu();

    return 0;
}

//Funcion gotoxy para las Margenes
void gotoxy(int x,int y){
    //Gotoxy para x y y (hacer cuadro)
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menu(){
    int opcion;
    do{
        margen();
        gotoxy(33,8);
        printf("CINEMA CINESMART\n");
        gotoxy(27,12);
        printf("1. Clientes\n");
        gotoxy(27,14);
        printf("2. Peliculas\n");
        gotoxy(27,16);
        printf("3. Entradas\n");
        gotoxy(27,18);
        printf("0. Salir\n");
        gotoxy(27,20);
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: system("cls");
                menuCliente();
                system("cls");
                break;
            case 2: system("cls");
                menuPeliculas();
                system("cls");
                break;
            case 3: system("cls");
                menuEntradas();
                system("cls");
                break;
            case 0: system("cls");
                printf("Hasta Pronto\n");
                exit(0);
            default: printf("Opcion no valida\n");
        }
    }while(opcion!=0);
}

//Menu Clientes
void menuCliente(){
    int opcion;
    do{
        margen();
        gotoxy(34,8);
        printf("MENU CLIENTES\n");
        gotoxy(27,12);
        printf("1. Crear Cliente\n");
        gotoxy(27,14);
        printf("2. Mostrar Clientes\n");
        gotoxy(27,16);
        printf("3. Editar Cliente\n");
        gotoxy(27,18);
        printf("4. Buscar Cliente\n");
        gotoxy(27,20);
        printf("5. Eliminar Cliente\n");
        gotoxy(27,22);
        printf("0. Salir\n");
        gotoxy(27,24);
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: system("cls");
                crearCliente();
                system("cls");
                break;
            case 2: system("cls");
                mostrarClientes();
                system("pause");
                system("cls");
                break;
            case 3: system("cls");
                editarCliente();
                system("pause");
                system("cls");
                break;
             case 4: system("cls");
                buscarCliente();
                system("pause");
                system("cls");
                break;
            case 5: system("cls");
                eliminarCliente();
                system("pause");
                system("cls");
                break;
            case 0: system("cls");
                menu();
            default: printf("Opcion no valida\n");
        }
    }while(opcion!=0);
}

void crearCliente(){
    //Creamos Cliente
    gotoxy(33,5);
    printf("Crear Cliente\n\n");
	fflush(stdin);
	printf("Cliente No. %d\n", nClientes + 1);
	(pclientes+nClientes)->id = nClientes;
	printf("Nombre del Cliente: ");
	fgets((pclientes+nClientes)->nombre, 30, stdin);
	printf("\n");
	printf("Cedula del Cliente: ");
	scanf("%d", &(pclientes+nClientes)->cedula);
	printf("\n");
	fflush(stdin);
	printf("Direccion del Cliente: ");
	fgets((pclientes+nClientes)->direccion, 45, stdin);
	printf("\n");
	printf("Telefono del Cliente: ");
	scanf("%d",&(pclientes+nClientes)->telefono);
	printf("\n");
	nClientes += 1;
}

void mostrarClientes(){
    gotoxy(32,5);
    printf("Mostrar Clientes\n\n");
    for(int i=0; i<nClientes; i++){
	       printf("Cliente No. %d\n\n", (pclientes+i)->id + 1);
	       printf("Nombre del Cliente: %s\n", (pclientes+i)->nombre);
	       printf("Cedula del Cliente: %d\n\n", (pclientes+i)->cedula);
	       printf("Direccion del Cliente: %s\n", (pclientes+i)->direccion);
	       printf("Telefono del Cliente: %d\n", (pclientes+i)->telefono);
	       printf("\n\n");
    }
}

void editarCliente(){
    //Editar Cliente
    int idCliente, *pidCliente, opcion;
    gotoxy(33,3);
    printf("Editar Cliente\n\n");
    idCliente = buscarCliente();
    pidCliente = &idCliente;
    if(*pidCliente != -1){
            do{
                margen();
                gotoxy(33,8);
                printf("Cambios Cliente\n");
                gotoxy(27,12);
                printf("1. Cambiar Nombre\n");
                gotoxy(27,14);
                printf("2. Cambiar Direccion\n");
                gotoxy(27,16);
                printf("3. Cambiar Telefono\n");
                gotoxy(27,18);
                printf("0. Salir\n");
                gotoxy(27,22);
                printf("Ingrese una opcion: ");
                scanf("%d",&opcion);
                switch(opcion){
                case 1: system("cls");
                cambioNombre(pidCliente);
                system("cls");
                break;
                case 2: system("cls");
                cambioDireccion(pidCliente);
                system("cls");
                break;
                case 3: system("cls");
                cambioTelefono(pidCliente);
                system("cls");
                break;
                case 0: system("cls");
                menuCliente();
                default: printf("Opcion no valida\n");
                }
            }while(opcion!=0);
    }
}

int buscarCliente(){
    //Buscar Cliente
    int cedula, *pCedula;
    gotoxy(33,5);
    printf("Buscar Cliente\n\n");
    printf("Ingrese la cedula del Cliente: ");
    scanf("%d",&cedula);
    pCedula=&cedula;
    for(int i=0; i<nClientes; i++){
        if(*pCedula == (pclientes+i)->cedula){
            mostrarCliente((pclientes+i)->id);
            return (pclientes+i)->id;
        }
    }
    printf("No se encuentra Registrado\n");
    return -1;
}

void mostrarCliente(int idCliente){
    //Mostrar Cliente Buscado
    printf("\n\n");
    printf("Mostrar Cliente\n\n");
    printf("Cliente No. %d\n\n", (pclientes+idCliente)->id + 1);
    printf("Nombre del Cliente: %s\n", (pclientes+idCliente)->nombre);
    printf("Cedula del Cliente: %d\n\n", (pclientes+idCliente)->cedula);
    printf("Direccion del Cliente: %s\n", (pclientes+idCliente)->direccion);
    printf("Telefono del Cliente: %d\n", (pclientes+idCliente)->telefono);
    printf("\n\n");
    system("pause");
    system("cls");
}

void cambioNombre(int *pidCliente){
    //Cambio Nombre
    gotoxy(20,5);
    printf("Ingrese su nombre: ");
    fflush(stdin);
    fgets((pclientes+*pidCliente)->nombre, 30, stdin);
}

void cambioDireccion(int *pidCliente){
    //Cambio Direccion
    gotoxy(20,5);
    printf("Ingrese su direccion: ");
    fflush(stdin);
    fgets((pclientes+*pidCliente)->direccion, 45, stdin);
}

void cambioTelefono(int *pidCliente){
    //Cambio Telefono
    gotoxy(20,5);
    printf("Ingrese su telefono: ");
    scanf("%d",&(pclientes+*pidCliente)->telefono);
}

void eliminarCliente(){
    //Eliminar cliente
    int idCliente, *pidCliente = &idCliente;
    idCliente = buscarCliente();
    if(*pidCliente != -1){
        if(*pidCliente < nClientes){
            for(int i=*pidCliente; i<nClientes; i++){
                (pclientes+i+1)->id = i;
                strcpy((pclientes+i)->nombre,(pclientes+i+1)->nombre);
                (pclientes+i)->cedula = (pclientes+i+1)->cedula;
                strcpy((pclientes+i)->direccion,(pclientes+i+1)->direccion);
                (pclientes+i)->telefono = (pclientes+i+1)->telefono;
            }
        }
        nClientes--;
        printf("Se Elimino el Cliente\n");
    }else{
        printf("No se puede Eliminar\n");
    }
}

void margen(){
    int i;
    for(i=26; i<=54; i++){
        gotoxy(i,6); printf("%c",205);
        gotoxy(i,26); printf("%c",205);
        gotoxy(i,10); printf("%c",205);
    }
    gotoxy(25,6); printf("%c",201);
    gotoxy(55,6); printf("%c",187);
    gotoxy(25,26); printf("%c",200);
    gotoxy(55,26); printf("%c",188);

    for(i=7; i<=25; i++){
        gotoxy(25,i); printf("%c",186);
        gotoxy(55,i); printf("%c",186);
    }
}

void dibujo(){
system("color 47");

printf("................................................-=#==:.........................\n");

printf("...............................................==:*:--**=.-*=*:..:@=*#.........\n");

printf(".......................................-:...-:-----------#++*:--+@:+*:+........\n");

printf(".....................................+*::-:W++::==#*:--::::**+---=*:-:*-:......\n");

printf("....................................:##--:#+:+:::-:----------------=----=-...-.\n");

printf("..................................:*++:---#*:----=#:-:----:+-----:------+#*-+::\n");

printf("..................................-=:+:--------+**::::::*#=::+--------------:+:\n");

printf("...................................#@-----------::------:::-+:------*:-----+=@W\n");

printf("...................................==+#@*:---:*=#:--::=:------+==@@*::+=@@#=**#\n");

printf("...................................*#:::++*=#@@##WWW*+++::++**=#@W@#=********#@\n");

printf("...................................:W@@#=+++++++++++++++++++++++++++++*****@=**\n");

printf("....................................#*--:#*++++++++++++++++++++++++++****=@*+#:\n");

printf("....................................*#---::*==***=@#+++++*@#**=@**#=:++**++++@.\n");

printf("....................................-@---:::::::::::*@WW#+:::::::::::+++++++==.\n");

printf(".....................................#:--::::::::::::::::::::::::::::+++++++@:.\n");

printf(".....................................+*--::::::::::::::::::::::::::::++++++*W..\n");

printf("......................................#---::::::::::::::::::::::::::+++++++##..\n");

printf("......................................#---::::::::::::::::::::::::::+++++++@+..\n");

printf("...........................-:+**+:....*+--::::::::::::::::::::::::::+++++++W-..\n");

printf("..................:*=#=*+::::::::::=*.:#--::::::::::::::::::::::::::++++++*@...\n");

printf(".........-+===*::::::+*===+-....-#::#-.@:--:::::::::::::::::::::::::++++++==...\n");

printf("...:=#=+::::::::::==-..............-...#*#*:::::::::::::::::::::::::++++++@:...\n");

printf("#=#=*:::::::::+#*......................**:=W*:::::::::::::::::::::::*@W@#*W....\n");

printf("#:::::*#WW@#W=.........................:#::+=@WW@@@@*:::::::::::+=#@@@####@....\n");

printf("=:@#=@@=+:::*#WW@*-.....................#:::++++++++*W=*@@#@W#*::::::*+:::*@-..\n");

printf("=:#=***::+=#@#*+::+=#WW#*:..............=:::++++++++=#@=+::::+=#@#******#=::+#.\n");

printf("=:#=*+::::::+**@:::::+*::+=#WW#*:.......**::+*#@#*::::::+=#*+++++++******@=#@:.\n");

printf("=+#*:::::::+***@:::::@=*=#@#*:::+=#W@*=@W@=+:::::::::=@=+++++++++++******W.....\n");

printf("=*=#*:::::+***#=:+:::@****++++*=#@#::#+:::::::::::*W#+++++++++++++******=@.....\n");

printf(":=#*::+#@#==#*:*+.+=:@=*++++++++++#+:#:::::::::+@W*+++++++++++++++******=#.....\n");

printf(".....:=#*::+:+*....#:+@+++++++++**@+:@::::::::#@*+++++++++++++++++******==.....\n");

printf("..........-+=-.....-=:=#+++++++***@+:@:::::::##+++++++++++++++++++*****=@+.....\n");

printf("....................=+:@=+++++****@+:@+:::::**.*@W@=*+++++++++++++*=#@*........\n");

printf("....................-@#+::*###****@+:@+:::::=......-+*#@WWWWWW@#=+-............\n");

printf("........................-*@=+::+=@W+:W+::::=...................................\n");

printf(".............................-*##*::+W+:::@-...................................\n");

printf("..................................-+#W=+:......................................\n");
}

//Menu Peliculas
void menuPeliculas(){
    int opcion;
    do{
        margen();
        gotoxy(34,8);
        printf("MENU PELICULAS\n");
        gotoxy(27,12);
        printf("1. Agregar Pelicula\n");
        gotoxy(27,14);
        printf("2. Mostrar Peliculas\n");
        gotoxy(27,16);
        printf("3. Editar Pelicula\n");
        gotoxy(27,18);
        printf("4. Eliminar Pelicula\n");
        gotoxy(27,20);
        printf("5. Buscar Pelicula\n");
        gotoxy(27,22);
        printf("0. Salir\n");
        gotoxy(27,24);
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: system("cls");
            agregarPelicula();
            system("pause");
            system("cls");
            break;
            case 2: system("cls");
            mostrarPeliculas();
            system("pause");
            system("cls");
            break;
            case 3: system("cls");
            editarPelicula();
            system("pause");
            system("cls");
            break;
            case 4: system("cls");
            eliminarPelicula();
            system("pause");
            system("cls");
            break;
            case 5: system("cls");
            buscarPelicula();
            system("pause");
            system("cls");
            break;
            case 0: system("cls");
            menu();
            default: printf("Opcion no valida\n");
        }
    }while(opcion!=0);
}

void agregarPelicula(){
    //Creamos Pelicula
    gotoxy(26,5);
    printf("Agregar Pelicula a mi Cinema\n\n");
	(ppeliculas+nPeliculas)->id = nPeliculas;
	printf("Nombre Pelicula: ");
	fflush(stdin);
	fgets((ppeliculas+nPeliculas)->nombre, 30, stdin);
	printf("\n");
	printf("Referencia (Codigo) Pelicula: ");
	scanf("%d",&(ppeliculas+nPeliculas)->referencia);
	printf("\n");
	printf("Valor Pelicula: ");
	scanf("%f",&(ppeliculas+nPeliculas)->valor);
	printf("\n");
	(ppeliculas+nPeliculas)->sillas = 50;
	printf("Hora de la Pelicula: ");
	fflush(stdin);
	fgets((ppeliculas+nPeliculas)->hora, 10, stdin);
	printf("\n");
	llenarMatriz();
	nPeliculas += 1;
}

void mostrarPeliculas(){
    //Mostrar Peliculas registradas
    gotoxy(32,5);
     printf("Mostrar Peliculas\n\n");
    for(int i=0; i<nPeliculas; i++){
	       printf("Pelicula No. %d\n\n", (ppeliculas+i)->id+1);
	       printf("Nombre de la Pelicula: %s\n", (ppeliculas+i)->nombre);
	       printf("Referencia de la Pelicula: %d\n\n", (ppeliculas+i)->referencia);
	       printf("Valor (Entrada) Pelicula: %.3f\n\n", (ppeliculas+i)->valor);
	       printf("Sillas Totales Pelicula: %d\n\n", (ppeliculas+i)->sillas);
	       printf("Hora de la Pelicula: %s\n", (ppeliculas+i)->hora);
	       printf("\n\n");
    }
}

int buscarPelicula(){
    //Buscar Pelicula
    int referencia, *pReferencia;
    gotoxy(32,5);
    printf("Buscar Pelicula\n\n");
    printf("Ingrese la referencia de la Pelicula: ");
    scanf("%d",&referencia);
    pReferencia=&referencia;
    for(int i=0; i<nPeliculas; i++){
        if(*pReferencia == (ppeliculas+i)->referencia){
            mostrarPelicula((peliculas+i)->id);
            return (ppeliculas+i)->id;
        }
    }
    printf("No se encuentra Registrada\n");
    return -1;
}

void mostrarPelicula(int idPelicula){
    //Mostrar pelicula Buscada
    printf("\n\n");
    printf("Pelicula No. %d\n\n", (ppeliculas+idPelicula)->id+1);
    printf("Nombre de la Pelicula: %s\n", (ppeliculas+idPelicula)->nombre);
    printf("Referencia de la Pelicula: %d\n\n", (ppeliculas+idPelicula)->referencia);
    printf("Valor (Entrada) Pelicula: %.3f\n\n", (ppeliculas+idPelicula)->valor);
    printf("Sillas Totales Pelicula: %d\n\n", (ppeliculas+idPelicula)->sillas);
    printf("Hora de la Pelicula: %s\n", (ppeliculas+idPelicula)->hora);
    printf("\n\n");
    system("pause");
    system("cls");
}

void editarPelicula(){
    //Editar Pelicula
    int idPelicula, *pidPelicula, opcion;
    gotoxy(32,3);
    printf("Editar Pelicula\n\n");
    idPelicula = buscarPelicula();
    pidPelicula=&idPelicula;
    if(*pidPelicula!=-1){
        do{
            margen();
            gotoxy(33,8);
            printf("Cambios Pelicula\n");
            gotoxy(27,12);
            printf("1. Cambiar Nombre\n");
            gotoxy(27,14);
            printf("2. Cambiar Valor\n");
            gotoxy(27,16);
            printf("3. Cambiar Sillas\n");
            gotoxy(27,18);
            printf("4. Cambiar Hora\n");
            gotoxy(27,20);
            printf("0. Salir\n");
            gotoxy(27,22);
            printf("Ingrese una opcion: ");
            scanf("%d",&opcion);
            switch(opcion){
            case 1: system("cls");
            peliculaCambioNombre(pidPelicula);
            system("cls");
            break;
            case 2: system("cls");
            peliculaCambioValor(pidPelicula);
            system("cls");
            break;
            case 3: system("cls");
            peliculaCambioSillas(pidPelicula);
            system("cls");
            break;
            case 4: system("cls");
            peliculaCambioHora(pidPelicula);
            system("cls");
            break;
            case 0: system("cls");
            menuPeliculas();
            default: printf("Opcion no valida\n");
                }
        }while(opcion!=0);
    }
}

void eliminarPelicula(){
    //Eliminar Pelicula
    int idPelicula, *pidPelicula = &idPelicula;
    idPelicula = buscarPelicula();
    if(*pidPelicula != -1){
        if(*pidPelicula < nPeliculas){
            for(int i=*pidPelicula; i<nPeliculas; i++){
                (ppeliculas+i+1)->id = i;
                strcpy((ppeliculas+i)->nombre,(ppeliculas+i+1)->nombre);
                (ppeliculas+i)->referencia = (ppeliculas+i+1)->referencia;
                (ppeliculas+i)->valor = (ppeliculas+i+1)->valor;
                (ppeliculas+i)->sillas = (ppeliculas+i+1)->sillas;
                strcpy((ppeliculas+i)->hora,(ppeliculas+i+1)->hora);
            }
        }
        nPeliculas--;
        printf("Se Elimino la Pelicula\n");
    }else{
        printf("No se puede Eliminar\n");
    }
}

void peliculaCambioNombre(int *pidPelicula){
    //Cambio Nombre Pelicula
     gotoxy(20,5);
     printf("Ingrese Nombre: ");
    fflush(stdin);
    fgets((ppeliculas+*pidPelicula)->nombre,30,stdin);
}

void peliculaCambioValor(int *pidPelicula){
    //Cambio valor Pelicula
    gotoxy(20,5);
     printf("Ingrese Valor: ");
    scanf("%f",&(ppeliculas+*pidPelicula)->valor);
}

void peliculaCambioSillas(int *pidPelicula){
    //Cambio Sillas Pelicula
    gotoxy(20,5);
     printf("Ingrese Sillas: ");
    scanf("%d",&(ppeliculas+*pidPelicula)->sillas);
}

void peliculaCambioHora(int *pidPelicula){
    //Cambio hora pelicula
    gotoxy(20,5);
     printf("Ingrese Hora: ");
    fflush(stdin);
    fgets((ppeliculas+*pidPelicula)->hora,10,stdin);
}

void menuEntradas(){
    //Menu entrada
    int opcion;
    do{
        margen();
        gotoxy(35,8);
        printf("MENU ENTRADA\n");
        gotoxy(27,12);
        printf("1. Comprar Tiquetes\n");
        gotoxy(27,14);
        printf("2. Mostrar Entradas Cliente\n");
        gotoxy(27,16);
        printf("3. Mostrar Entradas Pelicula\n");
        gotoxy(27,18);
        printf("0. Salir\n");
        gotoxy(27,24);
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: system("cls");
            comprarTiquete();
            system("cls");
            break;
            case 2: system("cls");
            mostrarEntradasCliente();
            system("pause");
            system("cls");
            break;
            case 3: system("cls");
            mostrarEntradasPelicula();
            system("pause");
            system("cls");
            break;
            case 0: system("cls");
            menu();
            default: printf("Opcion no valida\n");
        }
    }while(opcion!=0);
}

void comprarTiquete(){
    //Compra de tiquete
    int idClien, idPeli;
    gotoxy(25,5);
    printf("Compra tu tiquete (CINEMASMART)\n\n");
    printf("Identificacion Cliente: ");
    scanf("%d",&(pentrada+nEntrada)->cedulaCliente);
    printf("\n");
    for(int i=0; i<nClientes; i++){
            //Comprueba si la cedula ingresada ya esta registrada en la struct clientes
        if((pentrada+nEntrada)->cedulaCliente == (pclientes+i)->cedula){
            idClien = i;
            printf("Bienvenido a por tu Tiquete\n\n");
            system("pause");
            system("cls");
            mostrarPeliculas();
            system("pause");
            system("cls");
            printf("Ingrese (Nombre) Pelicula: "); fflush(stdin);
            fgets((pentrada+nEntrada)->nombrePelicula, 30, stdin);
            printf("\n");
            for(int j=0; j<nPeliculas; j++){
                //Comprueba si el nombre pelicula ingresado se encuentra en la cartelera de nuestras peliculas
            if(strcmp((pentrada+nEntrada)->nombrePelicula, (ppeliculas+j)->nombre)==0){
                idPeli = j;
                //Comprobacion cantidad asientos
                if((ppeliculas+idPeli)->sillas!=0){
                printf("Ingrese cantidad (Tiquetes): ");
                scanf("%d",&(pentrada+nEntrada)->cantidad);
                (ppeliculas+idPeli)->sillas = (ppeliculas+idPeli)->sillas - (pentrada+nEntrada)->cantidad;
                printf("\n");
                system("pause");
                system("cls");
                escogerSilla(idPeli, (pentrada+nEntrada)->cantidad);
                }else{
                    system("cls");
                    printf("No hay mas asientos disponibles para esta pelicula\n");
                    system("pause");
                    system("cls");
                    menuEntradas();
                }
                printf("Generando Factura...\n\n");
                system("pause");
                system("cls");
                mostrarTiquete(idClien, idPeli);
                nEntrada++;
            }
         }
      }
   }
}

void mostrarTiquete(int idClien, int idPeli){
    //Mostrar tiquete en pantalla
    margenTiquete();
    gotoxy(41,9);
    printf("TIQUETE DE ENTRADA\n");
    gotoxy(35,12);
    printf("Cliente: %s\n", (pclientes+idClien)->nombre);
    gotoxy(35,16);
    printf("Pelicula: %s\n", (ppeliculas+idPeli)->nombre);
    gotoxy(14,10);
    printf("CINEMASMART\n");
    gotoxy(35,20);
    printf("Hora: %s\n", (ppeliculas+idPeli)->hora);
    gotoxy(35,18);
    printf("Valor (N.T = %d): %.3f\n", (pentrada+nEntrada)->cantidad, (pentrada+nEntrada)->cantidad * (ppeliculas+idPeli)->valor);
    gotoxy(35,14);
    printf("Identificacion: %d\n", (pclientes+idClien)->cedula);
    gotoxy(13,18);
    printf("Cartago Valle\n");
    gotoxy(18,19);
    printf("2018");
    gotoxy(50,20);
    printf("¡Compra Exitosa!\n");
    gotoxy(20,24);
    system("pause");
}

void margenTiquete(){
    int i;
    for(i=10; i<=68; i++){
            gotoxy(i,8); printf("%c", 205);
            gotoxy(i,22); printf("%c", 205);
    }
    gotoxy(9,8); printf("%c", 201);
    gotoxy(9,22); printf("%c", 200);
    gotoxy(69,8); printf("%c", 187);
    gotoxy(69,22); printf("%c", 188);
    for(i=9; i<=21; i++){
        gotoxy(9,i); printf("%c", 186);
        gotoxy(69,i); printf("%c", 186);
    }
    for(i=9; i<=21; i++){
        gotoxy(30,i); printf("*");
    }
    for(i=11; i<=28; i++){
        gotoxy(i,14); printf("*");
    }
    for(i=32; i<=67; i++){
        gotoxy(i,10); printf("*");
    }
}

void escogerSilla(int idPeli, int cantidad){
    //Por medio de una matriz llena de 0 escogemos los asientos de la pelicula
    int fila, columna;
    while(cantidad!=0){
        printf("Filas 0 - 9 (10 filas), Columnas 0 - 4 (5 Columnas)\n");
        printf("Ingrese la fila y la columna donde desea sentarse: \n");
        do{
         printf("Fila: ");
         scanf("%d",&fila);
        }while(fila<0||fila>9);
        do{
        printf("Columna: ");
        scanf("%d",&columna);
        }while(columna<0||columna>4);
        system("cls");
        if((ppeliculas+idPeli)->escogeSilla[fila][columna]==0){
        (ppeliculas+idPeli)->escogeSilla[fila][columna]=1;
        cantidad--;
        }else{
            printf("El asiento se encuentra ocupado\n");
        }
        mostrarAsientos(idPeli);
    }
}

void llenarMatriz(){
    //Llenando matriz de 0
    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            (ppeliculas+nPeliculas)->escogeSilla[i][j]=0;
    }
  }
}

void mostrarAsientos(int idPeli){
    //Mostrando asientos de la pelicula
    numeracionAsientos();
    gotoxy(8,6);
    printf("Mostrando asientos: \n\n\n\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            if((ppeliculas+idPeli)->escogeSilla[i][j]==0){
                printf("\t%d", (ppeliculas+idPeli)->escogeSilla[i][j]);
            }else{
                printf("\tX");
            }
      }
      printf("\n");
   }
   printf("\n");
   system("pause");
   system("cls");
}

void numeracionAsientos(){
    //Numeracion de los asientos por gotoxy
    gotoxy(3,10); printf("F0");
    gotoxy(3,11); printf("F1");
    gotoxy(3,12); printf("F2");
    gotoxy(3,13); printf("F3");
    gotoxy(3,14); printf("F4");
    gotoxy(3,15); printf("F5");
    gotoxy(3,16); printf("F6");
    gotoxy(3,17); printf("F7");
    gotoxy(3,18); printf("F8");
    gotoxy(3,19); printf("F9");
    gotoxy(8,8); printf("0");
    gotoxy(16,8); printf("1");
    gotoxy(24,8); printf("2");
    gotoxy(32,8); printf("3");
    gotoxy(40,8); printf("4");
}

void mostrarEntradasCliente(){
    //Mostrar entradas a peliculas que posee un cliente
    int cedula;
    printf("Ingrese su cedula: ");
    scanf("%d",&cedula);
    for(int j=0; j<nClientes; j++){
            //Comprobar si la cedula ya se encuentra registrada en la struct clientes e imprimimos
            if(cedula==(pclientes+j)->cedula){
                mostrarCliente(j);
            }
    }

    gotoxy(16,5);
    //Recorremos toda la estructura entrada
    for(int i=0; i<nEntrada; i++){
            //Comprobamos si la cedula ingresada posee compras de peliculas
        if(cedula==(pentrada+i)->cedulaCliente){
            //Si la cedula posee compras imprimimos las peliculas compradas bajo este numero de cedula
            printf("Posee compras (entradas) a la siguiente pelicula: \n\n");
            printf("Nombre Pelicula: %s\n", (pentrada+i)->nombrePelicula);
        }
    }
}

void mostrarEntradasPelicula(){
    char nombre[30];
    //Mostramos peliculas que se encuentra en catalogo
    mostrarPeliculas();
    system("pause");
    system("cls");

    gotoxy(20,5);
    printf("Ingrese el nombre de la pelicula: ");
    fflush(stdin); fgets(nombre,30,stdin);
    printf("\n");
    //Recorremos struct entradas
    for(int i=0; i<nEntrada; i++){
            //Comparar si la pelicula posee entradas
            if(strcmp(nombre,(pentrada+i)->nombrePelicula)==0){
                    //Recorre struct clientes
                for(int j=0; j<nClientes; j++){
                    //Compara si la cedula registrada en la compra pertenece a un cliente para obtener id del cliente para posteriormente imrpimir su nombre
                    if((pentrada+i)->cedulaCliente==(pclientes+j)->cedula){
                        printf("El siguiente Cliente de CINESMART cuenta con entradas a esta pelicula: \n\n");
                        printf("Nombre del Cliente: %s\n", (pclientes+j)->nombre);
                    }
                }
            }
    }
}
