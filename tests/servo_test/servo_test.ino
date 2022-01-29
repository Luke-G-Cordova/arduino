#include <Servo.h>

Servo servo;
int vrx = A0;
int vry = A1;
int sw = A2;
void setup(){
    // servo.attach(9);

    Serial.begin(9600);
}

int x = 0, y = 0, s = 0;
bool off = false;
void loop(){
    s = analogRead(sw);
    if (s == 0){
        off = !off;
        delay(500);
    }
    if (!off){
        x = analogRead(vrx);
        y = analogRead(vry);
        servo.attach(9);
        servo.write(map(x, 0, 1023, 180, 0));
    }
    else{
        if (servo.attached()){
            servo.detach();
        }
    }

}
