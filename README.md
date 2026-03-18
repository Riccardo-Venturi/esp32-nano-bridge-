# esp32-nano-bridge 🔌

> **IT**: Ponte seriale tra Arduino Nano 33 BLE Sense e ESP32 — un cavo USB, due cervelli.  
> **EN**: Serial bridge between Arduino Nano 33 BLE Sense and ESP32 — one USB cable, two brains.

---

## Demo

<!-- Sostituisci con la tua GIF! -->
![demo](demo.gif)
!da caricare!
---

## 🇮🇹 Italiano

### Cosa fa
Il **Nano 33 BLE Sense** raccoglie dati dai sensori (IMU, temperatura, microfono...) e li invia via **UART seriale** all'**ESP32**.  
L'ESP32 riceve i dati, li stampa sul Serial Monitor via USB e — in futuro — li elabora per triggerare motori, loggarli su SD card o inviarli via WiFi/BLE.

Un solo cavo USB al PC. La Nano è alimentata direttamente dall'ESP32 (pin VIN → 5V).

### Schema di collegamento

```
Arduino Nano 33 BLE Sense        ESP32
─────────────────────────        ─────
TX1  (pin 1)          ──────►   GPIO16  (RXD2)
GND                   ──────►   GND
VIN                   ◄──────   5V / VIN
```

> ⚠️ Usa **VIN** sulla Nano (non il pin 3.3V!) — passa per il regolatore onboard e protegge la logica 3.3V.

### Come flashare

#### Prerequisiti
```bash
# arduino-cli
arduino-cli core install esp32:esp32
arduino-cli core install arduino:mbed_nano

# Se l'ESP32 aveva MicroPython → cancella il flash prima!
pip install esptool --break-system-packages
esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
```

#### Trovare le porte
```bash
ls /dev/ttyUSB* /dev/ttyACM*
# oppure con info estese:
ls -la /dev/serial/by-id/
```

Di solito:
- `ttyACM0` → Nano 33 BLE Sense
- `ttyUSB0` → ESP32 (chip CP2102/CH340)

#### Compile & Upload

```bash
# ESP32
arduino-cli compile --fqbn esp32:esp32:esp32 ./esp32/
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 ./esp32/

# Nano 33 BLE Sense
arduino-cli compile --fqbn arduino:mbed_nano:nano33ble ./nano/
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:mbed_nano:nano33ble ./nano/
```

#### Monitor seriale
```bash
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=115200
```

### Struttura repo
```
esp32-nano-bridge/
├── esp32/
│   └── esp32_receiver.ino      # Riceve da Nano, stampa al PC
├── nano/
│   └── nano_sender.ino         # Legge sensori, invia a ESP32
├── demo.gif
└── README.md
```

### Roadmap
- [x] Comunicazione seriale Nano → ESP32 funzionante
- [ ] Invio dati IMU/accelerometro (LSM9DS1 onboard)
- [ ] Trigger motori/attuatori basato su soglie
- [ ] Logging su SD card via ESP32
- [ ] Invio dati via WiFi (MQTT o HTTP)

---

## 🇬🇧 English

### What it does
The **Nano 33 BLE Sense** reads onboard sensor data (IMU, temperature, microphone...) and sends it over **UART serial** to the **ESP32**.  
The ESP32 receives the data, prints it to the Serial Monitor over USB, and — in the future — processes it to trigger motors, log to SD card, or transmit via WiFi/BLE.

Single USB cable to PC. The Nano is powered directly by the ESP32 (VIN pin → 5V).

### Wiring

```
Arduino Nano 33 BLE Sense        ESP32
─────────────────────────        ─────
TX1  (pin 1)          ──────►   GPIO16  (RXD2)
GND                   ──────►   GND
VIN                   ◄──────   5V / VIN
```

> ⚠️ Use **VIN** on the Nano (not the 3.3V pin!) — it goes through the onboard regulator and protects the 3.3V logic.

### Flashing

#### Prerequisites
```bash
arduino-cli core install esp32:esp32
arduino-cli core install arduino:mbed_nano

# If ESP32 had MicroPython → erase flash first!
pip install esptool --break-system-packages
esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
```

#### Find ports
```bash
ls /dev/ttyUSB* /dev/ttyACM*
ls -la /dev/serial/by-id/
```

Typically:
- `ttyACM0` → Nano 33 BLE Sense
- `ttyUSB0` → ESP32 (CP2102/CH340 chip)

#### Compile & Upload

```bash
# ESP32
arduino-cli compile --fqbn esp32:esp32:esp32 ./esp32/
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 ./esp32/

# Nano 33 BLE Sense
arduino-cli compile --fqbn arduino:mbed_nano:nano33ble ./nano/
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:mbed_nano:nano33ble ./nano/
```

#### Serial monitor
```bash
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=115200
```

### Roadmap
- [x] Serial communication Nano → ESP32 working
- [ ] Stream IMU/accelerometer data (LSM9DS1 onboard)
- [ ] Trigger motors/actuators based on thresholds
- [ ] Log data to SD card via ESP32
- [ ] Transmit data over WiFi (MQTT or HTTP)

---

## Hardware

| Board | Role | Port |
|-------|------|------|
| Arduino Nano 33 BLE Sense | Sensor node / transmitter | `ttyACM0` |
| ESP32 (CP2102) | Gateway / receiver | `ttyUSB0` |

---

*Built with ☕ and a data-only USB cable.*
