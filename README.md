<img width="600" alt="Screenshot 2024-12-04 at 11 44 46 PM" src="https://github.com/user-attachments/assets/12fa5b88-3fd3-423b-931c-2bec71ebd6c6">


# Minishell 🐚

Welcome to **Minishell** — a custom shell program designed to provide a comprehensive hands-on exploration of systems programming and Unix-based shell functionalities!
This project recreates the foundational elements of a shell environment, with features inspired by Bash, allowing you to navigate directories, manage environment variables, execute commands, and handle I/O redirection and piping, all within a streamlined, efficient C-based application.

---

## 🚀 Features

- **Prompt Display**: See a clear, intuitive prompt awaiting your commands.
- **Command History**: Use the up and down arrow keys to recall previous commands.
- **Command Execution**: Supports system executables and built-in commands with variable expansion.
- **Built-in Commands**: Implemented built-ins include `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Redirection**:
  - `<` for input redirection.
  - `>` and `>>` for output redirection (overwrite or append).
  - `<<` for heredoc, reading until a specified delimiter.
- **Pipes**: Chain commands with `|`, directing the output of one command to the input of the next.
- **Environment Variable Expansion**: Expands `$VARIABLE` and `$?` for the exit status of the last command.
- **Signal Handling**: Graceful handling of signals such as `ctrl-C`, `ctrl-D`, and `ctrl-\`.

---

## 🎛️ Installation and Setup

1. **Install Dependencies**:
   ```bash
   sudo apt-get install make libreadline-dev
   ```

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/DigitalPool/42-Minishell.git
   cd 42-Minishell
   ```

3. **Compile the Shell**:
   ```bash
   make
   ```

4. **Run Minishell**:
   ```bash
   ./minishell
   ```

---

## 📜 Built-in Commands

| Command   | Description                                                   |
|-----------|---------------------------------------------------------------|
| `echo`    | Prints arguments to the console. Supports `-n` option.        |
| `cd`      | Changes the current directory. Supports relative and absolute paths. |
| `pwd`     | Prints the current working directory.                         |
| `export`  | Sets environment variables.                                   |
| `unset`   | Unsets environment variables.                                 |
| `env`     | Lists all environment variables.                              |
| `exit`    | Exits the shell with an optional status code.                 |

---

## 📥 Redirections and Pipes

| Symbol | Function                                      |
|--------|-----------------------------------------------|
| `>`    | Redirects output, overwriting the target file. |
| `>>`   | Redirects output in append mode.              |
| `<`    | Redirects input from a file.                  |
| `<<`   | Here-doc mode, reading until a specified delimiter is reached. |
| `|`    | Connects commands, sending output of one to input of the next. |

---

## 🧠 Design Overview

### 1. **Input Parsing**  
   The parser handles spaces, quotes, redirections, pipes, and environment variables, converting input into tokens and checking syntax.

### 2. **Tokenization**  
   Breaks down input into manageable tokens, identifying command names, arguments, redirections, pipes, and more.

### 3. **Abstract Syntax Tree (AST)**  
   Commands, arguments, and I/O redirections are stored in a structured format to allow precise execution.

### 4. **Command Execution**  
   Supports executing built-in commands and external executables, handling pipes and redirection.

### 5. **Signal Management**  
   Interprets `ctrl-C`, `ctrl-D`, and `ctrl-\` signals, maintaining a smooth user experience.

### 6. **Environment Variable Expansion**  
   Dynamically replaces `$VARIABLE` with the correct environment values.

---

## 🛠 Usage and Examples

- **Basic Commands**:
  ```bash
  echo "Hello, Minishell!"
  cd ..
  pwd
  export PATH=/usr/bin
  unset PATH
  env
  exit 0
  ```

- **Pipes and Redirections**:
  ```bash
  ls -l | grep "minishell" > result.txt
  cat < result.txt | wc -l
  ```

- **Environment Variables**:
  ```bash
  echo $USER
  echo "Last exit code: $?"
  ```

---

## 💡 Tips for Development

- **Testing with Bash**: Always compare Minishell's output with Bash to ensure compatibility.
- **Memory Management**: Watch for memory leaks, especially with the `readline` function.
- **Signal Handling**: Mimic Bash behavior for a seamless user experience.
- **Error Handling**: Anticipate invalid input and handle gracefully with informative error messages.

---

## 📂 Project Structure

```plaintext
42-Minishell/
├── includes/          # Header files
├── src/               # Source code files
│   ├── builtins/      # Built-in command implementations
│   ├── parser/        # Tokenizer and parser modules
│   ├── executor/      # Execution logic and AST traversal
│   ├── signals/       # Signal handling modules
│   └── utils/         # Utility functions
├── Makefile           # Build automation
└── README.md          # Project documentation
```

---

## 👨‍💻 Authors

Created by AbdulAzeez Shobajo and Verónica Conesa. If you find any issues, feel free to [open an issue](https://github.com/DigitalPool/42-Minishell/issues).

---

## 🤝 Contributing

Contributions are welcome! Feel free to submit pull requests to improve Minishell further.
