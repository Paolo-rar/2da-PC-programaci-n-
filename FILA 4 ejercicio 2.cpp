#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Alumno {
    string nombre;
    vector<int> notas;
};

bool validarNota(int nota) {
    return nota >= 0 && nota <= 20;
}

float calcularMediaAlumno(const Alumno& alumno) {
    float suma = 0;
    int numNotas = 0;
    for (size_t i = 0; i < alumno.notas.size(); i++) {
        if (validarNota(alumno.notas[i])) {
            suma += alumno.notas[i];
            numNotas++;
        } else {
            cout << "La nota ingresada para la asignatura " << i + 1 << " del alumno " << alumno.nombre << " no es válida. Debe estar en el rango de 0 a 20." << endl;
        }
    }
    return numNotas > 0 ? suma / numNotas : 0;
}

int main() {
    int numAlumnos;
    cout << "Ingrese el numero de alumnos en la clase: ";
    cin >> numAlumnos;

    const int numAsignaturas = 8;

    vector<Alumno> alumnos(numAlumnos);
    vector<float> mediasAlumnos(numAlumnos, 0);
    vector<float> mediasAsignaturas(numAsignaturas, 0);
    vector<int> faltas(numAlumnos, 0);

    for (int i = 0; i < numAlumnos; i++) {
        cout << "\nIngrese el nombre del alumno " << i + 1 << ": ";
        cin >> alumnos[i].nombre;

        cout << "Ingrese las notas del alumno " << alumnos[i].nombre << " en las 8 asignaturas (de 0 a 20):" << endl;
        alumnos[i].notas.resize(numAsignaturas);
        for (int j = 0; j < numAsignaturas; j++) {
            int nota;
            cout << "Nota de la asignatura " << j + 1 << ": ";
            cin >> nota;
            if (validarNota(nota)) {
                alumnos[i].notas[j] = nota;
            } else {
                cout << "La nota ingresada no es valida. Debe estar en el rango de 0 a 20." << endl;
                j--; 
            }
        }
    }

    for (int i = 0; i < numAlumnos; i++) {
        mediasAlumnos[i] = calcularMediaAlumno(alumnos[i]);
        cout << "\nLa media del alumno " << alumnos[i].nombre << " es: " << fixed << setprecision(2) << mediasAlumnos[i] << endl;
    }
    
    
    for (int i = 0; i < numAlumnos; i++) {
        mediasAlumnos[i] = calcularMediaAlumno(alumnos[i]);
        for (int j = 0; j < numAsignaturas; j++) {
            if (alumnos[i].notas[j] != 0) {
                mediasAsignaturas[j] += alumnos[i].notas[j];
            } else {
                faltas[i]++;
            }
        }
    }

    float mediaGeneralClase = 0;
    for (int i = 0; i < numAlumnos; i++) {
        mediaGeneralClase += mediasAlumnos[i];
    }
    mediaGeneralClase /= numAlumnos;

    for (int i = 0; i < numAsignaturas; i++) {
        mediasAsignaturas[i] /= (numAlumnos - faltas[i]);
    }

    float porcentajeFaltas = 0;
    for (int i = 0; i < numAlumnos; i++) {
        porcentajeFaltas += (static_cast<float>(faltas[i]) / numAsignaturas) * 100;
    }
    porcentajeFaltas /= numAlumnos;

    cout << "\nMedia general de la clase: " << mediaGeneralClase << endl;
    cout << "\nMedias de la clase en cada asignatura:" << endl;
    for (int i = 0; i < numAsignaturas; i++) {
        cout << "Asignatura " << i + 1 << ": " << mediasAsignaturas[i] << endl;
    }
    cout << "\nPorcentaje de faltas: " << porcentajeFaltas << "%" << endl;

    return 0;
}





