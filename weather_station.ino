#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define MQ2 A0
#define MQ4 A1

#define RED 5
#define YELLOW 6
#define GREEN 7

#define BUZZER 8

void setup()
{

    Serial.begin(9600);

    dht.begin();

    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    noTone(BUZZER);

    Serial.println("WEATHER STATION");
}

void loop()
{

    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    int smoke = analogRead(MQ2);
    int methane = analogRead(MQ4);

    if (isnan(temp) || isnan(hum))
    {

        Serial.println("DHT11 ERROR");

        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);

        noTone(BUZZER);

        delay(2000);
        return;
    }

    String condition;

    if (smoke > 600 || methane > 600)
    {

        condition = "DANGER";

        digitalWrite(RED, HIGH);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);

        tone(BUZZER, 1000);
    }

    else if (smoke > 350 || methane > 350)
    {

        condition = "WARNING";

        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, HIGH);
        digitalWrite(GREEN, LOW);

        noTone(BUZZER);
    }

    else
    {

        condition = "NORMAL";

        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, HIGH);

        noTone(BUZZER);
    }

    Serial.println("======================");

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");

    Serial.print("MQ2 Smoke: ");
    Serial.println(smoke);

    Serial.print("MQ4 Methane: ");
    Serial.println(methane);

    Serial.print("Environment: ");
    Serial.println(condition);

    Serial.println("======================");

    delay(2000);
}
