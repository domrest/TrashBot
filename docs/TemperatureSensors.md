<h1 align="center"> Temperature Sensors </h1>

## Temperature Sensor usage

Trashbot receives its temperature readings via two Tsic 306 temperature sensors, which have an error of +-0.3 K and a sampling rate of 10 Hz.
These are connected to the Pi via the ground and 5V Power, and with the data pins connected to seperate GPIO ports.
The TSIC Temperature Sensors will communicate to the Pi passing the current temperature reading from the sensor through two packets of data transmitted at a Baud Rate of 8kHz
This is done through the ZACWire Protocol.
The Pi will interrupt on every bit received, storing the bit and decoding it into a temperature once both packets arrive.


## Temperature Sensor Component

As stated the temperature sensors utilised within the system are two TSIC 306 sensors
These can be found on <a href="https://uk.rs-online.com/web/p/temperature-humidity-sensor-ics/1218022/">RS-Online</a> for a price of £6.46 each.


<p align="center">
<img src="../images/Tsic306.jpg" alt="Tsic 306 sensor">
</p>

The sensor has Three pins:
- Power
- Data
- Ground
Which were soldered to distinct wires

The Power wires were then connected to the same Power pin on the Raspberry Pi, similarly to the Ground wires conencted to the same ground pin on the raspberryPi.
GPIO pins 23 and 24 were connected to the remaining Data wires.

<p align="center">
<img src="../images/GPIO-Pinout-Diagram-2.png" alt="Raspberry Pi 3 Pinouts">
</p>
