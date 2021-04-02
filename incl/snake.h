#include "SDLX.h"
#include <SDL2/SDL_ttf.h>
#include <emscripten.h>

# define SNAKE_INITIAL 3
# define BOARD_W 30
# define BOARD_H 30
# define TILE_W WIN_W / BOARD_W
# define TILE_H WIN_H / BOARD_H


typedef enum	INPUT
{
	LEFT 	= 0b000001,
	RIGHT	= 0b000010,
	UP 		= 0b000100,
	DOWN 	= 0b001000,
	RESET	= 0b010000,
	PAUSE 	= 0b100000,
}				INPUT;

typedef struct snake_node
{
	int x;
	int y;

	struct snake_node *next;
}				snake_node;


typedef struct Snake
{
	snake_node *head;
	snake_node *tail;

	int	 dir;
	int old_dir;
}				Snake;

typedef struct s_context
{
	SDL_GameController	*controller;
	Snake *snake;

	size_t score;

	TTF_Font *font;
	char map[BOARD_H][BOARD_W];
	int game;
	int input;
}				Context;

void move_snake(Context *ctx);
void input(Context *ctx);

void swap(int *a, int *b);
snake_node *new_node(int x, int y);
void render_game(Context *context);
void print_bits(int n,int bits);
void parse_map(Context *ctx);
void generate_point(Context *ctx);
Context *get_context();
void reset_game(Context *ctx);

void 	render_message(TTF_Font *font, char *msg, const SDL_Rect *src, const SDL_Rect *dst);
char	*strjoin(char const *s1, char const *s2);
char	*itoa(int nbr);
