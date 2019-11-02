#include <Arduino.h>
#include "emlearn/colorMLP.h"

#define     greenLed     5
#define     redLed       6
#define     blueLed      7
#define     LDR_PIN      A0

// Array to hold the color response for the LDR
volatile float color_resp[3] = {0,0,0};
volatile float color_pred[6] = {0,0,0,0,0,0};

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
    predict();
}

int predict(){

    // Printing probability of all colors using the neural network
    int error = eml_net_predict_proba(&colorMLP,&color_resp[0],3,&color_pred[0],6);
    Serial.print("Pred: ");
    for (size_t i = 0; i < 6; i++)
    {
        Serial.print(color_pred[i]);
        Serial.print(", ");
    }
    Serial.print("\n\n");

    // Print the color with highest probability
    int classColor = eml_net_predict(&colorMLP,&color_resp[0],3);

    if(classColor == 0){Serial.println("No color");}
    else if(classColor == 1){Serial.println("Color: Black");}
    else if(classColor == 2){Serial.println("Color: Pink");}
    else if(classColor == 3){Serial.println("Color: Yellow");}
    else if(classColor == 4){Serial.println("Color: LightBlue");}
    else if(classColor == 5){Serial.println("Color: Red");}

    Serial.println("-------------");
    return error;
}


void capture_color_response(){
    
    digitalWrite(redLed,HIGH);
    delay(50);
    color_resp[0] = (float)analogRead(LDR_PIN);
    digitalWrite(redLed,LOW);
    
    digitalWrite(greenLed,HIGH);
    delay(50);
    color_resp[1] = (float)analogRead(LDR_PIN);
    digitalWrite(greenLed,LOW);

    digitalWrite(blueLed,HIGH);
    delay(50);
    color_resp[2] = (float)analogRead(LDR_PIN);
    digitalWrite(blueLed,LOW);

}


void printLDR_response(){
    Serial.print(color_resp[0]);
    Serial.print(",");
    Serial.print(color_resp[1]);
    Serial.print(",");
    Serial.println(color_resp[2]);  
}