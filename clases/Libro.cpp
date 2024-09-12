#include <iostream>
using namespace std;

/**
 * Clase Libro para Ejercicio 1 con AVL
 */
class Libro
{
    private:
        int id;         // numero de identificacion unico
        string titulo;  // titulo
        bool estado;    // true (H), false (D)
        
    public:
        // Constructor
        Libro(int unId, string unTitulo, bool unEstado) { id = unId; titulo = unTitulo; estado = unEstado; }

        // Seters
        void setTitulo(string unTitulo) { titulo = unTitulo; }
        void setEstado(bool unEstado) { estado = unEstado; }
        
        // Geters
        int getId() { return id; }
        string getTitulo() { return titulo; }
        bool getEstado() { return estado; }

        void printTitulo() { cout << titulo << "X" << estado << endl; }
    
        friend ostream& operator<<(ostream& os, Libro const & l) {
            if (l.estado)
            {
                return os << l.titulo << " " << "H" << endl;
            }
            else
            {
                return os << l.titulo << " " << "D" << endl;
            }
        }
};
