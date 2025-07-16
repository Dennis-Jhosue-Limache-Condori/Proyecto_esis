#ifndef SEMESTRE_H
#define SEMESTRE_H

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

extern Semestre semestres[10];

void inicializarSemestres();

#endif
