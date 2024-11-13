#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#ifndef SERVOSG90_H
#define SERVOSG90_H


class servoSG90 : public Adafruit_PWMServoDriver {
public:
    // Constructor que recibe los valores de límite máximo y mínimo
    servoSG90(uint8_t addr , int maxLimit, int minLimit,int numberServo);
    void init();
  
    void moverMax();
    void moverMin();
    void moverMedio();
    void abrir(int time);
    void cerrar(int time);
private:
    int maxLimit;  // Atributo para el límite máximo del ángulo
    int minLimit;  // Atributo para el límite mínimo del ángulo
    int numberServo;  // Atributo para el numero del servo en el PCA
    bool abierto;
};

#endif
