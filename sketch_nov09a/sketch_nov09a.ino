/* First we need to figure out whether the doors are locked.
  Whenever you lock the doors (from the inside or outside (DOES
  NOT APPLY IF LOCKING WITH JUST THE KEYS) the lock receives +12V.
  To unlock the lock receives -12V. So we cut the one wire and attach
  it to the Arduino board (while also connecting it with cut end so
  the lock actually works) and figure out whether the lock is being
  turned.
 */

/* Code for Car alarm, sensor code will be based on the Memsic2125
  example. We will be using an Xtrinsic MMA8491Q 3-Axis multifunction
  digital accelerometer instead, so a few lines of code will have to
  be changed.
  */
/*
   Memsic2125
   
   Read the Memsic 2125 two-axis accelerometer.  Converts the
   pulses output by the 2125 into milli-g's (1/1000 of earth's
   gravity) and prints them over the serial connection to the
   computer.
   
   The circuit:
	* X output of accelerometer to digital pin 2
	* Y output of accelerometer to digital pin 3
	* +V of accelerometer to +5V
	* GND of accelerometer to ground
  
   http://www.arduino.cc/en/Tutorial/Memsic2125
   
   created 6 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
   
   This example code is in the public domain.

 */

// these constants won't change:
const int xPin = 2;		// X output of the accelerometer
const int yPin = 3;		// Y output of the accelerometer
//New code
const int zPin = 4;            // Z output of the accelerometer

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer
  // as inputs:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);
}

void loop() {
  // variables to read the pulse widths:
  int pulseX, pulseY, pulseZ;
  // variables to contain the resulting accelerations
  int accelerationX, accelerationY, acceleration Z;
  
  // read pulse from x- and y-axes:
  pulseX = pulseIn(xPin,HIGH);  
  pulseY = pulseIn(yPin,HIGH);
  pulseZ = pulseIn(zPin,HIGH);
  
  // convert the pulse width into acceleration
  // accelerationX and accelerationY are in milli-g's: 
  // earth's gravity is 1000 milli-g's, or 1g.
  accelerationX = ((pulseX / 10) - 500) * 8;
  accelerationY = ((pulseY / 10) - 500) * 8;
  accelerationZ = ((pulseZ / 10) - 500) * 8; 

  // print the acceleration
  Serial.print(accelerationX);
  // print a tab character:
  Serial.print("\t");
  Serial.print(accelerationY);
  Serial.print("\t");
  Serial.print(accelerationZ);
  Serial.println();

  delay(100);
}
