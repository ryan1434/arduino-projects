// Global variables
int sensor_val;
int sensor_high = 0;    // initial min of the photocell
int sensor_low  = 1023; // initial max of the photocell
const int ledPin = 13;
void setup() {

    pinMode(ledPin,   OUTPUT);
    digitalWrite(ledPin, HIGH);
 
    while (millis() < 5000) {
        sensor_val = analogRead(A0);
 
        if (sensor_val > sensor_high) {
            sensor_high = sensor_val; // set new max value
        }
 
        if (sensor_val < sensor_low) {
            sensor_low = sensor_val; // set new min value
        }
    }
    // calibration completed - red light turned off
    digitalWrite(ledPin, LOW);
}
 
void loop() {
    sensor_val = analogRead(A0);
    int pitch = map(sensor_val, sensor_low, sensor_high, 50, 4000);
    tone(8, pitch, 20);
    delay(10);
}
