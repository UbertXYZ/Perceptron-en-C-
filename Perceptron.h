#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__
class P_Capa
{
private:
    double *salida;
    double **pesos;
    double *bias;
    int input_size;
    int output_size;
public:
    P_Capa();
    void Iniciar(int*, double*, double**);
    double* Ejecutar(double*);
    void Funcion();
    void Entrenar(double*,double*);
    void Actualizar();
    ~P_Capa();
};

P_Capa::P_Capa()
{
}
void P_Capa::Iniciar(int* size, double* new_bias, double **new_pesos){
    input_size = size[0];
    output_size = size[1];
    delete[] pesos;
    pesos = new double*[input_size];
    bias = new double[output_size];
    salida = new double[output_size];
    for (int o = 0; o < output_size; o++){
        pesos[o] = new double[output_size];
        for (int i = 0; i < input_size; i++){
            pesos[o][i] = new_pesos[o][i];
        }
    }
    for (int o = 0; o < output_size; o++)
    {
        bias[o] = new_bias[o];
    }
    
}
double* P_Capa::Ejecutar(double *entrada){
    for (int o = 0; o < output_size; o++){
        double suma = 0;
        for (int i = 0; i < input_size; i++){
            suma += pesos[o][i] * entrada[i];
        }
        salida[o] = suma + bias[o];
    }
    return salida;
}
void P_Capa::Entrenar(double* entrada, double* valor_esperado){
    
}
P_Capa::~P_Capa()
{
    delete[] salida;
    delete[] bias;
    for (int o = 0; o < output_size; o++){
        delete[] pesos[o];
    }
    delete[] pesos;
}


class Perceptron
{
private:
    double* entradas;
    double* salidas;
    P_Capa *capas;
    int size_capas;
public:
    Perceptron(int, double***, int**, double**);
    double* Ejecutar(double*);
    ~Perceptron();
};
Perceptron::Perceptron(int num_capas, double*** num_pesos, int** size, double** bias)
{
    if(num_capas == 0)
        return;
    size_capas = num_capas;
    capas = new P_Capa[size_capas];
    for (int i = 0; i < size_capas; i++){
        capas[i].Iniciar(size[i], bias[i],num_pesos[i]);
    }
}
double* Perceptron::Ejecutar(double* nuevas_entradas){
    double *entradas = nuevas_entradas;
    double *tmp = entradas;
    for (int i = 0; i < size_capas; i++){
        tmp = capas[i].Ejecutar(tmp);
    }
    salidas = tmp;
    return salidas;
}
Perceptron::~Perceptron()
{
    for (int i = 0; i < size_capas; i++){
        capas->~P_Capa();
    }
    delete[] capas;
    delete[] entradas;
    delete[] salidas;
}

#endif