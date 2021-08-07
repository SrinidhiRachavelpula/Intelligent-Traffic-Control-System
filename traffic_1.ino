#include <Servo.h>
#include <WiFiClientSecure.h>

#include <WiFiClient.h>
 
#include <ESP8266WiFi.h>
Servo Servo_1;
Servo Servo_2;

const char* host = "script.google.com";
const int httpsPort = 443; 
WiFiClientSecure client;
const char *ssid = "Serole_AP"; 
const char *password = "Serole@123";  
String SCRIPT_ID = "</s/AKfycbywv4y5T6QGYfdIjT-ubkS8EcZeP8qf7gRei7_IY9CI5OyRNEg/exec>";
const char* Fingerprint="A5:D7:0E:CB:D7:CC:BF:7D:FC:44:77:8B:EE:43:3F:FE:8D:EA:50:B1";



void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(5000);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

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

Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print("connecting to ");
  Serial.println( host);
 
  WiFiClientSecure client;

  const int httpPort = 443;
  if (!client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
   
    return;
  delay(1000);
  }

digitalWrite(D4,HIGH);
digitalWrite(D5,HIGH);
int a = digitalRead(D4);
int b = digitalRead(D5);
if((a == HIGH) && (b == HIGH))
{
  Servo_1.write(0);
  Servo_2.write(90);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  }
  Serial.println("lane1: start");
  Serial.println("lane2: stop");
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
delay(500);//10000
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
delay(1000);//50000









}
