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
    int N;
    string comando;
    int id;
    string titulo;

    AVL<Libro>* biblioteca = new AVL<Libro>(comparacionLibroPorId);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> comando;

        if ( comando == "ADD" )
        {
            //cout << "## ADD" << endl;
            
            cin >> id;
            cin >> titulo;

            Libro temp(id, titulo, true);

            //cout << temp << endl;

            if (!biblioteca->contains(temp))
            {
                // si no existe el libro en la biblioteca lo inserto
                biblioteca->insert(temp);
            }
            else
            {
                // si el libro existe lo traigo y le actualizo el titulo
                Libro l = biblioteca->get(&temp);
                l.setTitulo(temp.getTitulo());
            }
        }
        else if ( comando == "FIND")
        {
            //cout << "## FIND" << endl;
            
            cin >> id;

            Libro temp(id, "", true);
            if (biblioteca->contains(temp))
            {
                cout << biblioteca->get(&temp);
            }
            else
            {
                cout << "libro_no_encontrado" << endl;
            }
        }
        else if ( comando == "TOGGLE")
        {
            //cout << "## TOGGLE" << endl;

            cin >> id;

            Libro temp(id, "", true);
            if (biblioteca->contains(temp))
            {
                if (biblioteca->get(&temp).getEstado())
                {
                    biblioteca->get(&temp).setEstado(false);
                }
                else
                {
                    biblioteca->get(&temp).setEstado(true);
                }
            }
            else
            {
                // si no existe el libro
                cout << "libro_no_encontrado" << endl;
            }
        }
        else if ( comando == "COUNT")
        {
            cout << "## COUNT" << endl;
        }
        else
        {
            cout << "El comando ingresado no es correcto." << endl;
        }
    }

    // Imprimir Biblioteca
    cout << endl;
    cout << "BIBLIOTECA:" << endl;
    biblioteca->imprimir();

    return 0;
}