#include <iostream>
#include "Par.h"
using namespace std;

int main() {
    
    Par<int, string> persona(25, "Carlos");
    cout << "Par persona: ";
    persona.mostrar();

    Par<double, char> ejemplo(3.14, 'D');
    cout << "Par ejemplo: ";
    ejemplo.mostrar();

    ejemplo.setPrimero(2.71);
    ejemplo.setSegundo('B');
    cout << "Par ejemplo modificado: ";
    ejemplo.mostrar();

    Par<string, bool> estado("Conectado", true);
    cout << "Par estado: ";
    estado.mostrar();

    return 0;
}
