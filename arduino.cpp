#include <Servo.h>
#define DHTPIN 2
// dht pin is connected to pin 2
#define DHTTYPE DHT11
// Includes libraries to run DHT,soil moisture sensor respectively
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
Servo myservo;
float moist;
float permoist;
float d;
DHT_Unified dht(DHTPIN, DHTTYPE);
void myTimerEvent()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event); // Reads the temperature of air
    Serial.print("Temperature: ");
    int temp = int(event.temperature); // Stores temperature for further calculations
    Serial.print(event.temperature);   // Sends temperature to display in serial monitor.
    Serial.println(" C");
    dht.humidity().getEvent(&event); // Reads humidity of the air
    Serial.print("Relative Humidity:");
    double hum = double(event.relative_humidity); // Stores humidity as a double value for further
    calculations
        Serial.print(hum); // Sends humidty to display in serial monitor.
    Serial.println("%");
    Serial.println("\n\n\n");
    moist = analogRead(A0); // Reading soil resistance and storing as moist
    Serial.print(moist);
    Serial.print('\t');
    permoist = (1023 - moist) * 100 / 1023; // Calculating the percentage-moisture present in
    soil and storing it as permoist
        Serial.println(permoist);
    // Sends Percentage-moisture to display in dashboard.
    int diff = permoist - 35; // Calculates difference between current moisture level and
minimum level of moisture needed for plant growth
 int hours = 0;
// Code calculates the number of hours where the moisture levels remain in healthy conditions
// Constants are obtained by linear regression
if (diff > 0) // if diff is < 0 it means less moisture so should be watered
{
    myservo.write(90); // servo position
    if (hum > 80)
    {
        if (temp < 20)
        {
            hours = diff / (0.018 * temp);
            if (hours > 48)
            {
                hours = 48; // Even though time required is more than 48 hours but initialise it to 48
                because we need to check again after 48 hours
                    Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 20 && temp < 23)
        {
            hours = diff / (0.022 * temp);
            if (hours > 48)
            {
                hours = 48;

                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            Else
            {

                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 23 && temp < 26)
        {
            hours = diff / (0.033 * temp);
            if (hours > 48)
            {
                hours = 48;

                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 26)
        {
            hours = diff / (0.039 * temp);
            if (hours > 48)
            {
                hours = 48;
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
    }
    else if (hum < 80 && hum > 50)
    {
        if (temp < 20)
        {
            hours = diff / (0.032 * temp);
            if (hours > 48)
            {
                hours = 48;
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {

                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 20 && temp < 23)
        {
            hours = diff / (0.026 * temp);
            if (hours > 48)
            {
                hours = 48 Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 23 && temp < 26)
        {
            hours = diff / (0.037 * temp);
            if (hours > 48)
            {
                hours = 48;

                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
        else if (temp > 26)
        {
            hours = diff / (0.043 * temp);
            if (hours > 48)
            {
                hours = 48;
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
            else
            {
                Serial.print("Approximate Time left to water in hours:");
                Serial.println(hours);
                Serial.print("\n");
            }
        }
    }
}
else
{
    Serial.print("Moisture content is very low!");
    Serial.print("Water ON!");
    myservo.write(180);
    // delay(2);
    // myservo.write(180);
}
Serial.print("\n ------ \n");
delay(3000);
}
void setup()
{
    Serial.begin(115200);
    dht.begin();
    myservo.attach(9);
}
void loop()
{
    myTimerEvent();
}
