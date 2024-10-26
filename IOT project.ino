#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define RST_PIN 9  
#define SS_PIN 10  
#define BUZZER_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); 


const float fareCost = 2.0;


struct User {
  String uid;  
  float balance; 
};

User users[] = {
  {"Ram", 10.0}, 
  {"Sita", 5.0},   
  {"Hari", 1.0}    
};
int numUsers = sizeof(users) / sizeof(users[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.begin();
  lcd.backlight();
  
  pinMode(BUZZER_PIN, OUTPUT);
  
  lcd.print("Scan your card");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }


  String scannedUID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    scannedUID += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    scannedUID += String(rfid.uid.uidByte[i], HEX);
  }
  scannedUID.toUpperCase();
  

  bool userFound = false;
  for (int i = 0; i < numUsers; i++) {
    if (scannedUID == users[i].uid) {
      userFound = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("User found!");


      if (users[i].balance >= fareCost) {
        users[i].balance -= fareCost;  
        lcd.setCursor(0, 1);
        lcd.print("Payment Success!");
        tone(BUZZER_PIN, 1000, 200);  
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Insufficient Fund");
        tone(BUZZER_PIN, 500, 1000); 
      }
      

      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Balance: $");
      lcd.print(users[i].balance);
      delay(2000);
      break;
    }
  }

 
  if (!userFound) {
    lcd.clear();
    lcd.print("Card not found");
    tone(BUZZER_PIN, 500, 1000); 
    delay(2000);
  }


  lcd.clear();
  lcd.print("Scan your card");


  rfid.PICC_HaltA();
}
