# The RelayBot Project

The RelayBot project involves the design and implementation of a system consisting of three specialized robots, each responsible for completing a unique segment of a racecourse. These robots include a line follower, a line maze follower, and a physical maze follower, collectively working as a team to ensure the successful completion of the race.
To achieve this, our team has developed a comprehensive software framework that includes a library of modular functions for robot movement. Each robot employs advanced sensor technologies such as Infrared Line Sensors for path tracking, Rotation Sensors for precise movement control, and Sonar Sensors for obstacle detection and "cone" identification.
This document outlines the technical design of the system, including the architecture, algorithms, and hardware integration necessary to ensure the success of the RelayBot project.

## Table of Contents
- Requirements
- Installation
- Configuration
- How It Works

## Requirements
- [Visual Studio Code](https://code.visualstudio.com/download)
- [PlatformIO](https://platformio.org/install/ide?install=vscode)
- Arduino Nano AT MEGA 328 
- Integral Neopixle LED’s 
- Rotation Sensors (LM393 Opto-Interrupter) 
- InfraRed Line Sensors 
- Sonar Sensor (HCSR04) 
- 2 Motors 
- Bread-Board
- PCB “Back-Bone” 
- Servo Motor with Integral “Gripper” 
- Bluetooth Wireless Serial Module 
- Power Bank 
- USB Cable 
- H bridge Motor Driver 
- 3 Onboard Push-Buttons 
- 2 Switches 
- Red, Yellow, Green LED’s 
- Robot04 Chasis 

## Installation
- Download Zip file from Github
- Open the folder in Visual Studio Code

## Configuration
- Turn the switches on Arduino Nano off
- Connect Arduino Nano to PC using USB cable
- Verify the port is correctly chosen
- Compile and upload the code
- Reset Arduino Nano

## Contents of the Library
The bulk of this project has been coded in C++ for Arduino, with PlatformIO in Visual Studio Code, and shared between the group via GIT. The website development has been done in HTML with Python, and the Database is developed with SQL with Python. This Project follows our Groups Code of Conduct in Development, which includes but is not limited to, Refrain from using Chat GPT, Ask Questions When Stuck, and Work in Collaboration with each other. The library consists of different headers.
- line header contains the code that is used for reading the line with line sensor
- motors header contains the code that is used for controlling basic movements
- rotation header contains the code that is used for counting pulses sent by rotation sensors and controlling the movements with rotation sensors
- sonar header contains the code that is used for setting up and getting the distance from the ultra sonic sensor
