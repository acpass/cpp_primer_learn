#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

constexpr double R_base = 1.8 / 2;
constexpr double theta_degree = 15;
constexpr int n = 1;
constexpr double S_whole = 12 * 12 / 2;

int main()
{
  double long_axis, short_axis;
  double S_base;
  double phi;

  constexpr double pi = M_PI;
  constexpr double theta = (theta_degree / 360) * 2 * pi;

  short_axis = R_base;
  long_axis = (2 * R_base) / sin(theta) / 2;
  S_base = pi * short_axis * long_axis;

  cout << long_axis << ", " << short_axis << '\n';
  cout << "the area of the hole or split is " << S_base << "\n";
  cout << "Phi is " << (S_base / S_whole * n * 100) << "%\n";

  cout << '\n';
  cout << "the equivalent circle's radiu is " << (R_base * sqrt(1 / sin(theta)));
}