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
 * Header for HW crypto API
 */

#ifndef _WICED_HAL_CRYPTO_H_
#define _WICED_HAL_CRYPTO_H_

//==================================================================================================
// Include
//==================================================================================================
#include <stdint.h>

//==================================================================================================
// Constants
//==================================================================================================
/** @brief wiced crypto result */
typedef enum
{
    WICED_CRYPTO_CCM_INPUT_ERROR = 0,
    WICED_CRYPTO_CCM_AUTH_FAIL = 1,
    WICED_CRYPTO_CCM_SUCCESS = 2,
    WICED_CRYPTO_SHA256_INPUT_ERROR = 3,
    WICED_CRYPTO_SHA256_FAIL = 4,
    WICED_CRYPTO_SHA256_SUCCESS = 5,
    WICED_CRYPTO_MULMOD_FAIL = 6,
    WICED_CRYPTO_MULMOD_SUCCESS = 7,
    WICED_CRYPTO_ECC_POINT_MUL_CFG_COMPLETE = 11,    //HW_ECC_POINT_MUL_CFG_COMPLETE
    WICED_CRYPTO_ECC_POINT_MUL_SUCCESS = 12,         //HW_ECC_POINT_MUL_SUCCESS
    WICED_CRYPTO_ECC_POINT_MUL_FAIL = 13,            //HW_ECC_POINT_MUL_FAIL
    WICED_CRYPTO_GENERAL_ALLOC_FAIL = 14,
}wiced_crypto_result_t;

/** @brief wiced ccm mode: encrypt or decrypt */
typedef enum
{
    WICED_CRYPTO_CCM_DECRYPT = 0,
    WICED_CRYPTO_CCM_ENCRYPT = 1
}wiced_crypto_ccm_mode_t;

//==================================================================================================
// Type Definitions
//==================================================================================================
/*
 *   The structure of ECC point multiplication
 */
typedef struct wiced_crypto_ecc_point_mul wiced_crypto_ecc_point_mul_t;
typedef void (*wiced_crypto_ecc_point_mul_callback)(wiced_crypto_ecc_point_mul_t *ecc_point_mul);
typedef struct wiced_crypto_ecc_point_mul
{
    uint32_t *hw_pka_next;	//PKA next point
    uint8_t   hw_pka_next_id;	//PKA function id
    uint8_t   hw_pka_skip_check;	//0: check PKA next point, 1: skip check
    int8_t    order;		//data ordering: "Q_BIGNUM"(*Not available), "Q_NORMAL"
    uint8_t   k_len;		//key length
    uint8_t   src_len;		//source length
    uint8_t   status;		//status
    uint32_t *k;			//Integer by which to multiply
    uint32_t *src_x;		//source: x
    uint32_t *src_y;		//source: y
    uint32_t *src_z;		//source: z
    uint32_t *cur_a;		//curve parameter: a
    uint32_t *cur_b;		//curve parameter: b
    uint32_t *cur_p;		//curve parameter: p
    uint32_t *dest_x;		//destination: x
    uint32_t *dest_y;		//destination: y
    uint32_t *dest_z;		//destination: z
    wiced_crypto_ecc_point_mul_callback callback;	//callback function
}wiced_crypto_ecc_point_mul_t;

/*
 *   The structure of AES ECB context
 */
typedef struct wiced_crypto_aes_context
{
    uint8_t ksch[240];
    uint8_t rnd;
} wiced_crypto_aes_context_t;

//==================================================================================================
// Functions
//==================================================================================================
/*
 * Function         wiced_hal_crypto_ecc_point_mul
 *
 *
 * @param[in]	    p_ecc_pt_mul: The parameters of ECC point multiplication
 *
 * @return
 *		    WICED_CRYPTO_ECC_POINT_MUL_CFG_COMPLETE  : hw config successfully
 *                  WICED_CRYPTO_ECC_POINT_MUL_SUCCESS       : hw return result successfully
 *                  WICED_CRYPTO_ECC_POINT_MUL_FAIL          : fail
 */
wiced_crypto_result_t wiced_hal_crypto_ecc_point_mul(wiced_crypto_ecc_point_mul_t *p_ecc_pt_mul);

/*
 * Function         wiced_hal_crypto_ccm_engine
 *
 * Run CCM (Counter with Cipher Block Chaining-Message Authentication Code) with HW acceleration
 *
 * @param[in]       mode    : select ccm encrypt or decrypt
 *
 * @param[in]       key     : buffer of the ccm key to encrypt or decrypt data
 *
 * @param[in]       key_len : ccm key length (bytes)
 *
 * @param[in]       iv      : buffer of the initialization vector (nonce)
 *
 * @param[in]       iv_len  : initialization vector length (bytes), limited to 11-14
 *
 * @param[in]       add     : buffer of additional authenticated data
 *
 * @param[in]       add_len : additional authenticated data length (bytes), limited to 0-2047
 *
 * @param[in]       input   : buffer of ccm input text
 *
 * @param[in]       length  : input text length (bytes), limited to 0-2047
 *
 * @param[out]      tag     : buffer of an output holding calculated authentication tag
 *
 * @param[in]       tag_len : tag length (bytes), limited to 0, 4, 8, 12, 16
 *
 * @param[out]      output  : buffer of output text
 *
 * @param[in]       ccm_buf : wiced ccm function needs caller creating a buffer with size (add_len + tag_len + length + 1)
 *                            to use. Caller needs free this buffer after wiced ccm function done.
 *
 * @return          WICED_CRYPTO_CCM_INPUT_ERROR  : bad input
 *                  WICED_CRYPTO_CCM_OUT_OF_MEMROY: no memory for HW accelerator operation
 *                  WICED_CRYPTO_CCM_AUTH_FAIL    : HW accelerator fail
 *                  WICED_CRYPTO_CCM_SUCCESS      : success
 */
wiced_crypto_result_t wiced_hal_crypto_ccm_engine(wiced_crypto_ccm_mode_t mode, const uint8_t *key, uint8_t key_len,
        const uint8_t *iv, uint8_t iv_len, const uint8_t *add, uint8_t add_len, const uint8_t *input, uint16_t length,
        uint8_t *tag, uint8_t tag_len, uint8_t *output, uint8_t *ccm_buf);

/*
 * Function         wiced_hal_crypto_aes_setkey
 *
 * Store the aes encrypt/decrypt key with this aes context
 *
 * @param[in]       ctx     : aes context
 *
 * @param[in]       key     : buffer of the aes key to encrypt or decrypt data
 *
 * @param[in]       key_len : aes key length (bytes)
 */
void wiced_hal_crypto_aes_setkey(wiced_crypto_aes_context_t *ctx, const uint8_t *key, uint8_t key_len);

/*
 * Function         wiced_hal_crypto_aes_encrypt
 *
 * Run AES-ECB encryption
 *
 * @param[in]       ctx     : aes context
 *
 * @param[in]       input   : buffer of input text (plaintext)
 *
 * @param[out]      output  : buffer of output text (ciphertext)
 */
void wiced_hal_crypto_aes_encrypt(wiced_crypto_aes_context_t *ctx, const uint8_t *input, uint8_t *output);

/*
 * Function         wiced_hal_crypto_aes_decrypt
 *
 * Run AES-ECB decryption
 *
 * @param[in]       ctx     : aes context
 *
 * @param[in]       input   : buffer of input text (ciphertext)
 *
 * @param[out]      output  : buffer of output text (plaintext)
 */
void wiced_hal_crypto_aes_decrypt(wiced_crypto_aes_context_t *ctx, const uint8_t *input, uint8_t *output);

/*
 * Function         wiced_hal_crypto_sha256_engine
 *
 * Run SHA-256 with HW acceleration to get 32-byte hash value
 *
 * @param[in]       input   : buffer of input text
 *
 * @param[out]      output  : buffer of output text
 *
 * @param[in]       length  : input text length (bytes)
 *
 * @return          WICED_CRYPTO_SHA256_INPUT_ERROR: bad input
 *                  WICED_CRYPTO_SHA256_FAIL       : HW accelerator fail
 *                  WICED_CRYPTO_SHA256_SUCCESS    : success
 */
wiced_crypto_result_t wiced_hal_crypto_sha256_engine(const uint8_t *input, uint8_t *output, uint16_t length);

/*
 * Function         wiced_hal_crypto_pka_mulmod
 *
 * Run big number calculation with HW acceleration. result = (left * right) % div
 *
 * @param[out]      result  : buffer of final remainder value
 *
 * @param[in]       left    : buffer of multiplier1
 *
 * @param[in]       right   : buffer of multiplier2
 *
 * @param[in]       div     : buffer of divider
 *
 * @param[in]       word_size : word(4-byte) length of multipliers, divider, and remainder
 *
 * @return          WICED_CRYPTO_MULMOD_FAIL   : HW accelerator fail
 *                  WICED_CRYPTO_MULMOD_SUCCESS: success
 */
wiced_crypto_result_t wiced_hal_crypto_pka_mulmod(uint32_t *result, const uint32_t *left, const uint32_t *right,
        const uint32_t *div, uint16_t word_size);

#endif //_WICED_HAL_CRYPTO_H_
