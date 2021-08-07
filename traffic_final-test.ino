#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
// Replace with your network credentials
const char* ssid = "AndroidAP33F5";
const char* password = "princess";
WiFiServer server(80);

Servo Servo_1;
Servo Servo_2;

void setup(void) {
  // put your setup code here, to run once:
Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
  Serial.println("Web server started!");
Servo_1.attach(D0);
Servo_2.attach(D1);

int LED1 = D2;
int LED2 = D3;
int LED3 = D4;
pinMode(D2,OUTPUT);//green
pinMode(D3,OUTPUT);//orange
pinMode(D4,OUTPUT);//red

int LED4 = D5;
int LED5 = D6;
int LED6 = D7;
pinMode(D5,OUTPUT);//green
pinMode(D6,OUTPUT);//orange
pinMode(D7,OUTPUT);//red



}

void loop(void) {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
digitalWrite(D4,HIGH);
digitalWrite(D5,HIGH);
int a = digitalRead(D4);
int b = digitalRead(D5);
client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta http-equiv=\"refresh\" content=\"5\">");
  client.println("<link rel=\"icon\" href=\"data:,\">");
  //css
  client.println("<style>html {font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println("text-decoration: none; font-size: 20px; margin: 4px; cursor: pointer;}</style></head>");
  // Web Page Heading
  client.println("<body><h1><b>Serole Smart Street lighting system</b></h1></body>");
if((a == HIGH) && (b == HIGH))
{
  Servo_1.write(0);
  Servo_2.write(90);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  }
 Serial.println("lane1: start ");
  Serial.println("lane2: stop");
  client.println("<h3> lane1: start <\h3>");
  client.println("<h3> lane2: stop <\h3>");
  client.println("<br><br>");
delay(1000);//50000



digitalWrite(D5,LOW);
digitalWrite(D4, LOW);
digitalWrite(D6,HIGH);
digitalWrite(D3,HIGH);
int c = digitalRead(D3);
int d = digitalRead(D6);
int u = digitalRead(D4);
int v = digitalRead(D5);
if((c == HIGH) && (d == HIGH) &&(u==LOW) && (v==LOW))
{
  Servo_1.write(35);
  Servo_2.write(35);
  digitalWrite(D2,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D7,LOW);
}
Serial.println("lane1: ready to stop");
Serial.println("lane2: ready to start");
client.println("<h3> lane1: ready to stop  <\h3>");
client.println("<h3> lane2: ready to start <\h3>");
client.println("<br><br>");
delay(1000);//10000


digitalWrite(D2,HIGH);
digitalWrite(D7,HIGH);

int e = digitalRead(D2);
int f = digitalRead(D7);
if((e == HIGH)  && (f == HIGH))
{
Servo_1.write(90);
Servo_2.write(180);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW);
}

Serial.println("lane1: stop");
Serial.println("lane2: start");
client.println("<h3> lane1: stop <\h3>");
client.println("<h3> lane2: start <\h3>");
client.println("<br><br>");
delay(1000);//50000


client.println("</html>");






}
