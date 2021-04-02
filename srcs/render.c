#include "../incl/snake.h"

void render_game(Context *ctx)
{
	SDL_Surface *surf;
	SDLX_Display *display;
	SDL_Rect	rect;
	int x;
	int y;

	rect.h = TILE_H + 1;
	rect.w = TILE_W + 1;
	display = SDLX_GetDisplay();
	surf = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0, 0, 0, 0);
	y = 0;
	while (y < BOARD_H)
	{
		x = 0;
		while (x < BOARD_W)
		{
			rect.x = x * TILE_W;
			rect.y = y * TILE_H;
			if (ctx->map[y][x] == 'X')
				SDL_FillRect(surf, &rect, SDL_MapRGBA(surf->format, 255,   0,   0, 255));
			if (ctx->map[y][x] == 'S')
				SDL_FillRect(surf, &rect, SDL_MapRGBA(surf->format,   0, 255,   0, 255));
			if (ctx->map[y][x] == 'H')
				SDL_FillRect(surf, &rect, SDL_MapRGBA(surf->format,   0, 200,  55, 255));
			if (ctx->map[y][x] == '0')
				SDL_FillRect(surf, &rect, SDL_MapRGBA(surf->format,   0,   0, 150, 255));
			x++;
		}
		y++;
	}

	SDL_RenderCopy(display->renderer, 
					SDL_CreateTextureFromSurface(display->renderer, surf),
					NULL, NULL);
	SDL_FreeSurface(surf);
}