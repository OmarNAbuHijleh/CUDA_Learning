# quality of life improvement over compiling code individually. We can define the tasks in a makefile and run them with commands like "make 01"

# PHONY tells Make that these names represent tasks, not files. Now, if we have a file that shares a name with our task, we still execute the task
.PHONY: 01 01_obj 01_obj_exe_run 02 03 clean

# Define makefile variables. These values get substituted into compiler commands later
GCC = gcc
NVCC = nvcc
CUDA_FLAGS = -arch=sm_86
# NOTE: sm stands for "streaming multiprocessor" and "86" indicates "compute capability 86". It describes the GPU's supported hardware and instructions

# Defines a task "compile 01.c into an executable"
# 01 is the task name from .PHONY and is the target while and 01.c is the prerequisite (a dependency that Make tracks!). The line below it is the command
# make does the following --> checks if 01 exists. If it doesn't, then checks if 01.c prerequisite exits. If it does, or 01.c is newer than 01, runs the command
01: 01.c
	# This command compiles and links into an executable
	@$(GCC) -o 01 01.c # NOTE: "@" tells Make not to print the command itself before executing it

# Defines a task to compile 01.c into an object file
# Because no prerequisite is defined, this runs every time it is invoked.
01_obj:
	# compiles into an object file only. '-c' indicates compile, but do not link.
	@$(GCC) -c 01.c -o 01.o

# Defines a task to link the object file and then run the executable
# Because 01_obj was declared as .PHONY while being a prerequisite, make will run 01_obj first before executing the rest of the tasks below
01_obj_exe_run: 01_obj
	@$(GCC) 01.o -o 01
	@./01

# define a task to compile 02.c
02:
	@$(GCC) -o 02 02.c
# define a task to compile cuda from source
03:
	@$(NVCC) $(CUDA_FLAGS) -o 03_cu 03.cu

# define a task to remove generated files
clean:
	rm -f 01 02 03_cu *.o
