/*
 * This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
 * 
 * External libraries needed:
 * DFRobot_AirQualitySensor: https://github.com/DFRobot/DFRobot_AirQualitySensor
 * 
 * Air Quality Sensor: https://www.dfrobot.com/product-2439.html
 *
 * Contributors: Sam Groveman
 */

#pragma once
#include <Sensor.h>
#include <Wire.h>
#include <DFRobot_AirQualitySensor.h>

class DFAirQuality : public Sensor {
	public:
		DFAirQuality(String Name, TwoWire* I2C_bus = &Wire, uint8_t address = 0x19);
		DFAirQuality(String Name, int sda, int scl, TwoWire* I2C_bus = &Wire, uint8_t address = 0x19);
		bool begin();
		bool takeMeasurement();

	protected:
		/// @brief I2C bus in use
		TwoWire* i2c_bus;

		/// @brief SCL pin in use
		int scl_pin = -1;

		/// @brief SDA pin in use
		int sda_pin = -1;
		
		DFRobot_AirQualitySensor air_sensor;
};