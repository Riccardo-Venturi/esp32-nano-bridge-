# esp32-nano-bridge-
Il Nano 33 BLE Sense raccoglie dati dai sensori (IMU, temperatura, ...) e li invia via UART seriale all'ESP32. L'ESP32 riceve i dati, li stampa sul Serial Monitor via USB e — in futuro — li elabora per triggerare motori, loggarli su SD card o inviarli via WiFi/BLE. Un solo cavo USB al PC. La Nano è alimentata direttamente dall'ESP32 (pin VIN → 5V).
