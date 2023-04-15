#include <iostream>
#include <string>

/*
Problema 2: Implementar un programa que permita agregar, eliminar y consultar empleados 
en una empresa, utilizando clases y interfaces adecuadas para implementar los principios SOLID.
*/

using namespace std;


class Empleado {            // Definición de la clase Empleado
private:
  string nombre;            // Atributos
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
};

int main() {
  // Crear un objeto de la clase Empleado
  Empleado empleado("Juan", "Pérez", "Gerente de ventas", 5000);
  
  // Acceder a los atributos
  cout << "Nombre: " << empleado.getNombre() << endl;
  cout << "Apellido: " << empleado.getApellido() << endl;
  cout << "Cargo: " << empleado.getCargo() << endl;
  cout << "Salario: " << empleado.getSalario() << endl;
  
  // Modificar los atributos
  empleado.setNombre("Pedro");
  empleado.setApellido("Gómez");
  empleado.setCargo("Analista de sistemas");
  empleado.setSalario(3500);
  
  // Acceder a los atributos modificados
  cout << "Nombre: " << empleado.getNombre() << endl;
  cout << "Apellido: " << empleado.getApellido() << endl;
  cout << "Cargo: " << empleado.getCargo() << endl;
  cout << "Salario: " << empleado.getSalario() << endl;
  
  return 0;
}
