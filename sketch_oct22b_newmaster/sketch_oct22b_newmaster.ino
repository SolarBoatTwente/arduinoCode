// Wire Master Writer
#define BASE 112

#include <Wire.h>

int x = 0;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  Serial.println(slaveScanner());
}

word slaveScanner(){
  word slave;
  byte error, address;

  slave = 0;
  for(address = 112; address < 128; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      slave += 1 << (address -112); 
    }
  }

  return slave;
}



void loop() {
  
  x = 0;
  
  Wire.beginTransmission(BASE +1); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  Wire.beginTransmission((BASE+2));
  Wire.write(x);
  Wire.endTransmission();

  delay(100);
  

  
}
