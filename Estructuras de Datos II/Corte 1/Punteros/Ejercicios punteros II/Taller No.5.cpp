/*Taller No. 5 Estructura de Datos II = JUAN PABLO MORALES TAMES - YORDAN DENILSON QUINTERO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
int primo(int);
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();
void ejercicio14();
void ejercicio15();
void ejercicio16();
void ejercicio17();
void ejercicio18();
void ejercicio19();
void ejercicio20();
void ejercicio21();
void ejercicio22();
void ejercicio23();
void ejercicio24();

int main()
{
    menu();
    return 0;
}

void menu(){
    int opcion;
    do{
        printf("MENU DE OPCIONES\n\n");
        printf("Ejercicios Arreglos con Punteros\n\n");
        printf("1. Ejercicio 1\n");
        printf("2. Ejercicio 2\n");
        printf("3. Ejercicio 3\n\n");
        printf("Ejercicios Matrices con Punteros\n\n");
        printf("4. Ejercicio 1\n");
        printf("5. Ejercicio 2\n");
        printf("6. Ejercicio 3\n\n");
        printf("Ejercicios de Punteros\n\n");
        printf("7. Ejercicio 1\n");
        printf("8. Ejercicio 2\n");
        printf("9. Ejercicio 3\n");
        printf("10. Ejercicio 4\n");
        printf("11. Ejercicio 5\n");
        printf("12. Ejercicio 6\n");
        printf("13. Ejercicio 7\n");
        printf("14. Ejercicio 8\n");
        printf("15. Ejercicio 9\n");
        printf("16. Ejercicio 10\n");
        printf("17. Ejercicio 11\n");
        printf("18. Ejercicio 12\n\n");
        printf("Ejercicios de Estructuras con Punteros\n\n");
        printf("19. Ejercicio 1\n");
        printf("20. Ejercicio 2\n");
        printf("21. Ejercicio 3\n");
        printf("22. Ejercicio 4\n");
        printf("23. Ejercicio 5\n");
        printf("24. Ejercicio 6\n\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: system("cls");
                ejercicio1();
                system("pause");
                system("cls");
            break;
            case 2: system("cls");
                ejercicio2();
                system("pause");
                system("cls");
            break;
            case 3: system("cls");
                ejercicio3();
                system("pause");
                system("cls");
                break;
            case 4: system("cls");
                ejercicio4();
                system("pause");
                system("cls");
                break;
            case 5: system("cls");
                ejercicio5();
                system("pause");
                system("cls");
                break;
            case 6: system("cls");
                ejercicio6();
                system("pause");
                system("cls");
                break;
            case 7: system("cls");
                ejercicio7();
                system("pause");
                system("cls");
                break;
            case 8: system("cls");
                ejercicio8();
                system("pause");
                system("cls");
                break;
            case 9: system("cls");
                ejercicio9();
                system("pause");
                system("cls");
                break;
            case 10: system("cls");
                ejercicio10();
                system("pause");
                system("cls");
                break;
            case 11: system("cls");
                ejercicio11();
                system("pause");
                system("cls");
                break;
            case 12: system("cls");
                ejercicio12();
                system("pause");
                system("cls");
                break;
            case 13: system("cls");
                ejercicio13();
                system("pause");
                system("cls");
                break;
            case 14: system("cls");
                ejercicio14();
                system("pause");
                system("cls");
                break;
             case 15: system("cls");
                ejercicio15();
                system("pause");
                system("cls");
                break;
            case 16: system("cls");
                ejercicio16();
                system("pause");
                system("cls");
                break;
            case 17: system("cls");
                ejercicio17();
                system("pause");
                system("cls");
                break;
            case 18: system("cls");
                ejercicio18();
                system("pause");
                system("cls");
                break;
            case 19: system("cls");
                ejercicio19();
                system("pause");
                system("cls");
                break;
            case 20: system("cls");
                ejercicio20();
                system("pause");
                system("cls");
                break;
            case 21: system("cls");
                ejercicio21();
                system("pause");
                system("cls");
                break;
            case 22: system("cls");
                ejercicio22();
                system("pause");
                system("cls");
                break;
            case 23: system("cls");
                ejercicio23();
                system("pause");
                system("cls");
                break;
            case 24: system("cls");
                ejercicio24();
                system("pause");
                system("cls");
                break;
            case 0: exit(0);
            default: printf("Opcion no valida\n");
        }
    }while(opcion!=0);
}

void ejercicio1(){
	int i;
    float vect [] = {32.583, 11.239, 45.781, 22.237};
    float *pvector = vect;

    printf("Mostrando numeros: \n");
    for(i=0; i<4; i++){
        printf("%.3f\n", *(pvector + i));
    }
}

void ejercicio2(){
    int i, j;
    int matriz[100][100], *pmatriz = &matriz[0][0];
    int num1, num2;

    printf("Ingrese dos numeros: \n");
    scanf("%d %d",&num1,&num2);

    for(i=0; i<num1; i++){
        for(j=0; j<num2; j++){
                if(j%2==0){
                    *(pmatriz + i + j * num2) = 0;
                }else{
                    *(pmatriz + i+ j * num2) = 1;
                }
        }
    }

    for(i=0; i<num1; i++){
        for(j=0; j<num2; j++){
            printf("%d\t", *(pmatriz + i + j * num2));
        }
        printf("\n");
    }

}

void ejercicio3(){
    int i;
    int vec1[4], vec2[4], vec3[4], vec4[4];
    int *pvec1 = vec1, *pvec2 = vec2, *pvec3 = vec3, *pvec4 = vec4;

    for(i=0; i<4; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&*(pvec1+i));
    }

    for(i=0; i<4; i++){
        *(pvec2+i) = *(pvec1+i) * *(pvec1+i);
    }

    for(i=0; i<4; i++){
        *(pvec3+i) = *(pvec2+i) * *(pvec1+i);
    }

    for(i=0; i<4; i++){
        *(pvec4+i) = *(pvec3+i) * *(pvec1+i);
    }

    //Mostramos arreglo
    for(i=0; i<4; i++){
        printf("\t%d", *(pvec1+i));
        printf("\t%d", *(pvec2+i));
        printf("\t%d", *(pvec3+i));
        printf("\t%d", *(pvec4+i));
        printf("\n");
    }
}

void ejercicio4(){
    int suma=0, i, j;
    int matriz[3][3], *pmatriz = &matriz[0][0];

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Ingrese un numero: ");
            scanf("%d",&*(pmatriz+i+j*3));
            suma += *(pmatriz+i+j*3);
        }
    }

    //Mostramos matriz
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("\t%d", *(pmatriz+i+j*3));
        }
        printf("\n");
    }

    printf("La suma total de los elementos de la matriz es: %d\n", suma);
}

void ejercicio5(){
    int i, j;
    int matriz[3][3], *pmatriz = &matriz[0][0];

    //Llenando matriz por numeros aleatorios
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            *(pmatriz+i+j*3) = rand () % 100;
        }
    }

    //Mostrando matriz
    printf("Mostrando matriz en pantalla: \n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("\t%d", *(pmatriz+i+j*3));
        }
        printf("\n");
    }
}

void ejercicio6(){
    int i, j, numero, comprobacion;
    int matriz[3][3], *pmatriz = &matriz[0][0];

    //Llenamos matriz con numeros primos aleatorios
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            numero = 2 + rand()%((100+1) - 2);
            comprobacion = primo(numero);
            if(comprobacion == numero){
                *(pmatriz+i+j*3) = comprobacion;
            }else{
                j--;
            }
        }
    }

    //Mostramos matriz
    printf("Mostrando matriz:\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("\t%d", *(pmatriz+i+j*3));
        }
        printf("\n");
    }
}

int primo(int n){
    int contador=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            contador++;
        }
    }
    if(contador==2){
        contador=0;
        return n;
    }else{
        return 1;
    }
}

void ejercicio7(){
    int numero, *pnumero;
    printf("Ingrese un numero para determinar si es par o impar: ");
    scanf("%d",&numero);

    pnumero=&numero;

    if(*pnumero%2==0){
        printf("El numero es par\n");
        printf("Su posicion en memoria es: %p\n", pnumero);
    }else{
        printf("El numero es impar\n");
        printf("Su posicion en memoria es: %p\n", pnumero);
    }
}

void ejercicio8(){
    int numero, *pnumero, contador=0, i;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    pnumero=&numero;

    for(i=1; i<=*pnumero; i++){
        if(*pnumero%i==0){
            contador++;
        }
    }

    if(contador==2){
        printf("El numero es primo\n");
        printf("Su posicion en memoria es: %p\n", pnumero);
    }else{
        printf("El numero no es primo\n");
        printf("Su posicion en memoria es: %p\n", pnumero);
    }
}

void ejercicio9(){
    int vect[10], *pvect, i;
    for(i=0; i<10; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&vect[i]);
    }
    pvect = vect;

    printf("Mostrando informacion: \n");
    for(i=0; i<10; i++){
        if(*(pvect+i)%2==0){
            printf("El %d es par\n", *(pvect+i));
            printf("La posicion en memoria es: %p\n", (pvect+i));
        }else{
            printf("El %d es impar\n", *(pvect+i));
            printf("La posicion en memoria es: %p\n", (pvect+i));
        }
    }
}

void ejercicio10(){
    int arreglo[100], *parreglo, tamano, menor=999999, i;
    printf("Ingrese la cantidad de elementos a registrar: ");
    scanf("%d",&tamano);

    //Llenamos vector
    for(i=0; i<tamano; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&arreglo[i]);
    }

    parreglo = arreglo;

    //Comprobamos elemento menor del vector
    for(i=0; i<tamano; i++){
        if(*(parreglo+i)<menor){
            menor = *(parreglo+i);
        }
    }

    printf("El elemento menor del vector es: %d\n", menor);

}

void ejercicio11(){
    int elementos, *elem, i, j, aux;
    printf("Digite el numero de elementos: ");
    scanf("%d",&elementos);

    elem = new int[elementos]; //Crear el arreglo dinamico

    for(i=0; i<elementos; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&*(elem+i));
    }

    for(i=0; i<elementos; i++){
        for(j=0; j<elementos-i; j++){
            if(*(elem+j)>*(elem+j+1)){
                aux = *(elem+j);
                *(elem+j) = *(elem+j+1);
                *(elem+j+1) = aux;
            }
        }
    }

    //Imprimiendo vector
    for(i=0;i<elementos;i++){
        printf("%d\n",*(elem+i));
    }

    delete(elem);

}

void ejercicio12(){
    int elementos, *elem, i, busqueda, cont=0;
    printf("Ingrese la cantidad de elementos: \n");
    scanf("%d",&elementos);

    elem = new int[elementos];

    //Llenando vector con numeros aleatorios
    for(i=0; i<elementos; i++){
        *(elem+i) = rand ()%100;
        printf("%d\n", *(elem+i));
    }

    printf("Ingrese el numero a buscar: \n");
    scanf("%d",&busqueda);

    for(i=0; i<elementos; i++){
            printf("%d\n", *(elem+i));
            if(busqueda==*(elem+i)){
                    cont=1;
            }
    }

    if(cont==1){
        printf("Se encontro el numero en el arreglo\n");
    }else{
        printf("No se encontro el numero en el arreglo\n");
    }

    delete(elem);
}

void ejercicio13(){
    char cadena[30], *Pcadena;
    int longitud;
    int conta=0 , conte=0, conti=0, conto=0, contu=0, suma=0;

    printf("Ingrese su nombre por favor: \n");
    fflush(stdin);
    fgets(cadena, 30, stdin);

    longitud = strlen(cadena)-1;

    Pcadena = cadena; // Pcadena = cadena[0];

    for(int i=0; i<longitud; i++){
        switch(*(Pcadena+i)){
            case 'a': conta++; break;
            case 'e': conte++; break;
            case 'i': conti++; break;
            case 'o': conto++; break;
            case 'u': contu++; break;
        }
    }
    suma = (conta + conte + conti + conto + contu);
    printf("La suma total de las vocales en su nombre es de: %d\n", suma);
}

void ejercicio14(){
    char cadena[30], *Pcadena;
    int longitud;
    int conta=0 , conte=0, conti=0, conto=0, contu=0;

    printf("Ingrese una cadena de caracteres por favor: \n");
    fflush(stdin);
    fgets(cadena, 30, stdin);

    longitud = strlen(cadena)-1;

    Pcadena = cadena; // Pcadena = cadena[0];

    for(int i=0; i<longitud; i++){
        switch(*(Pcadena+i)){
            case 'a': conta++; break;
            case 'e': conte++; break;
            case 'i': conti++; break;
            case 'o': conto++; break;
            case 'u': contu++; break;
        }
    }
    printf("Vocales a: %d\n", conta);
    printf("Vocales e: %d\n", conte);
    printf("Vocales i: %d\n", conti);
    printf("Vocales o: %d\n", conto);
    printf("Vocales u: %d\n", contu);
}

void ejercicio15(){
    int matriz1[3][3], *pmatriz1, matriz2[3][3], *pmatriz2, i, j;
    int matrizSuma[3][3], suma=0;

    printf("Llenando matrices\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matriz1[i][j] = rand()%100;
            matriz2[i][j] = rand()%100;
        }
    }

    pmatriz1 = &matriz1[0][0];
    pmatriz2 = &matriz2[0][0];

    printf("Sumando matrices\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matrizSuma[i][j] = *(pmatriz1+i+j*3) + *(pmatriz2+i+j*3);
            suma += matrizSuma[i][j];
        }
    }
    printf("El valor total de la suma de las dos matrices es: %d\n", suma);
}

void ejercicio16(){
    int i, j, matriz[3][3], *pmatriz;

    //Llenando matriz
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
                matriz[i][j] = rand()%100;
        }
    }

    pmatriz = &matriz[0][0];

    printf("Mostrando matriz\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
                printf("\t%d ", *(pmatriz+i+j*3));
        }
        printf("\n");
    }

    printf("Mostrando matriz traspuesta\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
                printf("\t%d ", *(pmatriz+j+i*3));
        }
        printf("\n");
    }
}

void ejercicio17(){
    int i, base;
    float mayor = -999999;
    struct alumno{
        char nombre[30];
        int edad;
        float promedio;
    }alumnos[3], *palumnos = alumnos;

    for(i=0; i<3; i++){
        printf("Ingrese nombre del alumno: "); fflush(stdin); fgets((palumnos+i)->nombre, 30, stdin);
        printf("Ingrese edad del alumno: "); scanf("%d",&(palumnos+i)->edad);
        printf("Ingrese promedio del alumno: "); scanf("%f",&(palumnos+i)->promedio);
        if((palumnos+i)->promedio>mayor){
            mayor = (palumnos+i)->promedio;
            base = i;
        }
        printf("\n");
    }

    printf("Imprimiendo datos del alumno con mejor promedio: \n");
    printf("Nombre del alumno: "); printf("%s\n", (palumnos+base)->nombre);
    printf("Edad del alumno: "); printf("%d\n", (palumnos+base)->edad);
    printf("Promedio del alumno: "); printf("%.1f\n", (palumnos+base)->promedio);
}

void ejercicio18(){
    int i, horasTotales=0, minutosTotales=0, segundosTotales=0;

    struct tiempo{
        int horas;
        int minutos;
        int segundos;
    }etapas[3], *petapas = etapas;

    //Pidiendo datos etapa al usuario
    for(i=0; i<3; i++){
        printf("\n");
        printf("Ingrese cantidad de horas en la etapa No.%d: ", i+1); scanf("%d",&(petapas+i)->horas);
        printf("Ingrese cantidad de minutos en la etapa No.%d: ", i+1); scanf("%d",&(petapas+i)->minutos);
        printf("Ingrese cantidad de segundos en la etapa No.%d: ", i+1); scanf("%d",&(petapas+i)->segundos);
        printf("\n");

        horasTotales+=(petapas+i)->horas;
        minutosTotales+=(petapas+i)->minutos;
        if(minutosTotales >= 60){
            minutosTotales = minutosTotales - 60;
            horasTotales++;;
        }
        segundosTotales+=(petapas+i)->segundos;
        if(segundosTotales >= 60){
            segundosTotales = segundosTotales - 60;
            minutosTotales++;
        }
    }

    printf("Tiempo total de las 3 etapas: \n");
    printf("Horas: %d ", horasTotales);
    printf("Minutos: %d ", minutosTotales);
    printf("Segundos: %d\n", segundosTotales);
}

void ejercicio19(){
    struct competidor{
        char nombre[30];
        int edad;
        char sexo[15];
        char club[30];
    }competidor1, *pcompetidor1 = &competidor1;

    printf("Ingrese nombre del competidor: "); fflush(stdin); fgets(pcompetidor1->nombre, 30, stdin);
    printf("Ingrese edad del competidor: "); scanf("%d",&pcompetidor1->edad);
    printf("Ingrese genero del competidor: "); fflush(stdin); fgets(pcompetidor1->sexo, 15, stdin);
    printf("Ingrese club del competidor: "); fflush(stdin); fgets(pcompetidor1->club, 30, stdin);

    //Imprimiendo en pantalla datos y categoria
    printf("\n Mostrando datos del competidor: \n");
    printf("Nombre del competidor: %s\n", pcompetidor1->nombre);
    printf("Edad del competidor: %d\n", pcompetidor1->edad);
    printf("Genero del competidor: %s\n", pcompetidor1->sexo);
    printf("Club del competidor: %s\n", pcompetidor1->club);
    if(pcompetidor1->edad <= 15){
        printf("Su categoria es: Infantil\n");
    }else if(pcompetidor1->edad <= 30){
        printf("Su categoria es: Joven\n");
    }else{
        printf("Su categoria es: Mayor\n");
    }
}

void ejercicio20(){
    int i, base;
    float mayor=-999999;
    struct estudiante{
        char nombre[30];
        int edad;
        int grado;
        float promedio;
    }alumnos[3], *palumnos = alumnos;

    //Llenando datos de los alumnos
    for(i=0; i<3; i++){
    printf("Ingrese nombre del Alumno: "); fflush(stdin); fgets((palumnos+i)->nombre,30,stdin);
    printf("Ingrese edad del Alumno: "); scanf("%d",&(palumnos+i)->edad);
    printf("Ingrese grado del Alumno: "); scanf("%d",&(palumnos+i)->grado);
    printf("Ingrese promedio del Alumno: "); scanf("%f",&(palumnos+i)->promedio);
    if((palumnos+i)->promedio > mayor){
        mayor = (palumnos+i)->promedio;
        base = i;
    }
    printf("\n");
    }

    //Mostrando datos del alumno con mejor promedio
    printf("Mostrando datos alumno con mejor promedio: \n");
    printf("Nombre del Alumno: %s\n", (palumnos+base)->nombre);
    printf("Edad del Alumno: %d\n", (palumnos+base)->edad);
    printf("Grado del Alumno: %d\n", (palumnos+base)->grado);
    printf("Promedio del Alumno: %.1f\n", (palumnos+base)->promedio);
}

void ejercicio21(){
    int tamano,i, base1, base2;
    float menor=999999, mayor=-999999;
    struct trabajadores{
        char nombre[30];
        int edad;
        int cedula;
        char direccion[30];
        float salario;
    }empleados[100], *pempleados = empleados;

    printf("Ingrese la cantidad de trabajdores a evaluar: "); scanf("%d",&tamano);

    for(i=0; i<tamano; i++){
    printf("Ingrese nombre del Empleado: "); fflush(stdin); fgets((pempleados+i)->nombre,30,stdin);
    printf("Ingrese edad del Empleado: "); scanf("%d",&(pempleados+i)->edad);
    printf("Ingrese cedula del Empleado: "); scanf("%d",&(pempleados+i)->cedula);
    printf("Ingrese direccion del Empleado: "); fflush(stdin); fgets((pempleados+i)->direccion,30,stdin);
    printf("Ingrese salario del Empleado: "); scanf("%f",&(pempleados+i)->salario);
    printf("\n");
    if((pempleados+i)->salario>mayor){
        mayor = (pempleados+i)->salario;
        base1 = i;
    }
    if((pempleados+i)->salario < menor){
        menor = (pempleados+i)->salario;
        base2 = i;
    }
    }
    printf("Datos del empleado con mayor salario\n");
    printf("Nombre del Empleado: %s\n", (pempleados+base1)->nombre);
    printf("Edad del Empleado: %d\n", (pempleados+base1)->edad);
    printf("Cedula del Empleado: %d\n", (pempleados+base1)->cedula);
    printf("Direccion del Empleado: %s\n", (pempleados+base1)->direccion);
    printf("Salario del Empleado: %f\n", (pempleados+base1)->salario);
    printf("\n");
    printf("Datos del empleado con menor salario\n");
    printf("Nombre del Empleado: %s\n", (pempleados+base2)->nombre);
    printf("Edad del Empleado: %d\n", (pempleados+base2)->edad);
    printf("Cedula del Empleado: %d\n", (pempleados+base2)->cedula);
    printf("Direccion del Empleado: %s\n", (pempleados+base2)->direccion);
    printf("Salario del Empleado: %f\n", (pempleados+base2)->salario);
}

void ejercicio22(){
    float promedio;

struct promedio{
    float nota1, nota2, nota3;
};

struct alumnos{
    char nombre[30];
    char sexo [15];
    int edad;
    struct promedio porcen;
}alumno, *palumno = &alumno;
    //Ingresamos datos alumno
    printf("Ingrese nombre alumno: "); fflush(stdin); fgets(palumno->nombre, 30, stdin);
    printf("Ingrese genero alumno: "); fflush(stdin); fgets(palumno->sexo, 15, stdin);
    printf("Ingrese edad alumno: "); scanf("%d",&palumno->edad);
    printf("Ingrese nota No. 1 del alumno: "); scanf("%f",&palumno->porcen.nota1);
    printf("Ingrese nota No. 2 del alumno: "); scanf("%f",&palumno->porcen.nota2);
    printf("Ingrese nota No. 3 del alumno: "); scanf("%f",&palumno->porcen.nota3);
    promedio = (palumno->porcen.nota1 + palumno->porcen.nota2 + palumno->porcen.nota3)/3;

    //Mostramos datos con promedio
    printf("\n");
    printf("Mostrando datos alumno: \n");
    printf("Nombre del Alumno: %s\n", palumno->nombre);
    printf("Genero del Alumno: %s\n", palumno->sexo);
    printf("Edad del Alumno: %d\n", palumno->edad);
    printf("Promedio del Alumno: %0.1f\n", promedio);
}

void ejercicio23(){
    int tamano, base1, base2;
    float promedio[100], menor=999999, mayor=-999999;

struct promedio{
    float nota1, nota2, nota3;
};

struct alumnos{
    char nombre[30];
    char sexo [15];
    int edad;
    struct promedio porcen;
}estudiantes[100], *pestudiantes = estudiantes;

    printf("Ingrese la cantidad de alumnos a examinar: "); scanf("%d",&tamano);

    //Llenando datos
    for(int i=0; i<tamano; i++){
        printf("Ingrese nombre del alumno: "); fflush(stdin); fgets((pestudiantes+i)->nombre, 30, stdin);
        printf("Ingrese genero del alumno: "); fflush(stdin); fgets((pestudiantes+i)->sexo, 30, stdin);
        printf("Ingrese edad del alumno: "); scanf("%d",&(pestudiantes+i)->edad);
        printf("Ingrese Nota No. 1: "); scanf("%f",&(pestudiantes+i)->porcen.nota1);
        printf("Ingrese Nota No. 2: "); scanf("%f",&(pestudiantes+i)->porcen.nota2);
        printf("Ingrese Nota No. 3: "); scanf("%f",&(pestudiantes+i)->porcen.nota3);
        promedio[i] = ((pestudiantes+i)->porcen.nota1 + (pestudiantes+i)->porcen.nota2 + (pestudiantes+i)->porcen.nota3)/3;
        printf("\n");
        if(promedio[i] > mayor){
            mayor = promedio[i];
            base1 = i;
        }
        if(promedio[i] < menor){
            menor = promedio[i];
            base2 = i;
    }
}

    //Imprimimos en pantalla estudiante con mayor y menor promedio
    printf("\n");
    printf("Alumno con mejor promedio: \n");
    printf("Nombre del Alumno: %s\n", (pestudiantes+base1)->nombre);
    printf("Genero del Alumno: %s\n", (pestudiantes+base1)->sexo);
    printf("Edad del Alumno: %d\n", (pestudiantes+base1)->edad);
    printf("Promedio del estudiante: %0.1f\n", promedio[base1]);
    printf("\n");
    printf("Alumno con menor promedio: \n");
    printf("Nombre del Alumno: %s\n", (pestudiantes+base2)->nombre);
    printf("Genero del Alumno: %s\n", (pestudiantes+base2)->sexo);
    printf("Edad del Alumno: %d\n", (pestudiantes+base2)->edad);
    printf("Promedio del estudiante: %0.1f\n", promedio[base2]);
}

void ejercicio24(){
    int cantPersonas=0, i, j = 1, c = 1;
struct Persona{
	char nombre[30];
	int discapacidad;
}personas[100], *ppersonas = personas;

    char opcion = 'n';
	while(opcion != 'e'){
		printf("Ingrese Nombre: ");
		fflush(stdin);
		fgets((ppersonas+cantPersonas)->nombre, 30, stdin);
		printf("Tiene discapacidad\n Ingrese 1 = Si, 0 = No : ");
		scanf("%d", &(ppersonas+cantPersonas)->discapacidad);
		printf("\n");
		cantPersonas += 1;
		printf("Presione e, si desea salir, de lo contrario pulse cualquier tecla");
		printf("\n");
		fflush(stdin);
		scanf("%c",&opcion);
	}

	printf("\n");
	printf("Personas con Discapacidad\n");
	for(i=0; i <cantPersonas; i++){
		if((ppersonas+i)->discapacidad==1){
			printf("%d. %s", j, (ppersonas + i)->nombre);
			j += 1;
		}
	}

	printf("\n");
	printf("\nPersonas sin Discapacidad\n");
	for(i=0; i <cantPersonas;i++){
		if((ppersonas + i)->discapacidad == 0){
			printf("%d. %s", c, (ppersonas + i)->nombre);
			c += 1;
		}
	}

}

