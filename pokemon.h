#ifndef POKEMON_H
#define POKEMON_H

// Maximum lengths for various string fields in the Pokemon data
#define MAX_NAME_LEN 100  // Max characters for Pokemon name
#define MAX_TYPE_LEN 20 // Max characters for Type 1 and Type 2
#define MAX_LINE_LEN 1024 // Max characters for a line in the CSV file
#define MAX_POKEMON 1000 // Max number of Pokemon that can be loaded

// Structure to represent a single Pokemon and its properties
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char type1[MAX_TYPE_LEN];
    char type2[MAX_TYPE_LEN];
    int total;
    int hp;
    int attack;
    int defense;
    int sp_atk;
    int sp_def;
    int speed;
    int generation;
    int legendary; // 0 = False, 1 = True
} Pokemon;

// Global variables declared as extern so they can be shared across multiple files

extern Pokemon *all_pokemon[MAX_POKEMON];
extern int pokemon_num;

extern Pokemon *search_results[MAX_POKEMON];
extern int matched_total;
extern int total_queries;

// Function declarations (prototypes)
void read_pokemon_file(const char *filename_input);
void search_by_type(const char *type);
void save_results_to_file(const char *filename_input);
void free_memory();

#endif
