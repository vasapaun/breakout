#include "Game.hpp"

void handleEvent(sf::Event* event, sf::RenderWindow* window);

int main() {
    sf::RenderWindow mainWin = sf::RenderWindow(sf::VideoMode(0,0), "BreakouT", sf::Style::Fullscreen);
    Ball mainBall = Ball(sf::Vector2f(200,200), 0, 0.1f, 80, "../resources/ball.png");

    Renderer rend = Renderer(mainWin, mainBall);
    Game game = Game(mainBall, rend, sf::Vector2f(mainWin.getSize().x, mainWin.getSize().y));

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
    if (event->type == sf::Event::Closed || (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Q))
        window->close();
}
