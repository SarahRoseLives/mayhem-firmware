/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "ui_chat.hpp"

namespace ui::external_app::chat {

ChatTabView::ChatTabView(NavigationView& nav)
    : nav_{nav} {
    add_children({&console_log, &text_compose, &btn_keyboard, &btn_send});

    btn_keyboard.on_select = [this](Button&) {
        text_prompt(nav_, compose_, 128, ENTER_KEYBOARD_MODE_ALPHA, [this](std::string&) {
            text_compose.set(compose_);
        });
    };

    btn_send.on_select = [this](Button&) {
        send_message();
    };
}

void ChatTabView::focus() {
    btn_keyboard.focus();
}

void ChatTabView::send_message() {
    if (compose_.empty()) return;
    console_log.writeln("> " + compose_);
    compose_.clear();
    text_compose.set("");
}

ChatView::ChatView(NavigationView& nav)
    : nav_{nav} {
    const Rect view_rect = {0, 3 * 8, screen_width, screen_height - 3 * 8};
    view_chat.set_parent_rect(view_rect);
    view_settings.set_parent_rect(view_rect);

    add_children({&tab_view, &view_chat, &view_settings});
}

void ChatView::focus() {
    tab_view.focus();
}

}  // namespace ui::external_app::chat
