**Arduino Master-Slave SPI Communication**

**Overview**

This project demonstrates the implementation of SPI (Serial Peripheral Interface) communication between two Arduino boards (Master and Slave) using STM32. The Master sends data to the Slave, and the Slave responds based on the input it receives. Additionally, both Master and Slave use LEDs to visualize the communication process.

**Features**

1.Bidirectional SPI communication

2.Master sends data based on button input

3.Slave controls an LED based on received data

4.Slave sends feedback back to the Master

5.Real-time data monitoring using Serial Monitor

**Components Used**

2 Arduino Boards (Master and Slave),LEDs (2x),Push Button,10kΩ Resistor,Connecting Wires,

**Circuit Connections**

**Master**

Pin 7 -> LED (Master LED)

Pin 2 -> Push Button (With 10kΩ pull-down resistor to GND)

MOSI (Pin 11) -> MOSI (Slave Pin 11)

MISO (Pin 12) -> MISO (Slave Pin 12)

SCK (Pin 13) -> SCK (Slave Pin 13)

SS (Pin 10) -> SS (Slave Pin 10)

**Slave**

Pin 7 -> LED (Slave LED)

Pin 2 -> Push Button (With 10kΩ pull-down resistor to GND)

MOSI (Pin 11) -> MOSI (Master Pin 11)

MISO (Pin 12) -> MISO (Master Pin 12)

SCK (Pin 13) -> SCK (Master Pin 13)

SS (Pin 10) -> SS (Master Pin 10)

**Code Explanation**

**Master Code:**

1. Initializes SPI communication using SPI.begin() and sets clock to SPI_CLOCK_DIV8.

2. Reads the button input using digitalRead() and sends its state to the Slave using SPI.transfer().

3. Controls the Master LED based on the data received from the Slave.

**Slave Code:**

1. Configures SPI in Slave mode using SPCR |= _BV(SPE).

2. Uses an Interrupt Service Routine (ISR) to handle incoming data using SPI_STC_vect.

3. Turns ON/OFF the Slave LED based on the received data.

4. Reads the button input and sends its state back to the Master using SPDR.

**Conclusion**

This project provides a simple yet effective demonstration of SPI communication using Arduino. It helps beginners understand master-slave interaction, data exchange, and hardware control. It is ideal for applications like sensor data sharing, device synchronization, and remote monitoring.
