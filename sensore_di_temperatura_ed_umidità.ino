#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
// Pin 8 on Arduino to which the temperature sensor is connected
#define DHTTYPE DHT11
// DHT11 is the type of sensor being used

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Connection to the display (pins)

void setup() {
  lcd.begin(16, 2);
  // Set the display type (columns, rows)
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.print("Humidity");
}

void loop() {
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  // Position the cursor at column 14 and row 0
  lcd.setCursor(14, 0);
  lcd.print(t);
  lcd.setCursor(14, 1);
  lcd.print(h);
}
