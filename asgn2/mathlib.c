#include <stdio.h>
#include <mathlib.h>

double Abs(double x){
    if(x < 0){
       pos  = x * -1;
    }
    return pos
}

//SOURCE: Piazza Darell Long's Exp Function
double Exp(double x){
    double term = 1, sum = 1;
    for(int k = 1; Abs(term) > EPSILON; k +=1){
        term *= x/k;
        sum += term;
    }
    return sum;
}

//SOURCE: Piazza Darell Long's Sqrt Function
double Sqrt(double x){
    double y = 1.0;
    assert(x >= 0);
    for(double guess = 0.0; Abs(y - guess) > EPSILON; y = (y + x / y) / 2.0){
        guess = y;
    }
    return y;
}

double arcSin(double x){

}
double arcCos(double x){

}
double arcTan(double x){

}

//Newtons Method
double Log(double x){

}

