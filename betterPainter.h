#include <FL/Fl.H>
#include <Fl_Widget.H>
#include <Fl_Window.H>
#include <vector>

class BetterPainter : public Fl_Double_Window {

private:
	int mouseX;
	int mouseY;
	double brushSize;
	bool isDrawing;

	std::vector<std::pair<int, int>> coordinates; //vector of coordinates as
	std::vector<std::pair<double, double>> drawPath;
	vector <std::pair<int, int>> lines[10];

	//ima try to make a circle struct that holds coordinates
	struct lines {
	
	};

public:

	BetterPainter(int x, int y, int w, int h, const char* title) //constructor method for making paint window object
		: Fl_Double_Window(x,y,w,h,title), mouseX(0), mouseY(0), brushSize(5.0), isDrawing(false) {}

	

	 void draw() {
		 Fl_Double_Window::draw(); //draw the window object
		 cursor(FL_CURSOR_NONE); 

		 //this draws the circle outline at position of mouse
		 
		 int x; int y;
		 int x1; int y2;
		 fl_color(FL_BLACK);
		 //isDrawing = false;
		 
			 for (unsigned long long i = 0; i < coordinates.size(); i++) {
				
				 x1 = coordinates[i].first;
				 y2 = coordinates[i].second;
				 fl_circle(mouseX, mouseY, brushSize);
				 if (isDrawing = true) break;
			 }
			 if (isDrawing = true) {
				 for (int b = 0; b < drawPath.size(); b++) {
				 	 // Draw filled arc
				 fl_begin_polygon();
				 fl_arc(drawPath[b].first , drawPath[b].second, brushSize, 0.0, 360);
				 fl_end_polygon();
				 //lines[1] = drawPath;
				 redraw();
				 if (isDrawing = false) break;
				 }
			 }
			 

		 }

	 //// Draw filled arc
	 //fl_begin_polygon();
	 //fl_arc(x, y, 5, 0.0, 360);
	 //fl_end_polygon();

	 int handle(int event) {

		 int x; int y;

		 switch (event) {
		 case FL_PUSH:
			 isDrawing = true;
			 //redraw();
			 mouseX = Fl::event_x(); //returns mouse position event at x and y 
			 mouseY = Fl::event_y();
			 //coordinates.clear(); //add new points to the coordinates vector
			 drawPath.push_back(std::make_pair(mouseX, mouseY));
			 //coordinates.push_back(std::make_pair(mouseX, mouseY));
			  //mouse is considered to be drawing if button is pressed
			 redraw(); //redraw tells the widget to update on the screen
			 return 1;

		 case FL_DRAG:
			 //coordinates.clear();
			 isDrawing = true;
			 mouseX = Fl::event_x();
			 mouseY = Fl::event_y();
			 drawPath.push_back(std::make_pair(mouseX , mouseY));
			 coordinates.push_back(std::make_pair(mouseX, mouseY));
			 redraw();
			 return 1;

		 case FL_RELEASE:
			 //drawPath.clear();
			 isDrawing = false;
			 
			 redraw();
			 
			 return 1;

		 case FL_MOVE:
			 isDrawing = false;

			 coordinates.clear();
				 mouseX = Fl::event_x();
				 mouseY = Fl::event_y();
				 coordinates.push_back(std::make_pair(mouseX, mouseY));
				 redraw();
				 return 1;

		 
		 }return Fl_Double_Window::handle(event);
	}
	












};