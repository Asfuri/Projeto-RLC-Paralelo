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

## :gear: Documentação

Conforme as informações relatadas na seção (Objetivo)[#dart-objetivo-1], a complexidade do programa está nos cálculos a partir das fórmulas vistas na disciplina. Com base nisso, a documentação aqui apresentada dá ênfase a essa complexidade, relevando algumas nuances presentes no código. 

### :abacus: Dependências

Este projeto foi desenvolvido utilizando apenas funcionalidades da biblioteca padrão da Linguagem C[^3][^4], ou seja, nenhuma biblioteca externa foi incluída no código.

[^4]:[Biblioteca Padrão da Linguagem C](https://www.ime.usp.br/~pf/algoritmos/apend/interfaces.html)

- **`<stdio.h>`**:  Usada para operações matemáticas de entrada e saída, como leitura de dados do teclado (`scanf`) e escrita de dados na tela (`printf`).
  - **Implementação:**  Em interações direta com um usuário, via terminal.

- **`<math.h>`**:  Utilizada para realizar operações matemáticas complexas, como funções trigonométricas (sin, cos), exponenciais (exp) e logarítmicas (log).
  - **Implementação:**  Essencial nos cálculos incluídos na proposta do programa, como o cálculo da frequência de ressonância, permitindo a análise precisa do comportamento do circuito.
 
### :bar_chart: Fórmulas

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
