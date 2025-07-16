#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

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

extern Estudiante listaEstudiantes[100];
extern int nEst;

void leerEstudiante(Estudiante &e);
void mostrarEstudiante(Estudiante &e);
void verEstudiantesCurso(string nombreCurso);
void editarEstudiante(Estudiante &e);
void limpiarEntrada();
void eliminarEstudiante(int posicion);


#endif
