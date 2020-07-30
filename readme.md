# ADC to SPI Converter

This project reads the ADC1 Channel 1 Pin and outputs it over SPI continuously.

## Hardware

A STM32F072 development board is used for this project.

Pinout:

* PA1: ADC_In1
* PB12: SPI_Nss
* PB13: SPI2_Sck
* PB15: SPI2_Mosi

## Firmware Description

The main function initializes the ADC, GPIO, and SPI peripherals and then repeatedly sends a SPI command containing the ADC reading over the SPI output.