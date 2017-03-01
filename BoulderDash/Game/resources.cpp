#include "resources.h"
#include <sstream>

namespace BoulderDash
{
	Engine::Texture* Resources::getTexture(std::string path, std::string name)
	{
		std::map<std::string, Engine::Texture*>::iterator it = m_textures.find(name);
		if (it != m_textures.end())
			return it->second;

		std::string fileName("Gfx\\");
		if (path.length() > 0)
		{
			fileName += path;
			fileName += "\\";
		}
		fileName += name;
		fileName += ".png";
		Engine::Texture* tex = Engine::Texture::load(fileName.c_str());
		m_textures[name] = tex;
		return tex;
	}

	Engine::Animation* Resources::getAnimation(std::string path, std::string name, int framesCount)
	{
		std::string id = path + name;
		std::map<std::string, Engine::Animation*>::iterator it = m_animations.find(id);
		if (it != m_animations.end())
			return it->second;

		std::string filePath("Gfx\\");
		if (path.length() > 0)
		{
			filePath += path;
			filePath += "\\";
		}
		filePath += name;
		filePath += "\\";
		std::vector<Engine::Texture*> textures(framesCount);
	
		for (int i = 0; i < framesCount; ++i)
		{
			std::string fileName = filePath;
			std::stringstream ss;
			ss << "frame" << i << ".png";
			fileName += ss.str();
			Engine::Texture* texture = Engine::Texture::load(fileName.c_str());
			textures[i] = texture;
		}

		Engine::Animation* animation = new Engine::Animation(textures, 15);
		m_animations[id] = animation;
		return animation;
	}

	Resources::~Resources()
	{
		for (std::map<std::string, Engine::Texture*>::iterator it = m_textures.begin(); it != m_textures.end(); ++it)
			delete it->second;

		for (std::map<std::string, Engine::Animation*>::iterator it = m_animations.begin(); it != m_animations.end(); ++it)
			delete it->second;
	}
}