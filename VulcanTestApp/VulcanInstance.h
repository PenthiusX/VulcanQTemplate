#pragma once

#include <vulkan/vulkan.h>
#include <vector>

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

