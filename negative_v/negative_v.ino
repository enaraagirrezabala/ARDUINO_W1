/*
  vu meter.

  circuito constituido por cinco Leds, 5 Resistencias de 220 ohms cada una, cables,
  placa Arduino nano y protoboard.

  Enciender Led por segundo en orden y dejarlo encendido.

  Enara Agirrezabala
  Oinarria: Blink ariketa.

*/

// Definimos las variables que vayamos a utilizar
int i;  //contador
int k;
int j;
int led [] = {3, 5, 6, 9, 10};//Definimos el array que contiene los números de
// vayamos a colocar nuestros leds, en este caso, pin 3,5,6,9,10

void setup() {
  // Definimos cada pin como output. Tendremos 4 pins por lo que el contador irá de 0
  //hasta llegar a 5, ya que la primera posición dentro del array es 0 (a0,a1,a2,a3)
  // Abrir el puerto de seial.
  Serial.begin(9600);
  for (int i = 0 ; i < 5; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  //Encender todos los leds
  for (int p = 0; p < 256; p++) {
    for (int i = 0; i < 5; i++) {
      analogWrite(led[i], p);  // Encender led
    }
    delay(15);
  }
  delay(1000); // Esperar 1

  //Apagar el led situado en la mitad y despues los que esten situados al lado suyo. led anterior
  //led posterior.


  for (int k = 0; k < 3; k++) {
    for (int p = 255; p >= 0; p--) {
      i = 2 - k; //posición de led anterior
      j = 2 + k; //posición de led posterior en el array
      analogWrite(led[i], p);  // apagar
      analogWrite(led[j], p); // apagar
      delay(15);
    }
    delay(1000); // esperar 1 s
  }
}
