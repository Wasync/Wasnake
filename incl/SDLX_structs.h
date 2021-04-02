/***************************************************************************
 * FILENAME:	SDLX_structs.h
 * DESCRIPTION: Structures to be used by SDLX and external files.
 *
 * ENVIRONMENT:
 *	 macOS Cataline 10.15.7
 *	 Visual Studio Code 1.30
 * AUTHORS:
 *	 Kevin Colour
 * DATES:
 *	 Created: 24Jan2021
***************************************************************************/

#ifndef SDLX_structs_H
#define SDLX_structs_H

# include <SDL2/SDL.h>

typedef struct SDLX_Display
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
}	SDLX_Display;


#endif
