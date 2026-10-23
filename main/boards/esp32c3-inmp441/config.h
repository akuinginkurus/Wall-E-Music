#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// Audio Configuration
// INMP441 Mic + MAX98357A Speaker share the same I2S clock, use same sample rate
#define AUDIO_INPUT_SAMPLE_RATE  24000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// I2S Configuration - Duplex mode with shared clocks
// ESP32-C3 has only ONE I2S peripheral, mic and speaker share BCLK/WS
#define AUDIO_I2S_GPIO_MCLK GPIO_NUM_1    // Master Clock (MCLK) for ES8311 (replaces unused battery ADC)
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_11   // Word Select (shared)
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_18   // Bit Clock (shared)
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_19   // INMP441 SD / WeAct DO (Mic Data In)
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_13   // MAX98357A DIN / WeAct DI (Speaker Data Out)

// WeAct ES8311 + NS4150B Configuration
#define AUDIO_ES8311_I2C_ADDR 0x18       // Default 7-bit I2C address of ES8311
#define AUDIO_ES8311_PA_PIN   GPIO_NUM_2 // NS4150B PA Enable (set GPIO_NUM_NC if hardwired to 3.3V)

// Button Configuration
#define BOOT_BUTTON_GPIO    GPIO_NUM_3    // Short click: chat; hold 2.5s: boot-mode menu
#define RESET_SSID_BUTTON_GPIO GPIO_NUM_7 // Click: hands-free toggle, hold: clear saved WiFi SSID (disabled if GPIO2 used for PA)
#define RESET_SSID_LONG_PRESS_MS 5000     // Long press duration in milliseconds

// Device battery measurement (disabled in this build; GPIO1 is dedicated to ES8311 MCLK).
// #define BATTERY_ADC_GPIO                 GPIO_NUM_1

// Hands-free mode: auto enter listen mode when device is idle.
// Set to 0 to restore pure push-to-talk behavior on GPIO3.
#define HANDS_FREE_AUTO_LISTEN              0
#define HANDS_FREE_AUTO_LISTEN_INTERVAL_MS  500
#define HANDS_FREE_AUTO_LISTEN_RETRY_MS     5000
#define HANDS_FREE_IDLE_TIMEOUT_MS          30000

// Vibration Motor / Haptic Configuration (Chronchi notification & find device alarm)
#ifndef VIBRATION_MOTOR_PIN
#define VIBRATION_MOTOR_PIN GPIO_NUM_0  // Pin motor getar (Default GPIO 20 pada ESP32-C3 Super Mini)
#endif

// LED Configuration (optional - set to NC if not used)
//#define BUILTIN_LED_GPIO    GPIO_NUM_NC  // No built-in LED

// OLED Display Configuration (SSD1306 128x64 via I2C)
#define DISPLAY_SDA_PIN     GPIO_NUM_4  // I2C SDA (GPIO8 rusak, pindah ke sini)
#define DISPLAY_SCL_PIN     GPIO_NUM_5  // I2C SCL (GPIO9 rusak, pindah ke sini)
#define DISPLAY_WIDTH       128
#define DISPLAY_HEIGHT      64
#define DISPLAY_MIRROR_X    true
#define DISPLAY_MIRROR_Y    true

// MX1508 dual H-bridge.
#define MOTOR_LEFT_IN1_PIN GPIO_NUM_6
#define MOTOR_LEFT_IN2_PIN GPIO_NUM_2
#define MOTOR_RIGHT_IN1_PIN GPIO_NUM_10
#define MOTOR_RIGHT_IN2_PIN GPIO_NUM_8
#define MOTOR_LEFT_INVERT false
#define MOTOR_RIGHT_INVERT false
#define MOTOR_PWM_FREQUENCY_HZ 10000
#define MOTOR_MIN_DUTY_PERCENT 100
#define MOTOR_MAX_DUTY_PERCENT 100
#define MOTOR_MAX_RUN_TIME_MS 5000
#define MOTOR_DIRECTION_DEAD_TIME_MS 120
#define MOTOR_DUAL_START_STAGGER_MS 40


#endif // _BOARD_CONFIG_H_
