# Compiler options
CC = g++
LDFLAGS= -Wall
CFLAGS = -Wall -g -c

# Files
PROGRAM = a.exe
FILES = main.cpp

# Folders
SRCDIR = src
OBJDIR = obj

# Extra Variables
SOURCES = $(patsubst %,$(SRCDIR)/%,$(FILES))
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: build archive

build: $(PROGRAM)

archive: Makefile $(PROGRAM)
	tar cvzf archive.tgz ./$(SRCDIR) $(PROGRAM) Makefile

clean: 
	rm -rf ./$(OBJDIR) $(PROGRAM) archive.tgz

.PHONY: all archive build clean

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p ./$(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<
	