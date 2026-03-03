#include <WiFi.h>
#include <DHT.h>           
#include <LiquidCrystal.h>

#define DHTPIN 3
#define DHTTYPE DHT22      
DHT dht(DHTPIN, DHTTYPE);  

#define LED_PIN 6 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const char* ssid = "DazeForFuture-NET";
const char* password = "!PasDFF0810";
const char* serverIP = "192.168.50.1";
const int serverPort = 8888;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  delay(1000);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Avvio sistema");

  WiFi.begin(ssid, password);
  lcd.setCursor(0, 1);
  lcd.print("Connessione...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.print("WiFi Connesso");
  delay(1500);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Errore di lettura dal sensore DHT!");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: "); lcd.print(t, 1); lcd.print((char)223); lcd.print("C   ");
  lcd.setCursor(0, 1);
  lcd.print("Umid: "); lcd.print(h, 1); lcd.print("%   ");
  if (WiFi.status() != WL_CONNECTED){
    lcd.setCursor(14, 0);
    lcd.print("NC"); //Non connesso
    WiFi.begin(ssid, password);
    delay(1000);
  }
  else{
    lcd.setCursor(14,0);
    lcd.print("  ");
  

    if (client.connect(serverIP, serverPort)) {
      client.print("GET /update?temp=");
      client.print(t);
      client.print("&hum=");
      client.print(h);
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(serverIP);
      client.println("Connection: close");
      client.println();
      client.stop();
    } else {
      Serial.println("Connessione al server fallita");
    }
  }
  delay(2000); 
}