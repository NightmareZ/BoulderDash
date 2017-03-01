#include "game.h"
#include "Screens\menuscreen.h"

namespace BoulderDash
{
	void Game::load()
	{
		m_screen = new Screens::MenuScreen(&m_resources);
	}

	void Game::unload()
	{
		if (m_screen)
			delete m_screen;
	}

	void Game::update(int timeSpan)
	{
		if (m_screen)
		{
			MouseState mouseState(getMouseLeftButton(), getMouseRightButton(), getMouseX(), getMouseY());
			Screen* nextScreen = m_screen->update(timeSpan, kbdState, mouseState);

			if (nextScreen)
			{
				delete m_screen;
				m_screen = nextScreen;
			}
		}
	}

	void Game::draw(int timeSpan)
	{
		if (m_screen)
			m_screen->draw(timeSpan, getWidth(), getHeight());
	}
}