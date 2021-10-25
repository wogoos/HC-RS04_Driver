#include <Arduino.h>
#include <HC_SR04_Driver.h>
// The setup() function runs once each time the micro-controller starts
/* Example code for HC-SR04 ultrasonic distance sensor with Arduino. No library required. More info: https://www.makerguides.com */
// Define Trig and Echo pin:

HC_SR04   DistSens(2,3,30,10,50);            // TrigPin, EchoPin, air_temperature, FIRfactor, Distance Startvalue(mm) 

void setup() {
    // Define inputs and outputs:
    Serial.begin(115200);
}
void loop() {
    Serial.print("Distance = ");
    Serial.print( DistSens.distance());
    Serial.print(",  ");
    Serial.print( DistSens.distance(30));
    Serial.print(",  ");
    Serial.print( DistSens.distance(30, true));
    Serial.println(" cm");
}
