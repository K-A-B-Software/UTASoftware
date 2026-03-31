#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <vector>
using namespace std;
struct Estudiante {
    string nombre;
    char paralelo;
    float n1, n2, nPrac;
    float asistencia;
    float promedio;
    string categoria;
    string estadoFinal;
    bool estable;
    bool inestable;
    bool alertaInconsistencia;
};
float validarNota(string mensaje);
float validarAsistencia();
char validarParalelo();
int validarN();
void calcularResultados(Estudiante &e);
void mostrarReporte(const vector<Estudiante> &estudiantes);
#endif
