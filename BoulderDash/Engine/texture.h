#ifndef TEXTURE_H
#define TEXTURE_H

#include "gameBase.h"
#include "..\FreeImage\FreeImage.h"
#include "textureBase.h"

#pragma comment (lib, "FreeImage.lib")

namespace Engine
{
	class Texture: public TextureBase
	{
	private:
		static int m_texturesCounter;

		static Texture* m_active;
		GLuint n;
		Texture();

		unsigned int  m_size;
		unsigned int  m_sourceWidth, m_sourceHeight;
	public:
		~Texture();
		static Texture* load(const char* filename);
		virtual void enable();
		virtual Point<float> getTextureCoords();
		unsigned int getWidth() const { return m_size; }
		unsigned int getHeight() const { return m_size; }
		unsigned int getSourceWidth() const { return m_sourceWidth; }
		unsigned int getSourceHeight() const { return m_sourceHeight; }
	};
}

#endif