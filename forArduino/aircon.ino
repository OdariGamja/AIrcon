#include <WiFi.h>
#include <HTTPClient.h>
#include "EmonLib.h"

// WiFi
#define WIFI_SSID "Xperia_2221"
#define WIFI_PASSWORD "11111111"
bool lastAirconOn = false;
// Firebase URL
#define FIREBASE_URL "https://aircon-cc3d0-default-rtdb.firebaseio.com/aircon/isOn.json"

EnergyMonitor emon1;

void setup()
{
  Serial.begin(19200);

  pinMode(5, OUTPUT);

  emon1.current(34, 111.1);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("WiFi Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("WiFi Connected!");
}

void loop()
{
  double Irms = emon1.calcIrms(1480);

  double power = Irms * 230.0;

  Serial.print("Current: ");
  Serial.print(Irms, 3);

  Serial.print(" A   Power: ");
  Serial.print(power, 1);
  Serial.println(" W");

  bool airconOn = Irms > 300;

  digitalWrite(5, airconOn);

  // 상태가 변했을 때만 실행
  if (airconOn != lastAirconOn) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin("https://aircon-cc3d0-default-rtdb.firebaseio.com/aircon.json");
      http.addHeader("Content-Type", "application/json");

      String jsonData;
      if (airconOn) {
        // 끄기 -> 켜기: 이때만 startTime을 서버 시간으로 기록!
        jsonData = "{\"isOn\":true,\"startTime\":{\".sv\":\"timestamp\"}}";
      } else {
        // 켜기 -> 끄기: 꺼진 상태 전송
        jsonData = "{\"isOn\":false}";
      }

      int code = http.PUT(jsonData); 
      Serial.print("Status Changed! Code: ");
      Serial.println(code);
      http.end();
      
      lastAirconOn = airconOn; // 현재 상태 저장
    }
  }

  delay(2000);
}