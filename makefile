APPNAME=list
SRCS+= list.c
SRCS+= main.c

all:
	gcc $(SRCS) -o $(APPNAME)
	./list

clean:
	rm -rf $(APPNAME)