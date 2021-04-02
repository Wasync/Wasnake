#include "../incl/snake.h"

void reset_game(Context *ctx)
{
	snake_node *head;
	snake_node *tmp;
	int i;

	i = 0;
	ctx->game = 1;
	ctx->score = 0;
	ctx->snake->dir = RIGHT;
	ctx->snake->old_dir = RIGHT;
	head = ctx->snake->head;
	head->x = 9;
	head->y = 10;
	while (i < SNAKE_INITIAL)
	{
		head->next->x = 9;
		head->next->y = 10;
		head = head->next;
		i++;
	}
	tmp = head->next;
	head->next = NULL;
	ctx->snake->tail = head;

	while (tmp != NULL)
	{
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	parse_map(ctx);
}

void init_ctx(Context *ctx)
{
	snake_node *head;
	int i;

	i = 0;
	ctx->game = 1;
	ctx->score = 0;
	parse_map(ctx);
	if (!ctx->snake)
		ctx->snake = SDL_calloc(1, sizeof(*ctx->snake));
	head = new_node(10, 10);

	ctx->snake->dir = RIGHT;
	ctx->snake->old_dir = RIGHT;
	ctx->snake->head = head;
	while (i < SNAKE_INITIAL)
	{
		head->next = new_node(9, 10);
		head = head->next;
		i++;
	}
	ctx->snake->tail = head;
	if (!TTF_Init())
		SDL_Log("NO TTF");

	ctx->font = TTF_OpenFont(strjoin(ASSETS_PATH, "Pixel_Font.ttf"), 14);
}

Context *get_context()
{
	static Context ctx;

	if (ctx.snake == NULL)
		init_ctx(&ctx);

	return &ctx;
}
