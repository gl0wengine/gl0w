//  _______    __       ______   __ __ __      
// /______/\  /_/\     /_____/\ /_//_//_/\     
// \::::__\/__\:\ \    \:::_ \ \\:\\:\\:\ \    
//  \:\ /____/\\:\ \    \:\ \ \ \\:\\:\\:\ \   
//   \:\\_  _\/ \:\ \____\:\ \ \ \\:\\:\\:\ \  
//    \:\_\ \ \  \:\/___/\\:\_\ \ \\:\\:\\:\ \ 
//     \_____\/   \_____\/ \_____\/ \_______\/                                            
// -- vulkan-based graphics engine -- 

#define GLFW_INCLUDE_VULKAN

#include <iostream>
#include "../include/GLFW/glfw3.h"

int main() {
    if (glfwVulkanSupported()) {
        // check if vulkan is available
        std::cout << "Vulkan available!";
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Glow Engine", NULL, NULL);

    VkSurfaceKHR surface;
    VkResult err = glfwCreateWindowSurface(NULL, window, NULL, &surface);
    if (err) {
        // Window surface creation failed
        std::cerr << "Window surface creation failed";
    }

     return 0;
}