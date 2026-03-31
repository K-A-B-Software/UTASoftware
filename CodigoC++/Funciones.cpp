#include "Estudiante.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
float validarNota(string mensaje) {
    float nota;
    do {
        cout << mensaje;
        cin >> nota;
        if (nota < 0 || nota > 10) cout << "Error: La nota debe estar entre 0 y 10.\n";
    } while (nota < 0 || nota > 10);
    return nota;
}
float validarAsistencia() {
    float asis;
    do {
        cout << "Ingrese asistencia (0-100): ";
        cin >> asis;
        if (asis < 0 || asis > 100) cout << "Error: Rango invalido.\n";
    } while (asis < 0 || asis > 100);
    return asis;
}
char validarParalelo() {
    char p;
    do {
        cout << "Ingrese paralelo (A, B o C): ";
        cin >> p;
        p = toupper(p);
    } while (p != 'A' && p != 'B' && p != 'C');
    return p;
}
int validarN() {
    int n;
    do {
        cout << "Ingrese cantidad de estudiantes (N > 0): ";
        cin >> n;
    } while (n <= 0);
    return n;
}
void calcularResultados(Estudiante &e) {
    e.promedio = (e.n1 * 0.30) + (e.n2 * 0.30) + (e.nPrac * 0.40);
    if (e.promedio >= 9) e.categoria = "Excelente";
    else if (e.promedio >= 8) e.categoria = "Muy bueno";
    else if (e.promedio >= 7) e.categoria = "Bueno";
    else if (e.promedio >= 6) e.categoria = "En riesgo";
    else e.categoria = "Reprobado";
    if (e.asistencia < 70) e.estadoFinal = "Reprobado por asistencia";
    else if (e.promedio < 6) e.estadoFinal = "Reprobado por nota";
    else e.estadoFinal = "Aprobado";
    e.alertaInconsistencia = (e.promedio >= 9 && e.asistencia < 80);
    e.estable = (e.n1 == e.n2 && e.n2 == e.nPrac);
    float notas[] = {e.n1, e.n2, e.nPrac};
    float maxN = *max_element(notas, notas + 3);
    float minN = *min_element(notas, notas + 3);
    e.inestable = (maxN - minN > 4);
}
void mostrarReporte(const vector<Estudiante> &estudiantes) {
    int total = estudiantes.size();
    int pA = 0, pB = 0, pC = 0;
    int catExc = 0, catMB = 0, catB = 0, catRisk = 0, catRep = 0;
    int repNota = 0, repAsis = 0, aprobados = 0;
    int estables = 0, inestables = 0;
    float sumaGen = 0, sA = 0, sB = 0, sC = 0;
    Estudiante mejor = estudiantes[0], peor = estudiantes[0];
    for (int i = 0; i < total; i++) {
    const Estudiante &e = estudiantes[i];
        sumaGen += e.promedio;
        if (e.paralelo == 'A') { pA++; sA += e.promedio; }
        if (e.paralelo == 'B') { pB++; sB += e.promedio; }
        if (e.paralelo == 'C') { pC++; sC += e.promedio; }
        if (e.categoria == "Excelente") catExc++;
        else if (e.categoria == "Muy bueno") catMB++;
        else if (e.categoria == "Bueno") catB++;
        else if (e.categoria == "En riesgo") catRisk++;
        else catRep++;
        if (e.estadoFinal == "Reprobado por nota") repNota++;
        else if (e.estadoFinal == "Reprobado por asistencia") repAsis++;
        else aprobados++;
        if (e.estable) estables++;
        if (e.inestable) inestables++;
        if (e.promedio > mejor.promedio) mejor = e;
        if (e.promedio < peor.promedio) peor = e;
    }
    cout << "\n--- REPORTE GENERAL ---\n";
    cout << "Total estudiantes: " << total << endl;
    cout << "Por paralelo: A: " << pA << " | B: " << pB << " | C: " << pC << endl;
    cout << "Categorias: Exc: " << catExc << ", MB: " << catMB << ", B: " << catB << ", Riesgo: " << catRisk << ", Rep: " << catRep << endl;
    cout << "Reprobados por nota: " << repNota << " | Por asistencia: " << repAsis << endl;
    cout << "Promedio General: " << (sumaGen / total) << endl;
    if(pA > 0) cout << "Promedio Paralelo A: " << (sA / pA) << endl;
    cout << "Mayor Promedio: " << mejor.promedio << " (" << mejor.nombre << ")\n";
    cout << "Menor Promedio: " << peor.promedio << " (" << peor.nombre << ")\n";
    cout << "Aprobados: " << (float)aprobados/total * 100 << "%\n";
    cout << "Rendimiento Estable: " << (float)estables/total * 100 << "%\n";
    cout << "Rendimiento Inestable: " << (float)inestables/total * 100 << "%\n";
}
