#include <ESP8266WiFi.h>

const char* ssid = "Lanzbc";
const char* password = "meomeomeo";
void setup(void)
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}
void loop() {
  
}
