# 🚤 Barco Autônomo com Controle de pH

Este repositório contém o código fonte de um projeto acadêmico desenvolvido para a disciplina de Circuitos Elétricos. O projeto consiste em um protótipo de barco que utiliza um sensor de pH para automatizar sua navegação e sinalização.

**Status:** Concluído (Nota Máxima ✔️)

## 🎯 Objetivo
Criar uma solução tecnológica alinhada às ODS (Objetivos de Desenvolvimento Sustentável), integrando eletrônica, programação e mecânica. O sistema simula um veículo de monitoramento ambiental.

## 🛠️ Funcionamento do Hardware

O sistema mecânico é composto por um **Motor de Passo** acoplado a um sistema de elásticos. O motor gira o eixo, que por sua vez movimenta as nadadeiras do barco na água.

O controle é feito através da leitura de um **Sensor de pH**:
1.  **Leitura:** O Arduino lê o valor analógico do sensor (Porta A0).
2.  **Processamento:** O código verifica se a água está Ácida, Alcalina ou Neutra.
3.  **Atuação:**
    * **Água Contaminada (Ácida/Alcalina):** O motor para por segurança e LEDs de alerta (Vermelho/Azul) acendem.
    * **Água Neutra:** O sistema indica segurança (LEDs Verdes) e aciona o motor de passo para navegação.

## 📋 Componentes Utilizados

* Microcontrolador Arduino (Uno/Nano)
* Motor de Passo (28BYJ-48) + Driver ULN2003
* Sensor de pH Analógico
* LEDs indicadores (Vermelho, Azul, Verde)
* Estrutura do barco (Mecânica de elásticos e nadadeiras)

## 💻 Sobre o Código

O código foi desenvolvido em C++ utilizando a biblioteca `Stepper.h`. Ele possui uma lógica de decisão (`if/else`) calibrada para os valores brutos do sensor de pH, garantindo que o motor opere apenas dentro da faixa segura (pH Neutro).

---
*Projeto desenvolvido por [Seu Nome] - 2025*
