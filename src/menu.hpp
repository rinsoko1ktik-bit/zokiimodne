#pragma once

#include <cstddef>

class Menu
{
public:

    Menu(
        const char* const* items,
        std::size_t count
    );

    void up();
    void down();

    int selected() const;

    void draw(const char* title) const;

private:

    const char* const* items_;
    std::size_t count_;
    std::size_t selected_;
};
