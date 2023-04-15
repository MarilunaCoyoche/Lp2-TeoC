#include <iostream>
#include <cmath>

/*
Actividad para el Problema 1: Crear una clase "FiguraGeometrica" como clase base para todas las figuras geométricas. 
Luego, hacer que cada clase de figura geométrica sea una clase derivada de "FiguraGeometrica".
*/

using namespace std;

const double PI = 3.141592653589793238462643383279502884;

class FiguraGeometrica {
protected:
    double area;
    double perimetro;

public:
    virtual void calcularArea() = 0;
    virtual void calcularPerimetro() = 0;

    void mostrarResultados() {
        cout << "El area es: " << area << endl;
        cout << "El perimetro es: " << perimetro << endl;
    }
};

class Cuadrado : public FiguraGeometrica {
private:
    double lado;

public:
    Cuadrado(double lado) {
        this->lado = lado;
    }

    void calcularArea() {
        area = lado * lado;
    }

    void calcularPerimetro() {
        perimetro = 4 * lado;
    }
};

class Circulo : public FiguraGeometrica {
private:
    double radio;

public:
    Circulo(double radio) {
        this->radio = radio;
    }

    void calcularArea() {
        area = PI * pow(radio, 2);
    }

    void calcularPerimetro() {
        perimetro = 2 * PI * radio;
    }
};

class Triangulo : public FiguraGeometrica {
private:
    double base;
    double altura;

public:
    Triangulo(double base, double altura) {
        this->base = base;
        this->altura = altura;
    }

    void calcularArea() {
        area = (base * altura) / 2;
    }

    void calcularPerimetro() {
        perimetro = base + (2 * sqrt(pow(base / 2, 2) + pow(altura, 2)));
    }
};

int main() {
    int opcion;
    double lado, radio, base, altura;

    cout << "Seleccione la figura geometrica: \n";
    cout << "1. Cuadrado \n";
    cout << "2. Circulo \n";
    cout << "3. Triangulo \n";
    cout << "Opcion: ";
    cin >> opcion;

    FiguraGeometrica *figura;

    switch(opcion) {
        case 1:
            cout << "Ingrese la longitud del lado: ";
            cin >> lado;

            figura = new Cuadrado(lado);
            break;

        case 2:
            cout << "Ingrese el radio: ";
            cin >> radio;

            figura = new Circulo(radio);
            break;

        case 3:
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese la altura: ";
            cin >> altura;

            figura = new Triangulo(base, altura);
            break;

        default:
            cout << "Opcion invalida. Por favor seleccione una opcion valida." << endl;
            return 0;
    }

    figura->calcularArea();
    figura->calcularPerimetro();
    figura->mostrarResultados();

    delete figura;

    return 0;
}
