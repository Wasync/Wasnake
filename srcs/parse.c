#include "../incl/snake.h"

void parse_map(Context *ctx)
{
	//char *line;
	//int fd;
	//int w;
	//int h;

	//fd = open("assets/map", O_RDONLY | O_DIRECTORY);
	//if (fd >= 0)
	//{
	//	SDL_Log("No map found\n");
	//	exit(1);
	//}
	
	//read(line, )
	//ctx->map = calloc(BOARD_H, sizeof(char *));
	memcpy((ctx->map)[ 0], "0000000000000   00000000000000", 30);
	memcpy((ctx->map)[ 1], "0                            0", 30);
	memcpy((ctx->map)[ 2], "0                            0", 30);
	memcpy((ctx->map)[ 3], "0                            0", 30);
	memcpy((ctx->map)[ 4], "0                            0", 30);
	memcpy((ctx->map)[ 5], "0                            0", 30);
	memcpy((ctx->map)[ 6], "0                            0", 30);
	memcpy((ctx->map)[ 7], "0                            0", 30);
	memcpy((ctx->map)[ 8], "0                            0", 30);
	memcpy((ctx->map)[ 9], "0                            0", 30);
	memcpy((ctx->map)[10], "0                            0", 30);
	memcpy((ctx->map)[11], "0                            0", 30);
	memcpy((ctx->map)[12], "0                            0", 30);
	memcpy((ctx->map)[13], "                              ", 30);
	memcpy((ctx->map)[14], "              X               ", 30);
	memcpy((ctx->map)[15], "                              ", 30);
	memcpy((ctx->map)[16], "                              ", 30);
	memcpy((ctx->map)[17], "0                            0", 30);
	memcpy((ctx->map)[18], "0                            0", 30);
	memcpy((ctx->map)[19], "0                            0", 30);
	memcpy((ctx->map)[20], "0                            0", 30);
	memcpy((ctx->map)[28], "0                            0", 30);
	memcpy((ctx->map)[21], "0                            0", 30);
	memcpy((ctx->map)[22], "0                            0", 30);
	memcpy((ctx->map)[23], "0                            0", 30);
	memcpy((ctx->map)[24], "0                            0", 30);
	memcpy((ctx->map)[25], "0                            0", 30);
	memcpy((ctx->map)[26], "0                            0", 30);
	memcpy((ctx->map)[27], "0                            0", 30);
	memcpy((ctx->map)[28], "0                            0", 30);
	memcpy((ctx->map)[29], "0000000000000   00000000000000", 30);
}