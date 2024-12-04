/*
    SPDX-FileCopyrightText: 2024 Thomas Dickson 

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#include <QWindow>
#include <QtWaylandClient/private/qwaylandwindow_p.h>

#include "qtKeyToXkb.h"

// TODO
//
// Broken chars: (got <- expected/name)
// À <- `/backtick
// Â <- stirling/pound
// <- euro
// <- sqrt
// { <- center period
// <- left quotes
// <- right quotes
// <- trademarked

const QHash<Qt::Key, xkb_keysym_t> qtKeyToXkb = {
    // Qt Keycodes to Xkb Keycodes
    //
    // https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qnamespace.h#n520
    // https://xkbcommon.org/doc/current/xkbcommon-keysyms_8h.html
    
    { Qt::Key_Space, XKB_KEY_space },
    { Qt::Key_Any, XKB_KEY_space },
    { Qt::Key_Exclam, XKB_KEY_exclam },
    { Qt::Key_QuoteDbl, XKB_KEY_quotedbl },
    { Qt::Key_NumberSign, XKB_KEY_numbersign},
    { Qt::Key_Dollar, XKB_KEY_dollar },
    { Qt::Key_Percent, XKB_KEY_percent },
    { Qt::Key_Ampersand, XKB_KEY_ampersand },
    { Qt::Key_Apostrophe, XKB_KEY_apostrophe },
    { Qt::Key_ParenLeft, XKB_KEY_parenleft },
    { Qt::Key_ParenRight, XKB_KEY_parenright },
    { Qt::Key_Asterisk, XKB_KEY_asterisk },
    { Qt::Key_Plus, XKB_KEY_plus },
    { Qt::Key_Comma, XKB_KEY_comma },
    { Qt::Key_Minus, XKB_KEY_minus },
    { Qt::Key_Period, XKB_KEY_period },
    { Qt::Key_Slash, XKB_KEY_slash },
    { Qt::Key_0, XKB_KEY_0 },
    { Qt::Key_1, XKB_KEY_1 },
    { Qt::Key_2, XKB_KEY_2 },
    { Qt::Key_3, XKB_KEY_3 },
    { Qt::Key_4, XKB_KEY_4 },
    { Qt::Key_5, XKB_KEY_5 },
    { Qt::Key_6, XKB_KEY_6 },
    { Qt::Key_7, XKB_KEY_7 },
    { Qt::Key_8, XKB_KEY_8 },
    { Qt::Key_9, XKB_KEY_9 },
    { Qt::Key_Colon, XKB_KEY_colon },
    { Qt::Key_Semicolon, XKB_KEY_semicolon },
    { Qt::Key_Less, XKB_KEY_less },
    { Qt::Key_Equal, XKB_KEY_equal },
    { Qt::Key_Greater, XKB_KEY_greater },
    { Qt::Key_Question, XKB_KEY_question },
    { Qt::Key_At, XKB_KEY_at },
    { Qt::Key_A, XKB_KEY_a },
    { Qt::Key_B, XKB_KEY_b },
    { Qt::Key_C, XKB_KEY_c },
    { Qt::Key_D, XKB_KEY_d },
    { Qt::Key_E, XKB_KEY_e },
    { Qt::Key_F, XKB_KEY_f },
    { Qt::Key_G, XKB_KEY_g },
    { Qt::Key_H, XKB_KEY_h },
    { Qt::Key_I, XKB_KEY_i },
    { Qt::Key_J, XKB_KEY_j },
    { Qt::Key_K, XKB_KEY_k },
    { Qt::Key_L, XKB_KEY_l },
    { Qt::Key_M, XKB_KEY_m },
    { Qt::Key_N, XKB_KEY_n },
    { Qt::Key_O, XKB_KEY_o },
    { Qt::Key_P, XKB_KEY_p },
    { Qt::Key_Q, XKB_KEY_q },
    { Qt::Key_R, XKB_KEY_r },
    { Qt::Key_S, XKB_KEY_s },
    { Qt::Key_T, XKB_KEY_t },
    { Qt::Key_U, XKB_KEY_u },
    { Qt::Key_V, XKB_KEY_v },
    { Qt::Key_W, XKB_KEY_w },
    { Qt::Key_X, XKB_KEY_x },
    { Qt::Key_Y, XKB_KEY_y },
    { Qt::Key_Z, XKB_KEY_z },
    { Qt::Key_BracketLeft, XKB_KEY_bracketleft },
    { Qt::Key_Backslash, XKB_KEY_backslash },
    { Qt::Key_BracketRight, XKB_KEY_bracketright },
    { Qt::Key_AsciiCircum, XKB_KEY_asciicircum },
    { Qt::Key_Underscore, XKB_KEY_underscore },
    { Qt::Key_QuoteLeft, XKB_KEY_quoteleft },
    { Qt::Key_BraceLeft, XKB_KEY_braceleft },
    { Qt::Key_Bar, XKB_KEY_bar },
    { Qt::Key_BraceRight, XKB_KEY_braceright },
    { Qt::Key_AsciiTilde, XKB_KEY_asciitilde },

    // Unicode Latin-1 Supplement block (0x80-0xff)
    { Qt::Key_nobreakspace, XKB_KEY_nobreakspace },
    { Qt::Key_exclamdown, XKB_KEY_exclamdown },
    { Qt::Key_cent, XKB_KEY_cent },
    { Qt::Key_sterling, XKB_KEY_sterling },
    { Qt::Key_currency, XKB_KEY_currency },
    { Qt::Key_yen, XKB_KEY_yen },
    { Qt::Key_brokenbar, XKB_KEY_brokenbar },
    { Qt::Key_section, XKB_KEY_section },
    { Qt::Key_diaeresis, XKB_KEY_diaeresis },
    { Qt::Key_copyright, XKB_KEY_copyright },
    { Qt::Key_ordfeminine, XKB_KEY_ordfeminine },
    { Qt::Key_guillemotleft, XKB_KEY_guillemotleft },        // left angle quotation mark
    { Qt::Key_notsign, XKB_KEY_notsign },
    { Qt::Key_hyphen, XKB_KEY_hyphen },
    { Qt::Key_registered, XKB_KEY_registered },
    { Qt::Key_macron, XKB_KEY_macron },
    { Qt::Key_degree, XKB_KEY_degree },
    { Qt::Key_plusminus, XKB_KEY_plusminus },
    { Qt::Key_twosuperior, XKB_KEY_twosuperior },
    { Qt::Key_threesuperior, XKB_KEY_threesuperior },
    { Qt::Key_acute, XKB_KEY_acute },
    { Qt::Key_micro, XKB_KEY_mu },
    { Qt::Key_paragraph, XKB_KEY_paragraph },
    { Qt::Key_periodcentered, XKB_KEY_periodcentered },
    { Qt::Key_cedilla, XKB_KEY_cedilla },
    { Qt::Key_onesuperior, XKB_KEY_onesuperior },
    { Qt::Key_masculine, XKB_KEY_masculine },
    { Qt::Key_guillemotright, XKB_KEY_guillemotright },        // right angle quotation mark
    { Qt::Key_onequarter, XKB_KEY_onequarter },
    { Qt::Key_onehalf, XKB_KEY_onehalf },
    { Qt::Key_threequarters, XKB_KEY_threequarters },
    { Qt::Key_questiondown, XKB_KEY_questiondown },
    { Qt::Key_Agrave, XKB_KEY_Agrave },
    { Qt::Key_Aacute, XKB_KEY_Aacute },
    { Qt::Key_Acircumflex, XKB_KEY_Acircumflex },
    { Qt::Key_Atilde, XKB_KEY_Atilde },
    { Qt::Key_Adiaeresis, XKB_KEY_Adiaeresis },
    { Qt::Key_Aring, XKB_KEY_Aring },
    { Qt::Key_AE, XKB_KEY_AE },
    { Qt::Key_Ccedilla, XKB_KEY_Ccedilla },
    { Qt::Key_Egrave, XKB_KEY_Egrave },
    { Qt::Key_Eacute, XKB_KEY_Eacute },
    { Qt::Key_Ecircumflex, XKB_KEY_Ecircumflex },
    { Qt::Key_Ediaeresis, XKB_KEY_Ediaeresis },
    { Qt::Key_Igrave, XKB_KEY_Igrave },
    { Qt::Key_Iacute, XKB_KEY_Iacute },
    { Qt::Key_Icircumflex, XKB_KEY_Icircumflex },
    { Qt::Key_Idiaeresis, XKB_KEY_Idiaeresis },
    { Qt::Key_ETH, XKB_KEY_ETH },
    { Qt::Key_Ntilde, XKB_KEY_Ntilde },
    { Qt::Key_Ograve, XKB_KEY_Ograve },
    { Qt::Key_Oacute, XKB_KEY_Oacute },
    { Qt::Key_Ocircumflex, XKB_KEY_Ocircumflex },
    { Qt::Key_Otilde, XKB_KEY_Otilde },
    { Qt::Key_Odiaeresis, XKB_KEY_Odiaeresis },
    { Qt::Key_multiply, XKB_KEY_multiply },
    { Qt::Key_Ooblique, XKB_KEY_Ooblique },
    { Qt::Key_Ugrave, XKB_KEY_Ugrave },
    { Qt::Key_Uacute, XKB_KEY_Uacute },
    { Qt::Key_Ucircumflex, XKB_KEY_Ucircumflex },
    { Qt::Key_Udiaeresis, XKB_KEY_Udiaeresis },
    { Qt::Key_Yacute, XKB_KEY_Yacute },
    { Qt::Key_THORN, XKB_KEY_THORN },
    { Qt::Key_ssharp, XKB_KEY_ssharp },
    { Qt::Key_division, XKB_KEY_division },
    { Qt::Key_ydiaeresis, XKB_KEY_ydiaeresis },

    { Qt::Key_Escape, XKB_KEY_Escape },                // misc keys
    { Qt::Key_Tab, XKB_KEY_Tab },
    { Qt::Key_Backtab, XKB_KEY_BackTab },
    { Qt::Key_Backspace, XKB_KEY_BackSpace },
    { Qt::Key_Return, XKB_KEY_Return },
    { Qt::Key_Enter, XKB_KEY_Return },
    { Qt::Key_Insert, XKB_KEY_Insert },
    { Qt::Key_Delete, XKB_KEY_Delete },
    { Qt::Key_Pause, XKB_KEY_Pause },
    { Qt::Key_Print, XKB_KEY_Print },               // print screen
    { Qt::Key_SysReq, XKB_KEY_Sys_Req },
    { Qt::Key_Clear, XKB_KEY_Clear },
    { Qt::Key_Home, XKB_KEY_Home },                // cursor movement
    { Qt::Key_End, XKB_KEY_End },
    { Qt::Key_Left, XKB_KEY_Left },
    { Qt::Key_Up, XKB_KEY_Up },
    { Qt::Key_Right, XKB_KEY_Right },
    { Qt::Key_Down, XKB_KEY_Down },
    { Qt::Key_PageUp, XKB_KEY_Page_Up },
    { Qt::Key_PageDown, XKB_KEY_Page_Down },
    { Qt::Key_Shift, XKB_KEY_Shift_L },                // modifiers
    { Qt::Key_Control, XKB_KEY_Control_L },
    { Qt::Key_Meta, XKB_KEY_Meta_L },
    { Qt::Key_Alt, XKB_KEY_Alt_L },
    { Qt::Key_CapsLock, XKB_KEY_Caps_Lock },
    { Qt::Key_NumLock, XKB_KEY_Num_Lock },
    { Qt::Key_ScrollLock, XKB_KEY_Scroll_Lock },
    { Qt::Key_F1, XKB_KEY_F1 },                // function keys
    { Qt::Key_F2, XKB_KEY_F2 },
    { Qt::Key_F3, XKB_KEY_F3 },
    { Qt::Key_F4, XKB_KEY_F4 },
    { Qt::Key_F5, XKB_KEY_F5 },
    { Qt::Key_F6, XKB_KEY_F5 },
    { Qt::Key_F7, XKB_KEY_F6 },
    { Qt::Key_F8, XKB_KEY_F7 },
    { Qt::Key_F9, XKB_KEY_F9 },
    { Qt::Key_F10, XKB_KEY_F10 },
    { Qt::Key_F11, XKB_KEY_F11 },
    { Qt::Key_F12, XKB_KEY_F12 },
    { Qt::Key_F13, XKB_KEY_F13 },
    { Qt::Key_F14, XKB_KEY_F14 },
    { Qt::Key_F15, XKB_KEY_F15 },
    { Qt::Key_F16, XKB_KEY_F16 },
    { Qt::Key_F17, XKB_KEY_F17 },
    { Qt::Key_F18, XKB_KEY_F18 },
    { Qt::Key_F19, XKB_KEY_F19 },
    { Qt::Key_F20, XKB_KEY_F20 },
    { Qt::Key_F21, XKB_KEY_F21 },
    { Qt::Key_F22, XKB_KEY_F22 },
    { Qt::Key_F23, XKB_KEY_F23 },
    { Qt::Key_F24, XKB_KEY_F24 },
    { Qt::Key_F25, XKB_KEY_F25 },                // F25 .. F35 only on X11
    { Qt::Key_F26, XKB_KEY_F26 },
    { Qt::Key_F27, XKB_KEY_F27 },
    { Qt::Key_F28, XKB_KEY_F28 },
    { Qt::Key_F29, XKB_KEY_F29 },
    { Qt::Key_F30, XKB_KEY_F30 },
    { Qt::Key_F31, XKB_KEY_F31 },
    { Qt::Key_F32, XKB_KEY_F32 },
    { Qt::Key_F33, XKB_KEY_F33 },
    { Qt::Key_F34, XKB_KEY_F34 },
    { Qt::Key_F35, XKB_KEY_F35 },
    { Qt::Key_Super_L, XKB_KEY_Super_L },                 // extra keys
    { Qt::Key_Super_R, XKB_KEY_Super_R },
    { Qt::Key_Hyper_L, XKB_KEY_Hyper_L },
    { Qt::Key_Hyper_R, XKB_KEY_Hyper_R },
    { Qt::Key_Help, XKB_KEY_Help },
    { Qt::Key_Menu, XKB_KEY_osfMenu },
    { Qt::Key_Direction_L, XKB_KEY_osfPrevMenu },
    { Qt::Key_Direction_R, XKB_KEY_osfNextMenu },

    //  International & multi-key character composition
    { Qt::Key_AltGr              , XKB_KEY_Alt_R             },  // TODO
    { Qt::Key_Multi_key          , XKB_KEY_Multi_key         },  // Multi-key character compose
    { Qt::Key_Codeinput          , XKB_KEY_Codeinput         },
    { Qt::Key_SingleCandidate    , XKB_KEY_SingleCandidate   },
    { Qt::Key_MultipleCandidate  , XKB_KEY_MultipleCandidate },
    { Qt::Key_PreviousCandidate  , XKB_KEY_PreviousCandidate },

    //  Misc Functions
    { Qt::Key_Mode_switch        , XKB_KEY_Mode_switch },  // Character set switch

    //  Japanese keyboard support -- commented out ones in https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qnamespace.h are deleted here
    { Qt::Key_Kanji              , XKB_KEY_Kanji },  // Kanji, Kanji convert
    { Qt::Key_Muhenkan           , XKB_KEY_Muhenkan },  // Cancel Conversion
    { Qt::Key_Henkan             , XKB_KEY_Henkan },  // Alias for Henkan_Mode
    { Qt::Key_Romaji             , XKB_KEY_Romaji },  // to Romaji
    { Qt::Key_Hiragana           , XKB_KEY_Hiragana },  // to Hiragana
    { Qt::Key_Katakana           , XKB_KEY_Katakana },  // to Katakana
    { Qt::Key_Hiragana_Katakana  , XKB_KEY_Hiragana_Katakana },  // Hiragana/Katakana toggle
    { Qt::Key_Zenkaku            , XKB_KEY_Zenkaku     },  // to Zenkaku
    { Qt::Key_Hankaku            , XKB_KEY_Hankaku     },  // to Hankaku
    { Qt::Key_Zenkaku_Hankaku    , XKB_KEY_Zenkaku_Hankaku },  // Zenkaku/Hankaku toggle
    { Qt::Key_Touroku            , XKB_KEY_Touroku     },  // Add to Dictionary
    { Qt::Key_Massyo             , XKB_KEY_Massyo      },  // Delete from Dictionary
    { Qt::Key_Kana_Lock          , XKB_KEY_Kana_Lock   },  // Kana Lock
    { Qt::Key_Kana_Shift         , XKB_KEY_Kana_Shift  },  // Kana Shift
    { Qt::Key_Eisu_Shift         , XKB_KEY_Eisu_Shift  },  // Alphanumeric Shift
    { Qt::Key_Eisu_toggle        , XKB_KEY_Eisu_toggle },  // Alphanumeric toggle

    //  Korean keyboard support
    { Qt::Key_Hangul             , XKB_KEY_Hangul        },  // Hangul start/stop(toggle)
    { Qt::Key_Hangul_Start       , XKB_KEY_Hangul_Start  },  // Hangul start
    { Qt::Key_Hangul_End         , XKB_KEY_Hangul_End    },  // Hangul end, English start
    { Qt::Key_Hangul_Hanja       , XKB_KEY_Hangul_Hanja  },  // Start Hangul->Hanja Conversion
    { Qt::Key_Hangul_Jamo        , XKB_KEY_Hangul_Jamo   },  // Hangul Jamo mode
    { Qt::Key_Hangul_Romaja      , XKB_KEY_Hangul_Romaja },  // Hangul Romaja mode
    { Qt::Key_Hangul_Jeonja      , XKB_KEY_Hangul_Jeonja },  // Jeonja mode
    { Qt::Key_Hangul_Banja       , XKB_KEY_Hangul_Banja  },  // Banja mode
    { Qt::Key_Hangul_PreHanja    , XKB_KEY_Hangul_PreHanja },  // Pre Hanja conversion
    { Qt::Key_Hangul_PostHanja   , XKB_KEY_Hangul_PostHanja },  // Post Hanja conversion
    { Qt::Key_Hangul_Special     , XKB_KEY_Hangul_Special },  // Special symbols

    //  dead keys (X keycode - 0xED00 to avoid the conflict)
    { Qt::Key_Dead_Grave         , XKB_KEY_dead_grave        },
    { Qt::Key_Dead_Acute         , XKB_KEY_dead_acute        },
    { Qt::Key_Dead_Circumflex    , XKB_KEY_dead_circumflex   },
    { Qt::Key_Dead_Tilde         , XKB_KEY_dead_tilde        },
    { Qt::Key_Dead_Macron        , XKB_KEY_dead_macron       },
    { Qt::Key_Dead_Breve         , XKB_KEY_dead_breve        },
    { Qt::Key_Dead_Abovedot      , XKB_KEY_dead_abovedot     },
    { Qt::Key_Dead_Diaeresis     , XKB_KEY_dead_diaeresis    },
    { Qt::Key_Dead_Abovering     , XKB_KEY_dead_abovering    },
    { Qt::Key_Dead_Doubleacute   , XKB_KEY_dead_doubleacute  },
    { Qt::Key_Dead_Caron         , XKB_KEY_dead_caron        },
    { Qt::Key_Dead_Cedilla       , XKB_KEY_dead_cedilla      },
    { Qt::Key_Dead_Ogonek        , XKB_KEY_dead_ogonek       },
    { Qt::Key_Dead_Iota          , XKB_KEY_dead_iota         },
    { Qt::Key_Dead_Voiced_Sound  , XKB_KEY_dead_voiced_sound },
    { Qt::Key_Dead_Semivoiced_Sound, XKB_KEY_semivoicedsound },
    { Qt::Key_Dead_Belowdot      , XKB_KEY_dead_belowdot       },
    { Qt::Key_Dead_Hook          , XKB_KEY_dead_hook           },
    { Qt::Key_Dead_Horn          , XKB_KEY_dead_horn           },
    { Qt::Key_Dead_Stroke        , XKB_KEY_dead_stroke         },
    { Qt::Key_Dead_Abovecomma    , XKB_KEY_dead_abovecomma     },
    { Qt::Key_Dead_Abovereversedcomma, XKB_KEY_dead_abovereversedcomma },
    { Qt::Key_Dead_Doublegrave   , XKB_KEY_dead_doublegrave    },
    { Qt::Key_Dead_Belowring     , XKB_KEY_dead_belowring      },
    { Qt::Key_Dead_Belowmacron   , XKB_KEY_dead_belowmacron    },
    { Qt::Key_Dead_Belowcircumflex, XKB_KEY_dead_belowcircumflex },
    { Qt::Key_Dead_Belowtilde    , XKB_KEY_dead_belowtilde     },
    { Qt::Key_Dead_Belowbreve    , XKB_KEY_dead_belowbreve     },
    { Qt::Key_Dead_Belowdiaeresis, XKB_KEY_dead_belowdiaeresis },
    { Qt::Key_Dead_Invertedbreve , XKB_KEY_dead_invertedbreve  },
    { Qt::Key_Dead_Belowcomma    , XKB_KEY_dead_belowcomma     },
    { Qt::Key_Dead_Currency      , XKB_KEY_dead_currency       },
    { Qt::Key_Dead_a             , XKB_KEY_dead_a              },
    { Qt::Key_Dead_A             , XKB_KEY_dead_A              },
    { Qt::Key_Dead_e             , XKB_KEY_dead_e              },
    { Qt::Key_Dead_E             , XKB_KEY_dead_E              },
    { Qt::Key_Dead_i             , XKB_KEY_dead_i              },
    { Qt::Key_Dead_I             , XKB_KEY_dead_I              },
    { Qt::Key_Dead_o             , XKB_KEY_dead_o              },
    { Qt::Key_Dead_O             , XKB_KEY_dead_O              },
    { Qt::Key_Dead_u             , XKB_KEY_dead_u              },
    { Qt::Key_Dead_U             , XKB_KEY_dead_U              },
    { Qt::Key_Dead_Small_Schwa   , XKB_KEY_dead_small_schwa    },
    { Qt::Key_Dead_Capital_Schwa , XKB_KEY_dead_capital_schwa  },
    { Qt::Key_Dead_Greek         , XKB_KEY_dead_greek          },
    { Qt::Key_Dead_Lowline       , XKB_KEY_dead_lowline        },
    { Qt::Key_Dead_Aboveverticalline, XKB_KEY_dead_aboveverticalline },
    { Qt::Key_Dead_Belowverticalline, XKB_KEY_dead_belowverticalline },
    { Qt::Key_Dead_Longsolidusoverlay, XKB_KEY_dead_longsolidusoverlay },

    //  multimedia/internet keys - ignored by default - see QKeyEvent c'tor
    { Qt::Key_Back , XKB_KEY_XF86Back },
    { Qt::Key_Forward , XKB_KEY_XF86Forward },
    { Qt::Key_Stop , XKB_KEY_XF86Stop },
    { Qt::Key_Refresh , XKB_KEY_XF86Refresh },
    { Qt::Key_VolumeDown, XKB_KEY_XF86AudioLowerVolume },
    { Qt::Key_VolumeMute , XKB_KEY_XF86AudioMute },
    { Qt::Key_VolumeUp, XKB_KEY_XF86AudioRaiseVolume },
    // Key_MicVolumeUp/Down, Bass/Treble keys are unsupported by Xkb
    { Qt::Key_MediaPlay , XKB_KEY_XF86AudioPlay },
    { Qt::Key_MediaStop , XKB_KEY_XF86AudioStop },
    { Qt::Key_MediaPrevious , XKB_KEY_XF86AudioPrev },
    { Qt::Key_MediaNext , XKB_KEY_XF86AudioNext },
    { Qt::Key_MediaRecord, XKB_KEY_XF86AudioRecord },
    { Qt::Key_MediaPause, XKB_KEY_XF86AudioPause },
    { Qt::Key_MediaTogglePlayPause, XKB_KEY_XF86AudioPause },
    { Qt::Key_HomePage , XKB_KEY_XF86HomePage },
    { Qt::Key_Favorites , XKB_KEY_XF86Favorites },
    { Qt::Key_Search , XKB_KEY_XF86Search },
    { Qt::Key_Standby, XKB_KEY_XF86Standby },
    { Qt::Key_OpenUrl, XKB_KEY_XF86OpenURL },
    { Qt::Key_LaunchMail , XKB_KEY_XF86Mail },
    { Qt::Key_LaunchMedia, XKB_KEY_XF86AudioMedia },
    { Qt::Key_Launch0 , XKB_KEY_XF86Launch0 },
    { Qt::Key_Launch1 , XKB_KEY_XF86Launch1 },
    { Qt::Key_Launch2 , XKB_KEY_XF86Launch2 },
    { Qt::Key_Launch3 , XKB_KEY_XF86Launch3 },
    { Qt::Key_Launch4 , XKB_KEY_XF86Launch4 },
    { Qt::Key_Launch5 , XKB_KEY_XF86Launch5 },
    { Qt::Key_Launch6 , XKB_KEY_XF86Launch6 },
    { Qt::Key_Launch7 , XKB_KEY_XF86Launch7 },
    { Qt::Key_Launch8 , XKB_KEY_XF86Launch8 },
    { Qt::Key_Launch9 , XKB_KEY_XF86Launch9 },
    { Qt::Key_LaunchA , XKB_KEY_XF86LaunchA },
    { Qt::Key_LaunchB , XKB_KEY_XF86LaunchB },
    { Qt::Key_LaunchC , XKB_KEY_XF86LaunchC },
    { Qt::Key_LaunchD , XKB_KEY_XF86LaunchD },
    { Qt::Key_LaunchE , XKB_KEY_XF86LaunchE },
    { Qt::Key_LaunchF , XKB_KEY_XF86LaunchF }, // LaunchG & H are unsupported on Xkb
    { Qt::Key_MonBrightnessUp, XKB_KEY_XF86MonBrightnessUp },
    { Qt::Key_MonBrightnessDown, XKB_KEY_XF86MonBrightnessDown },
    { Qt::Key_KeyboardLightOnOff, XKB_KEY_XF86KbdLightOnOff },
    { Qt::Key_KeyboardBrightnessUp, XKB_KEY_XF86KbdBrightnessUp },
    { Qt::Key_KeyboardBrightnessDown, XKB_KEY_XF86KbdBrightnessDown },
    { Qt::Key_PowerOff, XKB_KEY_XF86PowerOff },
    { Qt::Key_WakeUp, XKB_KEY_XF86WakeUp },
    { Qt::Key_Eject, XKB_KEY_XF86Eject },
    { Qt::Key_ScreenSaver, XKB_KEY_XF86ScreenSaver },
    { Qt::Key_WWW, XKB_KEY_XF86WWW },
    { Qt::Key_Memo, XKB_KEY_XF86Memo },
    { Qt::Key_LightBulb, XKB_KEY_XF86LightBulb },
    { Qt::Key_Shop, XKB_KEY_XF86Shop },
    { Qt::Key_History, XKB_KEY_XF86History },
    { Qt::Key_AddFavorite, XKB_KEY_XF86AddFavorite },
    { Qt::Key_HotLinks, XKB_KEY_XF86HotLinks },
    { Qt::Key_BrightnessAdjust, XKB_KEY_XF86BrightnessAdjust },
    { Qt::Key_Finance, XKB_KEY_XF86Finance },
    { Qt::Key_Community, XKB_KEY_XF86Community },
    { Qt::Key_AudioRewind, XKB_KEY_XF86AudioRewind }, // Media rewind
    { Qt::Key_BackForward, XKB_KEY_XF86BackForward },
    { Qt::Key_ApplicationLeft, XKB_KEY_XF86ApplicationLeft },
    { Qt::Key_ApplicationRight, XKB_KEY_XF86ApplicationRight },
    { Qt::Key_Book, XKB_KEY_XF86Book },
    { Qt::Key_CD, XKB_KEY_XF86CD },
    { Qt::Key_Calculator, XKB_KEY_XF86Calculator },
    { Qt::Key_ToDoList, XKB_KEY_XF86ToDoList },
    { Qt::Key_ClearGrab, XKB_KEY_XF86ClearGrab },
    { Qt::Key_Close, XKB_KEY_XF86Close },
    { Qt::Key_Copy, XKB_KEY_XF86Copy },
    { Qt::Key_Cut, XKB_KEY_XF86Cut },
    { Qt::Key_Display, XKB_KEY_XF86Display }, // Output switch key
    { Qt::Key_DOS, XKB_KEY_XF86DOS },
    { Qt::Key_Documents, XKB_KEY_XF86Documents },
    { Qt::Key_Excel, XKB_KEY_XF86Excel },
    { Qt::Key_Explorer, XKB_KEY_XF86Explorer },
    { Qt::Key_Game, XKB_KEY_XF86Game },
    { Qt::Key_Go, XKB_KEY_XF86Go },
    { Qt::Key_iTouch, XKB_KEY_XF86iTouch },
    { Qt::Key_LogOff, XKB_KEY_XF86LogOff },
    { Qt::Key_Market, XKB_KEY_XF86Market },
    { Qt::Key_Meeting, XKB_KEY_XF86Meeting },
    { Qt::Key_MenuKB, XKB_KEY_XF86MenuKB },
    { Qt::Key_MenuPB, XKB_KEY_XF86MenuPB },
    { Qt::Key_MySites, XKB_KEY_XF86MySites },
    { Qt::Key_News, XKB_KEY_XF86News },
    { Qt::Key_OfficeHome, XKB_KEY_XF86OfficeHome },
    { Qt::Key_Option, XKB_KEY_XF86Option },
    { Qt::Key_Paste, XKB_KEY_XF86Paste },
    { Qt::Key_Phone, XKB_KEY_XF86Phone },
    { Qt::Key_Calendar, XKB_KEY_XF86Calendar },
    { Qt::Key_Reply, XKB_KEY_XF86Reply },
    { Qt::Key_Reload, XKB_KEY_XF86Reload },
    { Qt::Key_RotateWindows, XKB_KEY_XF86RotateWindows },
    { Qt::Key_RotationPB, XKB_KEY_XF86RotationPB },
    { Qt::Key_RotationKB, XKB_KEY_XF86RotationKB },
    { Qt::Key_Save, XKB_KEY_XF86Save },
    { Qt::Key_Send, XKB_KEY_XF86Send },
    { Qt::Key_Spell, XKB_KEY_XF86Spell },
    { Qt::Key_SplitScreen, XKB_KEY_XF86SplitScreen },
    { Qt::Key_Support, XKB_KEY_XF86Support },
    { Qt::Key_TaskPane, XKB_KEY_XF86TaskPane },
    { Qt::Key_Terminal, XKB_KEY_XF86Terminal },
    { Qt::Key_Tools, XKB_KEY_XF86Tools },
    { Qt::Key_Travel, XKB_KEY_XF86Travel },
    { Qt::Key_Video, XKB_KEY_XF86Video },
    { Qt::Key_Word, XKB_KEY_XF86Word },
    { Qt::Key_Xfer, XKB_KEY_XF86Xfer },
    { Qt::Key_ZoomIn, XKB_KEY_XF86ZoomIn },
    { Qt::Key_ZoomOut, XKB_KEY_XF86ZoomOut },
    { Qt::Key_Away, XKB_KEY_XF86Away },
    { Qt::Key_Messenger, XKB_KEY_XF86Messenger },
    { Qt::Key_WebCam, XKB_KEY_XF86WebCam },
    { Qt::Key_MailForward, XKB_KEY_XF86MailForward },
    { Qt::Key_Pictures, XKB_KEY_XF86Pictures },
    { Qt::Key_Music, XKB_KEY_XF86Music },
    { Qt::Key_Battery, XKB_KEY_XF86Battery },
    { Qt::Key_Bluetooth, XKB_KEY_XF86Bluetooth },
    { Qt::Key_WLAN, XKB_KEY_XF86WLAN },
    { Qt::Key_UWB, XKB_KEY_XF86UWB },
    { Qt::Key_AudioForward, XKB_KEY_XF86AudioForward }, // Media fast-forward
    { Qt::Key_AudioRepeat, XKB_KEY_XF86AudioRepeat }, // Toggle repeat mode
    { Qt::Key_AudioRandomPlay, XKB_KEY_XF86AudioRandomPlay }, // Toggle shuffle mode
    // MediaLast is unsupported by Xkb
    { Qt::Key_Subtitle, XKB_KEY_XF86Subtitle },
    { Qt::Key_AudioCycleTrack, XKB_KEY_XF86AudioCycleTrack },
    { Qt::Key_Time, XKB_KEY_XF86Time },
    { Qt::Key_Hibernate, XKB_KEY_XF86Hibernate },
    { Qt::Key_View, XKB_KEY_XF86View },
    { Qt::Key_TopMenu, XKB_KEY_XF86TopMenu },
    { Qt::Key_PowerDown, XKB_KEY_XF86PowerDown },
    { Qt::Key_Suspend, XKB_KEY_XF86Suspend },
    { Qt::Key_ContrastAdjust, XKB_KEY_XF86ContrastAdjust },

    { Qt::Key_TouchpadToggle, XKB_KEY_XF86TouchpadToggle },
    { Qt::Key_TouchpadOn, XKB_KEY_XF86TouchpadOn },
    { Qt::Key_TouchpadOff, XKB_KEY_XF86TouchpadOff },

    { Qt::Key_MicMute, XKB_KEY_XF86AudioMicMute },

    { Qt::Key_Red, XKB_KEY_XF86Red },
    { Qt::Key_Green, XKB_KEY_XF86Green },
    { Qt::Key_Yellow, XKB_KEY_XF86Yellow },
    { Qt::Key_Blue, XKB_KEY_XF86Blue },

    { Qt::Key_ChannelUp, XKB_KEY_XF86ChannelUp },
    { Qt::Key_ChannelDown, XKB_KEY_XF86ChannelDown },

    { Qt::Key_Info, XKB_KEY_XF86Info },
    // Guide & Settings are unsupported by Xkb

    { Qt::Key_New, XKB_KEY_XF86New },
    { Qt::Key_Open, XKB_KEY_XF86Open },
    { Qt::Key_Find, XKB_KEY_Find },
    { Qt::Key_Undo, XKB_KEY_Undo },
    { Qt::Key_Redo, XKB_KEY_Redo },

    // Keypad navigation keys
    { Qt::Key_Select, XKB_KEY_XF86Select },
    // Yes and No keys are unsupported by Xkb

    // Newer misc keys
    { Qt::Key_Cancel , XKB_KEY_Cancel },
    { Qt::Key_Exit   , XKB_KEY_Cancel },
    { Qt::Key_Printer, XKB_KEY_Print },
    { Qt::Key_Execute, XKB_KEY_Execute },
    // Sleep, play, and zoom are not supported, falling back to XF86 keys
    { Qt::Key_Sleep  , XKB_KEY_XF86Sleep },
    { Qt::Key_Play   , XKB_KEY_XF86AudioPlay }, // Not the same as Key_MediaPlay
    { Qt::Key_Zoom   , XKB_KEY_XF86ZoomIn },

    // Device keys
    // Context1-4, Flip, ToggleCallHangup, VoiceDial, LastNumberRedial keys are all unsupported by Xkb
    { Qt::Key_Call, XKB_KEY_XF86PickupPhone },      // set absolute state to in a call (do not toggle state)
    { Qt::Key_Hangup, XKB_KEY_XF86HangupPhone },    // set absolute state to hang up (do not toggle state)

    { Qt::Key_Camera, XKB_KEY_XF86CameraFocus },
    { Qt::Key_CameraFocus, XKB_KEY_XF86CameraAccessToggle },

};
