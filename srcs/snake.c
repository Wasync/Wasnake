#include "../incl/snake.h"

void collision_check(Context *ctx)
{
	Snake 		*snake;

	snake = ctx->snake;

	if (snake->head->x >= BOARD_W)
		snake->head->x = 0;
	if (snake->head->y >= BOARD_H)
		snake->head->y = 1;

	if (snake->head->x < 0)
		snake->head->x = BOARD_W - 1;
	if (snake->head->y < 0)
		snake->head->y = BOARD_H - 1;
	
	if (ctx->map[snake->head->y][snake->head->x] == 'X')
	{
		ctx->score += 10;
		ctx->map[snake->head->y][snake->head->x] = ' ';
		snake->tail->next = new_node(snake->tail->x, snake->tail->y);
		snake->tail = snake->tail->next;
		generate_point(ctx);
		//SDL_Log("Score %zu\n", ctx->score);
	}
	if (ctx->map[snake->head->y][snake->head->x] == 'S' || ctx->map[snake->head->y][snake->head->x] == '0')
		ctx->game = 2;
}

void move_snake(Context *ctx)
{
	snake_node	*current;
	Snake 		*snake;
	int x;
	int y;

	snake = ctx->snake;
	current = snake->head;

	x = current->x;
	y = current->y;

	current = current->next;
	while (current)
	{
		ctx->map[current->y][current->x] = ' ';
		swap(&x, &(current->x));
		swap(&y, &(current->y));
		ctx->map[current->y][current->x] = 'S';
		current = current->next;
	}

	if (((snake->old_dir & LEFT)  && (snake->dir & RIGHT))||
		((snake->old_dir & RIGHT) && (snake->dir & LEFT)) ||
		((snake->old_dir & UP)	  && (snake->dir & DOWN)) ||
		((snake->old_dir & DOWN)  && (snake->dir & UP)))
			snake->dir = snake->old_dir;
	if ((snake->dir & LEFT) > 0)
		snake->head->x -= 1;    
	if ((snake->dir & RIGHT) > 0)
		snake->head->x += 1;
	if ((snake->dir & UP) > 0)
		snake->head->y -= 1;
	if ((snake->dir & DOWN) > 0)
		snake->head->y += 1;
	
	snake->old_dir = snake->dir;
	collision_check(ctx);
	ctx->map[snake->head->y][snake->head->x] = 'H';
}