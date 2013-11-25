/* Taken from Blink example with some minor changes, to be used
   on the car alarm project
   */
int lockpin = 0;      // Interrupt 0 is digital pin 3
volatile int stateoflock = LOW;
int led = 10;

void setup() {
  pinMode(led, OUTPUT);
  attachInterrupt(lockpin, stateChange, RISING);
}
void loop() {
  //Simulation
  for (int i = 0; i < 100; i++) {
    delay(10);
  }
}
void stateChange() {
  stateoflock = !stateoflock;
  digitalWrite(led, stateoflock);
}
