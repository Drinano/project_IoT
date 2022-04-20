#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial SerialBT;

#define PINO_LED 2
#define PINO_RELE 12

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_RELE, OUTPUT);
 
  Serial.begin(115200); //Conexão entre notebook e ESP32 através da UART
  SerialBT.begin("ESP32-ADS"); // Nome do dispositivo Bluetooth
  Serial.println("Dispositivo iniciou, prossiga com o pareamento bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    char caractereBT = SerialBT.read();
    if (caractereBT=='D') {
      digitalWrite(PINO_LED, LOW);
      digitalWrite(PINO_RELE, HIGH);
      Serial.print("Comando <DESLIGAR> recebido: "); 
      Serial.println(caractereBT);
    } else if (caractereBT=='L') {
      digitalWrite(PINO_LED, HIGH); 
      digitalWrite(PINO_RELE, LOW);
      Serial.print("Comando <LIGAR> recebido: ");
      Serial.println(caractereBT);
    }
  }

  delay(20); // Pausa de 20 ms
}         
