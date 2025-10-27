#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//Excepción 
class ErrorConexion : public exception {
private:
    string mensaje;
public:
    explicit ErrorConexion(const string& msg) : mensaje(msg) {}

    //Sobrescribimos what() para devolver el mensaje de error
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

//Función que simula una conexión a un servidor
void conectarServidor(bool conexionExitosa) {
    if (!conexionExitosa) {
        throw ErrorConexion("Error de conexión: No se pudo conectar al servidor.");
    }
    cout << "Conexión exitosa al servidor " << endl;
}

int main() {
    try {
        conectarServidor(false); //Prueba forzada que genera la excepción
    }
    catch (const ErrorConexion& e) {
        cerr << "Excepción capturada: " << e.what() << endl;
    }

    return 0;
}
