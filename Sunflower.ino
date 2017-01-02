/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int photocellPin = A2;
int photocellVal = 0;
int sunflower = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  photocellVal = analogRead(photocellPin);
  Serial.print(sunflower);
  Serial.print(" ");
  Serial.println(photocellVal);
  
  if(photocellVal > 500 && sunflower == 1){
    for (pos = 0; pos <= 180; pos += 3) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    sunflower = 0;
  }
  if(photocellVal < 500 && sunflower == 0){
    for (pos = 180; pos >= 0; pos -= 3) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    sunflower = 1;
  }
}

