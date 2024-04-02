// fede-console.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
// 
// *** NOTA IMPORTANTE ***
// Per evitare problemi tra il compilatore e la funzione "scanf" è stato necessario modificare le impostazioni al preprocessore.
// Di seguito i passi applicati:
//  - Progetto > Proprieta' [nome_progetto] > C/C++ > Preprocessore
//  - Aggiungere la stringa "_CRT_SECURE_NO_WARNINGS" in fondo (usare ";" per dividere gli argomenti).
// // ********************
//

#define DEBUG

//#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asdf.h"

int main() {
    char gen_imput = ' ';
    char fede_command[DIM_COMMAND]{};

    int bar_width = 70;
    double bar_increment = 0.01;
    int bar_increment_time_ms = 50;

    bool exitFedeconsole = false;

    printf(MSG_IDLE);
    scanf("%c", &gen_imput);
    printf("\n");
    printf(MSG_STARTING);
    printf("\n");
    // emulateProgressBar(bar_width, bar_increment, bar_increment_time_ms);
    printf("\n");
    printf(MSG_READY);
    while (!exitFedeconsole) {
        printf("\n\n");
        printf(MSG_WAITING_COMMAND);
        scanf("%s", &fede_command);
        if (strcmp(fede_command, COMMAND_HELP) == 0) {
            printf(MSG_COMMAND_HELP);
        }
        else if (strcmp(fede_command, COMMAND_CODE_REQUEST) == 0) {
            printf(MSG_COMMAND_CODE_REQUEST);
        }
        else if (strcmp(fede_command, COMMAND_EXIT) == 0) {
            exitFedeconsole = true;
            printf(MSG_COMMAND_EXIT);
            scanf("%c", &gen_imput);
        }
        else {
            printf("\n");
            printf(MSG_COMMAND_DEFAULT);
        }
    }

    return 0;
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
