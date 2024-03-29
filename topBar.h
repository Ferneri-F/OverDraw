#pragma once
#include <Fl_Menu.H>
#include <Fl_Menu_Bar.H>
#include <Fl_Menu_Item.H>

class topBar : public Fl_Menu_Bar {

private:



public:

	topBar(int x, int y, int w, int h, const char* label) 
		: Fl_Menu_Bar(x, y, w, h, label) {}

	void draw() {
		Fl_Menu_Bar::draw();

		


	}


};