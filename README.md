# 🏠 Smart-Home Automation System

This project automates home appliances using **Arduino Uno, DHT11, LDR, Ultrasonic Sensor, ESP32 and a Relay Module**. The system controls fans, lights, and other devices based on environmental conditions and can be integrated with a mobile app or web dashboard.

## 📌 Features:
✅ **Temperature-based Fan Control**: Turns ON/OFF automatically based on room temperature.  
✅ **Light Automation**: Controls LED based on light intensity (LDR) and object detection.  
✅ **Object-based Automation**: Uses an Ultrasonic Sensor to detect motion and activate devices.  
✅ **Wireless Control**: Supports IoT integration for remote access.  
✅ **Manual Override**: Users can turn devices ON/OFF via a mobile app or web interface.  

## 🛠️ Hardware Components:
- **Microcontroller**: Arduino Uno / NodeMCU (for IoT version)
- **Sensors**: DHT11 (Temperature), LDR (Light), Ultrasonic Sensor (Motion)
- **Actuators**: Relay Module, Fan, LED Bulb
- **Connectivity**: Wi-Fi Module (ESP8266 for IoT)
- **Power Supply**: 5V/12V as required

## 🏗️ Circuit Diagram:
![circuit Diagram](https://github.com/saaranshg/Smart-Home/blob/main/Circuit%20Diagram.png)
## 🛠️ How It Works

1. **Temperature-Based Fan Control**  
   - If room temperature **exceeds 29°C**, the **fan automatically turns ON**.  
   - If the temperature **drops below the threshold**, the **fan turns OFF**.  

2. **Light Automation with LDR**  
   - If the **room is dark**, the **LED turns ON** automatically.  
   - If the **light level is sufficient**, the **LED remains OFF**.  

3. **Ultrasonic Sensor for Object Detection**  
   - If an object is detected **within 15 cm**, the **LED turns ON**.  
   - The **fan can also turn ON** if movement is detected.  

---

## 📸 Proof of Working  


![Prototype](https://github.com/user-attachments/assets/874e5270-61c7-4042-8fff-cfb92aebdc8c)

![Prototype Working](https://github.com/user-attachments/assets/1ce2dabd-b450-4b50-9a86-a783694ce689)


### 🎥 Demo Video  
🎥 [Watch the Project in Action](https://drive.google.com/file/d/1V5BEhOe6beoYtIyCD-7tCvfB_LDa67dM/view?usp=sharing)


---
