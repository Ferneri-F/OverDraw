#pragma once
#include <Fl_Menu.H>
#include <Fl_Menu_Bar.H>
#include <Fl_Menu_Item.H>

void bar_cb(Fl_Widget* w, void* data) { //code from reference
	Fl_Menu_Bar* menubar = (Fl_Menu_Bar*)w;
	const Fl_Menu_Item* item = menubar->mvalue();
	
	char ipath[256]; menubar->item_pathname(ipath, sizeof(ipath));	// Get full pathname of picked item

	fprintf(stderr, "callback: You picked '%s'", item->label());	// Print item picked
	fprintf(stderr, ", item_pathname() is '%s'", ipath);		// ..and full pathname

	if (item->flags & (FL_MENU_RADIO | FL_MENU_TOGGLE)) {		// Toggle or radio item?
		fprintf(stderr, ", value is %s", item->value() ? "on" : "off");	// Print item's value
	}
	fprintf(stderr, "\n");
	if (strcmp(item->label(), "Google") == 0);
	if (strcmp(item->label(), "Quit") == 0) { exit(0); }
}



class topBar : public Fl_Menu_Bar {

private:

	
public:

	topBar(int x, int y, int w, int h, const char* label) 
		: Fl_Menu_Bar(x, y, w, h, label) {}

	/*void draw() {
		Fl_Menu_Bar::draw();
		Fl_Menu_Item* file = new Fl_Menu_Item();
		
		labelcolor(FL_RED);


	}*/


};