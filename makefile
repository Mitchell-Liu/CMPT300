all: my_userid.c
	gcc -g -Wall -o my_userid my_userid.c
clean:
	$(RM) my_userid