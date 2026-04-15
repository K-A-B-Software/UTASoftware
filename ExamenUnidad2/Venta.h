#ifndef VENTA_H
#define VENTA_H

#include <string>
using namespace std;

class Venta {
public:
    string cliente;
    string fecha;
    string formaPago;
};

// Declaraciones
Venta crearVenta();
void mostrarVenta(Venta v);

#endif