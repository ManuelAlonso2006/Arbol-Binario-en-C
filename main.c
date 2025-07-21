#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

// Recordatorio!!: La funcion de compararEnteros usa la estructura mencionada en el archivo arbol.h
int compararEnteros(void * datoA, void * datoB);
void mostrarEnteros(void * dato);

int main(){
    int num1 = 21, num2 = 3, num3 = 9, num4 = 25, num5 = 18, num6 = 23, num7 = 1, num8 = 12;
    NodoPtr raiz = crearNodo(&num1);
    insertarEnArbol(raiz, &num2, compararEnteros);
    insertarEnArbol(raiz, &num3, compararEnteros);
    insertarEnArbol(raiz, &num4, compararEnteros);
    insertarEnArbol(raiz, &num5, compararEnteros);
    insertarEnArbol(raiz, &num6, compararEnteros);
    insertarEnArbol(raiz, &num7, compararEnteros);
    insertarEnArbol(raiz, &num8, compararEnteros);

    printf("Pre-orden:\n");
    preOrden(raiz, mostrarEnteros);

    printf("In-orden:\n");
    inOrden(raiz, mostrarEnteros);

    printf("Post-orden:\n");
    postOrden(raiz, mostrarEnteros);

    //eliminamos el numero 3
    eliminarDeArbol(&raiz, &num2, compararEnteros);

    printf("In-orden:\n");
    inOrden(raiz, mostrarEnteros);

    //buscamos el numero 18
    int resultado = buscarEnArbol(raiz, &num5, compararEnteros);
    printf("Resultado de busqueda: %d\n", resultado);
    

}


int compararEnteros(void * datoA, void * datoB){
    //Desreferenciamos los datos
    int num1 = *(int*)datoA;
    int num2 = *(int*)datoB;

    //Los comparamos usando la estructura ya mencionada
    if (num1 > num2){
        return 0;
    }
    else if (num1 < num2){
        return 1;
    }
    else{
        return 2;
    }
}

void mostrarEnteros(void * dato){
    //Desreferenciamos el dato
    int num = *(int*)dato;
    printf("%d\n", num);
}