#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl_Double_window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Draw.H>
#include <Fl_Box.H>
#include <Fl_Button.H>
#include <utility> 
#include <iostream>
#include <vector>
#include "menu.h"
#include "paintWindow.h"
#include "topBar.h"
#include "betterPainter.h"

using namespace std; 

//void lineSave() {
//
//    pair<int, int> coord[5] = { make_pair(10,3), make_pair(20,5), make_pair(30, 6), make_pair(40, 8)};
//
//    for (size_t i = 1; i < 5; i++) {
//        fl_line(coord[i - 1].first, coord[i - 1].second,
//            coord[i].first, coord[i].second);
//
//    }
//}

//sets button_cb to be a callback function for the Fl_widget pointer
void button_cb(Fl_Widget* button, void*) { DraggableWindow::whenPushed(button, nullptr); } //correct way to do callback functions


int main(int argc, char** argv) {
   
    Fl_Window* window = new Fl_Window(500, 500, "Drawing");
    window->color(FL_WHITE);

    topBar* bar = new topBar(1, 1, 500, 30, "bar");
    BetterPainter betPaint(1, 30, 500, 500, "Testing");
    
    //betPaint.draw();
    //paintWindow* paintWin = new paintWindow(500, 500, 1, 30, "");

    //DraggableWindow* menu = new DraggableWindow(100, 100, 50, 70);
    
    //menu->box(FL_UP_BOX);
    //menu->position(10, 10);

  
    //Fl_Button* pen = new Fl_Button(5, 15, 40, 20, "Pen");
    //Fl_Button* eraser = new Fl_Button(5, 40, 40, 20, "Eraser"); 
    //pen->color(FL_BLACK);
    //pen->callback(button_cb);
    //menu->whenPushed(pen, nullptr); //currently TRYNING to make this callback shit work

    //paintWin->redraw();
    
    
    //paintWin->redraw();
    
    
    window->end();
    window->show();
    return Fl::run();

    return 0;
}

//Current issues/ future changes:
//
//
//- need to figure out how to store location of each and every line instead of one changing pair of coordinates
//
//Wanted features: 
//- custom background images/gifs
//- menu, with colors, and eraser maybe more tools
//- layers
//- 