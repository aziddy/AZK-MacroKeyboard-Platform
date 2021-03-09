#include <Arduino.h>
#include <EEPROM.h>
#include <Keyboard.h>

/* Related Code Documents:
 * https://www.arduino.cc/en/Reference/EEPROMObject
  */

#define number_of_keys 2

int key[127][4];

void setup() {


  /* special key definitions can be founder here
   * https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
   * (MAC) command ⌘ == KEY_LEFT_GUI
   */
 
  // 2 key layout
  key[0][0] = KEY_LEFT_CTRL;
    key[0][1] = KEY_LEFT_SHIFT;
    key[0][2] = 'M';
    key[0][3] = 0;
  key[1][0] = KEY_LEFT_CTRL;
    key[1][1] = KEY_LEFT_SHIFT;
    key[1][2] = 'D';
    key[1][3] = 0;
    
  // 4 key layout
  key[0][0] = 0xB0;
    key[0][1] = 0;
    key[0][2] = 0;
    key[0][3] = 0;
  key[1][0] = 0xEA;
    key[1][1] = 0;
    key[1][2] = 0;
    key[1][3] = 0;
  

  delay(10000);

  write_eeprom();
  serial_report_eeprom();
  
}


void write_eeprom(){
  // First EEPROM index specifies how many keys the layout has
  EEPROM[0] = number_of_keys;

  for(int i = 0; i < number_of_keys; i++ ){
    EEPROM[0+(i*4)] = key[i][0];
    EEPROM[1+(i*4)] = key[i][1];
    EEPROM[2+(i*4)] = key[i][2];
    EEPROM[3+(i*4)] = key[i][3];
  }
}

void serial_report_eeprom(){
  
}


void loop(){
}
