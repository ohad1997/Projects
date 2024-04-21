#include<ESP8266WiFi.h>

#define ssid "cohen1"
#define password "0545606242"

void setup(){

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password);

    Serial.begin(115200);

    while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("connected to: ");
    Serial.println(ssid);
    Serial.println("IP Adress: ");
    Serial.println(WiFi.localIP());
}

void loop(){}