// Wire Slave Receiver


#include <Wire.h>

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  delay(20);

  int address = 127 - (digitalRead(9)*8 + digitalRead(10)*4 + digitalRead(11)*2 + digitalRead(12)*1); // 111 xxxx als adres
  
  Wire.begin(address);
  
  Wire.onReceive(receiveEvent); // register event
  pinMode(LED_BUILTIN, OUTPUT);           // LED
}

void loop() {
  ;
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent() {
  while (1 < Wire.available()) { // loop through all but the last
  }
  int x = Wire.read();    // receive byte as an integer


  if (x == 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(200);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(200);
  }
  
}
