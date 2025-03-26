#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

// This function is to display the main user menu
void display_menu() {
    printf("\n----- Pokemon Server Menu -----\n");
    printf("1. Type search\n");
    printf("2. Save results\n");
    printf("3. Exit the program\n");
    printf("Choose an option (1-3): ");
}

int main() {
    char filename_input[100]; // Holds the input CSV file name
    int file_loaded = 0; // Flags to indicate if file was successfully loaded

    // Step 1: Keep asking for file until found or user exits
    while (!file_loaded) {
        printf("Enter the name of the Pokemon CSV file (or type 'exit' to quit): ");
        scanf("%99s", filename_input);

        // Exits if user types 'exit'
        if (strcmp(filename_input, "exit") == 0) {
            printf("Exiting program.\n");
            return 0;
        }

        // Attempts to read file; if successful, break the loop
        read_pokemon_file(filename_input);
        if (pokemon_num > 0) {
            file_loaded = 1;
        }
    }

    // Step 2: Display the menu
    int choice;
    char search_type[30]; // Holds user input for type search
    char save_filename[100]; // Holds filename to save results

    while (1) {
        display_menu(); // Prints the menu
        scanf("%d", &choice); // Gets user's menu choice
        getchar(); // consumes newline

        switch (choice) {
            // Option 1: Searchs Pokemon by Type 1
            case 1:
                printf("Enter Pokemon Type 1 (e.g., Fire, Water): ");
                scanf("%29s", search_type);
                search_by_type(search_type);
                break;

            // Option 2: Saves current search results to a file
            case 2:
                printf("Enter the name of the file to save results: ");
                scanf("%99s", save_filename);
                save_results_to_file(save_filename);
                break;

            // Option 3: Exits program and print session summary
	        case 3:
                printf("\n----- Session Summary -----\n");
                printf("Total successful type queries: %d\n", total_queries);
                // If you want to keep track of file names, you can print them here in future
                free_memory(); // Free dynamically allocated memory
                printf("Goodbye!\n");
                return 0;

                default:
                    // Handles invalid menu input
                    printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
