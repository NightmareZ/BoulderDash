#ifndef RESOURCES_H
#define RESOURCES_H

#include "..\Engine\gameBase.h"
#include "..\Engine\texture.h"
#include "..\Engine\animation.h"

#include <map>
#include <string>

namespace BoulderDash
{
	class Resources
	{
	private:
		std::map<std::string, Engine::Texture*> m_textures;
		std::map<std::string, Engine::Animation*> m_animations;
	public:
		~Resources();
	
		Engine::Texture* getTexture(std::string path, std::string name);
		Engine::Texture* getTexture(std::string name) { return getTexture(std::string(), name); }

		Engine::Animation* getAnimation(std::string path, std::string name, int framesCount);
		Engine::Animation* getAnimation(std::string name, int framesCount) { return getAnimation(std::string(), name, framesCount); }
	};
}

#endif