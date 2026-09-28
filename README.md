# Rental-System
This project is a C program for managing a rental housing system. It is designed to help an administrator or real-estate manager track tenants, available housing, and rental contracts.

The application allows the user to:

manage tenants and their information
manage housing units and their characteristics
create and archive rental contracts
check the occupation status of apartments
display lists of tenants, houses, and rentals
calculate rental amounts and duration
generate statistics and reports by year or by housing type
search for the best housing options based on criteria such as price, distance, or a balance between both
The system stores its data in files, which means the user is working on files as part of the project. The program reads information from files such as tenant records, housing records, rental records, and archived rental records, and updates them during use.

The project is built around linked-list structures in C and uses text files as persistent storage. It includes functions for creation, insertion, deletion, sorting, search, display, archiving, and statistics.

This project is useful for learning:

data structures in C
file handling
program menu design
sorting and searching algorithms
object-like modeling in procedural C
managing a small real-world information system
Main files
main.c: contains the application entry point and user interface
LOG_LLC_BIBLIO.h: header file with declarations and structures
LOG_LLC_BIBLIO.c: implementation of the logic and operations
data text files such as Locataire.txt, Logement.txt, Location.txt, and Archive_Location.txt
