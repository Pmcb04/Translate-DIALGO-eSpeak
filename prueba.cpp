
#include <iostream>
#include <cstring>
using namespace std;


int main(int argc, char const *argv[])
{
    
    char cadena [] = "Prueba";
    int entero = 30;
    float real = 3.1415;
    bool logico = true;

    cout << "cadena con cadena" << strcat(cadena, cadena) << endl;
    cout << "cadena con entero" <<  strcat(cadena, entero) << endl;



    return 0;
}
