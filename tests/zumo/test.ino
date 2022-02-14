#include <Servo.h>



#define echoPin 2
#define trigPin 5

long duration;
int distance;
Servo servo;

void setup(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    // servo.attach(11);

    Serial.begin(9600);
}

int x = 0;
int dir = 1;
void loop(){

    x += dir;
    // Serial.println(x);
    delay(1);
    if(x==180||x==0){
        dir *= -1;
    }
    // servo.write(x);

    // digitalWrite(trigPin, LOW);
    // delayMicroseconds(2);
    // digitalWrite(trigPin, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(trigPin, LOW);
    // duration = pulseIn(echoPin, HIGH);
    // distance = duration * 0.034 / 2;
    // Serial.print("Distance: ");
    // Serial.print(distance);
    // Serial.println(" cm");


}