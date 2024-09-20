# MQTT2BotaoHA_V2 - Controle de Dispositivo com Botão via MQTT para Home Assistant

**Autor:** Francisco Neves ([fnc245@gmail.com](mailto:fnc245@gmail.com) - [francisco.bsb.br](http://francisco.bsb.br)) - Brasília/DF - Brasil

**Data:** 20/09/2024

**Versão:** 2.0

## Descrição

Este projeto transforma um ESP8266 ESP-01 em um dispositivo IoT que controla um botão físico e envia seu estado (ON/OFF) para o Home Assistant via MQTT. A cada pressionamento do botão, o estado é alternado e publicado no tópico MQTT definido, permitindo controlar dispositivos no Home Assistant.

## Funcionalidades

- Conexão à rede Wi-Fi.
- Conexão ao broker MQTT.
- Monitoramento do estado de um botão conectado ao GPIO0.
- Publicação do estado do botão ("ON" ou "OFF") no tópico MQTT "esp8266/interruptor1/state" a cada mudança de estado.

## Hardware Necessário

1. **ESP8266 ESP-01**
2. **Botão momentary (push-button)**
3. **Resistor de pull-up (4.7kΩ recomendado)**
4. **Adaptador USB-Serial** (com driver CH340 instalado - veja instruções de instalação abaixo)

## Esquema de Ligação

[Insira aqui uma imagem do esquema de ligação. Você pode usar o Fritzing ou desenhar à mão e tirar uma foto.]

**Exemplo de esquema usando o Fritzing:**

[![Esquema de ligação]](link-para-a-imagem-do-esquema.png)

## Instalação e Configuração

1. **Driver CH340:**
   - Baixe o driver CH340 para o seu sistema operacional em: [https://www.arduined.eu/ch340-windows-10-driver-download/](https://www.arduined.eu/ch340-windows-10-driver-download/) 
   - Instale o driver seguindo as instruções do site.

2. **Arduino IDE:**
   - Instale o Arduino IDE: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
   - Adicione o suporte ao ESP8266 no Arduino IDE (veja instruções detalhadas em: [link-para-tutorial-de-instalacao-do-ESP8266]).

3. **Configuração do Código:**
   - Abra o arquivo `MQTT2BotaoHA_V2.ino` no Arduino IDE.
   - **Credenciais de Wi-Fi:** 
     - Altere as variáveis `WIFISSID` e `WIDIPASS` com o nome e a senha da sua rede Wi-Fi.
   - **Credenciais do MQTT:** 
     - Altere as variáveis `mqttserver`, `mqttuser` e `mqttpass` com as credenciais do seu broker MQTT. 
   - **Tópico MQTT:**
     - O estado do botão será publicado no tópico `esp8266/interruptor1/state`. Ajuste se necessário. 

4. **Gravação no ESP-01:**
   - Conecte o ESP-01 ao adaptador USB-Serial.
   - No Arduino IDE, selecione a placa "Generic ESP8266 Module" e a porta serial correta.
   - Compile e grave o código no ESP-01.

## Utilização

1. **Conecte o ESP-01 à sua rede Wi-Fi.**
2. **Configure o Home Assistant:**
   - Crie uma automação no Home Assistant que seja acionada pelo tópico MQTT `esp8266/interruptor1/state`.
3. **Pressione o botão!** A cada pressionamento, o estado do dispositivo no Home Assistant deverá mudar.

## Personalização

- **Múltiplos Botões:** Você pode adaptar este código para usar mais botões. Adicione pinos GPIO, variáveis de estado e tópicos MQTT adicionais. 
- **Funcionalidades Extras:** Explore a adição de LEDs para indicar o estado do botão e da conexão, ou a integração com outros sensores e atuadores. 

## Licença

Este projeto é licenciado sob a licença [MIT](LICENSE).
