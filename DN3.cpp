#include <iostream>
#include <cmath>

//definiramo funkcijo arkus tangens
double calcAtan(double* x, int* N_steps) {
    double rezultat = 0.0;
    double vrednost = *x;
    double x_kvadrat = (*x) *(*x);

    for  (int n = 0; n < *N_steps; ++n) {
        if (n % 2 == 0) {
            rezultat += vrednost / (2 * n + 1);
        } else {
            rezultat -= vrednost / (2 * n + 1);
        }
        vrednost *= x_kvadrat;
    } 
    return rezultat;
}


//definicija celotne f(x)
double funkcija(double x, int* N_steps) {
    double Atan_x = calcAtan(&x, N_steps); 
    return std::exp(3 * x) * Atan_x;
}


//definiramo funkcijo trapezne metode
double trapezna_metoda(double a, double b, int N, int* N_steps) {
    double h = (b - a) / N; 
    double rezultat = 0.0;

    rezultat += funkcija(a, N_steps) / 2.0;
    rezultat += funkcija(b, N_steps) / 2.0;

    for (int i = 1; i < N; ++i) {
        double x_i = a + i * h;
        rezultat += funkcija(x_i, N_steps);
    }

    rezultat *= h;
    return rezultat;
}


int main() {
    double a = 0.0;        
    double b = M_PI / 4;    
    int N = 1000;           // Število delitev za trapezno metodo
    int N_steps = 10;       // Taylorjeva vrsta - število korakov oz členov

    double rezultat = trapezna_metoda(a, b, N, &N_steps);

    std::cout << "Aproksimacija integrala z trapezno metodo je približno: " << rezultat << std::endl;

    return 0;
}

