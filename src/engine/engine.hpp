#pragma once
#include <SFML/Graphics.hpp>
#include "head/particle.hpp"




class Engine {
public:

sf::Vector2i vec2fToI(sf::Vector2f vec2f){
    int x = static_cast<int>(vec2f.x);
    int y = static_cast<int>(vec2f.y);

    return sf::Vector2i{x, y};
}

size_t getHashNumber(sf::Vector2i pos2i) { //chatgpt padare as ne toks chefas
    const int p1 = 73856093;
    const int p2 = 19349663;

    return static_cast<size_t>(pos2i.x * p1 ^ pos2i.y * p2);
}




void HashGrid(ParticleSystem& particleSystem)
{
        particleSystem.HashGrid.clear();

for( auto& p : particleSystem.Particles)
{

    sf::Vector2i posI = vec2fToI(p.position);
     p.HashNumber = getHashNumber(posI);
     particleSystem.HashGrid[p.HashNumber].push_back(&p);

}
}




};

