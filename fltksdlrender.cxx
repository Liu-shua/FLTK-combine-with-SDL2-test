#include "fltksdlrender.h"

FLTK_SDL_Worker::FLTK_SDL_Worker()
	: fltk_sdl_window(nullptr)
	, fltk_sdl_renderer(nullptr),fltk_sdl_texture(nullptr)
{
	m_show_rect.x = m_show_rect.y = 0;
	m_show_rect.w = m_show_rect.h = 0;
}

FLTK_SDL_Worker::~FLTK_SDL_Worker()
{
	Deinit();
}

bool FLTK_SDL_Worker::Init(HWND work_wnd)
{
	if (nullptr == work_wnd)
	{
		return false;
	}

	if (nullptr != fltk_sdl_window)
	{
		return true;
	}

	if (0 == SDL_WasInit(SDL_INIT_VIDEO))
	{
		SDL_InitSubSystem(SDL_INIT_VIDEO);
	}

	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

	fltk_sdl_window = SDL_CreateWindowFrom(work_wnd);
	if (nullptr == fltk_sdl_window)
	{
		return false;
		printf("SDL_Window error:s%\n",SDL_GetError());
	}

	SDL_ShowWindow(fltk_sdl_window);
//	SDL_SetWindowTitle(fltk_sdl_window,"SDL in FLTK");
	fltk_sdl_renderer = SDL_CreateRenderer(fltk_sdl_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (nullptr == fltk_sdl_renderer)
	{
		return false;
		printf("SDL_Render error:s%\n",SDL_GetError());

	}
	  	SDL_SetRenderDrawColor( fltk_sdl_renderer, 0xFF, 0xFF, 0xFF,
 0xFF );
		printf("SDL_Window Render created!\n");
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return false;
	}
	return true;
}

SDL_Texture *FLTK_SDL_Worker::loadTexture( std::string path )
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
	printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
        newTexture = SDL_CreateTextureFromSurface( fltk_sdl_renderer, loadedSurface );
	if( newTexture == NULL )
	{
	printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}

void FLTK_SDL_Worker::Deinit()
{
	if (nullptr != fltk_sdl_renderer)
	{
		SDL_DestroyRenderer(fltk_sdl_renderer);
		fltk_sdl_renderer = nullptr;
		printf("SDL_Window Render delete success!\n");
	}
		if (nullptr != fltk_sdl_texture)
	{
		SDL_DestroyTexture(fltk_sdl_texture);
		fltk_sdl_texture = nullptr;
		printf("SDL_Window texture delete success!\n");
	}

	if (nullptr != fltk_sdl_window)
	{
		SDL_DestroyWindow(fltk_sdl_window);
		fltk_sdl_window = nullptr;
		printf("SDL_Window delete success!\n");
	}
	IMG_Quit();
	SDL_Quit();
}
