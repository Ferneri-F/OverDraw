#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Draw.H>
#include <Fl_Box.H>
#include <vector>



class paintWindow : public Fl_Box {

private:
    std::vector<std::pair<int, int>> coordinates; //store mouse x and y in a dynamic vector array
    int mouseX, mouseY;
    bool isDrawing;

public:
    paintWindow(int width, int height, int x, int y, const char* title) //constructor method for making paint window object
        : Fl_Box(x, y, width, height, title), mouseX(0), mouseY(0), isDrawing(false) {}

    void draw() { //
        Fl_Box::draw();
        fl_color(FL_BLACK);
        fl_line_style(FL_SOLID, 5);

        for (size_t i = 1; i < coordinates.size(); i++) {
            fl_line(coordinates[i - 1].first, coordinates[i - 1].second, coordinates[i].first, coordinates[i].second);
        }
    }

    int handle(int event) {

        switch (event) {
        case FL_PUSH:
            mouseX = Fl::event_x(); //returns mouse position event at x and y 
            mouseY = Fl::event_y();
            coordinates.push_back(std::make_pair(mouseX, mouseY)); //add new points to the coordinates vector
            isDrawing = true; //mouse is considered to be drawing if button is pressed
            redraw(); //redraw tells the widget to update on the screen
            return 1;

        //if mouse is clicked and dragged
        case FL_DRAG:
            if (isDrawing) {
                mouseX = Fl::event_x();
                mouseY = Fl::event_y();
                coordinates.push_back(std::make_pair(mouseX, mouseY));
                redraw();
            }
            return 1;
        case FL_RELEASE: //if mouse is released
            isDrawing = false;
            return 1;
        }
        return Fl_Box::handle(event);
    }
};
  

  


int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(600, 800, "Drawing");
    paintWindow* paintWin = new paintWindow(600, 800, 10, 10, "");
    window->end();
    window->show();
    return Fl::run();
   

    return 0;
}

//Current issues/ future changes:
//- line trys to connect to the next coordinate
//- line is not that smooth
//- need to figure out how to store location of each and every line instead of one changing pair of coordinates
//
//Wanted features: 
//- custom background images/gifs
//- menu, with colors, and eraser maybe more tools
//- layers
//- fun calculations that manipulate lines, like a method that liquifys an area and gives it physics that drops down etc etc
