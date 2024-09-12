#==========================================================================================
INC_DIR=include
SRC_DIR=src
#------------------------------------------------------------------------------------------
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC_FILES))
#------------------------------------------------------------------------------------------
#==========================================================================================

.DEFAULT_GOAL = all

all: setup $(PROGRAM)

# formates the code
.PHONY: fmt
fmt:
	@echo -n "Running formatter... "
	@find . -type f -name "*.c" | xargs clang-format -i
	@find . -type f -name "*.h" | xargs clang-format -i

