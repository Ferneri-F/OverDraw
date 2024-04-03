#include <Fl_Window.H>
using namespace std;

class paintWindow : public Fl_Box {

private:
    std::vector<std::pair<int, int>> coordinates; //store mouse x and y in a dynamic vector array
    //fl_line = new *Fl_point[100];
    
    int mouseX, mouseY;
    bool isDrawing;

public:
    paintWindow(int width, int height, int x, int y, const char* title) //constructor method for making paint window object
        : Fl_Box(x, y, width, height, title), mouseX(0), mouseY(0), isDrawing(false) {}

    std::vector<std::vector<std::pair<int, int>>> lines;

    void draw() { 
        Fl_Box::draw();
        fl_color(FL_BLACK);
        fl_line_style(FL_SOLID, 2);

        for (size_t i = 1; i < coordinates.size(); i++) {
            fl_line(coordinates[i - 1].first, coordinates[i - 1].second,
                coordinates[i].first, coordinates[i].second);

            redraw();

        }
    }

    int handle(int event) {



        switch (event) {
        case FL_PUSH:
            redraw();
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
            coordinates.push_back(std::make_pair(mouseX, mouseY));
            
            redraw();
            return 1;

         case FL_MOVE:
             isDrawing = false;
             lines.push_back(coordinates);
             coordinates.clear();
             return 1;
        }
        return Fl_Box::handle(event);
    }
};  
