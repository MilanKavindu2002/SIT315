const int motionPin = 2;  // Pin connected to the motion sensor output
const int ledPin = 13;    // Pin connected to the LED

volatile bool motionDetected = false; 

void setup() {
  pinMode(motionPin, INPUT);   // Set motionPin as input
  pinMode(ledPin, OUTPUT);     // Set ledPin as output
  Serial.begin(9600);          // Initialize serial communication
  
  // Attach interrupt to motionPin, 
  attachInterrupt(digitalPinToInterrupt(motionPin), handleMotion, CHANGE);
}

void loop() {
  if (motionDetected) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("Motion detected! LED ON");
    motionDetected = false;     
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED off
    Serial.println("No motion. LED OFF");
  }
  delay(1000); // Wait for 1 second before next check
}

// Interrupt Service Routine (ISR) for handling motion
void handleMotion() {
  motionDetected = true;  
}
