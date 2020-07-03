# ADC to SPI Converter

This project reads the ADC1 Channel 1 Pin and outputs it over SPI continuously.

## Hardware

A STM32F072 development board is used for this project.

Pinout:

* PA1: ADC_In1
* PA4: SPI_Nss
* PA5: SPI1_Sck
* PA7: SPI1_Mosi

## Firmware Description

The SysTick interrupt triggers every 1ms and calls a single function to read the ADC and then output that value over SPI1.