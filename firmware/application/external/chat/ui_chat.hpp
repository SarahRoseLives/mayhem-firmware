/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"

namespace ui::external_app::chat {

class ChatView : public View {
   public:
    explicit ChatView(NavigationView& nav);
    void focus() override;
    std::string title() const override { return "Chat"; }

   private:
    NavigationView& nav_;

    Text text_placeholder{
        {UI_POS_X(0), UI_POS_Y(0), UI_POS_MAXWIDTH, UI_POS_DEFAULT_HEIGHT},
        "Chat UI coming soon..."};
};

}  // namespace ui::external_app::chat
