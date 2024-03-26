---

# Pipex

<img src="png/pipex.png" alt="Pipex Logo" width="100" height="100">

Welcome to my `pipex` project! 🚀 In this journey, I've tackled the recreation of UNIX pipe mechanisms in C programming, simulating the behavior of pipes and redirections. Dive in with me as we explore the power of UNIX mechanisms, bringing to light the intricate dance of data between processes.

---

## About

`pipex` is an enlightening project at 42 Berlin that deepens your understanding of two essential UNIX concepts: Redirections and Pipes. It serves as an introductory project that paves the way for more complex UNIX-based challenges. By implementing this project, not only have I simulated the UNIX pipe mechanism, but I've also gained invaluable insights into how data is efficiently passed between commands.

---

## Mandatory Part

In the heart of this project lies the `pipex` program, which embodies the core functionality of UNIX pipes. This program, when executed, takes four arguments: two file names and two shell commands. It then processes these inputs to mimic the UNIX pipe command:

```
$> < file1 cmd1 | cmd2 > file2
```

This hands-on approach allowed me to closely examine and implement a mechanism I previously only knew in theory, enhancing my comprehension of UNIX systems significantly.

---

## Examples

To illustrate, here are a couple of examples of how `pipex` works in practice, mirroring the behavior of shell commands:

```
$> ./pipex infile "ls -l" "wc -l" outfile
```

This behaves exactly like:

```
$> < infile ls -l | wc -l > outfile
```

And:

```
$> ./pipex infile "grep a1" "wc -w" outfile
```

Mimics:

```
$> < infile grep a1 | wc -w > outfile
```

---

## Requirements

Key to the success of this project are several requirements, including thorough error handling, no memory leaks, and adherence to UNIX command behaviors. By ensuring these criteria were met, I've crafted a robust simulation of pipe functionality.

---

## Usage

Embarking on the `pipex` journey is straightforward:

1. Clone this repository to your local machine.
2. Move into the project directory.
3. Compile the program using `make`.
4. Execute `./pipex` with the desired arguments to simulate the piping of commands between files.

Example:
```bash
./pipex file1 "cmd1" "cmd2" file2
```

---

Through this project, I've not only learned to implement a fundamental UNIX mechanism but also deepened my understanding of the UNIX system itself. Join me in exploring the nuances of redirections and pipes, and how they contribute to the efficiency and flexibility of UNIX systems.
