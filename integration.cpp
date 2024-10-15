#include <iostream>
using namespace std;
typedef double(*func)(double);

double integrate(double a, double b, func f) {
  double i = a, sum = 0, d = 0.000001;
  while(i<b) {
    sum += f(i) * d; //f(xi) * delta_x
    i = i+d; //index increasing
  }
  return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(1, 5, line) << endl;     // 12
  cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(1, 5,square) << endl; // 41.3333
  cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(1, 5,cube) << endl;   // 156
  return 0;
}