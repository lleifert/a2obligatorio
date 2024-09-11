#include <cassert>
#include <string>
#include <iostream>
#include <limits>

#include "./clases/Libro.cpp"
#include "./tads/Table.h"
#include "./tads/HashCerrado.cpp"

using namespace std;

int hash1(string key) {
    int h = 0;
    for (int i=0; i<key.length(); i++)
        h = h + key[i];
    return h;
}

int hash2(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++)
        h = h + key[i] * (i + 1);
    return h;
}

int hash3(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++)
        h = 31 * h + int(key[i]);
    return h;
}

int main()
{
    /**
     * Este ejercicio es similar al [**Ejercicio 1**](/ejercicios/ejercicio1), pero en esta ocasión,
     * utilizarás una tabla hash con hashing cerrado (también conocido como hashing con encadenamiento abierto)
     * y resolución de colisiones mediante **doble hash**.
     *
     * El sistema para gestionar el inventario de libros de una biblioteca almacenará cada libro con un número
     * de identificación único (ID), un título, y un estado de disponibilidad (habilitado o deshabilitado).
     * Las operaciones que se deben implementar son las mismas que en el Ejercicio 1.
     */
    
    /**
     * 1. **Agregar o actualizar un libro**: Insertar un libro con un ID y un título en el árbol AVL.
     *                                       Si el ID ya existe, el título del libro se actualiza con el nuevo nombre proporcionado.
     *                                       El árbol debe mantenerse balanceado después de cada inserción o actualización.
     */
    int N;                           // N es la cantidad de comandos a ejecutar, viene en la primera linea
    string comando;                  // linea con el comando y atributos a ejectuar
    string id_libro;
    string titulo_libro;

    // Creo la biblioteca como un puntero a una estructura de datos del tipo Tabla de Hash Cerrado.
    // Paso como parametro la funcion que se encarga de hacer el hash.
    Table<string, int> * biblioteca = new HashCerrado<string, int>(N, hash3);
    
    //string palabra;                  // Es la key leida del archivo de prueba
    //int cantPalabrasRepetidas = 0;   // Cantidad final de palabras repetidas
    
    cin >> N;                        // Leo la cantidad de comandos

    cout << "## " << N << " COMANDOS" << endl;

    // recorro el resto del archivo ejectuando los comandos solicitados
    for (int i = 1; i <= N; i++)
    {
        cin >> comando;

        if ( comando == "ADD" )
        {
            // si el comando es un ADD entonces tengo que leer el ID y el TITULO del libro
            cin >> id_libro;
            cin >> titulo_libro;
                    
            cout << "## " << i << ". ADD > ID: " << id_libro << " TITULO: " << titulo_libro << endl;

            // creo el libro
            cout << "Creo Libro 1" << endl;
            Libro l1(id_libro, titulo_libro, true);
            cout << "Inserto Libro 1" << endl;
            biblioteca->insert(l1); 
        }
        else if ( comando == "FIND")
        {
            // si el comando es un FIND entonces tengo que leer el ID
            cin >> id_libro;

            cout << "## " << i << ". FIND > ID: " << id_libro << endl;
        }
        else if ( comando == "TOGGLE")
        {
            // si el comando es un TOGGLE entonces tengo que leer el ID
            cin >> id_libro;

            cout << "## " << i << ". TOGGLE > ID: " << id_libro << endl;
        }
        else if ( comando == "COUNT")
        {
            // si el comando es un COUNT simplemente muestro el resultado
            cout << "## " << i << ". COUNT" << endl;
        }
        else
        {
            // si no existe el comando ingresado
            cout << "El comando ingresado no es correcto." << endl;
        }
    }

    // cout << "Son " << N << " palabras, ";

    // Table<string, int> * tabla = new HashCerrado<string, int>(N, hash3);

    // for (int i=0; i<N; i++)
    // {
    //     cin >> palabra;
    //     tabla->insert(palabra, 0);
    // }
    
    // /*
    // Recorro la tabla e identifico los repetidos 2 veces.
    // Los sumo a la variable cantPalabrasRepetidas.
    // Es O(N) caso promedio en tiempo de ejecución?.
    // */
    // for (int i=0; i<N; i++)
    // {
    //     if (tabla->getBucketNumRepeticiones(i) == 2)
    //     {
    //         cantPalabrasRepetidas = cantPalabrasRepetidas + 1;
    //     }
    // }

    // if (cantPalabrasRepetidas == 1)
    // {
    //     cout << cantPalabrasRepetidas << " repetida." << endl;
    // }
    // else
    // {
    //     cout << cantPalabrasRepetidas << " repetidas." << endl;
    // }
    
    return 0;
}


// g++ -std=c++11 -o ejercicio2 ejercicio2.cpp && ejercicio2.exe 

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