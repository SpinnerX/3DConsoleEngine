#pragma once
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <cstring>
#include <string>
#include <ostream>

/**
 * 
 * Window Entity
 * - DrawLines
 * - DrawShapes
 * - DrawObjects
 * - AddLayers
 *  - Layers are so we can have layers on top of the actual UI to interact with.
 *  - May need to look into the rendering pipelines for this.
 * 
 * 
*/


class Window{
public:
    Window() = default;
    Window(int w, int h, std::string name);
    ~Window();

    void mainloop();

    void DrawSprite();

    friend std::ostream& operator<<(std::ostream& outs, Window& w){
        return outs << "w: " << std::to_string(w.width) << ", h: " << std::to_string(w.height)  << ", name: " << w.name << ")"; 
    }

protected:
    int width;
    int height;
    std::string name;
    GLFWwindow* window;
};