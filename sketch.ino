/*
 * =========================================
 * Project : UART Serial Communication
 * Author  : Selvaraj S
 * Board   : Arduino Uno
 * Tool    : Wokwi Online Simulator
 * GitHub  : github.com/Selvaraja01
 * Date    : April 2026
 * =========================================
 * Description:
 * Demonstrates UART communication by sending
 * data through Serial Monitor and receiving
 * echo response with LED status indication.
 * =========================================
 */

// Pin Definitions
#define LED_PIN 13       // Built-in LED
#define BAUD_RATE 9600   // UART Baud Rate

// Variables
String receivedData = "";
int messageCount = 0;

void setup() {
  // Initialize UART
  Serial.begin(BAUD_RATE);
  
  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  // Startup message
  Serial.println("=====================================");
  Serial.println("  UART Communication Demo");
  Serial.println("  Author : Selvaraj S");
  Serial.println("  Board  : Arduino Uno");
  Serial.println("=====================================");
  Serial.println("System Ready! Type any message...");
  Serial.println();
}

void loop() {
  
  // ---- TRANSMIT: Send periodic status ----
  messageCount++;
  Serial.print("[TX] Status Message #");
  Serial.print(messageCount);

  Serial.println(" → Transmitted Successfully");
  
  // Blink LED to show transmission
  blinkLED(1);
  
  // ---- RECEIVE: Check incoming data ----
  if (Serial.available() > 0) {
    receivedData = Serial.readStringUntil('Hello Embedded\n');
    receivedData.trim();
    
    Serial.println("------------------------------");
    Serial.print("[RX] Received : ");
    Serial.println(receivedData);
    Serial.print("[RX] Length   : ");
    Serial.print(receivedData.length());
    Serial.println(" bytes");
    Serial.print("[RX] Echo Back: ");
    Serial.println(receivedData);
    Serial.println("------------------------------");
    
    // Blink LED 3 times on receive
    blinkLED(3);
  }
  
  delay(2000); // Wait 2 seconds before next transmission
}

// ---- Helper Function: Blink LED ----
void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}