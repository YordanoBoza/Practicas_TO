#include <iostream>
#include <string>
using namespace std;

// Jerarquía base
class Transaccion {
protected:
    double monto;
public:
    Transaccion(double m) : monto(m) {}
    virtual void ejecutar() const {
        cout << "Ejecutando transaccion generica de $" << monto << endl;
    }
    virtual ~Transaccion() = default;
};

class Deposito : public Transaccion {
public:
    Deposito(double m) : Transaccion(m) {}
    void ejecutar() const override {
        cout << "Realizando deposito de $" << monto << endl;
    }
};

class Retiro : public Transaccion {
public:
    Retiro(double m) : Transaccion(m) {}
    void ejecutar() const override {
        cout << "Realizando retiro de $" << monto << endl;
    }
};

// Procesador genérico
template <typename T>
class Procesador {
public:
    void procesar(T* transaccion) {
        cout << "[Procesador] Procesando transaccion..." << endl;
        transaccion->ejecutar();
    }
};

// Contravarianza simulada
template <typename Derivado>
void procesarComoBase(Procesador<Transaccion>& procesador, Derivado* objeto) {
    static_assert(is_base_of<Transaccion, Derivado>::value,
                  "El tipo Derivado debe heredar de Transaccion");
    procesador.procesar(static_cast<Transaccion*>(objeto));
}

int main() {
    Procesador<Transaccion> procesadorBase;

    Deposito dep(500);
    Retiro ret(200);

    cout << "Simulando contravarianza con transacciones\n";

    procesarComoBase(procesadorBase, &dep);
    procesarComoBase(procesadorBase, &ret);

    return 0;
}
