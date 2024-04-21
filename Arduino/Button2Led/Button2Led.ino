void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Button = digitalRead(8);
  if (Button == LOW)
    digitalWrite(7,HIGH);
  else
    digitalWrite(7,LOW);
}
