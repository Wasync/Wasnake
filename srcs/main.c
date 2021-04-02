#include "../incl/snake.h"

typedef void(*game_func)(Context *ctx);
	SDLX_Display 	*display;
	Context 		*context;
	game_func		loops[3];
	

void main_loop(Context *ctx);
void game_over(Context *ctx);
void pause(Context *ctx);


void game_loop(void)
{
	loops[0] = pause;
	loops[1] = main_loop;
	loops[2] = game_over;
	input(context);
	loops[context->game](context);
	SDLX_RenderLoop();
}

int main(void)
{
	display = SDLX_GetDisplay();
	context = get_context();
	emscripten_set_main_loop(game_loop, 0, 1);
}
