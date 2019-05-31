/*
 * Copyright notice goes here
 */

//#define ESP32
#undef ESP32
//#define OTA
#undef OTA
#define HAVE_LEDS
//#undef HAVE_LEDS
//#define HAVE_RGB_LED 1
#undef HAVE_RGB_LED

/* When SERIAL_IS_DEBUG is defined, the Heatpump is detached from 
 * 'HardSerial Serial' (default pins 1=tx, 3=rx) and instead a 
 * 115200,8N1 debug console is presented there.
 */
//#define SERIAL_IS_DEBUG 1
#undef SERIAL_IS_DEBUG

//const char* ota_password = "<YOUR OTA PASSWORD GOES HERE>";

// wifi settings
const char* ssid     = "<YOUR WIFI SSID GOES HERE>";
const char* password = "<YOUR WIFI PASSWORD GOES HERE>";

// mqtt server settings
const char* mqtt_server   = "<YOUR MQTT BROKER IP/HOSTNAME GOES HERE>"; // note that MQTTS prefers FQDN over IP.dot.quad
const int mqtt_port       = 1883; // typically 1883 for MQTT, 8883 for MQTTS
const char* mqtt_username = "<YOUR MQTT USERNAME GOES HERE>";
const char* mqtt_password = "<YOUR MQTT PASSWORD GOES HERE>";

//#define MQTTS
#undef MQTTS

/* MQTTS Certificate Fingerprint
 * So the ESP8266 in particular is a touch underpowered
 * It can't validate certificates "properly", and it doesn't check revokation lists.
 * It runs out of stack with a 2048 or 4096 length key; 1024 length is the best you will get
 * So we give the client the sha1 fingerprint of the server certificate, here baked into the code
 * and if the server presents a different certificate at runtime, we drop the link.
 *
 * The constant is a space separated list of exactly 20 hex characters
 * Found by running
 * openssl x509 -in CERT.pem -noout -sha1 -fingerprint | tr ':' ' '
 * (or you could use sed instead of tr)
 */
const char* mqtt_fingerprint = "00 11 22 33 44 55 66 77 88 99 a0 b1 c2 d3 e4 f5 66 77 88 99";


// mqtt client settings
// Note PubSubClient.h has a MQTT_MAX_PACKET_SIZE of 128 defined, so either raise it to 256 or use short topics
const char* client_id                   = "heatpump"; // Must be unique on the MQTT network
const char* heatpump_topic              = "heatpump";
const char* heatpump_set_topic          = "heatpump/set";
const char* heatpump_status_topic       = "heatpump/status";
const char* heatpump_timers_topic       = "heatpump/timers";

const char* heatpump_debug_topic        = "heatpump/debug";
const char* heatpump_debug_set_topic    = "heatpump/debug/set";

// using a similar structure to Tasmota to make all my Last-Wills easier to find
const char* heatpump_lastwill_topic     = "tele/heatpump/LWT";
const char* heatpump_lastwill_message   = "Offline";
const char* heatpump_online_message     = "Online";

// pinouts
const int redLedPin  = 0; // Onboard LED = digital pin 0 (red LED on adafruit ESP8266 huzzah)
const int blueLedPin = 2; // Onboard LED = digital pin 0 (blue LED on adafruit ESP8266 huzzah)

const uint8_t resetPin   = 0;  // Prototype uses GPIO0 as a flash/run button only
const uint8_t rgbLedPin  = 2;  // Mostly-free GPIO on ESP01
const uint8_t swRXPin    = 13; // GPIO13 MOSI/CTS0/RXD2
const uint8_t swTXPin    = 15; // GPIO15 CS/RTS0/TXD2, value at power on matters
const uint8_t hwRXPin    = 3;  // GPIO3 RXD0
const uint8_t hwTXPin    = 1;  // GPIO1 TXD0

// sketch settings
const unsigned int SEND_ROOM_TEMP_INTERVAL_MS = 60000;
