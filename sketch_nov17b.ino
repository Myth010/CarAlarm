/* Taken from Blink example with some minor changes, to be used
   on the car alarm project
   */
int stateofLock = 8;
int led = 10;
int val = 0;

void setup() 
{
  pinMode(stateofLock, INPUT);
  pinMode(led, OUTPUT);
}
void loop() {
  val =digitalRead(stateofLock);
  digitalWrite(led, val);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
