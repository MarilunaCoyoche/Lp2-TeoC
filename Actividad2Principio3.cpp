#include <iostream>
#include <string>

/*
Actividad para el Problema 2: Crear una clase "Empleado" como clase base para 
todos los tipos de empleados (Ejecutivo, Gerente, etc.). 
Luego, hacer que cada tipo de empleado sea una clase derivada de "Empleado".
*/

using namespace std;

class Empleado {
protected:  // Atributos protegidos para que puedan ser accedidos por las clases derivadas
    string nombre;
    string apellido;
    string cargo;
    float salario;

public:
    // Constructor
    Empleado(string nombre, string apellido, string cargo, float salario) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->cargo = cargo;
        this->salario = salario;
    }

    // Métodos para acceder a los atributos
    string getNombre() {
        return nombre;
    }

    string getApellido() {
        return apellido;
    }

    string getCargo() {
        return cargo;
    }

    float getSalario() {
        return salario;
    }

    // Métodos para modificar los atributos
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setApellido(string apellido) {
        this->apellido = apellido;
    }

    void setCargo(string cargo) {
        this->cargo = cargo;
    }

    void setSalario(float salario) {
        this->salario = salario;
    }

    // Método virtual puro para calcular el salario
    virtual float calcularSalario() = 0;
};

// Clase derivada Ejecutivo
class Ejecutivo : public Empleado {
public:
    // Constructor
    Ejecutivo(string nombre, string apellido, string cargo, float salario) : Empleado(nombre, apellido, cargo, salario) {}

    // Implementación del método calcularSalario
    float calcularSalario() {
        // El salario del ejecutivo se calcula sumando un bono al salario base
        return salario + 1000;
    }
};

// Clase derivada Gerente
class Gerente : public Empleado {
public:
    // Constructor
    Gerente(string nombre, string apellido, string cargo, float salario) : Empleado(nombre, apellido, cargo, salario) {}

    // Implementación del método calcularSalario
    float calcularSalario() {
        // El salario del gerente se calcula sumando un bono al salario base
        return salario + 500;
    }
};

int main() {
    // Crear objetos de las clases derivadas
    Ejecutivo ejecutivo("Juansito", "Mamani", "Ejecutivo de ventas", 5000);
    Gerente gerente("Julio", "Agustino", "Gerente general de sistemas", 3500);

    // Acceder a los atributos
    cout << "Nombre: " << ejecutivo.getNombre() << endl;
    cout << "Apellido: " << ejecutivo.getApellido() << endl;
    cout << "Cargo: " << ejecutivo.getCargo() << endl;
    cout << "Salario: " << ejecutivo.getSalario() << endl;

    // Calcular el salario y mostrarlo
    cout << "Salario total: " << ejecutivo.calcularSalario() << endl;

    cout << endl;

    // Acceder a los atributos
    cout << "Nombre: " << gerente.getNombre() << endl;
    cout << "Apellido: " << gerente.getApellido() << endl;
    cout << "Cargo: " << gerente.getCargo() << endl;
    cout << "Salario: " << gerente.getSalario() << endl;

    // Calcular el salario y mostrarlo
    cout << "Salario total: " << gerente.calcularSalario() << endl;

    return 0; 
}
