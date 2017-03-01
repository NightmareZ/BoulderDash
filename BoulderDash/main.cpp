#include "Engine\gameBase.h"
#include "Game\game.h"
#include <memory>

int main()
{
	HWND console = GetConsoleWindow();
	if (console != NULL)
		ShowWindow(console, SW_HIDE);

	std::auto_ptr<Engine::GameBase> game(new BoulderDash::Game());
	game->run();
}