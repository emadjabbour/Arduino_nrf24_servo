#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo s;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  s.attach(3);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  String i ;
  int Angel_value;
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));

for(int o = 0 ; o < sizeof(text);o++){
  i+=text[o];
}
Angel_value = map(i.toInt(),0,1023,10,169);
s.write(Angel_value);
    Serial.println();
  }
}
