#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//declaración de constantes globales
const int MAX = 100;

//declaración de tipos
typedef double tTipoNotas[MAX];

//declaración de prototipos de funciones
bool cargaNotas(tTipoNotas arrayNotas);

int main()
{
    tTipoNotas notas;
    if (!cargaNotas(notas))
        cout << "Error en apertura del fichero" << endl;
    else {
        for (int i = 0; notas[i] >= 0; i++)
            cout << notas[i] << endl;
    }

}

//Implementación de funciones
bool cargaNotas(tTipoNotas arrayNotas) {
    bool okCarga = true;
    ifstream inputData;
    string nombre;
    double nota;
    int ind = 0;
    cout << "Introduzca nombre fichero de carga: ";
    cin >> nombre;
    inputData.open(nombre);
    if (!inputData.is_open()) {
        okCarga = false;
    }
    else {
        inputData >> nota;
        while (nota >= 0.0 && ind < MAX) {
            arrayNotas[ind] = nota;
            ind++;
            inputData >> nota;
        }
        inputData.close();
    }
    return okCarga;
}