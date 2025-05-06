#include <iostream>
#include "PerceptronSimple.h"
using namespace std;
int main(){
    //Función OR en un Perceptrón Simple 
    double **data_entrenamiento = new double*[4];
    for (int i = 0; i < 4; i++)
    {
        data_entrenamiento[i] = new double[2];
    }
    data_entrenamiento[0][0] = 0.0;
    data_entrenamiento[0][1] = 0.0;
    data_entrenamiento[1][0] = 0.0;
    data_entrenamiento[1][1] = 1.0;
    data_entrenamiento[2][0] = 1.0;
    data_entrenamiento[2][1] = 0.0;
    data_entrenamiento[3][0] = 1.0;
    data_entrenamiento[3][1] = 1.0;

    double* esperado = new double[4];
    esperado[0] = 0.0;
    esperado[1] = 1.0;
    esperado[2] = 1.0;
    esperado[3] = 1.0;

    double pesos[2] = {0.1, 0.5};
    PerceptronSimple a(2, pesos, 0.1, 1.0);
    
    a.Entrenar(data_entrenamiento, esperado, 4, 200);
}