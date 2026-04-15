#include <iostream>
#include <vector>
#include <cctype>
#include "Producto.h"
#include "Venta.h"
#include "Ahorcado.h"

using namespace std;

bool esNumero(string texto){
    for (char c : texto) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool esDecimal(string texto) {
    int puntos = 0;

    for (char c : texto) {
        if (c == '.') {
            puntos++;
        } else if (!isdigit(c)) {
            return false;
        }
    }

    return puntos <= 1;
}

bool codigoExiste(vector<Producto> productos, string codigo) {
    for (auto p : productos) {
        if (p.codigo == codigo) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<Producto> productos;
    vector<Venta> ventas;
    vector<string> palabrasProductos;
    vector<string> palabrasClientes;

    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Registrar venta" << endl;
        cout << "3. Mostrar productos" << endl;
        cout << "4. Mostrar ventas" << endl;
        cout << "5. Jugar ahorcado" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
    Producto p;

    string codigo;
    do {
        cout << "Codigo (solo numeros): ";
        cin >> codigo;

        if (!esNumero(codigo)) {
            cout << "Error: solo numeros \n";
        } else if (codigoExiste(productos, codigo)) {
            cout << "Error: ese codigo ya existe \n";
        }

    } while (!esNumero(codigo) || codigoExiste(productos, codigo));

    p.codigo = codigo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, p.nombre);

    cout << "Categoria: ";
    getline(cin, p.categoria);

    string stockStr;
    do {
        cout << "Stock: ";
        cin >> stockStr;

        if (!esNumero(stockStr)) {
            cout << "Error: solo numeros enteros \n";
        }

    } while (!esNumero(stockStr));

    p.stock = stoi(stockStr);

    string costoStr;
    do {
        cout << "Costo: ";
        cin >> costoStr;

        if (!esDecimal(costoStr)) {
            cout << "Error: solo numeros \n";
        }

    } while (!esDecimal(costoStr));

    p.costo = stod(costoStr);

    string precioStr;
    do {
        cout << "Precio: ";
        cin >> precioStr;

        if (!esDecimal(precioStr)) {
            cout << "Error: solo numeros \n";
        }

    } while (!esDecimal(precioStr));

    p.precio = stod(precioStr);

    productos.push_back(p);
    palabrasProductos.push_back(p.nombre);

    cout << "Producto registrado " << endl;
    break;
}

        case 2: {
            Venta v = crearVenta();
            ventas.push_back(v);
            palabrasClientes.push_back(v.cliente);

            cout << "Venta registrada " << endl;
            break;
        }

        case 3: {
            for (auto p : productos) {
                cout << p.nombre << " - $" << p.precio << endl;
            }
            break;
        }

        case 4: {
            for (auto v : ventas) {
                mostrarVenta(v);
            }
            break;
        }

        case 5: {
            int tipo;
            cout << "\n--- AHORCADO ---" << endl;
            cout << "1. Con productos" << endl;
            cout << "2. Con clientes" << endl;
            cout << "Opcion: ";
            cin >> tipo;

            if (tipo == 1) {
                jugarAhorcado(palabrasProductos);
            } else if (tipo == 2) {
                jugarAhorcado(palabrasClientes);
            } else {
                cout << "Opcion invalida " << endl;
            }

            break;
        }

        case 0:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 0);

    return 0;
}