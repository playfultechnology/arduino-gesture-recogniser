#include <Wire.h>

// https://www.epsglobal.com/Media-Library/EPSGlobal/Products/files/pixart/PAJ7620F2.pdf?ext=.pdf
#include "src/PAJ7620/paj7620.h"

void setup() {
  // Initialise serial connection to display results
	Serial.begin(9600);

  // Initialise the sensor
	if(!paj7620Init()) {
    Serial.println(F("Initialisation error!")
	}
	else {
		Serial.println(F("Ready!"");
	}
}

void loop() {
	uint8_t data = 0, data1 = 0, error;

  // Read Reg 0x43 of Bank 0 to get result of any recognised gesture, and store in 'data' variable
	error = paj7620ReadReg(0x43, 1, &data);
 
	if(!error) {
		switch (data) {
			case GES_RIGHT_FLAG:
			  Serial.println("Right");          
				break;
			case GES_LEFT_FLAG: 
				Serial.println("Left");         
				break;
			case GES_UP_FLAG:
				Serial.println("Up");        
				break;
			case GES_DOWN_FLAG:
				Serial.println("Down");         
				break;
			case GES_FORWARD_FLAG:
				Serial.println("Forward");
				break;
			case GES_BACKWARD_FLAG:		  
				Serial.println("Backward");
				break;
      // Library also defines GES_CLOCKWISE_FLAG GES_COUNT_CLOCKWISE_FLAG and GES_WAVE_FLAG, but I found these unreliable
			default:
				break;
		}
	}
	delay(100);
}
