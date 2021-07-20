#include "pch.h"
#include "Engine.h"

namespace FO3D
{
	Engine::Engine() : run(true), window(NULL), videoWidth(SCREEN_WIDTH), videoHeight(SCREEN_HEIGHT)
	{
		glfwInit();
		//WINDOW HINTS
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		auto& monitor = *glfwGetVideoMode(glfwGetPrimaryMonitor());

		// BIT COLOURING
		glfwWindowHint(GLFW_RED_BITS, monitor.redBits);
		glfwWindowHint(GLFW_BLUE_BITS, monitor.blueBits);
		glfwWindowHint(GLFW_GREEN_BITS, monitor.greenBits);
		glfwWindowHint(GLFW_REFRESH_RATE, monitor.refreshRate);


		// CREATE WINDOW
		window = glfwCreateWindow(videoWidth, videoHeight, "FO3D", NULL, NULL);
		assert(window && "ERROR::GFLW::FAILED TO CREATE WINDOW");
		glfwMakeContextCurrent(window);

	}
}