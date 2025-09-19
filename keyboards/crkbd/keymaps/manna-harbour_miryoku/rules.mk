# RGB Matrix support (46 LEDs on CRKBD v4.1)
RGB_MATRIX_ENABLE = yes

# WS2812 driver selection based on revision
ifeq ($(strip $(KEYBOARD)), crkbd/rev4_1/standard)
    WS2812_DRIVER = vendor
else ifeq ($(strip $(KEYBOARD)), crkbd/rev4_1/mini)
    WS2812_DRIVER = vendor
else
    WS2812_DRIVER = bitbang
endif

# Split keyboard features for v4.1
SPLIT_KEYBOARD = yes
