#include <iostream>
using namespace std;

/**
 * Clase Libro para Ejercicio 1 con AVL
 */
class Libro
{
    private:
        int id;         // Numero de identificacion unico
        string titulo;  // titulo
        bool estado;    // true (habilitado), false (deshabilitado)
        
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

        void printLibro() {
            cout << "ID: " << id << endl;
            cout << "Titulo: " << titulo << endl;
            cout << "Estado: " << estado << endl;
        }

        void printTitulo() { cout << titulo << endl; }
    
        friend ostream& operator<<(ostream& os, Libro const & libro) {
            return os << "Id:" << libro.id << " Titulo:" << libro.titulo << " Estado:" << libro.estado << endl;
        }
};
