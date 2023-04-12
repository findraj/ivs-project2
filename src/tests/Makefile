# Google Tests

# Compiler settings
CXX=g++
CXXFLAGS=-std=c++14 -Wall -Wextra

# Directories
GTEST_DIR=./googletest
TEST_DIR=.

# Source file
TEST_SRCS=$(TEST_DIR)/mathTests.cpp

# Object file
TEST_OBJS=$(TEST_DIR)/mathTests.o

# Executable name
TEST_EXECUTABLE=mathTests.out

# Include directories
INC=-I$(GTEST_DIR)/googletest/include \
    -I$(GTEST_DIR)/googlemock/include

# Libraries to link
LIBS=$(GTEST_DIR)/build/lib/libgtest.a \
     $(GTEST_DIR)/build/lib/libgtest_main.a \
     $(GTEST_DIR)/build/lib/libgmock.a \
     $(GTEST_DIR)/build/lib/libgmock_main.a

# Targets
all: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(LIBS):
	mkdir -p $(GTEST_DIR)/build
	cd $(GTEST_DIR)/build && cmake .. && make

clean:
	rm -f $(TEST_EXECUTABLE) $(TEST_OBJS)
	rm -rf $(GTEST_DIR)/build
