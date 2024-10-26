# Transportation Payment Gateway through RFID Card

## Overview
The Transportation Payment Gateway through RFID Card is an IoT-based project that uses RFID (Radio-Frequency Identification) technology for a seamless payment experience in transportation systems. This gateway system reads RFID cards (such as smart travel cards) using an Arduino microcontroller and displays the status on an LCD screen. It can be integrated into public transportation systems to automate fare collection, enhancing convenience and security for both passengers and operators.This project prototype is created using Fritzing to illustrate the circuit connections and component layout.

## Components
- Arduino Uno: The microcontroller that processes RFID data and controls other components.
- RFID Reader Module (RC522): Reads unique RFID card IDs when the card is brought close to the reader.
- 16x2 LCD Display: Displays transaction status, such as card information and payment confirmation.
- Buzzer: Provides audio feedback when the RFID card is scanned (e.g., a beep for successful transactions).
- Jumper Wires: Connects the components on the breadboard or PCB to form the circuit.


## Prototype
![image](https://github.com/user-attachments/assets/d128de2a-89ab-44af-b58c-50512d34f81a)

The above prototype illustrates the circuit design for the RFID-based payment gateway:
- RFID Reader Module (RC522): Connected to the Arduino to capture the card's unique ID.
- Arduino Uno: Controls the RFID reader, LCD, and buzzer.
- LCD Display: Displays messages such as "e-Radionica.com" and other transaction details.
- Buzzer: Provides audio feedback when an RFID card is detected.

## Technical Diagram
![image](https://github.com/user-attachments/assets/b4e23f70-c3d5-4ddc-99f0-5db38be1fac4)



