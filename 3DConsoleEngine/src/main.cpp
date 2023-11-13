#include <iostream>
// #include <math/Vector.h>

#include <core/Window.h>

/**
 * 
 * Sandbox thhat will simply allow us to render stuff
 * 
*/

class Sandbox : public Window{
public:
    Sandbox(){
        
    }
    void CreateInstance(){

    }
};

int main(){
    Sandbox gui;
    gui.mainloop();
    return 0;
}