#include <iostream>
#include "estudiante.h"
#include "semestre.h"

using namespace std;

Estudiante listaEstudiantes[100];
int nEst = 0;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void leerEstudiante(Estudiante &e) {
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, e.nombre);
    do {
        cout << "Codigo: ";
        cin >> e.codigo;
        if (cin.fail()) {
            limpiarEntrada();
            cout << "Codigo invalido. Intente nuevamente.\n";
        }
    } while (cin.fail());

    do {
        cout << "Edad (15-100): ";
        cin >> e.edad;
        if (cin.fail() || e.edad < 15 || e.edad > 100) {
            limpiarEntrada();
            cout << "Edad invalida. Ingrese un valor entre 15 y 100.\n";
        }
    } while (cin.fail() || e.edad < 15 || e.edad > 100);

    do {
        cout << "Sexo (M/F): ";
        cin >> e.sexo;
        if (cin.fail() || (e.sexo != 'M' && e.sexo != 'F' && e.sexo != 'm' && e.sexo != 'f')) {
            limpiarEntrada();
            cout << "Sexo invalido. Ingrese M o F.\n";
        }
    } while (cin.fail() || (e.sexo != 'M' && e.sexo != 'F' && e.sexo != 'm' && e.sexo != 'f'));

    do {
        cout << "Semestre (1-10): ";
        cin >> e.semestre;
        if (cin.fail() || e.semestre < 1 || e.semestre > 10) {
            limpiarEntrada();
            cout << "Semestre invalido. Ingrese un valor entre 1 y 10.\n";
        }
    } while (cin.fail() || e.semestre < 1 || e.semestre > 10);

    system("cls");
    int idxSem = e.semestre - 1;
    e.promedioPonderado = 0;

    for (int i = 0; i < semestres[idxSem].cantidadCursos; i++) {
        e.notas[i].nombreCurso = semestres[idxSem].cursos[i].nombre;
        float nota;
        do {
            cout << "- Nota en " << e.notas[i].nombreCurso << ": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 20) {
                limpiarEntrada();
                cout << "Nota invalida. Ingrese un valor entre 0 y 20.\n";
            }
        } while (cin.fail() || nota < 0 || nota > 20);
        e.notas[i].nota = nota;
        e.promedioPonderado = e.promedioPonderado + e.notas[i].nota;
    }
    e.promedioPonderado = e.promedioPonderado / semestres[idxSem].cantidadCursos;
}

void mostrarEstudiante(Estudiante &e) {
    cout << "Nombre: " << e.nombre << endl;
    cout << "Codigo: " << e.codigo << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Sexo: " << e.sexo << endl;
    cout << "Semestre: " << e.semestre << endl;
    cout << "Promedio: " << e.promedioPonderado << endl;
}

void verEstudiantesCurso(string nombreCurso) {
    for(int i = 0; i < nEst; i++) {
        for(int j = 0; j < 10; j++) {
            if(listaEstudiantes[i].notas[j].nombreCurso == nombreCurso) {
                cout << "- " << listaEstudiantes[i].nombre << " | Nota: " << listaEstudiantes[i].notas[j].nota << endl;
            }
        }
    }
}

void editarEstudiante(Estudiante &e) {
    cin.ignore();
    cout << "Editar estudiante:\n";
    cout << "Nombre actual: " << e.nombre << "\nNuevo nombre: ";
    getline(cin, e.nombre);

    do {
        cout << "Codigo actual: " << e.codigo << "\nNuevo codigo: ";
        cin >> e.codigo;
        if (cin.fail()) {
            limpiarEntrada();
            cout << "Codigo invalido. Intente nuevamente.\n";
        }
    } while (cin.fail());

    do {
        cout << "Edad actual: " << e.edad << "\nNueva edad (15-100): ";
        cin >> e.edad;
        if (cin.fail() || e.edad < 15 || e.edad > 100) {
            limpiarEntrada();
            cout << "Edad invalida. Ingrese un valor entre 15 y 100.\n";
        }
    } while (cin.fail() || e.edad < 15 || e.edad > 100);

    do {
        cout << "Sexo actual: " << e.sexo << "\nNuevo sexo (M/F): ";
        cin >> e.sexo;
        if (cin.fail() || (e.sexo != 'M' && e.sexo != 'F' && e.sexo != 'm' && e.sexo != 'f')) {
            limpiarEntrada();
            cout << "Sexo invalido. Ingrese M o F.\n";
        }
    } while (cin.fail() || (e.sexo != 'M' && e.sexo != 'F' && e.sexo != 'm' && e.sexo != 'f'));

    do {
        cout << "Semestre actual: " << e.semestre << "\nNuevo semestre (1-10): ";
        cin >> e.semestre;
        if (cin.fail() || e.semestre < 1 || e.semestre > 10) {
            limpiarEntrada();
            cout << "Semestre invalido. Ingrese un valor entre 1 y 10.\n";
        }
    } while (cin.fail() || e.semestre < 1 || e.semestre > 10);

    int idxSem = e.semestre - 1;
    e.promedioPonderado = 0;
    cout << "Ingrese notas para los cursos del nuevo semestre:\n";

    for (int i = 0; i < semestres[idxSem].cantidadCursos; i++) {
        e.notas[i].nombreCurso = semestres[idxSem].cursos[i].nombre;
        float nota;
        do {
            cout << "- Nota en " << e.notas[i].nombreCurso << ": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 20) {
                limpiarEntrada();
                cout << "Nota invalida. Ingrese un valor entre 0 y 20.\n";
            }
        } while (cin.fail() || nota < 0 || nota > 20);
        e.notas[i].nota = nota;
        e.promedioPonderado = e.promedioPonderado + e.notas[i].nota;
    }
    e.promedioPonderado = e.promedioPonderado / semestres[idxSem].cantidadCursos;
}

void eliminarEstudiante(int posicion) {
    for (int i = posicion; i < nEst - 1; i++) {
        listaEstudiantes[i] = listaEstudiantes[i + 1];
    }
    nEst--;
}