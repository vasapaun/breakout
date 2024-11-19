#include "Game.hpp"
#include <random>

void handleEvent(sf::Event* event, sf::RenderWindow* window);

int main() {
    sf::Vector2f startPos = sf::Vector2f(200,200);

    std::mt19937 gen(std::random_device{}());
    float startAngle = std::uniform_real_distribution<float>(0.0f, 2.0f * M_PI)(gen);

    sf::RenderWindow mainWin = sf::RenderWindow(sf::VideoMode(0,0), "BreakouT", sf::Style::Fullscreen);
    sf::Vector2f mainWinSize = sf::Vector2f(mainWin.getSize().x, mainWin.getSize().y);
    Ball mainBall = Ball(startPos, startAngle, 0.1f, 20, "../resources/ball.png");

    Renderer rend = Renderer(mainWin, mainBall);
    Game game = Game(mainBall, rend, mainWinSize);

    while(mainWin.isOpen())
    {
        sf::Event event;
        while(mainWin.pollEvent(event))
        {
            handleEvent(&event, &mainWin);
        }

        game.updateBall();
        rend.drawAll();
    }

    return 0;
}


void handleEvent(sf::Event* event, sf::RenderWindow* window)
{
    if (event->type == sf::Event::Closed
    || (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Q))
        window->close();
}
