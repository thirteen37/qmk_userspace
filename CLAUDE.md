# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a QMK userspace repository containing custom keyboard configurations and keymaps. The userspace pattern allows maintaining personal keyboard customizations separately from the main QMK firmware repository while enabling code reuse across multiple keyboards.

**Critical Architecture Principle**: This repository is an *overlay system*. Files here override/extend the main QMK firmware without modifying it. The build system searches userspace first, then falls back to firmware files.

## Working with Two Directories

**qmk_userspace** (this repository):
- Location: `/Users/yuxi/Documents/keyboard/qmk_userspace`
- Contains: Custom keymaps, configurations, user-specific code
- All changes are made here

**qmk_firmware** (QMK core):
- Location: `/Users/yuxi/Documents/keyboard/qmk_firmware`
- Contains: Main QMK codebase
- **Do NOT modify files here**
- Used for building/compiling only

## Essential Build Commands

### Compiling Firmware

```bash
# From anywhere (if userspace is configured globally):
qmk compile -kb <keyboard> -km <keymap>

# Examples:
qmk compile -kb crkbd/rev4_1/standard -km manna-harbour_miryoku
qmk compile -kb atreus -km lysp

# Build all configured targets:
qmk userspace-compile
```

### Managing Build Targets

```bash
# Add a keyboard/keymap to build targets:
qmk userspace-add -kb <keyboard> -km <keymap>

# Remove from build targets:
qmk userspace-remove -kb <keyboard> -km <keymap>

# List current build targets:
qmk userspace-list
```

### Creating New Keymaps

```bash
# Create a new keymap for a keyboard:
qmk new-keymap -kb <keyboard> -km <keymap_name>

# This creates: keyboards/<keyboard>/keymaps/<keymap_name>/
```

## File Hierarchy and Configuration Inheritance

QMK searches for configuration in this order (later overrides earlier):

1. QMK firmware defaults
2. Keyboard defaults (in firmware)
3. Userspace user config (`users/<username>/`)
4. Userspace keyboard config (`keyboards/<keyboard>/`)
5. Userspace keymap config (`keyboards/<keyboard>/keymaps/<keymap>/`)

### Key Configuration Files

**rules.mk** - Build feature flags:
```makefile
# Enable/disable QMK features
MOUSEKEY_ENABLE = yes
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = yes
```

**config.h** - C preprocessor definitions:
```c
// Timing, hardware settings, feature parameters
#define TAPPING_TERM 200
#define ENCODER_RESOLUTION 2
```

**keymap.c** - Keymap implementation:
```c
// Layer definitions, custom keycodes, callback functions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { ... };
```

## Architecture Patterns

### User-Centric Code Sharing

The `users/` directory contains code shared across multiple keyboards:

```
users/manna-harbour_miryoku/
├── manna-harbour_miryoku.c    # Shared implementation
├── manna-harbour_miryoku.h    # Shared definitions
├── config.h                   # Global timing/settings
├── rules.mk                   # Features enabled globally
├── custom_rules.mk            # Build-time layout options
└── post_rules.mk              # Conditional compilation logic
```

Each keymap includes this via:
```c
#include "manna-harbour_miryoku.h"  // In keymap.c
```

### Platform-Specific Compilation

Use Make variables to control compilation:

```makefile
# In custom_rules.mk:
MIRYOKU_CLIPBOARD = MAC  # or WIN, FUN

# In post_rules.mk (converts to C defines):
ifneq ($(strip $(MIRYOKU_CLIPBOARD)),)
  OPT_DEFS += -DMIRYOKU_CLIPBOARD_$(MIRYOKU_CLIPBOARD)
endif
```

Then in C code:
```c
#if defined(MIRYOKU_CLIPBOARD_MAC)
    #define U_RDO SCMD(KC_Z)  // macOS: Cmd+Shift+Z
#elif defined(MIRYOKU_CLIPBOARD_WIN)
    #define U_RDO C(KC_Y)     // Windows: Ctrl+Y
#endif
```

### Multi-Revision Hardware Support

Handle different hardware revisions conditionally:

```c
#if defined(KEYBOARD_crkbd_rev4_1_standard) || defined(KEYBOARD_crkbd_rev4_1_mini)
    // Rev 4.1 specific code (has extra keys and encoders)
    #define LAYOUT_miryoku(...) LAYOUT_split_3x6_3_ex2(...)
#else
    // Standard CRKBD code
    #define LAYOUT_miryoku(...) LAYOUT_split_3x6_3(...)
#endif
```

### QMK Callback Chain

Customize behavior by implementing these callbacks (called in order):

```c
// Initialization
void matrix_init_user(void) { }

// Layer changes
layer_state_t layer_state_set_user(layer_state_t state) { }

// Key processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) { }

// Encoder rotation (for boards with encoders)
bool encoder_update_user(uint8_t index, bool clockwise) { }

// LED updates
bool led_update_user(led_t led_state) { }
```

## Encoder Implementation Pattern

For keyboards with rotary encoders (like CRKBD rev4.1), this codebase uses a sophisticated pattern:

**Key principle**: Each encoder button only affects its own encoder (you cannot hold one encoder's button while rotating the other).

**Architecture**:
1. Use QMK's `LT()` (Layer-Tap) for encoder buttons
2. Encoder buttons activate proxy layers when held
3. Left encoder button: `LT(U_ENC_LEFT, KC_MUTE)` - Mute on tap, proxy layer on hold
4. Right encoder button: `LT(U_ENC_RIGHT, KC_SPC)` - Space on tap, proxy layer on hold
5. `encoder_update_user()` checks which encoder and whether its button is held
6. Separate handler functions for each state:
   - `handle_encoder_no_button()` - Normal rotation (layer-contextual)
   - `handle_left_encoder_with_button()` - Left encoder with its button held (enhanced behavior)
   - `handle_right_encoder_with_button()` - Right encoder with its button held (enhanced behavior)

**Encoder Button Behaviors by Layer**:
- **Base/Extra/Tap layers**: Left encoder button held = Alt+Tab window switching (Alt modifier held automatically)
- **NUM layer**: Left encoder button held = Platform-specific window management with modifier hold:
  - macOS: CMD+` (switches windows within the same app)
  - Windows/Linux: Alt+Tab (switches between all windows)
- **FUN layer**: Left encoder button held = RGB animation speed, Right encoder button held = RGB hue

**Modifier Hold Pattern**: The implementation uses state tracking with separate boolean flags for each layer's modifier state:
- `window_switching_active` - Alt held on Base layer
- `num_window_switching_active` - CMD/Alt held on NUM layer
- `app_switching_active` - Platform modifier held for app switching on NUM layer
- `tab_switching_active` - CTRL held for tab switching on SYM layer

**Automatic Modifier Release**: Modifiers are released in two scenarios:
1. **Encoder button release**: Detected by monitoring transitions out of proxy layers (`U_ENC_LEFT`/`U_ENC_RIGHT`)
2. **Layer change**: Detected when the underlying layer changes while the encoder button is held

The implementation tracks `prev_highest` layer state to detect when exiting proxy layers, enabling proper cleanup when the encoder button is released.

See `keyboards/crkbd/keymaps/manna-harbour_miryoku/keymap.c` for a complete implementation.

## Important Keyboard-Specific Notes

### CRKBD (Corne) rev4.1
- Has 2 extra keys per half (uses `LAYOUT_split_3x6_3_ex2`)
- Supports encoders with clickable buttons
- Encoder buttons mapped as `LT(U_ENC_LEFT, KC_MUTE)` and `LT(U_ENC_RIGHT, KC_SPC)`
- Left encoder button tap: Volume Mute
- Right encoder button tap: Space
- RGB matrix with 46 LEDs
- Uses RP2040 microcontroller (ARM)

### Kinesis thirteen37
- Custom keyboard variant with audio and LED support
- Has dedicated hardware control code in `keyboards/kinesis/thirteen37/`
- Includes `sounds.h`, `leds.c/h`, and `thirteen37.c/h`

### Miryoku Layout
- The primary layout used across multiple keyboards
- Home row mods with layer-tap functionality
- Configurable via `MIRYOKU_*` variables (ALPHAS, TAP, EXTRA, CLIPBOARD)
- Defined in `users/manna-harbour_miryoku/miryoku_babel/`

## Development Workflow

### Making Changes

1. **Edit files in qmk_userspace** (this repository)
   - Modify keymaps, configs, or user code
   - Add new keyboards/keymaps as needed

2. **Compile to test**:
   ```bash
   qmk compile -kb <keyboard> -km <keymap>
   ```

3. **Verify the build output**:
   - `.uf2` files for RP2040 boards (CRKBD rev4.1)
   - `.hex` files for AVR boards (Atreus, Ergodox)
   - `.bin` files for STM32 boards
   - Firmware appears in userspace root directory

4. **Flash to keyboard** (when ready):
   ```bash
   qmk flash -kb <keyboard> -km <keymap>
   ```

### Testing Encoder Code

When modifying encoder behavior:
1. Build with `qmk compile`
2. Check for compilation warnings about unused variables
3. Test on actual hardware - encoder behavior cannot be fully simulated
4. Verify both normal rotation and button-held rotation work correctly
5. Test across different layers to ensure contextual behavior works

### Memory Considerations

Some keyboards (especially AVR-based) have tight memory constraints:
- Check build output for memory usage warnings
- Disable unused features in `rules.mk` if needed
- Use `#ifdef` guards for optional features
- Consider using `LTO_ENABLE = yes` to reduce firmware size

## CI/CD Pipeline

GitHub Actions automatically builds firmware on push:
- Workflow: `.github/workflows/build_binaries.yaml`
- Uses official QMK workflow: `qmk/.github/.github/workflows/qmk_userspace_build.yml`
- Publishes compiled firmware to GitHub Releases
- Configure targets in `qmk.json` or use `qmk userspace-add`

## Code Style Preferences

### C Code
- 4-space indentation (no tabs)
- QMK naming: `SNAKE_CASE` for constants, `snake_case` for functions
- Descriptive variable names
- Comment complex logic, especially encoder and layer state management
- Use shorter keycode aliases (e.g., `KC_ENT` not `KC_ENTER`)

### Configuration
- Document non-obvious settings in comments
- Keep platform-specific code in conditional blocks
- Use semantic layer names (`U_BASE`, `U_NAV`, `U_NUM`, etc.)
- Group related functionality in layers

### Documentation
- Each keymap should have a `README.md` explaining:
  - Hardware requirements
  - Key features and behaviors
  - Usage examples
  - Troubleshooting
- Keep detailed docs in README, not inline comments
- Update README when refactoring code

## Common Issues and Solutions

### Build Failures
- Ensure `qmk_firmware` is up to date: `qmk git-submodule`
- Check for syntax errors in recent changes
- Verify `rules.mk` feature flags are valid
- Clear build cache: `qmk clean`

### Encoder Not Working
- Verify `ENCODER_ENABLE = yes` in `rules.mk`
- Check encoder pin definitions in `config.h`
- Ensure `encoder_update_user()` returns `false` to skip default handling
- Remember: **Do NOT use `ENCODER_MAP_ENABLE`** when using `encoder_update_user()`

### Layer State Issues
- Verify `layer_state_set_user()` returns the state parameter
- Check that proxy layers are defined with unique IDs
- Ensure base layer is captured when entering proxy layers
- Release any held modifiers when exiting layers

### Platform-Specific Behavior Not Working
- Verify `MIRYOKU_CLIPBOARD` is set in `custom_rules.mk`
- Check that `post_rules.mk` is converting it to `OPT_DEFS`
- Ensure conditional compilation blocks use correct defines
- Test compilation for each platform variant

## File Locations Reference

```
qmk_userspace/
├── keyboards/
│   ├── crkbd/keymaps/manna-harbour_miryoku/    # Corne Miryoku layout
│   ├── atreus/keymaps/lysp/                    # Atreus custom layout
│   └── kinesis/thirteen37/                     # Custom Kinesis variant
├── users/manna-harbour_miryoku/                # Shared Miryoku code
├── qmk.json                                    # Build target configuration
├── .rules                                      # AI agent guidelines
└── .github/workflows/build_binaries.yaml       # CI/CD configuration
```
