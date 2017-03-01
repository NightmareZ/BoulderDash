#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include "point.h"

namespace Engine
{
	class TextureBase
	{
	public:
		virtual void enable() = 0;
		virtual Point<float> getTextureCoords() = 0;
	};
}

#endif