# 📝 **Get_next_line**

![Screenshot from 2024-12-05 14-52-03](https://github.com/user-attachments/assets/7a87e68c-bc1b-4ae2-8db2-2768041615e0)

## 📚 Overview
**Get_next_line** is a C function designed to read a file or standard input line-by-line. This project is centered around efficient file handling and memory management, providing a robust solution for reading data streams in C.

---

## 🛠 Features
- **Reads Line-by-Line**: Allows reading input from a file or stdin one line at a time, improving memory efficiency for large files.
- **Handles Multiple File Descriptors**: Supports reading from multiple open files simultaneously.
- **Efficient Memory Management**: Properly allocates and frees memory to prevent memory leaks.
- **Buffering**: Utilizes buffer management to ensure efficient reading of data from file streams.

---

## 📝 How It Works
`Get_next_line` reads from a file descriptor and returns a pointer to the next line of input. The function continues reading until it reaches the end of the file or standard input, then returns `NULL`.

### Key Steps:
- **Buffer Allocation**: A buffer is dynamically allocated to store the current line being read.
- **Reading Input**: The `read` function reads input from a file descriptor and appends characters to the buffer until a newline (`'\n'`) is encountered or the end of the file is reached.
- **Memory Management**: Memory is carefully managed using `malloc` and `free` to prevent memory leaks. After each line is processed, the allocated memory is freed to ensure no memory is left behind.

---

## 💡 Inspiration

This project was created to solve the common need for line-by-line reading of files while focusing on efficient memory management. By understanding how to handle memory properly (allocating and freeing memory), I avoided common pitfalls like memory leaks, which are crucial in C programming.

Additionally, the project allowed me to experiment with different buffer sizes, which significantly impacts the performance of reading files, especially large ones.

The project also helped me deepen my understanding of how the read function works, a low-level system call used for file Input/Output, and how to handle dynamic memory allocation to ensure the program runs efficiently and reliably.
