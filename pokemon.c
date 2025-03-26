#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

// Global array to hold all loaded Pokemon pointers
Pokemon *all_pokemon[MAX_POKEMON];
int pokemon_num = 0; // Number of Pokemon loaded total

// Array to hold search results (matched by Type 1)
Pokemon *search_results[MAX_POKEMON];
int matched_total = 0; // Total Pokemon matched for current query
int total_queries = 0; // Total number of successful type queries

// This function reads Pokemon data from a CSV file
void read_pokemon_file(const char *filename_input) {
    FILE *file = fopen(filename_input, "r");
    if (!file) {
        // If file can't be opened, prints an error and return
        printf("Pokemon file is not found. Please enter the name of the file again.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    fgets(line, sizeof(line), file); // Skips header

    // This while loop reads each line and parse Pokemon data
    while (fgets(line, sizeof(line), file)) {
        Pokemon *p = malloc(sizeof(Pokemon)); // Allocates memory for a new Pokemon
        if (!p) break; // It stops if allocation fails

        char legendary_str[10]; // Temporarily stores string for "True"/"False" 

        // Parses CSV values into the Pokemon struct
        sscanf(line, "%d,%99[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%9s",
               &p->id, p->name, p->type1, p->type2, &p->total, &p->hp,
               &p->attack, &p->defense, &p->sp_atk, &p->sp_def,
               &p->speed, &p->generation, legendary_str);
        
        // This converts string "True"/"False" to integer 1/0
        if (strcmp(legendary_str, "True") == 0 || strcmp(legendary_str, "TRUE") == 0)
            p->legendary = 1;
        else
            p->legendary = 0;

        // Stores pointer to Pokemon in global array
        all_pokemon[pokemon_num++] = p;
        // this will stop if we've reached the maximum allowed Pokemon
        if (pokemon_num >= MAX_POKEMON) break;

    }

    fclose(file);
    printf("Loaded %d Pokemon.\n", pokemon_num);
}

// This function is to search Pokemon by their Type 1 (case-insensitive)
void search_by_type(const char *type) {
    matched_total = 0; // Resets result count before search

    // This compares user input with each Pokemon's Type 1
    for (int i = 0; i < pokemon_num; i++) {
        if (strcasecmp(all_pokemon[i]->type1, type) == 0) {
            search_results[matched_total++] = all_pokemon[i];
        }
    }

    // Displays search results or a message if nothing was found
    if (matched_total == 0) {
        printf("No Pokemon found with Type 1 = %s\n", type);
    } else {
        printf("Found %d Pokemon with Type 1 = %s\n", matched_total, type);

        for (int i = 0; i < matched_total; i++) {
            Pokemon *p = search_results[i];
            printf("#%d: %s [%s/%s], HP: %d, Atk: %d, Def: %d\n",
                   p->id, p->name, p->type1, p->type2, p->hp, p->attack, p->defense);
        }

        total_queries++;  // Count successful queries
    }
}

// This function is to save the current search results to a CSV file
void save_results_to_file(const char *filename_input) {
    if (matched_total == 0) {
        // This message will print if no results are available to save
        printf("No results to save. Please run a type search first.\n");
        return;
    }

    FILE *file = fopen(filename_input, "w");
    if (!file) {
        // Handle error if file can't be created
        printf("Unable to create the new file. Please enter the name of the file again.\n");
        return;
    }

    // Write CSV header
    fprintf(file, "#,Name,Type 1,Type 2,Total,HP,Attack,Defense,Sp. Atk,Sp. Def,Speed,Generation,Legendary\n");

    // Write each result
    for (int i = 0; i < matched_total; i++) {
        Pokemon *p = search_results[i];
        fprintf(file, "%d,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%s\n",
                p->id, p->name, p->type1, p->type2, p->total,
                p->hp, p->attack, p->defense, p->sp_atk, p->sp_def,
                p->speed, p->generation, p->legendary ? "True" : "False");
    }

    fclose(file);
    printf("Saved %d results to '%s'\n", matched_total, filename_input);
}

// This function is to free all dynamically allocated Pokemon memory
void free_memory() {
    for (int i = 0; i < pokemon_num; i++) {
        free(all_pokemon[i]);
    }
    printf("[Memory cleaned up]\n");
}
