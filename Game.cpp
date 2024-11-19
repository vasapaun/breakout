#include "Game.hpp"

Game::Game(Ball& ball, Renderer& rend, sf::Vector2f bounds)
    : _ball(ball), _rend(rend), _bounds(bounds) {}

void Game::updateBall()
{
    sf::Vector2f currPos = _ball.getPos();
    float speed = _ball.getSpeed();
    float currAngle = _ball.getAngle();

    sf::Vector2f newPos = currPos + sf::Vector2f(speed * std::cos(currAngle), -speed * std::sin(currAngle));

    if(((newPos.x + _ball.getRadius()) > _bounds.x) || ((newPos.x - _ball.getRadius()) < 0))
    {
        // Put it back in the box as if it bounced off the wall in between ticks
        newPos.x = std::fmod(newPos.x - _bounds.x, _bounds.x);
        if (newPos.x < 0)   newPos.x += _bounds.x;

        _ball.setAngle(std::numbers::pi - currAngle);
    }

    if(((newPos.y + _ball.getRadius()) > _bounds.y) || ((newPos.y - _ball.getRadius()) < 0))
    {  
        // Put it back in the box as if it bounced off the wall in between ticks
        newPos.y = std::fmod(newPos.y, _bounds.y);
        if (newPos.y < 0) newPos.y += _bounds.y;

        _ball.setAngle(-currAngle);
    }

    _ball.setPos(newPos);
}
