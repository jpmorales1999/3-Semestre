#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipo de funciones
void menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
int primo(int);
void ejercicio7();
void ingresarCantidad();
void burbuja();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void mayorPromedio();
void menorPromedio();

//Estructuras
struct alumno{
    char nombre[30];
    float nota1, nota2, nota3;
    float promedio;
}alumnos[100];

struct competidor{
    char nombre[30];
    int edad;
    char sexo[15];
    char club[30];
}competidor1;

struct promedio{
    float nota1, nota2, nota3;
};

struct alumnos{
    char nombre[30];
    char sexo [15];
    int edad;
    struct promedio porcen;
}alumno, estudiantes[30];

//Variables globales
int tamano, base1, base2;
float promedio[100];

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
        printf("3. Ejercicio 3\n");
        printf("4. Ejercicio 4\n");
        printf("5. Ejercicio 5\n");
        printf("6. Ejercicio 6\n");
        printf("7. Ejercicio 7\n");
        printf("8. Ejercicio 8\n");
        printf("9. Ejercicio 9\n");
        printf("10. Ejercicio 10\n");
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
            case 0: exit(0);
            default: printf("Opcion no valida\n");
        }
    }while(opcion != 0);

}

void ejercicio1(){
    float numeros[] = {32.583, 11.239, 45.781, 22.237};
    for(int i=0; i<4; i++){
        printf("%0.3f\n", numeros[i]);
    }
}

void ejercicio2(){
    int numero1, numero2;
    int matriz[100][100];
    printf("Ingrese los valores: ");
    scanf("%d %d",&numero1,&numero2);
    for(int i=0; i<numero1; i++){
        for (int j=0; j<numero2; j++){
            if(j % 2 == 0){
                matriz[i][j]=1;
            }else{
                matriz[i][j]=0;
            }
        }
    }
    //Imprimimos matriz
    for(int i=0; i<numero1; i++){
        for(int j=0; j<numero2; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

void ejercicio3(){
    int vec1[4], vec2[4], vec3[4], vec4[4];

    for(int i=0; i<4; i++){
        printf("Ingrese un valor: ");
        scanf("%d",&vec1[i]);
    }

    for(int i=0; i<4; i++){
        vec2[i] = vec1[i] * vec1[i];
    }

    for(int i=0; i<4; i++){
        vec3[i] = vec2[i] * vec1[i];
    }

    for(int i=0; i<4; i++){
        vec4[i] = vec3[i] * vec1[i];
    }

    //Mostramos en pantalla
    for(int i=0; i<4; i++){
        printf("\t %d", vec1[i]);
        printf("\t %d", vec2[i]);
        printf("\t %d", vec3[i]);
        printf("\t %d", vec4[i]);
        printf("\n");
    }
}

void ejercicio4(){
    int matriz[3][3];
    int suma=0;

    //Llenando matriz
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("Ingrese un numero: ");
            scanf("%d",&matriz[i][j]);
        }
    }

    //Mostrando matriz en pantalla
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("\t %d", matriz[i][j]);
            suma = suma + matriz[i][j];
        }
        printf("\n");
    }
    printf("La suma total de los elementos de la matriz es: %d\n", suma);
}

void ejercicio5(){
    int matriz[3][3], aleatorio;

    //Llenamos matriz con numeros aleatorios
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            aleatorio = 1 + rand()%((100+1) - 1);
            matriz[i][j] = aleatorio;
        }
    }

    //Mostramos matriz
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("\t %d", matriz[i][j]);
        }
        printf("\n");
    }
}

void ejercicio6(){
    int matriz[3][3], aleatorio, comprobacion;

    //Llenamos matriz con numeros primos
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            aleatorio = 2 + rand()%((100+1) - 1);
            comprobacion = primo(aleatorio);
            if(comprobacion==aleatorio){
                matriz[i][j]=comprobacion;
            }else{
                j--;
            }
        }
    }

    //Mostramos matriz en pantalla
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("\t %d", matriz[i][j]);
        }
        printf("\n");
    }
}

int primo(int n){
    int contador=0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            contador++;
        }
    }
    if(contador == 2){
        contador = 0;
        return n;
    }else{
        return 1;
    }
}

void ejercicio7(){
    ingresarCantidad();

    for(int i=0; i<tamano; i++){
        printf("Ingrese nombre alumno: ");
        fflush(stdin);
        fgets(alumnos[i].nombre, 30, stdin);
        printf("Ingrese Nota. 1: "); scanf("%f",&alumnos[i].nota1);
        printf("Ingrese Nota. 2: "); scanf("%f",&alumnos[i].nota2);
        printf("Ingrese Nota. 3: "); scanf("%f",&alumnos[i].nota3);
        alumnos[i].promedio = (alumnos[i].nota1 + alumnos[i].nota2 + alumnos[i].nota3)/3;
        printf("Promedio del alumno: %0.1f\n", alumnos[i].promedio);
        printf("\n");
    }

    //Ordenamos por medio del metodo burbuja
    burbuja();

    //Imprimimos en pantalla los estudiantes por meritos
    printf("Mostrando estudiantes por meritos (promedio): \n");
    for(int i=0; i<tamano; i++){
        printf("\n");
        printf("Nombre alumno: %s\n", alumnos[i].nombre);
        printf("Promedio del alumno: %0.1f\n", alumnos[i].promedio);

    }
}

void ingresarCantidad(){
    printf("Ingrese la cantidad de personas a registrar: ");
    scanf("%d",&tamano);
}

void burbuja(){
    int aux;
    char aux2[30];

    for(int i=0; i<tamano; i++){
		for(int j=0; j<tamano-i; j++){
			if(alumnos[j].promedio < alumnos[j+1].promedio){
                    aux = alumnos[j].promedio;
                    alumnos[j].promedio = alumnos[j+1].promedio;
                    alumnos[j+1].promedio = aux;
                    strcpy(aux2,alumnos[j].nombre);
                    strcpy (alumnos[j].nombre,alumnos[j+1].nombre);
                    strcpy(alumnos[j+1].nombre,aux2);
         }
	  }
   }
}

void ejercicio8(){
    //Pedimos datos del competidor
    printf("Ingrese nombre del competidor: "); fflush(stdin); fgets(competidor1.nombre, 30, stdin);
    printf("Ingrese edad del competidor: "); scanf("%d",&competidor1.edad);
    printf("Ingrese genero del competidor: "); fflush(stdin); fgets(competidor1.sexo, 15, stdin);
    printf("Ingrese club del competidor: "); fflush(stdin); fgets(competidor1.club, 30, stdin);

    //Imprimiendo en pantalla datos y categoria
    printf("\n Mostrando datos del competidor: \n");
    printf("Nombre del competidor: %s\n", competidor1.nombre);
    printf("Edad del competidor: %d\n", competidor1.edad);
    printf("Genero del competidor: %s\n", competidor1.sexo);
    printf("Club del competidor: %s\n", competidor1.club);
    if(competidor1.edad <= 15){
        printf("Su categoria es: Infantil\n");
    }else if(competidor1.edad <= 30){
        printf("Su categoria es: Joven\n");
    }else{
        printf("Su categoria es: Mayor\n");
    }
}

void ejercicio9(){
    float promedio;
    //Ingresamos datos alumno
    printf("Ingrese nombre alumno: "); fflush(stdin); fgets(alumno.nombre, 30, stdin);
    printf("Ingrese genero alumno: "); fflush(stdin); fgets(alumno.sexo, 15, stdin);
    printf("Ingrese edad alumno: "); scanf("%d",&alumno.edad);
    printf("Ingrese nota No. 1 del alumno: "); scanf("%f",&alumno.porcen.nota1);
    printf("Ingrese nota No. 2 del alumno: "); scanf("%f",&alumno.porcen.nota2);
    printf("Ingrese nota No. 3 del alumno: "); scanf("%f",&alumno.porcen.nota3);
    promedio = (alumno.porcen.nota1 + alumno.porcen.nota2 + alumno.porcen.nota3)/3;

    //Mostramos datos con promedio
    printf("\n");
    printf("Mostrando datos alumno: \n");
    printf("Nombre del Alumno: %s\n", alumno.nombre);
    printf("Genero del Alumno: %s\n", alumno.sexo);
    printf("Edad del Alumno: %d\n", alumno.edad);
    printf("Promedio del Alumno: %0.1f\n", promedio);
}

void ejercicio10(){
    ingresarCantidad();
    //Ingresamos datos de los estudiantes
    for(int i=0; i<tamano; i++){
        printf("Ingrese nombre del alumno: "); fflush(stdin); fgets(estudiantes[i].nombre, 30, stdin);
        printf("Ingrese genero del alumno: "); fflush(stdin); fgets(estudiantes[i].sexo, 30, stdin);
        printf("Ingrese edad del alumno: "); scanf("%d",&estudiantes[i].edad);
        printf("Ingrese Nota No. 1: "); scanf("%f",&estudiantes[i].porcen.nota1);
        printf("Ingrese Nota No. 2: "); scanf("%f",&estudiantes[i].porcen.nota2);
        printf("Ingrese Nota No. 3: "); scanf("%f",&estudiantes[i].porcen.nota3);
        promedio[i] = (estudiantes[i].porcen.nota1 + estudiantes[i].porcen.nota2 + estudiantes[i].porcen.nota3)/3;
        printf("\n");
    }

    //Llamamos funciones mayor promedio y menor promedio para imprimir dichos alumnos en pantalla
    mayorPromedio();
    menorPromedio();

    //Imprimimos en pantalla estudiante con mayor y menor promedio
    printf("\n");
    printf("Alumno con mejor promedio: \n");
    printf("Nombre del Alumno: %s\n", estudiantes[base1].nombre);
    printf("Genero del Alumno: %s\n", estudiantes[base1].sexo);
    printf("Edad del Alumno: %d\n", estudiantes[base1].edad);
    printf("Promedio del estudiante: %0.1f\n", promedio[base1]);
    printf("\n");
    printf("Alumno con menor promedio: \n");
    printf("Nombre del Alumno: %s\n", estudiantes[base2].nombre);
    printf("Genero del Alumno: %s\n", estudiantes[base2].sexo);
    printf("Edad del Alumno: %d\n", estudiantes[base2].edad);
    printf("Promedio del estudiante: %0.1f\n", promedio[base2]);
}

void mayorPromedio(){
    int mayor = -999999;
    for(int i=0; i<tamano; i++){
        if(promedio[i] > mayor){
            mayor = promedio[i];
            base1 = i;
        }
    }
}

void menorPromedio(){
    int menor = 999999;
    for(int i=0; i<tamano; i++){
        if(promedio[i] < menor){
            menor = promedio[i];
            base2 = i;
        }
    }
}
