# Log File Analyzer (C)

A simple C program that analyzes a plain-text log file and counts how many lines contain:
- `INFO`
- `WARNING`
- `ERROR`

This project was created to practice core programming fundamentals such as file handling, string parsing, loops, and basic error checking.

---

## Features
- Reads any `.log` or `.txt` file line-by-line  
- Counts occurrences of:
  - INFO
  - WARNING
  - ERROR  
- Accepts filename as a command-line argument **or** prompts user for input  
- Handles invalid file names safely  
- Very small and beginner-friendly

---

## Compilation

Use GCC to compile:

```bash
gcc -Wall -Wextra -o log_analyzer log_analyzer.c
