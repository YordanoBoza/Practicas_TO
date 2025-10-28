#ifndef PAR_H
#define PAR_H

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;

public:
    
    Par(const T1& p, const T2& s) : primero(p), segundo(s) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }

    void setPrimero(const T1& p) { primero = p; }
    void setSegundo(const T2& s) { segundo = s; }

    void mostrar() const {
        cout << "(" << primero << ", " << segundo << ")" << endl;
    }
};

#endif
