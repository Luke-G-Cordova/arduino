
#include <Adafruit_NeoPixel.h>





int jStck = A0;
int x = 0, speed = 0;

class Display {
    public: 
        int cur;
        int last;
        Adafruit_NeoPixel pixels;
        int leds[4];
        void init();
        void update();
        void move(int dir);
};

Display disp;

void setup(){
    Serial.begin(9600);
    disp.init();
}

void loop(){
    x = analogRead(jStck);
    speed = x < 1024 / 2 ? map(x, 0, 512, 0, 2048) : map(1024 - x, 0, 512, 0, 2048);
    if(x < 1024 / 2){
        Serial.println(x);
    }
    
    x = map(x, 0, 1024, -1, 2);
    
    disp.move(x);

    disp.update();
    delay(speed);
}

void Display::init(){
    leds[0] = 7;
    leds[1] = 8;
    leds[2] = 12;
    leds[3] = 13;
    cur = 0;
    last = 0;
    pixels = Adafruit_NeoPixel(8, 4, NEO_GRB + NEO_KHZ800);
    for(int i = 0;i<4;i++){
        pinMode(leds[i], OUTPUT);
    }
    pixels.begin();
}
void Display::update(){
    if(cur != last){
        cur = cur == -1 ? 11 : cur == 12 ? 0 : cur;
        if(cur > 7){
            digitalWrite(leds[cur-8], HIGH);
            if(last<=7){
                pixels.setPixelColor(last, pixels.Color(0,0,0));
                pixels.show();
            }else{
                digitalWrite(leds[last-8], LOW);
            }
        }else{
            if(cur%2==0){
                pixels.setPixelColor(cur, pixels.Color(100,40,0));
            }else{
                pixels.setPixelColor(cur, pixels.Color(100,0,0));
            }
            if(last > 7){
                digitalWrite(leds[last-8], LOW);
            }else{
                pixels.setPixelColor(last, pixels.Color(0,0,0));

            }
            pixels.show();
        }
    }
}
void Display::move(int dir){
    last = cur;
    cur += dir;
}