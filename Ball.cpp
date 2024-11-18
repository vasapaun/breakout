#include "Ball.hpp"

Ball::Ball()
{
    _position = sf::Vector2f(0,0);
    _angle = -(std::numbers::pi / 3);
    _speed = 0.1;

    if(!_texture.loadFromFile("../resources/ball.png"))
        throw std::invalid_argument("Texture unable to load");
    _texture.setRepeated(false);
    _sprite.setTexture(_texture);
}

Ball::Ball(sf::Vector2f pos, float ang, float spd, float rad, const std::string& texture)
    : _position(pos), _angle(ang), _speed(spd), _radius(rad)
{
    if(!_texture.loadFromFile(texture))
        throw std::invalid_argument("Texture unable to load");
    _texture.setRepeated(false);

    _sprite.setOrigin(_radius, _radius);

    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
    float scale = rad * 2.0f / _texture.getSize().x;
    _sprite.setScale(sf::Vector2f(scale, scale));
}

void Ball::setPos(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
    _position = pos;
}
