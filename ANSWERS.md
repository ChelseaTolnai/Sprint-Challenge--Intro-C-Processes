**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- *Created*: System Call creates a new process which is not yet ready to run 
- *Ready/Waiting*: Process is ready to run and is waiting for an event or for a resource
    - *Ready to Run in Memory*: Ready to run in memory and is waiting for kernel mode to schedule
    - *Ready to Run, Swapped*: Ready to run but no empty memory present 
- *Running:* Process is running
    - *User Running*: Process is running in user mode
    - *Kernel Running*: Process is running in kernel mode.
    - *Preempted*: Process runs from kernel mode to user mode.
- *Stopped/Blocked*: Process has been stopped, usually by receiving a signal.
    - *Asleep in Memory*: Process in memory but is in blocked state
    - *Sleep, Swapped*: Process has been swapped to secondary stage and is at a blocked state
- *Zombie/Terminated*: Process does not exist and is terminated but has not been removed from the process table.

**2. What is a zombie process?**

A zombie process is a process in its terminated state. After a child function has finished execution, it sends an exit status to its parent function. Until the parent function receives and acknowledges the message, the child function remains in the zombie state, meaning it has executed but not exited.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process gets created in a program that has parent-child functions, specifically after a child function has finished execution but has not yet been removed from the process table. The zombie process gets destroyed once the parent function receives and acknowledges the child's exit status which is done by calling wait() on the parent function.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- *Performance*: 
    - Higer performance in terms of execution
    - Reduces to machine code once during the compilation step when being written as opposed to non-compiled langauge which occurs every time they are run
    - Creates faster run-time
- *Optimization*: 
    - Compiling once prior to runtime can allow for more effective optimization
    - Can catch bugs faster and ahead of runtim when compiling code during writting stage
    - Compiles to something closer to the hardware
    - Compiler can transform the code to the most optimal form for a computer