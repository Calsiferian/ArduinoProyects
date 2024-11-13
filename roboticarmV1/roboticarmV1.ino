#include "servoSG90.h"
 
servoSG90 garra = servoSG90(0x40, 580 , 210, 4); // 0x40 Dirección del PCA9685
                                                // 580 Maxima posición del servo.
                                                // 210 Minima posición del servo.
                                                // 4 pin de conexión con el PCA9685 del servo
                                               
servoSG90 base = servoSG90(0x40, 550,120 , 0);
                                                
servoSG90 motor1 = servoSG90(0x40,300,100 , 1); 

servoSG90 motor2 = servoSG90(0x40,300,220 , 2); 

servoSG90 motor3 = servoSG90(0x40,430,290 , 3); 
                                                


void setup() {
  Serial.begin(9600);  
  
  base.init();
  garra.init();
  motor1.init();
  motor2.init();
  motor3.init();
  home();
  
}

void loop() {
AtoB(); 
}

void home(){
  base.moverMin();
  motor1.moverMax();
  motor2.moverMax();
  motor3.moverMax();

}
void AtoB(){
  base.cerrar(10);
  bajar();
  garra.cerrar(0); 
  delay(2000);
  subir();
  base.abrir(10);
  bajar();
  garra.abrir(0);
  subir();
}

void bailar(){
  subir();
  bajar();
  base.moverMin();
  subir();
  bajar();
  base.moverMedio();
  subir();
  bajar();
  base.moverMax();
  subir();
  bajar();
  base.moverMedio();

}


void bajar(){

  
  motor1.abrir(5);
  Serial.println("motor 1 abierto");
  motor2.abrir(5);
  Serial.println("motor 2 abierto");
  motor3.abrir(5);
  Serial.println("motor 3 abierto");

}

void subir(){

  motor1.cerrar(5); 
  motor2.cerrar(5);
  motor3.cerrar(5);  
}

