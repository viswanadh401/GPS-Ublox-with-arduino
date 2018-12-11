String lat = "1234.7041778";
String longi = "12345.3966270";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
float x = lat.toFloat();
Serial.println(x);
float latitude = conv_coords(x);
Serial.println(String(latitude));
float y = longi.toFloat();
Serial.println(y);
float longitude = conv_coords(y);
Serial.println(String(longitude));
}

void loop() {
  // put your main code here, to run repeatedly:

}

float conv_coords(float in_coords)
 {
 //Initialize the location.
 float f = in_coords;
 // Get the first two digits by turning f into an integer, then doing an integer divide by 100;
 // firsttowdigits should be 77 at this point.
 int firsttwodigits = ((int)f)/100; //This assumes that f < 10000.
 Serial.println(firsttwodigits);
 float nexttwodigits = f - (float)(firsttwodigits*100);
 Serial.println(nexttwodigits);
 float theFinalAnswer = (float)(firsttwodigits + nexttwodigits/60.0);
 return theFinalAnswer;
 }


