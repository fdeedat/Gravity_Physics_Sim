#pragma once
#include "particle.h"

//gravity source functions
gravitySource::gravitySource(float posX,float posY,float mass){
    gravPos.x = posX;
    gravPos.y = posY;
    this->mass = mass;

    sourceShape.setRadius(10);
    sourceShape.setPosition(gravPos);

    sourceShape.setFillColor(sf::Color::Yellow);
    sourceShape.setOutlineThickness(1.0f);
    sourceShape.setOutlineColor(sf::Color::White);
}

void gravitySource:: render(sf::RenderWindow &window){
    window.draw(sourceShape);
}

sf::Vector2f gravitySource:: getPos(){
    return gravPos;
}

float gravitySource:: getMass(){
    return mass;
}