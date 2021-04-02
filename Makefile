NAME = Snake
FLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I includes/ -I includes/includes_SDL2/

LIB_DIR = libs/
LIBRARIES = $(LIB_DIR)libSDL2.dylib $(LIB_DIR)libSDL2_ttf.dylib

SDLX_DIR = SDLX/
SRCS_DIR = srcs/

BIN_DIR = bin/


SDLX_NAMES = 			\
	SDLX_init			\
	SDLX_render			\
	SDLX				\

SRCS_NAMES =	\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))		\
	game_loops			\
	init				\
	input				\
	main 				\
	parse				\
	render				\
	snake				\
	utils				\

C_FILES =				\
	$(SRCS_NAMES) 		\
	
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(C_FILES)))
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARIES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re clean
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
