#include "controller.hpp"

#include <orbis/Pad.h>
#include <cstdint>

namespace Controller
{
    static int g_padHandle = -1;
    static uint32_t g_previousButtons = 0;

    bool init()
    {
        if (scePadInit() != 0)
            return false;

        g_padHandle = scePadOpen(
            0,      // user
            0,      // type
            0,      // index
            nullptr
        );

        if (g_padHandle < 0)
            return false;

        g_previousButtons = 0;

        return true;
    }

    void shutdown()
    {
        if (g_padHandle >= 0)
        {
            scePadClose(g_padHandle);
            g_padHandle = -1;
        }

        g_previousButtons = 0;
    }

    Button readPressed()
    {
        if (g_padHandle < 0)
            return Button::None;

        OrbisPadData data{};

        if (scePadRead(g_padHandle, &data, 1) != 0)
            return Button::None;

        const uint32_t currentButtons = data.buttons;

        // اكتشاف بداية الضغط فقط.
        const uint32_t pressed =
            currentButtons & ~g_previousButtons;

        g_previousButtons = currentButtons;

        if (pressed & ORBIS_PAD_BUTTON_UP)
            return Button::Up;

        if (pressed & ORBIS_PAD_BUTTON_DOWN)
            return Button::Down;

        if (pressed & ORBIS_PAD_BUTTON_LEFT)
            return Button::Left;

        if (pressed & ORBIS_PAD_BUTTON_RIGHT)
            return Button::Right;

        if (pressed & ORBIS_PAD_BUTTON_CROSS)
            return Button::Cross;

        if (pressed & ORBIS_PAD_BUTTON_CIRCLE)
            return Button::Circle;

        if (pressed & ORBIS_PAD_BUTTON_OPTIONS)
            return Button::Options;

        return Button::None;
    }
}
