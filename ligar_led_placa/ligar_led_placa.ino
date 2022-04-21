#define LED 2

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
 if (Serial.available()){
  String comando = Serial.readStringUntil('\n');

  if (comando == "ON"){
    digitalWrite(LED, HIGH);
    Serial.println("LED Ligado");
  }else if (comando == "OFF"){
    digitalWrite(LED, LOW);
    Serial.println("LED Desligado");
  }
 }
}
