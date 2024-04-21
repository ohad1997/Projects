#define BUTTON 8
#define TRIG_OUTPUT 6
#define ECHO_INPUT 7

void setup() {
  // put your setup code here, to run once:
pinMode(BUTTON,INPUT);
pinMode(TRIG_OUTPUT,OUTPUT);
pinMode(ECHO_INPUT,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Press = digitalRead(BUTTON);

  if(Press != HIGH)
  {
    digitalWrite(TRIG_OUTPUT, LOW); delayMicroseconds(2);
    digitalWrite(TRIG_OUTPUT, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
    delayMicroseconds(10); 
    digitalWrite(TRIG_OUTPUT, LOW);
    int distance = pulseIn(ECHO_INPUT, HIGH); // Read receiver pulse time 
    distance= distance/57; // Transform pulse time to distance 
    Serial.println(distance); //Output distance
    delay(50);
  }

}
