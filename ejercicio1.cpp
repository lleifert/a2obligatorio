#include <cassert>
#include <string>
#include <iostream>
#include <limits>

#include "./clases/Libro.cpp"
#include "./tads/AVL.cpp"

using namespace std;

// Si la funcion retorna un numero mayor a cero entonces el Id del Libro A es mayor al Id del Libro B
int comparacionLibroPorId(Libro a, Libro b)
{
  return a.getId() - b.getId();
}

int main()
{
    /**
     * Estás desarrollando un sistema para gestionar el inventario de libros de una biblioteca.
     * Cada libro tiene un número de identificación único (ID), un título y un estado de disponibilidad (habilitado o deshabilitado).
     * El sistema utiliza un Árbol AVL para almacenar y gestionar la información de los libros.
     */

    // Creo la biblioteca como un puntero a una estructura de datos del tipo Arbol AVL.
    // Paso como parametro la funcion que se encarga de comparar los libros para poder ordenar.
    AVL<Libro>* biblioteca = new AVL<Libro>(comparacionLibroPorId);

    /**
     * 1. **Agregar o actualizar un libro**: Insertar un libro con un ID y un título en el árbol AVL.
     *                                       Si el ID ya existe, el título del libro se actualiza con el nuevo nombre proporcionado.
     *                                       El árbol debe mantenerse balanceado después de cada inserción o actualización.
     */
    cout << "Creo Libro 1" << endl;
    Libro l1(15, "Don_Quijote", true);
    cout << "Inserto Libro 1" << endl;
    biblioteca->insert(l1);
    
    cout << "Creo Libro 2" << endl;
    Libro l2(23, "La_Casa_de_los_Espiritus", true);
    cout << "Inserto Libro 2" << endl;
    biblioteca->insert(l2);

    cout << "Creo Libro 3" << endl;
    Libro l3(25, "Cien_Años_de_Soledad", true);
    biblioteca->insert(l3);
    
    cout << "Creo Libro 4" << endl;
    Libro l4(66, "Alien_8", true);
    biblioteca->insert(l4);

    /**
     * 2. **Buscar un libro por su ID**: Consultar si un libro con un ID específico existe en la biblioteca.
     *                                   Si el libro existe y está habilitado, devolver su título; si no, devolver "libro_no_encontrado".
     */
    cout << "Existe el libro 1 en la biblioteca?" << endl;
    if (biblioteca->contains(l1))
    {
      cout << "Existe el libro l1" << endl;
    }
    else
    {
      cout << "libro_no_encontrado" << endl;
    }

    cout << "Existe el libro 4 en la biblioteca?" << endl;
    if (biblioteca->contains(l4))
    {
      cout << "Existe el libro l3" << endl;
    }
    else
    {
      cout << "libro_no_encontrado" << endl;
    }

    /**
     * 3. **Habilitar o deshabilitar un libro**: Cambiar el estado de un libro a habilitado si está deshabilitado,
     *                                           o a deshabilitado si está habilitado, basándose en su ID.
     *                                           Si el ID no existe, devolver "libro_no_encontrado".
     */
    cout << "Cambiar el estado del libro 4" << endl;
    if (biblioteca->contains(l4))
    {
      if (l1.getEstado())
      {
        l1.setEstado(false);
      }
      else
      {
        l1.setEstado(true);
      }
    }
    else
    {
      cout << "libro_no_encontrado" << endl;
    }

    /**
     * 4. **Consultar la cantidad de libros habilitados y deshabilitados**: Proporcionar una consulta que devuelva la cantidad total de libros,
     *                                                                      así como la cantidad de libros habilitados y deshabilitados.
     */
    biblioteca->imprimir();

    return 0;
}


// g++ -std=c++11 -o ejercicio1 ejercicio1.cpp && ejercicio1.exe 

/* PRIMER TEST
11
ADD 15 Don_Quijote
ADD 23 La_Casa_de_los_Espiritus
FIND 15
FIND 88
TOGGLE 15
FIND 15
ADD 25 Cien_Años_de_Soledad
COUNT
TOGGLE 99
TOGGLE 23
COUNT
*/