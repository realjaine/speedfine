# 🚗 ESP32 Speed Detection & Automated Challan System

An IoT-based smart traffic monitoring system that detects vehicle speed using IR sensors and automatically issues challans via SMS and calls using Twilio API.

---

## 📌 Features

* 📡 Real-time speed detection using IR sensors
* 🚨 Buzzer alert system
* 📩 SMS alert for moderate violations
* 📞 Call alert for severe violations
* 📶 Wi-Fi enabled using ESP32
* 📟 Expandable to LCD / Cloud dashboard

---

## ⚙️ Working Principle

Two IR sensors are placed 25 cm apart.
The ESP32 calculates the time taken for a vehicle to travel between them.

[
Speed = \frac{Distance}{Time}
]

### Threshold Logic:

* ≤ 50 cm/s → Normal
* 50–100 cm/s → ₹500 fine (SMS)
* > 100 cm/s → ₹1000 fine (SMS + Call)

---

## 🧩 System Architecture

![System Architecture](docs/system_architecture.png)

---

## 🔄 Flowchart

![Flowchart](docs/flowchart.png)

---

## 🔌 Circuit Diagram

![Circuit](hardware/circuit_diagram.png)

---

## 🛠️ Hardware Components

* ESP32
* IR Break Beam Sensors (2)
* Buzzer
* Breadboard & Wires
* 16x2 LCD (optional)

---

## 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* Twilio Account

---

## 📂 Project Structure

```bash
📦 esp32-speed-detection-challan-system
 ┣ 📂 code
 ┃ ┣ main.ino
 ┃ ┣ twilio_handler.h
 ┃ ┗ config.h
 ┣ 📂 docs
 ┃ ┣ system_architecture.png
 ┃ ┣ flowchart.png
 ┃ ┗ results.png
 ┣ 📂 hardware
 ┃ ┗ circuit_diagram.png
 ┗ README.md
```

---

## 🔐 Setup Instructions

### 1. Clone Repository

```bash
git clone https://github.com/yourusername/esp32-speed-detection-challan-system
```

### 2. Add Credentials (`config.h`)

```cpp
#define WIFI_SSID "your_wifi"
#define WIFI_PASS "your_password"

#define ACCOUNT_SID "your_sid"
#define AUTH_TOKEN "your_token"

#define FROM_NUMBER "+1234567890"
#define TO_NUMBER "+91XXXXXXXXXX"
```

---

## 📡 Twilio Integration

* Uses Twilio REST API
* HTTPS POST requests from ESP32
* Basic Auth with Base64 encoding

### SMS Endpoint:

```
/Messages.json
```

### Call Endpoint:

```
/Calls.json
```

---

## 🚀 How It Works

1. Vehicle crosses Sensor 1 → Start timer
2. Vehicle crosses Sensor 2 → Stop timer
3. Speed calculated
4. Threshold check:

   * Medium → SMS sent
   * High → SMS + Call
5. Buzzer alerts locally

---

## 📊 Results

* Accurate speed detection (±5%)
* Instant alerts
* Reliable IoT communication

---

## 🔮 Future Improvements

* Number plate recognition (AI)
* Cloud dashboard
* Fine payment integration
* Traffic signal automation

---

## 📚 References

* Twilio API Docs
* ESP32 Documentation
* Arduino Reference

---

## 👨‍💻 Author

**Tanmay Jain**
B.Tech ECE
IIITDM Kurnool

---

## ⭐ If you like this project

Give it a ⭐ on GitHub!
