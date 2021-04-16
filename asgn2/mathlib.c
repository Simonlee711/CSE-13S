#include "mathlib.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define EPSILON 1e-10

static double Abs(double x) {
    double pos;
    if (x < 0) {
        pos = x * -1;
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
    double guess = x; //this resembles p_k in Newtons Method
    double closer_guess = 0.0; //this resembles p_k+1 in Newton's method
    double Newton_computation = ((sin(guess) - x) / cos(guess)); //this is f(y)/f'(y)
    while (Abs(closer_guess - guess) > EPSILON) {
        closer_guess = guess - Newton_computation; //Newton's Method
        guess = closer_guess; //make p_k+1 -> p_k to find next p_k+1
    }
    return closer_guess;
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

//SOURCE Lecture slides: Darell Long
double Log(double x) {
    double y = 1.0;
    double p = Exp(y);
    while (Abs(p - x) > EPSILON) {
        y = y + (x - p) / p;
        p = Exp(y);
    }
    return y;
}
