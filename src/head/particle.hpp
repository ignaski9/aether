#pragma once
#include <SFML/Graphics.hpp>
#include "engine/engine.hpp"
#include<math.h>

constexpr float PARTICLE_SIZE = 20.0f;
constexpr int PARTICLE_SPEED = 0;
constexpr int PARTICLE_MASS = 20;
constexpr int PARTICLE_AMOUNT = 3;
constexpr sf::Vector2 WINDOW_SIZE = { 1920, 1080 };
static const float gravity = 9.81f;
static const float GRAVITION_CONST = 6.7 * 10;

//= 6.6743* 10e-11f;




/////////////////////////////////////////////////

/////////////////////////////////////////////////


struct Particle {

	Engine engine;

	static const int mass = PARTICLE_MASS;
	sf::Vector2f velocity, acceleration, position, position0;

	sf::CircleShape shape;
	sf::Vector2i posI = engine.vec2fToI(position);
	size_t HashNumber{}; 

	void ParticleInit(sf::Vector2f pos, sf::CircleShape s) {
		velocity = { 0.0f, 0.0f };
		acceleration = { 0.0f, gravity };
		position = pos;
		position0 = pos;
		shape = s;
		posI = engine.vec2fToI(position);
		HashNumber = engine.getHashNumber(posI);
	};
};

struct ParticleSystem {
	static std::vector<Particle> Particles;
	static std::vector< size_t, Particle> HashGrid;

	sf::Vector2f CalculateDistance(Particle p1, Particle p2) {
		float deltaY = p1.position.y - p2.position.y;
		float deltaX = p1.position.x - p2.position.x;

		return{ deltaX, deltaY };
	}
	float CalculateDistanceY(Particle p1, Particle p2) {
		return p1.position.y - p2.position.y;
	}
	float CalculateDistanceX(Particle p1, Particle p2) {
		return p1.position.x - p2.position.x;
	}

	void ApplyForces(float dt) {
		for (auto& particle : Particles) {
			for (int i = 0; i < Particles.size(); i++) {
				

				sf::Vector2f distance = CalculateDistance(particle, Particles[i]);

				if (distance.x == 0 && distance.y == 0) continue;
				float r = sqrt(distance.x * distance.x + distance.y * distance.y);
				float softR = sqrt(r * r + 1.0f);
				float scale = 1 / (softR * softR * softR);
				particle.acceleration += -1 * GRAVITION_CONST * Particles[i].mass * distance * scale;

				
			}
			particle.velocity += particle.acceleration * dt;
			particle.position += particle.velocity * dt;
			particle.shape.setPosition(particle.position);

		}
	};
	void SetPos0() {
		for (auto& particle : Particles) {
			particle.position = particle.position0;
		}

	};
	




};

