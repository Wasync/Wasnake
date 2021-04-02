#include "../incl/snake.h"

void input(Context *ctx)
{
	SDL_Event		event;
	const Uint8		*keyboard;

	ctx->input = 0;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				ctx->input = PAUSE;
				return ;
			}
		}
	}
	keyboard = SDL_GetKeyboardState(NULL);
	if (keyboard[SDL_SCANCODE_R])
	{
		reset_game(ctx);
		return ;
	}

	ctx->snake->dir = (keyboard[SDL_SCANCODE_LEFT]  != 0) ? (LEFT) 	: (ctx->snake->dir);
	ctx->snake->dir = (keyboard[SDL_SCANCODE_RIGHT] != 0) ? (RIGHT) : (ctx->snake->dir);
	ctx->snake->dir = (keyboard[SDL_SCANCODE_UP]    != 0) ? (UP) 	: (ctx->snake->dir);
	ctx->snake->dir = (keyboard[SDL_SCANCODE_DOWN]  != 0) ? (DOWN) 	: (ctx->snake->dir);
	
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
}