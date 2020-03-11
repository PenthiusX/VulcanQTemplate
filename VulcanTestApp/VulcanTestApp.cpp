/*
Demo Entrypoint for the vulcan test App 
*/

#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

//#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

// Vulkan Error Checking wrapper
#define CHECK_VK(func)													\
  if (VK_SUCCESS != (func)) {											\
      std::cout << std::endl << "Error -->" << func << std::endl;						\
	  std::exit(-1);													\
  }		

#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <vector>

#include "Renderer.h"


GLFWwindow* window;

VkInstance pvkinstance;
VkApplicationInfo appInfo;

std::vector<const char*> layers;
std::vector<const char*> extensions;

bool initVulcan()
{
	//VkApplicationInfo appInfo;
	//	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	//	appInfo.pNext = nullptr;
	//	appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);
	//	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	//	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	//	appInfo.pApplicationName = "VulcanTest";
	//	appInfo.pEngineName = "VulcanTestEngine";
	//
	//// prepare necessary extensions: Vulkan on Android need these to function
	//std::vector<const char *> instanceExt, deviceExt;
	//instanceExt.push_back("VK_KHR_surface");
	//instanceExt.push_back("VK_KHR_android_surface");
	//deviceExt.push_back("VK_KHR_swapchain");
	//
	//
	//VkInstanceCreateInfo vkinstanceinfo;
	//	vkinstanceinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	//	vkinstanceinfo.pNext = nullptr;
	//	vkinstanceinfo.pApplicationInfo = &appInfo;
	//	vkinstanceinfo.enabledExtensionCount = static_cast<uint32_t>(instanceExt.size()),
	//	vkinstanceinfo.ppEnabledExtensionNames = instanceExt.data();
	//	vkinstanceinfo.enabledLayerCount = 0;
	//	vkinstanceinfo.ppEnabledLayerNames = nullptr;
	//
	//
	//	CHECK_VK(vkCreateInstance(&vkinstanceinfo, NULL, &pvkinstance));
	//	
	//	//Need to compare vkCreateAndroidSurfaceKHR and windows vulcan surfaceGenaration function;
	//	//TODO next......
	//
	////std::cout << VK_ERROR_DEVICE_LOST;
	return false;
}

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
