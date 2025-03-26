Pokemon Server Mini Project
========================

Authors: Fahmeda Afrin (0719251), Om Patel (0779666), Simone Micheal (0755045)
Date: 26th March 2025

----

Overview
--------
This is a simple Pokemon Server in C that allows the following operations from the user:
- Load the Pokemon data from a CSV file
- Find Pokemon by Type 1 (i.e., Fire, Water, etc.)
- Save the found Pokemon in a new CSV file
- Print session summary and exit in a safe way

The project demonstrates file input/output (I/O), string parsing, memory allocation, user interface using menus, and error handling in ANSI C.

---

How to Compile
--------------

Compile the program with the following command:

    gcc main.c pokemon.c -o pokemon_server

This generates an executable file `pokemon_server`.

---

How to Run
---------

Run the program from the command line as follows:

  ./pokemon_server

You will be prompted to input the filename of the Pokemon CSV data file. Enter:

    pokemon.csv

If the file does not exist or is invalid, the program will prompt you again or allow you to exit.

Having loaded the file successfully once, a menu will appear with the following commands:
1. Type search
2. Save results
3. Quit program

-----

Features Implemented
--------------------
- File I/O: Reading from and writing to CSV files
- Dynamic memory allocation with `malloc()` 
- Case-insensitive search on Pokemon Type 1 
- Results saving in user-defined CSV file 
- Error handling for non-existent files and saving errors 
- User menu with constant interaction loop 
- Session exit summary with memory clean-up

---

Key Design Decisions
--------------------
- A `Pokemon` struct stores each Pokemon's properties (ID, name, types, stats, etc.).
- `all_pokemon[]` holds all loaded Pokemon, and `search_results[]` holds filtered search results.
- `pokemon_num`, `matched_total`, and `total_queries` maintain respective counts throughout the session.
- `sscanf()` and `fgets()` are used to safely scan CSV data line by line.
- Functions are logically separated into `main.c` (interface) and `pokemon.c` (data manipulation).
- Global variables declared in `pokemon.h` facilitate access across files and enhance code modularity.

---

File List
---------
- `main.c`: Program entry point, user interaction, and menu logic
- `pokemon.c`: Function declarations for file I/O, search, save, and cleanup
- `pokemon.h`: Global definitions and data structures
- `pokemon.csv`: Input data (provided separately)
- `README.txt`: This document

---

Known Limitations
-----------------
- Type 1 search is supported but not Type 2.
- New search replaces old results.
- Saved filenames are not preserved or shown in summary.

---

Credits
 -------
Pokemon and all related trademarks are the property of their respective owners.
This program is solely for educational use and is not affiliated with The Pokémon Company.
