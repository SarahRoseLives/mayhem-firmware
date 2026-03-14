/*
 * Copyright (C) 2025 Sarah Rose
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"
#include "ui/ui_tabview.hpp"
#include "ui/ui_textentry.hpp"

namespace ui::external_app::chat {

class ChatTabView : public View {
   public:
    explicit ChatTabView(NavigationView& nav);
    void focus() override;

   private:
    void send_message();

    NavigationView& nav_;
    std::string compose_{};

    Console console_log{{0, 0, 240, 208}};
    Text text_compose{{0, 208, 240, 24}, ""};
    Button btn_keyboard{{0, 232, 120, 64}, "Keyboard"};
    Button btn_send{{120, 232, 120, 64}, "Send"};
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

    ChatTabView view_chat{nav_};
    SettingsTabView view_settings{};

    TabView tab_view{
        {"Chat", Theme::getInstance()->fg_light->foreground, &view_chat},
        {"Settings", Theme::getInstance()->fg_light->foreground, &view_settings},
    };
};

}  // namespace ui::external_app::chat
