const int travel = 409;

const int redLedPin = 13;


int channels[7];
int index = 0;
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
    
    //Detect headers/New data set
    if(val == 0x01 && prev == 0x03){
      Serial.print(channels[0]);
      Serial.print("\t");
      Serial.print(channels[1]);
      Serial.print("\t");
      Serial.print(channels[2]);
      Serial.print("\t");
      Serial.print(channels[3]);
      Serial.print("\t");
      Serial.print(channels[4]);
      Serial.print("\t");
      Serial.print(channels[5]);
      Serial.print("\t");
      Serial.print(channels[6]);
      Serial.println();
      analogWrite(3,map(channels[0],1024,2046,0,179));
      if(channels[5] > 4607) digitalWrite(redLedPin,1);
      else digitalWrite(redLedPin,0);
      
      index = 0;
    }
    else { //Register value to apropriate channel
      
      switch(index){
        case 0:
          channels[0] = val * 256;
          break;
        case 1:
          channels[0] = channels[0] + val;
          break;
        case 2:
          channels[1] = val * 256;
          break;
        case 3:
          channels[1] = channels[1] + val;
          break;
        case 4:
          channels[2] = val * 256;
          break;
        case 5:
          channels[2] = channels[2] + val;
          break;
        case 6:
          channels[3] = val * 256;
          break;
        case 7:
          channels[3] = channels[3] + val;
          break;
        case 8:
          channels[4] = val * 256;
          break;
        case 9:
          channels[4] = channels[4] + val;
          break;
        case 10:
          channels[5] = val * 256;
          break;
        case 11:
          channels[5] = channels[5] + val;
          break;
        case 12:
          channels[6] = val * 256;
          break;
        case 13:
          channels[6] = channels[6] + val;
          break;
        default:
          break;
      }
      
      
      
      prev = val;
      index++;
    }
    
    //Serial.print(val, HEX);
    //Serial.print("\t");
    
  }
}
