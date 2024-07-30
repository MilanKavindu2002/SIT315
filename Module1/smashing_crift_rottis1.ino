const int motionPin = 2;  // Pin connected to the motion sensor output
const int ledPin = 13;    // Pin connected to the LED

void setup() {
  pinMode(motionPin, INPUT);   // Set motionPin as input
  pinMode(ledPin, OUTPUT);     // Set ledPin as output
  Serial.begin(9600);          // Initialize serial communication
}

void loop() {
  int motionDetected = digitalRead(motionPin); // Read motion sensor
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("Motion detected! LED ON");
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED off
    Serial.println("No motion. LED OFF");
  }
  delay(1000); // Wait for 1 second before next read
}
