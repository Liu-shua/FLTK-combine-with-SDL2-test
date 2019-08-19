#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <windows.h>
#include <stdio.h>
#include <string>

class FLTK_SDL_Worker
{
public:
	FLTK_SDL_Worker();
	virtual ~FLTK_SDL_Worker();

	virtual bool Init(HWND work_wnd);
	virtual void Deinit();

	virtual bool Render(SDL_Rect work_rect)=0;
	
	virtual SDL_Texture* loadTexture(std::string path);

protected:
	SDL_Window * fltk_sdl_window;
	SDL_Renderer * fltk_sdl_renderer;
	SDL_Texture * fltk_sdl_texture;
	SDL_Rect m_show_rect;
};
