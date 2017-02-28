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
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], true);  // Encender led
  }
  delay(1000); // Esperar 1
  //Apagar el led situado en la mitad y despues los que esten situados a su alrededor.
  for (int k = 0; k < 3; k++) {
    i=2-k;
    j=2+k;
    digitalWrite(led[i], false);  // Encender led
    digitalWrite(led[j], false);
    delay(1000);
  }
 
}
