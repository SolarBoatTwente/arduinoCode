// Wire Master Writer
#define BASE 112

#include <Wire.h>

int x = 0;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  //Serial.println(slaveScanner());
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

      slave += 1 << (address -112);  // dit doet die 0000 0000 0000 0000 1'tjes zetten om aan te geven of apparaat 16 t/m 1 er is. 
    }
  }

  return slave;
}



void loop() {
  //Still have to implement slaves
  x = 0;
  
  Wire.beginTransmission(BASE +1); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  Wire.beginTransmission((BASE+2));
  Wire.write(x);
  Wire.endTransmission(); //Not difficult
  //delay to stop the system from over occupying the I2C bus

  delay(100);

  Wire.requestFrom(BASE + 2, 2);
    while (Wire.available()) {
      Serial.print("Device2= ");
      Serial.print("\t");
      int value = Wire.read();
      Serial.print(value);
      int value2 = Wire.read();
      Serial.print("\t");
      Serial.print(value2); 
      //Serial.print("\t");
      //float Vsens = value*(5.0/255.0)*(3900.0/(3900.0+4700.0));
      //Serial.print(Vsens);
      Serial.print("\n");
    }

  delay(500);

  
}
