# Student Name: Christopher Bell
# Program Name: Basic HTML Parsing and Crawling
# Creation Date: Feb. 22, 2018
# Last Modified Date: Mar. 12, 2018
# CSCI Course: 315
# Grade Received: 100/100

MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
PAGES := $(wildcard pages/*)
CFLAGS=-g -I src/
.PHONY: clean test all
BIN=html-test

all:
	g++ -o $(BIN) $(CFLAGS) ${SRCS} ${MAIN}

run: all
	./$(BIN) $(PAGES)

%test:
	cxxtestgen --runner=ErrorPrinter -o test/test-runner.cpp test/$@.cpp ${SRCS}
	g++ ${CFLAGS} test/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

clean:
	rm -rf $(BIN) test/test-runner.cpp test-runner
