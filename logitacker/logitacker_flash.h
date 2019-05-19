#ifndef LOGITACKER_FLASH_H
#define LOGITACKER_FLASH_H

#include "stdint.h"
#include "logitacker_devices.h"
#include "fds.h"

#define LOGITACKER_FLASH_FILE_ID_GLOBAL_OPTIONS 0x1000
#define LOGITACKER_FLASH_KEY_GLOBAL_OPTIONS_LOGITACKER 0x1000

#define LOGITACKER_FLASH_FILE_ID_DEVICES 0x1001
#define LOGITACKER_FLASH_RECORD_KEY_DEVICES 0x1001
#define LOGITACKER_FLASH_RECORD_SIZE_UNIFYING_DEVICE (sizeof(logitacker_devices_unifying_device_t) + 3) / 4
#define LOGITACKER_FLASH_FILE_ID_DONGLES 0x1002
#define LOGITACKER_FLASH_RECORD_KEY_DONGLES 0x1002
#define LOGITACKER_FLASH_RECORD_SIZE_UNIFYING_DONGLE (sizeof(logitacker_devices_unifying_dongle_t) + 3) / 4


// note: these functions only handle device data, not the dongle data referenced by pointers
uint32_t logitacker_flash_store_device(logitacker_devices_unifying_device_t * p_device);
uint32_t logitacker_flash_delete_device(logitacker_devices_unifying_device_rf_address_t rf_address);
uint32_t logitacker_flash_get_device(logitacker_devices_unifying_device_t * p_device, logitacker_devices_unifying_device_rf_address_t const rf_address);
uint32_t logitacker_flash_list_stored_devices();
uint32_t logitacker_flash_get_next_device_for_dongle(logitacker_devices_unifying_device_t * p_device, fds_find_token_t * p_find_token, logitacker_devices_unifying_dongle_t * p_dongle);

// note: these functions only handle dongle data, not the device data referenced by pointers
uint32_t logitacker_flash_store_dongle(logitacker_devices_unifying_dongle_t * p_dongle);
uint32_t logitacker_flash_delete_dongle(logitacker_devices_unifying_device_rf_addr_base_t base_addr);
uint32_t logitacker_flash_get_dongle(logitacker_devices_unifying_dongle_t * p_dongle, logitacker_devices_unifying_device_rf_addr_base_t const base_addr);
uint32_t logitacker_flash_list_stored_dongles();
uint32_t logitacker_flash_get_dongle_for_device(logitacker_devices_unifying_dongle_t * p_dongle, logitacker_devices_unifying_device_t * p_device);


uint32_t logitacker_flash_init();

#endif //LOGITACKER_FLASH_H