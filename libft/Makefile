NAME = libft.a
CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -rf

FILES = ft_atoi ft_substr ft_strjoin ft_strtrim ft_split ft_putnbr_fd ft_strmapi ft_itoa ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd \
       ft_bzero ft_strchr ft_strncmp ft_memcmp ft_memchr ft_strnstr ft_strdup ft_calloc \
       ft_strrchr ft_tolower ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memcpy ft_memmove ft_memset ft_strlcat ft_strlcpy ft_strlen ft_toupper


SRC = $(FILES:=.c)

OBJ = $(FILES:=.o)



$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean:
	$(RM) $(OBJ) 

fclean : clean 
	$(RM) $(NAME)

re : fclean all

.PHONY: clean
