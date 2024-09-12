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
        void setEstado(bool unEstado) {
            cout << "ACTUALIZO EL ESTADO A: " << unEstado << endl;
            estado = unEstado;
        }
        
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
    
        friend ostream& operator<<(ostream& os, Libro const & l) {
            if (l.estado)
            {
                cout << "ESTADO: " << l.estado << endl;
                return os << l.titulo << " " << "H" << endl;
            }
            else
            {
                cout << "PASO POR ACA 2" << endl;
                return os << l.titulo << " " << "D" << endl;
            }
        }
};
