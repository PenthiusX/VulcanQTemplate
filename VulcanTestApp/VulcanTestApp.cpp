

#include <iostream>
#include "17_vertex_input.h"
//#include "recreateSwapChain.h"
//#include "VulcanRenderer.h"




int main() {
	//VulcanRenderer app;
	Vertex_input app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
