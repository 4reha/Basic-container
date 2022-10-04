NAME		= container

SRC		= container.cpp

ROOT_DIR	= ./fake_root

CC		= c++

CFLAGS	= 

all		:	$(NAME)

clean	:
	rm -rf $(NAME)

fclean	: clean
	sudo rm -rf $(ROOT_DIR)/*

re		: fclean	all

debian	: fclean
	sudo tar -xvf rootfs.tar.xz -C $(ROOT_DIR)

ubuntu	: fclean
	sudo tar -xvf ubuntu-base-14.04-core-amd64.tar.gz -C $(ROOT_DIR)

$(NAME)	:	$(SRC)
	sudo find $(ROOT_DIR) -maxdepth 0 -empty -exec tar -xvf rootfs.tar.xz -C {} \;
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.PHONY: all clean fclean re