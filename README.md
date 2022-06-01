# Fan Controller System
A fan controller yystem is using ATmega16 microcontroller, in which the fan is automatically turned ON or OFF according to the temperature.

In this project, the LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values.

The digital output of the ADC is equivalent to sensed analog voltage. In order to get the temperature from the sensed analog voltage, we need to perform some calculations in the programming for the microcontroller.

Once the calculations are done by the microcontroller according to the logic, the temperature is displayed on the LCD.The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan.

## The project is designed and implemented based on the layered architecture model 
![image from program](?raw=true)

## proteus simulation
![image from program](?raw=true)

## Main Components
- ATmega16 
- 4*16 LCD
- LM35
- DC Motor
- L293D

## Drivers
- ADC
- PWM
- GPIO
- LCD
- LM35
- DC Motor

## Tools
- Eclipse
- Proteus
