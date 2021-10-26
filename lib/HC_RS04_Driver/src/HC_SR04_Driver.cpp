#include <HC_SR04_Driver.h>

HC_SR04::HC_SR04(uint8_t trig, uint8_t echo, uint8_t temp, uint8_t FIRfac, uint16_t noise){
    air_temp     = temp;
    trigPin      = trig;
    echoPin      = echo;
    noise_margin = noise;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
    cal= (331.3 + 0.606*air_temp)/(2*1000);
    FIRfactor=FIRfac;
}

void     HC_SR04::init(){
    dist_FIR=distance();                // init the startvalue of dist_FIR
} 

uint16_t HC_SR04::distance(uint8_t temp){
    air_temp=temp;
    cal = (331.3 + 0.606*air_temp)/(2*1000);
    return distance();
}

uint16_t HC_SR04::distance(){
    digitalWrite(trigPin, HIGH);         // Trigger the sensor by setting the trigPin high for 10 microseconds:
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);  
    dist = cal*pulseIn(echoPin, HIGH);    // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
    if ((uint16_t)(abs(dist-dist_FIR))>noise_margin) dist_FIR=dist;
    dist_FIR += (dist - dist_FIR)/FIRfactor;
    return  (uint16_t) dist;
}