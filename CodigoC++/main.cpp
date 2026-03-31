#include <iostream>
#include <vector>
#include "Estudiante.h"
using namespace std;
int main() {
    char continuar;
    do {
        int n = validarN();
        vector<Estudiante> lista(n);
        for (int i = 0; i < n; i++) {
            cout << "\n--- Estudiante " << i + 1 << " ---\n";
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, lista[i].nombre);
            lista[i].paralelo = validarParalelo();
            lista[i].n1 = validarNota("Nota Parcial 1: ");
            lista[i].n2 = validarNota("Nota Parcial 2: ");
            lista[i].nPrac = validarNota("Nota Practicas: ");
            lista[i].asistencia = validarAsistencia();
            calcularResultados(lista[i]);
            if(lista[i].alertaInconsistencia) {
                cout << "!!! ALERTA ACADEMICA: Inconsistencia detectada (Promedio alto / Asistencia baja)\n";
            }
        }
        mostrarReporte(lista);
        cout << "\n¿Desea procesar otro curso? (S/N): ";
        cin >> continuar;
    } while (toupper(continuar) == 'S');
    return 0;
}
