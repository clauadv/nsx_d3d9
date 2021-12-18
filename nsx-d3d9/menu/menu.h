#pragma once
#include "../includes.h"

namespace widgets {
	inline std::shared_ptr<FGUI::CContainer> container;
    inline std::shared_ptr<FGUI::CTabPanel> tabs;
    inline std::shared_ptr<FGUI::CContainer> groupbox;
    inline std::shared_ptr<FGUI::CComboBox> combobox;
    inline std::shared_ptr<FGUI::CCheckBox> checkbox;
    inline std::shared_ptr<FGUI::CColorPicker> color_picker;
    inline std::shared_ptr<FGUI::CContainer> groupbox_2;
    inline std::shared_ptr<FGUI::CCheckBox> checkbox_2;
    inline std::shared_ptr<FGUI::CSlider> slider;
}

namespace menu {
	inline void initialize() {
		static FGUI::CBuilder builder;

		const FGUI::SWidgetFont_t font = { "Verdana", 12, false, 0 };

        widgets::container = std::make_shared<FGUI::CContainer>();
        builder.Widget(widgets::container).Title("container").Position(200, 200).Flag(FGUI::WIDGET_FLAG::LIMIT).Size(735, 435).Key(VK_INSERT).Font(font);
        {
            widgets::tabs = std::make_shared<FGUI::CTabPanel>();
            builder.Widget(widgets::tabs).Position(0, 16).Font(font).Tabs({ "tab 1", "tab 2" }).SpawnIn(widgets::container, false);
            {
                widgets::groupbox = std::make_shared<FGUI::CContainer>();
                builder.Widget(widgets::groupbox).Title("groupbox 1").Position(15, 65).Size(290, 165).Font(font).Medium(widgets::tabs, 0).SpawnIn(widgets::container, false);
                {
                    widgets::checkbox = std::make_shared<FGUI::CCheckBox>();
                    builder.Widget(widgets::checkbox).Title("checkbox 1").Position(15, 15).Font(font).SpawnIn(widgets::groupbox);

                    widgets::color_picker = std::make_shared<FGUI::CColorPicker>();
                    builder.Widget(widgets::color_picker).Title("color picker").Position(255, 15).Color({ 255, 11, 124 }).SpawnIn(widgets::groupbox);

                    widgets::combobox = std::make_shared<FGUI::CComboBox>();
                    builder.Widget(widgets::combobox).Title("combobox").Position(15, (15 + 25)).Entries({ "Entry 1", "Entry 2", "Entry 3", "Entry 4", "Entry 5", "Entry 6", "Entry 7", "Entry 8", "Entry 9", "Entry 10", "Entry 11", "Entry 12", "Entry 13", "Entry 14", "Entry 15" }).Font(font).SpawnIn(widgets::groupbox);
                }

                widgets::groupbox_2 = std::make_shared<FGUI::CContainer>();
                builder.Widget(widgets::groupbox_2).Title("groupbox 2").Position(315, 65).Size(290, 165).Font(font).Medium(widgets::tabs, 0).SpawnIn(widgets::container, false);
                {
                    widgets::slider = std::make_shared<FGUI::CSlider>();
                    builder.Widget(widgets::slider).Title("slider").Range(1, 100).Value(80).Position(15, 25).Font(font).Medium(widgets::tabs, 0).SpawnIn(widgets::groupbox_2, false);
                }
            }
        }
	}

	inline void render() {
        widgets::container->Render();
	}
}