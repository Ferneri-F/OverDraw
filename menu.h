#pragma once
class DraggableWindow : public Fl_Double_Window {

private:
    int previous_x, previous_y;
    bool dragging;
    int dragHeight;

    static void TimerCallback(void* data) { //timer that refreshes the page every 0.01ms
        DraggableWindow* window = static_cast<DraggableWindow*>(data);
        if (window->dragging) {
            window->position(Fl::event_x() - window->previous_x, Fl::event_y() - window->previous_y);
            Fl::repeat_timeout(0.001, TimerCallback, data);
        }
    }
public:



    DraggableWindow(int x, int y, int w, int h, const char* label = 0)
        : Fl_Double_Window(x, y, w, h, label) , dragging(false) , dragHeight(15) {}

   

    int handle(int event)  {
        switch (event) {
        case FL_PUSH:
            if (Fl::event_y() < dragHeight) { //if mouse clicks above drag height, then the window will be draggable
                previous_x = Fl::event_x();
                previous_y = Fl::event_y();
                dragging = true;
                Fl::add_timeout(0.001, TimerCallback, this);
                redraw();
                return 1;
            }
            else break;
        case FL_RELEASE:
            dragging = false;
            //position(Fl::event_x, Fl::event_y);
            redraw();
            return 1;
        case FL_DRAG:
            if (dragging) redraw(); 
            return 1;
        default:
            return Fl_Window::handle(event);
        }
    }


};