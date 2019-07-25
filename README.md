# DomoTent gadget documentation

1. [ Goal](#Goal)
1. [ Hardware](#Hardware)
1. [ Setting up everything](#SettingUp)
1. [ Schematic](#Schematic)
1. [Communication Protocol](#CommunicationProtocol)


<a name="Goal"></a>
## Goal

<a name="Hardware"></a>
## Hardware

| Item            | Discription                                           | Ali link (short)       |   Price | IF    | Connect to pins     |
|-----------------|-------------------------------------------------------|------------------------|--------:|-------|---------------------|
| TTGo t5         | TTGo t5: ESP32 with support for LiPo charging         | https://bit.ly/2Xg9iyf |   $3.61 | N/A   |                     |
| NRF24L01        | Wireless data RF transmission module 2.4G             | https://bit.ly/2Xiy94z |   $3.61 | N/A   | Software SPI + Int  |
| Window sensor   | To detect opening of the tent                         | https://bit.ly/2Zhmy2q |   $0.90 | 1 pin | Any IO              |
| SD cards        | To store data , 128MB should be sufficient            | https://bit.ly/2F3nrUC | $8.09/5 | N/A   |                     |
| RTC             | To keep track of time                                 | https://bit.ly/2X55teJ |   $0.84 | I2C   | GP21(SDA)-22(SCL) (HW I2C)    |
| BME280          | Temperature, Humidity, pressure                       | https://bit.ly/2XzHNvL |   $2.21 | I2C   | GP21(SDA)-22(SCL)    |
| LED strip       | 8 LED Strip ws2812                                    | https://bit.ly/2MBBCX8 |   $0.72 | 1 pin | Any IO              |
| Battery         | 1500mAh, 3.7v, no connector                           | https://bit.ly/2F74osi |   €2.75 | N/A   | Vbat                |
|-----------------|-------------------------------------------------------|------------------------|--------:|-------|---------------------|
[Reference for pin mapping](https://github.com/espressif/arduino-esp32#esp32dev-board-pinmap)

<a name="SettingUp"></a>
## Setting up everything

This project should be maintained in the VS Code + PlatformIDE environment. Simply import this project in VS Code, and all the dependencies (compilers etc) should be downloaded automatically. Use the documentation in the folders to include for example libaries etc.


<a name="Schematic"></a>
## Schematic 

<a name="CommunicationProtocol"></a>
## Communication protocol

