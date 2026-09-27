<div align="center">

# 🏠 Home Automation Using Blynk IoT

### **Wi-Fi Based Smart Home Appliance Control using ESP8266**

[![Platform](https://img.shields.io/badge/Platform-ESP8266%20NodeMCU-blue?style=for-the-badge)](https://www.espressif.com/en/products/socs/esp8266)

[![IoT Platform](https://img.shields.io/badge/IoT-Blynk-green?style=for-the-badge)](https://blynk.io/)

[![Language](https://img.shields.io/badge/Language-Arduino%20C%2FC%2B%2B-orange?style=for-the-badge)](https://www.arduino.cc/)

[![Connectivity](https://img.shields.io/badge/Connectivity-Wi--Fi-blueviolet?style=for-the-badge)]()

[![Status](https://img.shields.io/badge/Status-Embedded%20IoT%20Project-success?style=for-the-badge)]()

</div>

---

# 📌 Overview

The **Home Automation Using Blynk IoT** project is a Wi-Fi-enabled embedded system that allows users to control electrical appliances remotely using a smartphone.

The system is built around the **ESP8266 NodeMCU** and the **Blynk IoT platform**.

The ESP8266 connects to a Wi-Fi network and communicates with the Blynk platform. The user can control connected appliances through buttons in the Blynk mobile application.

In this implementation, two relay channels are used to control two electrical loads such as:

* 💡 Light
* 🌀 Fan

The project demonstrates the integration of **embedded hardware, Wi-Fi communication, cloud-based IoT control and relay-based appliance switching**.

---

# 🎯 Objectives

The main objectives of this project are:

* Control electrical appliances remotely using a smartphone.
* Use ESP8266 as a Wi-Fi-enabled IoT controller.
* Interface relay modules with the microcontroller.
* Establish communication between ESP8266 and Blynk IoT.
* Control appliances using virtual buttons in the Blynk application.
* Understand the basic architecture of a Wi-Fi-based home automation system.

---

# ✨ Key Features

| Feature                   | Description                                                |
| ------------------------- | ---------------------------------------------------------- |
| 📱 **Smartphone Control** | Appliances can be controlled through the Blynk application |
| 📶 **Wi-Fi Connectivity** | ESP8266 provides wireless network connectivity             |
| ☁️ **Blynk IoT**          | Used as the IoT communication and control platform         |
| 🔌 **Relay Control**      | Two relay channels control electrical loads                |
| 💡 **Light Control**      | One relay can be assigned to a light                       |
| 🌀 **Fan Control**        | One relay can be assigned to a fan                         |
| ⚡ **Active-LOW Relays**   | Relay outputs are controlled using inverted logic          |
| 🔄 **Real-Time Control**  | Blynk commands are continuously processed by the ESP8266   |

---

# 🏗️ System Architecture

```text
                    ┌───────────────────┐
                    │    Smartphone     │
                    │   Blynk App       │
                    └─────────┬─────────┘
                              │
                              │ Internet
                              ▼
                    ┌───────────────────┐
                    │    Blynk Cloud     │
                    └─────────┬─────────┘
                              │
                              │ Wi-Fi
                              ▼
                    ┌───────────────────┐
                    │     ESP8266       │
                    │     NodeMCU       │
                    └─────────┬─────────┘
                              │
                    ┌─────────┴─────────┐
                    │                   │
                    ▼                   ▼
              ┌───────────┐       ┌───────────┐
              │  Relay 1  │       │  Relay 2  │
              └─────┬─────┘       └─────┬─────┘
                    │                   │
                    ▼                   ▼
                💡 Light              🌀 Fan
```

### Communication Flow

```text
User
  │
  ▼
Blynk Mobile App
  │
  ▼
Blynk Cloud
  │
  ▼
Wi-Fi
  │
  ▼
ESP8266
  │
  ├──────────────→ Relay 1 → Appliance 1
  │
  └──────────────→ Relay 2 → Appliance 2
```

---

# 🔧 Hardware Components

|  # | Component                  | Purpose                                 |
| -: | -------------------------- | --------------------------------------- |
|  1 | **ESP8266 NodeMCU**        | Main IoT controller and Wi-Fi interface |
|  2 | **2-Channel Relay Module** | Switches electrical loads               |
|  3 | **Light / Lamp**           | Example electrical appliance            |
|  4 | **Fan**                    | Example electrical appliance            |
|  5 | **Power Supply**           | Provides required power to the system   |
|  6 | **Smartphone**             | Provides remote user interface          |

---

# 🧠 Why ESP8266?

The **ESP8266** is suitable for IoT applications because it provides:

* Built-in Wi-Fi connectivity
* GPIO interfaces
* Microcontroller processing capability
* Serial communication
* Support for IoT libraries and platforms

In this project, the ESP8266 performs two main tasks:

```text
             ESP8266
                │
       ┌────────┴────────┐
       │                 │
       ▼                 ▼
   Wi-Fi Network      GPIO Control
       │                 │
       ▼                 ▼
 Blynk Communication   Relays
```

Therefore, it acts as both the **IoT communication controller** and the **appliance control unit**.

---

# ☁️ Blynk IoT

**Blynk** provides the user interface and communication layer for the project.

The user can create buttons in the Blynk application and assign virtual pins to different appliances.

In this project:

| Blynk Virtual Pin | Function        |
| ----------------- | --------------- |
| **V0**            | Relay 1 control |
| **V1**            | Relay 2 control |

The ESP8266 receives the button state from Blynk and changes the corresponding relay output.

---

# 🔌 Relay Interface

A relay allows a low-voltage microcontroller signal to control an electrical load.

The basic concept is:

```text
ESP8266 GPIO
     │
     ▼
Relay Module
     │
     ▼
Electrical Load
```

The relay provides electrical isolation between the control circuit and the switched load, depending on the relay module and wiring arrangement.

### Relay Connections

The current firmware uses:

```text
Relay 1 → D1
Relay 2 → D2
```

The source code defines:

```cpp
#define relay1 D1
#define relay2 D2
```

and configures both pins as outputs.

---

# ⚡ Active-LOW Relay Logic

The relay module used by the project is controlled using **active-LOW logic**.

That means:

```text
GPIO LOW  → Relay ON
GPIO HIGH → Relay OFF
```

The firmware initially sets both relay outputs HIGH:

```cpp
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
```

so that both relays start in the OFF state.

When a Blynk button changes state, the software uses inverted logic:

```cpp
digitalWrite(relay1, !state);
digitalWrite(relay2, !state);
```

This converts the Blynk button state into the active-LOW relay control signal.

---

# 📱 Blynk Control Logic

The Blynk application sends the appliance control state through virtual pins.

### Relay 1

```text
Blynk Button
     │
     ▼
Virtual Pin V0
     │
     ▼
BLYNK_WRITE(V0)
     │
     ▼
Read Button State
     │
     ▼
Invert State
     │
     ▼
ESP8266 D1
     │
     ▼
Relay 1
```

### Relay 2

```text
Blynk Button
     │
     ▼
Virtual Pin V1
     │
     ▼
BLYNK_WRITE(V1)
     │
     ▼
Read Button State
     │
     ▼
Invert State
     │
     ▼
ESP8266 D2
     │
     ▼
Relay 2
```

---

# 💻 Software Architecture

The project uses the following software components:

```text
                 Blynk Mobile App
                        │
                        ▼
                   Blynk Cloud
                        │
                        ▼
              BlynkSimpleEsp8266
                        │
                        ▼
                   ESP8266
                        │
             ┌──────────┴──────────┐
             │                     │
             ▼                     ▼
         BLYNK_WRITE(V0)      BLYNK_WRITE(V1)
             │                     │
             ▼                     ▼
          GPIO D1                GPIO D2
             │                     │
             ▼                     ▼
          Relay 1                Relay 2
```

---

# 🧩 Program Flow

The firmware follows this basic sequence:

```text
             POWER ON
                 │
                 ▼
       Configure Relay GPIOs
                 │
                 ▼
       Set Relays to OFF State
                 │
                 ▼
        Start Serial Communication
                 │
                 ▼
       Connect ESP8266 to Blynk
                 │
                 ▼
            Main Loop
                 │
                 ▼
           Blynk.run()
                 │
                 ▼
       Wait for Blynk Commands
                 │
        ┌────────┴────────┐
        │                 │
        ▼                 ▼
      V0 Change         V1 Change
        │                 │
        ▼                 ▼
     Relay 1            Relay 2
      Control            Control
```

---

# 🔄 Firmware Working

## 1. Initialization

During `setup()`:

* Relay pins are configured as outputs.
* Both relays are initially switched OFF.
* Serial communication is started.
* The ESP8266 connects to Blynk using the configured Wi-Fi credentials.

The source code uses:

```cpp
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);

digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);

Serial.begin(9600);

Blynk.begin(auth, ssid, pass);
```

---

## 2. Main Loop

The main loop continuously executes:

```cpp
Blynk.run();
```

This allows the ESP8266 to maintain communication with the Blynk platform and process incoming commands.

---

## 3. Relay 1 Control

The firmware handles Blynk virtual pin **V0** using:

```cpp
BLYNK_WRITE(V0)
```

The received button state is converted into the active-LOW relay signal and written to **D1**.

---

## 4. Relay 2 Control

Similarly, virtual pin **V1** controls the second relay:

```cpp
BLYNK_WRITE(V1)
```

The corresponding relay output is connected to **D2**.

---

# 🏠 Application Example

The two relay outputs can be assigned to household appliances as follows:

```text
                 ESP8266
                    │
          ┌─────────┴─────────┐
          │                   │
          ▼                   ▼
       GPIO D1             GPIO D2
          │                   │
          ▼                   ▼
       Relay 1              Relay 2
          │                   │
          ▼                   ▼
        LIGHT                FAN
```

From the smartphone:

```text
┌────────────────────────────┐
│       Blynk App             │
│                            │
│   💡 Light     [ ON/OFF ]  │
│                            │
│   🌀 Fan       [ ON/OFF ]  │
│                            │
└────────────────────────────┘
```

---

# 🔐 Wi-Fi and Blynk Credentials

The firmware requires three configuration values:

```cpp
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
```

These values are used by the ESP8266 to authenticate with Blynk and connect to the Wi-Fi network.

### ⚠️ Security Recommendation

Do **not** upload real:

* Wi-Fi passwords
* Blynk authentication tokens
* API keys
* Other private credentials

to a public GitHub repository.

For a public portfolio repository, use placeholders such as:

```cpp
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
```

and configure the actual credentials locally.

---

# 📁 Project Structure

The current repository is intentionally simple:

```text
Home-Automation-Using-Blynk-IOT/
│
├── README.md
│
└── WIFIModuleHomeAutomation.c
```

### `WIFIModuleHomeAutomation.c`

This file contains:

* ESP8266 Wi-Fi/Blynk libraries
* Blynk credentials placeholders
* Relay pin definitions
* GPIO initialization
* Blynk connection
* Main loop
* Relay 1 control
* Relay 2 control

---

# 🛠️ Software and Tools

| Tool / Technology   | Purpose                          |
| ------------------- | -------------------------------- |
| **ESP8266 NodeMCU** | IoT microcontroller              |
| **Arduino C/C++**   | Firmware development             |
| **Blynk IoT**       | Remote control platform          |
| **Wi-Fi**           | Wireless communication           |
| **Arduino IDE**     | Firmware development environment |
| **2-Channel Relay** | Appliance switching              |
| **Smartphone**      | User control interface           |

---

# 🧪 Testing

The system can be tested in the following sequence:

### Test 1 — Power ON

Verify that:

* ESP8266 powers up.
* Both relays initially remain OFF.

### Test 2 — Wi-Fi Connection

Verify that the ESP8266 successfully connects to the configured Wi-Fi network.

### Test 3 — Blynk Connection

Verify that the device connects to the Blynk platform.

### Test 4 — Relay 1

Press the Blynk button connected to **V0**.

Expected result:

```text
V0
 ↓
ESP8266
 ↓
D1
 ↓
Relay 1
 ↓
Load 1 changes state
```

### Test 5 — Relay 2

Press the Blynk button connected to **V1**.

Expected result:

```text
V1
 ↓
ESP8266
 ↓
D2
 ↓
Relay 2
 ↓
Load 2 changes state
```

---

# 🧠 Embedded & IoT Concepts Demonstrated

This project provides practical exposure to:

### Embedded Systems

* ESP8266 programming
* GPIO configuration
* Digital output control
* Relay interfacing

### IoT

* Wi-Fi connectivity
* Cloud-based communication
* Blynk IoT
* Remote device control

### Software

* Arduino C/C++
* Event-driven Blynk callbacks
* GPIO abstraction using macros
* Embedded control logic

### Hardware

* ESP8266 NodeMCU
* Relay modules
* Electrical load switching

---

# 📚 Learning Outcomes

Through this project, I gained practical understanding of:

* Using ESP8266 for IoT applications
* Connecting an embedded device to Wi-Fi
* Communicating with an IoT platform
* Using Blynk virtual pins
* Implementing callback functions
* Interfacing relay modules
* Understanding active-LOW digital logic
* Controlling appliances remotely
* Integrating hardware and cloud-based control

---

# 🚀 Possible Future Enhancements

The project can be extended with additional IoT features:

* 🌡️ Temperature and humidity monitoring
* 💡 Automatic light control using LDR
* 🚪 Door monitoring using sensors
* 🔔 Intrusion alerts
* 📊 Real-time sensor dashboard
* ⏰ Scheduled appliance control
* ⚡ Energy consumption monitoring
* 📱 Push notifications
* 🎙️ Voice-controlled appliances
* 🔐 Improved device authentication
* 🌐 Multiple-room appliance control

---

# 🌍 Real-World Applications

The same architecture can be adapted for:

* Smart homes
* Smart classrooms
* Smart offices
* Laboratory automation
* Remote appliance control
* IoT-based building automation
* Energy-management systems

---

# 🔭 Future System Architecture

A more advanced version could follow:

```text
             Sensors
                │
                ▼
          ┌───────────┐
          │ ESP8266   │
          └─────┬─────┘
                │
             Wi-Fi
                │
                ▼
          ┌───────────┐
          │ Blynk IoT │
          └─────┬─────┘
                │
        ┌───────┴────────┐
        │                │
        ▼                ▼
   Smartphone       Cloud Data
        │
        ▼
   User Control
        │
        ▼
      ESP8266
        │
        ▼
      Relays
        │
        ▼
     Appliances
```

This creates a complete IoT feedback and control architecture.

---

# ⚠️ Safety Note

When working with household AC appliances, the relay/load side can involve **dangerous mains voltage**.

For learning and testing:

* Prefer low-voltage DC loads.
* Use properly rated relay modules.
* Do not handle exposed mains connections while powered.
* Use appropriate electrical isolation and protection.
* Seek qualified supervision for mains-powered hardware.

---

# 👩‍💻 Project Focus

This project represents practical work in:

```text
Embedded Systems
       +
ESP8266
       +
Wi-Fi
       +
IoT
       +
Blynk
       +
GPIO
       +
Relay Interfacing
       =
Smart Home Automation
```

The main focus is understanding how an embedded controller can communicate over Wi-Fi and use cloud-based commands to control physical hardware.

---

# ⭐ Key Takeaway

The project demonstrates a complete basic IoT control path:

```text
Smartphone
    ↓
Blynk App
    ↓
Blynk Cloud
    ↓
Wi-Fi
    ↓
ESP8266
    ↓
GPIO
    ↓
Relay
    ↓
Electrical Appliance
```

This makes the project a practical example of combining **embedded programming, wireless communication and IoT-based automation**.

---

<div align="center">

### 🏠 ESP8266 | Wi-Fi | Blynk IoT | Embedded Systems

**Built as an Embedded IoT Home Automation Project**

</div>

