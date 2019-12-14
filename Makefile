# ********************************************* #
#                                               #
#                      :|||::|||:||||:::||||||  #
#  Makefile            :|::||::|::|:||::::||:|  #
#                      |:|:|:::|::::::|:|:|||:  #
#      |::|:| <|::|:|>                          #
#                                               #
#  C20191213102853 |::|:|                       #
#  U20191213215802 |:||||                       #
#                                               #
# ********************************************* #

all:
	gcc -g -Wall -Werror -Wextra ./main.c -o bibli
	./bibli

soft:
	gcc -g ./main.c -o bibli
	./bibli

deb:	soft
	valgrind ./bibli

clean:
	rm bibli.htm
	rm bibli
