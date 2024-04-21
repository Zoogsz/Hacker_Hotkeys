#include "FingerprintUSBHost.h"
#include <Keyboard.h>
#include <avr/pgmspace.h>

#define BTN1  13
#define BTN2  5
#define BTN3  10
#define BTN4  9
#define BTN5  8
#define BTN6  6
#define BTN7  12
#define BTN8  4


#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
#endif

// Ugly global layer int because i am a bad programmer
int layer = 0;


void setup() 
{
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP);
  pinMode(BTN6, INPUT_PULLUP);
  pinMode(BTN7, INPUT_PULLUP);
  pinMode(BTN8, INPUT_PULLUP);

    #ifdef DEBUG
    Serial.begin(9600); //initialize serial communication.  we put some debug in serial monitor
  #endif
  delay(3000); //Take a moment to let things settle

}

//
//  So instead of being smart and using the hacker-hotkeys adv code where it creates essentially an array of chars and sends it out.
//  I noticed video games were much more sensetive to the press/release side of things.

void loop() {

  // Layer setters

  if (digitalRead(BTN1) == LOW)
   {
    layer = 1;
    //Keyboard.println(layer);
    delay(200);
  }
  else if (digitalRead(BTN2) == LOW)
  {
    layer = 2;
    //Keyboard.println(layer);
    delay(200);
  }
  else if (digitalRead(BTN3) == LOW) {
    layer = 3;
    //Keyboard.println(layer);
    delay(200);
  }
  else if (digitalRead(BTN4) == LOW) {
    layer = 4;
    //Keyboard.println(layer);
    delay(200);
  }

  // Bottom Row


  else if (digitalRead(BTN5) == LOW) 
  {
    if(layer == 1)
    {
      // Helldivers reinforce
      DEBUG_PRINT(F("Layer 1 Button 1 Pressed"));;
      Keyboard.press(KEY_LEFT_ALT);

      // Press and release arrow keys
      Keyboard.press(KEY_UP_ARROW);
      delay(100);
      Keyboard.release(KEY_UP_ARROW);

      Keyboard.press(KEY_DOWN_ARROW);
      delay(100);
      Keyboard.release(KEY_DOWN_ARROW);

      Keyboard.press(KEY_RIGHT_ARROW);
      delay(100);
      Keyboard.release(KEY_RIGHT_ARROW);

      Keyboard.press(KEY_LEFT_ARROW);
      delay(100);
      Keyboard.release(KEY_LEFT_ARROW);

      // Release Alt key
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if(layer == 2){
      DEBUG_PRINT(F("Layer 2 Button 1 Pressed"));;
    }
    else if(layer == 3){
      DEBUG_PRINT(F("Layer 3 Button 1 Pressed"));;
    }
    else if(layer == 4){
      DEBUG_PRINT(F("Layer 4 Button 1 Pressed"));;
    }
    delay(200);
  }

  // Eagle 500KG Bomb
  else if (digitalRead(BTN6) == LOW)
  {
      if(layer == 1)
      {
        Keyboard.press(KEY_LEFT_ALT);

        // Press and release Up arrow key
        Keyboard.press(KEY_UP_ARROW);
        delay(100);
        Keyboard.release(KEY_UP_ARROW);

        // Press and release Right arrow key
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_RIGHT_ARROW);

        // Press and release Down arrow key three times
        for(int i = 0; i < 3; i++) {
          Keyboard.press(KEY_DOWN_ARROW);
          delay(100);
          Keyboard.release(KEY_DOWN_ARROW);
          delay(100);
        }

        // Release Alt key
        Keyboard.release(KEY_LEFT_ALT);
    }
    else if(layer == 2){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 3){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 4){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    delay(200);
  }
  else if (digitalRead(BTN7) == LOW) {
      if(layer == 1){
      DEBUG_PRINT(F("Layer 1 Button 3 pressed"));;
      // Press Alt key
        Keyboard.press(KEY_LEFT_ALT);

        // Press and release Up arrow key
        Keyboard.press(KEY_UP_ARROW);
        delay(100);
        Keyboard.release(KEY_UP_ARROW);

        // Press and release Right arrow key
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_RIGHT_ARROW);

        // Press and release Down arrow key
        Keyboard.press(KEY_DOWN_ARROW);
        delay(100);
        Keyboard.release(KEY_DOWN_ARROW);

        // Press and release Right arrow key
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_RIGHT_ARROW);

        // Release Alt key
        Keyboard.release(KEY_LEFT_ALT);
      
    }
    else if(layer == 2){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 3){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 4){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    delay(200);
  }
  else if (digitalRead(BTN8) == LOW) {
      if(layer == 1){
        DEBUG_PRINT(F("Layer 1 Button 4 Pressed"));;
        Keyboard.press(KEY_LEFT_ALT);

        // Press and release Right arrow key
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_RIGHT_ARROW);

        // Press and release Down arrow key
        Keyboard.press(KEY_DOWN_ARROW);
        delay(100);
        Keyboard.release(KEY_DOWN_ARROW);

        // Press and release Up arrow key
        Keyboard.press(KEY_UP_ARROW);
        delay(100);
        Keyboard.release(KEY_UP_ARROW);

        // Press and release Right arrow key
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_RIGHT_ARROW);

        // Press and release Down arrow key
        Keyboard.press(KEY_DOWN_ARROW);
        delay(100);
        Keyboard.release(KEY_DOWN_ARROW);

        // Release Alt key
        Keyboard.release(KEY_LEFT_ALT);
    }
    else if(layer == 2){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 3){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    else if(layer == 4){
      DEBUG_PRINT(F("Button 1 Pressed"));;
    }
    delay(200);
  }
}
