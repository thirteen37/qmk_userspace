# CRKBD v4.1 Miryoku Encoder Configuration

This keymap adds encoder support to the Miryoku layout for the CRKBD v4.1 keyboard with contextual functionality across all layers. Note this only works with the `rev4_1` versions, in either the mini or standard variants.

## Hardware Requirements

- CRKBD v4.1 PCB (supports up to 4 encoders)
- 2 rotary encoders for top row positions
- Encoders should be placed in the top extra key positions:
  - Left encoder: matrix position [0,0] (first encoder)
  - Right encoder: matrix position [2,0] (third encoder)

## Encoder Functionality by Layer

### Base Layer (U_BASE)
- **Left Encoder**: Volume down/up (`KC_VOLD`/`KC_VOLU`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Extra Layer (U_EXTRA)  
- **Left Encoder**: Volume down/up (`KC_VOLD`/`KC_VOLU`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Tap Layer (U_TAP)
- **Left Encoder**: Volume down/up (`KC_VOLD`/`KC_VOLU`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Button Layer (U_BUTTON)
- **Left Encoder**: Mouse acceleration slow/fast (`KC_ACL0`/`KC_ACL2`)
- **Right Encoder**: Undo/redo (`U_UND`/`U_RDO`)

### Navigation Layer (U_NAV)
- **Left Encoder**: Page down/up (`KC_PGDN`/`KC_PGUP`)
- **Right Encoder**: Undo/redo (`U_UND`/`U_RDO`)

### Mouse Layer (U_MOUSE)
- **Left Encoder**: Horizontal scroll left/right (`MS_WHLL`/`MS_WHLR`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Media Layer (U_MEDIA)
- **Left Encoder**: Volume down/up (`KC_VOLD`/`KC_VOLU`)
- **Right Encoder**: Previous/next track (`KC_MPRV`/`KC_MNXT`)

### Number Layer (U_NUM)
- **Left Encoder**: App switching backward/forward (`Shift+Cmd+Tab`/`Cmd+Tab`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Symbol Layer (U_SYM)
- **Left Encoder**: Tab switching backward/forward (`Shift+Ctrl+Tab`/`Ctrl+Tab`)
- **Right Encoder**: Vertical scroll down/up (`MS_WHLD`/`MS_WHLU`)

### Function Layer (U_FUN)
- **Left Encoder**: RGB animation previous/next (`RM_PREV`/`RM_NEXT`)
- **Right Encoder**: RGB brightness down/up (`RM_VALD`/`RM_VALU`)

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
| Button | Mouse Accel | Undo/Redo |
| Nav | Page Up/Down | Undo/Redo |
| Mouse | Horizontal Scroll | Vertical Scroll |
| Media | Volume | Track Prev/Next |
| Num | App Switching | Vertical Scroll |
| Sym | Tab Switching | Vertical Scroll |
| Fun | RGB Animation | RGB Brightness |

## Configuration Files

### keymap.c
Contains the encoder mapping definitions using the `encoder_map` array. Each layer specifies the behavior for all 4 potential encoder positions, with only the first (left) and third (right) encoders actually used.

The encoder mapping uses a 4-encoder array format:
- Position 0: Left encoder (active)
- Position 1: Unused encoder (set to `KC_TRNS`)
- Position 2: Right encoder (active)  
- Position 3: Unused encoder (set to `KC_TRNS`)

### config.h
- Maps the Miryoku layout to `LAYOUT_split_3x6_3_ex2` to utilize extra key positions
- Sets encoder resolution to 2 for smooth operation
- Extra key positions have `KC_CAPS` placeholders (overridden by hardware encoders)

### rules.mk
- Enables `ENCODER_MAP_ENABLE = yes` to use the encoder mapping feature
- Enables RGB matrix support for the 46 LEDs on CRKBD v4.1
- Configures split keyboard features

## Installation

1. Ensure your CRKBD v4.1 has encoders soldered in the top extra key positions
2. Compile the firmware:
   ```bash
   qmk compile -kb crkbd/rev4_1/standard -km manna-harbour_miryoku
   ```
3. Flash the resulting `crkbd_rev4_1_standard_manna-harbour_miryoku.uf2` file to both halves

## Customization

To modify encoder behavior:

1. Edit the `encoder_map` array in `keymap.c`
2. Use `ENCODER_CCW_CW(counter_clockwise_keycode, clockwise_keycode)` format
3. Each layer array has 4 positions: `[left_encoder, unused_encoder1, right_encoder, unused_encoder3]`
4. Set unused positions to `ENCODER_CCW_CW(KC_TRNS, KC_TRNS)` for transparency

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
- Verify `ENCODER_MAP_ENABLE = yes` in rules.mk
- Ensure correct keyboard variant: `crkbd/rev4_1/standard`

### Wrong encoder behavior
- Verify layer is correctly activated
- Check encoder mapping in `keymap.c` for the specific layer
- Encoder direction can be swapped by reversing the CCW/CW keycodes
- Uses modern mouse wheel codes (`MS_WHLU`, `MS_WHLD`, `MS_WHLL`, `MS_WHLR`)

### Compilation errors
- Ensure using CRKBD v4.1 variant (not rev1)
- Check that `LAYOUT_split_3x6_3_ex2` is defined in config.h
- Verify all Miryoku dependencies are present in userspace