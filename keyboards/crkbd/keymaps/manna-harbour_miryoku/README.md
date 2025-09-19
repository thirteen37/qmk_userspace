# CRKBD v4.1 Miryoku Contextual Encoder Configuration

This keymap adds comprehensive contextual encoder support to the Miryoku layout for the CRKBD v4.1 keyboard. The implementation provides three distinct behaviors per layer through encoder button states and contextual layer switching. Note this only works with the `rev4_1` versions, in either the mini or standard variants.

## Hardware Requirements

- CRKBD v4.1 PCB (supports up to 4 encoders)
- 2 rotary encoders for top row positions
- Encoders should be placed in the top extra key positions:
  - Left encoder: matrix position [0,0] (first encoder)
  - Right encoder: matrix position [2,0] (third encoder)

## Contextual Encoder System Overview

The contextual encoder system provides three distinct behaviors per layer:

1. **Normal encoder rotation**: Standard behavior when no encoder buttons are held
2. **Left encoder button held + rotation**: Enhanced contextual behavior
3. **Right encoder button held + rotation**: Alternative contextual behavior

### Architecture

The implementation uses QMK's built-in layer-tap (`LT`) functionality combined with "proxy layers":

- `U_ENC_LEFT`: Active when left encoder button is held
- `U_ENC_RIGHT`: Active when right encoder button is held

### Pure LT Implementation

The system leverages QMK's proven `LT` (Layer-Tap) functionality exclusively:
- **Tap behavior**: Encoder buttons act as Enter (left) and Space (right)
- **Hold behavior**: Activates proxy layers for contextual encoder rotation
- **No custom timing**: QMK handles tap vs hold detection automatically
- **Simplified architecture**: ~60 lines of code eliminated from previous versions

### Smart Modifier Management

Enhanced state tracking manages:
- Modifier hold states for app switching and tab switching
- Encoder button hold detection through proxy layers
- Base layer context preservation during proxy activation
- Automatic modifier cleanup on layer transitions

## Platform Adaptation

The implementation adapts to different platforms through compile-time configuration:

### macOS (`MIRYOKU_CLIPBOARD_MAC`)
- Browser navigation: `CMD+[` / `CMD+]`
- App switching: `CMD+Tab` / `CMD+Shift+Tab`
- Window switching: `CMD+`` / `CMD+Shift+``
- Tab switching: `CTRL+Tab` / `CTRL+Shift+Tab`

### Windows/Linux (Default)
- Browser navigation: Media keys (`KC_WBAK` / `KC_WFWD`)
- App switching: `ALT+Tab` / `ALT+Shift+Tab`
- Tab switching: `CTRL+Tab` / `CTRL+Shift+Tab`

## Comprehensive Encoder Behaviors

All encoder behavior is handled through a single `encoder_update_user()` callback function with contextual layer detection. The system automatically determines the effective layer context and provides appropriate behaviors.

### Enhanced Summary Table

| Layer | Left Encoder (Normal) | Left Encoder (Left Btn Held) | Left Encoder (Right Btn Held) | Right Encoder (Normal) | Right Encoder (Left Btn Held) | Right Encoder (Right Btn Held) |
|-------|---------------------|---------------------------|------------------------------|----------------------|---------------------------|-------------------------------|
| **Base/Extra/Tap** | Volume Control | Window Management (CMD+` / ALT+Tab) | Text Navigation (Word Jump) | Vertical Scroll | Window Management (CMD+` / ALT+Tab) | Page Navigation (PgUp/PgDn) |
| **Button** | Browser Forward/Back | *[Base Layer Context]* | *[Base Layer Context]* | Undo/Redo | *[Base Layer Context]* | *[Base Layer Context]* |
| **Nav** | Left/Right Cursor | Word Navigation (Ctrl+Arrow) | *[Text Selection]* | Undo/Redo | Word Navigation (Ctrl+Arrow) | *[Text Selection & Manipulation]* |
| **Mouse** | Horizontal Scroll | *[Mouse Acceleration]* | Advanced Mouse Wheel | Vertical Scroll | *[Mouse Acceleration]* | Advanced Mouse Wheel & Accel |
| **Media** | Volume Control | *[Playback Enhancement]* | Playlist Navigation | Track Prev/Next | *[Playback Enhancement]* | Playback Speed Control |
| **Num** | App Switching (Enhanced) | App Switching (Platform Modifier Held) | *[Numeric Enhancement]* | Vertical Scroll | Number Input Sequences | *[Numeric Enhancement]* |
| **Sym** | Tab Switching (Enhanced) | Recent Tabs Management | Text Selection (Word-by-Word) | Vertical Scroll | Recent Tabs Management | Text Selection (Word-by-Word) |
| **Fun** | RGB Animation (Direct) | *[Advanced RGB Controls]* | *[System Function Controls]* | RGB Brightness (Direct) | *[Advanced RGB Controls]* | *[System Function Controls]* |

*Note: Behaviors marked with [brackets] represent contextual enhancements that adapt based on the base layer and current context.*

### Key Implementation Features

#### Single Callback Architecture
- `encoder_update_user()` function handles ALL encoder behavior for every layer
- `get_encoder_context_layer()` determines effective layer context
- Context preservation during proxy layer activation
- No encoder maps used - complete control through callback

#### Modifier Hold Logic
For NUM and SYM layers with enhanced app/tab switching:
1. **Layer Entry**: No modifiers held initially
2. **Encoder Rotation**: Modifier automatically held during rotation
3. **Continuous Rotation**: Smooth multi-step navigation
4. **Layer Exit**: Modifiers automatically released

#### Context-Aware Behavior
- Proxy layers (`U_ENC_LEFT`, `U_ENC_RIGHT`) provide contextual markers
- Base layer context preserved during encoder button holds
- `layer_state_set_user()` manages state transitions and cleanup
- Different behaviors activate based on combination of base layer and button state

## Undo/Redo Functionality

The navigation and button layers feature undo/redo using Miryoku's clipboard system (`U_UND`/`U_RDO`):

- **Linux/Default**: `Ctrl+Z` (undo) and `Ctrl+Shift+Z` (redo)
- **macOS**: `Cmd+Z` (undo) and `Cmd+Shift+Z` (redo) 
- **Windows**: `Ctrl+Z` (undo) and `Ctrl+Y` (redo)

## Configuration Files

### keymap.c
Contains comprehensive contextual encoder implementation:

**Core Functions**:
- `encoder_update_user()`: Central encoder behavior dispatcher with context detection
- `layer_state_set_user()`: Base layer capture and modifier state management  
- `get_encoder_context_layer()`: Determines effective layer for encoder behavior
- Uses different function types optimally:
  - `tap_code()`: Basic keycodes (volume, media, scrolling)
  - `tap_code16()`: Keycodes with modifiers (undo/redo, navigation)
  - Direct functions: RGB matrix controls for immediate effect

**Encoder Button Mapping**:
- Left encoder button: `LT(U_ENC_LEFT, KC_ENT)` - Enter on tap, proxy layer on hold
- Right encoder button: `LT(U_ENC_RIGHT, KC_SPC)` - Space on tap, proxy layer on hold

### config.h
- Maps Miryoku layout to `LAYOUT_split_3x6_3_ex2` for extra key positions
- Sets encoder resolution to 2 for smooth operation
- Configures encoder positions and proxy layer definitions

### rules.mk
- Enables RGB matrix support for 46 LEDs on CRKBD v4.1
- Configures split keyboard features
- **Important**: `ENCODER_MAP_ENABLE` is NOT set (uses callback instead)

## Hardware Compatibility

### Standard CRKBD (rev1, rev4_0)
- Basic encoder rotation support only
- No encoder button functionality
- Uses `LAYOUT_split_3x6_3` with `WS2812_DRIVER = bitbang`

### CRKBD v4.1 (standard/mini)  
- Full contextual encoder support with button functionality
- Uses `LAYOUT_split_3x6_3_ex2` with `WS2812_DRIVER = vendor`
- Encoder buttons in top extra positions provide tap/hold functionality

## Installation

1. Ensure your CRKBD v4.1 has encoders with buttons soldered in top extra positions
2. Compile the firmware:
   ```bash
   qmk compile -kb crkbd/rev4_1/standard -km manna-harbour_miryoku
   ```
3. Flash the resulting `crkbd_rev4_1_standard_manna-harbour_miryoku.uf2` file to both halves

## Usage Examples

### Enhanced App Switching (NUM Layer)
1. Hold NUM layer key
2. Rotate left encoder: Next/previous app with modifier auto-held
3. Hold left encoder button + rotate: App switching with platform modifier held (CMD on Mac, ALT on Windows/Linux)
4. Release layer: All modifiers automatically cleaned up

### Contextual Navigation Examples

#### Word Navigation (NAV Layer + Left Encoder Button)
1. Hold NAV layer key + left encoder button
2. Rotate left encoder: Jump by words (CTRL+Left/Right Arrow)
3. Normal NAV + left encoder: Character-by-character movement
4. Release encoder button: Return to character navigation

#### Text Navigation (Base Layer + Right Encoder Button)
1. Hold right encoder button (activates `U_ENC_RIGHT` proxy layer)
2. Rotate left encoder: Jump by words (CTRL+Arrow)
3. Rotate right encoder: Navigate by pages (Page Up/Down)
4. Release button: Return to normal scroll behavior

### Advanced RGB Control (FUN Layer + Encoder Buttons)
1. Hold FUN layer key + encoder button
2. Left button held: Advanced RGB pattern controls
3. Right button held: System function controls
4. Normal rotation: Standard RGB animation/brightness

## Troubleshooting

### Contextual Behaviors Not Working
- **Encoder buttons not responding**: Verify CRKBD v4.1 hardware and `LAYOUT_split_3x6_3_ex2` mapping
- **Context not switching**: Check `get_encoder_context_layer()` function and proxy layer definitions
- **Base layer context lost**: Verify `layer_state_set_user()` captures base layer on proxy activation

### Standard Encoder Issues
- **No response**: Check encoder wiring, ensure `ENCODER_MAP_ENABLE` is NOT set
- **Wrong direction**: Modify clockwise/counter-clockwise logic in `encoder_update_user()`
- **Modifiers stuck**: Exit and re-enter layer; check modifier cleanup in `layer_state_set_user()`

### Layer-Tap Issues
- **Buttons not tapping Enter/Space**: Verify `LT()` configuration in keymap
- **Hold not activating proxy layers**: Check `U_ENC_LEFT`/`U_ENC_RIGHT` layer definitions
- **Timing issues**: QMK handles timing automatically - check for conflicting custom timing code

### Compilation Issues
- **Memory constraints**: Current implementation uses ~99% of AVR memory on some revisions
- **Layout errors**: Ensure using `LAYOUT_split_3x6_3_ex2` for v4.1
- **Missing dependencies**: Verify all Miryoku userspace components are present

## Technical Implementation Details

### QMK APIs Used
- `encoder_update_user()`: Core encoder callback with context detection
- `layer_state_set_user()`: State management and base layer capture  
- `get_highest_layer()`: Layer state queries
- `layer_state_cmp()`: Layer state comparisons
- `register_mods()` / `unregister_mods()`: Modifier management
- `LT()`: Built-in layer-tap functionality for encoder buttons

### Memory Efficiency
- Single state structure manages all encoder behavior
- Conditional compilation for revision-specific features
- Optimized for microcontroller memory constraints
- Pure LT implementation reduces code complexity significantly

### Performance Considerations
- Encoder callbacks optimized for frequent rotation events
- Direct RGB matrix functions for immediate visual feedback
- Minimal processing overhead in context detection
- No custom timing functions needed (QMK handles LT timing)

## Future Enhancements

### Potential Improvements
- User-configurable rotation behaviors per layer
- Application-specific encoder mappings based on active window
- Dynamic sensitivity adjustment
- Audio feedback for encoder state changes

### Framework Expansion
- Generic contextual encoder framework for other keyboards
- Runtime configuration system for behavior changes
- Integration with other QMK advanced features like combos and tap dance

This implementation demonstrates advanced QMK techniques including contextual layer management, state tracking, platform adaptation, and hardware abstraction, providing a robust foundation for sophisticated encoder behavior in any QMK-powered keyboard.