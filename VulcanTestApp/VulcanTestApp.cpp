/*
Demo Entrypoint for the vulcan test App 
*/

#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <iostream>
#include <vector>

#include "Renderer.h"

int main()
{
	std::cout << "Vulcan Test App for windows \n";
	Renderer r;

	try {
		r.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

	return 0;
}
