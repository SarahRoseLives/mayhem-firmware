/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "ui.hpp"
#include "ui_chat.hpp"
#include "ui_navigation.hpp"
#include "external_app.hpp"

namespace ui::external_app::chat {
void initialize_app(ui::NavigationView& nav) {
    nav.push<ChatView>();
}
}  // namespace ui::external_app::chat

extern "C" {
__attribute__((section(".external_app.app_chat.application_information"), used))
application_information_t _application_information_chat = {
    /*.memory_location = */ (uint8_t*)0x00000000,
    /*.externalAppEntry = */ ui::external_app::chat::initialize_app,
    /*.header_version = */ CURRENT_HEADER_VERSION,
    /*.app_version = */ VERSION_MD5,
    /*.app_name = */ "Chat",
    /*.bitmap_data = */ {
        0x00,
        0x00,
        0xFE,
        0x7F,
        0xFF,
        0xFF,
        0xBB,
        0xD0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x0B,
        0xE1,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xEB,
        0xD0,
        0xFF,
        0xFF,
        0xFE,
        0x7F,
        0x70,
        0x00,
        0x30,
        0x00,
        0x10,
        0x00,
        0x00,
        0x00,
    },
    /*.icon_color = */ ui::Color::cyan().v,
    /*.menu_location = */ app_location_t::TRX,
    /*.desired_menu_position = */ -1,
    /*.m4_app_tag = */ {0, 0, 0, 0},
    /*.m4_app_offset = */ 0x00000000,
};
}
