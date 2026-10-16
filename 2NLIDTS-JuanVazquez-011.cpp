#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

long long sumaIterativa(long long n)
{
    long long suma = 0;

    while (n > 9)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma + n;
}
long long sumaRecursiva(long long n)
{
    if (n <= 9)
        return n;
    else
        return sumaRecursiva(n / 10) + n % 10;
}

void limpiarEntrada()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

long long leerEntero(const string& mensaje, long long minimo)
{
    long long valor;

    while (true)
    {
        cout << mensaje;
        if (cin >> valor && valor >= minimo)
        {
            limpiarEntrada();
            return valor;
        }
        if (cin.eof())
        {
            // La entrada se cerro (Ctrl+D / Ctrl+Z): terminar sin ciclarse
            cout << "\n\nEntrada finalizada. Programa terminado.\n";
            exit(0);
        }
        cout << "  Entrada invalida. Ingrese un numero entero mayor o igual a "
            << minimo << ".\n";
        limpiarEntrada();
    }
}
void mostrarMenu()
{
    cout << "\n=============================================\n";
    cout << "   SUMA DE LOS DIGITOS DE UN NUMERO NATURAL\n";
    cout << "=============================================\n";
    cout << "1. Calcular con la solucion iterativa\n";
    cout << "2. Calcular con la solucion recursiva\n";
    cout << "3. Calcular con ambas y comparar\n";
    cout << "0. Salir\n";
    cout << "---------------------------------------------\n";
}

void procesarNumeros(int opcion)
{
    long long cantidad = leerEntero("\nCuantos numeros va a ingresar? ", 1);

    for (long long i = 1; i <= cantidad; i++)
    {
        long long n = leerEntero("Numero " + to_string(i) + ": ", 0);

        if (opcion == 1)
        {
            cout << "  Suma de digitos (iterativa) de " << n << " = "
                << sumaIterativa(n) << "\n";
        }
        else if (opcion == 2)
        {
            cout << "  Suma de digitos (recursiva) de " << n << " = "
                << sumaRecursiva(n) << "\n";
        }
        else
        {
            long long it = sumaIterativa(n);
            long long re = sumaRecursiva(n);
            cout << "  Iterativa: " << it << " | Recursiva: " << re
                << (it == re ? "  -> Resultados iguales" : "  -> Resultados distintos")
                << "\n";
        }
    }
}

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        opcion = (int)leerEntero("Elija una opcion: ", 0);

        switch (opcion)
        {
        case 1:
        case 2:
        case 3:
            procesarNumeros(opcion);
            break;
        case 0:
            cout << "\nPrograma terminado. Hasta luego!\n";
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}