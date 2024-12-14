# Compiler
CXX = clang++
CXXFLAGS = -O3 \
           -I/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2 \
           -I/opt/homebrew/Cellar/glew/2.2.0_1/include/GL \
           -I/opt/homebrew/Cellar/glm/1.0.1/include/glm \

# Libraries
LDFLAGS = -L/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2 \
          -L/opt/homebrew/Cellar/glew/2.2.0_1/lib -lGLEW \
          -L/opt/homebrew/Cellar/glm/1.0.1/lib -lGLM -framework OpenGL

# Project directories and files
SRC_DIR = Source
INCLUDE_DIR = Header
TARGET = main

# Source files
SRCS = main.cpp $(SRC_DIR)/stb_image.c $(SRC_DIR)/display.cpp \
       $(SRC_DIR)/shader.cpp $(SRC_DIR)/mesh.cpp $(SRC_DIR)/texture.cpp \
			 $(SRC_DIR)/obj_loader.cpp

# Default target to build the executable directly
all: $(TARGET)

# Build the executable directly from the source files
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean target to remove the executable
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
