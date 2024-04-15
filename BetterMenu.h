#pragma once
#include <Fl_Menu_Window.H>
#include <Fl_Menu.H>

class BetterMenu : public Fl_Menu_Window {

private:

	int arr[4];
	
public:
	BetterMenu(int x, int y, int w, int h, const char* label) :
		Fl_Menu_Window(x, y, w, h) {}


	void draw() {
		Fl_Menu_Window::draw(); 

		
		
	}































};