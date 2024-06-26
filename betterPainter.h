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
	
	double scale;
	
	std::vector<std::pair<int, int>> coordinates; //vector of coordinates as
	std::vector<std::pair<int, int>> drawPath;
	//vector <std::pair<int, int>> lines[10];

	//ima try to make a circle struct that holds coordinates

	typedef struct LineCoord { //hold coordinates of each position of the brush stroke
		int x; int y;
		int brushSize;

	}LineCoord;
	//each of these vectors is a layer... will add more if i make it work
	std::vector<struct LineCoord*> brushStrokes0 ; //a vector of brush stroke points/ layer number 0 and onwards
	std::vector<struct LineCoord*> brushStrokes1 ;
	std::vector<struct LineCoord*> brushStrokes2 ;

public:

	BetterPainter(int x, int y, int w, int h, const char* title) //constructor method for making paint window object
		: Fl_Double_Window(x, y, w, h, title), mouseX(0), mouseY(0), brushSize(5.0), scale(1) , isScrolling(false) {}
		
	/*static int setScale(int event, Fl_Widget* window, void* data) {

		BetterPainter* ptr = static_cast<BetterPainter*>(data);

		int dy = Fl::event_dy();
		if (dy > 0) {
			ptr->resize(ptr->y(), ptr->x(), ptr->w() + dy, ptr->h() + dy);
			std::cout << "\nWHEEL UP";
		}
		else if (dy < 0) {
			ptr->resize(ptr->y(), ptr->x(), ptr->w() + dy, ptr->h() + dy);
		}
	}*/

	//callback function when mouse is out of window
	
	static void whenMouseMoves(Fl_Widget* win, void* data) {
		bool mouseOut;
		if (Fl::belowmouse() != win) {
			mouseOut = true;
			printf("\nMouse Out Of Window");
		}
		else {
			mouseOut = false;
		}
	}


	//get and set the scale for the window
	double getScale() { return scale ; }
	void   setScale(double s) { scale = s; }
	

	bool isScrolling;
	bool isScrollingUp;
	bool isScrollingDown;

	void draw() {
		Fl_Double_Window::draw(); //draw the window object
		//cursor(FL_CURSOR_NONE);

		//this draws the circle outline at position of mouse

		int x; int y;
		int x1; int y2;
		fl_color(FL_BLACK);
		//isDrawing = false;
		LineCoord* coord = new LineCoord(); 

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
				fl_arc(drawPath[b].first, drawPath[b].second, brushSize, 0.0, 360);
				fl_end_polygon();

				// Save line in this layer
				coord->x = drawPath[b].first;
				coord->y = drawPath[b].second;
				coord->brushSize = brushSize;
				brushStrokes0.push_back(coord);

				//lines[1] = drawPath;
				redraw();
				if (isDrawing = false) break;
			}
		}


	}

	int handle(int event) {

		

		switch (event) {
		case FL_PUSH:
			isScrolling = false;
			isDrawing = true;
			//redraw();
			mouseX = Fl::event_x(); //returns mouse position event at x and y 
			mouseY = Fl::event_y();
			
			drawPath.push_back(std::make_pair(mouseX, mouseY));
			
			 //mouse is considered to be drawing if button is pressed
			redraw(); //redraw tells the widget to update on the screen
			return 1;

		case FL_DRAG:
			//coordinates.clear();
			//isScrolling = false;
			isDrawing = true;
			mouseX = Fl::event_x();
			mouseY = Fl::event_y();
			drawPath.push_back(std::make_pair(mouseX, mouseY));
			coordinates.push_back(std::make_pair(mouseX, mouseY));
			printf("\rDrawPath X : %d Y: %d     Coordinates X : %d Y: %d", mouseX, mouseY, mouseX, mouseY);
			
			redraw();
			return 1;

		case FL_RELEASE:
			isScrolling = false;
			//drawPath.clear();
			//isDrawing = false;

			redraw();

			return 1;

		case FL_MOVE:
			isDrawing = false;
			//isScrolling = false;
			if (Fl::belowmouse()) {
				coordinates.clear();
				mouseX = Fl::event_x();
				mouseY = Fl::event_y();
				coordinates.push_back(std::make_pair(mouseX, mouseY));
				
				//printf("\rmouse inside");
				redraw();
			}
			//else if (! Fl::belowmouse()) printf("\rmouse out of window");
			return 1;
		
			case FL_MOUSEWHEEL:
				int scrollY = Fl::event_y() * 2;
					//Fl::wait(0.1);
			isScrolling = true;
			if (scrollY < 0) isScrollingUp = true;
			else isScrollingDown = true;
			//std::cout << "\rmouse wheel moving";
			isScrolling = false;
			return 1;
		}return Fl_Double_Window::handle(event);
	}







};