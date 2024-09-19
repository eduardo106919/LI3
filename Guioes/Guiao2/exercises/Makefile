#========================================================================
CC=gcc
OPTS=
LDFLAGS=-lm
CFLAGS=-Wall -g -Iincludes $(OPTS)
#------------------------------------------------------------------------
BLD_DIR=build
DOC_DIR=docs
INC_DIR=include
SRC_DIR=src
#------------------------------------------------------------------------
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC_FILES))
#------------------------------------------------------------------------
PROGRAM=main
#========================================================================

.DEFAULT_GOAL = all

all: setup $(PROGRAM)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

# creates the build folder, if necessary
.PHONY: setup
setup:
	@mkdir -p $(BLD_DIR)

# cleans the executable and the build directory
.PHONY: clean
clean:
	rm -r $(BLD_DIR)
	rm $(PROGRAM)
