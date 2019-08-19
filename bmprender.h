#include "fltksdlrender.h"

class BmpRender: FLTK_SDL_Worker
{
public:
	BmpRender();
	~BmpRender();

	bool Init(HWND work_wnd);
	void Deinit();

	bool Render(SDL_Rect work_rect);
	SDL_Texture* loadTextureb (std::string path);
	
private:
	SDL_Texture * m_bmp_texture;

};
