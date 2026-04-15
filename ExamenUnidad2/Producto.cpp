#include "Producto.h"
#include <iostream>
using namespace std;

void mostrarProducto(Producto p) {
    cout << p.nombre << " - $" << p.precio << endl;
}