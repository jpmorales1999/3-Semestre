#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void ejercicio1();
void ejercicio2();
int longitudCadena(char cadena[]);
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();

char cadena[30];
char cadenaInversa[30];

int main()
{
    menu();

    return 0;
}

void menu(){
    int opcion;
    do{
        printf("MENU DE OPCIONES\n");
        printf("1. Ejercicio 1\n");
        printf("2. Ejercicio 2\n");
        printf("Ejercicios WHILE\n");
        printf("3. Ejercicio 3\n");
        printf("4. Ejercicio 4\n");
        printf("5. Ejercicio 5\n");
        printf("Ejercicios FOR\n");
        printf("6. Ejercicio 6\n");
        printf("7. Ejercicio 7\n");
        printf("8. Ejercicio 8\n");
        printf("Ejercicio SWITCH\n");
        printf("9. Ejercicio 9\n");
        printf("10. Ejercicio 10\n");
        printf("11. Ejercicio 11\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
                case 1:
                system("cls");
                ejercicio1();
                system("pause");
                system("cls");
                break;
                case 2:
                system("cls");
                ejercicio2();
                system("pause");
                system("cls");
                break;
                case 3:
                system("cls");
                ejercicio3();
                system("pause");
                system("cls");
                break;
                case 4:
                system("cls");
                ejercicio4();
                system("pause");
                system("cls");
                break;
                case 5:
                system("cls");
                ejercicio5();
                system("pause");
                system("cls");
                break;
                case 6:
                system("cls");
                ejercicio6();
                system("pause");
                system("cls");
                break;
                case 7:
                system("cls");
                ejercicio7();
                system("pause");
                system("cls");
                break;
                case 8:
                system("cls");
                ejercicio8();
                system("pause");
                system("cls");
                break;
                case 9:
                system("cls");
                ejercicio9();
                system("pause");
                system("cls");
                break;
                case 10:
                system("cls");
                ejercicio10();
                system("pause");
                system("cls");
                break;
                case 11:
                system("cls");
                ejercicio11();
                system("pause");
                system("cls");
                break;
            case 0: exit(0);
            default: printf("No valido\n");
        }
    }while(opcion!=0);
}

void ejercicio1(){
    char tecla;
    do{
    fflush(stdin);
    printf("Ingrese una tecla cualquiera: ");
    scanf("%c",&tecla);
    }while(tecla < 48 || tecla > 57);
}

void ejercicio2(){
    int longi;
    printf("Digite una cadena de texto: ");
    fflush(stdin);
    fgets(cadena, 30, stdin);
    longi = longitudCadena(cadena);
    for(int i=longi; i>=0; i--){
        cadenaInversa[longi-i] = cadena[i];
    }
    printf("%s\n", cadenaInversa);
}

void ejercicio3(){
    int numero=1, suma=0;
    while(numero<=100){
        suma += numero;
        numero++;
    }
    printf("La suma total de los numeros del 1 al 100 es: %d \n", suma);
}

void ejercicio4(){
    int suma = 0;
    for(int i=0; i<=50; i++){
    if(i % 2 == 0){
        suma += i;
      }
    }
    printf("La suma total de los numeros pares del 1 al 50 es: %d\n", suma);
}

void ejercicio5(){
    int suma = 0;
    for(int i=0; i<=50; i++){
        if(i%2==1){
            suma+=i;
        }
    }
    printf("La suma total de los numeros impares del 1 al 50 es: %d\n", suma);
}

void ejercicio6(){
    int resultado, numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    for(int i=1; i<=12; i++){
        resultado = numero * i;
        printf("%d * %d = %d\n", numero, i, resultado);
    }
}

void ejercicio7(){
    int numero, resultado=1;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    for(int i=numero; i>=1; i--){
        resultado *= i;
    }
    printf("El factorial del numero %d es: %d\n", numero, resultado);
}

void ejercicio8(){
    int x,y,z,numero;
    printf("Ingrese un numero para solucionar fibonacci: ");
    scanf("%d",&numero);
    x=0;
    y=1;
    for(int i=1; i<=numero; i++){
        z=x+y;
        printf("%d ", z);
        x=y;
        y=z;
    }
}

void ejercicio9(){
    time_t now;
    time(&now);
    /*
    printf("%s\n", ctime(&now));
    */

    struct tm *mesActual = localtime(&now);
    printf("Mes del sistema: %d\n", mesActual->tm_mon+1);

    switch(mesActual->tm_mon+1){
        case 1: printf("Mes en espanol segun el sistema: Enero\n"); break;
        case 2: printf("Mes en espanol segun el sistema: Febrero\n"); break;
        case 3: printf("Mes en espanol segun el sistema: Marzo\n"); break;
        case 4: printf("Mes en espanol segun el sistema: Abril\n"); break;
        case 5: printf("Mes en espanol segun el sistema: Mayo\n"); break;
        case 6: printf("Mes en espanol segun el sistema: Junio\n"); break;
        case 7: printf("Mes en espanol segun el sistema: Julio\n"); break;
        case 8: printf("Mes en espanol segun el sistema: Agosto\n"); break;
        case 9: printf("Mes en espanol segun el sistema: Septiembre\n"); break;
        case 10: printf("Mes en espanol segun el sistema: Octubre\n"); break;
        case 11: printf("Mes en espanol segun el sistema: Noviembre\n"); break;
        case 12: printf("Mes en espanol segun el sistema: Diciembre\n"); break;
    }
}

void ejercicio10(){
    char letra;
    printf("Ingrese una letra para determinar ASCII: ");
    fflush(stdin);
    scanf("%c",&letra);
    switch(letra){
        case 'a': printf("%d\n", letra); break;
        case 'b': printf("%d\n", letra); break;
        case 'c': printf("%d\n", letra); break;
        case 'd': printf("%d\n", letra); break;
        case 'e': printf("%d\n", letra); break;
        case 'f': printf("%d\n", letra); break;
        case 'g': printf("%d\n", letra); break;
        case 'h': printf("%d\n", letra); break;
        case 'i': printf("%d\n", letra); break;
        case 'j': printf("%d\n", letra); break;
        case 'k': printf("%d\n", letra); break;
        case 'l': printf("%d\n", letra); break;
        case 'm': printf("%d\n", letra); break;
        case 'n': printf("%d\n", letra); break;
        case 'o': printf("%d\n", letra); break;
        case 'p': printf("%d\n", letra); break;
        case 'q': printf("%d\n", letra); break;
        case 'r': printf("%d\n", letra); break;
        case 's': printf("%d\n", letra); break;
        case 't': printf("%d\n", letra); break;
        case 'u': printf("%d\n", letra); break;
        case 'v': printf("%d\n", letra); break;
        case 'w': printf("%d\n", letra); break;
        case 'x': printf("%d\n", letra); break;
        case 'y': printf("%d\n", letra); break;
        case 'z': printf("%d\n", letra); break;
        case 'A': printf("%d\n", letra); break;
        case 'B': printf("%d\n", letra); break;
        case 'C': printf("%d\n", letra); break;
        case 'D': printf("%d\n", letra); break;
        case 'E': printf("%d\n", letra); break;
        case 'F': printf("%d\n", letra); break;
        case 'G': printf("%d\n", letra); break;
        case 'H': printf("%d\n", letra); break;
        case 'I': printf("%d\n", letra); break;
        case 'J': printf("%d\n", letra); break;
        case 'K': printf("%d\n", letra); break;
        case 'L': printf("%d\n", letra); break;
        case 'M': printf("%d\n", letra); break;
        case 'N': printf("%d\n", letra); break;
        case 'O': printf("%d\n", letra); break;
        case 'P': printf("%d\n", letra); break;
        case 'Q': printf("%d\n", letra); break;
        case 'R': printf("%d\n", letra); break;
        case 'S': printf("%d\n", letra); break;
        case 'T': printf("%d\n", letra); break;
        case 'U': printf("%d\n", letra); break;
        case 'V': printf("%d\n", letra); break;
        case 'W': printf("%d\n", letra); break;
        case 'X': printf("%d\n", letra); break;
        case 'Y': printf("%d\n", letra); break;
        case 'Z': printf("%d\n", letra); break;
        default: printf("Dato ingresado no es valido\n");
    }
}

void ejercicio11(){
    int numero;
    printf("Ingrese un numero del 0 al 9 para determinar su ASCII: ");
    scanf("%d",&numero);
    switch(numero){
        case 0: printf("%d\n", numero+48); break;
        case 1: printf("%d\n", numero+48); break;
        case 2: printf("%d\n", numero+48); break;
        case 3: printf("%d\n", numero+48); break;
        case 4: printf("%d\n", numero+48); break;
        case 5: printf("%d\n", numero+48); break;
        case 6: printf("%d\n", numero+48); break;
        case 7: printf("%d\n", numero+48); break;
        case 8: printf("%d\n", numero+48); break;
        case 9: printf("%d\n", numero+48); break;
    }
}

int longitudCadena(char cadena[]){
    int contador=0;
    for(int i=0; i<100; i++){
        if(cadena[i]=='\n'){
            break;
        }
        contador++;
    }
    return contador;
}
