#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int numero1, *Pnumero1 = &numero1;
    int numero2, *Pnumero2 = &numero2;
    int resultado, *Presultado = &resultado;

    printf("Ingrese dos numeros: \n");
    scanf("%d %d",&numero1,&numero2);

    resultado = (*Pnumero1 + *Pnumero2);

    printf("La suma total es: %d\n", resultado);
    printf("Posicion en memoria del primer numero: %p\n", Pnumero1);
    printf("Posicion en memoria del segundo numero: %p\n", Pnumero2);
    printf("Posicion en memoria de la variable resultado: %p\n", Presultado);

    delete Pnumero1, Pnumero2, Presultado;
    Pnumero1 = NULL;
    Pnumero2 = NULL;
    Presultado = NULL;

    return 0;
}
