#include "DFAirQuality.h"

/// @brief Creates a new air quality sensor object
/// @param I2C_bus The I2C bus attached to the sensor
/// @param address Address of the sensor
DFAirQuality::DFAirQuality(TwoWire* I2C_bus, uint8_t address) : air_sensor(I2C_bus, address) {}

bool DFAirQuality::begin() {
	Description.parameterQuantity = 2;
	Description.type = "Air Quality Sensor";
	Description.name = "Air Quality Sensor";
	Description.parameters = {"PM 2.5", "PM 10"};
	Description.units = {"ug/m^3", "ug/m^3"};
	values.resize(Description.parameterQuantity);
	return air_sensor.begin();
}

bool DFAirQuality::takeMeasurement() {
	values[0] = air_sensor.gainParticleConcentration_ugm3(PARTICLE_PM2_5_STANDARD);
	values[1] = air_sensor.gainParticleConcentration_ugm3(PARTICLE_PM10_STANDARD);
	return true;
}