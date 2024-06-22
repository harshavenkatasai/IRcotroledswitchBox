// #include <IRremote.h>

// #define IR_RECEIVE_PIN 8

// void setup() {
//   Serial.begin(9600);
//   IrReceiver.begin(IR_RECEIVE_PIN);
// }

// void loop() {
//   if (IrReceiver.decode()) {
//     IrReceiver.resume();
//     Serial.println(IrReceiver.decodedIRData.command);
//   }
// }

#include <IRremote.h>

#define IR_RECEIVE_PIN 8

#define IR_BUTTON_1 146
#define IR_BUTTON_2 147
#define IR_BUTTON_3 204
#define IR_BUTTON_4 142


#define RELAY1_PIN 9
#define RELAY2_PIN 10
#define RELAY3_PIN 11
#define RELAY4_PIN 12
#define DEFULT_PIN 3

byte relay1State = LOW;
byte relay2State = LOW;
byte relay3State = LOW;
byte relay4State = LOW;



void setup() {
  
  IrReceiver.begin(IR_RECEIVE_PIN);
  digitalWrite(RELAY1_PIN,HIGH);
  digitalWrite(RELAY2_PIN,HIGH);
  digitalWrite(RELAY3_PIN,HIGH);
  digitalWrite(RELAY4_PIN,HIGH);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    delay(500);
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1: {
        relay1State = (relay1State == LOW) ? HIGH : LOW;
        digitalWrite(RELAY1_PIN, relay1State);
        // delay(3000);
        break;
      }
      case IR_BUTTON_2: {
        relay2State = (relay2State == LOW) ? HIGH: LOW;
        digitalWrite(RELAY2_PIN, relay2State);
        // delay(3000);
        break;
      }
      case IR_BUTTON_3: {
        relay3State = (relay3State == LOW) ? HIGH: LOW;
        digitalWrite(RELAY3_PIN, relay3State);
        // delay(3000);
        break;
      }
      case IR_BUTTON_4: {
        relay4State = (relay4State == LOW) ? HIGH: LOW;
        digitalWrite(RELAY4_PIN, relay4State);
        break;
      }
      default: {
      }
    }
  }
}