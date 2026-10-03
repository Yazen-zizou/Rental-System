# Rental-System

A console application written in **C** to manage a rental housing system: tenants (*locataires*), housing units (*logements*) and rental contracts (*locations*). All data is stored in plain text files and handled in memory with **linked lists**.

> Academic project (university lab, TP1) — Windows only (uses `windows.h`, `system("cls")` and `Sleep`).

## Features

- **Housing management**: add a unit, archive a unit, list available / occupied units, find the best units in a commune.
- **Tenant management**: add a tenant, archive a tenant, list tenants who rent several large units of the same type.
- **Rental contract management**: create a contract, archive a contract, display all contracts.
- **Statistics**: rental statistics by year.
- **Automatic rent calculation** from the unit type and surface area.
- **Persistent storage** in text files, reloaded after every update.
- **Best-housing search** by commune with three criteria: minimal distance, minimal rent, or a balanced score of both.

## Rent calculation

Each unit type has a base rent and an average surface area. Every square metre above the average adds 800 to the rent.

| Type   | Base rent | Average surface |
|--------|-----------|-----------------|
| STUDIO | 15 000    | 20 m²           |
| F2     | 20 000    | 45 m²           |
| F3     | 30 000    | 65 m²           |
| F4     | 45 000    | 85 m²           |

`rent = base rent + (surface - average surface) * 800` (only if surface > average)

## Project structure

```
Rental-System/
├── README.md
└── src/
    ├── main.c                # entry point, main loop and menus
    ├── LOG_LLC_BIBLIO.h      # structures and function declarations
    ├── LOG_LLC_BIBLIO.c      # all the logic (lists, files, sorting, stats)
    ├── TP1.cbp               # Code::Blocks project file
    ├── Locataire.txt         # tenants
    ├── Logement.txt          # housing units
    ├── Location.txt          # active rental contracts
    └── Archive_Location.txt  # archived rental contracts
```

Archiving also creates `Archive_Locataire.txt` and `Archive_Logement.txt` on first use.

## Requirements

- **Windows**
- **GCC** for Windows (e.g. [MinGW-w64](https://www.mingw-w64.org/) or MSYS2), or **Code::Blocks** with the MinGW compiler

## Compile and run

The program reads and writes its `.txt` files in the **current directory**, so always run it from inside the `src` folder.

### With GCC (command line)

```bash
cd src
gcc -Wall main.c LOG_LLC_BIBLIO.c -o rental.exe -lm
.\rental.exe
```

### With Code::Blocks

1. Open `src/TP1.cbp`.
2. Press **Build and run** (`F9`).
3. If the data files are not found, set the working directory to the `src` folder in *Project → Properties → Build targets*.

> It cannot be compiled on Linux or macOS as is, because of `windows.h`, `system("cls")` and `Sleep()`.

## Usage

1. At startup, enter today's date in the format `DD/MM/YYYY`. It is used to decide which contracts are active.
2. Pick an option from the main menu:

```
1. Logement Management
2. Locataire Management
3. Location Management
4. Stats and reports
5. Exit
0. Display Options
```

| Menu | Options |
|------|---------|
| **1. Logement** | Add a logement · Archive a logement · Display available/occupied logements · Find best logements (by commune) |
| **2. Locataire** | Add a locataire · Archive a locataire · Display locataires with large same-type logements |
| **3. Location** | Add a location · Archive a location · Display all locations |
| **4. Stats** | Location statistics by year |
| **0. Display** | Developer options: display all logements, locataires, locations or archived locations |

## Data file format

One record per line, as `key:value` pairs separated by commas.

```
# Locataire.txt
id:1085,nom:Mansouri,prenom:Mohamed,telephone:0567891234

# Logement.txt
id:1002,type:F2,superficie:45.00,quartier:El Mouradia,commune:Alger Centre,distance:1.50

# Location.txt
id:2014,id_locataire:1085,id_logement:1014,date_debut:15/12/2023,date_fin:15/12/2024
```

Dates use the format `DD/MM/YYYY`. Unit types are `STUDIO`, `F2`, `F3` and `F4`. The rent, duration and amount of a contract are computed by the program and not stored in the files.

## Data structures

- `locataire_t`: tenant, with a sub-list of the units they rent.
- `logement_t`: housing unit (type, surface, district, commune, distance, rent, state, owner).
- `location_t`: rental contract (tenant, unit, start and end dates, duration, amount).

Each structure is a singly linked list manipulated through small accessor functions (`allocate`, `ass_*`, `next*`), and sorted with **merge sort**.

## What this project teaches

- Linked lists in C
- File handling (read, append, rewrite via temporary files)
- Menu-driven console programs
- Merge sort and search algorithms
- Modeling a small real-world information system in procedural C
