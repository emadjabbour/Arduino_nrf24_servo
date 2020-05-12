#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
    int iVarToCast = analogRead(A0);
  char buffer[4];
  dtostrf(iVarToCast, 4, 0, buffer);
  radio.write(&buffer, sizeof(buffer));
  delay(100);
}
