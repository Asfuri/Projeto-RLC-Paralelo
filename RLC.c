#include <math.h>
#include <stdio.h>

int main() {
  double R, L, C, sigma, omega0, omegad, s1, s2, il0, vc0;
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
  printf("%g\n", sigma);
  printf("%g\n", omega0);
  s1 = -sigma + sqrt(pow(sigma, 2) - pow(omega0, 2));
  s2 = -sigma - sqrt(pow(sigma, 2) - pow(omega0, 2));
  printf("%g\n", s1);
  printf("%g\n", s2);
  
  if (sigma > omega0) {
  }
}