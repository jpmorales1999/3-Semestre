#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct arbol proyecto
struct nodo{
    char nombre[30]; //nombre de la persona
    int cedula; //cedula de la persona
    int edad; //edad de la persona
    struct nodo *izq; //nodo derecho
    struct nodo *der; //nodo izquierdo
    struct nodo *padre; //nodo padre
};

//variables globales
nodo *arbol = NULL; //variable puntero arbol de tipo struct nodo inicializada en NULL
char nombre[30]; //aux para almacenar el nombre 
int cedula; //aux para almacenar la cedula

//prototipos de funciones
void menu();
nodo *crear_Nodo(int, nodo *); //Crear un nuevo nodo en el arbol
void insertar(nodo *&, int, nodo *); //Insertar en el arbol
bool comprobarNombre(nodo *, char[]); //comprobamos si el nombre ya se encuentra registrado en el arbol
bool comprobarCedula(nodo *, int); //comprobamos si la identificacion ya se encuentra registrada en el arbol
void mostrar(nodo *); //Mostrar arbol en su totalidad
bool busqueda(nodo *, int); //Buscar algun nodo en el arbol
void modificar(nodo *, int); //Modificar algun nodo del arbol
void preorden(nodo *); //Mostrar arbol en preorden
void inorden(nodo *); //Mostrar arbol en inorden
void postorden(nodo *); //Mostrar arbol en postorden
void eliminar(nodo *, int); //Eliminar un nodo del arbol
void eliminarNodo(nodo *); //Eliminar el nodo encontrado
nodo *minimo(nodo *); //en el momento que se desee eliminar un nodo con dos hijos con esta funcion sacamos el nodo minimo recorrido der a izq posible
void reemplazar(nodo *, nodo *); //Reemplazar nodos (eliminar nodo con un solo hijo)
void destruirNodo(nodo *&); //destruye un respectivo nodo
void podar(nodo *&); //Eliminar - Cortar todo el arbol
int numeroNodos(nodo *, int *); //retorna numero total de nodos en el arbol
void auxContador(nodo *, int *); //determinar cuantos nodos hay en el arbol
int alturaArbol(nodo *, int *); //retorna altura total del arbol
void auxAltura(nodo *, int, int *); //calcula la altura del arbol
int esHoja(nodo *); //determina si el nodo es hoja
int gradoNodo(nodo *, int, int *); //funcion que retorna el grado total del nodo
void auxGrado(nodo *, int, int *); //funcion que calcula el grado o total de hijos de un nodo

int main(){
    system("color 70"); //fondo color blanco letra color negro
    menu(); //llamamos la funcion menú

    return 0;
}

//menu principal
void menu(){
    int opcion, valor, nnodos, altura, grado;
    
    do{
       printf("\t\tMENU PRINCIPAL\n\n");
       printf("1. Registrar Persona\n");
       printf("2. Mostrar Personas Registradas\n");
       printf("3. Buscar Persona\n");
       printf("4. Modificar Persona\n"); //Solo numero de documento
       printf("5. Mostrar Recorrido del Arbol (Preorden)\n");
       printf("6. Mostrar Recorrido del Arbol (Inorden)\n");
       printf("7. Mostrar Recorrido del Arbol (Postorden)\n");
       printf("8. Mostrar nodos del Arbol\n");
       printf("9. Mostrar altura del Arbol\n");
       printf("10. Mostrar Grado\n");
       printf("11. Eliminar Persona\n");
       printf("12. Eliminar Todos los Registros\n");
       printf("13. Salir\n\n");
       printf("Ingrese una opcion: ");
       scanf("%d",&opcion);
       switch(opcion){

       case 1:
       	    printf("\n");
       	    fflush(stdin); 
       	    printf("Ingrese su nombre: "); fgets(nombre, 30, stdin);
       	    printf("Ingrese su cedula: "); scanf("%d",&cedula);
       	    printf("Ingrese su edad: "); scanf("%d",&valor); //ingresamos edad representara la organizacion de los nodos
       	    
       	    if(comprobarNombre(arbol, nombre) == false){ //si comprobarNombre retorna false es porque no se encontro el nombre registrado en el arbol y es posible registrarlo
       	        if(comprobarCedula(arbol, cedula) == false){ //si comprobarCedula retorna false es porque no se encuentro la cedula registrada en el arbol y es posible registrarla
				        if(valor >= 55){ //si edad es mayor o igual a 55 podrá insertar en el arbol
       		            insertar(arbol, valor, NULL); //insertar
       		            printf("\nSe registro Correctamente...\n");
		                }else{ //si el numero es menor que 55 no podra insertar en el arbol
			            printf("\nNo te puedes registrar, eres menor de 55 anos\n");
		                }
		        }else if(comprobarCedula(arbol, cedula) == true){ //si comprobarCedula retorna true significa que ya se encuentra la cedula registrada en el arbol
		        	printf("No te puedes registrar, la cedula ya se encuentra en el arbol...\n");
				} 
		    }else if(comprobarNombre(arbol, nombre) == true){ //si comprobarNombre retorna true significa que ya se encuentra el nombre registrado en el arbol
		    	printf("No te puedes registrar, el nombre ya se encuentra en el arbol...\n");
			}   
       	    break;

       	case 2:
       	    printf("\n");
		    printf("Mostrando Arbol: \n\n");
		    mostrar(arbol); //llamamos a la funcion mostrar arbol
		    break;

		case 3:
			printf("\n");
			fflush(stdin);
			printf("Ingrese el nodo (edad) de la persona a buscar: "); //ingresamos edad de la persona a buscar
			scanf("%d",&valor);
			if(busqueda(arbol, valor) == true){ //si la funcion busqueda retorna true es porque encontro el elemento en el arbol
				printf("\nSe encontro la persona en el arbol...\n");
			}else{ //si la funcion busqueda retorna falso es porque no encontro el elemento en el arbol
				printf("\nNo se encontro la persona en este arbol...\n");
			}
			break;

		case 4:
			printf("\n");
			fflush(stdin);
			printf("Ingrese el nodo (edad) de la persona a buscar: "); //ingresamos edad de la persona a buscar
			scanf("%d",&valor);
			modificar(arbol, valor);
			break;

		case 5:
			printf("\n");
			printf("Mostrando arbol en preorden: ");
			preorden(arbol);
			printf("\n");
			break;

		case 6:
			printf("\n");
			printf("Mostrando arbol en inorden: ");
			inorden(arbol);
			printf("\n");
			break;

		case 7:
			printf("\n");
			printf("Mostrando arbol en postorden: ");
			postorden(arbol);
			printf("\n");
			break;
			
		case 8:
			printf("\n");
			printf("Numero de Nodos: %d\n\n", numeroNodos(arbol, &nnodos)); 
			break;
			
		case 9:
			printf("\n");
			printf("Altura del Arbol: %d\n\n", alturaArbol(arbol, &altura)); 
			break;
			
		case 10:
			printf("\n");
			printf("Ingrese el nodo a calcular su Grado: "); //digitamos el nodo (edad) a calcular su grado
			scanf("%d",&valor);
			printf("\nGrado del Nodo: %d\n\n", gradoNodo(arbol, valor, &grado)); 
			break;

		case 11:
			printf("\n");
			printf("Digite el nodo (edad) a eliminar: "); //digitamos el nodo (edad) a eliminar
			scanf("%d",&valor);
			eliminar(arbol, valor);
			printf("\n");
			break;
			
		case 12:
			printf("\n");
			podar(arbol);
			printf("Se elimino el arbol Correctamente...\n");
			break;
			
		case 13:
			exit(0);
			break;
			
		default: printf("Opcion Invalida...\n");

        }

       system("pause");
       system("cls");

    }while(opcion!=13);
}

//funcion para crear un nuevo nodo asignando todos los campos (variables) de la estructura
nodo *crear_Nodo(int valor, nodo *padre){
	//creamos un nuevo_nodo de tipo nodo
	nodo *nuevo_nodo = new nodo();

	//asignamos al nuevo_nodo->edad el valor ingresado por el usuario, que lo referenciamos como la edad en el primer caso del switch
	nuevo_nodo->edad = valor;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre; //nuevo_nodo->padre asignara quien es el padre del nuevo nodo creado (actual)

	//asignamos el nombre en el nuevo nodo
	strcpy(nuevo_nodo->nombre, nombre); 

	//asignamos la identificacion del usuario en el nuevo nodo
	nuevo_nodo->cedula = cedula;

	//retornamos nuevo nodo
	return nuevo_nodo;
}

//funcion para insertar en el arbol
void insertar(nodo *&arbol, int valor, nodo *padre){
	//si el arbol se encuentra vacio
	if(arbol == NULL){
		//creamos un nuevo nodo llamando la funcion crear nodo
		nodo *nuevo_nodo = crear_Nodo(valor, padre);
		//le asignamos al arbol el nuevo nodo
		arbol = nuevo_nodo;
	}else{ //si el arbol ya se encuentra lleno

		int valorRaiz = arbol->edad; //Obtenemos el valor de la raiz

		if(valor < valorRaiz){ //si el valor (edad) es menor que el valor de la raiz insertamos al lado izquierdo y enviamos como parametro el arbol actual con el cual podremos determinar su nodo padre
			insertar(arbol->izq, valor, arbol);
		}else if(valor > valorRaiz){ //si el valor (edad) es mayor que el valor de la raiz insertamos al lado derecho y enviamos como parametro el arbol actual con el cual podremos determinar su nodo padre
			insertar(arbol->der, valor, arbol);
		}
	}
}

//funcion para mostrar el arbol
void mostrar(nodo *arbol){
	if(arbol == NULL){ //si arbol esta vacio return
		return;
	}else{ //si no procedemos a mostrar el arbol primeramente por el lado derecho y posteriormente el lado izquierdo de manera recursiva
		mostrar(arbol->der);
		printf("Nombre: %s", arbol->nombre); //mostramos nombre
		printf("Edad: %d\n", arbol->edad); //mostrar edad
		printf("Documento: %d\n\n", arbol->cedula); //mostramos cedula
		mostrar(arbol->izq);
	} 
}

//funcion busqueda - determina si un elemento existe en el arbol
bool busqueda(nodo *arbol, int valor){
	if(arbol == NULL){ //si arbol esta vacio retorne falso
		return false;
	}else if (arbol->edad == valor){ //comparamos si el valor ingresado es igual al valor actual del arbol
		return true;
	}else if(valor < arbol->edad){ //si valor es menor que la edad actual del arbol entonces buscaremos por la izquierda
		busqueda(arbol->izq, valor); //llamamos a la funcion busqueda pero buscando por la izquierda con el valor ingresado por el usuario (de forma recursiva)
	}else if(valor > arbol->edad){ //si valor es mayor que la edad actual del arbol entonces buscaremos por la derecha
		busqueda(arbol->der, valor); //llamamos a la funcion busqueda pero buscando por la derecha con el valor ingresado por el usuario (de forma recursiva)
	}
}

//funcion modificar solamente (documento de una persona)
void modificar(nodo *arbol, int valor){
	if(arbol == NULL){ //si arbol esta vacio
		printf("\nNo se encontro en el arbol, Intentalo nuevamente...\n");
	}else if (arbol->edad == valor){ //comparamos si el valor ingresado es igual al valor actual del arbol
		printf("\nSe encontro la persona en el arbol...\n\n");
		printf("Ingrese su nuevo numero de documento: ");
		scanf("%d",&(arbol->cedula));
		printf("\nSe modifico correctamente el documento...\n");
	}else if(valor < arbol->edad){ //si valor es menor que la edad actual del arbol entonces buscaremos por la izquierda
		modificar(arbol->izq, valor); //llamamos a la funcion modificar pero buscando por la izquierda con el valor ingresado por el usuario (de forma recursiva)
	}else if(valor > arbol->edad){ //si valor es mayor que la edad actual del arbol entonces buscaremos por la derecha
		modificar(arbol->der, valor); //llamamos a la funcion modificar pero buscando por la derecha con el valor ingresado por el usuario (de forma recursiva)
	}
}

//mostrar arbol en la siguiente secuencia: raiz - subarbol izquierdo - subarbol derecho
void preorden(nodo *arbol){
	if(arbol == NULL){ //si arbol esta vacio retorne
		return;
	}else{ //si arbol esta lleno
		printf("%d - ", arbol->edad); //imprimimos edad actual del arbol
		preorden(arbol->izq); //llamamos a la funcion preorden recorriendo primeramente el subarbol izquierdo de forma recursiva
		preorden(arbol->der); //llamamos a la funcion preorden recorriendo el subarbol derecho de forma recursiva
	}
}

//mostrar arbol en la siguiente secuencia: subarbol izquierdo - raiz - subarbol derecho
void inorden(nodo *arbol){
	if(arbol == NULL){ //si arbol esta vacio retorne
		return;
	}else{ //si arbol esta lleno
		inorden(arbol->izq); //recorremos primeramente el subarbol izquierdo de forma recursiva
		printf("%d - ", arbol->edad); //imprimimos edad actual del arbol
		inorden(arbol->der); //recorremos el subarbol derecho de forma recursiva
	}
}

//mostrar arbol en la siguiente secuencia: subarbol izquierdo - subarbol derecho - raiz
void postorden(nodo *arbol){
	if(arbol == NULL){ //si arbol esta vacio retorne
		return;
	}else{ //si arbol esta lleno
		inorden(arbol->izq); //recorremos primeramente el subarbol izquierdo de forma recursiva
		inorden(arbol->der); //luego recorremos el subarbol derecho de forma recursiva
		printf("%d - ", arbol->edad); //imprimimos edad actual del arbol
	}
}

//funcion para eliminar un nodo del arbol
void eliminar(nodo *arbol, int valor){
	if(arbol == NULL){ //si el arbol esta vacio
		return; //no realiza ninguna accion
	}else if(valor < arbol->edad){ //si el valor es menor que la edad actual del arbol
		eliminar(arbol->izq, valor); //buscar o recorrer por la parte izquierda del arbol
	}else if(valor > arbol->edad){ //si el valor es mayor que la edad actual del arbol
		eliminar(arbol->der, valor); //buscar o recorrer por la parte derecha del arbol
	}else{ //si ya encontro el valor
		eliminarNodo(arbol);
		printf("\nSe elimino correctamente del Arbol...\n");
	}
}

//funcion para determinar el nodo mas izquierdo posible
nodo *minimo(nodo *arbol){
	if(arbol == NULL){ //si el arbol esta vacio
		return NULL; //retonar NULL
	}
	if(arbol->izq){ //si tiene hijo izquierdo
		return minimo(arbol->izq); //buscar la parte mas izquierda posible
	}else{ //si no tiene hijo izquierdo
		return arbol; //retornamos el mismo nodo
	}
}

//funcion para reemplazar dos nodos
void reemplazar(nodo *arbol, nodo *nuevo_nodo){
	if(arbol->padre){ //si el nodo arbol tiene padre
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->padre->izq == arbol){ //determina si el nodo (padre) tiene un hijo izquierdo
			arbol->padre->izq = nuevo_nodo; //cambiamos por el nuevo_nodo
		}else if(arbol->padre->der == arbol){ //determina si el nodo (padre) tiene un hijo derecho
			arbol->padre->der = nuevo_nodo; //cambiamos por el nuevo_nodo
		}
	}
	if(nuevo_nodo){ //si nuevo nodo existe
	    //Le asignamos al nuevo_nodo su nuevo padre
	    nuevo_nodo->padre = arbol->padre; //el nuevo nodo apuntara a su nuevo padre
	}
}

//funcion para destruir un nodo
void destruirNodo(nodo *&nodo){
	nodo->izq = NULL; //nodo apuntando a izq NULL
	nodo->der = NULL; //nodo apuntando a der NULL
	free(nodo); //liberamos el nodo 
	nodo = NULL; //por si acaso lo igualamos a NULL
}

//funcion para eliminar el nodo encontrado
void eliminarNodo(nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){ //si el nodo tiene hijo izquierdo e hijo derecho
		nodo *menor = minimo(nodoEliminar->der); //mandamos a la funcion minimo el hijo derecho del nodo actual para asi desde alli determinar su hijo mas izquierdo posible y almacenamos lo que nos retorne en la variable puntero menor
		nodoEliminar->edad = menor->edad; //cambiamos el valor actual del nodo a eliminar por el valor de la variable menor
		eliminarNodo(menor); //eliminamos el nodo menor (variable menor)
	}else if(nodoEliminar->izq){ //si el nodo a eliminar tiene hijo izquierdo
		reemplazar(nodoEliminar, nodoEliminar->izq); //reemplazar el nodo a eliminar por su hijo izquierdo
		destruirNodo(nodoEliminar); //destruir nodo
	}else if(nodoEliminar->der){ //si el nodo a eliminar tiene hijo derecho
		reemplazar(nodoEliminar, nodoEliminar->der); //reemplazar el nodo a eliminar por su hijo derecho
		destruirNodo(nodoEliminar); //destruir nodo
	}else{ //si es un nodo hoja (no tiene hijos)
		reemplazar(nodoEliminar, NULL); //reemplazar el nodo eliminar por NULL
		destruirNodo(nodoEliminar); //destruir nodo
	}
}

//funcion para podar completamente el arbol
void podar(nodo *&arbol){
	if(arbol){ //si existen nodos
      podar((arbol)->izq); //elimina todos los nodos del lado izquierdo
      podar((arbol)->der); //posteriormente elimina todos los nodos del lado derecho
      free (arbol); //liberamos el nodo
	  arbol = NULL; //igualamos nodo a NULL
   }
}

//funcion para retornar el total de nodos en el arbol
int numeroNodos(nodo *arbol, int *contador){
	*contador = 0; //igualamos contador a 0
	
	auxContador(arbol, contador); //llamos la funcion auxContador
	 
	return *contador; //retornamos contador
}

//funcion para calcular el total de nodos del arbol
void auxContador(nodo *arbol, int *contador){
	(*contador)++; //aumenta al contador en uno
	
	if(arbol->izq){ //si nodo tiene hijo izquierdo
		auxContador(arbol->izq, contador); //recorremos el arbol por la izquierda aumentando el contador de forma recursiva
	}
	
	if(arbol->der){ //si nodo tiene hijo derecho
		auxContador(arbol->der, contador); //recorremos el arbol por la derecha aumentando el contador de forma recursiva
	}
}

//funcion que retorna la altura total del arbol
int alturaArbol(nodo *arbol, int *altura){
	*altura = 0; //igualamos altura a 0
	
	auxAltura(arbol, 0, altura); //llamamos la funcion auxAltura
	
	return *altura; //retornamos el valor final de altura
}

//funcion para calcular la altura total del arbol
void auxAltura(nodo *arbol, int a, int *altura){
	if(arbol->izq){ //si nodo tiene hijo izquierdo
 		auxAltura(arbol->izq, a+1, altura); //recorremos el arbol por la izquierda aumentando la altura de forma recursiva
	}
	
	if(arbol->der){ //si el nodo tiene hijo derecho
		auxAltura(arbol->der, a+1, altura); //recorremos el arbol por la derecha aumentando la altura de forma recursiva
	}
	
	if(esHoja(arbol) && a > *altura){ //si el nodo es hoja y a es mayor que altura entonces
		*altura = a; //altura sera igual a la variable a
	}
}

//funcion que determina si un nodo es hoja
int esHoja(nodo *nodo){
	return !nodo->der && !nodo->izq; //retorna si el nodo no tiene hijo derecho y hijo izquierdo
}

//funcion que retorna el grado o numero de hijos de un nodo
int gradoNodo(nodo *arbol, int valor, int *grado){
	*grado = 0; //igualamos grado a 0
	
	auxGrado(arbol, valor, grado); //llamamos a la funcion auxGrado
	 
	return *grado; //retornamos el valor final del grado
}

//funcion que calcula el grado total de un nodo
void auxGrado(nodo *arbol, int valor, int *grado){
	if(arbol == NULL){ //si nodo vacio retorna
		return;
	}else if(arbol->edad == valor){ //si nodo->edad es igual al valor entonces
		if(arbol->izq && arbol->der){ //si el nodo tiene hijo derecho y izquierdo
			(*grado) = 2; //grado sera igual a 2
		}else if(arbol->izq || arbol->der){ //si solamente tiene un hijo
			(*grado) = 1; //grado sera igual a 1
		}
	}else if(valor < arbol->edad){ //si valor es menor que el nodo
		auxGrado(arbol->izq, valor, grado); //entonces buscamos por la izquierda dicho nodo
	}else if(valor > arbol->edad){ //si valor es mayor que el nodo
		auxGrado(arbol->der, valor, grado); //entonces buscamos por la derecha dicho nodo
	}
}

//funcion para determinar si un nombre ya se encuentra registrado en el arbol
bool comprobarNombre(nodo *arbol, char nombre[]){
	if(arbol == NULL){ //si arbol es null
		return false; //retorna false que significa que no se encontro el nombre registrado en el arbol
	}else if(strcmp(arbol->nombre, nombre) == 0){ //si nodo apuntando a nombre es igual al nombre que se desea registrar
		return true; //retorna true que significara que ya se encuentra registrado en el arbol
	}else if(arbol->izq){ //recorremos el arbol por la izquierda
		comprobarNombre(arbol->izq, nombre); //mandamos a comprobar de manera recursiva que el nombre ya no se encuentre registrado por la parte izq del arbol
	}else if(arbol->der){ //recorremos el arbol por la derecha
		comprobarNombre(arbol->der, nombre); //mandamos a comprobar de manera recursiva que el nombre ya no se encuentre registrado por la parte der del arbol
	}
}

//funcion para determinar si una identificacion ya se encuentra registrada en el arbol
bool comprobarCedula(nodo *arbol, int cedula){
	if(arbol == NULL){ //si arbol es null
		return false; //retorna false que significa que no se encontro la identificacion registrada en el arbol
	}else if(arbol->cedula == cedula){ //si nodo apuntando a cedula es igual a la cedula que se desea registrar
		return true; //retorna true que significara que ya se encuentra registrada en el arbol
	}else if(arbol->izq){ //recorremos el arbol por la izquierda
		comprobarCedula(arbol->izq, cedula); //mandamos a comprobar de manera recursiva que la identificacion ya no se encuentre registrada por la parte izq del arbol
	}else if(arbol->der){ //recorremos el arbol por la derecha
		comprobarCedula(arbol->der, cedula); //mandamos a comprobar de manera recursiva que la identifacion ya no se encuentre registrada por la parte der del arbol
	}
}

