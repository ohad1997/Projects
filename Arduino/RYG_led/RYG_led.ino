int greenPin = 6;
int yellowPin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(greenPin,HIGH);
  delay(100);
  digitalWrite(yellowPin,HIGH);
  delay(100);
  digitalWrite(greenPin,LOW);
  delay(100);
  digitalWrite(yellowPin,LOW);
  delay(100);
}
