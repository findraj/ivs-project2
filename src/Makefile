TARGET = xfindr01_xjoukl00_xkozan01_xolesa00
STDDEV = stddev
CALCULATOR = calculator
DIR = $(notdir $(abspath $(CURDIR)/..))

# Compiler settings
CXX = g++
CXXFLAGS = -g

.PHONY: all clean pack

all: build/calculator profile

profile: build
	@cd build && $(CXX) $(CXXFLAGS) ../standardDeviation.cpp -o $(STDDEV)

test:
	cd tests && make -s && ./mathTests.out
	
build:
	@mkdir -p build

build/calculator: | build
	@which build-essential > /dev/null || (sudo apt-get update && sudo apt install build-essential)
	@which cmake > /dev/null || (sudo apt-get update && sudo apt install cmake)
	@which qtbase5-dev > /dev/null || (sudo apt-get update && sudo apt install qtbase5-dev)
	@cd build && cmake .. && make -s

clean:
	@rm -rf build
	@rm -rf doc
	@cd tests && make -s clean

pack: clean $(TARGET) 

doc:
	@which doxygen > /dev/null || (sudo apt-get update && sudo apt install doxygen)
	@doxygen Doxyfile

$(TARGET):
	@cd .. && cd .. && mkdir -p $(TARGET) > /dev/null
	@cd .. && cd ../$(TARGET) && mkdir -p doc install repo > /dev/null
	@cd .. && cd .. && cp -r $(DIR)/* ./$(TARGET)/repo > /dev/null
	@$(MAKE) doc
	@cd .. && cd .. && cp -r $(DIR)/src/doc/* ./$(TARGET)/doc > /dev/null
	@cd .. && cd .. && cp -r $(DIR)/src/install/*.deb ./$(TARGET)/install > /dev/null
	@cd .. && cd .. && zip -r $(TARGET).zip $(TARGET) > /dev/null
	@cd .. && cd .. && rm -rf $(TARGET) > /dev/null

run: all
	./build/$(CALCULATOR)
