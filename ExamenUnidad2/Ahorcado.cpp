#include "Ahorcado.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

bool letraUsada(char letra, string usadas) {
    for (char c : usadas) {
        if (c == letra) return true;
    }
    return false;
}

void dibujarAhorcado(int intentos) {
    cout << "\n  +---+" << endl;
    cout << "  |   |" << endl;

    if (intentos <= 5) cout << "  O   |" << endl;
    else cout << "      |" << endl;

    if (intentos <= 3) cout << " /|\\  |" << endl;
    else if (intentos <= 4) cout << "  |   |" << endl;
    else cout << "      |" << endl;

    if (intentos <= 1) cout << " / \\  |" << endl;
    else cout << "      |" << endl;

    cout << "      |" << endl;
    cout << "=========" << endl;
}

void jugarAhorcado(vector<string> palabras) {
    if (palabras.empty()) {
        cout << "No hay palabras " << endl;
        return;
    }

    srand(time(0));
    string palabra = palabras[rand() % palabras.size()];
    string oculto = palabra;

    // ocultar letras
    for (int i = 0; i < oculto.length(); i++) {
        if (oculto[i] != ' ')
            oculto[i] = '_';
    }

    int intentos = palabra.length() / 2 + 3;
    string usadas = "";
    char letra;

    while (intentos > 0 && oculto != palabra) {
        cout << "\nPalabra: " << oculto << endl;
        cout << "Intentos: " << intentos << endl;
        cout << "Letras usadas: " << usadas << endl;

        cout << "Ingresa una letra: ";
        cin >> letra;
        letra = tolower(letra);

        if (letraUsada(letra, usadas)) {
            cout << "Ya usaste esa letra \n";
            continue;
        }

        usadas += letra;

        bool acierto = false;

        for (int i = 0; i < palabra.length(); i++) {
            if (tolower(palabra[i]) == letra) {
                oculto[i] = palabra[i];
                acierto = true;
            }
        }

        if (!acierto) {
            intentos--;
            cout << "Fallaste " << endl;
            dibujarAhorcado(intentos);
        } else {
            cout << "Bien " << endl;
        }
    }

    if (oculto == palabra) {
        cout << "\nGanaste  La palabra era: " << palabra << endl;
    } else {
        cout << "\nPerdiste  La palabra era: " << palabra << endl;
    }
}