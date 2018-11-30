- [Single Pass Assembler](https://github.com/KTU-CSE/System-Software-lab/tree/master/Process%20Synchronization/Assemblers/Single%20Pass%20Assembler/README.md)
- [Pass 1 of a Two Pass Assembler](https://github.com/KTU-CSE/System-Software-lab/tree/master/Process%20Synchronization/Assemblers/Two%20Pass%20Assembler/Pass%201%20of%20a%20Two%20Pass%20Assembler/README.md)
- [Pass 2 of a Two Pass Assembler](https://github.com/KTU-CSE/System-Software-lab/tree/master/Process%20Synchronization/Assemblers/Two%20Pass%20Assembler/Pass%202%20of%20a%20Two%20Pass%20Assembler/README.md)

# Theory

## Assembly Language
An assembly language is a low-level programming language for a computer, or other programmable device, in which there is a very strong (generally one-to-one) correspondence between the language and the architecture's machine code instructions. Each assembly language is specific to a particular computer architecture, in contrast to most high-level programming languages, which are generally portable across multiple architectures, but require interpreting or compiling.
Assembly language uses a mnemonic to represent each low-level machine operation or opcode. Some op-codes require one or more operands as part of the instruction.

## Assembler
Assembly language is converted into executable machine code by a utility program referred to as an assembler; the conversion process is referred to as assembly, or assembling the code.

![1](http://i.imgur.com/HPjwJOQ.jpg)

An assembler is a translator that translates an assembler program into a conventional machine language program. Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler proceeds to the next instruction. In this way, the entire machine code program is created.

![2](http://i.imgur.com/Mqntp81.jpg)

## Assembler Directives
- Assembler directives are pseudo instructions
    - They will not be translated into machine instructions.
    - They only provide instruction/direction/information to the assembler.
- Basic assembler directives :
    -   **START :**  Specify name and starting address for the program
    -   **END :**    Indicate the end of the source program.
    -   **EQU :**   The EQU directive is used to replace a number by a symbol. For example:                                         MAXIMUM EQU 99.
After using this directive, every appearance of the label “MAXIMUM” in the program will be interpreted by the assembler as the number 99 (MAXIMUM = 99). Symbols may be defined this way only once in the program. The EQU directive is mostly used at the beginning of the program.

## Three Main Data Structures
- Operation Code Table (OPTAB)

- Location Counter (LOCCTR)

- Symbol Table (SYMTAB)

## One-pass assemblers
A one pass assembler passes over the source file exactly once, in the same pass collecting the labels, resolving future references and doing the actual assembly. The difficult part is to resolve future label references (the problem of forward referencing) and assemble code in one pass

![4](http://i.imgur.com/oyn0JCi.png)

### Forward reference in one pass assembler
- Omits the operand address if the symbol has not yet been defined
- Enters this undefined symbol into SYMTAB and indicates that it is undefined
- Adds the address of this operand address to a list of forward references associated with the SYMTAB entry
- When the definition for the symbol is encountered, scans the reference list and inserts the address.
- At the end of the program, reports the error if there are still SYMTAB entries indicated undefined symbols.

## Two-pass assemblers
The two pass assembler performs two passes over the source program. 

In the first pass, it reads the entire source program, looking only for label definitions. All the labels are collected, assigned address, and placed in the symbol table in this pass, no instructions as assembled and at the end the symbol table should contain all the labels defined in the program. To assign address to labels, the assembles maintains a Location Counter (LC).


In the second pass the instructions are again read and are assembled using the symbol table.
Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler proceeds to the next instruction. In this way, the entire machine code program is created. For most instructions this process works fine, for example for instructions that only reference registers, the assembler can compute the machine code easily, since the assembler knows where the registers are.

![5](http://i.imgur.com/XIway7g.jpg)

### Difference between One Pass and Two Pass Assemblers
The difference between one pass and two pass assemblers are:-

A one pass assembler passes over the source file exactly once, in the same pass collecting the labels, resolving future references and doing the actual assembly. The difficult part is to resolve future label references (the problem of forward referencing) and assemble code in one pass. The one pass assembler prepares an intermediate file, which is used as input by the two pass assembler.


A two pass assembler does two passes over the source file (the second pass can be over an intermediate file generated in the first pass of the assembler). In the first pass all it does is looks for label definitions and introduces them in the symbol table (a dynamic table which includes the label name and address for each label in the source program). In the second pass, after the symbol table is complete, it does the actual assembly by translating the operations into machine codes and so on.
