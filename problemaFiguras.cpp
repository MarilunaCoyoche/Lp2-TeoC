#include <iostream>
#include <cmath>

/*
Problema 1: Implementar un programa que calcule el área y el perímetro de diferentes 
figuras geométricas, tales como círculos, triángulos y cuadrados.
*/

using namespace std;

const double PI = 3.141592653589793238462643383279502884;

int main() {
    int opcion;
    double lado, radio, base, altura;
    double area, perimetro;

    cout << "Seleccione la figura geometrica: \n";
    cout << "1. Cuadrado \n";
    cout << "2. Circulo \n";
    cout << "3. Triangulo \n";
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            cout << "Ingrese la longitud del lado: ";
            cin >> lado;

            area = lado * lado;
            perimetro = 4 * lado;

            break;

        case 2:
            cout << "Ingrese el radio: ";
            cin >> radio;

            area = PI * pow(radio, 2);
            perimetro = 2 * PI * radio;

            break;

        case 3:
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese la altura: ";
            cin >> altura;

            area = (base * altura) / 2;
            perimetro = base + (2 * sqrt(pow(base / 2, 2) + pow(altura, 2)));

            break;
    }

    cout << "El area es: " << area << endl;
    cout << "El perimetro es: " << perimetro << endl;

    return 0;
}
