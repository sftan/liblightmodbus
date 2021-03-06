/*
	liblightmodbus - a lightweight, multiplatform Modbus library
	Copyright (C) 2016	Jacek Wieczorek <mrjjot@gmail.com>

	This file is part of liblightmodbus.

	Liblightmodbus is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Liblightmodbus is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LIGHTMODBUS_SLAVE_TYPES_H
#define LIGHTMODBUS_SLAVE_TYPES_H

#include <inttypes.h>
#include "../core.h"

//Declarations for slave types

typedef struct
{
	uint8_t address; //Slave address

	uint16_t *registers; //Slave holding registers
	uint16_t registerCount; //Slave register count

	uint8_t *coils; //Slave coils
	uint16_t coilCount; //Slave coil count

	uint8_t *discreteInputs; //Slave discrete input
	uint16_t discreteInputCount; //Slave discrete input count

	uint8_t *registerMask; //Masks for register write protection (bit of value 1 - write protection)
	uint16_t registerMaskLength; //Masks length (each byte covers 8 registers)
	uint8_t *coilMask; //Masks for coil write protection (bit of value 1 - write protection)
	uint16_t coilMaskLength; //Masks length (each byte covers 8 coils)

	uint16_t *inputRegisters; //Slave input registers
	uint16_t inputRegisterCount; //Slave input count

	struct //Slave response formatting status
	{
		uint8_t *frame;
		uint8_t length;
	} response;

	struct //Request from master should be put here
	{
		uint8_t *frame;
		uint8_t length;
	} request;

} ModbusSlave; //Type containing slave device configuration data

#endif
