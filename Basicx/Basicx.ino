/*
  GP20U7 GPS Library - Basic
 Demonstrates the use of the GP20U7 GPS unit by retrieving the latitude
 and longitude of your current position.

 The circuit:
 * GP20U7 TX pin to digital pin 0/RX
 * GP20U7 VCC pin to 3.3V
 * GP20U7 GND pin to ground

 NOTE: The GPS unit can take up to a minute or more to acquire a position
 lock and start outputting data. That means you may not see the serial
 output right away which is normal.
 
 */

// include the library code:
#include <gp20u7.h>
#include <SoftwareSerial.h>
#include <SerialCommand.h> 
const byte RX = 3;
const byte TX = 2; 
// initialize the library with the serial port to which the device is
// connected
GP20U7 gps = GP20U7(Serial);
SoftwareSerial mySerial = SoftwareSerial(RX, TX); 
SerialCommand sCmd(mySerial);
// Set up a Geolocation variable to track your current Location
Geolocation currentLocation;

void setup() {
  // Start the GPS module
  gps.begin();
  Serial.begin(9600);
  mySerial.begin(57600);
  mySerial.println("Your current location is:");
  Serial.println("Your current location is:");
}

void loop() {
  // The call to read() checks for new location information and returns 1
  // if new data is available and 0 if it isn't. It should be called
  // repeatedly.
  if(gps.read()){
    currentLocation = gps.getGeolocation(); 
    mySerial.println("Your current location is:");
    mySerial.print("    Latitude: ");
    mySerial.println(currentLocation.latitude,5);
    mySerial.print("    Longitude: ");
    mySerial.println(currentLocation.longitude,5);
  }
}
