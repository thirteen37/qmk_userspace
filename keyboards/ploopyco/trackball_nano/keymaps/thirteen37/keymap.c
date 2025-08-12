/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include QMK_KEYBOARD_H

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

void suspend_power_down_user(void) {
    // Switch off sensor + LED making trackball unable to wake host
    adns5050_power_down();
}

void suspend_wakeup_init_user(void) {
    adns5050_init();
}

#define IDLE_TIMEOUT 1000
#define KEY_CODE KC_F18

static uint16_t idle_timer = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // if there's movement
    if (mouse_report.x != 0 && mouse_report.y != 0) {
        // if the idle timer is not set, send the keydown event
        if (!idle_timer) {
            register_code(KEY_CODE);
        }
        // update the timer
        idle_timer = timer_read();
    }
    return mouse_report;
}

void housekeeping_task_user(void) {
    // if the idle timer is set and the timer has expired, send the keyup event and reset the timer
    if (idle_timer && timer_elapsed(idle_timer) >= IDLE_TIMEOUT) {
        unregister_code(KEY_CODE);
        idle_timer = 0;
    }
}
