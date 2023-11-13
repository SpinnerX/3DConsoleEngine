#include <core/Window.h>
#include <formatCpp/formatCpp.h>

Window::Window(int w, int h, std::string name) : width(w), height(h), name(name) {
    if(!glfwInit()){
        formatCpp::print("GLFW was not initialized");
        std::terminate();
    }

    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

Window::~Window(){
    glfwTerminate();
}

void Window::mainloop(){
    if(window == nullptr){
        formatCpp::print("GLFWwindow is nullptr!\n");
        return;
    }

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}


void Window::DrawSprite(){
    
}