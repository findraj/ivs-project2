TARGET = xfindr01_xjoukl00_xkozan01_xolesa00

.PHONY: all clean pack

all: build/src

test:
	cd tests && make -s && ./mathTests.out

build:
	mkdir -p build

build/src: | build
	cd build && cmake .. && make -s

clean:
	rm -rf build
	cd tests && make -s clean

pack: clean $(TARGET) 

$(TARGET):
	@cd .. && cd .. && mkdir -p $(TARGET) > /dev/null
	@cd .. && cd ../$(TARGET) && mkdir -p doc install repo > /dev/null
	@cd .. && cd .. && cp -r ivs-project2 ./$(TARGET)/repo > /dev/null

	@cd .. && cd .. && zip -r $(TARGET).zip $(TARGET) > /dev/null
	@cd .. && cd .. && rm -rf $(TARGET) > /dev/null


run: all
	./build/src

