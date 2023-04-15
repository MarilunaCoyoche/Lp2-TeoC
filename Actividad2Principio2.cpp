#include <iostream>
#include <string>
#include <vector>

/*
Actividad para el Problema 2: Crear una interfaz "IGestionEmpleado" que tenga métodos 
para agregar, eliminar y consultar empleados. Luego, hacer que la clase "Empleado" implemente esta interfaz.
*/

// Interfaz para la gestión de empleados
class GestionEmpleado {
public:
    virtual void agregarEmpleado(const std::string& nombre, int edad, const std::string& cargo) = 0;
    virtual void eliminarEmpleado(int id) = 0;
    virtual void consultarEmpleado(int id) = 0;
};

// Clase para representar a un empleado
class Empleado : public GestionEmpleado {
public:
    // Constructor
    Empleado(const std::string& nombre, int edad, const std::string& cargo) :
        m_nombre(nombre), m_edad(edad), m_cargo(cargo) {}

    // Métodos de la interfaz GestionEmpleado
    void agregarEmpleado(const std::string& nombre, int edad, const std::string& cargo) override {
        // No hace nada, ya que la clase Empleado representa a un único empleado
    }

    void eliminarEmpleado(int id) override {
        // No hace nada, ya que la clase Empleado representa a un único empleado
    }

    void consultarEmpleado(int id) override {
        // Imprime los datos del empleado
        std::cout << "Empleado #" << id << ":" << std::endl;
        std::cout << "Nombre: " << m_nombre << std::endl;
        std::cout << "Edad: " << m_edad << std::endl;
        std::cout << "Cargo: " << m_cargo << std::endl;
    }

private:
    std::string m_nombre;
    int m_edad;
    std::string m_cargo;
};

// Función para mostrar un menú de opciones
void mostrarMenu() {
    std::cout << "1. Agregar empleado" << std::endl;
    std::cout << "2. Eliminar empleado" << std::endl;
    std::cout << "3. Consultar empleado" << std::endl;
    std::cout << "4. Salir" << std::endl;
}

int main() {
    std::vector<Empleado> empleados;
    int opcion = 0;

    while (opcion != 4) {
        mostrarMenu();
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, cargo;
                int edad;
                std::cout << "Ingrese el nombre del empleado: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del empleado: ";
                std::cin >> edad;
                std::cout << "Ingrese el cargo del empleado: ";
                std::cin >> cargo;
                Empleado nuevoEmpleado(nombre, edad, cargo);
                empleados.push_back(nuevoEmpleado);
                std::cout << "Empleado agregado con éxito." << std::endl;
                break;
            }
            case 2: {
                int id;
                std::cout << "Ingrese el ID del empleado a eliminar: ";
                std::cin >> id;
                if (id >= 1 && id <= empleados.size()) {
                    empleados.erase(empleados.begin() + (id - 1));
                    std::cout << "Empleado eliminado con éxito." << std::endl;
                } else {
                    std::cout << "ID de empleado inválido." << std::endl;
                }
                break;
            }
            case 3: {
                int id;
                std::cout << "Ingrese el ID del empleado a consultar: ";
                std::cin >> id;
                if (id >= 1 && id <= empleados.size()) {
                    empleados[id - 1].consultarEmpleado(id);
                } else {
                    std::cout << "ID de empleado inválido." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
      
          }
    }
    
    return 0;
}
