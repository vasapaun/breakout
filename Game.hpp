#pragma once

#include "Renderer.hpp"
#include <cmath>

class Game
{
    public:
        Game();
        Game(Ball&, Renderer&, sf::Vector2f bounds);
        void updateBall();

    private:
        Ball& _ball;
        Renderer& _rend;
        sf::Vector2f _bounds;
};
