# Weather Station

## About

The Weather Station is an Arduino-based environmental monitoring project that measures temperature and humidity and checks for smoke or methane gas using DHT11, MQ-2, and MQ-4 sensors. It shows the air quality status through LEDs and a buzzer and sends the readings to the Serial Monitor.

## How It Works

The DHT11 sensor reads the temperature and humidity every two seconds. The MQ-2 and MQ-4 sensors measure smoke and methane levels through analog inputs.

The LED and buzzer indicate the detected condition:

| Condition | Green LED | Yellow LED | Red LED | Buzzer |
| --------- | :-------: | :--------: | :-----: | :----: |
| NORMAL    |    ON     |    OFF     |   OFF   |  OFF   |
| WARNING   |    OFF    |     ON     |   OFF   |  OFF   |
| DANGER    |    OFF    |    OFF     |   ON    |   ON   |

A reading is marked **WARNING** when either gas sensor exceeds 350. A reading is marked **DANGER** when either sensor exceeds 600. If the DHT11 cannot provide valid readings, the system displays `DHT11 ERROR` and turns off the status LEDs and buzzer.

## Connections

| Component           | Component Pin | Arduino UNO Pin |
| ------------------- | ------------- | --------------- |
| DHT11               | VCC (+)       | 5V              |
|                     | GND (-)       | GND             |
|                     | DATA / OUT    | D2              |
| MQ-2 Smoke Sensor   | VCC           | 5V              |
|                     | GND           | GND             |
|                     | AO            | A0              |
|                     | DO            | Not connected   |
| MQ-4 Methane Sensor | VCC           | 5V              |
|                     | GND           | GND             |
|                     | AO            | A1              |
|                     | DO            | Not connected   |
| Traffic Light       | R             | D5              |
|                     | Y             | D6              |
|                     | G             | D7              |
|                     | GND           | GND             |
| Buzzer              | Positive (+)  | D8              |
|                     | Negative (-)  | GND             |

**Made by Baljit Panda ([olympus-mons26](https://github.com/olympus-mons26/))**
