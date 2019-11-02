// Just a simple test for the HW
#include <Arduino.h>

#define     greenLed     5
#define     redLed       6
#define     blueLed      7
#define     LDR_PIN      A0


void setup()
{
    // Set the 3 leds as OUTPUT
    pinMode(redLed,OUTPUT);
    pinMode(greenLed,OUTPUT);
    pinMode(blueLed,OUTPUT);

    Serial.begin(115200);
}

void loop()
{
    Serial.println(analogRead(LDR_PIN));
    
    digitalWrite(greenLed,HIGH);
    delay(500);
    digitalWrite(greenLed,LOW);
    delay(500);
    digitalWrite(redLed,HIGH);
    delay(500);
    digitalWrite(redLed,LOW);
    delay(500);
    digitalWrite(blueLed,HIGH);
    delay(500);
    digitalWrite(blueLed,LOW);
    delay(500);
}
