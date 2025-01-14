# PIR-controlled LED Strip

This project uses a motion detector (PIR) to turn on an LED strip. The program also turns off the LED strip after a given time (in this case, 30 minutes) and has a bypass/turn-off switch for when you don't want the LED strip to turn on. Because of the IR LED, the system is completely standalone and should be seen as a complement to the remote that is included with the LED strip.

#Inputs
This project has two main inputs: one PIR motion detector for detecting motion and one simple switch that allows you to disable the automatic turn-on.

# Outputs
This project only has one output: an IR LED to send signals to the LED strip's control box.

#Functionality
The system is actually really simple. The Arduino Uno reads the PIR sensor and checks for movement. If movement is detected and the bypass switch is turned off, the Arduino sends a command to the LED strip to turn on via the IR LED. If the bypass switch is turned on, the Arduino simply doesn't send a command to the LED strip. Furthermore, the Arduino sends a power-off command to the LED strip if the bypass switch is turned on.

# The IR Protocol
The LED strip, and thereby this project, uses the standard NEC protocol. This protocol uses an address and a command in its transmissions, and because the LED strip completely ignores the address, the communication is pretty straightforward.

# Pictures & Videos
