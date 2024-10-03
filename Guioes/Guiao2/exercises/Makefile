#========================================================================
BLD_DIR=build
DOC_DIR=docs
INC_DIR=includes
SRC_DIR=src
#------------------------------------------------------------------------
CC=gcc
OPTS=
LDFLAGS=-lm
CFLAGS=-Wall -g -I $(INC_DIR) $(OPTS)
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

# determines the complexity of each function in your code
.PHONY: complexity
complexity:
	@echo | pmccabe -v
	@pmccabe $(SRC_DIR)/*.c | sort -nr | awk '{if($$1>5)print}'

# gives advice on how to improve code
.PHONY: check
check:
	@cppcheck -I $(INC_DIR) --enable=all --disable=unusedFunction --suppress=missingIncludeSystem .

# cleans the executable and the build directory
.PHONY: clean
clean:
	rm -r $(BLD_DIR)
	rm $(PROGRAM)
