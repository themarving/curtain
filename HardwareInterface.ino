// include arduino stepper library
#include <Stepper.h>

// include wifinina and spi library to be able to connect board to wifi
#include <SPI.h>
#include <WiFiNINA.h>             
char wlanID[] = "iPhone";
char wlanPASS[] = "uniOl123";
int status = WL_IDLE_STATUS;
WiFiClient client;

// include arduinojson library to parse json
#include <ArduinoJson.h>        

// steps it takes to make a full revolution
const int STEPS_PER_REVOLUTION = 2048;

// push/pull length of opening/closing the curtain
const int PUSH_PULL_LENGTH = 1500;

// creating motor control unit
Stepper motorControl = Stepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);

// variable to save current state of curtain and to know if the curtain is to be closed
boolean curtainClosed = true;
boolean curtainToClose = true;

// variables to connect to Open-Weather-Map via API-Key (https://openweathermap.org/)
const String city = "Oldenburg";
const String api_key = "10f3b7e5d5ab9ad74903e045c692941a";

// variable to save current weather as id
int weatherID = 0;
int weatherIDshortened = 0;

// variable to save the time of last check
unsigned long timecheck = 0;  

void setup() {
  // setting motor RPM
  motorControl.setSpeed(5);

  // DEMO OPENING AND CLOSING CURTAIN //
  openCurtain(PUSH_PULL_LENGTH);
  delay(1000);
  closeCurtain(PUSH_PULL_LENGTH);
  delay(1000);  
  
  // use IP 192.168.4.1 when having problems at usual connection
  while (status != WL_CONNECTED){
    Serial.print("Attempting to connect to network: ");
    Serial.println(wlanID);
    status = WiFi.begin(wlanID, wlanPASS);
    delay(10000);
  }
  Serial.println("Successfully connected to network");
  weatherCheck();            // refreshing weather variables after (re-)starting
}

void loop() {
 // make sure that weather and weather variables get refreshed after ca. 3 minutes
  if (millis() - timecheck >= 180000) {
    weatherCheck();
    timecheck = millis();

    // refresh curtainToClose via refreshed weather variables
    switch (weatherIDshortened) {
      case 2:
        curtainToClose = true;
        break;
      case 3:
        if (weatherID == 300 || weatherID == 301) {
          curtainToClose = true;
        } else {
        curtainToClose = false;
        }
        break;
     case 5:
        if (weatherID == 500) {
          curtainToClose = true;
        } else {
          curtainToClose = false;
        }
        break;
     case 6:
        if (weatherID == 600 || weatherID == 601) {
          curtainToClose = true;
        } else {
          curtainToClose = false;
        }
        break;
     case 7:
        if (weatherID == 741) {
          curtainToClose = false;
        } else {
          curtainToClose = true;
        }
        break;
     case 8:
        if (weatherID == 803 || weatherID == 804) {
          curtainToClose = false;
        } else {
          curtainToClose = true;
        }
        break;
    }
  }

  // close curtain when curtain is opened and should be close or open when opposite situation
  if (curtainToClose == true && curtainClosed == false) {
    closeCurtain(PUSH_PULL_LENGTH);
  } else if (curtainToClose == false && curtainClosed == true) {
    openCurtain(PUSH_PULL_LENGTH);
  }
  delay(3000);
}

// opening the curtain
void openCurtain(int steps) {
  // making the motor run continuous (COUNTERCLOCKWISE)
  Serial.println("opening curtain.");
  motorControl.step(steps);
  curtainClosed = false;
}

// closing the curtain
void closeCurtain(int steps) {
  // making the motor run continuous (CLOCKWISE)
  Serial.println("closing curtain.");
  motorControl.step(-steps);
  curtainClosed = true;
}

// get current weather conditions
void weatherCheck() {
  Serial.print("connecting to "); Serial.println("api.openweathermap.org");
  if (client.connect("api.openweathermap.org", 80)) {
    client.println("GET /data/2.5/weather?q=" + city + ",DE&units=metric&lang=de&APPID=" + api_key);
    client.println("Host: api.openweathermap.org");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  const size_t capacity = JSON_ARRAY_SIZE(2) + 2 * JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(14) + 360;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, client);
  client.stop();

  // weatherIDs available at https://openweathermap.org/weather-conditions
  weatherID = doc["weather"][0]["id"];
  weatherIDshortened = weatherID / 100;
}                          
