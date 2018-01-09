#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define OHND 3 // one-handed operation

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 300
#undef TAPPING_TERM
#define TAPPING_TERM 100

//Tap Dance Declarations
enum {
  TD_HYPERSPACE_LEFT = 0,
  TD_HYPERSPACE_RIGHT = 1
};

// Macro shortcuts
enum {
  TAB_RIGHT = 1,
  TAB_LEFT = 2,
  TMUX_COPY_MODE = 5,
  KWM_ESCAPE_SEQ = 6
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | M(1) |           | M(2) |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | M(6) |           | Lead |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| L3   |           | L3   |------+------+------+------+------+--------|
 * | LShPo  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShPC  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  | Grv  |Insert| Left | Right|                                       | Down |  Up  |   [  |   ]  |  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Alt  |       | LGui | Ctrl |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | M(5) |       | PgUp |      |      |
 *                                 |Backsp| Del  |------|       |------| Enter| Space|
 *                                 |ace   |      | M(0) |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,  TD(TD_HYPERSPACE_LEFT),
        KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,  KC_TRNS,
        KC_TRNS,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,  MO(SYMB),
        KC_ESC,   KC_GRV,  KC_INS,  KC_LEFT,  KC_RGHT,
                                              MO(OHND), KC_LALT,
                                                        KC_TAB,
                                         KC_BSPC,KC_DEL,KC_TRNS,
        // right hand
             TD(TD_HYPERSPACE_RIGHT),KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_MINS,
             KC_LEAD                ,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_BSLS,
                                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
             MO(SYMB),               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,
                                             KC_DOWN,KC_UP,  KC_LBRC,KC_RBRC,  MO(MDIA),
             KC_LGUI, KC_RCTL,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrScr  |  F1  |  F2  |  F3  |  F4  |  F5  | M(3) |           | M(4) |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ScrLk  |   !  |   @  |  Up  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Pause  |   #  |  Lf  |  Dn  |  Rt  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_PSCR,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_SLCK,KC_EXLM,KC_AT,  KC_UP,  KC_RCBR,KC_PIPE,KC_TRNS,
       KC_PAUS,KC_HASH,KC_LEFT,KC_DOWN,KC_RGHT,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,    KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_0
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                                    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),


/* Keymap 3: Flipped ergodox
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[OHND] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                                    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TRNS,
                 KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_TRNS,
       KC_TRNS,  KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

/*
const macro_t *tmux_escape(void) {
  return MACRO( D(LCTRL), T(B), U(LCTRL), END  );
}

const macro_t *shift_tab_left(void) {
	return MACRO( D(LGUI), D(LSFT), T(LCBR), U(LSFT), U(LGUI), END  );
};

const macro_t *shift_tab_right(void) {
	return MACRO( D(LGUI), D(LSFT), T(RCBR), U(LSFT), U(LGUI), END  );
}
*/
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // Tmux Ctrl+B
      if (record->event.pressed) {
        return tmux_escape();
      }
      break;
    case 1: // Shift window tab right
      if (record->event.pressed) {
        return shift_tab_right();
      }
      break;
    case 2: // Shift window tab left
      if (record->event.pressed) {
				return shift_tab_left();
      }
      break;
    case 3: // Tmux Ctrl+B, P
      if (record->event.pressed) {
        return MACRO( D(LCTRL), T(B), U(LCTRL), T(P), END  );
      }
      break;
    case 4: // Tmux Ctrl+B, N
      if (record->event.pressed) {
        return MACRO( D(LCTRL), T(B), U(LCTRL), T(N), END  );
      }
      break;
    case 5: // Tmux Ctrl+B, [
      if (record->event.pressed) {
        return MACRO( D(LCTRL), T(B), U(LCTRL), T(LBRC), END  );
      }
      break;
    case 6: // KWM Ctrl+S
      if (record->event.pressed) {
        return MACRO( D(LCTRL), T(S), U(LCTRL), END  );
      }
      break;
  }
  return MACRO_NONE;
};
*/

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

void goto_left_space(void) {
		/* register_code(KC_RCTL); */
		/* register_code(KC_LEFT); */
		/* unregister_code(KC_LEFT); */
		/* unregister_code(KC_RCTL); */
};

void goto_right_space(void) {
		/* register_code(KC_RCTL); */
		/* register_code(KC_RGHT); */
		/* unregister_code(KC_RGHT); */
		/* unregister_code(KC_RCTL); */
}

void goto_left_tab(void) {
		/* register_code(KC_LGUI); */
		/* register_code(KC_LSFT); */
		/* register_code(KC_LCBR); */
		/* unregister_code(KC_LCBR); */
		/* unregister_code(KC_LSFT); */
		/* unregister_code(KC_LGUI); */
}

void goto_right_tab(void) {
		/* register_code(KC_LGUI); */
		/* register_code(KC_LSFT); */
		/* register_code(KC_RCBR); */
		/* unregister_code(KC_RCBR); */
		/* unregister_code(KC_LSFT); */
		/* unregister_code(KC_LGUI); */
}

void hyperspace_left(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
		goto_left_space();
  } else {
    goto_left_tab();
  }
};

void hyperspace_right(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
		goto_right_space();
  } else {
    goto_right_tab();
  }
};

void activate_tmux_edit_mode(void) {
  /* register_code(KC_LCTL); */
  /* register_code(KC_B); */
  /* unregister_code(KC_B); */
  /* unregister_code(KC_LCTL); */
  /* register_code(KC_LBRC); */
  /* unregister_code(KC_LBRC); */
}

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_HYPERSPACE_LEFT]  = ACTION_TAP_DANCE_FN(hyperspace_left),
  [TD_HYPERSPACE_RIGHT]  = ACTION_TAP_DANCE_FN(hyperspace_right),
};

// leader definition
LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        case OHND:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

		LEADER_DICTIONARY() {
			leading = false;
			leader_end();

			SEQ_ONE_KEY(KC_F) {
        activate_tmux_edit_mode();
        register_code(KC_LSFT);
        register_code(KC_SLSH);
        unregister_code(KC_SLSH);
        unregister_code(KC_LSFT);
			}
		}
};

