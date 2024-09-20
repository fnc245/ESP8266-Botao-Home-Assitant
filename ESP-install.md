# Instalação do ESP8266 no Arduino IDE

Este guia explica como configurar o Arduino IDE para programar o ESP8266. 

## Pré-requisitos

* **Arduino IDE instalado:** Faça o download e instale a versão mais recente em [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software).
* **Conexão com a Internet:**  Você precisará baixar arquivos durante a instalação.

## Passo 1: Adicionar URL do Gerenciador de Placas ESP8266

1. **Abrir o Arduino IDE.**
2. **Acessar Preferências:** 
   - Vá em "Arquivo" > "Preferências" (Windows/Linux) 
   - Ou "Arduino" > "Preferences" (macOS)
3. **Localizar "URLs Adicionais de Gerenciadores de Placas":** Encontre o campo com este nome na janela de Preferências.
4. **Colar a URL:** Copie e cole a seguinte URL no campo:


https://arduino.esp8266.com/stable/package_esp8266com_index.json

- Se já houver outras URLs no campo, separe-as com vírgula.
5. **Salvar as Alterações:** Clique em "OK".

## Passo 2: Instalar o Pacote ESP8266

1. **Abrir o Gerenciador de Placas:** Vá em "Ferramentas" > "Placa" > "Gerenciador de Placas...".
2. **Buscar ESP8266:** Digite "ESP8266" na caixa de pesquisa e pressione Enter.
3. **Selecionar e Instalar:** 
- Selecione o pacote "esp8266" by ESP8266 Community.
- Clique em "Instalar". Aguarde o download e a instalação (pode levar alguns minutos).

## Passo 3: Selecionar a Placa ESP8266

1. **Menu "Placa":** Vá em "Ferramentas" > "Placa".
2. **Escolher Placa ESP8266:** 
- Encontre a seção "ESP8266 Boards".
- Selecione a placa específica que você está usando (ex: "Generic ESP8266 Module", "NodeMCU 1.0 (ESP-12E Module)", etc.).

## Passo 4: Configurar a Porta Serial

1. **Conectar o ESP8266:** Conecte o ESP8266 ao computador usando um adaptador USB-Serial.
2. **Identificar a Porta:** No Arduino IDE, vá em "Ferramentas" > "Porta".
3. **Selecionar a Porta Correta:** Selecione a porta que corresponde ao seu adaptador.

## Passo 5: Instalar Driver do Adaptador (se necessário)

- **Verificar o Chip do Adaptador:** A maioria usa o chip **CH340G**.
- **Baixar e Instalar o Driver:** Se necessário, baixe o driver CH340 de um site confiável e instale-o.


Agora você pode programar seu ESP8266 com o Arduino IDE! 

## Dicas Extras

- **Reinicie o IDE:**  Se as placas ESP8266 não aparecerem após a instalação, reinicie o Arduino IDE. 
- **Atualize o Arduino IDE:** Use a versão mais recente.
- **Documentação:** Consulte a documentação do seu modelo de ESP8266 para informações específicas.
