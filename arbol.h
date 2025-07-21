#ifndef ARBOL_H
#define ARBOL_H


//¡Atencion!: En este codigo las funciones de comparar elementos siguen la siguiente estructura:

// Si el elemento A es mayor al elemento B la funcion debe retornar un 0.
// EJEMPLO: int compararElementos(A, B){
//              if (A > B){
//                  return 0;
//              }
// }

// Si el elemento B es mayor al elemento A la funcion debe retornar un 1.
// EJEMPLO: int compararElementos(A, B){
//              if (B > A){
//                  return 1;
//              }
// }

// Y en caso de que los valores sean iguales la funcion debe retornar un 2.
// EJEMPLO: int compararElementos(A, B){
//              if (A == B){
//                  return 2;
//              }
// }


struct Nodo;
typedef struct Nodo * NodoPtr;
NodoPtr crearNodo(void * dato);


void insertarEnArbol(NodoPtr raiz, void * dato, int(*compararElementos)(void * datoA, void * datoB));
void eliminarDeArbol(NodoPtr * raiz, void * dato, int(*compararElementos)(void * datoA, void * datoB));
int buscarEnArbol(NodoPtr arbol, void * dato, int(*compararElementos)(void * datoA, void * datoB));
void preOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato));
void inOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato));
void postOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato));



#endif