#include "Game.h"

using namespace std;

const int FPS = 60;
const int DELAY_TIME = (int) (1000.0f / FPS);

int main(int argc, char* args[])
{

	Uint32 frameStart, frameTime;

	cout << "game init attempt..." << endl;

	if (TheGame::Instance()->init("Janela maneira", 100, 100, 640, 480)) {

		while (TheGame::Instance()->isRunning()) {

			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME) {
				SDL_Delay((int) (DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		cout << "game init failure - " << SDL_GetError() << endl;
		return -1;
	}

	cout << "game closing..." << endl;

	TheGame::Instance()->clean();

	return 0;
}