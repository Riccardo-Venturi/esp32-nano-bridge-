unsigned long last_time = 0;
int counter = 0;

void setup() {
  // NIENTE "while(!Serial);" altrimenti si blocca per sempre!
  Serial1.begin(115200); // Questa è l'hardware UART sui pin TX(1) e RX(0)
}

void loop() {
  if (millis() - last_time >= 500) { 
    last_time = millis();
    String payload = "BATTITO CARDIACO: " + String(counter);
    
    // Spara i dati nel vuoto (o all'ESP32, se è collegato)
    Serial1.println(payload); 
    
    counter++;
  }
}
