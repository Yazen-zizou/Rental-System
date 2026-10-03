
#include "LOG_LLC_BIBLIO.h"

char buffer[BUFFER_SIZE];
locataire_t *locataire_head = NULL;
logement_t *logement_head = NULL;
logement_t *archive_logement_head = NULL;
location_t *location_head = NULL;
location_t *archive_location_head = NULL;
propreties_t* next0(propreties_t* ptr){
    return ptr->next;
};
//--------------------------------------------locataire abstract machine----------------------------------------------------//
locataire_t* allocate1(){
    return (locataire_t*)malloc(sizeof(locataire_t));
};

void ass_id1(locataire_t* ptr , int n){
    ptr->id = n;
};
void ass_nom1(locataire_t* ptr  , char s[20]){
    strcpy (ptr->nom, s);
};
void ass_prenom1(locataire_t* ptr  , char s[20]){
    strcpy (ptr->prenom, s);
};
void ass_telephone1(locataire_t* ptr, char phone[11]){
    strcpy(ptr->telephone , phone);
};

void ass_next1(locataire_t* ptr , locataire_t* suivant){
    ptr->next = suivant;
};
locataire_t* next1(locataire_t* ptr){
    return ptr->next;
};

 int id1(locataire_t* ptr){
    return ptr->id;
};

char* nom(locataire_t* ptr){
    return ptr->nom;
};
char* prenom(locataire_t* ptr ){
    return ptr->prenom;
};
char* telephone(locataire_t* ptr){
    return ptr->telephone;
};

propreties_t* houses(locataire_t* ptr){
    return ptr->houses_head;
};
//-------------------------------------------------calcul de loyer -----------------------------------------------------------

int loyer_de_base(type_logement_t type){
    switch(type){
        case STUDIO:
            return 15000;
        case F2:
            return 20000;
        case F3:
            return 30000;
        case F4:
            return 45000;
    }
};

int superficie_moyenne(type_logement_t type){
    switch(type){
        case STUDIO:
            return 20;
        case F2:
            return 45;
        case F3:
            return 65;
        case F4:
            return 85;
    }
};

int calcul_loyer(type_logement_t type ,double superficie){
    int loyer = loyer_de_base(type);
    int superficie_moy = superficie_moyenne(type);
    if(superficie > superficie_moy){
        loyer += (superficie - superficie_moy) * 800;
    }
    return loyer;
};

// convert to upper case
char* to_upper(char* str){
        for (int i = 0; i < strlen(str); i++) {
            str[i] = toupper(str[i]);
        }
        return str; // Returning the same modified string
};
// ---------------------------------------------------logement abstract machine----------------------------------------------------//logement_t* allocate2(){
    return (logement_t*)malloc(sizeof(logement_t));
};

void ass_id2(logement_t* ptr , int n){
    ptr->id = n;
};

void ass_type(logement_t* ptr , type_logement_t typ){
    ptr->type = typ;
};
void ass_area(logement_t* ptr  , double n ){
    ptr->superficie =  n;
};

void ass_owner_id(logement_t* ptr , int id){
    ptr->owner_id = id;
}
void ass_quartier(logement_t* ptr  , char s[20]){
    strcpy (ptr->quartier, s);
};
void ass_commune(logement_t* ptr, char s[20]){
    strcpy(ptr->commune , s);
};
void ass_distance(logement_t* ptr , double n  ){
   ptr->distance = n;
};

logement_t* next2(logement_t* ptr){
    return ptr->next;
};

int id2(logement_t* ptr){
    return ptr->id;
};

type_logement_t type(logement_t* ptr){
    return ptr->type;
};

double area(logement_t* ptr){
    return ptr->superficie;
};

int owner_id(logement_t* ptr){
    return ptr->owner_id;
};
int loyer(logement_t* ptr){
    return ptr->loyer;
};

void ass_loyer(logement_t* ptr){
   ptr->loyer = calcul_loyer(type(ptr) ,area(ptr));
};

void ass_etat(logement_t* ptr , bool state){  // true means occupied
    ptr->etat = state;
};
void ass_next2(logement_t* ptr , logement_t* suivant){
    ptr->next = suivant;
};


char* quartier(logement_t* ptr){
    return ptr->quartier;
};

char* commune(logement_t* ptr){
    return ptr->commune;
};

double distance(logement_t* ptr){
    return ptr->distance;
};

bool etat(logement_t* ptr ){
    return ptr->etat;
};

//---------------------------------------LOCATION ET SA MACHINE ABSTRAITE -----------------------------------------------------
location_t* allocate3(){
    return (location_t*)malloc(sizeof(location_t));
};

void ass_id3(location_t* ptr , int n){
    ptr->id = n;
};

void ass_id_locataire(location_t* ptr , int n){
    ptr->id_locataire = n;
};

void ass_id_logement(location_t* ptr ,  int n){
    ptr->id_logement = n;
};

void ass_dd(location_t* ptr, char s[11]){ // date debut
    strcpy(ptr->date_debut , s);
};

void ass_df(location_t* ptr, char s[11]){ // date fin
    strcpy(ptr->date_fin , s);
};

void ass_duree(location_t* ptr, int duration){
    ptr->duree = duration;
};

void ass_next3(location_t* ptr , location_t* suivant){
    ptr->next = suivant;
};

void ass_montant(location_t* ptr , int price){
    ptr->montant=price;
}

long int id3(location_t* ptr){
    return ptr->id;
};

long int id_locataire(location_t* ptr){
    return ptr->id_locataire;
};
long int id_logement(location_t* ptr){
    return ptr->id_logement;
};

char* date_d(location_t* ptr ){
    return ptr->date_debut;
};
char* date_f(location_t* ptr){
    return ptr->date_fin;
};

int duration(location_t* ptr){
    return ptr->duree;
};

int montant(location_t* ptr){
    return ptr->montant;
};

location_t* next3(location_t* ptr){
    return ptr->next;
};
//--------------------------------------------------------CHECKIGN DATE FUNCTIONS------------------------------------------------------------------//
bool check_valid_date(char date[11]) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        return false;
    }
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1000 || year > 9999) return false;
    return true;
}

bool check_date_is_bigger(char date1[11], char date2[11]) {
    int day1, month1, year1;
    int day2, month2, year2;
    sscanf(date1, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(date2, "%d/%d/%d", &day2, &month2, &year2);
    if (year1 > year2) return true;
    if (year1 < year2) return false;
    if (month1 > month2) return true;
    if (month1 < month2) return false;
    return (day1 > day2);
}


//----------------------------------------------------------------------------------------------------------------------//


// treats a string to return a type
type_logement_t str_type(char s[7]){
    if(strcmp("STUDIO" ,  to_upper(s))== 0) {
        return STUDIO;
    }
    else if(strcmp("F2" , to_upper(s))== 0) {
        return F2;
    }
    else if(strcmp("F3" ,  to_upper(s))== 0) {
        return F3;
    }
    else if(strcmp("F4" ,  to_upper(s))== 0) {
        return F4;
    }
    else{
    return -1;
    };
};

//convert type to string
char* type_str(type_logement_t typ){ 
    if(typ == STUDIO){return "STUDIO";}
    if(typ == F2){return "F2";}
    if(typ == F3){return "F3";}
    if(typ == F4){return "F4";}
};

// to calculate the duration of location
int calcul_duree_mois(char date_debut[11], char date_fin[11]){//            DD/MM/YYYY   it is a string 
    int jour_debut = (date_debut[0] - '0') * 10 + (date_debut[1] - '0'); // 0123456789   we do -"0" because "1" is an ascii code so minus the ascii code of "0" returns its true integer value.
    int mois_debut = (date_debut[3] - '0') * 10 + (date_debut[4] - '0');
    int annee_debut = (date_debut[6] - '0') * 1000 + (date_debut[7] - '0') * 100 + (date_debut[8] - '0') * 10 + (date_debut[9] - '0');

    int jour_fin = (date_fin[0] - '0') * 10 + (date_fin[1] - '0');
    int mois_fin = (date_fin[3] - '0') * 10 + (date_fin[4] - '0');
    int annee_fin = (date_fin[6] - '0') * 1000 + (date_fin[7] - '0') * 100 + (date_fin[8] - '0') * 10 + (date_fin[9] - '0');

    int duree = (annee_fin - annee_debut) * 12 + (mois_fin - mois_debut);

    if(jour_fin < jour_debut){
        duree--;
    }
    return duree;
};
//-----------------------------------------------TRIE DE LOGEMENTS---------------------------------------------------------//

//we used merge sort because it is more efficient than divising the linked list into 4 linked lists then sorting them , then merging them into the original linked list.
logement_t* middle_log(logement_t* head ){
    logement_t* prev =NULL;
    logement_t* fast = head;
    logement_t* slow = head;

    if ( (head ==NULL) || (next2(head) == NULL)){
        return head;
    };
    while((fast != NULL) && (next2(fast) != NULL)){
        prev = slow;
        slow = next2(slow);
        fast = next2(next2(fast));
    };
    return prev;  //you should assign to the left next2(prev)
};

logement_t* merge_sorted_log(logement_t* left , logement_t* right , int n){
    logement_t* result;
    switch(n){
        case 1:  // sort by type
        if(left == NULL){return right;}
        if(right == NULL){return left;}
        if( type(left)> type(right)){
            result  = left;
            ass_next2(result  , merge_sorted_log(next2(left), right , n));
        }
        else{
            result  = right;
            ass_next2(result  , merge_sorted_log(left, next2(right) , n));
        };
        return result;
        break;
        case 2:  // sort by price
        if(left == NULL){return right;}
        if(right == NULL){return left;}
        if( loyer(left) < loyer(right)){
            result  = left;
            ass_next2(result  , merge_sorted_log(next2(left), right , n));
        }
        else{
            result  = right;
            ass_next2(result  , merge_sorted_log(left, next2(right) , n));
        };
        return result;
        break;
        case 3:  // sort by price and type
        if(left == NULL){return right;}
        if(right == NULL){return left;}
        if( (type(left) == type(right) )&&(loyer(left)< loyer(right))){
            result  = left;
            ass_next2(result  , merge_sorted_log(next2(left), right , n));
        }
        else if(type(left)<type(right)){
            result  = left;
            ass_next2(result  , merge_sorted_log(next2(left), right , n));
        }
        else{
            result = right;
            ass_next2(result  , merge_sorted_log(left, next2(right) , n));
        };
        return result;
        break;
        case 4: // sort by distance
        {
            if(left == NULL){return right;}
            if(right == NULL){return left;}
            if( distance(left) < distance(right)){
                result  = left;
                ass_next2(result  , merge_sorted_log(next2(left), right , n));
            }
            else{
                result  = right;
                ass_next2(result  , merge_sorted_log(left, next2(right) , n));
            };
            return result;
            break;
        }

        default:
        printf("invalid choice");
        break;
    }
}
logement_t* merge_sort_log(logement_t* head , int n){
    if((head == NULL)|| next2(head)==NULL){
        return head;
    }
    logement_t* middle = middle_log(head);
    logement_t* right = next2(middle);
    ass_next2(middle , NULL);

    logement_t* left_sorted = merge_sort_log(head,n);
    logement_t* right_sorted = merge_sort_log(right,n);

    return (merge_sorted_log(left_sorted , right_sorted , n));
};

//------------------------------------------------ID GENERATION----------------------------------------------------------------------//


 int generate_unique_id(int choice) { //function to generate an id : for logement(1) , locataire(2) , location(3)
    int newid;
    int unique;
    switch( choice ){
      case 1 :{
      logement_t* head = logement_head;
      if(head == NULL){return 1;}
      do {
        newid=(rand() % (UPPER - LOWER + 1)) + LOWER;
        unique=1; //we assume its unique
        //now we check if its unique
        while (head != NULL) {
            if (id2(head) == newid) {
                unique = 0; //its duplicate so we regenrate
            }
            head = next2(head);
        }
        } while (!unique);
        return newid;
        }

        case 2 :{
        locataire_t* head = locataire_head;
        if(head == NULL){return 1;}
        do {
            newid=(rand() % (UPPER - LOWER + 1)) + LOWER;
            unique=1; //we assume its unique
            //now we check if its unique
            while (head != NULL) {
                if (id1(head) == newid) {
                    unique = 0; //its duplicate so we regenrate
                }
                head = next1(head);
            }
        } while ((!unique));
        return newid;
        }
        case 3 :{
        location_t* head = location_head;
        if(head == NULL){return 1;}
        do {
            newid=(rand() % (UPPER - LOWER + 1)) + LOWER;
            unique=1; //we assume its unique
            //now we check if its unique
            while (head != NULL) {
                if (id3(head) == newid) {
                    unique = 0; //its duplicate so we regenrate
                }
                head = next3(head);
            }
        } while ((!unique));
        return newid;
        }

        default:
        printf("Error in choice");
        return -1;
    }

}

//-------------------------------------------------FIND BY ID-----------------------------------------------------------------//

logement_t* find_logement(int id) {
    logement_t* head = logement_head;
    logement_t* head2 =archive_logement_head;
    bool found = false;
    while(head && !found ) {
        if (id2(head) == id) {
            found = true;
            return head;
        }
        head = next2(head);
    }
    if (head ==NULL){
        while(head2 && !found){
            if (id2(head2) == id) {
                found = true;
                return head2;
            }
            head2 = next2(head2);
        }
    }

    printf("logement not found\n");
    return NULL;
}
locataire_t* find_locataire(int id){
    locataire_t* head =locataire_head;
    while(head !=NULL) {
        if (id1(head)==id) {return head;}
        head=next1(head);
    }
    return NULL;
}
location_t* find_location(int id){
    location_t* head =location_head;
    while(head !=NULL) {
        if (id3(head)==id) {return head;}
        head=next3(head);
    }
    printf("location not found");

}

//------------------------------------------FIND BY NAME-------------------------------------------------------------------------//

locataire_t* find_locataire_by_name(char name[20] , char prename[20]){
    locataire_t* head =locataire_head;
    while(head !=NULL) {
        if ((strcmp(to_upper(nom(head)),to_upper(name))==0)&& (strcmp(to_upper(prenom(head)),to_upper(prename))) == 0) {return head;}
        head=next1(head);
    }
    printf("locataire not found");
    return NULL;
}

//assign to locataire the house of id 
void ass_house1(locataire_t* ptr, int house_id) {
    if (ptr == NULL) {
        return;
    }
    propreties_t* temp = (propreties_t*)malloc(sizeof(propreties_t));
    if (temp == NULL) {
        printf("memory allocation fail.\n");
        return;
    }
    temp->id = house_id;
    temp->typ = type(find_logement(house_id));
    temp->next = NULL;
    if (ptr->houses_head == NULL) {
        ptr->houses_head = temp;
    } else {
        temp->next = ptr->houses_head;
        ptr->houses_head = temp;
    }
}




//------------------------------------------CREATION OF NODES---------------------------------------------------------------------//

locataire_t* create_locataire(int id , char name[20] , char prename[20] , char phone[11], int choice ){ // 1 when reading  from file
        locataire_t* temp = allocate1();
        if(temp==NULL){
            printf("Error in allocation");
            return NULL;
        }
        ass_id1(temp, (choice == 0) ? generate_unique_id(2) : id); // choice == 1  means reading from file , 0 means manual
        ass_nom1(temp , name);
        ass_prenom1(temp, prename);
        ass_telephone1(temp , phone);
        ass_next1(temp,NULL);
        temp->houses_head = NULL;
        return temp;
    }


logement_t* create_logement(int id, type_logement_t type,double superficie, char quartier[20], char commune[20],double distance,int choice){
        logement_t* temp = allocate2();
        if(temp==NULL){
            printf("eroor in alocation");
            return NULL;
        }
        ass_id2(temp, (choice == 0) ? generate_unique_id(1) : id); // choice == 1  means reading from file , 0 means manual
         ass_type(temp,type);
        ass_area(temp,superficie);
        ass_quartier(temp,quartier);
        ass_commune(temp,commune);
         ass_distance(temp,distance);
        ass_loyer(temp);
        ass_owner_id(temp ,-1);
        ass_etat(temp , false);
         ass_next2(temp , NULL);
         return temp;

}

location_t* create_location(int id, int id_1, int id_2, char date_debut[11], char date_fin[11], int choice ,char date[11]) {
    location_t* temp = allocate3();
    bool assign;
    assign= check_date_is_bigger(date_fin , date); // to check if the location didn't end yet when reading from file.
    if(temp == NULL) {
        printf("error in allocation\n");
        return NULL;
    }
    logement_t* logement = find_logement(id_2);
    locataire_t* locataire = find_locataire(id_1);
    if(logement == NULL || locataire == NULL) {
        printf("error: logement or locataire not found\n");
        free(temp);
        return NULL;
    }
    ass_id3(temp, (choice == 0) ? generate_unique_id(3) : id);  // choice == 1  means reading from file , 0 means manual
    ass_id_locataire(temp, id_1);
    ass_id_logement(temp, id_2);
    ass_dd(temp, date_debut);
    ass_df(temp, date_fin);
    ass_duree(temp,calcul_duree_mois(date_debut, date_fin));
    ass_montant(temp, (loyer(logement) * calcul_duree_mois(date_debut, date_fin)));
    if(assign){
        ass_etat(logement, true);
        ass_owner_id(logement, id_1);
        ass_house1(locataire, id_2);
    }
    ass_next3(temp, NULL);

    return temp;
}
//-------------------------------------------INSERT INTO LINKED LIST -------------------------------------------------------

// we are inserting at the head of the linked lists .

void insert_locataire(locataire_t* ptr){ 
    if(ptr ==NULL){return;}
    if (locataire_head == NULL){
        locataire_head = ptr;
        return;
    }
    ass_next1(ptr , locataire_head);
    locataire_head = ptr;
    return;

};


void insert_logement(logement_t* ptr){
    if(ptr == NULL){return;}
    if (logement_head == NULL){
        logement_head=ptr;
        return;
    }
    ass_next2(ptr , logement_head);
    logement_head = ptr;

}

void insert_archive_logement(logement_t* ptr){
    if(ptr == NULL){return;}
    if (archive_logement_head == NULL){
        archive_logement_head=ptr;
        return;
    }
    ass_next2(ptr , archive_logement_head);
    archive_logement_head = ptr;

}
void insert_location(location_t* ptr){
    if(ptr==NULL) {return;}
    if (location_head == NULL){
        location_head = ptr;
        return;
    }
    ass_next3(ptr , location_head);
    location_head = ptr;

}

void insert_location_archive(location_t* ptr){
    if(ptr==NULL) {return;}
    if (archive_location_head == NULL){
        archive_location_head = ptr;
        return;
    }
    ass_next3(ptr , archive_location_head);
    archive_location_head = ptr;
}
//-------------------------------------------------FREE LISTS------------------------------------------------------------------//
//free all houses from memory
void free_all_houses(locataire_t* ptr) {
    if (ptr == NULL) {
        printf("error!\n");
        return;
    }

    if (ptr->houses_head == NULL) {
        printf("ce locataire n'a pas de logements.\n");
        return;
    }

    propreties_t* temp = ptr->houses_head;
    logement_t* log;
    while (temp) {
        propreties_t* next = temp->next;
        log = find_logement(temp->id);
        ass_owner_id(log , -1);// to free the house
        free(temp);
        temp = next;
    }
    ptr->houses_head = NULL;
}
// Free all locataires from memory
void free_all_locataires() {
    locataire_t* current = locataire_head;
    while (current != NULL) {
        locataire_t* next = next1(current);
        // Free the houses/properties list first
        free_all_houses(current);
        free(current);
        current = next;
    }
    locataire_head = NULL;
}

// Free all logements from memory
void free_all_logements() {
    logement_t* current = logement_head;
    while (current != NULL) {
        logement_t* next = next2(current);
        free(current);
        current = next;
    }
    logement_head = NULL;
}

// Free all locations from memory
void free_all_locations() {
    location_t* current = location_head;
    while (current != NULL) {
        location_t* next = next3(current);
        free(current);
        current = next;
    }
    location_head = NULL;
}

// Free all archived locations from memory
void free_all_archived_locations() {
    location_t* current = archive_location_head;
    while (current != NULL) {
        location_t* next = next3(current);
        free(current);
        current = next;
    }
    archive_location_head = NULL;
}

// Free all archived logements from memory
void free_all_archived_logements() {
    logement_t* current = archive_logement_head;
    while (current != NULL) {
        logement_t* next = next2(current);
        free(current);
        current = next;
    }
    archive_logement_head = NULL;
}
//-----------------------------------------LECTUER DES FICHIERS----------------------------------------------------------//

void fichier_locataire(){
    free_all_locataires();
    FILE* fichier=fopen("Locataire.txt","r");
    if (fichier == NULL){
        printf(" File dosen't exist, creating file ....");
        fichier = fopen("Locataire.txt","w");
        fclose(fichier);
        return;
    }
    while(fgets(buffer,BUFFER_SIZE,fichier)!= NULL){  // reading file line by line.
        if(buffer[0] =='\n'){
            continue; // skipping empty lines .
        }
        buffer[strcspn(buffer,"\n")] = '\0';  // replacing last character with null terminator to avoid problems
        int id;
        char name_buffer[20],prename_buffer[20],phone_buffer[20];
        int count = sscanf(buffer, "id:%d,nom:%19[^,],prenom:%19[^,],telephone:%10s", &id, name_buffer, prename_buffer, phone_buffer);
        if (count == 4){
            printf("scanned\n");
        }
        else{
            printf("problem\n"); //skip lines that are not compatible with what we want 
        }

        insert_locataire( create_locataire(id ,name_buffer , prename_buffer , phone_buffer ,1)); //insert into linked list
    }
    fclose(fichier);
}


void fichier_logement(){
    free_all_logements();
    FILE* fichier=fopen("Logement.txt", "r");
    if (fichier == NULL) {
    printf("File does not exist, creating file ....");
    fichier = fopen("Logement.txt", "w");
    fclose(fichier);
    return;
    }
    while(fgets(buffer,BUFFER_SIZE,fichier) != NULL){
    if(buffer[0] == '\n'){
        continue;
    }
    int id;
    char typ[7];
    double area;
    char quar[20];
    char comm[20];
    double dist;
    sscanf(buffer, "id:%d,type:%7[^,],superficie:%lf,quartier:%19[^,],commune:%19[^,],distance:%lf", &id , typ , &area , quar , comm ,&dist);
    insert_logement(create_logement(id , str_type(typ), area ,quar ,comm ,dist ,1));
    }
    fclose(fichier);
}
void fichier_archive_logement(){ //same thing as fichier logement
    free_all_archived_logements();
    FILE* fichier=fopen("Logement.txt", "r");
    if (fichier == NULL) {
    printf("File does not exist, creating file ....");
    fichier = fopen("Logement.txt", "w");
    fclose(fichier);
    return;
    }
    while(fgets(buffer,BUFFER_SIZE,fichier) != NULL){
    if(buffer[0] == '\n'){
        continue;
    }
    int id;
    char typ[7];
    double area;
    char quar[20];
    char comm[20];
    double dist;
    sscanf(buffer, "id:%d,type:%7[^,],superficie:%lf,quartier:%19[^,],commune:%19[^,],distance:%lf", &id , typ , &area , quar , comm ,&dist);
    insert_archive_logement(create_logement(id , str_type(typ), area ,quar ,comm ,dist ,1));
    }
    fclose(fichier);
}

void fichier_location(char date[11]) { //
    free_all_locations();
    FILE* fichier = fopen("Location.txt", "r");
    if (fichier == NULL) {
        printf("File does not exist, creating file .....\n");
        fichier = fopen("Location.txt", "w");
        fclose(fichier);
        return;
    }
    while (fgets(buffer, BUFFER_SIZE, fichier) != NULL) {
        if (buffer[0] == '\n') continue;

        int id, id_1, id_2;
        char date_debut[11], date_fin[11];

        if (sscanf(buffer, "id:%d,id_locataire:%d,id_logement:%d,date_debut:%10[^,],date_fin:%10[^\n]",&id, &id_1, &id_2, date_debut, date_fin) != 5) {// != 5 means it didn't scan 5 elements so we skip
            printf("Skipping malformed line: %s", buffer);
            continue;
        }
        // verification of existence of locataire and logement
        if (find_logement(id_2) == NULL) {
            printf("Skipping location %d - logement %d not found\n", id, id_2);
            continue;
        }
        if (find_locataire(id_1) == NULL) {
            printf("Skipping location %d - locataire %d not found\n", id, id_1);
            continue;
        }
        location_t* new_location = create_location(id, id_1, id_2, date_debut, date_fin, 1, date);
        if (new_location) {
            insert_location(new_location);
        }
    }
    fclose(fichier);
}
void fichier_archive_location() { //same thing as fichier location
    free_all_archived_locations();
    FILE* fichier = fopen("Archive_Location.txt", "r");
    if (fichier == NULL) {
        printf("File does not exist, creating file .....\n");
        fichier = fopen("Archive_Location.txt", "w");
        fclose(fichier);
        return;
    }
    while (fgets(buffer, BUFFER_SIZE, fichier) != NULL) {
        if (buffer[0] == '\n') continue;

        int id, id_1, id_2;
        char date_debut[11], date_fin[11];

        if (sscanf(buffer, "id:%d,id_locataire:%d,id_logement:%d,date_debut:%10[^,],date_fin:%10[^\n]", &id, &id_1, &id_2, date_debut, date_fin) != 5) { // != 5 means it didn't scan 5 elements so we skip
            continue;
        }
        // verification of existence of locataire and logement if not we skip
        if (find_logement(id_2) == NULL) {
            continue;
        }
        if (find_locataire(id_1) == NULL) {
            continue;
        }
        location_t* new_location = create_location(id, id_1, id_2, date_debut, date_fin, 1, "31/12/9999");
        if (new_location) {
            insert_location_archive(new_location);
        }
    }
    fclose(fichier);
}

//----------------------------------------L'ECRITURE DES FICHIER-----------------------------------------------------------------

void add_locataire() {
    FILE *fichier = fopen("Locataire.txt", "a");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }


    fseek(fichier, 0, SEEK_END);// if there is not a \n we add it so we won't face problems
    if (ftell(fichier) > 0) {
        fseek(fichier, -1, SEEK_END); // go to the end of file,
        if (fgetc(fichier) != '\n') {
            fputc('\n', fichier);
        }
    }

    locataire_t *temp = allocate1();
    ass_id1(temp, generate_unique_id(2));

    printf("Entrez le nom du locataire: ");
    char str[20];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    ass_nom1(temp, str);

    printf("Entrez le prenom du locataire: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    ass_prenom1(temp, str);

    printf("Entrez le numero de telephone du locataire: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    ass_telephone1(temp, str);

    ass_next1(temp, NULL);


    fprintf(fichier, "id:%d,nom:%s,prenom:%s,telephone:%s\n", id1(temp), temp->nom, temp->prenom, temp->telephone); //printing into file .

    fflush(fichier);  // Ensure all data is written (forced)
    fclose(fichier);

    insert_locataire(temp);
}

void add_logement(){
    FILE *fichier = fopen("Logement.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    fseek(fichier, 0, SEEK_END); // move to the end of the file
    long fileSize = ftell(fichier); // check if the file is empty

    if (fileSize > 0) {
        // move to the last character in the file
        fseek(fichier, -1, SEEK_END);
        char lastChar = fgetc(fichier);
        if (lastChar != '\n') {
            // if the file does not end with a newline, add one
            fputc('\n', fichier);
        }
    }

    logement_t *temp = allocate2();
    ass_id2(temp, generate_unique_id(1));

    // read type
    printf("Entrez le type du logement: STUDIO, F2, F3, F4\n");
    char str[8];
    do {
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // remove newline character
    } while (str_type(str) == -1);
    ass_type(temp, str_type(str));

    // read superficie
    printf("Entrez la superficie du logement: ");
    char superfici_buffer[20];
    fgets(superfici_buffer, sizeof(superfici_buffer), stdin);
    double superfici = atof(superfici_buffer); // convert string to double
    ass_area(temp, superfici);

    // read quartier
    printf("Entrez le quartier du logement: ");
    char quartier_buffer[20];
    fgets(quartier_buffer, sizeof(quartier_buffer), stdin);
    quartier_buffer[strcspn(quartier_buffer, "\n")] = '\0'; // remove newline character
    ass_quartier(temp, quartier_buffer);

    // read commune
    printf("Entrez la commune du logement: ");
    char commune_buffer[20];
    fgets(commune_buffer, sizeof(commune_buffer), stdin);
    commune_buffer[strcspn(commune_buffer, "\n")] = '\0'; // remove newline character
    ass_commune(temp, commune_buffer);

    // read distance
    printf("Entrez la distance du logement: ");
    char dist_buffer[20];
    fgets(dist_buffer, sizeof(dist_buffer), stdin);
    double dist = atof(dist_buffer); // convert string to double
    ass_distance(temp, dist);

    ass_loyer(temp);
    ass_etat(temp, false);
    ass_next2(temp, NULL);
    // write to file
    fprintf(fichier, "id:%d,type:%s,superficie:%.2lf,quartier:%s,commune:%s,distance:%.2lf\n", id2(temp), type_str(type(temp)), area(temp), quartier(temp), commune(temp), distance(temp));
    fclose(fichier);
    // insert into linked list
    insert_logement(temp);
};
void add_location() {

    FILE *fichier = fopen("Location.txt", "a");
    if(fichier == NULL) {
        printf("Error opening file\n");
        return;
    }

    // check if we need to add a newline
    fseek(fichier, 0, SEEK_END);
    if (ftell(fichier) > 0) {
        fseek(fichier, -1, SEEK_END);
        if (fgetc(fichier) != '\n') {
            fputc('\n', fichier);
        }
    }

    location_t *temp = allocate3();
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        fclose(fichier);
        return;
    }
    ass_id3(temp, generate_unique_id(3));

    // get locataire ID 
    int id;
    locataire_t *locataire = NULL;
    do {
        printf("Enter locataire ID: ");
        scanf("%d", &id);
        getchar(); // consume newline
        locataire = find_locataire(id);
        if(locataire == NULL) {
            printf("Locataire not found!\n");
        }
    } while(locataire == NULL);

    ass_id_locataire(temp, id);

    // get logement ID 
    logement_t *logement = NULL;
    do {
        printf("Enter logement ID: ");
        scanf("%d", &id);
        getchar(); // consume newline
        logement = find_logement(id);
        if(logement == NULL) {
            printf("Logement not found!\n");
        }
        else if(etat(logement)) {
            printf("Logement is already occupied!\n");
            logement = NULL;
        }
    } while(logement == NULL);

    ass_id_logement(temp, id);

    // get start date
    char date_debut[12];
    do {
        printf("Enter start date (DD/MM/YYYY): ");
        fgets(date_debut, sizeof(date_debut), stdin);
        date_debut[strcspn(date_debut, "\n")] = '\0'; // remove newline
        if(!check_valid_date(date_debut)) {
            printf("Invalid date format!\n");
        }
    } while(!check_valid_date(date_debut));
    ass_dd(temp, date_debut);

    // get end date
    char date_fin[12];
    do {
        printf("Enter end date (DD/MM/YYYY): ");
        fgets(date_fin, sizeof(date_fin), stdin);
        date_fin[strcspn(date_fin, "\n")] = '\0'; // remove newline
        if(!check_valid_date(date_fin)) {
            printf("Invalid date format!\n");
        }
        else if(!check_date_is_bigger(date_fin, date_debut)) {
            printf("End date must be after start date!\n");
        }
    } while(!check_valid_date(date_fin) || !check_date_is_bigger(date_fin, date_debut));
    ass_df(temp, date_fin);

    // calculate duration and amount
    int duree = calcul_duree_mois(date_debut, date_fin);
    ass_duree(temp, duree);
    ass_montant(temp, (loyer(logement) * duree));
    ass_next3(temp, NULL);

    // update logement status
    ass_etat(logement, true);
    ass_owner_id(logement, temp->id_locataire);
    ass_house1(locataire, temp->id_logement);

    fprintf(fichier, "id:%ld,id_locataire:%ld,id_logement:%ld,date_debut:%s,date_fin:%s\n",   id3(temp), id_locataire(temp), id_logement(temp), date_d(temp), date_f(temp));
    fclose(fichier);

    insert_location(temp);
    printf("Location added successfully!\n");
}

//------------------------------------------Deletion-----------------------------------------------------------------------------------//

void delete_house(locataire_t* ptr, int house_id){
    propreties_t* temp = houses(ptr);
    propreties_t* prev;
    logement_t* log = find_logement(house_id);
    ass_etat(log , false); // free the occupied logement
    bool deleted = false;
    while(temp && !deleted){
        prev = temp ;
        if(temp->id == house_id){
            if(temp == houses(ptr)){
                ptr->houses_head = next0(temp);
                temp->next = NULL;
                free(temp);
                deleted = true;
            }
            else{
                prev->next = next0(temp);
                temp->next = NULL;
                free(temp);
                deleted = true;
            }
        }
        temp = next0(temp);
    }
}

int have_a_house(locataire_t* ptr) { //how many houses he has
    if (ptr == NULL) {
        return 0;
    }

    if (ptr->houses_head == NULL) {
        printf("No houses found for locataire.\n");
        return 0;
    }

    propreties_t* temp = ptr->houses_head;
    int count = 0;

    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}


void delete_locataire(int id){
    locataire_t* temp = locataire_head;
    locataire_t* prev = NULL;
    while(temp != NULL) {
        if(id1(temp) == id) {
            // found the node to delete
            if(prev == NULL) {
                // deleting the head node
                locataire_head = next1(temp);
            } else {
                // deleting a middle or tail node
                ass_next1(prev, next1(temp));
            }
            free_all_houses(temp);
            free(temp);
            return;
        }
        prev = temp;
        temp = next1(temp);
    }
    printf("Locataire with ID %d not found.\n", id);
}

void delete_logement(int id){
    logement_t* temp = logement_head;
    logement_t* prev= NULL;
    while(temp!=NULL){
        if(id2(temp) == id) {
            if(prev == NULL) {
                logement_head = next2(temp);
            } else {
                ass_next2(prev, next2(temp));
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = next2(temp);
    }

}
void delete_location(int id){
    location_t* temp = location_head;
    location_t* prev= NULL;
    while(temp!=NULL){
        if(id3(temp) == id) {
            if(prev == NULL) {
                location_head = next3(temp);
            } else {
                ass_next3(prev, next3(temp));
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = next3(temp);
    }
}



//--------------------------------------------------ARCHIVATION-------------------------------------------------------------------
void archive_locataire() {
    // Get locataire to archive
    int choice;
    do {
        printf("Delete by name (0) or by ID (1)? Cancel (2): ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();
        if(choice == 2) return;
    } while(choice < 0 || choice > 2);

    locataire_t* locataire = NULL;
    int target_id = -1;

    if(choice == 0) { // searching by name
        char name[20], prename[20];
        printf("Enter last name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter first name: ");
        fgets(prename, sizeof(prename), stdin);
        prename[strcspn(prename, "\n")] = '\0';

        locataire = find_locataire_by_name(name, prename);
    } else { // searching by id
        printf("Enter locataire ID: ");
        scanf("%d", &target_id);
        getchar();
        locataire = find_locataire(target_id);
    }

    if(!locataire) {
        printf("Locataire not found.\n");
        return;
    }

    target_id = locataire->id;

    // check for active properties
    if(have_a_house(locataire) > 0) {
        printf("this locataire has %d properties. free them first? (1=Yes, 0=No): ", have_a_house(locataire));
        int free_choice;
        scanf("%d", &free_choice);
        getchar();

        if(free_choice == 1) {
            free_all_houses(locataire);
        } else {
            printf("cancelling operation.\n");
            return;
        }
    }

    // archive to file
    FILE *active_file = fopen("Locataire.txt", "r");
    FILE *archive_file = fopen("Archive_Locataire.txt", "a");
    FILE *temp_file = fopen("temp_locataire.txt", "w");

    if(!active_file || !archive_file || !temp_file) {
        printf("error opening files.\n");
        if(active_file) fclose(active_file);
        if(archive_file) fclose(archive_file);
        if(temp_file) fclose(temp_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    int found = 0;

    while(fgets(buffer, BUFFER_SIZE, active_file)) {
        int current_id;
        if(sscanf(buffer, "id:%d", &current_id) == 1) {
            if(current_id == target_id) {
                fprintf(archive_file, "%s", buffer);
                found = 1;
                continue;
            }
        }
        fprintf(temp_file, "%s", buffer);
    }

    fclose(active_file);
    fclose(archive_file);
    fclose(temp_file);

    if(!found) {
        printf("Locataire not found in file.\n");
        remove("temp_locataire.txt");
        return;
    }

    // handle associated locations
    FILE *loc_file = fopen("Location.txt", "r");
    FILE *loc_archive = fopen("Archive_Location.txt", "a");
    FILE *loc_temp = fopen("temp_location.txt", "w");

    if(loc_file && loc_archive && loc_temp) {
        while(fgets(buffer, BUFFER_SIZE, loc_file)) {
            int loc_id, locataire_id, logement_id;
            if(sscanf(buffer, "id:%d,id_locataire:%d,id_logement:%d",
                      &loc_id, &locataire_id, &logement_id) >= 2) {
                if(locataire_id == target_id) {
                    fprintf(loc_archive, "%s", buffer); //put the location into archive location
                    continue;
                }
            }
            fprintf(loc_temp, "%s", buffer);
        }
        fclose(loc_file);
        fclose(loc_archive);
        fclose(loc_temp);

        remove("Location.txt");
        rename("temp_location.txt", "Location.txt");
    }

    // update files
    remove("Locataire.txt");
    rename("temp_locataire.txt", "Locataire.txt");

    // remove from memory
    delete_locataire(target_id);

    printf("Locataire archived successfully.\n");
}

void archive_logement() {
    int choice;
    do {
        printf("Archive by ID (0) or by type (1)? ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();
    } while(choice != 0 && choice != 1);

    FILE *active_file = fopen("Logement.txt", "r");
    FILE *archive_file = fopen("Archive_Logement.txt", "a");
    FILE *temp_file = fopen("temp_logement.txt", "w");

    if(!active_file || !archive_file || !temp_file) {
        printf("Error opening files.\n");
        if(active_file) fclose(active_file);
        if(archive_file) fclose(archive_file);
        if(temp_file) fclose(temp_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    int found = 0;
    type_logement_t typ;

    if(choice == 0) { //archive by id
        printf("Enter logement ID to archive: ");
        int target_id;
        scanf("%d", &target_id);
        getchar();

        logement_t* logement = find_logement(target_id);
        if(!logement) {
            printf("Logement not found.\n");
            fclose(active_file);
            fclose(archive_file);
            fclose(temp_file);
            remove("temp_logement.txt");
            return;
        }

        // handle if occupied
        if(etat(logement)) {
            printf("logement is occupied. Free it? (1=Yes, 0=No): ");
            int free_choice;
            scanf("%d", &free_choice);
            getchar();

            if(free_choice == 1) {
                locataire_t* owner = find_locataire(owner_id(logement));
                if(owner) {
                    delete_house(owner, target_id);
                }
            } else {
                printf("cancelling archive.\n");
                fclose(active_file);
                fclose(archive_file);
                fclose(temp_file);
                remove("temp_logement.txt");
                return;
            }
        }
        while(fgets(buffer, BUFFER_SIZE, active_file)) {
            int current_id;
            if(sscanf(buffer, "id:%d", &current_id) == 1) {
                if(current_id == target_id) {
                    fprintf(archive_file, "%s", buffer);
                    found = 1;
                    continue;
                }
            }
            fprintf(temp_file, "%s", buffer);
        }

        if(found) {
            delete_logement(target_id);
        }
    }
    else { // archive by type
        printf("Enter type (STUDIO, F2, F3, F4): ");
        char str[7];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        typ = str_type(str);
        if(typ == -1) {
            printf("Invalid type.\n");
            fclose(active_file);
            fclose(archive_file);
            fclose(temp_file);
            remove("temp_logement.txt");
            return;
        }

        // process memory first
        logement_t* current = logement_head;
        while(current) {
            if(type(current) == typ) {
                // handle if occupied
                if(etat(current)) {
                    locataire_t* owner = find_locataire(owner_id(current));
                    if(owner) {
                        delete_house(owner, id2(current));
                    }
                }

                // add to archive
                fprintf(archive_file, "id:%d,type:%s,superficie:%.2lf,quartier:%s,commune:%s,distance:%.2lf\n",
                        id2(current), type_str(type(current)), area(current),
                        quartier(current), commune(current), distance(current));

                logement_t* to_delete = current;
                current = next2(current);
                delete_logement(id2(to_delete));
                found = 1;
            } else {
                current = next2(current);
            }
        }

        // now process file to remove archived logements
        rewind(active_file);
        while(fgets(buffer, BUFFER_SIZE, active_file)) {
            int current_id;
            char current_type[7];
            if(sscanf(buffer, "id:%d,type:%6[^,]", &current_id, current_type) == 2) {
                if(str_type(current_type) == typ) {
                    continue; // skip logements of this type
                }
            }
            fprintf(temp_file, "%s", buffer);
        }
    }

    fclose(active_file);
    fclose(archive_file);
    fclose(temp_file);

    if(!found) {
        printf("No matching logements found.\n");
        remove("temp_logement.txt");
        return;
    }

    // handle associated locations
    FILE *loc_file = fopen("Location.txt", "r");
    FILE *loc_archive = fopen("Archive_Location.txt", "a");
    FILE *loc_temp = fopen("temp_location.txt", "w");

    if(loc_file && loc_archive && loc_temp) {
        while(fgets(buffer, BUFFER_SIZE, loc_file)) {
            int loc_id, locataire_id, logement_id;
            if(sscanf(buffer, "id:%d,id_locataire:%d,id_logement:%d",&loc_id, &locataire_id, &logement_id) >= 2) {
                logement_t* logement = find_logement(logement_id);
                if(!logement || (choice == 1 && type(logement) == typ)) {
                    fprintf(loc_archive, "%s", buffer);
                    continue;
                }
            }
            fprintf(loc_temp, "%s", buffer);
        }
        fclose(loc_file);
        fclose(loc_archive);
        fclose(loc_temp);

        remove("Location.txt");
        rename("temp_location.txt", "Location.txt");
    }

    // updatelogement file
    remove("Logement.txt");
    rename("temp_logement.txt", "Logement.txt");

    printf("Logement(s) archived successfully.\n");
}

void archive_location() {
    int id_to_archive;
    printf("Enter the ID of the location you want to archive: ");
    if(scanf("%d", &id_to_archive) != 1) {
        printf("Invalid ID input.\n");
        return;
    }
    getchar(); //skip newline
    location_t* location = find_location(id_to_archive);
    if(location == NULL) {
        printf("Location not found.\n");
        return;
    }
    printf("Enter today's date (DD/MM/YYYY): ");
    char date[11];
    int choice;
    do {
        fgets(date, sizeof(date), stdin);
        date[strcspn(date, "\n")] = '\0';
        if(!check_valid_date(date)) {
            printf("Invalid date format. Please use DD/MM/YYYY: ");
        }
    } while(!check_valid_date(date));
    if(!check_date_is_bigger(date, date_f(location))) {
        printf("today's date is before the end date of the location.\n");
        printf("are you sure you want to proceed? (0=No, 1=Yes): ");
        scanf("%d", &choice);
        getchar();

    }
    if(choice == 0) {
        printf("operation cancelled .\n");
        return;
    }
    // free the logement if needed
    logement_t* logement = find_logement(id_logement(location));
    if(logement != NULL) {
        ass_etat(logement, false);
        ass_owner_id(logement, -1);
    }
    delete_location(id_to_archive);

    // archive to file
    FILE *active_file = fopen("Location.txt", "r");
    FILE *archive_file = fopen("Archive_Location.txt", "a");
    FILE *new_file = fopen("New_Location.txt", "w");

    if(!active_file || !archive_file || !new_file) {
        printf("Error opening files.\n");
        if(active_file) fclose(active_file);
        if(archive_file) fclose(archive_file);
        if(new_file) fclose(new_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    int archived = 0;
    while(fgets(buffer, BUFFER_SIZE, active_file)) {
        if(buffer[0] == '\n') continue;

        int id;
        if(sscanf(buffer, "id:%d", &id) != 1) continue;

        if(id == id_to_archive) {
            fprintf(archive_file, "%s", buffer);
            archived = 1;
        } else {
            fprintf(new_file, "%s", buffer);
        }
    }

    fclose(active_file);
    fclose(archive_file);
    fclose(new_file);

    if(!archived) {
        printf("Location not found in file.\n");
        remove("New_Location.txt");
        return;
    }

    remove("Location.txt");
    rename("New_Location.txt", "Location.txt");
    printf("Location archived successfully.\n");
}

//---------------------------------------------DISPLAY FUNCTIONS---------------------------------------------------------------//


void display(logement_t* ptr){
    printf("Logement id: %d, logement type : %s, Loyer :%d , logement superficie : %.2lf m^2 , quartier : %s , commune : %s , distance : %.2lf Km\n " ,id2(ptr), type_str(type(ptr)),loyer(ptr), area(ptr) , quartier(ptr) , commune(ptr) , distance(ptr));
};

void display_loctaire(locataire_t* ptr){
    if(ptr == NULL){
        printf("Locataire doesen't exist");
        return;
    }
    printf("Locataire: %s %s (ID: %d   /   Phone: %s)\n" ,nom(ptr) ,prenom(ptr) , id1(ptr) , telephone(ptr));
    printf("Propreties: \n");
    propreties_t* prop = houses(ptr);
    if(!prop){
        printf("%s dosen't have a house\n", nom(ptr));
    }
    logement_t* temp ;
    while(prop){
        display(find_logement(prop->id));
        prop=next0(prop);
    }
}

void display_location(location_t* ptr) {
    if (ptr == NULL) {
        printf("Error: NULL location pointer\n");
        return;
    }

    //get related locataire and logement
    locataire_t* locataire = find_locataire(id_locataire(ptr));
    logement_t* logement = find_logement(id_logement(ptr));

    if (locataire == NULL) {
        printf("Error: Locataire not found for ID %ld\n", id_locataire(ptr));
        return;
    }

    if (logement == NULL) {
        printf("Error: Logement not found for ID %ld\n", id_logement(ptr));
        return;
    }

    printf("\nLocation ID: %ld\n", id3(ptr));
    printf("Locataire: %s %s (ID: %d, Tel: %s)\n",
           prenom(locataire), nom(locataire),
           id1(locataire), telephone(locataire));
    printf("Logement: %s (ID: %d)\n", type_str(type(logement)), id2(logement));
    printf("  - Superficie: %.2lf m^2\n", area(logement));
    printf("  - Quartier: %s, Commune: %s\n", quartier(logement), commune(logement));
    printf("  - Distance: %.2lf km, Loyer: %d\n", distance(logement), loyer(logement));
    printf("Dates: %s to %s (%d months)\n",
           date_d(ptr), date_f(ptr), duration(ptr));
    printf("Total amount: %d\n", montant(ptr));
}

void display_logmenents() {
    logement_t* head = merge_sort_log(logement_head,3);
    int choice;
    int choix;
    char date[11];
    do {
        printf("\n1. Display currently occupied logements\n");
        printf("2. Display logements that will be available after a specific date\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        getchar();
    } while((choice != 1) && (choice != 2));
    if (choice == 2) {
        do {
            printf("Enter the target date (DD/MM/YYYY): ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = '\0';
            if(!check_valid_date(date)) {
                printf("invalid date format. please use DD/MM/YYYY.\n");
            }
        } while(!check_valid_date(date));
    }

    int count = 0;
    while (head != NULL) {
        bool display1 = false;

        // case 1 : show currently occupied logements
        if (choice == 1 && etat(head)) {
            display1 = true;
            printf("\noccupied Logement:\n");
            printf("ID: %d, Type: %s, Superficie: %.2lf\n", id2(head), type_str(type(head)), area(head));
            printf("Quartier: %s, Commune: %s, Distance: %.2lf km\n", quartier(head), commune(head), distance(head));

            locataire_t* locataire = find_locataire(owner_id(head));
            if (locataire != NULL) {
                printf("Occupied by: %s %s (ID: %d)\n",
                       prenom(locataire), nom(locataire), id1(locataire));
            }
        }
        // case 2: show logements that will be available after given date
        else if (choice == 2) {
            if (!etat(head)) {
                // already avaliable
                display1 = true;
                printf("\nLogement currently available:\n");
                display(head);
            } else { //available after given date
                // check locations
                location_t* loc = location_head;
                bool availble = true;

                while (loc != NULL) {
                    if (id_logement(loc) == id2(head)) {
                        if (check_date_is_bigger(date_f(loc), date) ||
                            strcmp(date_f(loc), date) == 0) {
                            availble = false;
                            break;
                        }
                    }
                    loc = next3(loc);
                }

                if (availble) {
                    display1 = true;
                    printf("\nLogement available after %s:\n", date);
                    display(head);
                }
            }
        }
        if (display1) {
            count++;
            // show 5 at once
            if (count % 5 == 0) {
                do {
                    printf("\nshow more? (0=No, 1=Yes): ");
                    scanf("%d", &choix);
                    getchar();
                    if (choix == 0) return;
                } while(choix != 1);
            }
        }
        head = next2(head);
    }
    if (count == 0) {
        printf("\nNo logements found matching your criteria.\n");
    } else {
        printf("\nTotal matching logements: %d\n", count);
    }
}
//-----------------------------------------------------Trie de location-------------------------------------------------------------//

location_t* middle_location(location_t* head ){
    location_t* prev =NULL;
    location_t* fast = head;
    location_t* slow = head;

    if ( (head ==NULL) || (next3(head) == NULL)){
        return head;
    };
    while((fast != NULL) && (next3(fast) != NULL)){
        prev = slow;
        slow = next3(slow);
        fast = next3(next3(fast));
    };
    return prev;  //you should assign to the left next2(prev)
};

location_t* merge_sorted_location(location_t* left, location_t* right, int n) {
    location_t* result = NULL;

    if (left == NULL) return right;
    if (right == NULL) return left;

    switch (n) {
        case 1:  // Sort by logement type
            if (type(find_logement(id_logement(left))) <= type(find_logement(id_logement(right)))) {
                result = left;
                ass_next3(result, merge_sorted_location(next3(left), right, n));
            } else {
                result = right;
                ass_next3(result, merge_sorted_location(left, next3(right), n));
            }
            break;

        case 2:  // Sort by price
            if (loyer(find_logement(id_logement(left))) <= loyer(find_logement(id_logement(right)))) {
                result = left;
                ass_next3(result, merge_sorted_location(next3(left), right, n));
            } else {
                result = right;
                ass_next3(result, merge_sorted_location(left, next3(right), n));
            }
            break;

        case 3:  // Sort by type and price
            if (type(find_logement(id_logement(left))) < type(find_logement(id_logement(right)))) {
                result = left;
                ass_next3(result, merge_sorted_location(next3(left), right, n));
            } else if (type(find_logement(id_logement(left))) == type(find_logement(id_logement(right)))) {
                if (loyer(find_logement(id_logement(left))) <= loyer(find_logement(id_logement(right)))) {
                    result = left;
                    ass_next3(result, merge_sorted_location(next3(left), right, n));
                } else {
                    result = right;
                    ass_next3(result, merge_sorted_location(left, next3(right), n));
                }
            } else {
                result = right;
                ass_next3(result, merge_sorted_location(left, next3(right), n));
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return result;
}


location_t* merge_sort_location(location_t* head, int n) {
    if (head == NULL || next3(head) == NULL) {
        return head;
    }

    location_t* middle = middle_location(head);
    location_t* right = next3(middle);
    ass_next3(middle, NULL);

    location_t* left_sorted = merge_sort_location(head, n);
    location_t* right_sorted = merge_sort_location(right, n);

    return merge_sorted_location(left_sorted, right_sorted, n);
}
void display_all_locations() {
    printf("\nAll Locations:\n");
    location_t *temp = location_head;
    int count = 0;
    while (temp) {
        display_location(temp);
        count++;
        temp = next3(temp);
    }
    printf("Total locations: %d\n", count);
}
void display_all_unoccupied_logments(){
    logement_t* log = merge_sort_log(logement_head,3);
     while(log && (!etat(log))){
        display(log);
        log = next2(log);
    }
}
void display_all_logments(){
    logement_t* log = merge_sort_log(logement_head,3) ;
    while(log){
       display(log);
       log = next2(log);
   }
}
void display_all_locataires(){
    locataire_t* loc = locataire_head;

                while(loc){
                    display_loctaire(loc);
                    loc = next1(loc);
                }
}
//-----------------------------------------------QST 6 -----------------------------------------------------------------------

  void display_locataires_with_large_same_type() {
    // Ask for the type of(logement)
    printf("Enter the type of logement (STUDIO, F2, F3, F4): ");
    char str[8];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    type_logement_t typ = str_type(str);
    if (typ == -1) {
        printf("Invalid type entered.\n");
        return;
    }
    // get the average area for this type
    double avg_area = (double)superficie_moyenne(typ);
    printf("\nloctaires occupying %s logements with area > %.2lf m^2:\n", type_str(typ), avg_area);
    locataire_t* loc = locataire_head;
    int count=0 ;
    while (loc != NULL) {
        propreties_t* house = houses(loc);
        // Check all properties of this locataire
        while (house != NULL) {
            logement_t* logement = find_logement(house->id);

            if (logement != NULL && type(logement) == typ && area(logement) > avg_area) {
                // Found a matching logement for loctaire
                printf("locataire ID: %d\n", id1(loc));
                printf("nom: %s %s\n", prenom(loc), nom(loc));
                printf("telephone: %s\n", telephone(loc));
                printf("logement id: %d, superficie: %.2lf m�\n", id2(logement), area(logement));
                printf("quartier: %s, commune: %s\n", quartier(logement), commune(logement));
                count++;
                break; // show locataire once if he has more than one house
            }
            house=next0(house);
        }
    loc=next1(loc);
    }
    if (count==0) {
        printf("no locataires found occupying %s logements with area > %.2lf m^2.\n", type_str(typ), avg_area);
    }
         else {
        printf("matching locataires : %d\n", count);
    }
}

//-----------------------------------------------------------QST 8 -------------------------------------------------------------
logement_t* merge_sorted_score(logement_t* left, logement_t* right, double max_loyer, double max_distance) {
    if(!left) return right;
    if(!right) return left;

    logement_t* result = NULL;
    double score_left = (distance(left)/max_distance) + ((double)loyer(left)/max_loyer);
    double score_right = (distance(right)/max_distance) + ((double)loyer(right)/max_loyer);

    if(score_left < score_right) {
        result = left;
        ass_next2(result, merge_sorted_score(next2(left), right, max_loyer, max_distance));
    } else {
        result = right;
        ass_next2(result, merge_sorted_score(left, next2(right), max_loyer, max_distance));
    }
    return result;
}

logement_t* merge_score(logement_t* head  ,double max_loyer , double max_distance){
    if((head == NULL)|| next2(head)==NULL){
        return head;
    }
    logement_t* middle = middle_log(head);
    logement_t* right = next2(middle);
    ass_next2(middle , NULL);

    logement_t* left_sorted = merge_score(head,max_loyer,max_distance);
    logement_t* right_sorted = merge_score(right,max_loyer,max_distance);

    return (merge_sorted_score(left_sorted , right_sorted , max_loyer, max_distance));
}


 void find_best_logements() {
        if (logement_head == NULL) {
            printf("No logements available.\n");
            return;
        }
        printf("Enter commune: ");
        char comm[20];
        fgets(comm, sizeof(comm), stdin);
        comm[strcspn(comm, "\n")] = '\0';
        to_upper(comm);

        // choose method
        printf("\nchoose search method:\n");
        printf("1. prioritize minimal distance\n");
        printf("2. prioritize minimal loyer\n");
        printf("3. balanced score (distance et loyer)\n");
        printf("your choice (1-3): ");

        int method;
        if (scanf("%d", &method) != 1 || method < 1 || method > 3) {
            printf("invalid input. using score mehtod as default.\n");
            method = 3;
        }
        getchar();
        double max_distance = 0;
        double max_loyer= 0 ;
        double miminal_distance = 100000000 ;
        double minimal_loyer = 100000000000 ;
        double best_score = 100000000;

        logement_t* head = logement_head;
        logement_t* current = NULL;
        logement_t* temp_head = NULL;
        logement_t* head1 = NULL;
        logement_t* tail1 = NULL;

  while(head) {
    if(strcmp(to_upper(commune(head)), to_upper(comm)) == 0) {
        logement_t* new_node = allocate2();
        // Copy all data from head to new_node
        memcpy(new_node, head, sizeof(logement_t));
        ass_next2(new_node, NULL);

        if(temp_head == NULL) {
            temp_head = new_node;
            current = temp_head;
        } else {
            ass_next2(current, new_node);
            current = new_node;
        }
    }
    head = next2(head);
}


        current = temp_head;
          while (current) {
            if (distance(current) > max_distance) {max_distance = distance(current);}
            if (loyer(current) > max_loyer) {max_loyer = loyer(current);}
            current = next2(current);
            }

        switch(method){
        case 1 : {
            head1 = merge_sort_log(temp_head , 4);
            break;
        }
        case 2 :{
            head1 = merge_sort_log(temp_head , 2);
            break;
        }
        case 3:{
            head1 = merge_score(temp_head , max_loyer , max_distance);
            break;
        }
        default:{
            printf("error in choice using score method\n");
            head1 = merge_score(temp_head , max_loyer , max_distance);
            break;
        }
    }
    current=head1;
    while(current){
        display(current);
        current=next2(current);
    }
    current = head1;
    while(current) {
        logement_t* temp = current;
        current = next2(current);
        free(temp);
    }
 }

 //-------------------------------------------QST 7-------------------------------------------------------------------------------


void location_par_year(char date[11]) {
    if (!location_head) { fichier_location(date); }
    if (!archive_location_head) { fichier_archive_location(); }
    if (!archive_logement_head){fichier_archive_logement();}
    printf("Enter the year : ");
    int yr;
    scanf("%d", &yr);
    getchar();

    printf("Enter the way you want to see the statistics :\n(1) : nombre de logements loues par quartier/ (2):nombre de locations par type de logments  : ");
    int method;
    scanf("%d", &method);
    getchar();
    int count = 0;
    int day, month, year;
    logement_t* temp_log = NULL;
    logement_t* current = NULL;
    logement_t* new_node;
    //active locations
    location_t* temp_loc = location_head;
    while (temp_loc) {
        if (sscanf(date_d(temp_loc), "%d/%d/%d", &day, &month, &year) == 3 && year == yr) {
            logement_t* temp = find_logement(id_logement(temp_loc));
            if (temp) {
                new_node = allocate2();
                memcpy(new_node, temp, sizeof(logement_t));
                ass_next2(new_node, NULL);
                count++;
                if (temp_log == NULL) {
                    temp_log = new_node;
                    current = temp_log;
                } else {
                    ass_next2(current, new_node);
                    current = new_node;
                }
            }
        }
        temp_loc = next3(temp_loc);
    }
    //archived locations
    temp_loc = archive_location_head;
    while (temp_loc) {
        if (sscanf(date_d(temp_loc), "%d/%d/%d", &day, &month, &year) == 3 && year == yr) {
            logement_t* temp = find_logement(id_logement(temp_loc));
            if (temp) {
                new_node = allocate2();
                memcpy(new_node, temp, sizeof(logement_t));
                ass_next2(new_node, NULL);
                count++;
                if (temp_log == NULL) {
                    temp_log = new_node;
                    current = temp_log;
                } else {
                    ass_next2(current, new_node);
                    current = new_node;
                }
            }
        }
        temp_loc = next3(temp_loc);
    }

    // Count logements by quartier
    quartier_count_t* q_saver_head = NULL;
    quartier_count_t* tailq = NULL;
    quartier_count_t* tempq;
    int quartier_count_size = 0;

    logement_t* log = merge_sort_log(temp_log,3);
    while (log) {
        bool found = false;
        tempq = q_saver_head;
        while (tempq && !found) {
            if ((method == 1) &&(strcmp(tempq->quartier, quartier(log)) == 0)) {
                tempq->count++;
                found = true;
            }
            else if((method == 2)&&(type(log)== tempq->typ)){
                tempq->count++;
                found = true;
            }
            tempq = tempq->next;
        }
        if (!found) {
            quartier_count_t* tempq2 = (quartier_count_t*)malloc(sizeof(quartier_count_t));
            if(method==1){
                strcpy(tempq2->quartier, quartier(log));
            }
            else if(method ==2){
                tempq2->typ=type(log);
            };
            tempq2->count = 1;
            tempq2->next = NULL;
            quartier_count_size++;
            if (q_saver_head == NULL) {
                q_saver_head = tempq2;
                tailq = q_saver_head;
            } else {
                tailq->next = tempq2;
                tailq = tempq2;
            }
        }
        log = next2(log);
    }

    //display mrthod 1
    if (method==1){
    printf("\nNumber of quartiers with rentals in %d: %d\n", yr, quartier_count_size);
    printf("\nLogements rented in %d by quartier:\n", yr);
    tempq = q_saver_head;
    while (tempq) {
        printf("%s: %d logement\n", tempq->quartier, tempq->count);
        tempq = tempq->next;
    }
    }
    //display method 2
    if (method==2){
        printf("\n Number of locations with rentals in %d: %d\n ", yr,quartier_count_size);
        printf("\n locations rented in %d by type : \n", yr);
        tempq = q_saver_head;
    while (tempq){
     printf("%s: %d location \n", type_str(tempq->typ) ,tempq->count);
     tempq = tempq->next;
    }
    }
    // free allocated memory
    log = temp_log;
    while (log) {
        logement_t* next = next2(log);
        free(log);
        log = next;
  }
    tempq = q_saver_head;
    while (tempq) {
        quartier_count_t* next = tempq->next;
        free(tempq);
        tempq = next;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------//
void clear_screen() {
    system("cls");
};
void press_enter_to_continue() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
}
void display_main_menu() {
    clear_screen();
    printf("\n========================================\n");
    printf("    RENT  - MAIN MENU\n");
    printf("========================================\n");
    printf("1. Logement Management\n");
    printf("2. Locataire Management\n");
    printf("3. Location Management\n");
    printf("4. Stats and reports\n");
    printf("5. Exit\n");
    printf("0. Display Options\n");
}
void handle_stats_menu(char date[11]) {
    int choice;
    do {
        clear_screen();
        printf("\n=== STATS AND REPORTS ===\n");
        printf("1. Location statistics by year\n");
        printf("2. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                location_par_year(date);
                press_enter_to_continue();
                break;
            case 2:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                press_enter_to_continue();
        }
    } while (choice != 2);
}
bool handle_logement_menu() {
    int choice;
    do {
        clear_screen();
        printf("\n=== LOGEMENT MANAGEMENT ===\n");
        printf("1. Add new logement\n");
        printf("2. Archive logement\n");
        printf("3. Display available/occupied logements\n");
        printf("4. Find best logements (by commune)\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_logement();
                printf("\nLogement added successfully!\n");
                press_enter_to_continue();
                return true;
                break;
            case 2:
                display_all_logments();
                archive_logement();
                press_enter_to_continue();
                return true;
                break;
            case 3:
                display_logmenents();
                press_enter_to_continue();
                return false;
                break;
            case 4:
                find_best_logements();
                press_enter_to_continue();
                return false;
                break;
            case 5:
            return false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                press_enter_to_continue();
        }
    } while (choice != 5);
}
bool handle_locataire_menu() {
    int choice;
    do {
        clear_screen();
        printf("\n=== LOCATAIRE MANAGEMENT ===\n");
        printf("1. Add new locataire\n");
        printf("2. Archive locataire\n");
        printf("3. Display locataires with large same-type logements\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_locataire();
                printf("\nLocataire added successfully!\n");
                press_enter_to_continue();
                return true;
                break;
            case 2:
                display_all_locataires();
                archive_locataire();
                press_enter_to_continue();
                return true;
                break;
            case 3:
                display_locataires_with_large_same_type();
                press_enter_to_continue();
                return false;
                break;
            case 4:
                return false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                press_enter_to_continue();
        }
    } while (choice != 4);
}
bool handle_location_menu() {
    int choice;
    do {
        clear_screen();
        printf("\n=== LOCATION MANAGEMENT ===\n");
        printf("1. Add new location\n");
        printf("2. Archive location\n");
        printf("3. Display all locations\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                display_all_locataires();
                display_all_unoccupied_logments();
                printf("\n");
                add_location();
                printf("\nLocation added successfully!\n");
                press_enter_to_continue();
                return true;
                break;
            case 2:
                display_all_locations();
                archive_location();
                press_enter_to_continue();
                Sleep(2);
                return true;
                break;
            case 3:
                display_all_locations();
                press_enter_to_continue();
                return false;
                break;
            case 4:
                return false ;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                press_enter_to_continue();
        }
    } while (choice != 4);
}
