# IoT Temperature Alert System

## Table of Contents
- [Components/Software Required](#componentssoftware-required)
- [Pin Diagram](#pin-diagram)
- [Procedure](#procedure)
   - [1. Setup Arduino IDE and Install Libraries](#1-setup-arduino-ide-and-install-libraries)
   - [2. Connect Hardware Components](#2-connect-hardware-components)
   - [3. Configure Arduino IDE for NodeMCU](#3-configure-arduino-ide-for-nodemcu)
   - [4. Write and Upload Code](#4-write-and-upload-code)
   - [5. Setup ThingSpeak IoT Platform](#5-setup-thingspeak-iot-platform)
   - [6. Develop Mobile Application with MIT App Inventor](#6-develop-mobile-application-with-mit-app-inventor)
   - [7. Test the System](#7-test-the-system)
   - [8. Address Challenges and Debug](#8-address-challenges-and-debug)
- [Setup](#setup)
- [Screenshots](#screenshots)
  
# Components/Software Required

**Components:**
- NodeMCU ESP8266
- DHT11 Sensor
- Jumper Wires 
- Mobile Device for Testing
- USB Cable for NodeMCU
- Computer with Arduino IDE installed

**Software:**
- [Arduino IDE](https://www.arduino.cc/en/software) (Integrated Development Environment)
- DHT Sensor Library (for Arduino IDE)
- ThingSpeak Platform Account
- [MIT App Inventor](https://appinventor.mit.edu/explore/ai2/tutorials) (for mobile application development)

# Pin Diagram

![NodeMCU Pin Diagram](https://github.com/SreyaMynampati/Temperature-Alert-System/assets/143126242/181cd1f1-ab2a-44c3-bff6-21dcdd1f9455)

# Procedure

### 1. Setup Arduino IDE and Install Libraries:

- Download and install the [Arduino Software IDE](https://www.arduino.cc/en/software) on your computer.
- Open Arduino IDE and install the necessary libraries, including the DHT Sensor Library and ESP8266 WiFi Client, through the Library Manager.
- Ensure that the CP102x Driver Software is installed for NodeMCU compatibility.

### 2. Connect Hardware Components:

- Arrange the NodeMCU ESP8266, DHT11 sensor, and jumper wires on a breadboard.
- Connect the DHT11 sensor to the NodeMCU using jumper wires, ensuring proper pin connections.
- Use another set of jumper wires to connect the NodeMCU to the computer via USB for power and programming.

### 3. Configure Arduino IDE for NodeMCU:

- Open the Arduino IDE and select the appropriate board (NodeMCU ESP8266) and port from the Tools menu.
- Configure the IDE's board manager to download any required additional packages.

### 4. Write and Upload Code:

- Write the C code for the Temperature Alert System in the Arduino IDE.
- Ensure that the code includes instructions for reading sensor data, establishing WiFi connection, and MQTT communication with ThingSpeak.
- Compile the code and upload it to the NodeMCU ESP8266.

### 5. Setup ThingSpeak IoT Platform:

- Create an account on the [ThingSpeak](https://thingspeak.com/login?skipSSOCheck=true) IoT platform.
- Set up a new channel on ThingSpeak to receive and visualize temperature data.
- Obtain the ThingSpeak channel ID and API key.

### 6. Develop Mobile Application with MIT App Inventor:

- Access [MIT App Inventor](https://appinventor.mit.edu/explore/ai2/tutorials) and create a new project.
- Design the user interface to display temperature readings and alerts.
- Implement the MQTT protocol to receive real-time data from ThingSpeak.
- Program the app to trigger alerts when predefined temperature thresholds are exceeded.

### 7. Test the System:

- Power on the NodeMCU and ensure it connects to the WiFi network.
- Verify that temperature data is successfully sent to ThingSpeak and is visible on the platform's dashboard.
- Test the mobile application by running it on a mobile device.
- Simulate normal and high-temperature scenarios to confirm the app's alerting functionality.

### 8. Address Challenges and Debug:

- Address any recognition issues with libraries by periodically reinstalling them.
- Verify and use the correct versions of libraries to ensure smooth code execution.
- Troubleshoot and resolve any memory usage errors encountered during the implementation.
- Handle any malfunctions or issues with the DHT11 sensor.

# Setup

![NodeMCU Setup](https://github.com/SreyaMynampati/Temperature-Alert-System/assets/143126242/a33c6930-b229-48eb-8fc7-89b164329c2a)

# Screenshots
![Mobile App Screenshot](https://github.com/SreyaMynampati/Temperature-Alert-System/assets/143216212/79af8c00-8add-46e1-9ae4-e2a905d01a20)

By following these steps, you can effectively implement the Temperature Alert System using Arduino IDE, NodeMCU ESP8266, DHT11 sensor, ThingSpeak IoT platform, and MIT App Inventor, ensuring successful real-time temperature monitoring and alerting.
