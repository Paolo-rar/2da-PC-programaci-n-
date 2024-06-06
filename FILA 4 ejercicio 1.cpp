#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int filas = 3;
    const int columnas = 3;
    int matriz[filas][columnas];
    vector<int> sumaFilas(filas, 0);
    vector<int> sumaColumnas(columnas, 0);
   
    cout << "Ingresa los elementos de la matriz de 3x3:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
          
            sumaFilas[i] += matriz[i][j];
            sumaColumnas[j] += matriz[i][j];
        }
    }
    
    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Suma de cada fila:" << endl;
    for (int i = 0; i < filas; i++) {
        cout << "Fila " << i + 1 << ": " << sumaFilas[i] << endl;
    }
    
    cout << "Suma de cada columna:" << endl;
    for (int j = 0; j < columnas; j++) {
        cout << "Columna " << j + 1 << ": " << sumaColumnas[j] << endl;
    }
    return 0;
}

