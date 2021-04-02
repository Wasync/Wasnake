#include "../incl/snake.h"

void pause(Context *ctx)
{
	SDL_Rect dest;

	render_game(ctx);
	if (ctx->input & PAUSE)
	{
		ctx->game = 1;
		ctx->input = 0;
		return ;
	}
	dest.x = TILE_W;
	dest.y = 10;
	dest.h = WIN_H / 3;
	dest.w = WIN_W - 50;
	render_message(ctx->font, "GAME PAUSED", NULL, &dest);

	dest.x = WIN_W / 4;
	dest.y += dest.h;
	dest.w = WIN_W / 2;
	render_message(ctx->font, strjoin("Score : ", itoa(ctx->score)), NULL, &dest);
	
	dest.x = TILE_W;
	dest.y += dest.h;
	dest.w = WIN_W - 50;
	render_message(ctx->font, "Space to resume", NULL, &dest);
}

void game_over(Context *ctx)
{
	SDL_Rect dest;

	dest.h = WIN_H / 3;
	dest.w = WIN_W - 50;
	if (ctx->input & RESET)
	{
		ctx->game = 1;
		return ;
	}
	render_game(ctx);
	
	dest.x = TILE_W;
	dest.y = 10;
	render_message(ctx->font, "GAME OVER", NULL, &dest);
	
	dest.x = WIN_W / 4;
	dest.y += dest.h;
	dest.w = WIN_W / 2;
	render_message(ctx->font, strjoin("Score : ", itoa(ctx->score)), NULL, &dest);
	
	dest.x = TILE_W;
	dest.y += dest.h;
	dest.w = WIN_W - 50;
	render_message(ctx->font, "R to restart", NULL, &dest);
}

void main_loop(Context *ctx)
{
	SDL_Rect dest;

	dest.x = 10;
	dest.y = 10;
	dest.h = TILE_H * 3;
	dest.w = TILE_W * 4;

	if (ctx->input & PAUSE)
	{
		ctx->game = 0;
		return ;
	}
	move_snake(ctx);
	render_game(ctx);
	render_message(ctx->font, strjoin("Score : ", itoa(ctx->score)), NULL, &dest);
}