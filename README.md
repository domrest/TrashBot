<h1 align="center"> TrashBot </h1>

<p align="center">
<img src="images/Facebook Post 940x788 px (3).gif" alt="logo for Trashbot">
</p>

Your gateway into the future!
</br>
TrashBot is an open-source project which monitors the temperature of the trash bins and reminds you to take out the trash before it goes bad!
</br>
</br>
<div align="center">
  <img src="images/Facebook Post 940x788 px (4).gif" alt="Animation" width="600">
</div>
</br>
<p align="center">
    </br>
    <a href="https://www.trashbot.info/"><strong>Checkout the website »</strong></a>
    </br>
    </br>    ·
    <a href="https://github.com/domrest/TrashBot/issues">Report Bug</a>
    ·
    <a href="https://github.com/domrest/TrashBot/issues">Request Feature</a>
</p>

<p align="center">
<a href="https://www.facebook.com/TrashBotOfficial"><img  src="images/fb_logo.png"  width="44" height="44">
<img src="images/instagram_logo.png" width="44" height="44">
<img  src="images/utube_logo.png"  width="47" height="47">
</p>

<div align="center">

[![Contributors](https://img.shields.io/github/contributors/domrest/TrashBot.svg?style=for-the-badge&logo=probot&color=1abc9c)](https://github.com/domrest/TrashBot/graphs/contributors)
[![Forks](https://img.shields.io/github/forks/domrest/TrashBot.svg?style=for-the-badge&logo=probot&color=1abc9c)](https://github.com/domrest/TrashBot/network/members)
[![Stars](https://img.shields.io/github/stars/domrest/TrashBot.svg?style=for-the-badge&logo=probot&color=1abc9c)](https://github.com/domrest/TrashBot/stargazers)
[![Issues](https://img.shields.io/github/issues/domrest/TrashBot.svg?style=for-the-badge&logo=probot&color=1abc9c)](https://github.com/domrest/TrashBot/issues)
[![License](https://img.shields.io/github/license/domrest/TrashBot.svg?style=for-the-badge&logo=probot&color=1abc9c)](https://github.com/domrest/TrashBot/blob/main/LICENSE)
</div>
<div align="center">

![](https://img.shields.io/badge/OS-Debian-informational?style=plastic&color=1f425f)
![](https://img.shields.io/badge/Hardware-RaspberryPi4-informational?style=plastic&color=1f425f)
![](https://img.shields.io/badge/Hardware-Tsic306-informational?style=plastic&logo=<LOGO_NAME>&logoColor=white&color=1f425f)
![](https://img.shields.io/badge/Hardware-Sensors-informational?style=plastic&logo=<LOGO_NAME>&logoColor=white&color=1f425f)
![](https://img.shields.io/badge/Code-C++-informational?style=plastic&logo=<LOGO_NAME>&logoColor=white&color=1f425f)
</div>
</br>

<div align="center">
<a href="https://hackaday.io/project/179098-trashbot">  <img  src="images/hack2.png"  width="47" height="47">
  </div>
<!-- TABLE OF CONTENTS -->

## Table of contents
<ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#getting-started">Getting Started</a>
       <ul>
          <li><a href="#Prerequisites">Prerequisites</a</li>
          <li><a href="#Installation">Installation</a</li> 
          <li><a href="#temperature sensors">temperature sensors</a</li>
          <li><a href="#gui">gui</a</li>
          <li><a href="#email alert">email alert</a</li>
       </ul>
       </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contribution">Contribution</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
</ol>
        
## About The Project


## Getting Started

There are 3 components to this project - `email alert`, `gui`, and `temperature sensors`.

### `temperature sensors` 
More documentation about `temperature sensors` can be found [here](./docs/TemperatureSensors.md)
### `email alert `
More documentation about `email alert ` can be found [here](./docs/Messaging.md)
### `gui`
More documentation about `gui` can be found [here](./docs/GUI.md)

To get the project up and running by yourself, follow these steps:
### Prerequisites

GUI Prerequisites:

`apt-get install qtdeclarative5-dev-tools`

`apt-get install libqcustomplot-dev`

Email Messaging Prerequisites:

`sudo apt-get install libssl-dev`

`sudo apt-get install libboost-all-dev`

Temp Sensor Prerequisites:

`sudo apt-get install pigpio python-pigpio python3-pigpio`


### Installation

Run Cmake within directory:

`cmake .`

Run Make:

`make`

Run Program:

`sudo ./Trashbot`



## Roadmap
See the [open issues](https://github.com/domrest/ChoreBot/issues) for a list of proposed features (and known issues).

## Contribution
Want to contribute? Great!
To fix a bug or enhance an existing module, follow these steps:

1. Fork the repo
2. Create your new Branch (`git checkout -b newfeature/Feature`)
3. Commit your Changes (`git commit -m 'Add some new Feature'`)
4. Push to the Branch (`git push origin newfeature/Feature`)
5. Create a Pull Request

## License
Project is licensed under the MIT License. Click [License](./LICENSE) for more information.

## Contributors
Domenico Restuccia 

Rohma Khalid

Ulvis Silavnieks

Project Link: https://github.com/domrest/TrashBot

HACKADAY.IO: https://hackaday.io/project/179098-trashbot
