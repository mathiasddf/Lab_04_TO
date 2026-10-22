#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::vector<int> numeros;
    std::mt19937 generador(std::random_device{}());
    std::uniform_int_distribution<int> distribucion(1, 1500);

    for (int i = 0; i < 30; ++i) {
        numeros.push_back(distribucion(generador));
    }

    auto esPrimo = [](int numero) {
        if (numero < 2) {
            return false;
        }

        for (int divisor = 2; divisor * divisor <= numero; ++divisor) {
            if (numero % divisor == 0) {
                return false;
            }
        }

        return true;
    };

    int cantidad = std::count_if(
        numeros.begin(),
        numeros.end(),
        [&esPrimo](int numero) {
            return numero < 1000 && esPrimo(numero);
        }
    );

    std::cout << "Numeros generados: ";
    for (int numero : numeros) {
        std::cout << numero << " ";
    }

    std::cout << "\nCantidad de primos menores que 1000: "
              << cantidad << "\n";

    return 0;
}