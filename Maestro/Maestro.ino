#include <Wire.h>

#define LED_ROJO 2
#define LED_AMARILLO 3
#define LED_VERDE 4
#define LED_VERDE_VUELTA 5

void setup() {
  Wire.begin(0x08); // Inicializa el esclavo con la dirección I2C correspondiente
  Wire.onReceive(receiveEvent); // Configura el evento de recepción
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERDE_VUELTA, OUTPUT);
}

void loop() {
  delay(3000); // Espera 1 segundo
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read(); // Lee el comando recibido
    if (c == 'R') {
      encenderRojo();
    } else if (c == 'Y') {
      encenderAmarillo();
    } else if (c == 'G') {
      encenderVerde();
    } else if (c == 'g') {
      encenderVerdeVuelta();
    }
    
    
  }
}

void encenderRojo() {
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

void encenderAmarillo() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, LOW);
}

void encenderVerde() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERDE_VUELTA, LOW);
}

void encenderVerdeVuelta() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERDE_VUELTA, HIGH);
}
