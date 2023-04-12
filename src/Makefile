TARGET = xfindr01_xjoukl00_xkozan01_xolesa00

.PHONY: all clean pack

all: build/src

test:
	cd tests && make && ./mathTests.out

build:
	mkdir -p build

build/src: | build
	cd build && cmake .. && make -s

clean:
	rm -rf build $(TARGET)
	cd tests && make clean

pack: $(TARGET)

$(TARGET): all
	@cd .. && cd .. && mkdir -p $(TARGET) > /dev/null
	@cd .. && cd ../$(TARGET) && mkdir -p doc install repo > /dev/null
	@cd .. && cd .. && cp -r ivs-project2 ./$(TARGET)/repo/ivs-project2 > /dev/null

	@cd .. && cd .. && zip -r $(TARGET).zip $(TARGET) > /dev/null
	@cd .. && cd .. && rm -rf $(TARGET) > /dev/null


run: all
	./build/src

