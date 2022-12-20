﻿#pragma once

enum VerticalSwingMode
{
  VerticalSwingHealthUp       = 0x01,
  VerticalSwingMaxUp          = 0x02,
  VerticalSwingHealthDown     = 0x03,
  VerticalSwingUp             = 0x04,
  VerticalSwingCenter         = 0x06,
  VerticalSwingDown           = 0x08,
  VerticalSwingAuto           = 0x0C
};

enum HorizontalSwingMode
{
  HorizontalSwingCenter       = 0x00,
  HorizontalSwingMaxLeft      = 0x03,
  HorizontalSwingLeft         = 0x04,
  HorizontalSwingRight        = 0x05,
  HorizontalSwingMaxRight     = 0x06,
  HorizontalSwingAuto         = 0x07
};

enum ConditioningMode
{
  ConditioningAuto            = 0x00,
  ConditioningCool            = 0x01,
  ConditioningDry             = 0x02,
  ConditioningHealthyDry      = 0x03,
  ConditioningHeat            = 0x04,
  ConditioningEnergySaving    = 0x05,
  ConditioningFan             = 0x06
};

enum SpecialMode
{
  SpecialModeNone             = 0x00,
  SpecialModeElderly          = 0x01,
  SpecialModeChildren         = 0x02,
  SpecialModePregnant         = 0x03
};

enum FanMode
{
  FanHigh                     = 0x01,
  FanMid                      = 0x02,
  FanLow                      = 0x03,
  FanAuto                     = 0x05
};

const std::string ErrorMessages[] = {
  "Alarm clear",
  "Outdoor module failure",
  "Faulty outdoor defrost sensor",
  "Outdoor compressor discharge sensor fault",
  "Outdoor EEPROM Abnormal",
  "Indoor coil sensor failure",
  "Indoor and outdoor communication failure",
  "Power supply overvoltage protection",
  "Communication failure between panel and internal unit",
  "Outdoor compressor overheating protection",
  "Abnormal outdoor environment sensor",
  "full water protection",
  "Indoor EEPROM fault",
  "Outdoor return air sensor failure",
  "CBD and module communication failure",
  "Indoor DC fan failure",
  "Outdoor DC fan failure",
  "Door switch failure",
  "Tips for cleaning the dust net",
  "Water shortage protection",
  "Humidity sensor failure",
  "Indoor temperature sensor failure",
  "Robot limit fault",
  "Indoor PM2.5 sensor failure",
  "Outdoor PM2.5 sensor failure",
  "Indoor heating overload/high load alarm",
  "Outdoor AC current protection",
  "The outdoor compressor is running abnormally",
  "Outdoor DC current protection",
  "Outdoor no load fault",
  "Abnormal CT current",
  "Indoor refrigeration freeze protection",
  "High and low pressure protection",
  "Compressor return air temperature is too high",
  "Faulty outdoor evaporation sensor",
  "Outdoor cooling overload",
  "Water pump drainage failure",
  "Three-phase power failure",
  "Four-way valve failure",
  "External alarm/rake switch failure",
  "Temperature cut-off protection alarm",
  "Idiosyncratic operation failure",
  "Electronic expansion valve failure",
  "Dual heat source sensor Tw failure",
  "Communication failure with the wired controller",
  "Indoor unit address duplicate fault",
  "50Hz zero crossing fault",
  "Outdoor unit failure",
  "Formaldehyde sensor failure",
  "VOC sensor failure",
  "CO2 sensor failure",
  "Firewall failure"
};

struct HaierPacketControl
{
  // Control bytes starts here
  /* 10 */    uint8_t             set_point;                  // Target temperature with 16°C offset (0x00 = 16°C)
  /* 11 */    uint8_t             vertical_swing_mode:4;      // See enum VerticalSwingMode
              uint8_t             :0;
  /* 12 */    uint8_t             fan_mode:3;                 // See enum FanMode
              uint8_t             special_mode:2;             // See enum SpecialMode 
              uint8_t             ac_mode:3;                  // See enum ConditioningMode
  /* 13 */    uint8_t             :8;
  /* 14 */    uint8_t             ten_degree:1;               // 10 degree status
              uint8_t             display_status:1;           // If 0 disables AC's display
              uint8_t             half_degree:1;              // Use half degree
              uint8_t             intelegence_status:1;       // Intelligence status
              uint8_t             pmv_status:1;               // Comfort/PMV status               
              uint8_t             use_fahrenheit:1;           // Use Fahrenheit instead of Celsius
              uint8_t             :0;
  /* 15 */    uint8_t             ac_power:1;                 // Is ac on or off
              uint8_t             health_mode:1;              // Health mode (negative ions) on or off
              uint8_t             electric_heating_status:1;  // Electric heating status
              uint8_t             fast_mode:1;                // Fast mode
              uint8_t             quiet_mode:1;               // Quiet mode
              uint8_t             sleep_mode:1;               // Sleep mode
              uint8_t             lock_remote:1;              // Disable remote
              uint8_t             beeper_status:1;            // If 1 disables AC's command feedback beeper (need to be set on every control command)
  /* 16 */    uint8_t             target_humidity;            // Target humidity (0=30% .. 3C=90%, step = 1%)
  /* 17 */    uint8_t             horizontal_swing_mode:3;    // See enum HorizontalSwingMode
              uint8_t             :3;
              uint8_t             human_sensing_status:2;     // Human sensing status
  /* 18 */    uint8_t             change_filter:1;            // Filter need replacement
              uint8_t             :0;
  /* 19 */    uint8_t             fresh_air_status:1;         // Fresh air status
              uint8_t             humidification_status:1;    // Humidification status
              uint8_t             pm2p5_cleaning_status:1;    // PM2.5 cleaning status
              uint8_t             ch2o_cleaning_status:1;     // CH2O cleaning status
              uint8_t             self_cleaning_status:1;     // Self cleaning status
              uint8_t             light_status:1;             // Light status
              uint8_t             energy_saving_status:1;     // Energy saving status
              uint8_t             cleaning_time_status:1;     // Cleaning time (0 - accumulation, 1 - clear)
};

struct HaierPacketSensors
{
  /* 20 */    uint8_t             room_temperature;           // 0.5°C step
  /* 21 */    uint8_t             room_humidity;              // 0%-100% with 1% step
  /* 22 */    uint8_t             outdoor_temperature;        // 1°C step, -64°C offset (0=-64°C)
  /* 23 */    uint8_t             pm2p5_level:2;              // Indoor PM2.5 grade (00: Excellent, 01: good, 02: Medium, 03: Bad)
              uint8_t             air_quality:2;              // Air quality grade (00: Excellent, 01: good, 02: Medium, 03: Bad)
              uint8_t             human_sensing:2;            // Human presence result (00: N/A, 01: not detected, 02: One, 03: Multiple)
              uint8_t             :1;
              uint8_t             ac_type:1;                  // 00 - Heat and cool, 01 - Cool only)
  /* 24 */    uint8_t             error_status;               // See enum ErrorStatus
  /* 25 */    uint8_t             operation_source:2;         // who is controlling AC (00: Other, 01: Remote control, 02: Button, 03: ESP)
              uint8_t             operation_mode_hk:2;        // Homekit only, operation mode (00: Cool, 01: Dry, 02: Heat, 03: Fan)
              uint8_t             :3;
              uint8_t             err_confirmation:1;         // If 1 clear error status
  /* 26 */    uint16_t            total_cleaning_time;        // Cleaning cumulative time (1h step)
  /* 28 */    uint16_t            indoor_pm2p5_value;         // Indoor PM2.5 value (0 ug/m3 -  4095 ug/m3, 1 ug/m3 step)
  /* 30 */    uint16_t            outdoor_pm2p5_value;        // Outdoor PM2.5 value (0 ug/m3 -  4095 ug/m3, 1 ug/m3 step)
  /* 32 */    uint16_t            ch2o_value;                 // Formaldehyde value (0 ug/m3 -  10000 ug/m3, 1 ug/m3 step)
  /* 34 */    uint16_t            voc_value;                  // VOC value (Volatile Organic Compounds) (0 ug/m3 -  1023 ug/m3, 1 ug/m3 step)
  /* 36 */    uint16_t            co2_value;                  // CO2 value (0 PPM -  10000 PPM, 1 PPM step)
};

struct HaierStatus
{
  uint16_t            subcommand;
  HaierPacketControl  control;
  HaierPacketSensors  sensors;
};

struct HaierControl
{
  uint16_t            subcommand;
  HaierPacketControl  control;
};

struct DeviceVersionAnswer
{
  char        protocol_version[8];
  char        software_version[8];
  uint8_t     encryption[3];
  char        hardware_version[8];
  uint8_t     :8;
  char        device_name[8];
  uint8_t     functions[2];
};

// In this section comments: 
//  - module is the ESP32 control module (communication module in Haier protocol document)
//  - device is the conditioner control board (network appliances in Haier protocol document)
enum class FrameType : uint8_t
{
  CONTROL                                 = 0x01,   // Requests or sets one or multiple parameters (module <-> device, master-slave/interactive, required)
  STATUS                                  = 0x02,   // Contains one or multiple parameters values, usually answer to control frame (module <-> device, master-slave/interactive, required)
  INVALID                                 = 0x03,   // Communication error indication (module <-> device, master-slave/interactive, required)
  ALARM_STATUS                            = 0x04,   // Alarm status report (module <-> device, interactive, required)
  CONFIRM                                 = 0x05,   // Acknowledgment, usually used to confirm reception of frame if there is no special answer (module <-> device, master-slave/interactive, required)
  REPORT                                  = 0x06,   // Report frame (module <-> device, interactive, required)
  STOP_FAULT_ALARM                        = 0x09,   // Stop fault alarm frame (module -> device, interactive, required)
  SYSTEM_DOWNLIK                          = 0x11,   // System downlink frame (module -> device, master-slave/interactive, optional)
  DEVICE_UPLINK                           = 0x12,   // Device uplink frame (module <- device , interactive, optional)
  SYSTEM_QUERY                            = 0x13,   // System query frame (module -> device, master-slave/interactive, optional)
  SYSTEM_QUERY_RESPONSE                   = 0x14,   // System query response frame (module <- device , master-slave/interactive, optional)
  DEVICE_QUERY                            = 0x15,   // Device query frame (module <- device, master-slave/interactive, optional)
  DEVICE_QUERY_RESPONSE                   = 0x16,   // Device query response frame (module -> device, master-slave/interactive, optional)
  GROUP_COMMAND                           = 0x60,   // Group command frame (module -> device, interactive, optional)
  GET_DEVICE_VERSION                      = 0x61,   // Requests device version (module -> device, master-slave/interactive, required)
  GET_DEVICE_VERSION_RESPONSE             = 0x62,   // Device version answer (module <- device, master-slave/interactive, required_
  GET_ALL_ADDRESSES                       = 0x67,   // Requests all slave addresses (module -> device, interactive, optional)
  GET_ALL_ADDRESSES_RESPONSE              = 0x68,   // Answer to request of all slave addresses (module <- device , interactive, optional)
  HANDSET_CHANGE_NOTIFICATION             = 0x69,   // Handset change notification frame (module <- device , interactive, optional)
  GET_DEVICE_ID                           = 0x70,   // Requests Device ID (module -> device, master-slave/interactive, required)
  GET_DEVICE_ID_RESPONSE                  = 0x71,   // Response to device ID request (module <- device , master-slave/interactive, required)
  GET_ALARM_STATUS                        = 0x73,   // Alarm status request (module -> device, master-slave/interactive, required)
  GET_ALARM_STATUS_RESPONSE               = 0x74,   // Response to alarm status request (module <- device, master-slave/interactive, required)
  GET_DEVICE_CONFIGURATION                = 0x7C,   // Requests device configuration (module -> device, interactive, required)
  GET_DEVICE_CONFIGURATION_RESPONSE       = 0x7D,   // Response to device configuration request (module <- device, interactive, required)
  DOWNLINK_TRANSPARENT_TRANSMISSION       = 0x8C,   // Downlink transparent transmission (proxy data Haier cloud -> device) (module -> device, interactive, optional)
  UPLINK_TRANSPARENT_TRANSMISSION         = 0x8D,   // Uplink transparent transmission (proxy data device -> Haier cloud) (module <- device, interactive, optional)
  START_DEVICE_UPGRADE                    = 0xE1,   // Initiate device OTA upgrade (module -> device, master-slave/interactive, OTA required)
  START_DEVICE_UPGRADE_RESPONSE           = 0xE2,   // Response to initiate device upgrade command (module <- device, master-slave/interactive, OTA required)
  GET_FIRMWARE_CONTENT                    = 0xE5,   // Requests to send firmware (module <- device, master-slave/interactive, OTA required)
  GET_FIRMWARE_CONTENT_RESPONSE           = 0xE6,   // Response to send firmware request (module -> device, master-slave/interactive, OTA required) (multipacket?)
  CHANGE_BAUD_RATE                        = 0xE7,   // Requests to change port baud rate (module <- device, master-slave/interactive, OTA required)
  CHANGE_BAUD_RATE_RESPONSE               = 0xE8,   // Response to change port baud rate request (module -> device, master-slave/interactive, OTA required)
  GET_SUBBOARD_INFO                       = 0xE9,   // Requests subboard information (module -> device, master-slave/interactive, required)
  GET_SUBBOARD_INFO_RESPONSE              = 0xEA,   // Response to subboard information request (module <- device, master-slave/interactive, required)
  GET_HARDWARE_INFO                       = 0xEB,   // Requests information about device and subboard (module -> device, master-slave/interactive, required)
  GET_HARDWARE_INFO_RESPONSE              = 0xEC,   // Response to hardware information request (module <- device, master-slave/interactive, required)
  GET_UPGRADE_RESULT                      = 0xED,   // Requests result of the firmware update (module <- device, master-slave/interactive, OTA required)
  GET_UPGRADE_RESULT_RESPONSE             = 0xEF,   // Response to firmware update results request (module -> device, master-slave/interactive, OTA required)
  GET_NETWORK_STATUS                      = 0xF0,   // Requests network status (module <- device, interactive, optional)
  GET_NETWORK_STATUS_RESPONSE             = 0xF1,   // Response to network status request (module -> device, interactive, optional)
  START_WIFI_CONFIGURATION                = 0xF2,   // Starts WiFi configuration procedure (module <- device, interactive, required)
  START_WIFI_CONFIGURATION_RESPONSE       = 0xF3,   // Response to start WiFi configuration request (module -> device, interactive, required)
  STOP_WIFI_CONFIGURATION                 = 0xF4,   // Stop WiFi configuration procedure (module <- device, interactive, required)
  STOP_WIFI_CONFIGURATION_RESPONSE        = 0xF5,   // Response to stop WiFi configuration request (module -> device, interactive, required)
  REPORT_NETWORK_STATUS                   = 0xF7,   // Reports network status (module -> device, master-slave/interactive, required)
  CLEAR_CONFIGURATION                     = 0xF8,   // Request to clear module configuration (module <- device, interactive, optional)
  BIG_DATA_REPORT_CONFIGURATION           = 0xFA,   // Configuration for autoreport device full status (module -> device, interactive, optional)
  BIG_DATA_REPORT_CONFIGURATION_RESPONSE  = 0xFB,   // Response to set big data configuration (module <- device, interactive, optional)
  GET_MANAGEMENT_INFORMATION              = 0xFC,   // Request management information from device (module -> device, master-slave, required)
  GET_MANAGEMENT_INFORMATION_RESPONSE     = 0xFD,   // Response to management information request (module <- device, master-slave, required)
  WAKE_UP                                 = 0xFE,   // Request to wake up (module <-> device, master-slave/interactive, optional)
  NO_COMMAND                              = 0xFF,   // Indicate that there is no command supplied
};

enum class SubcomandsControl : uint16_t
{
  CONTROL_GET_PARAMETERS        = 0x4C01,    // Request specific parameters (packet content: parameter ID1 + parameter ID2 + ...)
  CONTROL_GET_USER_DATA         = 0x4D01,    // Request all user data from device (packet content: None)
  CONTROL_GET_BIG_DATA          = 0x4DFE,    // Request big data information from device (master-slave mode only) (packet content: None)
  CONTROL_SET_PARAMETERS        = 0x5C01,    // Set parameters of the device and device return parameters (packet content: parameter ID1 + parameter data1 + parameter ID2 + parameter data 2 + ...)
  CONTROL_SET_SINGLE_PARAMETER  = 0x5D00,    // Set single parameter (0x5DXX second byte define parameter ID) and return all user data (packet content: ???)
  CONTROL_SET_GROUP_PARAMETERS  = 0x6001,    // Set group parameters to device (0x60XX second byte define parameter is group ID, the only group mentioned in document is 1) and return all user data (packet content: all values like in status packet)
};
