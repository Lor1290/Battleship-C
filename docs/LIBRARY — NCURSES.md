# INTRO

`NCurses` (New Curses) offre ai programmatori la possibilità di sviluppare **text user interface** (`TUI`) performanti ed efficienti, fornendo un livello di astrazione più elevato rispetto alla libreria originale `Curses`, sviluppata negli anni ’90 per i sistemi Unix. Per compilare un’applicazione che utilizza `NCurses`, è necessario **linkare** il progetto con la flag:

```c
-lncurses
```

Qualora si desiderassero utilizzare le funzionalità di debug, è possibile compilare il tutto con:

```c
-lncurses_g
```

---
## STRUCTURE

Un’applicazione `NCurses` utilizza il formato testuale del sistema operativo (es. `UTF-8`). Se il formato non viene impostato manualmente, la libreria userà quello predefinito del sistema.  
Per specificarlo esplicitamente si utilizza:

```c
setlocale(LC_ALL, "");
````

È sempre consigliato inizializzare la codifica, soprattutto nelle applicazioni _legacy_ che potrebbero richiedere un supporto più ampio per caratteri estesi o simboli speciali. Per inizializzare un’applicazione `NCurses` è necessario richiamare le seguenti funzioni:

```c
initscr();    // inizializza lo schermo e crea stdscr 
newterm(...); // inizializza un nuovo terminale (opzionale, usato per setup avanzati)
```

Può inoltre essere necessario richiamare alcune procedure utili per gestire correttamente l’input e stampare caratteri senza buffering indesiderato:

```c
initscr();  // inizializzazione principale 
cbreak();   // input carattere per carattere, senza aspettare il newline 
noecho();   // evita che i tasti premuti vengano mostrati automaticamente
```

Successivamente, per migliorare la gestione dell’input e delle prestazioni, possono essere abilitate ulteriori funzioni:

```c
noqiflush();  // evita il flush automatico degli input buffer su segnali 
keypad(stdscr, TRUE); // abilita la lettura dei tasti funzione e delle frecce
```

Infine, ogni applicazione `NCurses` deve concludersi con una corretta chiusura del contesto:

```c
endwin();   // ripristina lo stato originale del terminale
```

---
## OVERVIEW

Una applicazione `NCurses` tratta la finestra come una `structure`, e descrive ogni suo attributo come un argomento di una `structure`. La finestra in se, però, verrà trattata come una matrice `n x n`, dove la posizione in alto a sinistra è descritta come (0, 0). 