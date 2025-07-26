# Rock-Paper-Scissors Game in C

A terminal-based Rock-Paper-Scissors game written in C.

### 🎮 Features
- Guest mode and authenticated user gameplay
- User login and sign-up system
- Score tracking (saved in `scores.txt`)
- ASCII art display for Rock, Paper, Scissors
- 5-round gameplay per session
- Modular code structure with clear separation of concerns

---

### 🗂️ Project Structure

| File         | Purpose                                         |
|--------------|-------------------------------------------------|
| `main.c`     | Main menu, game entry point                     |
| `play.c`     | Core gameplay logic                             |
| `print.c`    | ASCII art rendering for game moves              |
| `userauth.c` | Login and signup functionality                  |
| `update.c`   | High score read/write via file handling         |
| `rps.h`      | Common header file with struct/function declarations |

---

### 🧪 Compilation

Compile using the following command:
```bash
gcc main.c print.c play.c userauth.c update.c -o main
```

Run the game:
```bash
./main
```

---

### 📂 Data Files

The following files will be created automatically when needed:
- `users.txt` — stores usernames and passwords
- `scores.txt` — stores high scores

These files are ignored from Git tracking via `.gitignore`.

---

### 📋 Sample Game Flow
```
1. Login / Signup / Guest
2. 5 rounds of Rock, Paper, Scissors
3. Track win/loss/draw and score
4. Option to play again or exit
```

---

### 🛡️ License

This project is open-source and free to use or modify.
Attribution appreciated but not required.
