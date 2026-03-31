#include <iostream>
#include <string>

using namespace std;

class Jean {
private:
    string codigo;
    string color;
    string talla;
    bool fueTenido;
    int cantTenidos;
    double precio;
    int cantBotones;
    double humedad;
    string estadoTela;

public:
    // Función para capturar datos
    void registrar() {
        cout << "Codigo: "; cin >> codigo;
        cout << "Color: "; cin >> color;
        cout << "Talla: "; cin >> talla;
        cout << "Tenido? (1:Si / 0:No): "; cin >> fueTenido;
        cantTenidos = (fueTenido) ? (cout << "Cant. Tenidos: ", cin >> cantTenidos, cantTenidos) : 0;
        cout << "Precio: "; cin >> precio;
        cout << "Humedad (0-100): "; cin >> humedad;
        cout << "Estado tela: "; cin >> estadoTela;
    }

    // Función Lavar
    void lavar() {
        cout << "\n[Accion: Lavando]" << endl;
        if (fueTenido && cantTenidos > 0) {
            cantTenidos--;
        }
        humedad = 100.0;
    }

    // Función Secar
    void secar() {
        cout << "[Accion: Secando]" << endl;
        humedad = 0.0;
    }

    // Función MostrarDatos
    void mostrarDatos() {
        cout << "\n======= REPORTE DE LA CLASE JEAN =======" << endl;
        cout << "ID: " << codigo << " | Color: " << color << endl;
        cout << "Talla: " << talla << " | Estado: " << estadoTela << endl;
        cout << "Tenidos: " << cantTenidos << " | Humedad: " << humedad << "%" << endl;
        cout << "Precio Final: $" << precio << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    Jean objetoJean; // Instancia de la clase

    cout << "--- ENTRADA DE DATOS ---" << endl;
    objetoJean.registrar();

    // Uso de las funciones solicitadas
    objetoJean.lavar();
    objetoJean.secar();
    objetoJean.mostrarDatos();

    return 0;
}
