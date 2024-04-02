/*
 * Copyright 2016-2023, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/*
 * @file
 * Header for Serial Flash API
 */

#ifndef _WICED_PLATFORM_SERIAL_FLASH_H_
#define _WICED_PLATFORM_SERIAL_FLASH_H_

//==================================================================================================
// Include
//==================================================================================================
#include <wiced.h>

//==================================================================================================
// Constants
//==================================================================================================

//==================================================================================================
// Type Definitions
//==================================================================================================

//==================================================================================================
// Functions
//==================================================================================================
/**
 * Function         wiced_platform_serial_flash_init
 *
 *                  Initialized the serial flash.
 *
 * @retval          success or failure
 */
wiced_bool_t wiced_platform_serial_flash_init(void);

/**
 * Function         wiced_platform_serial_flash_size_get
 *
 *                  Get the serial flash size.
 *
 * @retval          size of the serial flash
 */
uint32_t wiced_platform_serial_flash_size_get(void);

/**
 * Function         wiced_platform_serial_flash_read
 *
 *                  Read data from serial flash.
 *
 * @param[in]       addr      start address
 * @param[in]       p_data    buffer to store the read data
 * @param[in]       data_len  length of data to be read
 *
 * @retval          total length of read data
 */
uint32_t wiced_platform_serial_flash_read(uint32_t addr, uint8_t *p_data, uint32_t data_len);

/**
 * Function         wiced_platform_serial_flash_write
 *
 *                  Write data to serial flash.
 *
 * @param[in]       addr      start address
 * @param[in]       p_data    buffer of the data to be written to the serial flash
 * @param[in]       data_len  length of data to be written
 *
 * @retval          total length of written data
 */
uint32_t wiced_platform_serial_flash_write(uint32_t addr, uint8_t *p_data, uint32_t data_len);

/**
 * Function         wiced_platform_serial_flash_sector_num_get
 *
 *                  Get the serial flash total sector numbers.
 *
 * @retval          total sectors of the serial flash
 */
uint32_t wiced_platform_serial_flash_sector_num_get(void);

/**
 * Function         wiced_platform_serial_flash_erase
 *
 *                  Erase data in serial flash. (Set both parameters to 0 to erase whole serial flash)
 *
 * @param[in]       start_sector  start index of sector to erase
 * @param[in]       sector_num    number of sector(s) to be erases
 */
void wiced_platform_serial_flash_erase(uint32_t start_sector, uint32_t sector_num);

#endif //_WICED_PLATFORM_SERIAL_FLASH_H_
