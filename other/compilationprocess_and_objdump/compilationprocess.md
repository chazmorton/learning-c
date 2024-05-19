# Compilation Process

Compiler converts C program into executable, this includes 4 phases:

1. Pre-processing
2. Compilation
3. Assembly
4. Linking


![compilation process](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)


Following command gets all intermediate files in the directory along w/ the executable:
```$gcc -Wall -save-temps filename.c –o filename```

In this folder we have lookatobjectdump.c, which just prints "hello world."

In the process, it gave me *lookatobjectdump.bc*, it gave me *lookatobjectdump.i*, *lookatobjectdump.o*, and it gave me *lookatobjectdump.s*.

1. Pre-processing:
    - Removal of comments
    - Expansion of macros -> Replaces macro definitions with corresponding values using "#define". For example, "#define PI 3.14" will replace every instance of "PI" with 3.14.
    - Expansion of included files -> handles "#include" directives. Inserting contents of specified header files into the program. 
    - Conditional compilation -> Directives like "#ifdef", "#if", "#else", "#endif" allow compiler to compile the code conditionally. Used for debugging or platform-specific code

    The pre-processed output is stored inside *lookatobjectdump.i*

2. Compilation: Next step is to compile *lookatobjectdump.i*, and produce an intermediate file named *lookatobjectdump.s*, which is assembly-level instructions. Involving several sub-steps:
    - Syntax & semantic analysis -> compiler checks syntax (structure) and semantics (meaning) of the code. Essentially ensures that the code adheres to the rules of the language.
    - Optimization -> Compiler may perform optimization to improve performance of the code. Can be at the level of loops, instructions, and data handling
    - Code generation -> Generates assembly for the target machine

3. Assembly: Takes *lookatobjectdump.s* and turns into *lookatobjectdump.o*. Turns the assembly instructions into machine level code (binary format). This object file contains the machine code and is not yet complete because it may have unresolved references to external functions or variables. Machine code only understandable by computers. CPU executes the instructions directly.

4. Linking: All linking of function calls with their definitions. Linker knows where all these functions are implemented. Also adds some extra code to our program which is required when the program starts and ends. We can verify this by using "size lookatobjectdump.o" and "size a.out". We know that the output file increases in size from an object file to an executable file. This is due to the extra code that the linker adds to our program. 
From chatgpt: linker combines one or more object files and libraries into a single executable program. Final output is an executable program. Involves these steps:
    - Symbol resolution -> Linker resolves references to external symbols (functions or variables) by linking them to their definitions
    - Relocation -> Linker adjusts the addresses of the code & data to ensure that they can be loaded into memory correctly
    - Library linking -> includes code from libraries (static or dynamic) if needed

5. (Not part of compilation process) Loading and execution (runtime): This step involves loading the executable into memory and executing it. The OS's loader is responsible for this task, setting up the program's memory and starting execution from the entry point, typically the 'main' function in a C program.  

I also have a .bc file. This is an LLVM bitcode file. An intermediate form of the source code within the LLVM compilatoin framework. Allowing for extensive optimization and analysis before final machine code is generated. 