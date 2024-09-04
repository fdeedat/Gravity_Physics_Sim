#pragma once
#include "particle.h"

// particle functions

particle::particle(float posX, float posY, float velX, float velY, const sf::Color &color){
    pos.x = posX;
    pos.y = posY;

    vel.x = velX;
    vel.y = velY;

    this->color = color;

    particleShape.setRadius(5);
    particleShape.setPosition(pos);

    particleShape.setFillColor(color);
    particleShape.setOutlineThickness(1.0f);
}

void particle:: render(sf::RenderWindow &window){

    particleShape.setPosition(pos);
    window.draw(particleShape);
}

sf::Vector2f particle::getPosition(){
    return pos;
}

sf::Vector2f particle::getVelocity(){
    return vel;
}

void particle::update(gravitySource &s){
    float distanceX = s.getPos().x - pos.x;
    float distanceY = s.getPos().y - pos.y;

    float distance = sqrt(distanceX*distanceX + distanceY*distanceY);
    
    float iDistance = 1.0f/distance;
    
    float normX = iDistance*distanceX;
    float normY = iDistance*distanceY;

    float ax,ay;

    if(distance <=5){ // not physically realistic but idc
        ax = 0;
        ay = 0;
        vel.x = -vel.x;
        vel.y = -vel.y;
    }else{
        ax = normX * G * s.getMass() * iDistance* iDistance;
        ay = normY * G * s.getMass() * iDistance* iDistance;
        vel.x += ax;
        vel.y += ay;
    }

    pos.x += vel.x;
    pos.y += vel.y;
}