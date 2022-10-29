/*
  Prueba: simple_Semáforo 
  INSTRUCCIONES: Realizar un sketch en Arduino que permita
  encender tres LED’s con la lógica de funcionamiento de un
  semáforo simple. El proceso inicia con el encendido del VERDE.
*/

/*Declaramos las variables que vamos a utilizar*/
int ledRojo = 7, // ´7´ hace referencia al numero de pin que estamos utilizando en la placa arduino. 
    ledAmarillo = 8, // ´8´ hace referencia al numero de pin que estamos utilizando en  la placa arduino.
    ledVerde = 9; // ´9´ hace referencia al numero de pin que estamos utilizando en la placa arduino.


  /*
    Establecemos como salida los tres leds
  */
void setup(){
    pinMode(ledRojo, OUTPUT);
    pinMode(ledAmarillo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
}

 /*
    En el bucle prendemos nuestro semaforo 
  */
void loop(){
    digitalWrite(ledVerde, HIGH);
    delay(10000);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    delay(2000);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    delay(10000);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, HIGH);
    delay(1000);
    digitalWrite(ledAmarillo, LOW);
}