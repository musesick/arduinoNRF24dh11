#include <DHT.h>
#include <RF24.h>

// Initialize the button pin
int buttonPin = 7;

// Initialize the current screen index
int currentScreen = 0;

// Initialize the radio object
RF24 radio(2, 4);

// Define the address for the radio
const byte address[6] = "00001";

#define DHTPIN 8 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

float temperature;
float humidity;

bool buttonPressed = false;

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);
  radio.begin();
  radio.openWritingPipe(address);
  dht.begin();
  
  // Start the serial connection
  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(buttonPin) == LOW && !buttonPressed) 
  {
    buttonPressed = true;
    currentScreen = (currentScreen + 1) % 3;

    // Read the temperature and humidity data
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    // Send the data to the second Arduino
    radio.write(&currentScreen, sizeof(currentScreen));
    radio.write(&temperature, sizeof(temperature));
    radio.write(&humidity, sizeof(humidity));
    
    // Print the data to the serial connection
    Serial.print("Screen: ");
    Serial.print(currentScreen);
    Serial.print(", Temperature: ");
    Serial.print(temperature);
    Serial.print(", Humidity: ");
    Serial.println(humidity);
  }
  
  if (digitalRead(buttonPin) == HIGH && buttonPressed) 
  {
    buttonPressed = false;
  }
}
