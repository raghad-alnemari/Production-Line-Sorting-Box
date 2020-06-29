#include <Servo.h>

// defines pins numbers
const int trigPin1 = 9;
const int echoPin1 = 10;

const int trigPin2 = 7;
const int echoPin2 = 8;

const int trigPin3 = 5;
const int echoPin3 = 6;

int ServoPin = 3;

Servo Servo1;

// defines variables
long duration1;
int distance1;

long duration2;
int distance2;

long duration3;
int distance3;


void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT); 

pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT); 


pinMode(ServoPin, OUTPUT);

Serial.begin(9600); 
Servo1.attach(ServoPin); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);

// Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance2= duration2*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance2: ");
Serial.println(distance2);

// Clears the trigPin
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration3 = pulseIn(echoPin3, HIGH);
// Calculating the distance
distance3= duration3*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance3: ");
Serial.println(distance3);


if (distance3 <= 30) {
   Servo1.write(180); 
}

else if (distance2 <= 30) {
   Servo1.write(90); 
}

else {
   Servo1.write(0); 
}


}
