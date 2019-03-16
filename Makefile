CXX=g++
CXXFLAGS= -std=c++17 -Wall 
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window

csrc = $(wildcard src/*.cpp) 					        \
       $(wildcard src/core/*.cpp) 				        \
       $(wildcard src/core/controllers/*.cpp)           \
       $(wildcard src/core/management/*.cpp)			\
       $(wildcard src/core/object_components/*.cpp)		\
       $(wildcard src/core/storage/*.cpp)

obj = $(csrc:.cpp=.o)

all: EngineX clean

EngineX: $(obj)
	$(CXX) $(CFLAGS)-o $@ $^ $(LDFLAGS)	

clean: 
	rm $(obj)

