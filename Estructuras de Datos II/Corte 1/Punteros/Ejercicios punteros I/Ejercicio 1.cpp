#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    char a, *p;

    printf("Ingrese un valor para la variable: \n");
    scanf("%c",&a);
    p = &a;

    while(a>=48 && a<=57){
        printf("Ingrese un valor mayor que cero: \n");
        scanf("%d",&a);
        p = &a;
    }

    system("cls");
    printf("a = %d\n", a); /* Se imprime el valor de a */
    printf("La direccion de a es %p\n", &a);
    printf("*p = %p\n", p); /* Se imprime la direccion que guarda p */
    printf("a = %d\n", *p); /* Se imprime el valor guardado en la direccion a la que apunta p */
    printf("El tamano *p es %d\n", sizeof(p));
    delete[] p;
    printf("Valor de p = %d\n", p);
    p = NULL;
    printf("p despues del delete = %d\n", p);
    getch();
    return 0;
}
