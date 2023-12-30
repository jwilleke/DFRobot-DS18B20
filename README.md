# DS18B20 Temperature Sensor

Code use [1-Wire]

## Device

I used this [Gravity: Waterproof DS18B20 Temperature Sensor Kit](https://www.dfrobot.com/product-1354.html)

## I statred with the code

[SKU:DFR0198 Waterproof DS18B20 Sensor Wiki](https://wiki.dfrobot.com/Waterproof_DS18B20_Digital_Temperature_Sensor__SKU_DFR0198_) and added few things like 
getTempF(celsius) tp get Fahrenheit from Celsius value.

## Expected Output

``` bash
24.00 Celsius 75.20 Fahrenheit
24.00 Celsius 75.20 Fahrenheit
23.94 Celsius 73.40 Fahrenheit
23.87 Celsius 73.40 Fahrenheit
23.81 Celsius 73.40 Fahrenheit
23.75 Celsius 73.40 Fahrenheit
```
 64.00 Fahrenheit
18.87 Celsius 64.00 Fahrenheit
18.87 Celsius 64.00 Fahrenheit
1

float getTempF(int32_t raw)
{
  // return ((float)raw * 0.0140625f) + 32.0f;
  return (raw * 9 / 5) + 32.0;
}

float celsius = getTemp();

