#include <IRremote.h> // invlude libraries
#include <neotimer.h>
Neotimer mytimer = Neotimer(5000); // create timer for ledstrip and main loop
Neotimer looptimer = Neotimer(100);
const int pirpin = 5; // set pins of i/o
const int irpin = 3;
const int bypasspin = 6;
bool oldbypass = true; //create bool for keeping track of old bypass state
IRsend irsend; // create ir objekt
void setup() {
  Serial.begin(9600); // start serial
  IrSender.begin(irpin); // enable ir output
  pinMode(pirpin, INPUT); // define som i/o
  pinMode(irpin, OUTPUT);
  pinMode(bypasspin, INPUT_PULLUP);
}



void loop()
{
  if(looptimer.repeat()) { // repat every 100 milisec
    if(digitalRead(pirpin) == true && digitalRead(bypasspin) == true){ // if motion is detected and bypass is off
    mytimer.start(); //then start the timer for the automatic turnoff,
    IrSender.sendNEC(0x00, 0x3, irpin); // send the off comand with adress 0x00 and message 0x3
    Serial.println("Motion detected, turned on"); //print to serial monitor
    }
  if(mytimer.done()){ // if the tier has run out
    IrSender.sendNEC(0x00, 0x2, irpin); //then turn the ledstrip off
    Serial.println("Turned off by timer"); // and write to the serial monitor
  }

  if(digitalRead(bypasspin) == false && oldbypass == true) { // if the bypass state has changed from off to on
    IrSender.sendNEC(0x00, 0x2, irpin); //the turn the ledstrip off
    Serial.println("Turned off by bypass-switch being activated"); //and write a message
  }
    oldbypass = digitalRead(bypasspin); //set the oldbypass to the current bypass states
    /*Serial.print(digitalRead(bypasspin));
    Serial.print(", ");
    Serial.println(oldbypass);*/
  }
}
