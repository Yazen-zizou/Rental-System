
#ifndef LOG_LLC_BIBLIO_H
#define LOG_LLC_BIBLIO_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef enum {STUDIO, F2, F3, F4} type_logement_t; //type des logements

#define BUFFER_SIZE 512
#define LOWER 1
#define UPPER 100000

extern char buffer[BUFFER_SIZE];

typedef struct propreties_node { //linked list for houses
    int id;
    type_logement_t typ;
    struct propreties_node* next;
} propreties_t;

propreties_t* next0(propreties_t* ptr);

typedef struct locataire_node { //linked list for locataires
    int id;
    char nom[20];
    char prenom[20];
    char telephone[11];
    propreties_t* houses_head;
    struct locataire_node *next;
} locataire_t;

extern locataire_t *locataire_head;
// machine abstraite pour locataire
locataire_t* allocate1();
void ass_id1(locataire_t* ptr, int n);
void ass_nom1(locataire_t* ptr, char s[20]);
void ass_prenom1(locataire_t* ptr, char s[20]);
void ass_telephone1(locataire_t* ptr, char phone[11]);
void ass_next1(locataire_t* ptr, locataire_t* suivant);
locataire_t* next1(locataire_t* ptr);
int id1(locataire_t* ptr);
char* nom(locataire_t* ptr);
char* prenom(locataire_t* ptr);
char* telephone(locataire_t* ptr);
propreties_t* houses(locataire_t* ptr);

typedef struct logement_node { //linked list for logement
    int id;
    type_logement_t type;
    double superficie;
    char quartier[20];
    char commune[20];
    double distance;
    int loyer;
    bool etat;
    int owner_id;
    struct logement_node *next;
} logement_t;

extern logement_t* archive_logement_head;
//calcul de loyer
int loyer_de_base(type_logement_t type);
int superficie_moyenne(type_logement_t type);
int calcul_loyer(type_logement_t type, double superficie);
extern logement_t *logement_head;

char* to_upper(char* str); //convert to upper case

//machine abstraite pour logement
logement_t* allocate2();
void ass_id2(logement_t* ptr, int n);
void ass_type(logement_t* ptr, type_logement_t typ);
void ass_area(logement_t* ptr, double n);
void ass_owner_id(logement_t* ptr, int id);
void ass_quartier(logement_t* ptr, char s[20]);
void ass_commune(logement_t* ptr, char s[20]);
void ass_distance(logement_t* ptr, double n);
logement_t* next2(logement_t* ptr);
int id2(logement_t* ptr);
type_logement_t type(logement_t* ptr);
double area(logement_t* ptr);
int owner_id(logement_t* ptr);
int loyer(logement_t* ptr);
void ass_loyer(logement_t* ptr);
void ass_etat(logement_t* ptr, bool state);
void ass_next2(logement_t* ptr, logement_t* suivant);
char* quartier(logement_t* ptr);
char* commune(logement_t* ptr);
double distance(logement_t* ptr);
bool etat(logement_t* ptr);

typedef struct location_node { // linked list for location
    long int id;
    long int id_locataire;
    long int id_logement;
    char date_debut[11];
    char date_fin[11];
    int duree;
    int montant;
    struct location_node *next;
} location_t;

extern location_t* archive_location_head;
extern location_t *location_head;
// machine abstraite pour location
location_t* allocate3();
void ass_id3(location_t* ptr, int n);
void ass_id_locataire(location_t* ptr, int n);
void ass_id_logement(location_t* ptr, int n);
void ass_dd(location_t* ptr, char s[11]);
void ass_df(location_t* ptr, char s[11]);
void ass_duree(location_t* ptr, int duration);
void ass_next3(location_t* ptr, location_t* suivant);
void ass_montant(location_t* ptr, int price);
long int id3(location_t* ptr);
long int id_locataire(location_t* ptr);
long int id_logement(location_t* ptr);
char* date_d(location_t* ptr);
char* date_f(location_t* ptr);
int duration(location_t* ptr);
int montant(location_t* ptr);
location_t* next3(location_t* ptr);
//checking date functions
bool check_valid_date(char date[11]);
bool check_date_is_bigger(char date1[11], char date2[11]);
// converting between string and type de logements
type_logement_t str_type(char s[7]);
char* type_str(type_logement_t typ);

int calcul_duree_mois(char date_debut[11], char date_fin[11]);
//merging + sorting functions
logement_t* middle_log(logement_t* head);
logement_t* merge_sorted_log(logement_t* left, logement_t* right, int n);
logement_t* merge_sort_log(logement_t* head, int n);
// function to generate id's
int generate_unique_id(int choice);
//functions to find logements/locataires/locations
logement_t* find_logement(int id);
locataire_t* find_locataire(int id);
location_t* find_location(int id);
locataire_t* find_locataire_by_name(char name[20], char prename[20]);
void ass_house1(locataire_t* ptr, int house_id);
//creation of locataire/logement/location
locataire_t* create_locataire(int id, char name[20], char prename[20], char phone[11], int choice);
logement_t* create_logement(int id, type_logement_t type, double superficie, char quartier[20],
                          char commune[20], double distance, int choice);
location_t* create_location(int id, int id_1, int id_2, char date_debut[11],
                          char date_fin[11], int choice, char date[11]);
//inserting into the linked list
void insert_locataire(locataire_t* ptr);
void insert_logement(logement_t* ptr);
void insert_archive_logement(logement_t* ptr);
void insert_location(location_t* ptr);
void insert_location_archive(location_t* ptr);
//freeing functions
void free_all_houses(locataire_t* ptr);
void free_all_locataires();
void free_all_logements();
void free_all_locations();
void free_all_archived_locations();
void free_all_archived_logements();
//les fichiers
void fichier_locataire();
void fichier_logement();
void fichier_archive_logement();
void fichier_location(char date[11]);
void fichier_archive_location();
//adding
void add_locataire();
void add_logement();
void add_location();
//deletion + removing from linked list
void delete_house(locataire_t* ptr, int house_id);
int have_a_house(locataire_t* ptr);
void delete_locataire(int id);
void delete_logement(int id);
void delete_location(int id);
//archiving from active list to archive list
void archive_locataire();
void archive_logement();
void archive_location();
//display functions
void display(logement_t* ptr);
void display_loctaire(locataire_t* ptr);
void display_location(location_t* ptr);
void display_logmenents();
void display_all_locations();
void display_all_unoccupied_logments();
void display_all_logments();
void display_all_locataires();
//merging + sorting les locations
location_t* middle_location(location_t* head);
location_t* merge_sorted_location(location_t* left, location_t* right, int n);
location_t* merge_sort_location(location_t* head, int n);
//for question number 6
void display_locataires_with_large_same_type();
//also for merging and sorting locations
logement_t* merge_sorted_score(logement_t* left, logement_t* right, double max_loyer, double max_distance);
logement_t* merge_score(logement_t* head, double max_loyer, double max_distance);
//function for question number 7
void find_best_logements();

typedef struct quartier_saver {
    char quartier[20];
    type_logement_t typ;
    int count;
    struct quartier_saver* next;
} quartier_count_t;
//also for qst 7
void location_par_year(char date[11]);
//for main program ( menu and handling stuff)
void clear_screen();
void press_enter_to_continue();
void display_main_menu();
void handle_stats_menu(char date[11]);
bool handle_logement_menu();
bool handle_locataire_menu();
bool handle_location_menu();

#endif // LOG_LLC_BIBLIO_H
