<h1 align="center"> TrashBot </h1>

<p align="center">
<img src="images/Facebook Post 940x788 px (3).gif" alt="logo for Trashbot">
</p>
Your gateway into the future!
</br>
TrashBot is an open-source project which monitors the temperature of the trash bins and reminds you to take out the trash before it goes bad!
</br>
<p align="center">
    </br>
<a href="https://domrest.github.io/TrashBot/"><strong>Browse the docs »</strong></a>
    </br>
    <a href="https://www.trashbot.info/"><strong>Checkout the website »</strong></a>
    </br>
    </br> 
    <a href="https://user-images.githubusercontent.com/77978118/115160562-c376a700-a090-11eb-993b-aa074892db83.mp4">View Demo</a>
    ·
    <a href="https://github.com/domrest/TrashBot/issues">Report Bug</a>
    ·
    <a href="https://github.com/domrest/TrashBot/issues">Request Feature</a>
</p>

<p align="center">
<a href="https://www.facebook.com/TrashBotOfficial"><img  src="images/fb_logo.png"  width="44" height="44">
<a href="https://www.instagram.com/thetrashbotofficial/"><img src="images/instagram_logo.png" width="44" height="44">
<a href="https://twitter.com/Trashbo27883021"><img  src="images/twitter.png"  width="47" height="47">
<a href="https://www.trashbot.info/"><img  src="images/logo_n3_insta_white.png"  width="47" height="47">
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
  <a href="https://www.hackster.io/rohmakhalid1994/trashbot-ffdec7">  <img  src="images/hacks1.png"  width="47" height="47">
 </div>
<!-- TABLE OF CONTENTS -->

## Table of contents
<ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#getting-started">Getting Started</a>
       <ul>
          <li><a href="#Prerequisites">Prerequisites</a</li>
          <li><a href="#Installation">Installation</a</li> 
          <li><a href="#Temperature-Sensors">Temperature Sensors</a</li>
          <li><a href="#Gui">Gui</a</li>
          <li><a href="#Email-Alert">Email Alert</a</li>
       </ul>
      </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contribution">Contribution</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
</ol>
        
## About The Project

The inspiration of the project was taken from the waste management necessity for our planet. To target a zero waste planet, healthy habits with useful gadgets can help us move towards this global goal. 

The most common issue we see is that in the public spaces and streets the trash bins are collected and emptied without even checking if they are full or not which leads to waste of resources. And sometimes, the trash bins would start overflowing and waste would collect and would continue to pile up ruining the natural and preserved spaces. To target this issue we started at a smaller level.

We planned on implementing this idea at home by implementing a smart bin - a 'TrashBot' which upon measuring the temperature of the waste would detect the decay and send an alert to user to empty the trash. Along with creating a fun home automation project this will help create a healthy habit of being mindful of clearing the waste timely.

This project can then be expanded for largescale implementation especially in residential area streets and parks. Before trash overflows and starts to decay spreading unpleasant smell in beautiful natural spaces, Trashbot will send an alert to the waste collectors.
</br>

<div align="center">
  <img src="images/Facebook Post 940x788 px (4).gif" alt="Animation" width="600">
</div>
</br>

## Getting Started

There are 3 components to this project - `Email Alert`, `Gui`, and `Temperature Sensors`.

### `Temperature Sensors` 
More documentation about `Temperature Sensors` can be found [here](./docs/TemperatureSensors.md)
### `Email Alert`
More documentation about `Email Alert` can be found [here](./docs/Messaging.md)
### `Gui`
More documentation about `Gui` can be found [here](./docs/GUI.md)

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

Clone Repository:

`git clone https://github.com/domrest/TrashBot.git`

Run Cmake within directory:

`cmake .`

Run Make:

`make`

Run Program:

`sudo ./Trashbot`



## Roadmap
See the [open issues](https://github.com/domrest/TrashBot/issues) for a list of proposed features (and known issues).

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
Domenico Restuccia - Responsible for: The temperature code, combing all software and responsible for all hardware.

Rohma Khalid - Responsible for: GUI code, QT, Facebook marketing, marketing material, graphics and the logo, Readme.

Ulvis Silavnieks - Responsible for: The email code, instagram, twitter, demo video, website.

Project Link: https://github.com/domrest/TrashBot

Hackaday.io: https://hackaday.io/project/179098-trashbot
