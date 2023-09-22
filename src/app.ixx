module;

#include <compare>
#include <string>
#include <entt.hpp>

export module app;

import lime.Game;

export int app_main() {
    lime::Game game = {};
    game.run();

    return 0;
}
