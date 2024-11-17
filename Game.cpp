#include "Game.hpp"

Game::Game(Ball& ball, Renderer& rend, sf::Vector2f bounds)
    : _ball(ball), _rend(rend), _bounds(bounds) {}

void Game::updateBall()
{
    sf::Vector2f currPos = _ball.getPos();
    float speed = _ball.getSpeed();
    float currAngle = _ball.getAngle();

    sf::Vector2f newPos = currPos + sf::Vector2f(speed * std::cos(currAngle), -speed * std::sin(currAngle));

    // TODO: Finish collision logic
    if(newPos.x + _ball.getRadius() > _bounds.x || newPos.x - _ball.getRadius() < _bounds.x)
    {

    }

    if(newPos.y + _ball.getRadius() > _bounds.y || newPos.y - _ball.getRadius() < _bounds.y)
    {

    }

    _ball.setPos(newPos);
}
