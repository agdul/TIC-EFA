/*
  Prueba 1: 0_Semáforo simple
  INSTRUCCIONES: Realizar un sketch en Arduino que permita
  encender tres LED’s con la lógica de funcionamiento de un
  semáforo simple. El proceso inicia con el encendido del VERDE.
*/

/*Declaramos las variables que vamos a utilizar*/
int ledRojo = 7, // ´7´ hace referencia al numero de pin que estamos utilizando en la placa arduino 
    ledAmarillo = 8, // ´8´ hace referencia al numero de pin que estamos utilizando en  la placa arduino
    ledVerde = 9, // ´9´ hace referencia al numero de pin que estamos utilizando en la placa arduino
    ledInicio = 0; // Por defecto no hay led encendido.

boolean inicio = true; // Una bandera para saber es el inicio del semaforo.

  /*
    Establecemos como salida los tres leds
  */
void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

  /*
    En el bucle simplemente preguntamos si la variable "inicio" es verdadera llamamos a la función "Inicio" sino llamamos a "Semaforo"
  */
void loop() {
  if(inicio == true){
    Inicio();
  } else{
    Semaforo();
  }
}

/*Funcion donde se encuentra la logica de nuestro Semaforo en el cual prende y apaga las luces*/
void Semaforo() {
    Prender(ledVerde);
    delay(10000);
    Apagar(ledVerde);
    Prender(ledAmarillo);
    delay(2000);
    Apagar(ledAmarillo);
    Prender(ledRojo);
    delay(10000);
    Apagar(ledRojo);
    Prender(ledAmarillo);
    delay(1000);
    Apagar(ledAmarillo);
}

/*
  Funcion cuando se ejecuta por primera vez nuestro semaforo el Inicio.
  es para dar un tiempo donde todas las luces esten apagadas.
  despues llama a la funcion Semaforo para prender nuestro semaforo.
*/
void Inicio(){
  inicio = false;
  Prender(ledInicio);
  delay(5000);
  Apagar(ledInicio);
  Semaforo();
}

/*Funcion que recibe un led en el cual vamos a cambiar su estado a prendido*/
void Prender(int led){
    digitalWrite(led, HIGH);
}

/*Funcion que recibe un led en el cual vamos a cambiar su estado ha apagar*/
void Apagar(int led){
    digitalWrite(led, LOW);

}
