CXX = g++

include_dirs = -I../inc -Iinc

# General flags
CXXFLAGS = -O2 -Wall $(include_dirs)

# If DEBUG is specified, then add debug flags to CXXFLAGS
DEBUG ?= false
ifeq ($(DEBUG), true) 
	CXXFLAGS += -DDEBUG -g
else
	CXXFLAGS += -DNDEBUG
endif

# Enable C++11
CXXFLAGS += -std=c++11

# Name of file needs to be tested
TEST_NAME ?= example

TARGET = test_$(TEST_NAME)

SOURCES := $(wildcard ../inc/**/*.h ../inc/*.h)

OBJECTS := $(patsubst ../inc/%.h, ../build/%.o, $(SOURCES))

# DEPS := $(OBJECTS:.o:.d)
DIRS = bin inc src data

all: build/$(TARGET).o bin/$(TARGET)

-include build/*.d

build/$(TARGET).o: CXXFLAGS += -c
build/$(TARGET).o: CXXFLAGS += -MP -MMD
build/$(TARGET).o: src/$(TARGET).cpp
	@echo Building object file...
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo Finished.

bin/$(TARGET): $(OBJECTS)
	@echo Building executive file...
	$(CXX) $(CXXFLAGS) $(OBJECTS) build/$(TARGET).o -o $@
	@echo Finished.

.PHONY: configure
configure:
	@echo Creating neccessary directories...
	@mkdir -p $(DIRS)
	@echo Finished.

.PHONY: clean
clean:
	@echo Cleaning...
	@$(RM) build/*.o build/*.d bin/*
	@echo Finished.