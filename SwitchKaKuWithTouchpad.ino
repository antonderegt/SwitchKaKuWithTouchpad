/**
 * For details, see NewRemoteReceiver.h!
 *
 * Connect the transmitter to digital pin 11.
 *
 * This sketch demonstrates the use of the NewRemoteTransmitter class.
 *
 * When run, this sketch switches some pre-defined devices on and off in a loop.
 * 
 * To use this actual example, you'd need to "learn" the used code in the receivers
 * This sketch is unsuited for that.
 * 
 */

#include <NewRemoteTransmitter.h>
const int touchPadOne = 2;
const int toucPadTwo = 3;
const int toucPadThree = 4;
const int toucPadFour = 5;
const int touchPadFive = 6;
const int toucPadSix = 7;
const int toucPadSeven = 8;
const int toucPadEight = 9;

int statusOne = 0;
int statusTwo = 0;
int statusThree = 0;
int statusFour = 0;
int statusFive = 0;
int statusSix = 0;
int statusSeven = 0;
int statusEight = 0;


// Create a transmitter on address 123, using digital pin 11 to transmit, 
// with a period duration of 260ms (default), repeating the transmitted
// code 2^3=8 times.
NewRemoteTransmitter transmitter(15986790, 11, 260, 3);

void setup() {
  pinMode(touchPadOne, INPUT);
  pinMode(toucPadTwo, INPUT);
  pinMode(toucPadThree, INPUT);
  pinMode(toucPadFour, INPUT);
  
  pinMode(touchPadFive, INPUT);
  pinMode(toucPadSix, INPUT);
  pinMode(toucPadSeven, INPUT);
  pinMode(toucPadEight, INPUT);
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
    statusFive = !statusFive;
    transmitter.sendUnit(4, statusFive);
  }
//  if (digitalRead(toucPadSix) == HIGH){
//    statusSix = !statusSix;
//    transmitter.sendUnit(5, statusSix);
//  }
//  if (digitalRead(toucPadSeven) == HIGH){
//    statusSeven = !statusSeven;
//    transmitter.sendUnit(6, statusSeven);
//  }
//  if (digitalRead(toucPadEight) == HIGH){
//    statusEight = !statusEight;
//    transmitter.sendUnit(7, statusEight);
//  }

  delay(40);
}
