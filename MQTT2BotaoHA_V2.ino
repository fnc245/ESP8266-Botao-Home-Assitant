//*************************************************************** 
// MQTT2BotaoHA_V2
// 
// Controle de Dispositivo com Botão via MQTT para Home Assistant
// 
// Por: Francisco Neves - fnc245@gmail.com - francisco.bsb.br
// Brasilia DF Brasil
// Data: 20/09/2024
// Versão: 2.0
// 
// Descrição:
// Este programa transforma um ESP8266 ESP-01 em um 
// dispositivo IoT que controla um botão físico e envia 
// seu estado (ON/OFF) para o Home Assistant via MQTT. 
//
// Funcionalidades:
// - Conecta à rede Wi-Fi.
// - Conecta ao broker MQTT.
// - Monitora o estado de um botão conectado ao GPIO0.
// - Publica o estado do botão ("ON" ou "OFF") no tópico 
//   MQTT "esp8266/interruptor1/state" a cada mudança de estado.
//
// Hardware Necessário:
// - ESP8266 ESP-01
// - Botão momentary (push-button)
// - Resistor de pull-up (4.7kΩ recomendado)
// - Adaptador USB-Serial (com driver CH340 instalado)
//
// Observações:
// - Adapte as credenciais de Wi-Fi (SSID e senha) e 
//   MQTT (servidor, usuário, senha) no código.
// - Certifique-se de que o Home Assistant esteja configurado 
//   para receber as mensagens no tópico MQTT definido. 
//*************************************************************** 

#include <PubSubClient.h>
#include <ESP8266WiFi.h>

//Informações do WiFi
#define WIFISSID "<SSID>"
#define WIDIPASS "<WiFi PASSWORD>"

//MQTT SERVER INFO
const char* mqttserver = "<SERVER MQTT>";
int mqttserverport = <1883 or other PORT>;
const char* mqttuser = "<USER MQTT>";
const char* mqttpass = "<PASSWORD MQTT>";

//Vars
WiFiClient wifiClient;
PubSubClient ConexaoMQTT(wifiClient);
int UltimoValor = 0;

//PinOuts
const int PINbotao = 0;

void reconnect() {
  ConexaoMQTT.setServer(mqttserver, mqttserverport);
  while (!ConexaoMQTT.connected()) {
    ConexaoMQTT.connect("esp8266_V2",mqttuser,mqttpass);
    delay(10);
  }

}

void setup() {
  delay(1000);
//  IPAddress ip(192, 168, 89, 155); // Omited to use DHCP
//  IPAddress gateway(192, 168, 89, 1);
//  IPAddress subnet(255, 255, 255, 0);
//  IPAddress dns(192, 168, 89, 1);
//  WiFi.config(ip, dns, gateway, subnet);
  WiFi.begin(WIFISSID, WIDIPASS);
  delay(5000);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);

  }

  if (!ConexaoMQTT.connected()) {
    reconnect();
  }
  
  pinMode(PINbotao, INPUT); 

  //First Read
  int LeituraSwitchD1Pin = digitalRead(PINbotao);
  delay(100);

  if (LeituraSwitchD1Pin == 0) {
    UltimoValor = LeituraSwitchD1Pin;
    ConexaoMQTT.publish("esp8266/interruptor1/state","LOW");
  } else if (LeituraSwitchD1Pin == 1) {
    UltimoValor = LeituraSwitchD1Pin;
    ConexaoMQTT.publish("esp8266/interruptor1/state","HIGH");
  }
}

void loop() {

  
  int LeituraSwitchD1Pin = digitalRead(PINbotao);

  if (LeituraSwitchD1Pin != UltimoValor) {
    if (!ConexaoMQTT.connected()) {
      reconnect();
    }

    if (LeituraSwitchD1Pin == 0) {
      UltimoValor = LeituraSwitchD1Pin;
      ConexaoMQTT.publish("esp8266/interruptor1/state","LOW");
    } else if (LeituraSwitchD1Pin == 1) {
      UltimoValor = LeituraSwitchD1Pin;
      ConexaoMQTT.publish("esp8266/interruptor1/state","HIGH");
    }
  }

  delay(100);
}