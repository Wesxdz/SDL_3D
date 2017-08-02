#include "Game.h"
#include "Example.h"

int main(int argc, char** argv)
{
	Game::Init("OpenGL Test", 640, 320);
	Game::Run(new Example);
	return 0;
}