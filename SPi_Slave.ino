#include <SPI.h>

#define LEDpin 7
#define buttonpin 2

volatile boolean received;
volatile byte Slavereceived, Slavesend;
int buttonvalue;
int x;

void setup() {
  Serial.begin(9600);

  pinMode(buttonpin, INPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(MISO, OUTPUT);  // Set MISO as OUTPUT to send data to Master

  SPCR |= _BV(SPE);  // Enable SPI in Slave Mode
  received = false;

  SPI.attachInterrupt();  // Enable SPI interrupt
}

ISR(SPI_STC_vect) {  // SPI Interrupt Service Routine
  Slavereceived = SPDR;  // Store received value from master
  received = true;  // Set flag to indicate data is received
}

void loop() {
  if (received) {
    received = false;  // Reset flag after processing

    // Control LED based on received data
    if (Slavereceived == 1) {
      digitalWrite(LEDpin, HIGH);  // LED ON
      Serial.println("Slave LED ON");
    } else {
      digitalWrite(LEDpin, LOW);   // LED OFF
      Serial.println("Slave LED OFF");
    }

    // Read button state with debounce
    delay(50);  // Simple debounce delay
    buttonvalue = digitalRead(buttonpin);
    x = (buttonvalue == HIGH) ? 1 : 0;

    Slavesend = x;
    SPDR = Slavesend;  // Send button state to master
  }
}
