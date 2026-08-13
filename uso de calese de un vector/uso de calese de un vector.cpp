// uso de calese de un vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Definimos el struct Producto
struct Producto {
    string nombre;
    float precio;
};

int main() {

    // Crear el vector de productos
    vector<Producto> inventario;

    // Agregar productos usando push_back()
    inventario.push_back({ "Arroz", 65.50 });
    inventario.push_back({ "Leche", 80.00 });
    inventario.push_back({ "Pan", 45.00 });
    inventario.push_back({ "Huevos", 120.00 });

    // Recorrer el inventario e imprimir los productos
    cout << "=== INVENTARIO ===" << endl;

    for (Producto p : inventario) {
        cout << "Producto: " << p.nombre
            << " | Precio: RD$ " << p.precio << endl;
    }

    // Modificar el precio de un producto mediante índice
    inventario[1].precio = 85.00;

    cout << "\n=== INVENTARIO ACTUALIZADO ===" << endl;

    for (Producto p : inventario) {
        cout << "Producto: " << p.nombre
            << " | Precio: RD$ " << p.precio << endl;
    }

    // Calcular el precio promedio
    float suma = 0;

    for (Producto p : inventario) {
        suma += p.precio;
    }

    float promedio = suma / inventario.size();

    cout << "\nPrecio promedio: RD$ "
        << fixed << setprecision(2) << promedio << endl;

    // Acceder de forma segura usando at()
    cout << "\n=== ACCESO SEGURO CON at() ===" << endl;

    try {
        Producto producto = inventario.at(2);

        cout << "Producto en la posicion 2: "
            << producto.nombre
            << " | Precio: RD$ "
            << producto.precio << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: posicion fuera del rango." << endl;
    }

    return 0;
}


