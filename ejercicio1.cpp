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
    // variables tests
    int N;
    string comando;

    // variables libros
    int id;
    string titulo;

    // variables sistema
    int total_libros = 0;
    int total_libros_habilitados = 0;
    int total_libros_deshabilitados = 0;

    // estructura principal para la biblioteca
    AVL<Libro>* biblioteca = new AVL<Libro>(comparacionLibroPorId);

    // leo la primer linea del test que tiene la cantidad de comandos a ejecutar
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> comando;

        if ( comando == "ADD" )
        {
            /**
             * Estructura del comando: ADD <ID del libro> <Título del libro>
             */
            cin >> id;
            cin >> titulo;

            // creo el libro a insertar
            Libro l(id, titulo, true);

            // verifico si el libro ya existe en la biblioteca
            if ( biblioteca->contains(l) )
            {
                // si existe entonces le modifico el nombre y lo habilito (si esta deshabilitado)
                Libro& x = biblioteca->get(l);

                if ( x.getEstado() )
                {
                    x.setTitulo(l.getTitulo());
                }
                else
                {
                    x.setTitulo(l.getTitulo());
                    x.setEstado(true);

                    total_libros_deshabilitados--;
                    total_libros_habilitados++;
                }
            }
            else
            {
                // si no existe lo inserto
                biblioteca->insert(l);

                // aumento 1 libro al sistema y 1 libro habilitado
                total_libros++;
                total_libros_habilitados++;
            }
        }
        else if ( comando == "FIND")
        {
            /**
             * Estructura del comando: FIND <ID del libro>
             */            
            cin >> id;

            // creo libro auxiliar a buscar
            Libro l(id, "", true);

            if ( biblioteca->contains(l) )
            {
                // si existe entonces imprimo el titulo y si esta habilitado (no esta del todo claro)
                Libro& x = biblioteca->get(l);
                //Libro x = biblioteca->get(l);
                cout << x;
            }
            else
            {
                // si no existe o esta deshabilitado
                cout << "libro_no_encontrado" << endl;
            }
        }
        else if ( comando == "TOGGLE")
        {
            /**
             * Estructura del comando: TOGGLE <ID del libro>
             */    
            cin >> id;

            // creo libro a buscar
            Libro l(id, "", true);

            if ( biblioteca->contains(l) )
            {
                Libro& x = biblioteca->get(l);
                
                if ( x.getEstado() )
                {
                    // si el libro esta habilitado lo deshabilito
                    x.setEstado(false);

                    // aumento 1 libro a deshabilitado y resto 1 libro a habilitado
                    total_libros_habilitados--;
                    total_libros_deshabilitados++;
                }
                else
                {
                    // si el libro esta deshabilito lo habilito
                    x.setEstado(true);

                    // aumento 1 libro a shabilitado y resto 1 libro a deshabilitado
                    total_libros_habilitados++;
                    total_libros_deshabilitados--;
                }
            }
            else
            {
                // si no existe
                cout << "libro_no_encontrado" << endl;
            }
        }
        else if ( comando == "COUNT")
        {
            /**
             * Estructura del comando: COUNT
             */ 
            cout << total_libros << " " << total_libros_habilitados << " " << total_libros_deshabilitados << endl;
        }
        else
        {
            cout << "El comando ingresado no es correcto." << endl;
        }
    }

    return 0;
}