#/**
#* @file makefile
#* @brief
#* @author Vikas.M.K
#* @version 0.1
#* @date 2015-06-11
#*/

CC=gcc

LIBDIR=../../lib
INCLUDE_DIR=../../include
TEST_DIR=.
OBJ_DIR=$(TEST_DIR)/obj

C_FLAGS= -g -pg -I$(INCLUDE_DIR) -I$(LIBDIR)

C_OBJS=$(OBJ_DIR)/float2fixed.o

TEST_OBJS=$(OBJ_DIR)/test.o

LD_FLAGS= -lm
TARGET=testexec

ALL_OBJS=$(C_OBJS) $(TEST_OBJS)

obj_dir:
	mkdir -p $(OBJ_DIR)
all:obj_dir $(ALL_OBJS)
	$(CC) -c $(C_FLAGS) $(LD_FLAGS) $(ALL_OBJS) -o $(TARGET)

clean:
	rm -rf $(OBJ_DIR)
