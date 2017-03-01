#ifndef ANIMATION_H
#define ANIMATION_H

#include "gameBase.h"
#include "textureBase.h"
#include "texture.h"
#include <vector>

namespace Engine
{
	class Animation: public TextureBase
	{
	private:
		std::vector<Texture*> m_textures;
		int m_frameTime;
		int m_timeSpan;
		int m_frame;
	public:
		Animation(std::vector<Texture*> textures, int framesPerSecond)
			: m_textures(textures.begin(), textures.end()), m_frameTime(1000 / framesPerSecond), m_timeSpan(0), m_frame(0)
		{ }

		~Animation();
		void update(int timeSpan);
		void reset();
		Texture* current() const { return getFrame(m_frame); }
		Texture* getFrame(int n) const { return m_textures[n]; }
		virtual void enable() { current()->enable(); }
		virtual Point<float> getTextureCoords() { return current()->getTextureCoords(); }
	};
}

#endif