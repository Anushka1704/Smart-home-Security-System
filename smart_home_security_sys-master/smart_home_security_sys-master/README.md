# smart_home_security_sys
Smart home security system project code and other files

Installation and Configuration
1. Download the Arduino IDE and Install - https://www.arduino.cc/en/main/software

2. Download and Install Proteus software - https://crackdaily.com/proteus-download/

3. Extract the Zip folder PID


5. Need to config the library files for arduino, GSM, LCD and PIR in proteus software
	1. Open the source location of the proteus software installed in your computer
	   in my case (C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Library)
	2. Then open the Library folder in proteus software installed location 
	3. Before that copy the two file (.IDX file and .LIB file) inside the --> Smart_home_security/Proteus_library/Arduino/
	4. Past that copied files in the location mentioned in 1st point
	5. Follow the same procedure for GSM, LCD and PIR folders in location mentioned in 2nd Point.

6. Basic installation and Library configs all are completed

7. Open the arduino source code from Smart_home_security/Arduino Program/smart_home_security_sys/smart_home_security_sys.ino

8. Go to File->Perferences and checkIn compilation option, then click ok.

9. Then Click the Run button, Sketch->Verify/Complie or Ctrl+R or click the tick button on the top left corner below the file option.


10. Remaining procedures, please follow up the connection video - https://drive.google.com/file/d/1FRGxvEQVpXSNNEhYF-OZ8IxXX9BWuZzZ/view?usp=sharing
      Demo video - https://drive.google.com/file/d/1JDHhwJpdWynfc2klQ8WkoOXk_ut5qPd8/view?usp=sharing

Pin Connection:
	Components used:-
		1.  Arduino UNO - 1 
		2.  LM35 (Temperature Sensor) - 3
		3.  PIR Sensor
		4.  GSM
		5. LCD

	Connections:
		1.  LM35 sensor 1:
			LM35 Vcc        -   Arduino 5V
			LM35 Gnd       -   Arduino Gnd
			LM35 Out Pin  -  Arduino A0

		2.  PIR sensor:
			PIR Vcc	-  Arduino 5V
			PIR Gnd	-  Arduino GND
			PIR Out	-  Arduino 4th Pin

		3.  LCD:
			LCD Vss	-  Arduino Gnd
			LCD Vdd	-  Arduino 5V
			LCD Vee   -  Pot -HG output Pin
			LCD  RS	-  Arduino 13th Pin
			LCD R/W 	-  Arduino Gnd
			LCD E	-  Arduino 12th Pin
			LCD D4	-  Arduino 11th Pin
			LCD D5	-  Arduino 10th Pin
			LCD D6	-  Arduino 9th Pin
			LCD D7	-  Arduino 8th Pin
		
		4.  GSM (Virtual Terminal):-
			GSM Vcc		-  5Watt Power Supply
			GSM Gnd		-  Power Supply Gnd (Arduino Gnd and Power Supply Gnd Should be short)
			GSM Tx		-  Arduino Rx Pin (0th Pin)
			GSM Rx		-  Arduino Tx Pin (1st Pin)
