#pragma once

#include <vulkan/vulkan.h>
#include <vector>

// Vulkan Error Checking wrapper
#define CHECK_VK(func)													\
  if (VK_SUCCESS != (func)) {											\
      std::cout << std::endl << "Error -->" << func << std::endl;						\
	  std::exit(-1);													\
  }		

class VulcanInstance
{
public:
	VulcanInstance();
	~VulcanInstance();


private:
	void initVulkan();
	void createInstance();

	VkApplicationInfo appInfo;
	VkInstanceCreateInfo createInfo;

};

