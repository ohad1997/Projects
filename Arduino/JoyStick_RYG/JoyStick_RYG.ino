#define X A0
#define Y A1
#define BUTTON 7
#define YLW 8
#define GRN 9
#define RED 10


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(BUTTON,INPUT);
pinMode(YLW,OUTPUT);
pinMode(GRN,OUTPUT);
pinMode(RED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Switch = digitalRead(BUTTON);
  float X_coordinate = analogRead(X);
  float Y_coordinate = analogRead(Y);

  
  if(X_coordinate > 750 || X_coordinate < 250)
    digitalWrite(GRN,HIGH);
  else
    digitalWrite(GRN,LOW);

    if(Y_coordinate > 750 || Y_coordinate < 250)
    digitalWrite(RED,HIGH);
  else
    digitalWrite(RED,LOW);

  if(Switch == HIGH)
    digitalWrite(YLW,HIGH);
  else
    digitalWrite(YLW,LOW);

}
