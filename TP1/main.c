#include "LOG_LLC_BIBLIO.h"
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed for ID generation
    srand(time(NULL));

    // Get current date from user
    char date[11];
    do {
        printf("Enter today's date (DD/MM/YYYY): ");
        fgets(date, sizeof(date), stdin);
        date[strcspn(date, "\n")] = '\0';
        if(!check_valid_date(date)) {
            printf("Invalid date format. Please use DD/MM/YYYY.\n");
        }
    } while(!check_valid_date(date));

    // Load data from files
    fichier_locataire();          // Load locataires
    fichier_logement();           // Load logements
    fichier_archive_logement();   // Load archived logements
    fichier_location(date);       // Load active locations
    fichier_archive_location();   // Load archived locations

    int choice;
    bool update = false;

    do {
        if(update) {
            // Reload data if updates were made
            fichier_locataire();
            fichier_logement();
            fichier_archive_logement();
            fichier_location(date);
            fichier_archive_location();
            clear_screen();
            update = false;
        }

        display_main_menu();
        printf("\nEnter your choice (0-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch(choice) {
            case 1: // Logement Management
                update = handle_logement_menu();
                break;

            case 2: // Locataire Management
                update = handle_locataire_menu();
                break;

            case 3: // Location Management
                update = handle_location_menu();
                break;

            case 4: // Statistics and Reports
                handle_stats_menu(date);
                break;

            case 5: // Exit
                printf("\nThank you for using the rental management system!\n");
                break;

            case 0: // Developer Options
                printf("\nDeveloper Options:\n");
                printf("1. Display all logements\n");
                printf("2. Display all locataires\n");
                printf("3. Display all locations\n");
                printf("4. Display archived locations\n");
                printf("Enter choice: ");

                int dev_choice;
                scanf("%d", &dev_choice);
                getchar();

                switch(dev_choice) {
                    case 1:
                        display_all_logments();
                        break;
                    case 2:
                        display_all_locataires();
                        break;
                    case 3:
                        display_all_locations();
                        break;
                    case 4:
                       fichier_archive_location();
                        location_t* loc = archive_location_head;
                        while(loc) {
                            display_location(loc);
                            loc = next3(loc);
                        }
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                press_enter_to_continue();
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                press_enter_to_continue();
        }
    } while(choice != 5);

    // Clean up memory
    free_all_locataires();
    free_all_logements();
    free_all_locations();
    free_all_archived_logements();
    free_all_archived_locations();

    return 0;
}
