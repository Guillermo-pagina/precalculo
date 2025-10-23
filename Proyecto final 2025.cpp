#include <iostream>
#include <cmath>
#include <string>
#include <complex>
#include <chrono>
#include <ctime>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

double pedirNumero(const string &mensaje) {
    double numero;
    while (true) {
        cout << mensaje;
        if (!(cin >> numero)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "error\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); return numero;
        }
    }
}

void numerosReales() {
    cout << "\n Ordenador de numeros reales ---\n";
    double n = pedirNumero("ingrese un valor: ");

    if (floor(n) == n) {
        if (n >= 0) cout << "El numero es natural, entero y real (positivo).\n";
        else cout << "el numero es entero y real (negativo).\n";
    } else {
        double raiz2_check = n / sqrt(2.0);
        if (abs(raiz2_check - round(raiz2_check)) < 1e-9) {
             cout << "El numero es real e irracional cercano a un multiplo de raiz de 2.\n";
        } else {
             cout << "el numero es real y racional.\n";
        }
    }
    cout << "------------------------------------\n";
}

void expresionesAlgebraicas() {
    cout << "\n suma de terminos semejantes ---\n";
    cout << "formato: ax + bx. se suman 'a' y 'b'.\n";
    double a = pedirNumero("coeficiente 'a': "), b = pedirNumero("coeficiente 'b': ");
    cout << "resultado: (" << a << "x) + (" << b << "x) = " << a + b << "x\n";
    cout << "------------------------------------\n";
}

void expresionesRacionales() {
    cout << "\n suma de fracciones (a/b + c/d) ---\n";
    double a = pedirNumero("numerador 1 (a): "), b = pedirNumero("denominador 1 (b): "), c = pedirNumero("numerador 2 (c): "), d = pedirNumero("denominador 2 (d): ");
    
    if (b == 0 || d == 0) { cout << "advertencia: el denominador no puede ser cero.\n"; return; }
    
    double num = a*d + b*c, den = b*d;
    cout << "resultado: " << a << "/" << b << " + " << c << "/" << d << " = " << num << "/" << den << " ~ " << num / den << "\n";
    cout << "------------------------------------\n";
}

void resolverEcuaciones() {
    cout << "\n solucion de ecuaciones cuadraticas ---\n";
    cout << "forma: ax^2 + bx + c = 0\n";
    double a = pedirNumero("valor de a: "), b = pedirNumero("valor de b: "), c = pedirNumero("valor de c: ");

    if (fabs(a) < 1e-12) {
        if (fabs(b) < 1e-12) { cout << "ecuacion degenerada. no hay solucion.\n"; return; }
        double x = -c / b;
        cout << "ecuacion lineal. solucion: x = " << x << "\n"; return;
    }

    double D = b*b - 4*a*c;
    cout << "discriminante (d) es: " << D << "\n";
    
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2*a), x2 = (-b - sqrt(D)) / (2*a);
        cout << "dos raices reales distintas: x1 = " << x1 << ", x2 = " << x2 << "\n";
    } else if (D == 0) {
        double x = -b / (2*a);
        cout << "una raiz real doble: x1 = x2 = " << x << "\n";
    } else {
        complex<double> x1(-b / (2*a), sqrt(-D) / (2*a)), x2(-b / (2*a), -sqrt(-D) / (2*a));
        cout << "dos raices complejas conjugadas: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
    cout << "------------------------------------\n";
}

void funcionesCuadraticas() {
    cout << "\n analisis de funcion cuadratica ---\n";
    cout << "forma: f(x) = ax^2 + bx + c\n";
    double a = pedirNumero("valor de a: "), b = pedirNumero("valor de b: "), c = pedirNumero("valor de c: ");
    
    if (fabs(a) < 1e-12) { cout << "el valor de 'a' debe ser distinto de cero.\n"; return; }
    
    double xv = -b / (2*a), yv = (a * xv * xv) + (b * xv) + c;
    
    cout << "vertice: (" << xv << ", " << yv << ")\n";
    cout << "eje de simetria: x = " << xv << "\n";
    cout << "orientacion: " << (a > 0 ? "abre hacia arriba (minimo).\n" : "abre hacia abajo (maximo).\n");
    cout << "------------------------------------\n";
}


void mostrarMenu() {
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S | %d/%m/%Y", localtime(&now));
    const string PAIS = "guatemala";

    cout << "\n-----------------------------------";
    cout << "\n" << buffer << " | zona: " << PAIS << "\n";
    cout << "-----------------------------------\n";
    cout << " Bienvenido/a, este programa fue realizado por los estudiantes de Ingenieria en sistemas de la seccion c, del segundo semestre\n";
    cout << "-----------------------------------\n";
    cout << "seleccione:\n";
    cout << "1. clasificacion de numeros\n";
    cout << "2. suma de terminos semejantes\n";
    cout << "3. suma de fracciones\n";
    cout << "4. resolver cuadraticas\n";
    cout << "5. analizar funciones cuadraticas\n";
    cout << "6. salir\n";
    cout << "------UNIVERSIDAD MARIANO GALVEZ-----\n";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int opcion = 0;

    do {
        mostrarMenu();
        cout << "opcion: ";
        
        if (!(cin >> opcion)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "error: ingrese solo el numero de opcion.\n"; continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: numerosReales(); break;
            case 2: expresionesAlgebraicas(); break;
            case 3: expresionesRacionales(); break;
            case 4: resolverEcuaciones(); break;
            case 5: funcionesCuadraticas(); break;
            case 6: cout << "\nsalida exitosa. ¡adios!\n"; break;
            default: cout << "opcion invalida. intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}