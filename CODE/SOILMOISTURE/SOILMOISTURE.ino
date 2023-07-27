#define smpin A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(smpin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.println(moisture_percentage);
  delay(500);
  if(moisture_percentage <= 10){
    Serial.println("The Sensor is out of the soil");
    }
  else if(moisture_percentage >= 11 && moisture_percentage <= 50){
    Serial.println("Soil is Dry...Turn on the Sprinklers");
    }
  else
    Serial.println("Soil is Wet...Turn off the Sprinklers"); 
}
