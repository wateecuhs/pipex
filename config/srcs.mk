SRCS= 			pipex.c \
				$(SRCS_UTILS) \
				$(SRCS_PARSING) \
				$(SRCS_HANDLING) \
				$(SRCS_PRINTF) \
				$(SRCS_GNL) \
				$(SRCS_ERRORS)

SRCS_UTILS=		utils/ft_split.c \
				utils/ft_strlen.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strncmp.c \
				utils/ft_substr.c \
				utils/ft_freetab.c \
				utils/ft_strcmp.c

SRCS_PARSING=	parsing/get_paths.c \
				parsing/join_paths.c \
				parsing/params_checking.c

SRCS_HANDLING=	handling/commands_handler.c \
				handling/fd_handler.c

SRCS_ERRORS=	errors/errors.c

SRCS_PRINTF=	ft_printf/ft_printf.c \
				ft_printf/ft_putadr_hex.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_putnbr.c

SRCS_GNL=		get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c