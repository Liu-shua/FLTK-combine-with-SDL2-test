#include "BmpRender.h"

BmpRender::BmpRender()
	: FLTK_SDL_Worker()
	, m_bmp_texture(nullptr)
{

}
BmpRender::~BmpRender()
{
	Deinit();
}

bool BmpRender::Init(HWND work_wnd)
{
	if (!FLTK_SDL_Worker::Init(work_wnd))
	{
		return false;
		printf("Init error:s%\n",SDL_GetError());
	}
	m_bmp_texture = FLTK_SDL_Worker::loadTexture( "texture.png" );
	if (nullptr == m_bmp_texture)
	{
		return false;
		printf("Image load error:s%\n",SDL_GetError());
	}
	else
		printf("Image load success\n");
	return true;
}
void BmpRender::Deinit()
{
	if (nullptr != m_bmp_texture)
	{
		SDL_DestroyTexture(m_bmp_texture);
		m_bmp_texture = nullptr;
		printf("Image surface texture free\n");
	}
		FLTK_SDL_Worker::Deinit();
}


bool BmpRender::Render(SDL_Rect work_rect)
{
	if (nullptr != m_bmp_texture)
	{
	bool quit = false;

			//Event handler
	SDL_Event e;

			//While application is running
	while( !quit )
		{
		while( SDL_PollEvent( &e ) != 0 )
		{
					//User requests quit
		if( e.type == SDL_QUIT )
			{
			quit = true;
				}
			}
				SDL_RenderClear( fltk_sdl_renderer );
				SDL_RenderCopy( fltk_sdl_renderer, m_bmp_texture, NULL, &work_rect );
				SDL_RenderPresent( fltk_sdl_renderer );
			}
	}
	return true;
}
