/*-----------------------------------------*\
|  AuraAddressableController.h              |
|                                           |
|  Definitions and types for ASUS Aura      |
|  Addressable RGB lighting controller      |
|                                           |
|  Adam Honse (CalcProgrammer1) 1/18/2020   |
\*-----------------------------------------*/

#include "RGBController.h"
#include "AuraUSBController.h"

#include <string>
#include <hidapi/hidapi.h>

#pragma once

enum
{
    AURA_ADDRESSABLE_CONTROL_MODE_EFFECT            = 0x3B,     /* Effect control mode                  */
    AURA_ADDRESSABLE_CONTROL_MODE_DIRECT            = 0x40,     /* Direct control mode                  */
};

class AuraAddressableController : public AuraUSBController
{
public:
    AuraAddressableController(hid_device* dev_handle);
    ~AuraAddressableController();

    void SetChannelLEDs
        (
        unsigned char   channel,
        RGBColor *      colors,
        unsigned int    num_colors
        );

    void SetMode
        (
        unsigned char   channel,
        unsigned char   mode,
        unsigned char   red,
        unsigned char   grn,
        unsigned char   blu
        );

private:

    void SendEffect
        (
        unsigned char   channel,
        unsigned char   mode,
        unsigned char   red,
        unsigned char   grn,
        unsigned char   blu
        );

    void SendDirect
        (
        unsigned char   device,
        unsigned char   start_led,
        unsigned char   led_count,
        unsigned char*  led_data
        );

    void    SendDirectApply
        (
        unsigned char   channel
        );
};