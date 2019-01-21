
all:a.out

SERVER_OBJECTS=sort.o 

INCLUDES=-I.

ifeq "$(debug)" "no"
BUILD_FLAGS=-std=c++11 -Wall -Wextra -Wno-unused-function -Wno-unused-parameter -O2 -fno-strict-aliasing
else
BUILD_FLAGS=-std=c++11 -g -Wall -Wextra -Wno-unused-function -Wno-unused-parameter
endif

%.o:%.cpp
	gcc $(BUILD_FLAGS) $(INCLUDES) -c $< -o $@  

a.out:$(SERVER_OBJECTS)
	gcc $(BUILD_FLAGS) -o a.out $(SERVER_OBJECTS)
    
clean:
	rm -f a.out $(SERVER_OBJECTS)

