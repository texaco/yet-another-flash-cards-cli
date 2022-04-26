# file: Makefile
# author: Yassin Achengli <0619883460@uma.es>
# date: 24/04/2022

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, see
# <https://www.gnu.org/licenses/>.

# A Makefile for building and testing with Google Test.
#
# SYNOPSIS:
#
#   make setup  - Setup the devchain. In particular clone google test code.
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# It is safe to say that you need to run "make setup" before to
# continue working with the project.

# All compiled files will go to this folder.
BIN=bin/

# All project related source code will go to this folder.
SRC=src/

# All project related tests source code will go to this folder.
TEST_SRC=tests

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = googletest/googletest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_CPP_ = $(GTEST_DIR)/src/*.cc
GTEST_SRCS_ = $(GTEST_SRCS_CPP_) $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

GTEST_OBJS_ = (patsubst $(GTEST_DIR)%.c,$(BIN)%.o,$(GTEST_SRCS_CPP_))

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.

TESTS_SRC_FILES = $(wildcard $(TEST_SRC)/*.cc)
TESTS_SRC_OBJS = $(patsubst $(TEST_SRC)/%.cc,$(BIN)tests/%.o,$(TESTS_SRC_FILES))
TESTS = $(patsubst $(TEST_SRC)/%.cc,$(BIN)tests/%,$(TESTS_SRC_FILES))

INC_SRC_LIB=-Isrc/include
INC=-Isrc $(INC_SRC_LIB)

# Sources.
SOURCE_FILES=$(wildcard $(SRC)*.c)
SOURCE_LIB_FILES=$(shell find $(SRC)include -type f -name '*.c')

# Objects.
OBJECT_FILES:=$(patsubst $(SRC)%.c,$(BIN)%.o,$(SOURCE_FILES))
OBJECT_LIB_FILES:=$(patsubst $(SRC)%.c,$(BIN)%.o,$(SOURCE_LIB_FILES))

# Main binary.
MAIN=$(BIN)flashcards

# compiler
CC=g++
FLAGS=-std=c++11

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include $(INC_SRC_LIB)

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

all : $(OBJECT_LIB_FILES) $(OBJECT_FILES)
	echo $(OBJECT_FILES) $(OBJECT_LIB_FILES)
	mkdir -p bin/include
	$(CC) -o $(MAIN) $?

$(BIN)%.o : $(SRC)%.c
	@echo "compiling files... $@"
	$(CC) $(FLAGS) -c $< -o $@

# House-keeping build targets.

test : $(TESTS)
	@$(TESTS)

# Builds gtest.a and gtest_main.a.

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

$(BIN)tests/%.test.o : $(TEST_SRC)/%.test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN)tests/%.test : $(BIN)tests/%.test.o gtest_main.a $(OBJECT_LIB_FILES)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

setup:
	git clone https://github.com/google/googletest

.PHONY: clean
clean:
	@echo "removing extra files..."
	@-find . -name *.o -delete
	@-rm bin/flashcards
	@-rm bin/*.ghc
	@-rm -f $(TESTS) *.a *.o
	@echo "done!"
