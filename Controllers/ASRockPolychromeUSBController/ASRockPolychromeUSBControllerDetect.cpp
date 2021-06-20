#include "Detector.h"
#include "ASRockPolychromeUSBController.h"
#include "RGBController.h"
#include "RGBController_ASRockPolychromeUSB.h"
#include "i2c_smbus.h"
#include "pci_ids.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>

/*---------------------------------------------------------*\
| ASRock vendor ID                                          |
\*---------------------------------------------------------*/
#define ASROCK_VID                                  0x26CE

/*---------------------------------------------------------*\
| ASRock product ID                                         |
\*---------------------------------------------------------*/
#define ASROCK_MOTHERBOARD_1_PID                    0x01A2
#define ASROCK_DESKMINI_ADDRESSABLE_LED_STRIP_PID   0x01A6

void DetectPolychromeUSBControllers(hid_device_info* info, const std::string& /*name*/)
{
    hid_device* dev = hid_open_path(info->path);

    if(dev)
    {
        PolychromeUSBController*     controller     = new PolychromeUSBController(dev, info->path);
        RGBController_PolychromeUSB* rgb_controller = new RGBController_PolychromeUSB(controller);
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

REGISTER_HID_DETECTOR("ASRock Polychrome USB", DetectPolychromeUSBControllers, ASROCK_VID, ASROCK_MOTHERBOARD_1_PID);
REGISTER_HID_DETECTOR("ASRock Deskmini Addressable LED Strip", DetectPolychromeUSBControllers, ASROCK_VID, ASROCK_DESKMINI_ADDRESSABLE_LED_STRIP_PID);
