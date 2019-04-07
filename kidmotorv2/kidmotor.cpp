#ifndef __KIDMOTOR_CPP__
#define __KIDMOTOR_CPP__

#include "kidmotor.h"

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

KidMotor::KidMotor(int bus_ch, int dev_addr) {
	channel = bus_ch;
	address = dev_addr;
	polling_ms = 100;
}

void KidMotor::init(void) {
	// set initialized flag
	this->initialized = true;
	
	// clear error flag
	this->error = false;
	
	// Start initialized
	this->state = s_detect;
	
	// Clear
	memset(KidMotorData, 0, 2);
}

int KidMotor::prop_count(void) {
	// not supported
	return 0;
}

bool KidMotor::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool KidMotor::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool KidMotor::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool KidMotor::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool KidMotor::prop_write(int index, char *value) {
	// not supported
	return false;
}
// --------------------------------------

// Start here
void KidMotor::process(Driver *drv) {
	i2c = (I2CDev *)drv;
}

// Method
void KidMotor::setMotor(uint8_t ch, uint8_t dir, uint8_t speed) {
	KidMotorData[ch - 1] = (dir << 7) | (speed & 0x7F);
	
	this->error = this->i2c->write(this->channel, this->address, KidMotorData, 2) ==  ESP_OK;
}
#endif
