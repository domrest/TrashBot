<h1 align="center"> Temperature Sensors </h1>


## Temperature Sensor Component

The temperature sensors utilised within the system are two TSIC 306 sensors
These can be found on <a href="https://uk.rs-online.com/web/p/temperature-humidity-sensor-ics/1218022/">RS-Online</a> for a price of £6.46 each.
These temperature sensors have a refresh rate of 10 Hz, and an error of +-0.3 Degrees.


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
