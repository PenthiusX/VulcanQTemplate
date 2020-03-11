#include "Renderer.h"


Renderer::Renderer(){}
Renderer::~Renderer(){}

void Renderer::run()
{
	initWindow(1024, 768);
	initVulcan();
	mainLoop();
	cleanUp();
}

void Renderer::initVulcan()
{

}

void Renderer::mainLoop()
{
	while (!glfwWindowShouldClose(this->renderWindow)) {
		glfwPollEvents();
	}
}

void Renderer::initWindow(int width, int height) {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->renderWindow = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
}

void Renderer::cleanUp()
{
	glfwDestroyWindow(this->renderWindow);
	glfwTerminate();
}
