#include "mathlib.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define EPSILON 10e-10

static inline double Abs(double x) {
    double pos;
    if (x < 0.0) {
        pos = x * -1.0;
    }
    else{
	pos = x * 1.0;
    }
    return pos;
}

//SOURCE: Piazza Darell Long's Exp Function
static double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; Abs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

//SOURCE: Piazza Darell Long's Sqrt Function
static double Sqrt(double x) {
    double y = 1.0;
    assert(x >= 0);
    for (double guess = 0.0; Abs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}


//Newtons Method
double arcSin(double x) {
   double guess = x;
   double fx = (sin(guess) - x);
   double dfx = (cos(guess));
   double Newton = (fx/dfx)
   while (Abs(fx - x) > EPSILON){
       guess = guess + (x -
   } 
}
double arcCos(double x) {
    double solution;
    double arccos;
    solution = arcSin(x);
    arccos = (M_PI_2 - solution);
    return arccos;
}
double arcTan(double x) {
  double equation = (x/(Sqrt(x) + 1));
  double arctan;
  arctan = arcSin(equation);
  return arctan;
}

//Newtons Method - Darell Long's lecture. Changed variable names for readability
double Log(double x){
   double guess = 1.0;
   double fx = Exp(guess);
   while (Abs(fx - x) > EPSILON) {
       guess = guess + (x - fx) / fx;
       fx = Exp(guess);
   }
   return guess;
}
