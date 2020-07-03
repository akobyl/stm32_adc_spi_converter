/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  */

#include "main.h"
#include "adc_spi_convert.h"

/**
  * @brief Converts an ADC reading into a SPI message
  * @param None
  * @retval None
  */
void adc_spi_convert(void)
{
  uint32_t adc_value = 0;
  LL_ADC_REG_StartConversion(ADC1);
  while(LL_ADC_IsActiveFlag_EOC(ADC1) == 0);
  if(LL_ADC_IsActiveFlag_EOC(ADC))
  {
	LL_ADC_ClearFlag_EOC(ADC1);
  }
  
  adc_value = LL_ADC_REG_ReadConversionData12(ADC1);

  // Send the data out over SPI
  uint8_t data_0 = adc_value && 0xFF;
  uint8_t data_1 = (adc_value >> 8) && 0xFF;
  LL_SPI_TransmitData8(SPI1, data_1);
  LL_SPI_TransmitData8(SPI1, data_0);
}
