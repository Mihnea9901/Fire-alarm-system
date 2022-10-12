  Built a fire alarm and monitoring system based on the ATMega8 microcontroller. 
   The system has a MQ-5 gas sensor, a LM35 temperature sensor, an IR fire sensor, a LCD 1602, a servo motor SG90 and a Wi-Fi module
ESP8266.  
   The sensors are used to gather information, the servo motor is used to move the IR sensor to give it
more detection angle, the LCD is used to display the information gathered by the sensors and the Wi-Fi module is
used to send the information and the alarm message to a smartphone. 
    The Wi-Fi module is communicating with the microcontroller via UART protocol and it is configured as a server to communicate with the smartphone via
TCP protocol.

Proteus wiring diagram
![image](https://user-images.githubusercontent.com/56684717/195295181-0e5653e5-df06-4fa9-99a9-80feaa8111fd.png)

The circuit made on the test wiring
![image](https://user-images.githubusercontent.com/56684717/195295560-b876fb54-eece-4e66-8680-a5d7bef846b7.png)

Information displayed on the LCD
![image](https://user-images.githubusercontent.com/56684717/195295626-0fe29844-fa7d-447e-9157-8be2fe25b307.png)
![image](https://user-images.githubusercontent.com/56684717/195295652-33849c1f-ef6d-4514-a882-b3ada934a6f9.png)
![image](https://user-images.githubusercontent.com/56684717/195295674-a451de8b-1b3f-400e-b787-d10c8ed9aa98.png)

Information displayed on the smartphone using a TCP controller app 
![image](https://user-images.githubusercontent.com/56684717/195295712-3458543b-901b-4206-9f22-022b7bd74477.png)


