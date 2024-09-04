#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#define G 1

class gravitySource{
    public:

    sf::Vector2f gravPos;
    sf::CircleShape sourceShape;
    float mass;

    gravitySource(float posX,float posY,float mass);
    void render(sf::RenderWindow &window);
    sf::Vector2f getPos();
    float getMass();
};

#include "gravitySource.cpp"

class particle{
    public:

    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape particleShape;
    sf::Color color;

    particle(float posX, float posY, float velX, float velY, const sf::Color &color);
    void render(sf::RenderWindow &window);
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    void update(gravitySource &s);
};

#include "particle.cpp"