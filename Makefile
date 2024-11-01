
CUR_DIR = $(shell pwd)

CFLAGS = -Wall
CFLAGS += -I/$(CUR_DIR)/include/
CC = g++

all: src/digit.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o digit
