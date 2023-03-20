/**
 *            @file: SX1509.c
 *
 *          @author: Sneha Sreedhar Rao
 * Created on @date: 13-Feb-2023 5:20:01 PM
 *           Editor:
 *             @ref:
 *            @note:
 *       @copyright (c) 2023-2029 Sneha Sreedhar Rao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <SX1509.h>

I2C_HandleTypeDef *SX1509_i2c;

uint8_t SX1509Add;

void SX1509_init(SX1509_HandleTypeDef *hdev,I2C_HandleTypeDef *SX1509_I2C_CHANNEL_ID,uint8_t addr)
{
	hdev->hi2c= SX1509_I2C_CHANNEL_ID;
	hdev->addr = addr << 1;
}

SX1509_STATUS SX1509_reset(SX1509_HandleTypeDef *hdev,uint8_t number)
{
//	SX1509_HandleTypeDef  sx1509h;
	uint8_t regintmaskB = RegInterruptMaskB;
	uint8_t regoff3 = RegOff3;
	if(number == 0)
	{
		hdev->addr = SX1509_ADDRESS_0;
	    if( SX1509_write(hdev , RegReset, &regintmaskB ) == SX1509_OK )
	    {
	        if( SX1509_write(hdev, RegReset, &regoff3 ) == SX1509_OK )
	        {
	            return SX1509_OK;
	        }
	    }
	}

	if(number == 1)
	{
		hdev->addr = SX1509_ADDRESS_1;
	    if( SX1509_write(hdev, RegReset,  &regintmaskB) == SX1509_OK )
	    {
	        if( SX1509_write(hdev, RegReset, &regoff3) == SX1509_OK )
	        {
	            return SX1509_OK;
	        }
	    }
	}

	if(number == 2)
	{
		hdev->addr = SX1509_ADDRESS_2;
	    if( SX1509_write(hdev, RegReset,  &regintmaskB) == SX1509_OK )
	    {
	        if( SX1509_write(hdev, RegReset, &regoff3) == SX1509_OK )
	        {
	            return SX1509_OK;
	        }
	    }
	}
	if(number == 3)
	{
		hdev->addr = SX1509_ADDRESS_3;
	    if( SX1509_write(hdev, RegReset,  &regintmaskB) == SX1509_OK )
	    {
	        if( SX1509_write(hdev, RegReset, &regoff3) == SX1509_OK )
	        {
	            return SX1509_OK;
	        }
	    }
	}
    return SX1509_ERROR;
}

SX1509_STATUS SX1509_write( SX1509_HandleTypeDef  *hdev, uint8_t reg, uint8_t *data )
{
	if(HAL_I2C_Mem_Write(hdev->hi2c, hdev->addr, reg, 1, data, 1, 100) == HAL_OK){
		return SX1509_OK;
	}
	else{
		return SX1509_ERROR;
	}
}

SX1509_STATUS SX1509_read( SX1509_HandleTypeDef  *hdev, uint8_t reg, uint8_t *data )
{
    if(HAL_I2C_Mem_Read(hdev->hi2c, hdev->addr, reg, 1, data, 1, 100) == HAL_OK){
		return SX1509_OK;
	}
	else{
		return SX1509_ERROR;
	}
}

SX1509_STATUS SX1509_pullup(SX1509_HandleTypeDef *hdev, uint8_t port,uint8_t *datapullupconfig){
	return SX1509_write(hdev, RegDirB | port, datapullupconfig);
}

SX1509_STATUS SX1509_iodir(SX1509_HandleTypeDef *hdev, uint8_t port,
		uint8_t iodir) {
	uint8_t data[1] = { iodir };
	return SX1509_write(hdev, RegDirB | port, data);
}

SX1509_STATUS SX1509_write_gpio_port(SX1509_HandleTypeDef *hdev, uint8_t port)
{
	uint8_t data[1] = {hdev->gpioport[port]};
	return SX1509_write(hdev, RegDataB|port,data);
}
