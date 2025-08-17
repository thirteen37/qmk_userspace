#pragma once

// User-configurable idle timeout in milliseconds
#define IDLE_TIMEOUT 500

// User-configurable key code sent when movement is detected
#define KEY_CODE KC_F18

// User-configurable key behavior mode
// If defined, a mouse drag will be started after DRAG_DELAY when movement starts
// If not defined, KEY_CODE will be held during movement and released after idle timeout
#define TAP_MODE

// User-configurable delay before starting mouse drag in TAP_MODE (milliseconds)
#define DRAG_DELAY 150
