#include <Servo.h>
Servo MyServo;                       
int const potPin = A0;
int pot_val;                // potentiometer
int angle;                 // servo's angle

void setup() {
    MyServo.attach(9);       // attach MyServo into SERVO_PIN
    
    Serial.begin(9600);         // start the Serial Monitor
}

void loop() {
    pot_val = analogRead(potPin);
    Serial.print("pot_val: ");
    Serial.print(pot_val);
    angle = map(pot_val, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);
    MyServo.write(angle);
    delay(15);
}
