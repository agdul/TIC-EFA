/*
  Prueba 1: Semáforo simple
  INSTRUCCIONES: Realizar un sketch en Arduino que permita
  encender tres LED’s con la lógica de funcionamiento de un
  semáforo simple. El proceso inicia con el encendido del VERDE.
*/

/*unsigned long: variable de tamaño extendido para almacenar datos numericos, utilizado para guardar datos millis() */
unsigned long ultimosMilisegundos = 0,
              milisegundosActuales;

int ledRojo = 7,
    ledAmarillo = 8,
    ledVerde = 9,
    SEGUNDOS_DE_ESPERA_VERDE_Y_ROJO = 5 * 1000, // En mi caso puse que el verde y rojo duren 10 segundos (10,000 milisegundos)
    SEGUNDOS_DE_ESPERA_AMARILLO = 2 * 1000,      // En mi caso puse que el amarillo dure 2 segundos (2,000 milisegundos)
    LED_ACTUAL = 0; // Por defecto no hay led encendido

void setup() {
  /*
    Establecemos como salida los tres leds
  */
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  /*
    En el bucle simplemente llamamos a la función "semaforo"
  */
  semaforo();
}

void semaforo() {
  /*millis(): Funcion que nos permite obtener los milisegundos que pasaron desde que comenzo la ejecucion el codigo*/
  milisegundosActuales = millis(); // Obtenemos los milisegundos actuales

  // Nos fijamos en cuál led está encendido...
  switch (LED_ACTUAL) {
    case 9:
      if (elTurnoDeVerdeORojoHaTerminado())
        cambiaA(ledAmarillo);
      break;
    case 8:
      if (elTurnoDeAmarilloHaTerminado())
        cambiaA(ledRojo);
      break;
    case 7:
      if (elTurnoDeVerdeORojoHaTerminado())
        cambiaA(ledVerde);
      break;

    // Por defecto encenderá el verde al inicio
    default:
      cambiaA(ledVerde);
      break;
  }
}

boolean elTurnoDeVerdeORojoHaTerminado() {
  /*
    Simple función que compara el tiempo que lleva encendido el led verde o rojo
    ya que ambos duran 10 segundos encendidos.
    Devuelve verdadero si ya estuvo encendido 10 segundos, falso en caso contrario
  */
  if (milisegundosActuales - ultimosMilisegundos >= SEGUNDOS_DE_ESPERA_VERDE_Y_ROJO) {
    ultimosMilisegundos = milisegundosActuales;
    return true;
  }
  return false;
}

boolean elTurnoDeAmarilloHaTerminado() {
  /*
    Simple función que compara el tiempo que lleva encendido el led amarillo
    Devuelve verdadero si ya estuvo encendido 2 segundos, falso en caso contrario
  */
  if (milisegundosActuales - ultimosMilisegundos >= SEGUNDOS_DE_ESPERA_AMARILLO) {
    ultimosMilisegundos = milisegundosActuales;
    return true;
  }
  return false;
}

void cambiaA(int nuevoLed) {
  /*
    Función ayudante que apaga el led y enciende el nuevo,
    además de asignar a LED_ACTUAL el valor del (valga la redundancia)
    led actual
  */
  digitalWrite(LED_ACTUAL, LOW);
  LED_ACTUAL = nuevoLed;
  digitalWrite(LED_ACTUAL, HIGH);
}