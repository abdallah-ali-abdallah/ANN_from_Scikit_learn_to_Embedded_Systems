#include <Arduino.h>

#define     greenLed     5
#define     redLed       6
#define     blueLed      7
#define     LDR_PIN      A0

// Array to hold the color response for the LDR
volatile uint16_t color_resp[3] = {0,0,0};

void printLDR_response();
void capture_color_response();

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
    capture_color_response();
    printLDR_response();
    Serial.println("label");

}

void capture_color_response(){
    
    digitalWrite(redLed,HIGH);
    delay(50);
    color_resp[0] = analogRead(LDR_PIN);
    digitalWrite(redLed,LOW);
    
    digitalWrite(greenLed,HIGH);
    delay(50);
    color_resp[1] = analogRead(LDR_PIN);
    digitalWrite(greenLed,LOW);

    digitalWrite(blueLed,HIGH);
    delay(50);
    color_resp[2] = analogRead(LDR_PIN);
    digitalWrite(blueLed,LOW);

}

void printLDR_response(){
    Serial.print(color_resp[0]);
    Serial.print(",");
    Serial.print(color_resp[1]);
    Serial.print(",");
    Serial.print(color_resp[2]);
    Serial.print(",");

}