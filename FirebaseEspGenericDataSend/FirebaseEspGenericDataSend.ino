#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID ""        // Your WiFi SSID
#define _PASSWORD ""    // Your WiFi Password
#define PROJECT_ID ""   // Your Firebase Project ID. Can be found in project settings.

Firebase firebase(PROJECT_ID);
int data;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);
  //firebase.setInt("Random/Percentage", random(1,100));
}

void loop() {
  data= random(1,100);
  //firebase.pushInt("Random/Percentage", data);
  firebase.setInt("Random/Percentage/Value", random(1,100));
  delay(4000);
}
