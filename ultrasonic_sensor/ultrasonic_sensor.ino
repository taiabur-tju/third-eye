// defines pins numbers
const int trigPin = A5;
const int echoPin = A0;
const int lightRed= A1;
const int lightGreen= A3;
// defines variables
long duration;
int distance;

void setup() {
pinMode(lightRed,OUTPUT);
pinMode(lightGreen,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
if(distance <= 5){
  digitalWrite(lightRed, HIGH);
  digitalWrite(lightGreen, LOW);
  delay(100);
}
if(distance > 5 ){
   digitalWrite(lightRed, LOW);
   digitalWrite(lightGreen, HIGH);
   delay(100);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
