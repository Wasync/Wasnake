#include "../incl/snake.h"

snake_node *new_node(int x, int y)
{
	snake_node *new;

	new = calloc(1, sizeof(snake_node));

	new->x = x;
	new->y = y;

	return new;
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_bits(int n, int bits)
{
	for (int i = bits; i > 0; i++)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

void generate_point(Context *ctx)
{
	int x;
	int y;
	x = rand()  % (BOARD_W - 1);
	y = rand()  % (BOARD_H - 1);
	while (ctx->map[y][x] != ' ')
	{
		x = rand()  % (BOARD_W - 1);
		y = rand()  % (BOARD_H - 1);
	}
	ctx->map[y][x] = 'X';
}

char	*strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	
	len = SDL_strlen(s1) + SDL_strlen(s2) + 1;
	if (!(str = SDL_malloc(len)))
		return (NULL);

	SDL_strlcpy(str, s1, len);

	SDL_strlcat(str, s2, len);
	return str;
}

unsigned int	intsize(long long nb)
{
	unsigned int size;

	size = 0;
	while (nb > 0)
	{
		++size;
		nb /= 10;
	}
	return (size);
}

char	*itoa(int nbr)
{
	char			*str;
	long long		n;
	unsigned int	size;

	if (nbr == 0)
		return (SDL_strdup("0"));
	n = (long long)nbr;
	if (nbr < 0)
		n *= -1;
	size = intsize(n) + (nbr < 0);
	if (!(str = (char*)SDL_malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	str[size] = '\0';
	while (n > 0)
	{
		str[--size] = (char)(n % 10 + 48);
		n /= 10;
	}
	return (str);
}

void render_message(TTF_Font *font, char *msg, const SDL_Rect *src, const SDL_Rect *dst)
{
	SDL_Surface *message;
	SDLX_Display *display;

	display = SDLX_GetDisplay();
	message = TTF_RenderText_Solid(font,
						msg,
						(SDL_Color){255, 255, 255, 255});
	SDL_RenderCopy(display->renderer,
					SDL_CreateTextureFromSurface(display->renderer, message),
					src, dst);
	SDL_FreeSurface(message);
	//Should be using SDL_itoa here but there is no internet so I can't look at the documentation >:(
}
