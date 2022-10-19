#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

const char* ssid = "kan";
const char* password = "12345678";
String serverName = "https://api.thingspeak.com/channels/1898443/feeds.json?api_key=STR30P7FOAD6Q4WN&results=1";

int path = 0;
int i = 0;

void json_decode(String sensorReadings)
{
  JSONVar myObject = JSON.parse(sensorReadings);
  float sensorReadingsArr[8];
  // JSON.typeof(jsonVar) can be used to get the type of the var
  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }

  Serial.print("JSON object = ");
  Serial.println(myObject);

  // myObject.keys() can be used to get an array of all the keys in the object
  JSONVar keys = myObject.keys();

  for (int i = 0; i < keys.length(); i++) {

    JSONVar value = myObject[keys[i]];
    Serial.print(keys[i]);
    Serial.print(" = ");
    Serial.println(value);
    sensorReadingsArr[i] = double(value);
  }
  if (sensorReadingsArr[0] == 1)
  {
    path = 1;
  }
}



void setup()
{
  Serial.begin(115200);
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);

  // receive path from cloud
  path = 0;
  i = 0;

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String serverPath = serverName + "?temperature=24.37";

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      json_decode(payload);
    }
    http.end();


    if (path)
    {
      if (i < 3) {
        digitalWrite(i, HIGH);
        i = (i + 1);
        delay(2000); // Wait for 2000 millisecond(s)
        digitalWrite(i, LOW);
      } else {
        digitalWrite(4, HIGH);
        i = 0;
        delay(2000); // Wait for 2000 millisecond(s)
        digitalWrite(4, LOW);
      }
      path = 0;
    }
  }
}
