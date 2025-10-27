#include <iostream>
#include <memory>
using namespace std;

class Vehiculo {
public:
    virtual ~Vehiculo() = default;

    virtual void mostrar() const {
        cout << "Soy un Vehiculo generico" << endl;
    }

    // Metodo clonar
    virtual Vehiculo* clonar() const {
        cout << "Clonando Vehiculo" << endl;
        return new Vehiculo(*this);
    }
};

class Auto : public Vehiculo {
public:
    void mostrar() const override {
        cout << "Soy un Auto" << endl;
    }

    // Covarianza: retorna Auto* en lugar de Vehiculo*
    Auto* clonar() const override {
        cout << "Clonando Auto" << endl;
        return new Auto(*this);
    }
};

class Moto : public Vehiculo {
public:
    void mostrar() const override {
        cout << "Soy una Moto" << endl;
    }

    // Covarianza: retorna Moto* en lugar de Vehiculo*
    Moto* clonar() const override {
        cout << "Clonando Moto" << endl;
        return new Moto(*this);
    }
};

int main() {
    Vehiculo* v = new Vehiculo();
    Auto* a = new Auto();
    Moto* m = new Moto();

    cout << "Clonando objetos:" << endl;

    unique_ptr<Vehiculo> v_clon(v->clonar());
    unique_ptr<Auto> a_clon(a->clonar());
    unique_ptr<Moto> m_clon(m->clonar());

    cout << "Objetos clonados:" << endl;
    v_clon->mostrar();
    a_clon->mostrar();
    m_clon->mostrar();

    delete v;
    delete a;
    delete m;

    return 0;
}
