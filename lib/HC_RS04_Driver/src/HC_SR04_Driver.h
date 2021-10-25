/*
Header file definitions for HC-SR04 typ sensors
*/
#include <Arduino.h>

#ifndef  HC_SR04_Driver_H
#define  HC_SR04_Driver_H


class  HC_SR04 {

public:
            HC_SR04 (uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);

uint16_t    distance(uint8_t, boolean);
uint16_t    distance(uint8_t);
uint16_t    distance();

private:
uint8_t     air_temp;
uint8_t     trigPin;
uint8_t     echoPin;
uint16_t    TOF;                          // Time Of Flight
float       cal;                          // Vsound=(331.3 + 0.606T)/1000 mm/uS, Cal=Vsoudn/2
float       dist, dist_FIR=100;           //
uint8_t     FIRfactor;

protected:
};

#endif