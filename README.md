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

## Arduino can not deal with high precision numbers

The float data type has only 6-7 decimal digits of precision. That means the total number of digits, not the number to the right of the decimal point. Unlike other platforms, where you can get more precision by using a double (e.g. up to 15 digits), on the Arduino, __double is the same size as float__.

We have been aunable to get any Celsius to Fahrenheit calculations to be accurate.
