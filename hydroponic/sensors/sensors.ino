//note this temp sensor and ph sensor is calibrated for our specfic
//ds18b20 & ph sensors respectively
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>

int temp_sensor = 5; // pin ds18b20 sensor is connected
float temperatureC = 0; // variable to store the temperature in
float temperatureF = 0; // for farenheit
int lowerLimit = 15; // define the lower threshold for the temperature
int higherLimit = 35; //define the upper threshold for the temp

OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  Serial.print("Requesting Temperatures from sensors: ");
  sensors.requestTemperatures();
  Serial.println("DONE");
  temperatureC = sensors.getTempCByIndex(0);
  temperatureF = sensors.getTempFByIndex(0);
  Serial.println("Temperature in Celcius is");
  Serial.println(temperatureC);
  Serial.println("Temperature in Fahrenheit is");
  Serial.println(temperatureF);
  delay(1000);
}
