#include <M5StickC.h>

#include<WiFi.h>
#include<HTTPClient.h>
#include <ArduinoJson.h>


//以下三个定义为调试定义
#define DebugBegin(baud_rate)    Serial.begin(baud_rate)
#define DebugPrintln(message)    Serial.println(message)
#define DebugPrint(message)    Serial.print(message)

const char* ssid     = "";         
const char* password = "";
// -----
    

const char* HOST = "http://116.62.44.219:8088";

const char *keys[] = {"Set-Cookie"};//需要收集的响应头的信息


const unsigned long BAUD_RATE = 115200;                   // serial connection speed
const unsigned long HTTP_TIMEOUT = 5000;               // max respone time from server

HTTPClient http;

String GetUrl;
String response;

void setup() {

    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    delay(4000);
    WiFi.begin(ssid,password);
    M5.begin();

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
        M5.Lcd.print("Connecting to WiFi...");
    }

    Serial.println("Connected to the WiFi network");

 //拼接get请求url  
  GetUrl = String(HOST) + "/topgps/Login/ClientAccount?u=rl&s=F6&f=0&t=15";
  
  http.setTimeout(HTTP_TIMEOUT); //设置超时
  http.begin(GetUrl);   //设置请求url
  http.collectHeaders(keys,1);  //设置获取响应头的信息
  
}

void loop() {
  //
  int httpCode = http.GET();
  if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      //判断请求是否成功
      if (httpCode == HTTP_CODE_OK) {
        //读取响应内容
        response = http.getString();
        DebugPrintln("Get the data from Internet!");
        DebugPrintln(response);
        DebugPrintln(String("Set-Cookie:")+ http.header("Set-Cookie"));

        Serial.print(response);
        Serial.print("Set-Cookie");
        
      }
  } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  
  

  http.end();
  delay(1000);    //每1s调用一次 
}
