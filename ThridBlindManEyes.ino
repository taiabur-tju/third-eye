//viral science
//Ultrasonic Distance alarm
const int trigPin = 11;
const int echoPin = 12;
//const int buzzer = 11;
//const int ledPin = 10;
//#define ledPin 10
// defines variables
long duration;
int distance;
int safetyDistance;
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(8,9); // RX | TX


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//pinMode(buzzer, OUTPUT);
//pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
 BTSerial.begin(115200);
}


void loop() {
// Clears the trigPin
//digitalWrite(ledPin, HIGH);

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= (duration/2)/29.1;

safetyDistance = distance;
//if (safetyDistance < 20){ //Enter the Distance 
//  //digitalWrite(buzzer, HIGH);
// digitalWrite(ledPin, HIGH);
//}
//else{
//// // digitalWrite(buzzer, LOW);
//digitalWrite(ledPin, LOW);
//}

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");

BTSerial.println(distance);
//Serial.println(distance);
delay(1000);
}
