#ifndef _RENDERER_
/*
Renderer TemplateClass for the Vulcan test Demo
inteded for refactoring
Author: Aditya
*/


#include <GLFW/glfw3.h>
#include <iostream>

#include "VulcanInstance.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void run();

private:
	void initWindow(int width, int height);
	void mainLoop();
	void cleanUp();

	//vars 
	GLFWwindow *renderWindow;
	VulcanInstance *vulcanInstance;
};


#endif // !_RENDERER_


