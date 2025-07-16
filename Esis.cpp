#include <iostream>
#include "estudiante.h"
#include "semestre.h"
using namespace std;

int main() {
    int op;
    inicializarSemestres();

    do {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Editar estudiante\n";
        cout << "3. Eliminar estudiante\n";
        cout << "4. Semestres\n";
        cout << "5. Estudiantes registrados\n";
        cout << "0. Salir\n";
        cout << "Elija una opcion: ";
        cin >> op;
        if (cin.fail()) {
            limpiarEntrada();
            cout << "Entrada invalida. Presione una tecla...\n";
            system("pause");
            continue;
        }
        system("cls");
        switch(op) {
            case 1:
                leerEstudiante(listaEstudiantes[nEst]);
                nEst++;
                system("pause");
                break;
            
            case 2:
                if (nEst == 0) {
                    cout << "No hay estudiantes registrados.\n";
                    system("pause");
                break;
                }
                cout << "Lista de estudiantes:\n";
                for (int i = 0; i < nEst; i++) {
                    cout << i + 1 << ". " << listaEstudiantes[i].nombre << " (Codigo: " << listaEstudiantes[i].codigo << ")\n";
                }
                int idx;
                
                cout << "Seleccione el numero del estudiante a editar: ";
                cin >> idx;
                if (cin.fail() || idx < 1 || idx > nEst) {
                    limpiarEntrada();
                    cout << "Indice invalido.\n";
                    system("pause");
                    break;
                }
                editarEstudiante(listaEstudiantes[idx - 1]);
                cout << "Estudiante actualizado.\n";
                system("pause");
                break;
                
            case 3:
                if (nEst == 0) {
                    cout << "No hay estudiantes para eliminar.\n";
                    system("pause");
                    break;
                }
                cout << "Lista de estudiantes:\n";
                for (int i = 0; i < nEst; i++) {
                    cout << i + 1 << ". " << listaEstudiantes[i].nombre << " (Codigo: " << listaEstudiantes[i].codigo << ")\n";
                }
                int delIdx;
                cout << "Seleccione el numero del estudiante a eliminar: ";
                cin >> delIdx;
                if (cin.fail() || delIdx < 1 || delIdx > nEst) {
                    limpiarEntrada();
                    cout << "Indice invalido.\n";
                    system("pause");
                    break;
                }
                eliminarEstudiante(delIdx - 1);
                cout << "Estudiante eliminado correctamente.\n";
                system("pause");
                break;
                
            case 4: {
                int semOp;
                do {
                    system("cls");
                    cout << "SELECCIONAR SEMESTRE\n";
                    for(int i = 0; i < 10; i++) {
                        cout << i+1 << ". Semestre " << semestres[i].numero << endl;
                    }
                    cout << "0. Volver\nElija una opcion: ";
                    cin >> semOp;
                    cin >> semOp;
        
                    if (semOp >= 1 && semOp <= 10) {
                        Semestre sem = semestres[semOp - 1];

                        int opC;
                        do {
                            system("cls");
                            cout << "Cursos del semestre " << sem.numero << ":\n";
                            for(int i = 0; i < sem.cantidadCursos; i++) {
                                cout << i+1 << ". " << sem.cursos[i].nombre << endl;
                            }
                            cout << "0. Volver\nElija una opcion: ";
                            cin >> opC;

                            if (cin.fail() || opC < 0 || opC > sem.cantidadCursos) {
                                limpiarEntrada();
                                cout << "Opcion invalida. Intente nuevamente.\n";
                                system("pause");
                                continue;
                            }

                            if(opC >= 1 && opC <= sem.cantidadCursos) {
                                int subOp;
                                do {
                                    system("cls");
                                    cout << "Curso: " << sem.cursos[opC-1].nombre << endl;
                                    cout << "1. Ver estudiantes y notas\n2. Volver\nElija: ";
                                    cin >> subOp;
                                    if (cin.fail() || subOp < 1 || subOp > 2) {
                                        limpiarEntrada(); 
                                        cout << "Opcion invalida. Intente nuevamente.\n";
                                        system("pause");
                                        continue;
                                    }
                                    if(subOp == 1) {
                                        verEstudiantesCurso(sem.cursos[opC-1].nombre);
                                        system("pause");
                                    }
                                } while(subOp != 2);
                            }

                        } while(opC != 0);
                    }
                } while(semOp != 0);
                break;
            }

            case 5:
                if (nEst == 0) {
                    cout << "No hay estudiantes registrados.\n";
                    system("pause");
                break;
                }
                for (int i = 0; i < nEst; i++) {
                    cout << "Estudiante #" << i + 1 << ":\n";
                    mostrarEstudiante(listaEstudiantes[i]);
                    cout << "-----------------------------\n";
                }
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