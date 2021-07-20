#pragma once

#include <GLFW/glfw3.h>

namespace FO3D {

	const int SCREEN_WIDTH(1280);
	const int SCREEN_HEIGHT(720);

	class Engine
	{
	public: 
		Engine();
		Engine(const Engine&) = delete;
		~Engine();

		static Engine& Ref() {
			static Engine refference;
			return refference;
		}

		void Quit();
		void Update();
		void Initialize();

		inline const bool Run() const {return run;}
		inline GLFWwindow& Window() { return *window; }
		inline const float VideoWidth() const { return videoWidth; }
		inline const float VideoHeight() const { return videoHeight; }


	private:
		bool run;
		GLFWwindow* window;
		float videoWidth, videoHeight;
	};

	static Engine& Core = Engine::Ref();
	};

