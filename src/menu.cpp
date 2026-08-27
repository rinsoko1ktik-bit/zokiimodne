#include "menu.hpp"

#include <cstdio>

Menu::Menu(
    const char* const* items,
    std::size_t count
)
    : items_(items),
      count_(count),
      selected_(0)
{
}

void Menu::up()
{
    if (count_ == 0)
        return;

    if (selected_ == 0)
        selected_ = count_ - 1;
    else
        --selected_;
}

void Menu::down()
{
    if (count_ == 0)
        return;

    ++selected_;

    if (selected_ >= count_)
        selected_ = 0;
}

int Menu::selected() const
{
    return static_cast<int>(selected_);
}

void Menu::draw(const char* title) const
{
    std::printf("\n");
    std::printf("==============================\n");
    std::printf("        %s\n", title);
    std::printf("==============================\n");

    for (std::size_t i = 0; i < count_; ++i)
    {
        if (i == selected_)
            std::printf("> %s\n", items_[i]);
        else
            std::printf("  %s\n", items_[i]);
    }

    std::printf("==============================\n");
    std::printf("D-Pad: Move | X: Select | O: Back\n");
}
