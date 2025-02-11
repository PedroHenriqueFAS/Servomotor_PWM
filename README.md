# Servomotor_PWM

## 📝 Sobre o Projeto

Este programa utiliza o Raspberry Pi Pico para controlar um servomotor por meio de um sinal PWM (Pulse Width Modulation). O servo é movimentado para três posições iniciais (180°, 90° e 0°) e, em seguida, oscila suavemente entre 0° e 180° continuamente.

## 🎯 Funcionalidades

1. Inicializa a comunicação serial para depuração.

2. Configura o pino 22 para operação PWM com uma frequência de 50Hz.

3. Move o servo para três posições fixas: 180°, 90° e 0°, com um intervalo de 5 segundos entre cada movimento.

4. Inicia uma movimentação suave e contínua do servo entre 0° e 180°, ajustando gradualmente o ciclo de trabalho do PWM.

## 📂 Estrutura do Projeto

O projeto é composto pelos seguintes arquivos principais:

- `Servomotor.c`: Contém a lógica principal do sistema.
- `CMakeLists.txt`: Arquivo de configuração do CMake para compilação do projeto.
- `diagram.json`: Arquivo utilizado para simular o hardware.

## 📂 Estrutura do Código

- `pwm_setup(uint gpio)`: Configura o pino especificado para operação PWM.

- `set_servo_position(uint gpio, uint16_t duty_cycle_us)`: Define a posição do servo com base no ciclo de trabalho do PWM.

- `main()`: Executa a sequência de movimentação do servo.

## 🛠️ Requisitos

- Raspberry Pi Pico W
- Servomotor
- Fonte de alimentação apropriada
- Fios de conexão
- SDK do Pico instalado
- CMake
- Compilador compatível com C e C++

## ✔️ Ligações

- O pino do sinal do servo deve ser conectado ao GPIO 22 do Raspberry Pi Pico.

- O pino de alimentação do servo (“VCC”) deve ser conectado a 3.3V, conforme especificações do servo.

- O pino GND do servo deve ser conectado ao GND do Raspberry Pi Pico.

## ⚙️ Compilação e Execução

1. Clone o repositório do projeto:
   ```sh
   git clone https://github.com/PedroHenriqueFAS/Servomotor_PWM
   cd Temporizador_Periodico
   ```
2. Crie um diretório de build e entre nele:
   ```sh
   mkdir build
   cd build
   ```
3. Execute o comando CMake para configurar a compilação:
   ```sh
   cmake ..
   ```
4. Compile o projeto:
   ```sh
   make
   ```
5. Faça o upload do binário gerado para a Raspberry Pi Pico.

## 🔎 Observação

Caso queira usar o LED RGB interno da placa no lugar do servo, basta substituir:
```
#define PWM_SERVO 22
```

por
```
#define PWM_SERVO 12
```

No entanto, ao substituir pelo LED interno da placa, é possível observar variações na intensidade da iluminação, pois o sinal PWM afeta seu brilho de maneira diferente em comparação ao controle de um servomotor.

## ▶️ Compilação e Execução

Para compilar e rodar o código no Raspberry Pi Pico:

1. Instale o SDK do Raspberry Pi Pico.

2. Compile o programa com o CMake e o GCC.

3. Carregue o arquivo .uf2 gerado na placa Pico conectada via USB.

## 👥 Colaboradores

1. **Pedro Henrique Ferreira Amorim da Silva** - [GitHub](https://github.com/PedroHenriqueFAS)

## 🎥 Vídeo Ensaio

- `Link`: https://youtube.com/shorts/s_YQZdhLbGE?si=6k_QyQe1CEHGXqHc

## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Para mais detalhes, consulte o arquivo LICENSE.

