#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
public:
    string codigo;
    string nombre;
    string categoria;
    int stock;
    double costo;
    double precio;
};

#endif