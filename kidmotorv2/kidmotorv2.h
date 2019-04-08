#ifndef __KIDMOTOR_H__
#define __KIDMOTOR_H__

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

#include <string.h>
#include "driver.h"
#include "device.h"
#include "i2c-dev.h"
#include "driver/uart.h"
#include "kidbright32.h"

class KidMotorV2 : public Device {
	private:		
		I2CDev *i2c;
		uint8_t KidMotorData[2];

	public:
		// constructor
		KidMotorV2(int bus_ch, int dev_addr) ;
		
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		
		// method
		void setMotor(uint8_t ch, uint8_t dir, uint8_t speed) ;
		
};

#endif
