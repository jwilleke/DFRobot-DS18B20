#include <Arduino.h>
#include <OneWire.h>
#include "Config.h"

// Temperature chip i/o
OneWire ds(DS18S20PIN); // on digital pin defined in "Config.h"

byte addr[8];

String getChip()
{
  // the first ROM byte indicates which chip
  int chipID = addr[0];
  String chipType = "";
  switch (addr[0])
  {
  case 0x10:
    chipType = String(addr[0]) + ": DS18S20 or old DS1820";
    // Serial.println("Chip = DS18S20"); // or old DS1820
    break;
  case 0x28:
    chipType = String(addr[0]) + ": DS18B20";
    // Serial.println("Chip = DS18B20");
    break;
  case 0x22:
    chipType = String(addr[0]) + ": DS1822";
    // Serial.println("Chip = DS1822");
    break;
  default:
    chipType = String(addr[0]) + ": Device is not a DS18x20 family device.";
    // Serial.println("Device is not a DS18x20 family device.");
  }
  return chipType;
}

float getTemp()
{
  // returns the temperature from one DS18S20 in DEG Celsius
  byte data[12];
  // byte addr[8];

  if (!ds.search(addr))
  {
    // no more sensors on chain, reset search
    ds.reset_search();
    return -1000;
  }

  if (OneWire::crc8(addr, 7) != addr[7])
  {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad

  for (int i = 0; i < 9; i++)
  { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); // using two's compliment
  float TemperatureSum = tempRead / 16;
  Serial.print("  Celsius : ");
  Serial.println(TemperatureSum);
  return TemperatureSum;
}

float getTempF(int32_t raw)
{
  float f =  ((float)raw * 1.8) + 32.0f;
  Serial.print("  Fahrenheit: ");
  Serial.println(f);
  return f;
}

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Getting chipType");
  Serial.print("Chip Type:");
  Serial.println(getChip());
}

void loop(void)
{
  float celsius = getTemp();
  //Serial.print(celsius);
  //Serial.print(" Celsius ");
  float fahrenheit = getTempF(celsius);
  //Serial.print(fahrenheit);
  //Serial.println(" Fahrenheit");

  delay(1500); // just here to slow down the output so it is easier to read
}
