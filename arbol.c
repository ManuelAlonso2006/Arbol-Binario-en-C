#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

struct Nodo{
    void * dato;
    NodoPtr izquierda;
    NodoPtr derecha;
};

NodoPtr crearNodo(void * dato){
    NodoPtr nodo = (NodoPtr)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}


void insertarEnArbol(NodoPtr raiz, void * dato, int(*compararElementos)(void * datoA, void * datoB)){
    if (!raiz){
        return;
    }
    int resultado = compararElementos(raiz->dato, dato);
    if (resultado == 0){
        if (raiz->izquierda == NULL){
            raiz->izquierda = crearNodo(dato);
        }
        else{
            insertarEnArbol(raiz->izquierda, dato, compararElementos);
        }
    }
    if (resultado == 1){
        if (raiz->derecha == NULL){
            raiz->derecha = crearNodo(dato);
        }
        else{
            insertarEnArbol(raiz->derecha, dato, compararElementos);
        }
    }
}

void eliminarDeArbol(NodoPtr * raiz, void * dato, int(*compararElementos)(void * datoA, void * datoB)){
    if (!*raiz){
        return;
    }
    int resultado = compararElementos((*raiz)->dato, dato);

    if (resultado == 0){
        eliminarDeArbol(&(*raiz)->izquierda, dato, compararElementos);
    }
    if (resultado == 1){
        eliminarDeArbol(&(*raiz)->derecha, dato, compararElementos);
    }
    if (resultado == 2){
        NodoPtr basura = (*raiz);
        if (!basura->izquierda && !basura->derecha){
            free(basura);
            *raiz = NULL;
        }
        else if (basura->izquierda && !basura->derecha){
            (*raiz) = basura->izquierda;
            free(basura);
        }
        else if (!basura->izquierda && basura->derecha){
            (*raiz) = basura->derecha;
            free(basura);
        }
        else{
            NodoPtr remplazo = basura->derecha;

            while(remplazo->izquierda){
                remplazo = remplazo->izquierda;
            }
            basura->dato = remplazo->dato;
            eliminarDeArbol(&(*raiz)->derecha, remplazo->dato, compararElementos);
        }
    }
}

int buscarEnArbol(NodoPtr raiz, void * dato, int(*compararElementos)(void * datoA, void * datoB)){
    if (!raiz){
        return 0;
    }
    int resultado = compararElementos(raiz->dato, dato);
    if (resultado == 0){
        return buscarEnArbol(raiz->izquierda, dato, compararElementos);
    }
    if (resultado == 1){
        return buscarEnArbol(raiz->derecha, dato, compararElementos);
    }
    if (resultado == 2){
        return 1;
    }
}

void preOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato)){
    if (raiz){
        mostrarElementos(raiz->dato);
        preOrden(raiz->izquierda, mostrarElementos);
        preOrden(raiz->derecha, mostrarElementos);
    }
}

void inOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato)){
    if (raiz){
        inOrden(raiz->izquierda, mostrarElementos);
        mostrarElementos(raiz->dato);
        inOrden(raiz->derecha, mostrarElementos);
    }
}

void postOrden(NodoPtr raiz, void(*mostrarElementos)(void * dato)){
    if (raiz){
        postOrden(raiz->izquierda, mostrarElementos);
        postOrden(raiz->derecha, mostrarElementos);
        mostrarElementos(raiz->dato);
    }
}