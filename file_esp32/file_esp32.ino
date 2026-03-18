#define RXD2 16
#define TXD2 17

void setup() {
  Serial.begin(115200); // Al PC
  // Forziamo il baudrate della Serial2
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); 
  Serial.println("ESP32 AVVIATO E PRONTO A LEGGERE...");
}

void loop() {
  if (Serial2.available() > 0) {
    String msg = Serial2.readStringUntil('\n');
    msg.trim();
    if(msg.length() > 0) {
      Serial.print(">>> IL NANO DICE: ");
      Serial.println(msg);
    }
  }
}
