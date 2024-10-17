# :zap: Simulação de Circuitos RLC Paralelo

- ### [:dart: Objetivo](#dart-objetivo-1)
- ### [:gear: Documentação](#gear-documentação-1)
- ### [:wrench: Como rodar](#wrench-como-rodar-1)
- ### [:arrow_down: Baixar o projeto](https://github.com/Asfuri/Projeto-RLC-Paralelo/archive/refs/heads/main.zip)

## Disciplina de Eletricidade e Circuitos para computação I

Esse foi um projeto desenvolvido por discentes do curso de *Engenharia da Computação da Universidade Federal da Paraíba*, curso este que pertence ao *[Centro de Informática](http://ci.ufpb.br/)*, localizado na *[Rua dos Escoteiros S/N - Mangabeira - João Pessoa - Paraíba - Brasil](https://g.co/kgs/xobLzCE)*. O programa decorrente do desenvolvimento do código foi empregado com o objetivo de permitir ao docente, utilizando de métodos avaliativos, calcular e atribuir as respectivas notas dos participiantes do projeto. 

### :battery: Autores:

-  :zap:  *[Eduardo Asfuri Carvalho](https://github.com/Asfuri)*
-  :zap:  *[Lucas Henrique Vieira da Silva](https://github.com/hvslucas)*

###  :battery: Docente:

-  	:zap: Mardson Freitas de Amorim

[![360_F_477196087_Sopm1X0RnYmYYNHbJwiFTMhxGPcnki0S](https://github.com/user-attachments/assets/89d8d7dd-6977-4e5d-9de5-c100b286af56)](#zap-simulação-de-circuitos-rlc-paralelo)

## :dart: Objetivo:

O objetivo proposto foi desenvolver um programa em Linguagem C[^1] para apresentar , no terminal, os resultados da resposta natural de circuitos RLC em paralelo. Isto é, um circuito de segunda ordem que possui um resistor equivalente, um capacitor equivalente e um indutor equivalente após uma mudança no estado inicial ( carga forçada ) do circuito. As tensões dos componentes serão equivalentes para todo e qualquer t > 0, considerando t = 0 como o instante em que ocorre a mudança do circuto inicial para a equivalência com a resposta natural.[^2]

[^1]: [Linguagem C](https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o))
[^2]: [Circuito RLC em paralelo](https://embarcados.com.br/circuito-rlc-paralelo/)

O programa deve receber os seguintes dados de entrada:
- Os valores dos componentes e suas respectivas cargas iniciais, sendo fornecidas opções para a escolha das unidades:
  - R -> Resistência equivalente
  - L -> Indutância equivalente
  - C -> Capacitância equivalente
  - v<sub>C</sub>(t=0) -> Tensão inicial no capacitor equivalente 
  - i<sub>L</sub>(t=0) -> Corrente inicial no indutor equivalente

O programa deve fornecer os seguintes dados de saída:
- Nome(s) do(s) autor(es)
- Valores de **σ** (Sigma, representa a Frequência Neperiana), **ω<sub>0</sub>** (Ômega 0, representa a Frequência de Ressonância)
- Tipo de circuito e seus respectivos valores específicos, sendo eles:
  - Circuito Superamortecido  ->  s<sub>1</sub>, s<sub>2</sub>, A<sub>1</sub> e A<sub>2</sub>
  - Circuito Criticamente Amortecido  ->  A<sub>1</sub> e A<sub>2</sub>
  - Circuito Subamortecido  ->  **ω<sub>d</sub>** (Ômega d), B<sub>1</sub> e B<sub>2</sub>
- Valores de **t<sub>m</sub>** (Tempo de Tensão Máxima ou Mínima) e **v(t<sub>m</sub>)** (Valor da tensão Máxima ou Mínima)

Todas as entradas e saídas devem obedecer o padrão estabelecido pelo S.I.[^3].

[^3]:[Sistema Internacional de Unidades](https://pt.wikipedia.org/wiki/Sistema_Internacional_de_Unidades)

Para a padronização das respostas, as condições iniciais para o circuito têm as seguintes notações:

![Captura de tela 2024-10-16 220340](https://github.com/user-attachments/assets/0049c77f-b52f-44cb-b06f-799eb1f9b8b6)

# :gear: Documentação

Conforme as informações relatadas na seção (Objetivo)[#dart-objetivo-1], a complexidade do programa está nos cálculos a partir das fórmulas vistas na disciplina. Com base nisso, a documentação aqui apresentada dá ênfase a essa complexidade, relevando algumas nuances presentes no código. 

## :abacus: Dependências

Este projeto foi desenvolvido utilizando apenas funcionalidades da biblioteca padrão da Linguagem C[^3][^4], ou seja, nenhuma biblioteca externa foi incluída no código.

[^4]:[Biblioteca Padrão da Linguagem C](https://www.ime.usp.br/~pf/algoritmos/apend/interfaces.html)

- **`<stdio.h>`**:  Usada para operações matemáticas de entrada e saída, como leitura de dados do teclado (`scanf`) e escrita de dados na tela (`printf`).
  - **Implementação:**  Em interações direta com um usuário, via terminal.

- **`<math.h>`**:  Utilizada para realizar operações matemáticas complexas, como funções trigonométricas (sin, cos), exponenciais (exp) e logarítmicas (log).
  - **Implementação:**  Essencial nos cálculos incluídos na proposta do programa, como o cálculo da frequência de ressonância, permitindo a análise precisa do comportamento do circuito.
 
## :bar_chart: Fórmulas

Todas as fórmulas utilizadas foram deduzidas a partir da análise das equações fundamentais com valores literais, ou seja, as variáveis (paramâmetros como coeficientes e constantes, tal como, incógnitas e variáveis dependentes) foram manipuladas com o objetivo de chegar em uma fórmula direta.

**OBS.:** As unidades das fórmulas foram omitidas, de forma que pode complicar o entendimento e uma possível aplicação prática, recomendamos a busca pelas fórmulas originais em fontes relevantes e a tentativa de manipulação das fórmulas pelos métodos aqui aplicados.

Equações fundamentais:

Resistor - Lei de Ohm

$$ V = R * I ∴ v_{R}(t) = R * i_{R}(t) $$

Corrente no Capacitor

$$ i_{C}(t) = C \cdot \frac{dv_{C}(t)}{dt} $$

**σ** (Frequência Neperiana)

$$ \sigma = \frac{1}{2 \cdot R \cdot C} $$

**ω<sub>0</sub>** (Frequência de ressonância)

$$ \omega_0 = \frac{1}{\sqrt{L \cdot C}} $$

### Para **σ**<sup>2</sup> > **ω<sub>0</sub>**<sup>2</sup> - Circuito Superamortecido

$$ S_1 = -\sigma + \sqrt{\sigma^2 - \omega_0^2} $$

$$ S_2 = -\sigma - \sqrt{\sigma^2 - \omega_0^2} $$

A fórmula geral da tensão nos componenetes do Circuito Superamortecido é dada por:

$$ v(t) = A_1 e^{s_1 t} + A_2 e^{s_2 t} $$

Como entrada do programa, é fornecida a tensão inicial no capacitor, a qual também poderia ser determinada por meio da análise da tensão no capacitor para t = 0⁻. Ou seja, conseguimos atribuir o valor 0 para t e igualar a equação ao valor de v<sub>C</sub>(0).

$$ v_{C}(0) = A_1 e^{s_1 0} + A_2 e^{s_2 0} \therefore v_{C}(0) = A_1 + A_2 $$

Para obter uma segunda equação e resolver um sistema de duas equações com duas variáveis distintas, devemos realizar a análise do circuito. A partir de um dos nós essenciais, podemos aplicar a Lei de Kirchhoff das Correntes (LKC), chegando à conclusão de que:

$$ i_L (t) = i_C (t) + i_R (t) $$

$$ \therefore $$ 

$$i_L (t) = C \cdot \frac{dv_{C}(t)}{dt}^{t=t} + \frac{v_{R}(t)}{R} $$

Como entrada do programa, é fornecida a corrente inicial no indutor (i<sub>L</sub>0), a qual também poderia ser determinada por meio da análise da corrente no indutor para t = 0⁻. Com isso, podemos realizar a análise dessa fórmula para t = 0. Mas antes, é essencial determinar a derivada de v<sub>C</sub>(t) e igualar t = 0.

$$ \frac{d}{dt} (A_1 e^{s_1 t} + A_2 e^{s_2 t}) = A_1 s_1 e^{s_1 t} + A_2 s_2 e^{s_2 t} $$

Utilizando y para representar a equação resultante de t = 0:

$$ y = \frac{dv_{C}(t)}{dt}^{t=0} = A_1 s_1 e^{s_1 0} + A_2 s_2 e^{s_2 0} = A_1 s_1 + A_2 s_2 $$

Voltando à equação das correntes para t = 0, sabemos que v<sub>R</sub>(t) = v<sub>C</sub>(t). Como conhecemos esse valor para t = 0, podemos substituí-lo na equação, assim como i<sub>L</sub>(0).

$$i_L (0) = C \cdot y + \frac{v_{C}(0)}{R} $$

Queremos isolar o y, então ficaremos com:

$$ y = \frac{i_{L}(0)}{C} - \frac{v_{C}(0)}{CR} $$

Utilizando de y como uma nova variável de valor determinável, conseguimos nossa 2ª equação. Ficando com o seguinte sistema:

$$
\begin{cases}
\quad v_{C}(0) = A_1 + A_2 \\
\quad y = A_1 s_1 + A_2 s_2 
\end{cases}
$$

Que nos leva a:

$$
\begin{cases}
\quad A_1 = \frac{y - v_{C}(0)s_1}{s_1 - s_2} \\
\quad A_2 = \frac{y - v_{C}(0)s_1}{s_2 - s_1}  = v_{C}(0) - A_1
\end{cases}
$$

Para achar o tempo para o alcance da tensão máxima ou mínima, é necessário derivar v(t) e igualar a 0. Reutilizando a conta já relizada e fazendo algumas manipulações, chegaremos a:

$$ t_m = \frac{ln |A_1s_1| - ln |-A_2s_2|}{s_2 - s_1}$$

Possuindo todas as variáveis da equação e o t<sub>m</sub>, basta calcular v(t<sub>m</sub>) e achar o valor esperado. 

### Para **σ**<sup>2</sup> = **ω<sub>0</sub>**<sup>2</sup> - Circuito Criticamente Amortecido

A fórmula geral da tensão nos componenetes do Circuito Criticamente Amortecido é dada por:

$$ v(t) = (A_1t + A_2) e^{-\sigma t}$$

Como entrada do programa, é fornecida a tensão inicial no capacitor, a qual também poderia ser determinada por meio da análise da tensão no capacitor para t = 0⁻. Ou seja, conseguimos atribuir o valor 0 para t e igualar a equação ao valor de v<sub>C</sub>(0).

$$ v_{C}(0) = (A_1 \cdot 0 + A_2) e^{-\sigma \cdot 0} \therefore A_2 = v_{C}(0)$$

Para obter uma segunda equação para conseguir determinar A<sub>1</sub>, devemos realizar a análise do circuito. A partir de um dos nós essenciais, podemos aplicar a Lei de Kirchhoff das Correntes (LKC), chegando à conclusão de que:

$$ i_L (t) = i_C (t) + i_R (t) $$

$$ \therefore $$ 

$$i_L (t) = C \cdot \frac{dv_{C}(t)}{dt}^{t=t} + \frac{v_{R}(t)}{R} $$

Como entrada do programa, é fornecida a corrente inicial no indutor (i<sub>L</sub>0), a qual também poderia ser determinada por meio da análise da corrente no indutor para t = 0⁻. Com isso, podemos realizar a análise dessa fórmula para t = 0. Mas antes, é essencial determinar a derivada de v<sub>C</sub>(t) e igualar t = 0.

$$ \frac{d}{dt} (A_1t + A_2) e^{-\sigma t} = A_1 \cdot e^{-\sigma t} - \sigma (A_1t + A_2) e^{-\sigma t} $$

Utilizando y para representar a equação resultante de t = 0:

$$ y = \frac{dv_{C}(t)}{dt}^{t=0} = A_1 - \sigma \cdot A_2 $$

Se:

$$ y = \frac{dv_{C}(t)}{dt}^{t=0} = \frac{i_{C}(0)}{C} $$

Então:

$$ A_1 = \frac{i_{C}(0)}{C} + \sigma \cdot A_2 $$

Para achar o tempo para o alcance da tensão máxima ou mínima, é necessário derivar v(t) e igualar a 0. Reutilizando a conta já relizada e fazendo algumas manipulações, chegaremos a:

$$ t_m = \frac{1}{\sigma} - \frac{A_2}{A_1} = \frac{A_1-(A_2\sigma)}{A_1\sigma}$$

Possuindo todas as variáveis da equação e o t<sub>m</sub>, basta calcular v(t<sub>m</sub>) e achar o valor esperado. 

### Para **σ**<sup>2</sup> < **ω<sub>0</sub>**<sup>2</sup> - Circuito Subamortecido

A fórmula geral da tensão nos componenetes do Circuito Subamortecido é dada por:

$$ v(t) = e^{-\sigma t} \cdot [B_1 \cdot cos(\omega_d \cdot t) + B_2 \cdot sen(\omega_d \cdot t)] $$

Sendo **ω_d** a Frequência natural de ressonância, dada pela equação:

$$ \omega_d = \sqrt{\omega_0^2 - \sigma^2} $$

Como entrada do programa, é fornecida a tensão inicial no capacitor, a qual também poderia ser determinada por meio da análise da tensão no capacitor para t = 0⁻. Ou seja, conseguimos atribuir o valor 0 para t e igualar a equação ao valor de v<sub>C</sub>(0).

$$ v_{C}(0) = e^{-\sigma 0} \cdot [B_1 \cdot cos(\omega_d \cdot 0) + B_2 \cdot sen(\omega_d \cdot 0)] \therefore B_1 = v_{C}(0)$$

Para obter uma segunda equação para conseguir determinar B<sub>@</sub>, devemos realizar a análise do circuito. A partir de um dos nós essenciais, podemos aplicar a Lei de Kirchhoff das Correntes (LKC), chegando à conclusão de que:

$$ i_L (t) = i_C (t) + i_R (t) $$

$$ \therefore $$ 

$$i_L (t) = C \cdot \frac{dv_{C}(t)}{dt}^{t=t} + \frac{v_{R}(t)}{R} $$

Como entrada do programa, é fornecida a corrente inicial no indutor (i<sub>L</sub>0), a qual também poderia ser determinada por meio da análise da corrente no indutor para t = 0⁻. Com isso, podemos realizar a análise dessa fórmula para t = 0. Mas antes, é essencial determinar a derivada de v<sub>C</sub>(t) e igualar t = 0.

$$ \frac{d}{dt} e^{-\sigma t} \cdot [B_1 \cdot cos(\omega_d \cdot t) + B_2 \cdot sen(\omega_d \cdot t)] = $$

$$
-\sigma e^{-\sigma t} \left[ B_1 cos(\omega_d t) + B_2 sen(\omega_d t) \right] + \omega_d e^{-\sigma t} \left[ -B_1 sen(\omega_d t) + B_2 cos(\omega_d t) \right] ^{t=t}
$$

Para t = 0 teremos:

$$ - \sigma \cdot B_1 + B_2 \cdot \omega_d = \frac{i_C(0)}{C} $$

Implicando em:

$$ B_2 = \frac{i_C(0)}{C \omega_d} + \frac{\sigma \cdot B_1}{\omega_d} $$

Para achar o tempo para o alcance da tensão máxima ou mínima, é necessário derivar v(t) e igualar a 0. Reutilizando a conta já relizada e fazendo algumas manipulações, que nesse caso, se torna um pouco mais complexo, pois envolve uma divisão estratégica por cos(ω<sub>d</sub>t), chegaremos a:

$$ \large t_m = \frac{arc tg(\frac{\omega_d \cdot B_2 - \sigma \cdot B_1}{\omega_d \cdot B_1 + \sigma \cdot B_2})}{\omega_d} $$

Possuindo todas as variáveis da equação e o t<sub>m</sub>, basta calcular v(t<sub>m</sub>) e achar o valor esperado. 

## :wrench: Como rodar

[**Atenção:** Lembre de baixar o projeto e extraí-lo devidamente do `.zip`.](#zap-simulação-de-circuitos-rlc-paralelo)

***Requisitos***
- Um terminal de linha de comando
- Um compilador de c, recomendamos o `gcc` ou o `clang`

### Bash - Linux ou Mac

Para compilar

```sh
gcc RLC.c -o RLC.out
```

Para rodar

```sh
./RLC.out
```

### No Windows

```sh
gcc RLC.c -o RLC.exe
```

Para rodar

```sh
./RLC.exe
```

**OBS.:** Utilizamos de barra normal ('/') considerando um ambiente como Git Bash, WSL e PowerShell, considere utilizar de barra invertida ('\\') em caso de não compilar
