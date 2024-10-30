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
		DFAirQuality(TwoWire* I2C_bus = &Wire, uint8_t address = 0x19);
		bool begin();
		bool takeMeasurement();

	protected:
		DFRobot_AirQualitySensor air_sensor;
};