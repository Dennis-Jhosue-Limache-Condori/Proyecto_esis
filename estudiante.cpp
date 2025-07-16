#include <iostream>
#include "estudiante.h"
#include "semestre.h"

using namespace std;

Estudiante listaEstudiantes[100];
int nEst = 0;

void leerEstudiante(Estudiante &e) {
    cin.ignore();
    cout << "Nombre: "; getline(cin, e.nombre);
    cout << "Codigo: "; cin >> e.codigo; 	
    cout << "Edad: "; cin >> e.edad;
    cout << "Sexo (M/F): "; cin >> e.sexo;
    cout << "Semestre (1-10): "; cin >> e.semestre;

    system("cls");

    int idxSem = e.semestre - 1;
    e.promedioPonderado = 0;
    for(int i = 0; i < semestres[idxSem].cantidadCursos; i++) {
        e.notas[i].nombreCurso = semestres[idxSem].cursos[i].nombre;
        cout << "Nota en " << e.notas[i].nombreCurso << ": ";
        cin >> e.notas[i].nota;
    }
}

void mostrarEstudiante(Estudiante &e) {
    cout << "Nombre: " << e.nombre << endl;
    cout << "Codigo: " << e.codigo << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Sexo: " << e.sexo << endl;
    cout << "Semestre: " << e.semestre << endl;
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
