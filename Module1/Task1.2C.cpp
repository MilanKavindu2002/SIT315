const int motionPin1 = 2;   // Pin connected to the first motion sensor output
const int motionPin2 = 3;   // Pin connected to the second motion sensor output
const int ledPin1 = 13;     // Pin connected to the first LED
const int ledPin2 = 12;     // Pin connected to the second LED

volatile bool motionDetected1 = false; 
volatile bool motionDetected2 = false; 

void setup() {
  pinMode(motionPin1, INPUT);   // Set motionPin1 as input
  pinMode(motionPin2, INPUT);   // Set motionPin2 as input
  pinMode(ledPin1, OUTPUT);     // Set ledPin1 as output
  pinMode(ledPin2, OUTPUT);     // Set ledPin2 as output
  Serial.begin(9600);          // Initialize serial communication
  
  // Attach interrupts to motionPin1 and motionPin2
  attachInterrupt(digitalPinToInterrupt(motionPin1), handleMotion1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motionPin2), handleMotion2, CHANGE);
}

void loop() {
  if (motionDetected1) {
    digitalWrite(ledPin1, HIGH); // Turn LED 1 on
    Serial.println("Motion detected by Sensor 1! LED 1 ON");
    motionDetected1 = false;     
  } else {
    digitalWrite(ledPin1, LOW);  // Turn LED 1 off
  }

  if (motionDetected2) {
    digitalWrite(ledPin2, HIGH); // Turn LED 2 on
    Serial.println("Motion detected by Sensor 2! LED 2 ON");
    motionDetected2 = false;     
  } else {
    digitalWrite(ledPin2, LOW);  // Turn LED 2 off
  }
  
  delay(1000); // Wait for 1 second before next check
}

// Interrupt Service Routine (ISR) for handling motion on Sensor 1
void handleMotion1() {
  motionDetected1 = true;  
}

// Interrupt Service Routine (ISR) for handling motion on Sensor 2
void handleMotion2() {
  motionDetected2 = true;  
}
