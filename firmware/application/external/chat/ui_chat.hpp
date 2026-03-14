/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"
#include "ui/ui_tabview.hpp"

namespace ui::external_app::chat {

class ChatTabView : public View {
   public:
    ChatTabView() {
        add_children({&text_placeholder});
    }
    void focus() override { text_placeholder.focus(); }

   private:
    Text text_placeholder{
        {UI_POS_X(0), UI_POS_Y(0), UI_POS_MAXWIDTH, UI_POS_DEFAULT_HEIGHT},
        "Chat coming soon..."};
};

class SettingsTabView : public View {
   public:
    SettingsTabView() {
        add_children({&text_placeholder});
    }
    void focus() override { text_placeholder.focus(); }

   private:
    Text text_placeholder{
        {UI_POS_X(0), UI_POS_Y(0), UI_POS_MAXWIDTH, UI_POS_DEFAULT_HEIGHT},
        "Settings coming soon..."};
};

class ChatView : public View {
   public:
    explicit ChatView(NavigationView& nav);
    void focus() override;
    std::string title() const override { return "Chat"; }

   private:
    NavigationView& nav_;

    ChatTabView view_chat{};
    SettingsTabView view_settings{};

    TabView tab_view{
        {"Chat", Theme::getInstance()->fg_light->foreground, &view_chat},
        {"Settings", Theme::getInstance()->fg_light->foreground, &view_settings},
    };
};

}  // namespace ui::external_app::chat
