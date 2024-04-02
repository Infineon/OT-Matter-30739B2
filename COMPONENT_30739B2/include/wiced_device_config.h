/*
 * Copyright 2016-2021, Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef __WICED_DEVICE_CONFIG_H__
#define __WICED_DEVICE_CONFIG_H__

#include <stddef.h>
#include <wiced_hal_pwm.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "wiced_hal_gpio.h"
typedef enum
{
    WICED_PLATFORM_LED_1,
    WICED_PLATFORM_LED_2,
    WICED_PLATFORM_LED_3,
    WICED_PLATFORM_LED_4,
} wiced_platform_led_number_t;

typedef enum
{
    WICED_PLATFORM_BUTTON_1,
    WICED_PLATFORM_BUTTON_2,
    WICED_PLATFORM_BUTTON_3,
    WICED_PLATFORM_BUTTON_4,
} wiced_platform_button_number_t;

typedef enum
{
    WICED_PLATFORM_GPIO_1,
    WICED_PLATFORM_GPIO_2,
    WICED_PLATFORM_GPIO_3,
    WICED_PLATFORM_GPIO_4,
    WICED_PLATFORM_GPIO_5,
    WICED_PLATFORM_GPIO_6,
    WICED_PLATFORM_GPIO_7,
    WICED_PLATFORM_GPIO_8,
    WICED_PLATFORM_GPIO_9,
    WICED_PLATFORM_GPIO_10,
    WICED_PLATFORM_GPIO_11,
    WICED_PLATFORM_GPIO_12,
    WICED_PLATFORM_GPIO_13,
    WICED_PLATFORM_GPIO_14,
    WICED_PLATFORM_GPIO_15,
    WICED_PLATFORM_GPIO_16,
    WICED_PLATFORM_GPIO_17,
    WICED_PLATFORM_GPIO_18,
    WICED_PLATFORM_GPIO_19,
    WICED_PLATFORM_GPIO_20,
    WICED_PLATFORM_GPIO_21,
    WICED_PLATFORM_GPIO_22,
    WICED_PLATFORM_GPIO_23,
    WICED_PLATFORM_GPIO_24,
    WICED_PLATFORM_GPIO_25,
    WICED_PLATFORM_GPIO_26,
    WICED_PLATFORM_GPIO_27,
    WICED_PLATFORM_GPIO_28,
    WICED_PLATFORM_GPIO_29,
    WICED_PLATFORM_GPIO_30,
    WICED_PLATFORM_GPIO_31,
    WICED_PLATFORM_GPIO_32,
    WICED_PLATFORM_GPIO_33,
    WICED_PLATFORM_GPIO_34,
    WICED_PLATFORM_GPIO_35,
    WICED_PLATFORM_GPIO_36,
    WICED_PLATFORM_GPIO_37,
    WICED_PLATFORM_GPIO_38,
    WICED_PLATFORM_GPIO_39,
    WICED_PLATFORM_GPIO_40,
} wiced_platform_gpio_number_t;

typedef enum
{
    PLATFORM_GPIO_0,
    PLATFORM_GPIO_1,
    PLATFORM_GPIO_2,
    PLATFORM_GPIO_3,
    PLATFORM_GPIO_4,
    PLATFORM_GPIO_5,
    PLATFORM_GPIO_6,
    PLATFORM_GPIO_7,
    PLATFORM_GPIO_8,
    PLATFORM_GPIO_9,
    PLATFORM_GPIO_10,
    PLATFORM_GPIO_11,
    PLATFORM_GPIO_12,
    PLATFORM_GPIO_13,
    PLATFORM_GPIO_14,
    PLATFORM_GPIO_15,
    PLATFORM_GPIO_16,
    PLATFORM_GPIO_17,
    PLATFORM_GPIO_18,
    PLATFORM_GPIO_19,
    PLATFORM_GPIO_20,
    PLATFORM_GPIO_21,
    PLATFORM_GPIO_22,
    PLATFORM_GPIO_23,
    PLATFORM_GPIO_24,
    PLATFORM_GPIO_25,
    PLATFORM_GPIO_26,
    PLATFORM_GPIO_27,
    PLATFORM_GPIO_28,
    PLATFORM_GPIO_29,
    PLATFORM_GPIO_30,
    PLATFORM_GPIO_31,
    PLATFORM_GPIO_32,
    PLATFORM_GPIO_33,
    PLATFORM_GPIO_34,
    PLATFORM_GPIO_35,
    PLATFORM_GPIO_36,
    PLATFORM_GPIO_37,
    PLATFORM_GPIO_38,
    PLATFORM_GPIO_39,
    PLATFORM_GPIO_40,
} platform_gpio_t;

typedef enum
{
    PLATFORM_PWM_0,
    PLATFORM_PWM_1,
    PLATFORM_PWM_2,
    PLATFORM_PWM_3,
    PLATFORM_PWM_4,
    PLATFORM_PWM_5,
} platform_pwm_t;

/**
 * configuration for the platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t gpio_pin; /**< WICED GPIO pin */
    wiced_bt_gpio_function_t functionality; /**< chosen functionality for the pin */
}
wiced_platform_gpio_t;

/**
 * Configuration for platform LEDs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_led_config_t;

/**
 * Configuration for platform Buttons
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
    uint32_t button_pressed_value; /**< Button pressed value */
}
wiced_platform_button_config_t;

/**
 * Configuration for platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_gpio_config_t;

/**
 * Configuration for platform PWMs
 */
typedef struct
{
    const wiced_platform_gpio_t *gpio; /**< GPIO configurations */
    PwmChannels channel; /**< PWM channel */
    wiced_bool_t invert; /**< Invert the PWM signal */
}
wiced_platform_pwm_config_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __WICED_DEVICE_CONFIG_H__ */
