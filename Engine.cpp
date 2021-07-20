#include "pch.h"
#include "Engine.h"

namespace FO3D
{
	Engine::Engine() : run(true), window(NULL), videoWidth(SCREEN_WIDTH), videoHeight(SCREEN_HEIGHT)
	{
		glfwInit();
	}
}