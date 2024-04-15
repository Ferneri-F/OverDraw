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
//#include "paintWindow.h"
#include "topBar.h"
#include "betterPainter.h"
#include "BetterMenu.h"
#include <thread>
#include <Fl_Slider.H>

using namespace std;  

//sets button_cb to be a callback function for the Fl_widget pointer
void button_cb(Fl_Widget* button, void* data) { DraggableWindow::whenPushed(button, nullptr); } //correct way to do callback functions

//void setScale(Fl_Widget* window, void* data) {
//    int dy = Fl::event_dy();
//    if (dy > 0) {
//        window->resize(window->y(), window->x(), window->w() + dy, window->h() + dy);
//        std::cout << "\nWHEEL UP";
//    }
//    else if (dy < 0) {
//        window->resize(window->y(), window->x(), window->w() + dy, window->h() + dy);
//    }
//}

//static void setScale_cb(Fl_Widget* window, void* data) { BetterPainter::setScale(FL_MOUSEWHEEL, window, nullptr); }



//infinite loop that will run in the background that checks for mousewheel scroll
//it sizes the paint window up and down
void sizeLoop(BetterPainter* win) {
    for (;;) {
     
        if (Fl::event() == FL_MOUSEWHEEL) {
            if (Fl::event_dy() > 0) {
                win->size(win->w() + 25, win->h() + 25);
                
                std::cout << "\nScroll Up";
            }
            else if (Fl::event_dy() < 0) {
                win->size(win->w() - 25, win->h() - 25);
                std::cout << "\nScroll Down";
            }
                //if (win->isScrolling == false) break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

//bool mouseOut;
//void whenMouseMoves(Fl_Widget* win, void* data) {
//    if (Fl::belowmouse() != win) {
//        mouseOut = true;
//        printf("\nMouse Out Of Window");
//    }
//    else {
//        mouseOut = false;
//    }
//}
void mouse_cb(Fl_Widget* win, void* data) { BetterPainter::whenMouseMoves , nullptr; }

void (BetterPainter::* sizeLoopPtr)(BetterPainter*);

int main(int argc, char** argv) {
    Fl::scheme("gleam");
   
     Fl_Window* window = new Fl_Window(500, 500, "Drawing");
     
    

     BetterPainter* betPaint = new BetterPainter(1, 30, 500, 500, "Testing");
     //betPaint->focus(betPaint);
     betPaint->callback(BetterPainter::whenMouseMoves);
     betPaint->align(FL_ALIGN_CENTER);
        betPaint->end();
       
        topBar* bar = new topBar(1, 1, 500, 30, "bar");

            bar->add("File/New", 0, bar_cb);
            bar->add("File/Open", 0, bar_cb);
            bar->add("File/Save", 0, bar_cb);
            bar->add("File/Undo", 0, bar_cb, 0 , FL_MENU_DIVIDER);
            bar->add("File/Quit", 0, bar_cb);
            bar->add("Edit/Brush", 0, bar_cb);
            bar->add("Edit/Preferences", 0, bar_cb);
            bar->add("View/Layers", 0, bar_cb);
        
        //thread for zoom but there must be a better solution 
    std::thread t1(sizeLoop , betPaint );
    
    window->color(FL_GRAY);
    betPaint->color(FL_WHITE);
    //betPaint->callback(setScale_cb);
    //betPaint->handle(FL_MOUSEWHEEL);
    
    //betPaint->BetterPainter::setScale(betPaint, nullptr);
    
    //betPaint->draw();
    //paintWindow* paintWin = new paintWindow(500, 500, 1, 30, "");

   
    //menu->callback(menuMouseOver_cb);
    

  
   // Fl_Button* pen = new Fl_Button(5, 15, 40, 20, "Pen");
    //Fl_Button* eraser = new Fl_Button(5, 40, 40, 20, "Eraser"); 
    //pen->color(FL_BLACK);
    //pen->callback(button_cb);
    //menu->whenPushed(pen, nullptr); 
    
    
    
    
    //paintWin->redraw();
    
    window->end();
    //betPaint->show();
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

// 4/5/2024: zooming in and out works with the mouse wheel. need to make it smoother or something,
// at this point its morre like resizing the paint window. need to work on the scale of the lines.
// need to work on a move tool
// STILL NEED TO WORK ON SAVING THE LINES JESUS CHRIST
// 