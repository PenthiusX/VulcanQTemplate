#include "VulcanInstance.h"
#include <GLFW/glfw3.h>

VulcanInstance::VulcanInstance(){

}
VulcanInstance::~VulcanInstance(){

}

void VulcanInstance::startInstance(){
	createInstance();
}

void VulcanInstance::createInstance(){

	if (enableValidationLayers && !checkValidationLayerSupport()){throw std::runtime_error("Validation layers requested, but not available!");}
	else if (enableValidationLayers && checkValidationLayerSupport()){std::cout << "Validation layers requested, and are available!" << std::endl;}
	
	checkExtensionSupport();
	initVulkan();
}

void VulcanInstance::initVulkan(){

	appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	//-------
	glfwExtensionCount = 0;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	CHECK_VK(vkCreateInstance(&createInfo, nullptr, &instance));
}

//Check for all extensions support for the current hardware 
void VulcanInstance::checkExtensionSupport()
{
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	std::cout << "available extensions:" << std::endl;
	for (const auto& extension : extensions) {
		std::cout << "\t" << extension.extensionName << std::endl;
	}
}

void VulcanInstance::destroyInstance(){

	//if (enableValidationLayers) {
	//	DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	//}

	vkDestroyInstance(instance, nullptr);
}

bool VulcanInstance::checkValidationLayerSupport(){
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
    bool layerFound = false;

    for (const auto& layerProperties : availableLayers) {
        if (strcmp(layerName, layerProperties.layerName) == 0) {
            layerFound = true;
            break;
        }
    }
		if (!layerFound) {
			return false;
		}
	}
}