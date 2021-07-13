NAME			= philo
SRC				=	main.c	\
					ft_atoi_long.c	\
					ft_isdigit.c	\
					ph_check_arg.c	\
					ph_init.c	\
					ph_init_2.c	\
					ph_exec.c	\
					ph_add.c	\

SRCDIR			= src
OBJDIR			= obj
OBJ				= $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME) 

$(OBJDIR):			
				mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
				$(CC) $(CFLAGS) -I. -c -MD $< -o $@

include $(wildcard $(OBJDIR)/*.d)

all:			$(NAME)

clean:	
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
