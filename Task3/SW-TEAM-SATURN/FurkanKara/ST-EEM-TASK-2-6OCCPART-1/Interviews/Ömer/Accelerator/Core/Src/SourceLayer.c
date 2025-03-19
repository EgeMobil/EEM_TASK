/*
 * SourceLayer.c
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */

#include "SourceLayer.h"

// Gaz pedalından alınan veriyi Flash belleğe kaydetme
void save_to_flash(uint16_t speed) {
    HAL_FLASH_Unlock();
    // Flash bellek adresi belirlenir
    HAL_FLASH_Program(parametre,speed);
    HAL_FLASH_Lock();
}
