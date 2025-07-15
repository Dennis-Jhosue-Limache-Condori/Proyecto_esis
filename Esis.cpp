#include <iostream>
#include <string>
using namespace std;

struct Curso {
    string nombre;
};
struct Semestre {
    int numero;
    int cantidadCursos;
    Curso cursos[10];
};
struct NotaCurso {
    string nombreCurso;
    float nota;
};
struct Estudiante {
    string nombre;
    int codigo;
    int edad;
    char sexo;
    int semestre;
    NotaCurso notas[10];
    float promedioPonderado;
};

Estudiante listaEstudiantes[100];
int nEst = 0;
Semestre semestres[10];

int main() {
    int op;
    do {
        system("cls");
        cout << "Menu Principal\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Semestres\n";
        cout << "0. Salir\n";
        cout << "Elija una opcion: ";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Funcion Agregar Estudiante (no implementada aun)\n";
                system("pause");
                break;
            case 2:
                cout << "Funcion Ver Semestres (no implementada aun)\n";
                system("pause");
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                system("pause");
        }
    } while(op != 0);
    return 0;
}
