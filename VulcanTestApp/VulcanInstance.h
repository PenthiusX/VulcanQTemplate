#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

// Vulkan Error Checking wrapper
#define CHECK_VK(func)													\
  if (VK_SUCCESS != (func)) {											\
      throw std::runtime_error("failed to create instance!");						\
	  std::exit(-1);													\
  }		


class VulcanInstance
{
public:
	VulcanInstance();
	~VulcanInstance();

	void startInstance();
	void destroyInstance();

private:
	void initVulkan();
	void createInstance();

	void checkExtensionSupport();
	bool checkValidationLayerSupport();

	VkInstance instance;
	VkApplicationInfo appInfo;
	VkInstanceCreateInfo createInfo;
	uint32_t glfwExtensionCount;
	const char** glfwExtensions;




	//Validation enabled on Debug
	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

};

