/*
  Esse código depende de informações primordiais que se encontram do repositório no github:
  https://github.com/Asfuri/Projeto-RLC-Paralelo
*/

#include <math.h>
#include <stdio.h>

// Função para solicitar repetidamente um número válido como entrada
double checaSeNumero() {
  double num;
  int resultado;
  int c;
  while (1) {
    resultado = scanf("%lf", &num);
    if (resultado == 1) {
      break;
    } else {
      printf("Digite um numero!\n");
      while ((c = getchar()) != '\n' && c != EOF);
    }
  }
  return num;
}


/*
  Função que transforma e exibe um valor numérico com ou sem prefixos de unidade
  @param resposta = Valor a ser convertido
  @param prefixo = Condição de exibir o prefixo, 1 para exibir
  M -> Mega 10^6
  K -> Quilo 10^3
  m -> Mili 10^-3
  u -> Micro 10^-6
  n -> Nano 10^-9
*/
void transformarResposta(double resposta, int prefixo) {

// Verifica se o valor é maior ou igual a 10^6 ou menor ou igual a -10^6
  if (resposta >= 1000000 || resposta <= -1000000) {
  // Converte para Mega e exibe o número
    resposta = resposta / 1000000;
    if (prefixo == 1) {
      printf("%g M", resposta);
    } else {
      printf("%g * 10^6", resposta);
    }

// Verifica se o valor é maior ou igual a 10^3 ou menor ou igual a -10^3
  } else if (resposta >= 1000 || resposta <= -1000) {
  // Converte para Quilo e exibe o número
    resposta = resposta / 1000;
    if (prefixo == 1) {
      printf("%g k", resposta);
    } else {
      printf("%g * 10^3", resposta);
    }

// Verifica se o valor é maior ou igual a 10^0 ou menor ou igual a -10^0
  } else if (resposta >= 1 || resposta <= -1) {
  // Exibe o número
    resposta = resposta;
    printf("%g ", resposta);

// Verifica se o valor é maior ou igual a 10^-3 ou menor ou igual a -10^-3
  } else if (resposta >= 0.001 || resposta <= -0.001) {
  // Converte para Mili e exibe o número
    resposta = resposta * 1000;
    if (prefixo == 1) {
      printf("%g m", resposta);
    } else {
      printf("%g * 10^-3", resposta);
    }

// Verifica se o valor é maior ou igual a 10^-6 ou menor ou igual a -10^-6
  } else if (resposta >= 0.000001 || resposta <= -0.000001) {
  // Converte para Micro e exibe o número
    resposta = resposta * 1000000;
    if (prefixo == 1) {
      printf("%g u", resposta);
    } else {
      printf("%g * 10^-6", resposta);
    }

// Verifica se o valor é maior ou igual a 10^-9 ou menor ou igual a -10^-9
  } else if (resposta >= 0.000000001 || resposta <= -0.000000001) {
  // Converte para Nano e exibe o número
    resposta = resposta * 1000000000;
    if (prefixo == 1) {
      printf("%g n", resposta);
    } else {
      printf("%g * 10^-9", resposta);
    }
  }
}

// Função que ajusta um valor numérico com base no prefixo escolhido pelo usuário.
// Essa é a função que dá opções de prefixo para as unidade
double prefixo(double valor) {
  printf("Digite seu prefixo:\n");
  printf("0 - Sem prefixo. 1 - Quilo (k). 2 - Mili (m). 3 - Micro (u). 4 - Nano (n).\n");
  int prefixo;
  prefixo = checaSeNumero();
  double resultado = 0;
  // Verifica a opção escolhida pelo usuário
  switch (prefixo) {
  case 1:
    resultado = valor * 1000;
    break;
  case 2:
    resultado = valor / 1000;
    break;
  case 3:
    resultado = valor / 1000000;
    break;
  case 4:
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
    // Declaração das variaveis utilizadas
    double Rtemp, Ltemp, Ctemp, sigma, omega0, omegad, s1, s2, il0temp, vc0temp, ir0, ic0, vl0, vr0, y, tm, vtm;

    // Leitura dos dados de entrada
    printf("Digite a resistencia do resistor equivalente: \n");
    Rtemp = checaSeNumero();
    double R = prefixo(Rtemp);
    transformarResposta(R, 1);
    printf("Ohms\n");

    printf("Digite a indutancia do indutor equivalente: \n");
    Ltemp = checaSeNumero();
    double L = prefixo(Ltemp);
    transformarResposta(L, 1);
    printf("H\n");

    printf("Digite a capacitancia do capacitor equivalente: \n");
    Ctemp = checaSeNumero();
    double C = prefixo(Ctemp);
    transformarResposta(C, 1);
    printf("F\n");

    printf("Digite a tensao inicial do capacitor: \n");
    vc0temp = checaSeNumero();
    double vc0 = prefixo(vc0temp);
    transformarResposta(vc0, 1);
    printf("V\n");

    printf("Digite a corrente inicial do indutor: \n");
    il0temp = checaSeNumero();
    double il0 = prefixo(il0temp);
    transformarResposta(il0, 1);
    printf("A\n");

    // Calcula sigma, omega 0 e exibe na tela
    sigma = 1 / (2 * R * C);
    omega0 = 1 / (sqrt(L * C));
    printf("Sigma = ");
    transformarResposta(sigma, 0);
    printf(" s^-1\nOmega0 = ");
    transformarResposta(omega0, 0);
    printf(" rad/s\n");

    // Calcula previamente s1 e s2, para a exibição no circuito superamortecido
    s1 = -sigma + sqrt(pow(sigma, 2) - pow(omega0, 2));
    s2 = -sigma - sqrt(pow(sigma, 2) - pow(omega0, 2));

    // Calcula a corrente no resistor no instante t = 0 atraves da lei de ohm
    ir0 = vc0 / R;

    // Calcula a corrente no capacitor no instante t = 0 atraves da LKC
    ic0 = il0 - ir0;

    // Sendo y a derivada de v(t), em relação ao tempo, com t = 0, esse valor será igual a ic0/C
    y = ic0 / C;

    // Caso o circuito seja superacmortecido
    if (sigma > omega0) {
      printf("Circuto Superamortecido\n");
      // Exibe s1 e s2
      printf("S1 = ");
      transformarResposta(s1, 0);
      printf("\nS2 = ");
      transformarResposta(s2, 0);

      // Calcula A2 e A2 e exibe
      printf("\nA1 = ");
      double A1, A2;
      A2 = (y - s1 * vc0) / (s2 - s1);
      A1 = vc0 - A2;
      transformarResposta(A1, 0);
      printf("\nA2 = ");
      transformarResposta(A2, 0);
      printf("\n");

      // Calcula tm
      tm = -(log(fabs(-(A1 * s1) / (A2 * s2))) / (s1 - s2));
      printf("tm = ");
      transformarResposta(tm, 1);
      // Calcula vtm
      printf("s\nvtm = ");
      vtm = A1 * exp(s1 * tm) + A2 * exp(s2 * tm);
      transformarResposta(vtm, 1);
      printf("V\n");

      // Caso o circuito seja criticamente amortecido
    } else if (sigma == omega0) {
      printf("Circuito Criticamente Amortecido\n");
      // printf("S1 = ");
      // transformarResposta(s1, 0);
      // printf("\nS2 = ");
      // transformarResposta(s2, 0);

      // Calcula A1 e A2 e exibe
      printf("\nA1 = ");
      double A1, A2;
      A2 = vc0;
      A1 = y + (vc0 * sigma);
      transformarResposta(A1, 0);
      printf("\nA2 = ");
      transformarResposta(A2, 0);

      // Calcula tm
      printf("\ntm = ");
      tm = (A1 - A2 * sigma) / (A1 * sigma);
      transformarResposta(tm, 1);

      // Calcula vtm
      printf("s\nvtm = ");
      vtm = (A1 * tm + A2) * exp(-sigma * tm);
      transformarResposta(vtm, 1);
      printf("V\n");

      // Caso o circuito seja subamortecido
    } else {
      double omegad, B1, B2;
      
      // calcula omegad
      omegad = sqrt(pow(omega0, 2) - pow(sigma, 2));
      printf("Circuito Subamortecido\n");
      printf("OmegaD = ");
      transformarResposta(omegad, 0);
      printf(" rad/s\nB1 = ");

      // Calcula B1 e B2
      B1 = vc0;
      B2 = (y + sigma * B1) / omegad;
      transformarResposta(B1, 0);
      printf("\nB2 = ");
      transformarResposta(B2, 0);

      // Calcula tm
      printf("\ntm = ");
      tm = atan((-sigma * B1 + omegad * B2) / (sigma * B2 + omegad * B1)) / omegad;
      if (tm < 0) {
        tm += 3.14159 / omegad;
      }
      transformarResposta(tm, 1);

      // Calcula vtm
      printf("s\nvtm = ");
      vtm = exp(-sigma * tm) * (B1 * cos(omegad * tm) + B2 * sin(omegad * tm));
      transformarResposta(vtm, 1);
      printf("V\n");
    }
    tentarNovamente = 0;
    printf("Quer tentar novamente? (1-Sim 0-Nao)\n");
    tentarNovamente = checaSeNumero();
  }
}