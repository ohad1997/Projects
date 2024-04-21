#define RED 8
#define YLW 9
#define GRN 10
#define ON 1
#define OFF 0

void setup() {
  // put your setup code here, to run once:
pinMode(RED,OUTPUT);
pinMode(GRN,OUTPUT);
pinMode(YLW,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(RED,ON);
delay(750);
digitalWrite(YLW,ON);
delay(500);
digitalWrite(RED,OFF);
digitalWrite(YLW,OFF);
digitalWrite(GRN,ON);
delay(500);
digitalWrite(GRN,OFF);
delay(100);
}
