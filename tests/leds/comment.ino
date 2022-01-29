// void setup(){
//     for(int i = 0;i<4;i++){
//         pinMode(leds[i], OUTPUT);
//     }
//     pixels.begin();
// }

// void loop(){
//     x = analogRead(jStck);
//     last = cur;
//     cur = map(x, 0, 1024, 0, 12);
    
    // if(cur != last){
        
    //     if(cur > 7){
    //         digitalWrite(leds[cur-8], HIGH);
    //         if(last<=7){
    //             pixels.setPixelColor(last, pixels.Color(0,0,0));
    //             pixels.show();
    //         }else{
    //             digitalWrite(leds[last-8], LOW);
    //         }
    //     }else{
    //         if(cur%2==0){
    //             pixels.setPixelColor(cur, pixels.Color(100,40,0));
    //         }else{
    //             pixels.setPixelColor(cur, pixels.Color(100,0,0));

    //         }
    //         if(last > 7){
    //             digitalWrite(leds[last-8], LOW);
    //         }else{
    //             pixels.setPixelColor(last, pixels.Color(0,0,0));

    //         }
    //         pixels.show();
    //     }
    // }
// }