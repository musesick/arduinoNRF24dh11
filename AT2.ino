#include <RF24.h>

// Initialize the radio object
RF24 radio(22, 23);

// Define the address for the radio
const byte address[6] = "00001";

// Initialize variables to hold data received from AT1
int currentScreen = 0;
float temperature = 0.0;
float humidity = 0.0;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() 
{
  if (radio.available()) 
  {
    radio.read(&currentScreen, sizeof(currentScreen));
    radio.read(&temperature, sizeof(temperature));
    radio.read(&humidity, sizeof(humidity));

    // Print the received data to the serial connection
    Serial.print("Screen: ");
    Serial.print(currentScreen);
    Serial.print(", Temperature: ");
    Serial.print(temperature);
    Serial.print(", Humidity: ");
    Serial.println(humidity);
  }
  delay(1000);
}
