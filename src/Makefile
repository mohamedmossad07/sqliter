PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CXXFLAGS = -Wall -I$(PROJECT_ROOT)include
CFLAGS += -O2
SRCS  := $(shell  find $(PROJECT_ROOT) -name "*.cpp")
LEXERS  := $(shell  find $(PROJECT_ROOT) -name "*.l")
LEXERS_CPP := $(LEXERS:%.l=%.cpp)
PARSERS  := $(shell  find $(PROJECT_ROOT) -name "*.y")
PARSERS_CPP := $(PARSERS:%.y=%.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: sqliter
	
sqliter: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROJECT_ROOT)../$@ $^
	$(MAKE) clean
	clear
	@$(PROJECT_ROOT)../$@
%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<
compiler: $(PARSERS_CPP) $(LEXERS_CPP)

$(LEXERS_CPP): $(LEXERS) 
	flex -o $(PROJECT_ROOT)core/compiler/lexer.cpp -i $<		
$(PARSERS_CPP): $(PARSERS) 
	bison  -d -v -o $(PROJECT_ROOT)core/compiler/parser.cpp  $<
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean-all:clean clean-compiler
clean:
	rm -fr $(OBJS) 
clean-compiler:

