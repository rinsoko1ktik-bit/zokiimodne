#include "menu.hpp"
#include "controller.hpp"

#include <cstdio>

static const char* mainItems[] = {
    "Player",
    "Vehicle",
    "Weapons",
    "World",
    "Teleport",
    "Scripts",
    "Settings",
    "Exit"
};

static const char* scriptItems[] = {
    "Script 1",
    "Script 2",
    "Script 3",
    "Script 4",
    "Back"
};

int main()
{
    Menu mainMenu(
        mainItems,
        sizeof(mainItems) / sizeof(mainItems[0])
    );

    Menu scriptsMenu(
        scriptItems,
        sizeof(scriptItems) / sizeof(scriptItems[0])
    );

    if (!Controller::init())
    {
        std::printf("Controller initialization failed.\n");
        return 1;
    }

    bool running = true;
    bool inScripts = false;

    while (running)
    {
        if (inScripts)
            scriptsMenu.draw("ZOKII MENU > SCRIPTS");
        else
            mainMenu.draw("ZOKII MENU");

        const Controller::Button button =
            Controller::readPressed();

        switch (button)
        {
            case Controller::Button::Up:
                if (inScripts)
                    scriptsMenu.up();
                else
                    mainMenu.up();
                break;

            case Controller::Button::Down:
                if (inScripts)
                    scriptsMenu.down();
                else
                    mainMenu.down();
                break;

            case Controller::Button::Cross:

                if (inScripts)
                {
                    if (scriptsMenu.selected() == 4)
                    {
                        inScripts = false;
                    }
                    else
                    {
                        std::printf(
                            "Script %d selected.\n",
                            scriptsMenu.selected() + 1
                        );
                    }
                }
                else
                {
                    if (mainMenu.selected() == 5)
                    {
                        inScripts = true;
                    }
                    else if (mainMenu.selected() == 7)
                    {
                        running = false;
                    }
                    else
                    {
                        std::printf(
                            "Menu item %d selected.\n",
                            mainMenu.selected()
                        );
                    }
                }

                break;

            case Controller::Button::Circle:

                if (inScripts)
                    inScripts = false;
                else
                    running = false;

                break;

            case Controller::Button::Options:
                running = false;
                break;

            default:
                break;
        }
    }

    Controller::shutdown();

    return 0;
}
