PROGRAM=forcemath
CC ?= gcc
CXX ?= g++
INSTALL ?= install
RM ?= rm
PREFIX ?= /usr/local
BINDIR ?= bin
CFLAGS ?= -std=gnu2x
CXXFLAGS ?= -std=gnu++23
OPTFLAGS ?= -march=native -mfpmath=sse+387 -O3 -pipe
CFLAGS += $(OPTFLAGS)
CXXFLAGS += $(OPTFLAGS)
SUBDIRS ?= ilogxi

ifdef _WIN32
OBJECT_EXT ?= .obj
EXECUTABLE_EXT ?= .exe
else
OBJECT_EXT ?= .o
EXECUTABLE_EXT ?= 
endif

all: $(PROGRAM) $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $(SUBDIRS)

$(PROGRAM): $(PROGRAM)$(OBJECT_EXT)
	$(CXX) $(CXXFLAGS) -lm -o $(PROGRAM) $(PROGRAM)$(OBJECT_EXT)

$(PROGRAM)$(OBJECT_EXT): $(PROGRAM).c
	$(CXX) $(CXXFLAGS) -c $(PROGRAM).c
clean:
	$(RM) -rf $(PROGRAM)$(OBJECT_EXT) $(PROGRAM)$(EXECUTABLE_EXT)
	$(MAKE) -C $(SUBDIRS) clean

install: $(PROGRAM)
	$(INSTALL) -d $(PREFIX)/$(BINDIR)
	$(INSTALL) -m 755 $(PROGRAM)$(EXECUTABLE_EXT) $(PREFIX)/$(BINDIR)
	$(MAKE) -C $(SUBDIRS) install

uninstall: $(PROGRAM)
	$(RM) -rf $(PREFIX)/$(BINDIR)/$(PROGRAM)$(EXECUTABLE_EXT)
