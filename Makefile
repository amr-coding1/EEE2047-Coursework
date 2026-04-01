CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g
GLLIB = -lglut -lGLU -lGL

TARGET = logo
BASELINE_DIR = baseline_objs

# Files always built locally
COMMON_SRC = main.cpp command.cpp
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)

# Student-owned source files
STUDENT1_SRC = program.cpp
STUDENT2_SRC = repeat.cpp
STUDENT3_SRC = forward.cpp jump.cpp left.cpp right.cpp

STUDENT1_OBJ = $(STUDENT1_SRC:.cpp=.o)
STUDENT2_OBJ = $(STUDENT2_SRC:.cpp=.o)
STUDENT3_OBJ = $(STUDENT3_SRC:.cpp=.o)

# Baseline object files
STUDENT1_BASELINE_OBJ = $(BASELINE_DIR)/program.o
STUDENT2_BASELINE_OBJ = $(BASELINE_DIR)/repeat.o
STUDENT3_BASELINE_OBJ = $(BASELINE_DIR)/forward.o \
                        $(BASELINE_DIR)/jump.o \
                        $(BASELINE_DIR)/left.o \
                        $(BASELINE_DIR)/right.o

BASELINE_OBJ = $(STUDENT1_BASELINE_OBJ) $(STUDENT2_BASELINE_OBJ) $(STUDENT3_BASELINE_OBJ)

# Full local build
ALL_SRC = $(COMMON_SRC) $(STUDENT1_SRC) $(STUDENT2_SRC) $(STUDENT3_SRC)
ALL_OBJ = $(ALL_SRC:.cpp=.o)

.PHONY: all student1 student2 student3 baseline clean

all: $(TARGET)

$(TARGET): $(ALL_OBJ)
	$(CXX) $(ALL_OBJ) $(GLLIB) -o $(TARGET)

student1: $(COMMON_OBJ) $(STUDENT1_OBJ)
	$(CXX) $(COMMON_OBJ) $(STUDENT1_OBJ) \
	$(STUDENT2_BASELINE_OBJ) $(STUDENT3_BASELINE_OBJ) \
	$(GLLIB) -o $(TARGET)

student2: $(COMMON_OBJ) $(STUDENT2_OBJ)
	$(CXX) $(COMMON_OBJ) $(STUDENT2_OBJ) \
	$(STUDENT1_BASELINE_OBJ) $(STUDENT3_BASELINE_OBJ) \
	$(GLLIB) -o $(TARGET)

student3: $(COMMON_OBJ) $(STUDENT3_OBJ)
	$(CXX) $(COMMON_OBJ) $(STUDENT3_OBJ) \
	$(STUDENT1_BASELINE_OBJ) $(STUDENT2_BASELINE_OBJ) \
	$(GLLIB) -o $(TARGET)

baseline: $(COMMON_OBJ)
	$(CXX) $(COMMON_OBJ) $(BASELINE_OBJ) $(GLLIB) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)