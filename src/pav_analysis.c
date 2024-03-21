#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float res = 0.0;
    float sum = 0.0;        // si no funciona, inicialitzem a 1.e-6
    for(int i=0; i<N; i++){
        sum += x[i]*x[i]; 
    }
    res = 10 * log10(sum/N);
    return res;
}

float compute_am(const float *x, unsigned int N) {
    float res = 0.0;
    float sum = 0.0;
    for(int i=0; i<N; i++){
        sum += fabs(x[i]);
    }
    res = sum/N;
    return res;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float res = 0.0;
    float sum = 0.0;
    for(int i=1; i<N; i++){
        if((x[i]>0 && x[i-1]<0) || (x[i]<0 && x[i-1]>0)){
            sum++;
        }
    }
    res = (fm/2)*(1/(N-1))*sum;
    return res;
}
