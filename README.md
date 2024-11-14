
# Custom System Call | Operating Systems Assignment
Developed a Custom System Call as a Mainline Kernel Function to compute determinants of 2x2 matrices in C programming language. 

## Problem Statement - Kernel 2D Memcpy()

### Overview
The Kernel 2D Memcpy() exercise is designed to evaluate your understanding of system calls, particularly focusing on kernel memory copy operations. The task involves implementing a custom system call, `kernel 2d memcpy()`, responsible for copying one 2-D floating-point matrix to another within the kernel space. This exercise assesses your ability to utilize kernel functions such as `copy_from_user()` and `copy_to_user()` to transfer data between user space and kernel space.

### Task Description
You are required to implement the `kernel 2d memcpy()` system call, which mimics the functionality of the standard `memcpy()` operation but relies on the kernel for the copy operations instead of user space. The primary goal is to understand and demonstrate how system calls function within the kernel environment.

### Submission Requirements/Rubric

1. **Kernel Modification Diff:**
   - Provide a diff file showcasing the changes made to the stock kernel to incorporate your custom system call (`kernel 2d memcpy()`).
   - Successful compilation of the patched kernel is crucial, and no partial points will be awarded.

   **Points:** 50

2. **Sample Test Program:**
   - Develop a sample program to test the `kernel 2d memcpy()` system call.
   - Hard-wire the source 2-D matrix in the program; there is no need to take input from the user at runtime or via a file.
   - Ensure the program correctly calls the system call with appropriate parameters, successfully copying the matrix.

   **Points:**
   - Program correctly calls the system call: 10
   - Program compiles successfully, but copying is unsuccessful: 5

3. **README/Write-up:**
   - Provide a README or write-up explaining the logic used in the program to achieve the required functionality.
   - Limit the description to no more than one page.

   **Points:** 5


## Deployment


1) Copy the linux kernel source (stock kernel with the custom config shared earlier) into  another directory (would be used later to generate **Diff** file).

2) In the copied linux kernel directory, open **syscall_64.tbl** under **arch/x86/entry/syscalls** & add this entry -
```bash
451 common hello_system_call sys_hello
```

3) I’ve named my system call as **hello_system_call**, which does the job of copying data from one 2D matrix to another.

4) Next, create another directory named **hello_syscall** in the copied kernel source directory, and add 2 files in it -
```bash
hello_syscall.c
Makefile
```

5) In the Makefile, add the code -
```bash
obj-y := hello_syscall.o
```

6) This will build the **hello_syscall.c** file. Here, **y** refers to **yes**.

7) Now, we’ll open the root of the kernel source (of the copy) and edit the Makefile using **vim** command.

8) At line **1103** add **hello_syscall/** at the end of the command. This builds our system call and gets it linked to the kernel.

9) Now Compilation & installation steps of the kernel -
```bash
make -j$(nproc)
sudo cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linux-5.19.8-special3
sudo make modules_install
sed s/linux/linux-5.19.8-special3/g </etc/mkinitcpio.d/linux.preset >/etc/mkinitcpio.d/linux-5.19.8-special3.preset
mkinitcpio -p linux-5.19.8-special3
grub-mkconfig -o /boot/grub/grub.cfg
```

10) Now we can boot into the new kernel & test the system call by compiling the **demo.c** program using the usual **gcc** command, and then running the generated executable file.


