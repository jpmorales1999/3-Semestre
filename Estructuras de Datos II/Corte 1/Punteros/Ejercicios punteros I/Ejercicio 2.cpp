#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[30], *Pcadena;
    int longitud;
    int conta=0 , conte=0, conti=0, conto=0, contu=0;

    printf("Ingrese una cadena de caracteres: \n");
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

    delete[] Pcadena;
    Pcadena = NULL;

    return 0;
}
