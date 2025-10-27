#include <iostream>
using namespace std;

// Funcion generica minimo()
template <typename T>
T minimo(T a, T b, T c) {
    T menor = a;

    if (b < menor)
        menor = b;
    if (c < menor)
        menor = c;

    return menor;
}

int main() {
    cout << "Menor de (3, 7, 5): " << minimo(3, 7, 5) << endl;
    cout << "Menor de (2.5, 1.1, 3.4): " << minimo(2.5, 1.1, 3.4) << endl;
    cout << "Menor de ('x', 'a', 'm'): " << minimo('x', 'a', 'm') << endl;

    return 0;
}
