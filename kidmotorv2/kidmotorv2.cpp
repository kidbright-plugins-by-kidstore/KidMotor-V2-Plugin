#ifndef __KIDMOTOR_CPP__
#define __KIDMOTOR_CPP__

#include "kidmotorv2.h"

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

KidMotorV2::KidMotorV2(int bus_ch, int dev_addr) {
	channel = bus_ch;
	address = dev_addr;
	polling_ms = 100;
}

void KidMotorV2::init(void) {
	// set initialized flag
	this->initialized = true;
	
	// clear error flag
	this->error = false;
	
	// Clear
	memset(KidMotorData, 0, 2);
}

int KidMotorV2::prop_count(void) {
	// not supported
	return 0;
}

bool KidMotorV2::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool KidMotorV2::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool KidMotorV2::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool KidMotorV2::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool KidMotorV2::prop_write(int index, char *value) {
	// not supported
	return false;
}
// --------------------------------------

// Start here
void KidMotorV2::process(Driver *drv) {
	i2c = (I2CDev *)drv;
}

// Method
void KidMotorV2::setMotor(uint8_t ch, uint8_t dir, uint8_t speed) {
	if (speed > 100) speed = 100;
	
	KidMotorData[ch - 1] = (dir << 7) | (speed & 0x7F);
	
	this->error = this->i2c->write(this->channel, this->address, KidMotorData, 2) ==  ESP_OK;
}
#endif
