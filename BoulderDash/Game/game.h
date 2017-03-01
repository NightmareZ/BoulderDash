#ifndef GAME_H
#define GAME_H

#include "..\Engine\gameBase.h"
#include "..\Engine\texture.h"
#include "..\Engine\animation.h"
#include "resources.h"
#include "screen.h"
#include "Screens\levelscreen.h"

namespace BoulderDash
{
	class Game: public Engine::GameBase
	{
	private:
		Resources m_resources;
		Screen* m_screen;
	public:
		Game() : GameBase("BoulderDash") { }

		virtual void load();
		virtual void unload();

		virtual void update(int timeSpan);
		virtual void draw(int timeSpan);
	};
}

#endif