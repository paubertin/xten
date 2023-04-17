#pragma once

// From glfw3.h
// #define (?<name>XT_KEY_([a-zA-Z_\d]*)(\s)*)(?<code>\d*)(?<comment>.*)

constexpr auto XT_KEY_SPACE               = 32; 
constexpr auto XT_KEY_APOSTROPHE          = 39;   /* ' */
constexpr auto XT_KEY_COMMA               = 44;   /* , */
constexpr auto XT_KEY_MINUS               = 45;   /* - */
constexpr auto XT_KEY_PERIOD              = 46;   /* . */
constexpr auto XT_KEY_SLASH               = 47;   /* / */
constexpr auto XT_KEY_0                   = 48; 
constexpr auto XT_KEY_1                   = 49; 
constexpr auto XT_KEY_2                   = 50; 
constexpr auto XT_KEY_3                   = 51; 
constexpr auto XT_KEY_4                   = 52; 
constexpr auto XT_KEY_5                   = 53; 
constexpr auto XT_KEY_6                   = 54; 
constexpr auto XT_KEY_7                   = 55; 
constexpr auto XT_KEY_8                   = 56; 
constexpr auto XT_KEY_9                   = 57; 
constexpr auto XT_KEY_SEMICOLON           = 59;   /* ; */
constexpr auto XT_KEY_EQUAL               = 61;   /* = */
constexpr auto XT_KEY_A                   = 65; 
constexpr auto XT_KEY_B                   = 66; 
constexpr auto XT_KEY_C                   = 67; 
constexpr auto XT_KEY_D                   = 68; 
constexpr auto XT_KEY_E                   = 69; 
constexpr auto XT_KEY_F                   = 70; 
constexpr auto XT_KEY_G                   = 71; 
constexpr auto XT_KEY_H                   = 72; 
constexpr auto XT_KEY_I                   = 73; 
constexpr auto XT_KEY_J                   = 74; 
constexpr auto XT_KEY_K                   = 75; 
constexpr auto XT_KEY_L                   = 76; 
constexpr auto XT_KEY_M                   = 77; 
constexpr auto XT_KEY_N                   = 78; 
constexpr auto XT_KEY_O                   = 79; 
constexpr auto XT_KEY_P                   = 80; 
constexpr auto XT_KEY_Q                   = 81; 
constexpr auto XT_KEY_R                   = 82; 
constexpr auto XT_KEY_S                   = 83; 
constexpr auto XT_KEY_T                   = 84; 
constexpr auto XT_KEY_U                   = 85; 
constexpr auto XT_KEY_V                   = 86; 
constexpr auto XT_KEY_W                   = 87; 
constexpr auto XT_KEY_X                   = 88; 
constexpr auto XT_KEY_Y                   = 89; 
constexpr auto XT_KEY_Z                   = 90; 
constexpr auto XT_KEY_LEFT_BRACKET        = 91;   /* [ */
constexpr auto XT_KEY_BACKSLASH           = 92;   /* \ */
constexpr auto XT_KEY_RIGHT_BRACKET       = 93;   /* ] */
constexpr auto XT_KEY_GRAVE_ACCENT        = 96;   /* ` */
constexpr auto XT_KEY_WORLD_1             = 161;  /* non-US #1 */
constexpr auto XT_KEY_WORLD_2             = 162;  /* non-US #2 */

/* Function keys */
constexpr auto XT_KEY_ESCAPE              = 256; 
constexpr auto XT_KEY_ENTER               = 257; 
constexpr auto XT_KEY_TAB				  = 258;
constexpr auto XT_KEY_BACKSPACE           = 259; 
constexpr auto XT_KEY_INSERT              = 260; 
constexpr auto XT_KEY_DELETE              = 261; 
constexpr auto XT_KEY_RIGHT               = 262; 
constexpr auto XT_KEY_LEFT                = 263; 
constexpr auto XT_KEY_DOWN                = 264; 
constexpr auto XT_KEY_UP                  = 265; 
constexpr auto XT_KEY_PAGE_UP             = 266; 
constexpr auto XT_KEY_PAGE_DOWN           = 267; 
constexpr auto XT_KEY_HOME                = 268; 
constexpr auto XT_KEY_END                 = 269; 
constexpr auto XT_KEY_CAPS_LOCK           = 280; 
constexpr auto XT_KEY_SCROLL_LOCK         = 281; 
constexpr auto XT_KEY_NUM_LOCK            = 282; 
constexpr auto XT_KEY_PRINT_SCREEN        = 283; 
constexpr auto XT_KEY_PAUSE               = 284; 
constexpr auto XT_KEY_F1                  = 290; 
constexpr auto XT_KEY_F2                  = 291; 
constexpr auto XT_KEY_F3                  = 292; 
constexpr auto XT_KEY_F4                  = 293; 
constexpr auto XT_KEY_F5                  = 294; 
constexpr auto XT_KEY_F6                  = 295; 
constexpr auto XT_KEY_F7                  = 296; 
constexpr auto XT_KEY_F8                  = 297; 
constexpr auto XT_KEY_F9                  = 298; 
constexpr auto XT_KEY_F10                 = 299; 
constexpr auto XT_KEY_F11                 = 300; 
constexpr auto XT_KEY_F12                 = 301; 
constexpr auto XT_KEY_F13                 = 302; 
constexpr auto XT_KEY_F14                 = 303; 
constexpr auto XT_KEY_F15                 = 304; 
constexpr auto XT_KEY_F16                 = 305; 
constexpr auto XT_KEY_F17                 = 306; 
constexpr auto XT_KEY_F18                 = 307; 
constexpr auto XT_KEY_F19                 = 308; 
constexpr auto XT_KEY_F20                 = 309; 
constexpr auto XT_KEY_F21                 = 310; 
constexpr auto XT_KEY_F22                 = 311; 
constexpr auto XT_KEY_F23                 = 312; 
constexpr auto XT_KEY_F24                 = 313; 
constexpr auto XT_KEY_F25                 = 314; 
constexpr auto XT_KEY_KP_0                = 320; 
constexpr auto XT_KEY_KP_1                = 321; 
constexpr auto XT_KEY_KP_2                = 322; 
constexpr auto XT_KEY_KP_3                = 323; 
constexpr auto XT_KEY_KP_4                = 324; 
constexpr auto XT_KEY_KP_5                = 325; 
constexpr auto XT_KEY_KP_6                = 326; 
constexpr auto XT_KEY_KP_7                = 327; 
constexpr auto XT_KEY_KP_8                = 328; 
constexpr auto XT_KEY_KP_9                = 329; 
constexpr auto XT_KEY_KP_DECIMAL          = 330; 
constexpr auto XT_KEY_KP_DIVIDE           = 331; 
constexpr auto XT_KEY_KP_MULTIPLY         = 332; 
constexpr auto XT_KEY_KP_SUBTRACT         = 333; 
constexpr auto XT_KEY_KP_ADD              = 334; 
constexpr auto XT_KEY_KP_ENTER            = 335; 
constexpr auto XT_KEY_KP_EQUAL            = 336; 
constexpr auto XT_KEY_LEFT_SHIFT          = 340; 
constexpr auto XT_KEY_LEFT_CONTROL        = 341; 
constexpr auto XT_KEY_LEFT_ALT            = 342; 
constexpr auto XT_KEY_LEFT_SUPER          = 343; 
constexpr auto XT_KEY_RIGHT_SHIFT         = 344; 
constexpr auto XT_KEY_RIGHT_CONTROL       = 345; 
constexpr auto XT_KEY_RIGHT_ALT           = 346; 
constexpr auto XT_KEY_RIGHT_SUPER         = 347; 
constexpr auto XT_KEY_MENU                = 348; 