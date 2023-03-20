/**
 *            @file: SX1509.h
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


#ifndef __SX1509_H__
#define __SX1509_H__

#include "i2c.h"

#define SX1509_ADDRESS_0 0x3E
#define SX1509_ADDRESS_1 0x3F
#define SX1509_ADDRESS_2 0x70
#define SX1509_ADDRESS_3 0x71

typedef enum {
	SX1509_OK = 0,
	SX1509_ERROR = 1,
	SX1509_BUSY = 1,
	SX1509_TIMEOUT = 1
} SX1509_STATUS;

/*!
 * SX1509 registers addresses
 */
#define RegReset                                    0x7D
#define RegInputDisableB                            0x00
#define RegInputDisableA                            0x01
#define RegLongSlewB                                0x02
#define RegLongSlewA                                0x03
#define RegLowDriveB                                0x04
#define RegLowDriveA                                0x05
#define RegPullUpB                                  0x06
#define RegPullUpA                                  0x07
#define RegPullDownB                                0x08
#define RegPullDownA                                0x09
#define RegOpenDrainB                               0x0A
#define RegOpenDrainA                               0x0B
#define RegPolarityB                                0x0C
#define RegPolarityA                                0x0D
#define RegDirB                                     0x0E
#define RegDirA                                     0x0F
#define RegDataB                                    0x10
#define RegDataA                                    0x11
#define RegInterruptMaskB                           0x12
#define RegInterruptMaskA                           0x13
#define RegSenseHighB                               0x14
#define RegSenseLowB                                0x15
#define RegSenseHighA                               0x16
#define RegSenseLowA                                0x17
#define RegInterruptSourceB                         0x18
#define RegInterruptSourceA                         0x19
#define RegEventStatusB                             0x1A
#define RegEventStatusA                             0x1B
#define RegLevelShifter1                            0x1C
#define RegLevelShifter2                            0x1D
#define RegClock                                    0x1E
#define RegMisc                                     0x1F
#define RegLEDDriverEnableB                         0x20
#define RegLEDDriverEnableA                         0x21
#define RegDebounceConfig                           0x22
#define RegDebounceEnableB                          0x23
#define RegDebounceEnableA                          0x24
#define RegKeyConfig1                               0x25
#define RegKeyConfig2                               0x26
#define RegKeyData1                                 0x27
#define RegKeyData2                                 0x28
#define RegTOn0                                     0x29
#define RegIOn0                                     0x2A
#define RegOff0                                     0x2B
#define RegTOn1                                     0x2C
#define RegIOn1                                     0x2D
#define RegOff1                                     0x2E
#define RegTOn2                                     0x2F
#define RegIOn2                                     0x30
#define RegOff2                                     0x31
#define RegTOn3                                     0x32
#define RegIOn3                                     0x33
#define RegOff3                                     0x34
#define RegTOn4                                     0x35
#define RegIOn4                                     0x36
#define RegOff4                                     0x37
#define RegTRise4                                   0x38
#define RegTFall4                                   0x39
#define RegTOn5                                     0x3A
#define RegIOn5                                     0x3B
#define RegOff5                                     0x3C
#define RegTRise5                                   0x3D
#define RegTFall5                                   0x3E
#define RegTOn6                                     0x3F
#define RegIOn6                                     0x40
#define RegOff6                                     0x41
#define RegTRise6                                   0x42
#define RegTFall6                                   0x43
#define RegTOn7                                     0x44
#define RegIOn7                                     0x45
#define RegOff7                                     0x46
#define RegTRise7                                   0x47
#define RegTFall7                                   0x48
#define RegTOn8                                     0x49
#define RegIOn8                                     0x4A
#define RegOff8                                     0x4B
#define RegTOn9                                     0x4C
#define RegIOn9                                     0x4D
#define RegOff9                                     0x4E
#define RegTOn10                                    0x4F
#define RegIOn10                                    0x50
#define RegOff10                                    0x51
#define RegTOn11                                    0x52
#define RegIOn11                                    0x53
#define RegOff11                                    0x54
#define RegTOn12                                    0x55
#define RegIOn12                                    0x56
#define RegOff12                                    0x57
#define RegTRise12                                  0x58
#define RegTFall12                                  0x59
#define RegTOn13                                    0x5A
#define RegIOn13                                    0x5B
#define RegOff13                                    0x5C
#define RegTRise13                                  0x5D
#define RegTFall13                                  0x5E
#define RegTOn14                                    0x5F
#define RegIOn14                                    0x60
#define RegOff14                                    0x61
#define RegTRise14                                  0x62
#define RegTFall14                                  0x63
#define RegTOn15                                    0x64
#define RegIOn15                                    0x65
#define RegOff15                                    0x66
#define RegTRise15                                  0x67
#define RegTFall15                                  0x68
#define RegHighInputB                               0x69
#define RegHighInputA                               0x6A

/* Ports*/
#define SX1509_PORTB 0x00
#define SX1509_PORTA 0x01

#define SET_FULLPORT_OUTPUT 0x00
#define SET_FULLPORT_INPUT  0xFF
//#define SET_TWOPIN_OUTPUT_SIXPIN_INPUT  0x3F // 00111111

typedef struct {
    I2C_HandleTypeDef *hi2c;
    uint8_t addr;
    uint8_t gpioport[2];
}SX1509_HandleTypeDef;


void SX1509_init(SX1509_HandleTypeDef *hdev,I2C_HandleTypeDef *SX1509_I2C_CHANNEL_ID,uint8_t addr);
SX1509_STATUS SX1509_reset(SX1509_HandleTypeDef *hdev,uint8_t number);
SX1509_STATUS SX1509_write( SX1509_HandleTypeDef  *hdev, uint8_t reg, uint8_t *data );
SX1509_STATUS SX1509_read( SX1509_HandleTypeDef  *hdev, uint8_t reg, uint8_t *data );
SX1509_STATUS SX1509_iodir(SX1509_HandleTypeDef *hdev, uint8_t port,uint8_t iodir);
SX1509_STATUS SX1509_pullup(SX1509_HandleTypeDef *hdev, uint8_t port,uint8_t *datapullupconfig);
SX1509_STATUS SX1509_write_gpio_port(SX1509_HandleTypeDef *hdev, uint8_t port);
#endif
