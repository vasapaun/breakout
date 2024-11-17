#pragma once

#include "Ball.hpp"

class Renderer {

    public:
        Renderer(sf::RenderWindow& win, Ball& ball);

        void drawAll();

    private:
        sf::RenderWindow& _window;
        Ball& _ball;
};
