#include <Wire.h>                      //For I2C comms
#include <dht.h>                       //For temp and humidity sensor
#include <BH1750.h>                    //For light intensity 
#include <Adafruit_BMP085.h>           //For pressure
#define MQ2pin 12                      //For gas

float sensorValue;   //Took a variable to store the value of GAS

Adafruit_BMP085 bmp; //For Pressure 

dht DHT;             //For Temp

BH1750 lightMeter;   //For Light 

void setup(){
 
  Serial.begin(9600);
  delay(500);
  lightMeter.begin();
  bmp.begin();
}
 
void loop(){
 
    //FOR TEMPERATURE AND HUMIDITY
    DHT.read11(A0);
    Serial.print("Humidity:");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature:");
    Serial.print(DHT.temperature); 
    Serial.print("C  ");

    //FOR LIGHT INTENSITY
    float lux = lightMeter.readLightLevel();
    Serial.print("Light:");
    Serial.print(lux);
    
    //FOR PRESSURE
    float pressure=bmp.readPressure();
    Serial.print(" Pressure:");
    Serial.print(pressure/100);
    Serial.print("hPa ");
    
    //FOR GAS SENSOR
    sensorValue = analogRead(MQ2pin);  
    Serial.print("Sensor Value:");
    Serial.println(sensorValue);
   
    delay(1000);
 
 
}
