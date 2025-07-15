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

void inicializarSemestres();
void leerEstudiante(Estudiante &e);
void mostrarEstudiante(Estudiante &e);
void verEstudiantesCurso(string nombreCurso);

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

void inicializarSemestres() {
    
    semestres[0].numero = 1;
    semestres[0].cantidadCursos = 7;
    semestres[0].cursos[0].nombre = "Matematica";
    semestres[0].cursos[1].nombre = "Comunicacion y Redaccion";
    semestres[0].cursos[2].nombre = "Metodologia del Trabajo Universitario";
    semestres[0].cursos[3].nombre = "Fundamentos de Programacion";
    semestres[0].cursos[4].nombre = "Quimica";
    semestres[0].cursos[5].nombre = "Matematica Discreta I";
    semestres[0].cursos[6].nombre = "Programacion Grafica";
   
    semestres[1].numero = 2;
    semestres[1].cantidadCursos = 7;
    semestres[1].cursos[0].nombre = "Ecologia y Ambiente";
    semestres[1].cursos[1].nombre = "Realidad Nacional e Internacional";
    semestres[1].cursos[2].nombre = "Filosofia, Etica y Sociedad";
    semestres[1].cursos[3].nombre = "Matematica I";
    semestres[1].cursos[4].nombre = "Fisica I";
    semestres[1].cursos[5].nombre = "Matematica Discreta II";
    semestres[1].cursos[6].nombre = "Programacion Avanzada";

    semestres[2].numero = 3;
    semestres[2].cantidadCursos = 6;
    semestres[2].cursos[0].nombre = "Teoria General de los Sistemas";
    semestres[2].cursos[1].nombre = "Sistemas Electricos y Electronicos";
    semestres[2].cursos[2].nombre = "Estructura de Datos";
    semestres[2].cursos[3].nombre = "Algoritmos y Programacion Paralela";
    semestres[2].cursos[4].nombre = "Matematica II";
    semestres[2].cursos[5].nombre = "Estadistica y Probabilidades";

    semestres[3].numero = 4;
    semestres[3].cantidadCursos = 6;
    semestres[3].cursos[0].nombre = "Analisis de Sistemas";
    semestres[3].cursos[1].nombre = "Sistemas Digitales";
    semestres[3].cursos[2].nombre = "Modelado Computacional para Ingenieria";
    semestres[3].cursos[3].nombre = "Contabilidad, Costos y Presupuestos";
    semestres[3].cursos[4].nombre = "Matematica III";
    semestres[3].cursos[5].nombre = "Ingenieria Economica";

    semestres[4].numero = 5;
    semestres[4].cantidadCursos = 5;
    semestres[4].cursos[0].nombre = "Diseno de Sistemas";
    semestres[4].cursos[1].nombre = "Arquitectura de Computadores";
    semestres[4].cursos[2].nombre = "Compiladores y Teoria de Lenguajes";
    semestres[4].cursos[3].nombre = "Base de Datos I";
    semestres[4].cursos[4].nombre = "Investigacion Operativa I";

    semestres[5].numero = 6;
    semestres[5].cantidadCursos = 6;
    semestres[5].cursos[0].nombre = "Ingenieria de Software I";
    semestres[5].cursos[1].nombre = "Redes I";
    semestres[5].cursos[2].nombre = "Sistemas Operativos";
    semestres[5].cursos[3].nombre = "Base de Datos II";
    semestres[5].cursos[4].nombre = "Investigacion Operativa II";
    semestres[5].cursos[5].nombre = "Legislacion Industrial e Informatica";

    semestres[6].numero = 7;
    semestres[6].cantidadCursos = 6;
    semestres[6].cursos[0].nombre = "Ingenieria de Software II";
    semestres[6].cursos[1].nombre = "Redes II";
    semestres[6].cursos[2].nombre = "Sistemas de Informacion";
    semestres[6].cursos[3].nombre = "Analitica de Datos";
    semestres[6].cursos[4].nombre = "Dinamica de Sistemas";
    semestres[6].cursos[5].nombre = "Proyectos de TI";

    semestres[7].numero = 8;
    semestres[7].cantidadCursos = 6;
    semestres[7].cursos[0].nombre = "Ingenieria Web y Aplicaciones Moviles";
    semestres[7].cursos[1].nombre = "Taller de Emprendimiento e Innovacion";
    semestres[7].cursos[2].nombre = "Simulacion de Sistemas";
    semestres[7].cursos[3].nombre = "Realidad Virtual";
    semestres[7].cursos[4].nombre = "Seguridad Informatica";
    semestres[7].cursos[5].nombre = "Electivo I";

    semestres[8].numero = 9;
    semestres[8].cantidadCursos = 6;
    semestres[8].cursos[0].nombre = "Taller de Tesis I";
    semestres[8].cursos[1].nombre = "Inteligencia Artificial";
    semestres[8].cursos[2].nombre = "Gestion de Tecnologias de la Informacion";
    semestres[8].cursos[3].nombre = "Sistemas Expertos";
    semestres[8].cursos[4].nombre = "Metodos Cuantitativos para Investigacion";
    semestres[8].cursos[5].nombre = "Electivo II";

    semestres[9].numero = 10;
    semestres[9].cantidadCursos = 6;
    semestres[9].cursos[0].nombre = "Taller de Tesis II";
    semestres[9].cursos[1].nombre = "Practicas Pre Profesionales";
    semestres[9].cursos[2].nombre = "Robotica";
    semestres[9].cursos[3].nombre = "Auditoria de Sistemas";
    semestres[9].cursos[4].nombre = "Procesamiento de Imagenes";
    semestres[9].cursos[5].nombre = "Electivo III";
}

void leerEstudiante(Estudiante &e) {
    cin.ignore();
    cout << "Nombre: "; getline(cin, e.nombre);
    cout << "Codigo: "; cin >> e.codigo; 	
    cout << "Edad: "; cin >> e.edad;
    cout << "Sexo (M/F): "; cin >> e.sexo;
    cout << "Semestre (1-10): "; cin >> e.semestre;
    
    system ("cls");

    int idxSem = e.semestre - 1;
    e.promedioPonderado = 0;
    for(int i=0; i<semestres[idxSem].cantidadCursos; i++) {
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
    for(int i=0; i<nEst; i++) {
        for(int j=0; j<10; j++) {
            if(listaEstudiantes[i].notas[j].nombreCurso == nombreCurso) {
                cout << "- " << listaEstudiantes[i].nombre << " | Nota: " << listaEstudiantes[i].notas[j].nota << endl;
            }
        }
    }
}