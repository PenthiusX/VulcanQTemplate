#include <iostream>
#include "17_vertex_input.h"
//#include "recreateSwapChain.h"
//#include "VulcanRenderer.h"//need to compile shader 09



int main() {
	//VulcanRenderer app;//need to compile shader 09
	Vertex_input app;//need to compile shader 17

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
