# arduinoNRF24dh11
Use an Arduino to read the temp &amp; humidity from a DH11 and send the values via a NRF24L01 to another Arduino

First Arduino, used an Uno
Connect the nRF24L01+ module's Vcc pin to the 3.3V pin on the Arduino.
Connect the nRF24L01+ module's GND pin to the GND pin on the Arduino.
Connect the nRF24L01+ module's CE pin to pin 9 on the Arduino.
Connect the nRF24L01+ module's CSN pin to pin 10 on the Arduino.
SCK: connected to digital pin 13 on the Arduino
MOSI: connected to digital pin 11 on the Arduino
MISO: connected to digital pin 12 on the Arduino
Connect a pushbutton to pin 2 on the Arduino.
Connect a DHT11 temperature and humidity sensor to pin 3 on the Arduino.

Second Arduino, used a Mega ADK

nRF24L01:
VCC to 3.3V pin on Arduino
GND to GND pin on Arduino
CE to digital pin 9 on Arduino
CSN to digital pin 10 on Arduino
SCK to digital pin 13 on Arduino
MOSI to digital pin 11 on Arduino
MISO to digital pin 12 on Arduino
