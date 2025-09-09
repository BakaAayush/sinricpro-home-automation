# 🔌 ESP8266 + Sinric Pro Smart Home Automation

![Project Banner](./images/project_cover.png)

> **Control Home Appliances & LEDs Remotely using ESP8266, Sinric Pro, and a 4-Channel Relay!**  
Seamlessly integrate Google Assistant & Alexa to build a **smart home ecosystem** with IoT.

---

## 📌 Overview

This project demonstrates **home automation** using an **ESP8266 Wi-Fi module**, a **4-channel relay**, and **Sinric Pro** cloud integration.  
With this setup, you can **control LED bulbs, fans, or other devices** from anywhere using **voice commands** or the **Sinric Pro app**.

**Why Sinric Pro?**  
Unlike hardcoded Google APIs, Sinric Pro provides a **simple cloud interface** that connects your devices to **Alexa, Google Assistant, or custom apps**.

---

## ✨ Features

- 🌐 **Wi-Fi-Enabled Control** – Manage devices remotely.
- 🎙 **Voice Commands** – Works with Alexa & Google Assistant.
- ⚡ **Real-Time Switching** – Ultra-low latency via Sinric Pro.
- 🛡 **Safe Relay Control** – Opto-isolated 4-channel relay support.
- 🔄 **Expandable Design** – Can control up to 4 appliances.
- 📱 **Cross-Platform App Support** – Control from mobile or web.

---

## 🛠️ Hardware Components

| **Sl. No** | **Component**         | **Specification**            | **Quantity** | **Usage** |
|------------|----------------------|-------------------------------|--------------|-----------|
| 1 | ESP8266 (NodeMCU) | Wi-Fi-enabled microcontroller | 1 | Main IoT controller |
| 2 | 4-Channel Relay | 5V, opto-isolated | 1 | Switches AC/DC devices |
| 3 | LED Bulbs | 5V / 220V | 2 | Devices to be controlled |
| 4 | Resistors | 220Ω | 2 | Current limiting for LEDs |
| 5 | Breadboard | Medium-size | 1 | For prototyping |
| 6 | Jumper Wires | Male-to-Male | ~10 | Connections between components |
| 7 | Power Supply | 5V / USB | 1 | Powers ESP8266 and relay |

📄 [**Detailed Components List**](./BOM.docx)

---

## 🗺️ Circuit Diagram

![Circuit Diagram](./Circuit%20diagram.jpeg)

> ⚡ **Note:** Be careful when working with AC appliances. Always ensure proper insulation and safe handling.

---

## ⚙️ Setup & Installation

### **1. Clone the Repository**
```bash
git clone https://github.com/BakaAayush/sinricpro-home-automation.git
cd sinricpro-home-automation
