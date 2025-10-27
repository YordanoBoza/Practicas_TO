#include <iostream>
using namespace std;

constexpr int potencia(int base, int exponente) {
    return (exponente ==0) ? 1 : base * potencia(base, exponente - 1);
}

int main() {
    constexpr int resultado = potencia(3, 4);

    cout << "potencia en tiempo de compilacion: " << resultado << endl;

    int b, e;
    cout << "base y exponente seaprados por un espacio: ";
    cin >> b >> e;
    cout << "Tiempo de ejecucion: " << potencia(b, e) << endl;

    return 0;
}
