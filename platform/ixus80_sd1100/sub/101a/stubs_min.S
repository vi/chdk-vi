#include "stubs_asm.h"

DEF(physw_status, 0x10370)
DEF(physw_run, 0x1c00) // 0x1bf4 + 0xc // 0x1bf4 + 12 found @ 0xff821b94

DEF(FlashParamsTable, 0xffaee050) // it seems

DEF(zoom_busy, 0x85f0)  // 0x85dc + 0x14
DEF(focus_busy, 0x8578)

DEF(canon_menu_active, 0x94e8) // 0x94e4 + 4
DEF(canon_shoot_menu_active, 0x9e2d)   // 0x9e2c + 1

DEF(recreview_hold, 0x9c0c) // 0x9b60 + 0xac

DEF(zoom_status, 0xd1cc)
DEF(movie_status, 0x53b4) // 0x5368 + 0x4c

// ??
// DEF(some_flag_for_af_scan, )
DEF(levent_table,0xFFACAC68)
DEF(playrec_mode,0x5534) // 0x5530+4 "MenuIn"
