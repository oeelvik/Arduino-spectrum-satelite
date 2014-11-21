#include <SatelliteReceive.h>
#include <Servo.h>

#define ledPin 13
SatelliteReceive reciver;
Servo myServo;
int time = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  myServo.attach(3);
}

void loop()
{
  if (Serial.available() > 0) {
    reciver.regByte(Serial.read());
  }
  /* Will fail after a while. Maby to high baudrate. Could use SoftwareSerial for this dump to pc.
  if(millis() - time > 100){
    Serial.print(reciver.getThro());
    Serial.print("\t");
    Serial.print(reciver.getAile());
    Serial.print("\t");
    Serial.print(reciver.getElev());
    Serial.print("\t");
    Serial.print(reciver.getRudd());
    Serial.print("\t");
    Serial.print(reciver.getGear());
    Serial.print("\t");
    Serial.print(reciver.getFlap());
    Serial.println();
  
    time = millis();
  }*/
  
  
  myServo.write(map(reciver.getAile(),RXMIN,RXMAX,0,179));
  
  if(reciver.getGear() > RXCENTER) digitalWrite(ledPin,1);
  else digitalWrite(ledPin,0);
  
}