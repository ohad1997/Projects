
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
float temperature = analogRead(A0);
  temperature = ((temperature * 4.88)/10);
  Serial.println(temperature);
  delay(500);
}
