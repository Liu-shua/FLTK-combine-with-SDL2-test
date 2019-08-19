#include "bmprender.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/X.H>
//#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <SDL2/SDL.h>

HWND MainWnd;
BmpRender bmpRender;

void Quit_CB(Fl_Widget *, void *) {
    exit(0);
}

#undef main

int main(int argc, char **argv) {
Fl_Window *window = new Fl_Window(100,100,800,600,"测试");
  window->box(FL_DOWN_BOX);
//  Fl_Button but1(600,0,100,50,"button");

  int dx = 20, dy = dx; // border width of resizable() - see below
  Fl_Tile tile(0,0,800,600);

  // create the symmetrical resize box with dx and dy pixels distance, resp.
  // from the borders of the Fl_Tile widget before all other children
//Fl_Box r(tile.x()+dx,tile.y()+dy,tile.w()-2*dx,tile.h()-2*dy);
//tile.resizable(r);

//Fl_Window *window2 = new Fl_Window(0,0,800,60);
//  window2->box(FL_DOWN_BOX);
Fl_Menu_Window *window2 = new Fl_Menu_Window(0,0,700,40);
  window2->box(FL_DOWN_BOX);


  Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,500,40);
   menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
 
  Fl_Button but1(600,0,100,50,"button");

  window2->end();

 tile.end();

 window->end();

//window2->show(argc, argv);
//
window2->show();

window->show(argc, argv);

//window2->make_current();

//
Fl::lock();
//Fl::check();

MainWnd=fl_xid(window);

if( SDL_Init( SDL_INIT_VIDEO ) !=0 )
	{
	return false;
	printf("Init 2\n");
	}
/*	RECT show_rect = {0};
	GetClientRect(MainWnd, &show_rect);
	printf("show_rect top left are: %d %d\n",show_rect.top,show_rect.left);

	printf("show_rect right bottom are: %d %d\n",show_rect.right,show_rect.bottom);
*/


	bmpRender.Init(MainWnd);
	 printf("go here\n");
//	InvalidateRect(MainWnd, &show_rect, TRUE);
	SDL_Rect show_rect;
	show_rect.x=50;
	show_rect.y=60;
	show_rect.w=500;
	show_rect.h=500;
	bmpRender.Render(show_rect);

	SDL_Delay(1000);

//	window=fl_find(MainWnd);
//	window2->show();
	printf("go show\n");

//Fl::unlock();
int result=Fl::run();
	bmpRender.Deinit();
	printf("delete all\n");
return result;
}
