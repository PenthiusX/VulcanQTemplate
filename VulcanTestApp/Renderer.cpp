#include "Renderer.h"


Renderer::Renderer(){
	vulcanInstance = new VulcanInstance();
}

Renderer::~Renderer(){
	delete renderWindow;
	delete vulcanInstance;
}

void Renderer::run()
{
	initWindow(1024, 768);
	vulcanInstance->startInstance();
	mainLoop();
	cleanUp();
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
	vulcanInstance->destroyInstance();
	glfwDestroyWindow(this->renderWindow);
	glfwTerminate();
}
