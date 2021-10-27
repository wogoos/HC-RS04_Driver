# HC-RS04_Driver</br>
/*</br>
Testes for HC-RS04, HC-SRF05 and AJ-RS04M sensors</br>
Code tested on ATMega328</br>
Date of test 26-10-21</br>
Tester Name Oscar Goos</br>
Notes   :  At 1850 meters high @21C the measurement tells 384mm while the real distance is 400mm </br>
        :  AT 1850 meters high @21C the measurement tells 2780mm while the real distance is 2800mm </br>
        :  The AJ-RS04M seems to be quite sensitive for any small object in the audio path of the tranceiver</br>
To add  :  Mesure the actuale noise of the measured values.</br>
*/</br>

Library for HCRS04 type remote sensors with :

        * Software selectable trigger and echo pins
        * Realtime and noice filtered distance values in millimeters.
        * Buildin FIR filter
        * FIR filter parameter setting
        * Noise window setting
        * Temperature compensation
        * Initialiation of the FIR output startup value
