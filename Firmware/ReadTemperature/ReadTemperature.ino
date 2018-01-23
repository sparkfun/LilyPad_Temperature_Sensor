/*
LilyPad Temperature Sensor Example
SparkFun Electronics
https://www.sparkfun.com/products/8777

This code reads the input of the temperature sensor, converts it to Farenheit and Celsius
and prints to the Serial Monitor.

Temperature sensor connections:
   * S tab to A3
   * + tab to A5 (or +)
   * - tab to -

Follow the tutorial at:
https://learn.sparkfun.com/tutorials/lilypad-temperature-sensor-hookup-guide

This code is released under the MIT License (http://opensource.org/licenses/MIT)
******************************************************************************/

// Connect the S tab of the Temperature Sensor to A3
// If using the LilyPad ProtoSnap Plus, change to A9
 int sensorPin = A3;  

void setup()
{
  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);

  // Set pin A5 to use as a power pin for the light sensor
  // If using the LilyPad Development Board or the + tab for power, comment out these lines of code
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);

  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
}

void loop()
{
  // Variable to store raw temperature
  long rawTemp;

  // Variable to store voltage calculation
  float voltage;

  // Variable to store Fahrenheit value
  float fahrenheit;

  // Variable to store Celsius value
  float celsius;

  // Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);

  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (3.3V) and divide by maximum ADC value (1023).
  // If you plan on using this with a LilyPad Simple Arduino on USB power, change to 4.2
  voltage = rawTemp * (3.3 / 1023.0);
  Serial.print("Voltage: "); // Print voltage reading to serial monitor
  Serial.println(voltage);

  // Calculate the celsius temperature, based on that voltage..
  celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: "); // Print celcius temp to serial monitor
  Serial.println(celsius);

  // Use a common equation to convert celsius to Fahrenheit. F = C*9/5 + 32.
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print("Fahrenheit: "); // Print Fahrenheit temp to serial monitor
  Serial.println(fahrenheit); 
  // Print a blank line
  Serial.println();       

  // Wait 1 second between readings
  delay(1000);  
}
