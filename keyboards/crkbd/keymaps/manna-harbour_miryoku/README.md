# CRKBD v4.1 Miryoku Encoder Configuration

This keymap adds comprehensive encoder support to the Miryoku layout for the CRKBD v4.1 keyboard with contextual functionality across all layers. All encoder behavior is handled through a single callback function for precise control and enhanced app/tab switching with modifier hold logic. Note this only works with the `rev4_1` versions, in either the mini or standard variants.

## Hardware Requirements

- CRKBD v4.1 PCB (supports up to 4 encoders)
- 2 rotary encoders for top row positions
- Encoders should be placed in the top extra key positions:
  - Left encoder: matrix position [0,0] (first encoder)
  - Right encoder: matrix position [2,0] (third encoder)

## Comprehensive Encoder Implementation

All encoder behavior is handled through a single `encoder_update_user()` callback function, eliminating the complexity of encoder maps and providing complete control over functionality. The NUM and SYM layers feature enhanced app and tab switching with modifier hold logic:

### How It Works
1. **Single Callback**: All encoders handled by `encoder_update_user()` function - no encoder maps used
2. **Layer Detection**: Function detects current layer and executes appropriate encoder behavior
3. **Modifier Hold**: For NUM/SYM layers, modifiers are held only when encoder is rotated
4. **Layer Exit**: When you exit the layer, any held modifiers are automatically released

### Benefits
- **Simplified Architecture**: Single callback function handles all encoder behavior
- **Smooth Navigation**: Rotate through multiple apps/tabs in one gesture
- **No Interference**: Other keys in layers work normally (no unwanted modifiers)
- **Precise Control**: Each layer has exactly defined encoder behavior
- **Clean Implementation**: No encoder map complexity or conflicts
- **Cross-Platform**: Uses standard shortcuts (CMD+Tab on macOS, CTRL+Tab for browsers)

### Usage Examples
- **App Switching**: Hold NUM layer → rotate left encoder (CMD auto-held) → continue rotating → release layer
- **Tab Switching**: Hold SYM layer → rotate left encoder (CTRL auto-held) → continue rotating → release layer

## Undo/Redo Functionality

The navigation and button layers feature undo/redo on the right encoder using Miryoku's clipboard system (`U_UND`/`U_RDO`). These automatically adapt to your operating system:

- **Linux/Default**: Uses `Ctrl+Z` (undo) and `Ctrl+Shift+Z` (redo)
- **macOS**: Uses `Cmd+Z` (undo) and `Cmd+Shift+Z` (redo) 
- **Windows**: Uses `Ctrl+Z` (undo) and `Ctrl+Y` (redo)

The clipboard system is configured in the Miryoku userspace configuration.

## Quick Reference Table

| Layer | Left Encoder | Right Encoder |
|-------|-------------|---------------|
| Base/Extra/Tap | Volume | Vertical Scroll |
| Button | Browser Forward/Back (CMD+]/[) | Undo/Redo |
| Nav | Left/Right Cursor | Undo/Redo |
| Mouse | Horizontal Scroll | Vertical Scroll |
| Media | Volume | Track Prev/Next |
| Num | App Switching (Enhanced) | Vertical Scroll |
| Sym | Tab Switching (Enhanced) | Vertical Scroll |
| Fun | RGB Animation (Direct) | RGB Brightness (Direct) |

## Configuration Files

### keymap.c
Contains comprehensive encoder behavior implementation through callback functions:

**Comprehensive Encoder Logic**: 
- `encoder_update_user()` function handles ALL encoder behavior for every layer
- Each layer has specific encoder behaviors implemented in a switch statement
- App/tab switching uses modifier hold logic for smooth multi-step navigation
- RGB matrix controls use direct function calls (`rgb_matrix_step()`, `rgb_matrix_increase_val()`, etc.)
- `layer_state_set_user()` function cleans up held modifiers when layers are exited
- Uses different function types for different keycodes:
  - `tap_code()`: Basic keycodes (volume, media, scrolling, page navigation)
  - `tap_code16()`: Keycodes with modifiers (undo/redo, app/tab switching)
  - Direct functions: RGB matrix controls for immediate effect
- Single source of truth for all encoder functionality

### config.h
- Maps the Miryoku layout to `LAYOUT_split_3x6_3_ex2` to utilize extra key positions
- Sets encoder resolution to 2 for smooth operation
- Extra key positions have `KC_CAPS` placeholders (overridden by hardware encoders)

### rules.mk
- Enables RGB matrix support for the 46 LEDs on CRKBD v4.1
- Configures split keyboard features

## Installation

1. Ensure your CRKBD v4.1 has encoders soldered in the top extra key positions
2. Compile the firmware:
   ```bash
   qmk compile -kb crkbd/rev4_1/standard -km manna-harbour_miryoku
   ```
3. Flash the resulting `crkbd_rev4_1_standard_manna-harbour_miryoku.uf2` file to both halves

## Hardware Notes

- The CRKBD v4.1 supports up to 4 encoders (2 per side)
- This configuration uses only 2 encoders (left and right) for maximum compatibility
- Middle extra key positions remain available for future encoder expansion
- Uses newer mouse wheel codes (`MS_WHL*`) for improved compatibility
- Encoder resolution is set to 2 for balanced responsiveness
- Both halves must be flashed with the same firmware

## Troubleshooting

### Encoders not responding
- Check encoder wiring and solder connections
- Verify that `ENCODER_MAP_ENABLE` is NOT set in rules.mk (we use callback instead)
- Ensure correct keyboard variant: `crkbd/rev4_1/standard`
- Check that `encoder_update_user()` function is present and returning `false`

### Wrong encoder behavior
- Verify layer is correctly activated
- Check encoder logic in `encoder_update_user()` function for the specific layer
- Encoder direction can be swapped by changing clockwise/counter-clockwise logic
- No encoder maps are used - all behavior is handled in callback function
- Uses modern mouse wheel codes (`MS_WHLU`, `MS_WHLD`, `MS_WHLL`, `MS_WHLR`)

### App/Tab switching issues
- **Modifiers not held**: Check `encoder_update_user()` and `layer_state_set_user()` functions are present
- **Switching too fast**: Encoder sends discrete Tab presses, speed depends on rotation rate
- **Wrong direction**: Check clockwise/counter-clockwise logic in `encoder_update_user()` switch statement
- **Stuck modifiers**: Exit and re-enter layer to reset; modifiers auto-release on layer exit
- **Other keys affected**: Modifiers are only registered when encoder is rotated, not on layer entry
- **Fallback to base behavior**: No encoder maps used; all behavior defined in callback function

### Function call issues
- **Undo/redo not working**: Ensure `tap_code16()` is used for `U_UND`/`U_RDO` (contain modifiers)
- **Basic keys not working**: Use `tap_code()` for simple keycodes like volume, media controls
- **RGB not responding**: Use direct RGB matrix functions, not `tap_code()` with RGB keycodes

### Compilation errors
- Ensure using CRKBD v4.1 variant (not rev1)
- Check that `LAYOUT_split_3x6_3_ex2` is defined in config.h
- Verify all Miryoku dependencies are present in userspace
