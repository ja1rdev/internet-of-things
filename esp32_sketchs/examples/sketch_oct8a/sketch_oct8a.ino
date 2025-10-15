# include <DHT.h>
# define DHTPIN 2
# define DHTTYPE DHT11 
# define LED_RED 13
float humidity, temperature;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.println("::: Welcome to Weather Station :::");
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Turn on led red T > 30
  if (!isnan(temperature) && temperature > 30.0) {
    digitalWrite(LED_RED, HIGH);
  } else {
    digitalWrite(LED_RED, LOW);
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  delay(2000);
}
