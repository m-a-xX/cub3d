# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 23:18:07 by mavileo           #+#    #+#              #
#    Updated: 2019/11/13 05:09:23 by mavileo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=    ft_atoi.c       \
		ft_bzero.c      \
		ft_calloc.c     \
		ft_isalnum.c    \
		ft_isalpha.c    \
		ft_isascii.c    \
		ft_isdigit.c    \
		ft_isprint.c    \
		ft_itoa.c       \
		ft_memccpy.c    \
		ft_memchr.c     \
		ft_memcmp.c     \
		ft_memcpy.c     \
		ft_memmove.c    \
		ft_memset.c     \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \
		ft_putstr_fd.c  \
		ft_split.c      \
		ft_strchr.c     \
		ft_strdup.c     \
		ft_strjoin.c    \
		ft_strlcat.c    \
		ft_strlcpy.c    \
		ft_strlen.c     \
		ft_strmapi.c    \
		ft_strncmp.c    \
		ft_strnstr.c    \
		ft_strrchr.c    \
		ft_strtrim.c    \
		ft_substr.c     \
		ft_tolower.c    \
		ft_toupper.c    \

BSRC=	ft_lstnew.c       \
		ft_lstsize.c      \
		ft_lstadd_front.c     \
		ft_lstlast.c    \
		ft_lstadd_back.c    \
		ft_lstdelone.c    \
		ft_lstclear.c    \
		ft_lstiter.c    \
		ft_lstmap.c       \
    	ft_atoi.c       \
		ft_bzero.c      \
		ft_calloc.c     \
		ft_isalnum.c    \
		ft_isalpha.c    \
		ft_isascii.c    \
		ft_isdigit.c    \
		ft_isprint.c    \
		ft_itoa.c       \
		ft_memccpy.c    \
		ft_memchr.c     \
		ft_memcmp.c     \
		ft_memcpy.c     \
		ft_memmove.c    \
		ft_memset.c     \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \
		ft_putstr_fd.c  \
		ft_split.c      \
		ft_strchr.c     \
		ft_strdup.c     \
		ft_strjoin.c    \
		ft_strlcat.c    \
		ft_strlcpy.c    \
		ft_strlen.c     \
		ft_strmapi.c    \
		ft_strncmp.c    \
		ft_strnstr.c    \
		ft_strrchr.c    \
		ft_strtrim.c    \
		ft_substr.c     \
		ft_tolower.c    \
		ft_toupper.c    \

NAME= libft.a

OBJETS= ${SRC:.c=.o}

BOBJETS= ${BSRC:.c=.o}

gcc=gcc -Werror -Wall -Wextra

%.o: %.c
	${gcc} -o $@ -c $<

$(NAME):    ${OBJETS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

all: ${NAME}

bonus:	${BOBJETS}
		ar -rc ${NAME} $^
		ranlib ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS}
		rm -f ${BOBJETS}

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re