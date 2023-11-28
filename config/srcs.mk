SRCS= 			pipex.c \
				$(SRCS_UTILS) \
				$(SRCS_PARSING) \
				$(SRCS_EXEC) \
				$(SRCS_PRINTF) \
				$(SRCS_ERR)

SRCS_UTILS=		utils/ft_split.c \
				utils/ft_strlen.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strncmp.c \
				utils/ft_substr.c \
				utils/ft_freetab.c

SRCS_PARSING=	parsing/get_paths.c \
				parsing/join_paths.c \
				parsing/params_checking.c

SRCS_EXEC=		exec/commands_handler.c

SRCS_PRINTF=	ft_printf/ft_printf.c \
				ft_printf/ft_putadr_hex.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_putnbr.c

SRCS_ERR=		errors_tools/error.c