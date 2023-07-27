Software Used:

Arduino IDE
https://www.arduino.cc/en/software
PyCharm
https://www.jetbrains.com/edu-products/download/other-PCE.html


Components Required:

1*ESP32 cam module
2*Arduino Uno
1*IR sensor array
4*N20 motor and wheels
L298n Motor driver
2* 18650 li-ion battery and battery holder 
Jumper Cables

Pin Connections

Arduino 1 with IR sensor array 

IR sensor-->Arduino 
OUT5-->2
OUT4-->3
OUT3-->4
OUT2-->5
OUT1-->6
VCC-->5V
GND-->GND

Arduino 1 with motor driver

Motor Driver-->Arduino 1
MA1-->7
MA2-->8
MB1-->12
MB2-->13
ENA-->10
ENB-->11
12V-->Battery +ve
5V-->Arduino 5V
GND-->Battery -ve + Arduino GND

Arduino 2 with ESP32 Cam module

ESP32-->Arduino 2
U0T-->TX
U0R-->RX
5V--> Arduino 5V
GND-->Arduino GND
GPO0 ESP32--> GND ESP32 (It has to be pulled out after uploading the code and then the Reset button is to be pressed to get the Output IP address on the serial monitor)


#Both of the codes are given in the folder. 

