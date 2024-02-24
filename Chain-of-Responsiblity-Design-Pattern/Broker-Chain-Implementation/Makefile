CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++20
BOOST_INCLUDE = -I/opt/homebrew/opt/boost/include
BOOST_LIBDIR = -L/opt/homebrew/opt/boost/lib

SRCDIR = ./
OBJDIR = ~/Desktop/Pranshu/obj
BINDIR = ~/Desktop/Pranshu/bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/my_program

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(BOOST_LIBDIR) $^ -o $@ $(BOOST_LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(BOOST_INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(BINDIR)
