# Árbol Binario Genérico en C
Este proyecto implementa un árbol binario genérico en C, diseñado para almacenar y manipular datos de cualquier tipo mediante el uso de punteros void* y funciones de callback.

# Características Principales
Genérico: Almacena cualquier tipo de dato usando punteros void*

Operaciones completas:

Inserción y eliminación de nodos

Búsqueda de elementos

Recorridos: Pre-orden, In-orden, Post-orden

Sistema de callbacks:

Función de comparación personalizable

Función de visualización de datos

Gestión de memoria segura

# Estructura del Proyecto

```bash
  arbol-binario-c/
    ├── include/
    │  └── arbol.h        # Cabecera con definiciones y prototipos
    ├── src/
    │  └── arbol.c        # Implementación de las funciones
    ├── main.c             # Programa de demostración
    └── README.md          # Este archivo
```
# Funciones Implementadas

```c
// Creación
NodoPtr crearNodo(void * dato);

// Operaciones
void insertarEnArbol(NodoPtr raiz, void * dato, int(*comparar)(void*, void*));
void eliminarDeArbol(NodoPtr * raiz, void * dato, int(*comparar)(void*, void*));
int buscarEnArbol(NodoPtr arbol, void * dato, int(*comparar)(void*, void*));

// Recorridos
void preOrden(NodoPtr raiz, void(*mostrar)(void *));
void inOrden(NodoPtr raiz, void(*mostrar)(void *));
void postOrden(NodoPtr raiz, void(*mostrar)(void *));
```
# Sistema de Comparación
La función de comparación debe seguir esta convención:
```c
int compararElementos(void *datoA, void *datoB) {
    if (A > B) return 0;   // Mayor
    if (A < B) return 1;   // Menor
    return 2;              // Igual
}
```
# Ejemplo de Salida
```bash
Pre-orden:
21
3
1
9
18
12
25
23
In-orden:
1
3
9
12
18
21
23
25
Post-orden:
1
12
18
9
3
23
25
21
In-orden después de eliminar 3:
1
9
12
18
21
23
25
Resultado de búsqueda (18): 1
```
# Requisitos
- **Compilador C (GCC recomendado)**
- **Sistema operativo Unix/Linux o Windows con WSL**
  
# Limitaciones y Mejoras Futuras
- **Insertar en árbol vacío:**

- - Actualmente requiere crear manualmente el primer nodo

- - Solución propuesta:
    ```c
    void insertarEnArbol(NodoPtr *raiz, ...) {
    if (!*raiz) *raiz = crearNodo(dato);
    ```
- **Liberación de memoria:**
- - Agregar función liberarArbol con callback:
     ```c
    void liberarArbol(NodoPtr raiz, void(*liberarDato)(void*));
    ```
