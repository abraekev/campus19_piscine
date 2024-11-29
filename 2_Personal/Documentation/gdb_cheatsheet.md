# GDB Cheatsheet

## Compilation

- **Compile with debugging information**:  
  `gcc -g union.c`  
  (For all C files, include the `-g` flag or add it to the Makefile using GCC as the compiling method)

## Starting GDB

- **Start GDB**:  
  `gdb a.out`

- **In case of core files**:  
  `gdb a.out core`  
  Then use the `backtrace` command to learn how to read the core dump.

- **With argument vectors**:  
  `gdb --args a.out 1 2 3 4`

- **Multiple processes (Minitalk project)**:  
  Start the server first:  
  `./server`  
  Then start GDB for the client:  
  `gdb --args ./client 7132 da`

- **For Minishell**:  
  `gdb --args ./minishell`  
  You can give arguments to GDB itself, for example:  
  `cat t1 | grep a`  
  *(This is entered when readline prompts a `minishell:line`)*

## Layouts

- **Source code layout**:  
  `lay src`  
  *(Use `lay next` for other views)*

## Breakpoints

- **Set a breakpoint at a specific line**:  
  `b 10`  
  *(Sets a breakpoint at line 10)*

- **Set a breakpoint in a specific file at a line number**:  
  `b ft_printf.c:52`

- **Run the program**:  
  `run` or `r`

- **Watch a variable**:  
  `watch i`  
  *(Breaks when the value of variable `i` changes)*

## Stepping

- **Step into a function**:  
  `s`  
  *(Steps into the function or line, entering function calls)*

- **Next step (without going into the function)**:  
  `n`  
  *(Steps over the function or line, does not enter function calls)*

## Printing

- **Print a variable**:  
  `print i`  
  *(Prints the value of `i` at the current step)*

- **Print the size of a variable**:  
  `print sizeof(s_joined_read)`

- **Print using a function**:  
  `print ft_strlen(s_joined_read)`  
  *(You can even use a function in the print statement)*

- **Short print statement**:  
  `p ft_putchar_count_fd`  
  *(Displays the return value of a function)*

## Child Processes

- **Follow child process after fork**:  
  `set follow-fork-mode child`  
  *(This needs to be done before the `fork()` call. It goes into the child process.)*

- **Detach from a child process**:  
  `detach`

- **Attach to a process by PID**:  
  `attach <PID>`  
  *(Use the parent PID displayed by GDB when detaching from the parent)*

- **List processes**:  
  `ps -e | grep minishell`  
  *(Find the process ID for Minishell)*

- **Check the file descriptor table**:  
  `ls -l /proc/<PID>/fd`  
  *(Check if the file descriptor is open or closed)*

- **Check if a file descriptor is closed**:  
  `call fcntl(pipefd[i][1], 1)`  
  *(Returns `0` if open, `-1` if closed)*

- **Call a function inside GDB**:  
  `call show(cmd, data)`  
  *(You can also call external functions like `write(1, "test fd\n", 8)`)*

- **Trace file writes (external tool)**:  
  `strace -e write -f ./minishell`

## Debugging Flow Control

- **Continue execution**:  
  `c`  
  *(Continues the program until the next breakpoint or until it ends)*

- **Finish the current function**:  
  `finish`  
  *(Finishes the current function and returns to the caller)*

- **Delete a breakpoint**:  
  `delete 1`  
  *(Deletes breakpoint 1)*

- **List all breakpoints**:  
  `info b`

## Additional Commands

- **View previous commands**:  
  `Ctrl + P`

- **Copy from GDB**:
  - **Select output**: Shift + Mouse Select
  - **Copy**: Ctrl + Shift + C
  - **Paste**: Ctrl + V
 
## TUI (Text User Interface) Mode

- **Start GDB in TUI mode**:  
  `gdb --tui a.out`

- **Switch to TUI mode** (if already running):  
  `Ctrl + x + a`

- **Layouts**:
  - `Ctrl + x + 2`: Show source code and assembly (split-screen view).
  - `Ctrl + x + o`: Switch between panes.
  - `Ctrl + x + 1`: Exit TUI mode.

- **TUI Commands**:
  - `layout src`: Show source code only.
  - `layout asm`: Show assembly code only.
  - `layout regs`: Show registers.
  - `focus next`: Switch focus between windows.

- **Sync/Refresh TUI window**:  
  `Ctrl + L`  
  *(Redraws and syncs the terminal window)*
