MCU = atmega32u4
BOOTLOADER = atmel-dfu

# Build options
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

CONSOLE_ENABLE = no # Console for debug
COMMAND_ENABLE = no # Commands for debug and configuration

NKRO_ENABLE = yes     # Enable N-Key Rollover
BACKLIGHT_ENABLE = no # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no # Enable keyboard RGB underglow

AUDIO_ENABLE = no
ENCODER_ENABLE = no
LTO_ENABLE = yes
