#ifndef __PARTICLE_POOL_H__
#define __PARTICLE_POOL_H__

#include "Particle.h"
#include "Emitter.h"
#include "ctPoint.h"
#include <vector>

struct SDL_Texture;
class Emitter;

class ParticlePool
{
private:

	int poolSize = 0;
	Particle* firstAvailable;
	// TODO 2.1: Declare an static array of 100 particles
	// Particle particleArray[100];
	Particle* particleArray = nullptr;

public:

	ParticlePool(Emitter* emitter);
	virtual ~ParticlePool();

	//Generates a new particle each time it's called
	void Generate(fPoint pos, float startSpeed, float endSpeed, float angle, float rotSpeed, float startSize, float endSize, uint life, SDL_Rect textureRect, SDL_Color startColor, SDL_Color endColor, SDL_BlendMode blendMode);

	// Update (move and draw) particles in the pool. If there are no particles alive returns false
	bool Update(float dt);
	bool PostUpdate();
};

#endif
