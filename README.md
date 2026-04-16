# 🚗 Automated Speed Violation Detection & Challan System

> Microprocessors and Microcontrollers Practice (EC255)

---

## 👨‍🏫 Instructor

**Dr. MOHAMED ASAN BASIRI M**

---

## 👨‍💻 Author

**Tanmay Jain**
B.Tech – Electronics and Communication Engineering
IIITDM Kurnool

---

## 📌 Project Overview

This project presents an **IoT-based automated traffic monitoring system** using ESP32 that detects vehicle speed and issues challans via SMS and calls using Twilio API.

The system eliminates manual monitoring and ensures **real-time enforcement of speed limits**.

---

## 🎯 Objectives

* Measure vehicle speed using IR sensors
* Detect over-speeding in real time
* Trigger local alerts (buzzer)
* Send automated SMS and call notifications
* Build a scalable smart traffic solution

---

## ⚙️ System Description

Two IR sensors are placed at a fixed distance (25 cm).
The ESP32 records the time difference between detections and calculates speed.

### 📐 Formula Used

[
Speed = \frac{Distance}{Time}
]

---

## 🚦 Speed Classification

| Speed Range   | Action                  |
| ------------- | ----------------------- |
| ≤ 50 cm/s     | Normal                  |
| 50 – 100 cm/s | SMS Alert (₹500 Fine)   |
| > 100 cm/s    | SMS + Call (₹1000 Fine) |

---

## 🧩 System Architecture

![Architecture](docs/system_architecture.png)

---

## 🔄 Flowchart

![Flowchart](docs/flowchart.png)

---

## 🔌 Circuit Diagram

![Circuit](hardware/circuit_diagram.png)

---

## 🛠️ Hardware Components

* ESP32 Microcontroller
* IR Break Beam Sensors (x2)
* Buzzer
* Breadboard & Jumper Wires
* 16×2 LCD (optional)

---

## 💻 Software & Tools

* Arduino IDE
* ESP32 Board Package
* Twilio API
* Libraries:

  * WiFi.h
  * HTTPClient.h
  * WiFiClientSecure.h

---

## 📂 Repository Structure

```bash
📦 esp32-speed-detection-challan-system
 ┣ 📂 code
 ┃ ┣ main.ino
 ┃ ┣ config.h
 ┃ ┣ twilio_handler.h
 ┣ 📂 docs
 ┃ ┣ system_architecture.png
 ┃ ┣ flowchart.png
 ┣ 📂 hardware
 ┃ ┗ circuit_diagram.png
 ┗ README.md
```

---

## 🔐 Setup Instructions

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/yourusername/esp32-speed-detection-challan-system
```

### 2️⃣ Configure Credentials

Edit `config.h`:

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
* Basic Authentication (Base64 encoded)

### Endpoints Used:

* `/Messages.json` → SMS
* `/Calls.json` → Voice Call

---

## 🚀 Working Flow

1. Vehicle crosses Sensor 1 → Timer starts
2. Vehicle crosses Sensor 2 → Timer stops
3. Speed calculated
4. Condition check:

   * Medium violation → SMS
   * Severe violation → SMS + Call
5. Buzzer alert triggered

---

## 📊 Results

* Accurate speed detection (~±5%)
* Instant alert system
* Reliable wireless communication

---

## 🔮 Future Scope

* License Plate Recognition (AI)
* Cloud Dashboard Integration
* Automated Fine Payment System
* Smart Traffic Signal Control

---

## 📚 References

* Twilio API Documentation
* ESP32 Technical Manual
* Arduino Documentation

---

## 🙌 Acknowledgement

I would like to thank **Dr. MOHAMED ASAN BASIRI M** for guidance and support throughout this project.

---

## ⭐ Support

If you found this useful, consider giving it a ⭐ on GitHub!
