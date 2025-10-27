#include <iostream>
using namespace std;

// Clase base con CRTP
template <typename Derivada>
class Base {
public:
    void ejecutar() {
        //Llama a la implementación personalizada de la clase derivada
        static_cast<Derivada*>(this)->operacion();
    }
};

//Primera clase derivada 
class MensajeSaludo : public Base<MensajeSaludo> {
public:
    void operacion() {
        cout << "Hola, usando CRTP" << endl;
    }
};

//Segunda Clase derivada 
class MensajeDespedida : public Base<MensajeDespedida> {
public:
    void operacion() {
        cout << "Nos vemos" << endl;
    }
};

int main() {
    MensajeSaludo saludo;
    MensajeDespedida despedida;

    saludo.ejecutar();     
    despedida.ejecutar(); 

    return 0;
}
