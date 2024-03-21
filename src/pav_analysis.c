#include <math.h>
#include <stdlib.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    double suma = 0;
    int n = 0;

    for (n = 0; n < N; n++) {
        suma += x[n] * x[n];
    }
     double resultado = 10 * log10(suma / N);
    return resultado;
}

float compute_am(const float *x, unsigned int N) {
    float suma = 0;
    int n = 0;

    for (n = 0; n < N; n++) {
        suma += fabs(x[n]); 
    }

    double resultado = suma / N;
    return resultado;
}
int signo(double x) {
        if (x > 0) return 1;
        else if (x < 0) return -1;
        else return 0;
}  
float compute_zcr(const float *x, unsigned int N, float fm) {
    
    double suma = 0;
    int n = 0;
    float ZCR=0;
    
    for (n = 1; n < N; n++) {
        suma += abs(signo(x[n]) - signo(x[n-1]));
    }     

    return ZCR = (fm / 2) * (1.0 / (N - 1)) * suma;
}

