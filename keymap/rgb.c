#ifdef RGB_MATRIX_ENABLE
#include "layers.h" // layers enum

#define COMMA ,

#define COLOR_OFF {0 COMMA 0 COMMA 0}
#define _________ COLOR_OFF

#define COLOR_RED {0 COMMA 255 COMMA 255}
#define COLOR_GREEN {85 COMMA 255 COMMA 255}
#define COLOR_BLUE {170 COMMA 255 COMMA 255}

#define COLOR_DBLUE {146 COMMA 224 COMMA 255}
#define COLOR_YELLOW {33 COMMA 255 COMMA 255}
#define COLOR_ORANGE {14 COMMA 255 COMMA 255}
#define COLOR_PURPLE {243 COMMA 222 COMMA 234}

#define COLOR_KEEB {30 COMMA 96 COMMA 255}
#define COLOR_RU COLOR_BLUE
#define COLOR_PROG COLOR_GREEN

#define LEDS_SOFLE( \
	k00, k01, k02, k03, k04, k05,   k06, k07, k08, k09, k0a, k0b, \
	k10, k11, k12, k13, k14, k15,   k16, k17, k18, k19, k1a, k1b, \
	k20, k21, k22, k23, k24, k25,   k26, k27, k28, k29, k2a, k2b, \
	k30, k31, k32, k33, k34, k35,   k36, k37, k38, k39, k3a, k3b, \
	k40, k41, k42, k43, k44,	         k47, k48, k49, k4a, k4b  \
)                                                                 \
{                                                                                \
	_________, _________, _________, _________, _________, _________,           \
	k40, k30, k20, k10, k00, k01, k11, k21, k31, k41, k42, k32, k22, k12, k02,   \
	k03, k13, k23, k33, k43, k44, k34, k24, k14, k04, k05, k15, k25, k35,        \
	k0b, k1b, k2b, k3b, k4b, k4a, k3a, k2a, k1a, k0a, k09, k19, k29, k39, k49,   \
    k48, k38, k28, k18, k08, k07, k17, k27, k37, k47, k36, k26, k16, k06,        \
	_________, _________, _________, _________, _________, _________             \
}

// 	k4b, k3b, k2b, k1b, k0b, k0a, k1a, k2a, k3a, k4a, k49, k39, k29, k19, k09,
// 	k08, k18, k28, k38, k48, k47, k37, k27, k17, k07, k06, k16, k26, k36 

// k36, k26, k16, k06, k07, k17, k27, k37, k47, k48, k38, k28, k18, k08,        
// 	k09, k19, k29, k39, k49, k4a, k3a, k2a, k1a, k0a, k0b, k1b, k2b, k3b, k4b    




const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_RU] = LEDS_SOFLE(
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		           COLOR_RU,  COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU,    COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU
	), 
	[L_MOVE] = LEDS_SOFLE(
		_________, COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE,    COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE, COLOR_DBLUE, _________,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW, COLOR_DBLUE,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_ORANGE, COLOR_ORANGE, COLOR_ORANGE, COLOR_ORANGE, COLOR_DBLUE,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, _________,
		           COLOR_RU,  COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU,    COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU, COLOR_RU
	),
    [L_PROG] = LEDS_SOFLE(
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_GREEN, _________,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_GREEN, COLOR_GREEN, COLOR_GREEN, COLOR_GREEN, _________,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_DBLUE, COLOR_GREEN, _________, _________, _________,
		           COLOR_PROG,  COLOR_PROG, COLOR_PROG, COLOR_PROG, COLOR_PROG,    COLOR_PROG, COLOR_PROG, COLOR_PROG, COLOR_PROG, COLOR_PROG
	),
    [L_KEEB] = LEDS_SOFLE(
		_________, _________, _________, _________, _________, COLOR_YELLOW,    _________, _________, _________, _________, _________, COLOR_RED,
		_________, _________, _________, _________, _________, _________,    _________, COLOR_GREEN, COLOR_BLUE, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		_________, _________, _________, _________, _________, _________,    _________, _________, _________, _________, _________, _________,
		           COLOR_KEEB,  COLOR_KEEB, COLOR_KEEB, COLOR_KEEB, COLOR_KEEB,    COLOR_KEEB, COLOR_KEEB, COLOR_KEEB, COLOR_KEEB, COLOR_KEEB
	),
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rgb_matrix_get_suspend_state()) { return false; }
  switch (biton32(layer_state)) {
    //L_EN and L_EN_S intentionally have no designated cases here
    case L_RU:
    case L_RU_S:
      set_layer_color(L_RU);
      break;
    case L_MOVE:
      set_layer_color(L_MOVE);
      break;
    case L_PROG:
      set_layer_color(L_PROG);
      break;
    case L_KEEB:
      set_layer_color(L_KEEB);
      break;

   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}
#endif