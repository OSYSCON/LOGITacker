#ifndef LOGITACKER_DEVICES_H__
#define LOGITACKER_DEVICES_H__

#include <stdint.h>
#include "nrf_esb_illegalmod.h"

#define LOGITACKER_DEVICES_MAX_LIST_ENTRIES 30
#define LOGITACKER_DEVICE_ADDR_STR_LEN 16
#define LOGITACKER_DEVICE_ADDR_LEN 5

typedef enum
{
    LOGITACKER_COUNTER_TYPE_UNIFYING_INVALID = 0, //f.e. keep alive without type
    LOGITACKER_COUNTER_TYPE_UNIFYING_PLAIN_KEYBOARD,
    LOGITACKER_COUNTER_TYPE_UNIFYING_PLAIN_MOUSE,
    LOGITACKER_COUNTER_TYPE_UNIFYING_PLAIN_MULTIMEDIA,
    LOGITACKER_COUNTER_TYPE_UNIFYING_PLAIN_SYSTEM_CTL,
    LOGITACKER_COUNTER_TYPE_UNIFYING_LED,
    LOGITACKER_COUNTER_TYPE_UNIFYING_SET_KEEP_ALIVE,
    LOGITACKER_COUNTER_TYPE_UNIFYING_HIDPP_SHORT,
    LOGITACKER_COUNTER_TYPE_UNIFYING_HIDPP_LONG,
    LOGITACKER_COUNTER_TYPE_UNIFYING_ENCRYPTED_KEYBOARD,
    LOGITACKER_COUNTER_TYPE_UNIFYING_PAIRING,
    LOGITACKER_COUNTER_TYPE_LENGTH,
} logitacker_device_frame_counter_type_t;

typedef struct {
    uint8_t typed[LOGITACKER_COUNTER_TYPE_LENGTH]; //frame count of each known type
    uint32_t overal; //overall frame count
    uint32_t logitech_chksm;
} logitacker_device_frame_counter_t;

typedef struct {
    uint8_t base_addr[4];
    uint8_t addr_prefix;
    bool is_logitech;
    bool is_unifying_compatible;
    bool is_plain_keyboard;
    bool is_encrypted_keyboard;
    bool is_mouse;

    logitacker_device_frame_counter_t frame_counters;
} logitacker_device_t;

void logitacker_device_update_counters_from_frame(logitacker_device_t *device, nrf_esb_payload_t frame);

logitacker_device_t* logitacker_device_list_add(logitacker_device_t device);

logitacker_device_t* logitacker_device_list_get(uint32_t pos); //returns NULL if position is unused or invalid
logitacker_device_t* logitacker_device_list_get_by_addr(uint8_t *addr);
logitacker_device_t* logitacker_device_list_get_by_base_prefix(uint8_t *base_addr, uint8_t prefix);

uint32_t logitacker_device_list_remove_by_addr(uint8_t *addr);
uint32_t logitacker_device_list_remove_by_base_prefix(uint8_t *base_addr, uint8_t prefix);
uint32_t logitacker_device_list_remove(logitacker_device_t device);
void logitacker_device_list_flush();
#endif