#include "Venta.h"
#include <iostream>
using namespace std;

Venta crearVenta() {
    Venta v;

    cout << "Ingrese cliente: ";
    cin.ignore();
    getline(cin, v.cliente);

    cout << "Ingrese fecha: ";
    getline(cin, v.fecha);

    cout << "Forma de pago: ";
    getline(cin, v.formaPago);

    return v;
}

void mostrarVenta(Venta v) {
    cout << "\n--- Venta ---" << endl;
    cout << "Cliente: " << v.cliente << endl;
    cout << "Fecha: " << v.fecha << endl;
    cout << "Pago: " << v.formaPago << endl;
}