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
| ESP32           | Lolin lite: ESP32 with support for LiPo charging      | https://bit.ly/31nSt2P |   $3.61 | N/A   |                     |
| Window sensor   | To detect opening of the tent                         | https://bit.ly/2Zhmy2q |   $0.90 | 1 pin | Any IO              |
| SD cards        | To store data , 128MB should be sufficient            | https://bit.ly/2F3nrUC | $8.09/5 | N/A   |                     |
| SD card holders | No description required                               | https://bit.ly/2F08hiF | $1.66/5 | SPI   | GP12-15 (HSPI)      |
| RTC             | To keep track of time                                 | https://bit.ly/2X55teJ |   $0.84 | I2C   | GP21-22 (HW I2C)    |
| E-INK screen    | 1.54", 200x200                                        | https://bit.ly/2MR1vm3 |  $10.22 | SPI   | GP5,18,19,23 (VSPI) |
| BME280          | Temperature, Humidity, pressure                       | https://bit.ly/2XzHNvL |   $2.21 | I2C   | GP21-22 (HW I2C)    |
| LED strip       | 8 LED Strip ws2812                                    | https://bit.ly/2MBBCX8 |   $0.72 | 1 pin | Any IO              |
| Battery         | 800mAh, 3.7v, TODO: find connector that matches ESP32 | https://bit.ly/2ZaxiPU |   $2.30 | N/A   |                     |

[Reference for pin mapping](https://github.com/espressif/arduino-esp32#esp32dev-board-pinmap)

<a name="SettingUp"></a>
## Setting up everything
This project should be maintained in the VS Code + PlatformIDE environment. Simply import this project in VS Code, and all the dependencies (compilers etc) should be downloaded automatically. Use the documentation in the folders to include for example libaries etc.


<a name="Schematic"></a>
## Schematic 

<a name="CommunicationProtocol"></a>
## Communication protocol

