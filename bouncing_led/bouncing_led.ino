/*
  Bouncing LED.

  circuito constituido por cinco Leds, 5 Resistencias de 220 ohms cada una, cables,
  placa Arduino nano y protoboard.

  El objetivo de este ejercicio es conseguir que los Leds crean una coreografia especificada
  por nosotros, con el menor número de código posible.
  Para ello, cada Led irá conectado a un pin digital del arduino nano. Los Leds estarán colocados
  de forma que hagan un circuito paralelo. A su vez, cada led estara conectado en serie a una
  resistencia. Estos irán conectados a la salida de Tierra (GND) de nuestro arduino nano.

  Enciende y apaga un Led por segundo en orden para adelante y luego hacia atras

  Enara Agirrezabala
  Oinarria: Blink ariketa.

*/

// Definimos las variables que vayamos a utilizar
int i;  //contador
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
  //Definimos un bucle que hará que se encienda un led por segundo. Cada valor de la 
  //variable i llamara al pin que este en esa posición.

  //Encender-apagar pin 3-5-6-9-10
  //la variable i comienza del valor i=0; y va sumando 1 en cada paso.
  for (int i = 0; i < 5; i++) { 
    digitalWrite(led[i], true);  // Encender led
    delay(1000); // Esperar 1 s
    digitalWrite(led[i], false); // Apagar led
  }
  
  //Encender-apagar pin 9-6-5
  //la variable i comienza del valor i=3; y va restando 1 en cada paso.
  for (int i = 3; i >1; i--) {
    Serial.println(i);
    digitalWrite(led[i], true);  // Encender led
    delay(1000); // Esperar 1 s
    digitalWrite(led[i], false); // Apagar led
  }

}
