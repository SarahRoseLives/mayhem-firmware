/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "ui_chat.hpp"

namespace ui::external_app::chat {

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
