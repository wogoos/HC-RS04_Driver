#include <HC_SR04_Driver.h>

HC_SR04::HC_SR04(uint8_t trig, uint8_t echo, uint8_t temp, uint8_t FIR, uint16_t FIRstart){
    air_temp = temp;
    trigPin  = trig;
    echoPin  = echo;
    dist_FIR = FIRstart;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
    cal= (331.3 + 0.606*air_temp)/(2*1000);
    FIRfactor=FIR;
}

uint16_t HC_SR04::distance(){
    return distance(air_temp, false);
    }

uint16_t HC_SR04::distance(uint8_t temp){
    return distance(temp, false);
}

uint16_t HC_SR04::distance(uint8_t temp, boolean FIR){
    if (temp != air_temp) {
      air_temp=temp;
      cal = (331.3 + 0.606*air_temp)/(2*1000);
    }
    digitalWrite(trigPin, HIGH);         // Trigger the sensor by setting the trigPin high for 10 microseconds:
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);  
    dist= cal*pulseIn(echoPin, HIGH);    // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
    dist_FIR+= (dist - dist_FIR)/FIRfactor;
    if (FIR) return  (uint16_t) dist_FIR;   // Return distance in mm.
    else     return  (uint16_t) dist; 
}