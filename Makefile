NAME			:= simulation
DEBUG_SUFFIX	:= _debug
RELEASE_SUFFIX	:= _release
DEBUG_OUTPUT	:= $(NAME)$(DEBUG_SUFFIX)
RELEASE_OUTPUT	:= $(NAME)$(RELEASE_SUFFIX)
SRC_EXT			:= .c
SRC_DIR			:= src
SRC				:= $(wildcard $(SRC_DIR)/*$(SRC_EXT))
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -MMD -MP
CFLAGS_DEBUG	:= $(CFLAGS) -g3
CFLAGS_RELEASE	:= $(CFLAGS) -Ofast -DNDEBUG
LDFLAGS			:= -lm
BUILD_DIR		:= .build
OBJ_EXT			:= .o
OBJ_DEBUG		:= $(SRC:$(SRC_DIR)/%$(SRC_EXT)=$(BUILD_DIR)/%$(DEBUG_SUFFIX)$(OBJ_EXT))
OBJ_RELEASE		:= $(SRC:$(SRC_DIR)/%$(SRC_EXT)=$(BUILD_DIR)/%$(RELEASE_SUFFIX)$(OBJ_EXT))
DOXYGEN_DIR		:= doc/doxygen
RUN_ARGS		:= 5

all: $(DEBUG_OUTPUT) $(RELEASE_OUTPUT)

$(DEBUG_OUTPUT): $(OBJ_DEBUG)
	$(CC) $(CFLAGS_DEBUG) $^ -o $@ $(LDFLAGS)

$(RELEASE_OUTPUT): $(OBJ_RELEASE)
	$(CC) $(CFLAGS_RELEASE) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(DEBUG_OUTPUT) $(RELEASE_OUTPUT) $(BUILD_DIR) $(DOXYGEN_DIR) lora.data *.Rout

doc:
	doxygen

re: clean all

run: $(RELEASE_OUTPUT)
	./$< $(RUN_ARGS)

run-gdb: $(DEBUG_OUTPUT)
	gdb --args ./$< $(RUN_ARGS)

run-valgrind: $(DEBUG_OUTPUT)
	valgrind --leak-check=full ./$< $(RUN_ARGS)

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%$(DEBUG_SUFFIX)$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT) | $(BUILD_DIR)
	$(CC) $(CFLAGS_DEBUG) -c $< -o $@

$(BUILD_DIR)/%$(RELEASE_SUFFIX)$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT) | $(BUILD_DIR)
	$(CC) $(CFLAGS_RELEASE) -c $< -o $@

-include $(OBJ:%$(OBJ_EXT)=%.d)

.PHONY: all clean doc re run run-gdb run-valgrind