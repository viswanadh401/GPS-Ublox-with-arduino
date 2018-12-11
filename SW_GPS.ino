#include <SoftwareSerial.h>

SoftwareSerial swSer(10, 11);

String inputString = "";
String lat = "";
String longi = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  swSer.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (swSer.available() > 0)
  {
    delay(5);
    char inChar = swSer.read();
    if (inChar == '$')
    {
      delay(5);
      //Serial.print(inChar);
      inChar = swSer.read();
      if (inChar == 'G')
      {
        delay(5);
        //Serial.print(inChar);
        inChar = swSer.read();
        if (inChar == 'P')
        {
          delay(5);
          //Serial.print(inChar);
          inChar = swSer.read();
          if (inChar == 'R')
          {
            delay(5);
            Serial.print(inChar);
            inChar = swSer.read();
            if (inChar == 'M')
            {
              delay(5);
              Serial.print(inChar);
              inChar = swSer.read();
              if (inChar == 'C')
              {
                delay(5);
                Serial.print(inChar);
                inChar = swSer.read();
                if (inChar == ',')
                {
                  delay(5);
                  Serial.print(inChar);
                  //Serial.println("READ_GPS"); //$GPRMC,225446,A,4916.45,N,12311.12,W,000.5,054.7,191194,020.3,E*68
                  inChar = swSer.read();
                  while (inChar != '*')
                  {
                    delay(5);
                    inChar = swSer.read();
                    //Serial.print(inChar);
                    inputString += inChar;
                  }
                  Serial.println(inputString);
                  String lat = getValue(inputString, ',', 2);
                  String longi = getValue(inputString, ',', 4);
                  Serial.print("latitude is: ");
                  Serial.print(lat);
                  Serial.print("longitude is: ");
                  Serial.print(longi);
                  inputString = "";
                  Serial.println();
                }
              }
            }
          }
        }
      }
    }
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

