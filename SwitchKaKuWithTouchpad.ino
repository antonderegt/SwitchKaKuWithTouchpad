/**
 * For details, see NewRemoteReceiver.h!
 *
 * Connect the transmitter to digital pin 9.
 *
 * This sketch demonstrates the use of the NewRemoteTransmitter class.
 *
 * When run, this sketch switches some pre-defined devices on and off in a loop.
 * 
 * To use this actual example, you'd need to "learn" the used code in the receivers
 * This sketch is unsuited for that.
 * 
 */
 
#include <VirtualWire.h>
#include <NewRemoteTransmitter.h>

const int touchPadOne = 17;
const int toucPadTwo = 16;
const int toucPadThree = 15;
const int toucPadFour = 14;
const int touchPadFive = 13;
const int toucPadSix = 12;
const int toucPadSeven = 11;
const int toucPadEight = 10;

int statusOne = 0;
int statusTwo = 0;
int statusThree = 0;
int statusFour = 0;
int statusFive = 0;
int statusSix = 0;
int statusSeven = 0;
int statusEight = 0;

char *msg;

// Create a transmitter on address 123, using digital pin 9 to transmit, 
// with a period duration of 260ms (default), repeating the transmitted
// code 2^3=8 times.
NewRemoteTransmitter transmitter(15986790, 9, 260, 3);

void setup() {
  pinMode(touchPadOne, INPUT);
  pinMode(toucPadTwo, INPUT);
  pinMode(toucPadThree, INPUT);
  pinMode(toucPadFour, INPUT);
  
  pinMode(touchPadFive, INPUT);
  pinMode(toucPadSix, INPUT);
  pinMode(toucPadSeven, INPUT);
  pinMode(toucPadEight, INPUT);

  // Initialise the IO and ISR
  vw_set_ptt_inverted(true);  // Required for DR3100
  vw_setup(2000);	      // Bits per sec
}

void loop() {
  if (digitalRead(touchPadOne) == HIGH){
    statusOne = !statusOne;
    transmitter.sendUnit(1, statusOne);
  }
  if (digitalRead(toucPadTwo) == HIGH){
    statusTwo = !statusTwo;
    transmitter.sendUnit(3, statusTwo);
  }
  if (digitalRead(toucPadThree) == HIGH){
    statusThree = !statusThree;
    transmitter.sendUnit(2, statusThree);
  }
  if (digitalRead(toucPadFour) == HIGH){
    statusFour = !statusFour;
    transmitter.sendUnit(0, statusFour);
  }
  if (digitalRead(touchPadFive) == HIGH){
    msg = "brightnessMin";
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
  }
  if (digitalRead(toucPadSix) == HIGH){
    msg = "brightnessPlus";
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
  }
  if (digitalRead(toucPadSeven) == HIGH){
    // Implement color switcher
  }
  
  // LED on/off
  if (digitalRead(toucPadEight) == HIGH){
    statusEight = !statusEight;
    
    if (statusEight){
      msg = "on";
    }
    else {
      msg = "off";
    }
    
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
  }

  delay(20);
}
