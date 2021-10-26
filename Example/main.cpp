#include <Arduino.h>
#include <HC_SR04_Driver.h>
// The setup() function runs once each time the micro-controller starts
/* Example code for HC-SR04 ultrasonic distance sensor with Arduino. No library required. More info: https://www.makerguides.com */
// Define Trig and Echo pin:

HC_SR04   DistSens(2,3,22,10,100);            // TrigPin, EchoPin, air_temperature, FIRfactor

void setup() {
    // Define inputs and outputs:
    Serial.begin(115200);
    DistSens.init();
}
void loop() {
    DistSens.distance(20);
    Serial.print("Distance = ");
    Serial.print( DistSens.dist);
    Serial.print(",  ");
    Serial.print( (uint16_t)DistSens.dist);
    Serial.print(",  ");
 //   Serial.print( DistSens.distance(20));
 //   Serial.print(",  ");
    Serial.print( DistSens.dist_FIR);
    Serial.print(",  ");
    Serial.print( (uint16_t)DistSens.dist_FIR);
    Serial.println(" mm");
    delay(1000);
}
