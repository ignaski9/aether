#include <SFML/Graphics.hpp>
#include "head/particle.hpp"

std::vector<Particle> ParticleSystem::Particles;


int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_SIZE.x, WINDOW_SIZE.y}), "SFML works!", sf::State::Fullscreen);
    window.setFramerateLimit(240);


    sf::CircleShape default_shape(PARTICLE_SIZE);
    default_shape.setFillColor(sf::Color::Red);

    ParticleSystem system;
    for (int i = 0; i < PARTICLE_AMOUNT; i++) {
        Particle particle;
        sf::Vector2f pos = { 100.0f + i * 200.0f, 100.0f + 50.0f*(i%2)};
        particle.ParticleInit(pos, default_shape);


        system.Particles.push_back(particle);
    }




    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            
            if (const auto* keyboardButtonPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyboardButtonPressed->scancode == sf::Keyboard::Scan::Escape)
                    window.close();


            }


            if(const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    system.SetPos0();
                }
                else  if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    Particle particle;
                    sf::Vector2i p = sf::Mouse::getPosition(window);
                    sf::Vector2f pos = { p.x * 1.0f, p.y * 1.0f };
                    particle.ParticleInit(pos, default_shape);

                    system.Particles.push_back(particle);
                }
            }
    
        }
       
       

        constexpr float dt = 0.001;
        system.ApplyForces(dt);

        window.clear();
        for (auto& particle : system.Particles) {
            window.draw(particle.shape);
        }
        window.display();
    }
}
