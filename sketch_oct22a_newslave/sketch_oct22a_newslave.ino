// Wire Slave Receiver


#include <Wire.h>
#include <math.h>

int Vsens = 10;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(2, INPUT);
  pinMode(A7, INPUT);
  pinMode(A1, INPUT);
  delay(20);

  int address = 127 - (digitalRead(9)*8 + digitalRead(10)*4 + digitalRead(11)*2 + digitalRead(12)*1); // 111 xxxx als adres
  
  Wire.begin(address);

  
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent);
  
  pinMode(LED_BUILTIN, OUTPUT);           // LED
  
  Serial.begin(9600);
  
}

void loop() {
 ;
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent() {
   int x = B00000000;
   int y = B00000000;
   
  while (1 < Wire.available()) { // loop through all but the last
    x = Wire.read();    // receive byte as an integer
    y = Wire.read(); 
  }
  //int x = Wire.read();    // receive byte as an integer

  if (x == B00000000)
  {
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(200);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(200);
  }
  
  if (bitRead(y,7) == 1) //(y == B10000001)
  { 
    digitalWrite(2, HIGH);
  }
}


void requestEvent() {
 int Vsens1 = analogRead(A7);
 //Serial.print(Vsens);
// Serial.print("\t");
 //float testVsens = (1.725+1.850)/(1.725)*Vsens*(5.0/1023.0);
 //Serial.print(testVsens);
 //Serial.print("\t");
 Vsens1 = Vsens1 >> 2;
 //Serial.print(Vsens);
 //testVsens = (1.725+1.850)/(1.725)*Vsens*(5.0/255.0);
 //Serial.print("\t");
 //Serial.print(testVsens);
 //Serial.print("\n");
 //delay(100);
 Wire.write(Vsens1);
 int Vsens2 = analogRead(A1);
 Vsens2 = Vsens2 >> 2;
 Wire.write(Vsens2);
  

}
