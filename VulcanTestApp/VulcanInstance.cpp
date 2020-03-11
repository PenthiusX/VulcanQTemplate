#include "VulcanInstance.h"

#include <GLFW/glfw3.h>

VulcanInstance::VulcanInstance(){
	initVulkan();
}

VulcanInstance::~VulcanInstance(){
	if(instance){vkDestroyInstance(instance, nullptr);}
}

void VulcanInstance::start(){
	createInstance();
	initVulkan();
}

void VulcanInstance::initVulkan(){
	createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	//-------
	glfwExtensionCount = 0;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	//-------

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	CHECK_VK(vkCreateInstance(&createInfo, nullptr, &instance));
}

void VulcanInstance::createInstance(){
	appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;
}

void VulcanInstance::destroyInstance(){
	vkDestroyInstance(instance, nullptr);
}


