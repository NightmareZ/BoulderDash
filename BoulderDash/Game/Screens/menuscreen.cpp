#include "menuscreen.h"
#include "levelscreen.h"
#include "..\level.h"
#include "..\..\Engine\texture.h"
#include "..\..\Engine\sprite.h"

namespace BoulderDash
{
	namespace Screens
	{
		Screen* MenuScreen::update(int timeSpan, std::list<int> kbdEvents, MouseState mouseState)
		{
			if (m_needNew)
				return new LevelScreen(getResources(), 1);
			else if (m_needLoad)
			{
				return LevelScreen::load(getResources(), "save.txt");
			}

			m_mouseState = mouseState;
			return 0;
		}

		void MenuScreen::draw(int timeSpan, int width, int height)
		{
			int optimalRectSize = std::min<int>(
				width / Level::minCellsOnScreen,
				height / Level::minCellsOnScreen);

			Engine::Texture* bgTexture = getResources()->getTexture("box");
			for (int j = 0; j < height; j += optimalRectSize)
				for (int i = 0; i < width; i += optimalRectSize)
				{
					Engine::Sprite bgSprite(bgTexture);
					bgSprite.draw(
						static_cast<float>(i), static_cast<float>(j),
						static_cast<float>(optimalRectSize), static_cast<float>(optimalRectSize));
				}

			const float dist = height / 30.f;
			Engine::Texture* titleTexture = getResources()->getTexture("title");
			float titleWidth = width / 2.f;
			float titleHeight = titleWidth / titleTexture->getSourceWidth() * titleTexture->getSourceHeight();
			float titleX = (width - titleWidth) / 2.f;
			float titleY = height - titleHeight * 3;
			Engine::Sprite titleSprite(titleTexture);
			titleSprite.draw(titleX, titleY, titleWidth, titleHeight);

			float scaleFactor = titleWidth / titleTexture->getSourceWidth();
			float newGameSpriteWidth = dynamic_cast<Engine::Texture*>(m_newGameSprite->getTexture())->getSourceWidth() * scaleFactor;
			float newGameSpriteHeight = dynamic_cast<Engine::Texture*>(m_newGameSprite->getTexture())->getSourceHeight() * scaleFactor;
			float offsetY = titleHeight * 0.5;
			float newGameSpriteX = (width - newGameSpriteWidth) / 2.f;
			float newGameSpriteY = titleY - offsetY * 4;

			bool newGameSpriteActive =
				m_mouseState.x() >= newGameSpriteX &&
				m_mouseState.x() <= newGameSpriteX + newGameSpriteWidth &&
				height - m_mouseState.y() >= newGameSpriteY &&
				height - m_mouseState.y() <= newGameSpriteY + newGameSpriteHeight;

			if (newGameSpriteActive && m_mouseState.leftButton())
				m_needNew = true;

			(newGameSpriteActive ? m_newGameSpriteActive : m_newGameSprite)->draw(
				newGameSpriteX,
				newGameSpriteY,
				newGameSpriteWidth,
				newGameSpriteHeight);

			float loadSpriteWidth = dynamic_cast<Engine::Texture*>(m_loadSprite->getTexture())->getSourceWidth() * scaleFactor;
			float loadSpriteHeight = dynamic_cast<Engine::Texture*>(m_loadSprite->getTexture())->getSourceHeight() * scaleFactor;
			float loadSpriteX = (width - loadSpriteWidth) / 2.f;
			float loadSpriteY = newGameSpriteY - loadSpriteHeight - offsetY;

			bool loadSpriteActive =
				m_mouseState.x() >= loadSpriteX &&
				m_mouseState.x() <= loadSpriteX + loadSpriteWidth &&
				height - m_mouseState.y() >= loadSpriteY &&
				height - m_mouseState.y() <= loadSpriteY + loadSpriteHeight;

			if (loadSpriteActive && m_mouseState.leftButton())
				m_needLoad = true;

			(loadSpriteActive ? m_loadSpriteActive : m_loadSprite)->draw(
				loadSpriteX,
				loadSpriteY,
				loadSpriteWidth,
				loadSpriteHeight);
		}
	}
}