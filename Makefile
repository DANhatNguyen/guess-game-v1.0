CXX = g++

include_dirs = -Iinc

# General flags
CXXFLAGS = -O2 -Wall $(include_dirs)

# Extra flags that help
# CXXFLAGS += -Wextra -Wpedantic

# If DEBUG is specified, then add debug flags to CXXFLAGS
DEBUG ?= false
ifeq ($(DEBUG), true) 
	CXXFLAGS += -DDEBUG -g
else
	CXXFLAGS += -DNDEBUG
endif

# Enable c++11		
CXXFLAGS += -std=c++11

# Get all source files in src and its subdirectories 
SOURCES := $(wildcard src/**/*.cpp src/*.cpp)

# Get all object files by substituting .cpp by .o
OBJECTS := $(patsubst src/%.cpp, build/%.o, $(SOURCES))

# Header dependencies
# Replace each .o file in $(OBJECTS) with .d
DEPS := $(OBJECTS:.o=.d)

# Executable file name
BIN = guess

# Necessary files and directories for project
FILES = LICENSE README.md
DIRS = bin inc src doc build data

all: bin/$(BIN)

# Compile object files from .cpp files except for main.cpp
objects: $(OBJECTS)

# Generate header dependencies
-include $(DEPS)

# Compile object files 
build/%.o: CXXFLAGS += -c # flag for compiling object libraries
build/%.o: CXXFLAGS += -MP -MMD # flags for generating header dependencies
build/%.o: src/%.cpp
	@echo Building object files...
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo Finished.

# Compile executive file
bin/$(BIN): $(OBJECTS)
	@echo Building executive file...
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo Finished.

# Create necessary directories and files
.PHONY: configure
configure:
	@echo Creating neccessary files and directories...
	@mkdir -p $(DIRS)
	@touch $(FILES)
	@echo Finished.

.PHONY: clean
clean:
	@echo Cleaning unnecessary files...
	@$(RM) build/*.o build/*.d bin/$(BIN)
	@echo Finished.