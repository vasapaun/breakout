#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball : public sf::Drawable {

    public:
        Ball();
        Ball(sf::Vector2f pos, float ang, float spd, float rad, const std::string& texture);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(_sprite);
        }

        sf::Vector2f getPos() { return _position; }
        void setPos(sf::Vector2f pos);

        float getSpeed() { return _speed; }
        void setSpeed(float sp) { _speed = sp; }

        float getAngle() { return _angle; }
        void setAngle(float ang) { _angle= ang; }

        float getRadius() { return _radius; }
        void setRadius(float rad) { _radius= rad; }

    private:
        sf::Vector2f _position;
        float _radius;
        float _speed;
        float _angle;
        sf::Sprite _sprite;
        sf::Texture _texture; // Have to keep it in class because the texture's lifetime needs to be equal to sprite's lifetime
};
