SRCS= 			pipex.c \
				./errors/error.c \
				./exec/do_cmd.c \
				$(SRCS_UTILS) \
				$(SRCS_PARSING) \
				$(SRCS_EXEC) 


SRCS_UTILS=		./utils/ft_split.c \
				./utils/ft_strlen.c \
				./utils/ft_strdup.c \
				./utils/ft_strjoin.c \
				./utils/ft_strncmp.c \
				./utils/ft_substr.c \
				./utils/ft_freetab.c

SRCS_PARSING=	./parsing/get_paths.c \
				./parsing/join_paths.c \
				./parsing/params_checking.c

SRCS_EXEC=		./exec/do_cmd.c \
				./exec/receive_commands.c