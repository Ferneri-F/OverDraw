#pragma once
#include <Fl_Menu.H>
#include <Fl_Menu_Bar.H>
#include <Fl_Menu_Item.H>

class topBar : public Fl_Menu_Bar {

private:

	enum { // values for flags:
		FL_MENU_INACTIVE = 1,      // Deactivate menu item (gray out)
		FL_MENU_TOGGLE = 2,      // Item is a checkbox toggle (shows checkbox for on/off state)
		FL_MENU_VALUE = 4,      // The on/off state for checkbox/radio buttons (if set, state is 'on')
		FL_MENU_RADIO = 8,      // Item is a radio button (one checkbox of many can be on)
		FL_MENU_INVISIBLE = 0x10,   // Item will not show up (shortcut will work)
		FL_SUBMENU_POINTER = 0x20,   // Indicates user_data() is a pointer to another menu array
		FL_SUBMENU = 0x40,   // This item is a submenu to other items
		FL_MENU_DIVIDER = 0x80,   // Creates divider line below this item. Also ends a group of radio buttons.
		FL_MENU_HORIZONTAL = 0x100   // ??? -- reserved
	};

public:

	struct Fl_Menu_Item {
		const char* text;     // label()
		ulong         shortcut;
		Fl_Callback* callback;
		void* user_data_;
		int           flags;
		uchar         labeltype;
		uchar         labelfont;
		uchar         labelsize;
		uchar         labelcolor;
	};


	topBar(int x, int y, int w, int h, const char* label) 
		: Fl_Menu_Bar(x, y, w, h, label) {}

	void draw() {
		Fl_Menu_Bar::draw();
		Fl_Menu_Item* file = new Fl_Menu_Item();
		
		//file->labelcolor(FL_BLACK);


	}


};