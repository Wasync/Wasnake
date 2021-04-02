#include "../../incl/SDLX.h"

void SDLX_InputLoop(void)
{
	SDL_Event	event;
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
	}
}

void SDLX_RenderLoop(void)
{	
	SDLX_Display *display;

	display = SDLX_GetDisplay();
	SDLX_screen_reset(display->renderer, NULL);
	SDL_Delay(DELAY_AMNT);
}

void SDLX_Update(void)
{
	SDLX_InputLoop();
	SDLX_RenderLoop();
}