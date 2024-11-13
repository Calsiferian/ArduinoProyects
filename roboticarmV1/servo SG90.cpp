#include "servoSG90.h"

// Constructor que inicializa los límites máximo y mínimo
servoSG90::servoSG90(uint8_t addr, int maxLimit, int minLimit,int numberServo )
    : Adafruit_PWMServoDriver(addr), 
    maxLimit(maxLimit), 
    minLimit(minLimit), 
    numberServo(numberServo),
    abierto(false){}
void servoSG90::init() {
    begin();
    setPWMFreq(50);
}
void servoSG90::moverMax() {
    // Ajusta el ángulo dentro de los límites máximo y mínimo
    
    setPWM(numberServo, 0, maxLimit);
    delay(500);
}
void servoSG90::moverMin() {
    // Ajusta el ángulo dentro de los límites máximo y mínimo
    
    setPWM(numberServo, 0, minLimit);
    delay(500);
}
void servoSG90::moverMedio() {
    // Ajusta el ángulo dentro de los límites máximo y mínimo
   
    setPWM(numberServo, 0, ((maxLimit-minLimit)/2)+minLimit);
    delay(500);
}


void servoSG90::abrir(int time=0) {
    // Ajusta el ángulo dentro de los límites máximo y mínimo
    if(abierto==false){
      for(int pos=minLimit; pos<maxLimit;pos++){
        setPWM(numberServo, 0, pos);
        //Serial.println(pos);
        delay(time);
      }
    abierto=true;
    }
}
void servoSG90::cerrar(int time=0) {
    // Ajusta el ángulo dentro de los límites máximo y mínimo
    if(abierto==true){
      for(int pos=maxLimit; minLimit<pos;pos--){
        setPWM(numberServo, 0, pos);
        //Serial.println(pos);
        delay(time);
      }
    abierto=false;
    }
}
