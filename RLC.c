#include <math.h>
#include <stdio.h>

int main() {
  double R, L, C, sigma, omega0, omegad, s1, s2, il0, vc0, ir0, ic0, vl0, vr0, y;
  printf("Digite seu resistor: \n");
  scanf("%lf", &R);
  printf("Digite seu indutor: \n");
  scanf("%lf", &L);
  printf("Digite seu capacitor: \n");
  scanf("%lf", &C);
  printf("Digite seu vInicial: \n");
  scanf("%lf", &vc0);
  printf("Digite seu iInicial: \n");
  scanf("%lf", &il0);

  sigma = 1 / (2 * R * C);
  omega0 = 1 / (sqrt(L * C));
  printf("Sigma %g\n", sigma);
  printf("Omega0 %g\n", omega0);
  s1 = -sigma + sqrt(pow(sigma, 2) - pow(omega0, 2));
  s2 = -sigma - sqrt(pow(sigma, 2) - pow(omega0, 2));
  printf("S1 %g\n", s1);
  printf("S2 %g\n", s2);
  ir0 = vc0 / R;
  ic0 = il0 - ir0;
  y = ic0 / C;
  if (sigma > omega0) {
    double A1, A2;
    A2 = (y - s1 * vc0) / (s2 - s1);
    A1 = vc0 - A2;
    printf("A1 %g\n", A1);
    printf("A2 %g\n", A2);
    double tm = log((A1 * s1) / (-A2 * s2)) / (s2 - s1);
    printf("tm %g\n", tm);
  } else if (sigma == omega0) {
    double D1, D2;
    D2 = vc0;
    D1 = y + (vc0 * sigma);
    printf("D1 %g\n", D1);
    printf("D2 %g\n", D2);
  } else {
    double omegad, B1, B2;
    omegad = sqrt(pow(omega0, 2) - pow(sigma, 2));
    B1 = vc0;
    printf("ic0 %g\n", ic0);
    B2 = (-y + sigma * B1) / omegad;
    printf("B1 %g\n", B1);
    printf("B2 %g\n", B2);
  }
}