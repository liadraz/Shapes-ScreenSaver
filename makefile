# MakeFile Shapes Project

NAME = screenSaver
CLASSES = src/line.cpp src/circle.cpp src/square.cpp src/triangle.cpp src/rectangle.cpp

CC = g++
CPPFLAGS = -I ./include
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g -D_DEBUG

LIB = -Wl,-rpath=. ./lib/libglut_utils.so ./lib/libpoint.a
SOURCE = test/screensaver.cpp src/shape.cpp src/group.cpp
OBJS = screensaver.o shape.o group.o line.o circle.o square.o triangle.o rectangle.o


.PHONY: all rm
all: $(NAME) rm

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(LIB) -o a.out

$(OBJS): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE) $(CLASSES) $(CPPFLAGS)

rm:
	rm *.o