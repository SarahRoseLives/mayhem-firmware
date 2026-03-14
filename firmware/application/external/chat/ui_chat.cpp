/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "ui_chat.hpp"

namespace ui::external_app::chat {

ChatView::ChatView(NavigationView& nav)
    : nav_{nav} {
    add_children({&text_placeholder});
}

void ChatView::focus() {
    text_placeholder.focus();
}

}  // namespace ui::external_app::chat
