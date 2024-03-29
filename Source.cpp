#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl_Double_window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Draw.H>
#include <Fl_Box.H>
#include <Fl_Button.H>
#include <vector>
#include "menu.h"
#include "paintWindow.h"
#include "topBar.h"


int main(int argc, char** argv) {
    
   

    Fl_Window* window = new Fl_Window(500, 500, "Drawing");
    topBar* bar = new topBar(1, 1, 500, 30, "bar");
    
    paintWindow* paintWin = new paintWindow(500, 500, 1, 30, "");
 
    
    DraggableWindow* menu = new DraggableWindow(100, 100, 100, 300);
    menu->box(FL_UP_BOX);
    menu->position(10, 10);
    Fl_Button* button = new Fl_Button(5, 10, 90, 50, "options");
    
    
    window->end();
    window->show();
    return Fl::run();


    return 0;
}

//Current issues/ future changes:
//
//- line is not that smooth
//- need to figure out how to store location of each and every line instead of one changing pair of coordinates
//
//Wanted features: 
//- custom background images/gifs
//- menu, with colors, and eraser maybe more tools
//- layers
//- fun calculations that manipulate lines, like a method that liquifys an area and gives it physics that drops down etc etc