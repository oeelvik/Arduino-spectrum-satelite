int redLedPin = 13;

int prev;

void setup()  
{
  pinMode(redLedPin, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0) {
    int val = Serial.read();
    if(val == 0x01 && prev == 0x03){
      Serial.println();
    }
    Serial.print(val);
    Serial.print("\t");
    prev = val;
  }
}
