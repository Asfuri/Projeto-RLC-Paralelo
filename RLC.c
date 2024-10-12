#include <math.h>
#include <stdio.h>

void transformarResposta(double resposta, int prefixo) {
  if (resposta >= 1000000 || resposta <= -1000000) {
    resposta = resposta / 1000000;
    if (prefixo == 1) {
      printf("%g M", resposta);
    } else {
      printf("%g * 10^6", resposta);
    }
  } else if (resposta >= 1000 || resposta <= -1000) {
    resposta = resposta / 1000;
    if (prefixo == 1) {
      printf("%g k", resposta);
    } else {
      printf("%g * 10^3", resposta);
    }
  } else if (resposta >= 1 || resposta <= -1) {
    resposta = resposta;
    printf("%g ", resposta);
  } else if (resposta >= 0.001 || resposta <= -0.001) {
    resposta = resposta * 1000;
    if (prefixo == 1) {
      printf("%g m", resposta);
    } else {
      printf("%g * 10^-3", resposta);
    }
  } else if (resposta >= 0.000001 || resposta <= -0.000001) {
    resposta = resposta * 1000000;
    if (prefixo == 1) {
      printf("%g u", resposta);
    } else {
      printf("%g * 10^-6", resposta);
    }
  } else if (resposta >= 0.000000001 || resposta <= -0.000000001) {
    resposta = resposta * 1000000000;
    if (prefixo == 1) {
      printf("%g n", resposta);
    } else {
      printf("%g * 10^-9", resposta);
    }
  }
}

double prefixo(double valor) {
  printf("Digite seu prefixo:\n");
  printf("0 - Sem prefixo. 1 - Quilo (k). 2 - Mili (m). 3 - Micro (u). 4 - Nano (n).\n");
  char prefixo;
  getchar();
  prefixo = getchar();
  double resultado = 0;
  switch (prefixo) {
  case '1':
    resultado = valor * 1000;
    break;
  case '2':
    resultado = valor / 1000;
    break;
  case '3':
    resultado = valor / 1000000;
    break;
  case '4':
    resultado = valor / 1000000000;
    break;
  default:
    resultado = valor;
  }
  return resultado;
}

int main() {
  printf("Autores: \n");
  printf("Eduardo Asfuri \n");
  printf("Lucas Henrique \n");
  int tentarNovamente = 1;
  while (tentarNovamente != 0) {
    double Rtemp, Ltemp, Ctemp, sigma, omega0, omegad, s1, s2, il0temp, vc0temp, ir0, ic0, vl0, vr0, y, tm, vtm;
    printf("Digite a resistencia do resistor equivalente: \n");
    scanf("%lf", &Rtemp);
    double R = prefixo(Rtemp);
    transformarResposta(R, 1);
    printf("Ohms\n");
    printf("Digite a indutancia do indutor equivalente: \n");
    scanf("%lf", &Ltemp);
    double L = prefixo(Ltemp);
    transformarResposta(L, 1);
    printf("H\n");
    printf("Digite a capacitancia do capacitor equivalente: \n");
    scanf("%lf", &Ctemp);
    double C = prefixo(Ctemp);
    transformarResposta(C, 1);
    printf("F\n");
    printf("Digite a tensao inicial do capacitor: \n");
    scanf("%lf", &vc0temp);
    double vc0 = prefixo(vc0temp);
    transformarResposta(vc0, 1);
    printf("V\n");
    printf("Digite a corrente inicial do indutor: \n");
    scanf("%lf", &il0temp);
    double il0 = prefixo(il0temp);
    transformarResposta(il0, 1);
    printf("A\n");
    sigma = 1 / (2 * R * C);
    omega0 = 1 / (sqrt(L * C));
    printf("Sigma = ");
    transformarResposta(sigma, 0);
    printf(" s^-1\nOmega0 = ");
    transformarResposta(omega0, 0);
    printf(" rad/s\n");
    s1 = -sigma + sqrt(pow(sigma, 2) - pow(omega0, 2));
    s2 = -sigma - sqrt(pow(sigma, 2) - pow(omega0, 2));
    ir0 = vc0 / R;
    ic0 = il0 - ir0;
    y = ic0 / C;
    if (sigma > omega0) {
      printf("Circuto Superamortecido\n");
      printf("S1 = ");
      transformarResposta(s1, 0);
      printf("\nS2 = ");
      transformarResposta(s2, 0);
      printf("\nA1 = ");
      double A1, A2;
      A2 = (y - s1 * vc0) / (s2 - s1);
      A1 = vc0 - A2;
      transformarResposta(A1, 0);
      printf("\nA2 = ");
      transformarResposta(A2, 0);
      printf("\n");
      tm = -(log(fabs(-(A1 * s1) / (A2 * s2))) / (s1 - s2));
      printf("tm = ");
      transformarResposta(tm, 1);
      printf("s\nvtm = ");
      vtm = A1 * exp(s1 * tm) + A2 * exp(s2 * tm);
      transformarResposta(vtm, 1);
      printf("V\n");
    } else if (sigma == omega0) {
      printf("Circuito Criticamente Amortecido\n");
      printf("S1 = ");
      transformarResposta(s1, 0);
      printf("\nS2 = ");
      transformarResposta(s2, 0);
      printf("\nA1 = ");
      double A1, A2;
      A2 = vc0;
      A1 = y + (vc0 * sigma);
      transformarResposta(A1, 0);
      printf("\nA2 = ");
      transformarResposta(A2, 0);
      printf("\ntm = ");
      tm = (A1 - A2 * sigma) / (A1 * sigma);
      transformarResposta(tm, 1);
      printf("s\nvtm = ");
      vtm = (A1 * tm + A2) * exp(-sigma * tm);
      transformarResposta(vtm, 1);
      printf("V\n");
    } else {
      double omegad, B1, B2;
      omegad = sqrt(pow(omega0, 2) - pow(sigma, 2));
      printf("Circuito Subamortecido\n");
      printf("OmegaD = ");
      transformarResposta(omegad, 0);
      printf(" rad/s\nB1 = ");
      B1 = vc0;
      B2 = (y + sigma * B1) / omegad;
      transformarResposta(B1, 0);
      printf("\nB2 = ");
      transformarResposta(B2, 0);
      printf("\ntm = ");
      tm = atan((-sigma * B1 + omegad * B2) / (sigma * B2 + omegad * B1)) / omegad;
      if (tm < 0) {
        tm += 3.14159 / omegad;
      }
      transformarResposta(tm, 1);
      printf("s\nvtm = ");
      vtm = exp(-sigma * tm) * (B1 * cos(omegad * tm) + B2 * sin(omegad * tm));
      transformarResposta(vtm, 1);
      printf("V\n");
    }
    tentarNovamente = 0;
    printf("Quer tentar novamente? (1-Sim 0-Nao)\n");
    scanf("%d", &tentarNovamente);
  }
}