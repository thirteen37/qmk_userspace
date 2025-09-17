#pragma once

// Define LAYOUT_miryoku mapping for CRKBD v4.1 using extra keys
// Uses LAYOUT_split_3x6_3_ex2 to utilize the additional keys in v4.1
//
// CRKBD v4.1 Layout Options:
// - LAYOUT_split_3x6_3: Standard 42-key layout (what was used before)
// - LAYOUT_split_3x6_3_ex2: Extended 44-key layout with 4 extra keys
// - LAYOUT_split_3x5_3: Minimal 36-key layout
// - LAYOUT_split_3x5_3_ex2: Minimal + 2 extra keys (38 keys)
//
// The extra keys in v4.1 are positioned:
// - Top right of left half (matrix [0,6])
// - Top left of right half (matrix [4,6])
// - Middle right of left half (matrix [1,6])
// - Middle left of right half (matrix [5,6])
//
// Current mapping for encoder positions:
// - Top extra keys: KC_CAPS (placeholders for encoders 0 and 1)
//   * Left encoder (0): Volume control on most layers, context-specific on others
//   * Right encoder (1): Vertical scroll, undo/redo on nav/button/mouse, volume in media
// - Middle extra keys: KC_CAPS (placeholders for encoders 2 and 3)
// - Outer columns remain U_NU (unused) for maximum compatibility
//
#define LAYOUT_miryoku( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
LAYOUT_split_3x6_3_ex2( \
     U_NU, K00, K01, K02, K03, K04, KC_CAPS,     KC_CAPS, K05, K06, K07, K08, K09, U_NU, \
     U_NU, K10, K11, K12, K13, K14, KC_CAPS,     KC_CAPS, K15, K16, K17, K18, K19, U_NU, \
     U_NU, K20, K21, K22, K23, K24,                       K25, K26, K27, K28, K29, U_NU, \
                         K32, K33, K34,                K35, K36, K37 \
)

// Miryoku configuration
#define MIRYOKU_MAPPING LAYOUT_miryoku
