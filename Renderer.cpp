#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& win, Ball& ball)
    : _window(win), _ball(ball) {}

void Renderer::drawAll()
{
    _window.clear();

    _window.draw(_ball);

    _window.display();
}
