  Built a fire alarm and monitoring system based on the ATMega8 microcontroller. 
   The system has a MQ-5 gas sensor, a LM35 temperature sensor, an IR fire sensor, a LCD 1602, a servo motor SG90 and a Wi-Fi module
ESP8266.  
   The sensors are used to gather information, the servo motor is used to move the IR sensor to give it
more detection angle, the LCD is used to display the information gathered by the sensors and the Wi-Fi module is
used to send the information and the alarm message to a smartphone. 
    The Wi-Fi module is communicating with the microcontroller via UART protocol and it is configured as a server to communicate with the smartphone via
TCP protocol.
