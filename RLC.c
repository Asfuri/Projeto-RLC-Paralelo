#include <math.h>
#include <stdio.h>

int main() {
  double R, L, C, sigma, omega0, omegad, s1, s2, il0, vc0, ir0, ic0, vl0, vr0, y, x, A1, A2;
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

  if (sigma > omega0) {
    s1 = -sigma + sqrt(pow(sigma, 2) - pow(omega0, 2));
    s2 = -sigma - sqrt(pow(sigma, 2) - pow(omega0, 2));
    printf("S1 %g\n", s1);
    printf("S2 %g\n", s2);
    ir0 = vc0 / R;
    ic0 = il0 - ir0;
    y = ic0 / C;
    A2 = (y - s1 * vc0) / (s2 - s1);
    A1 = vc0 - A2;
    printf("y %g\n", y);
    printf("A1 %g\n", A1);
    printf("A2 %g\n", A2);
    double tm = log((A1 * s1) / (-A2 * s2)) / (s2 - s1);
    printf("%g\n", tm);
  } else if (sigma == omega0) {
    
  }
}