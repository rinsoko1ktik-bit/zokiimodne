#pragma once

namespace Controller
{
    enum class Button
    {
        None,
        Up,
        Down,
        Left,
        Right,
        Cross,
        Circle,
        Options
    };

    bool init();
    void shutdown();

    // ترجع الزر مرة واحدة عند بداية الضغط فقط.
    Button readPressed();
}
