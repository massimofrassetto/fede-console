// fede-console.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
// 
// *** NOTA IMPORTANTE ***
// Per evitare problemi tra il compilatore e la funzione "scanf" è stato necessario modificare le impostazioni al preprocessore.
// LA PROCEDURA È DA RIPETERE PER TUTTE LE CONFIGURAZIONI DI COMPILAZIONE!!
// Di seguito i passi applicati:
//  - Progetto > Proprieta' [nome_progetto] > C/C++ > Definizioni Preprocessore
//  - Aggiungere la stringa "_CRT_SECURE_NO_WARNINGS" in fondo (usare ";" per dividere gli argomenti).
// // ********************
//

// #define DEBUG

//#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asdf.h"

int main() {
    char gen_imput = ' ';
    char fede_command[DIM_COMMAND]{};
    //char prot[DIM_COMMAND];
    //char prot_code[DIM_PROTOCOL];
    //char prot_check[DIM_CODE];
    
    char massimo_string_test[DIM_COMMAND]{};

    int bar_width = 70;
    double bar_increment = 0.01;
    int bar_increment_time_ms = 50;

    bool exitFedeConsole = false;

    printf(MSG_IDLE);
    scanf("%c", &gen_imput);
    logoPrint();
    printf("\n");
    printf(MSG_STARTING);
    printf("\n");
    emulateProgressBar(bar_width, bar_increment, bar_increment_time_ms);
    printf("\n");
    printf(MSG_READY);
    while (!exitFedeConsole) {
        printf("\n\n");
        printf(MSG_SEPARATOR_LINE);
        printf(MSG_WAITING_COMMAND, COMMAND_HELP);
        fflush(stdin);
        scanf("%s", &fede_command);
        if (strcmp(fede_command, COMMAND_HELP) == 0) {
            helperHeaderline(MSG_HELPER_TYPE_CMD);
            printf("  %s\t\t%s", COMMAND_HELP,         MSG_HELPER_COMMAND_H);
            printf("\n\n");
            printf("  %s\t%s",   COMMAND_CODE_REQUEST, MSG_HELPER_COMMAND_C);
            printf("\n\n");
            printf("  %s\t%s",   COMMAND_PROTOCOLS,    MSG_HELPER_COMMAND_P);
            printf("\n\n");
            printf("  %s\t%s",   COMMAND_CREDITS,      MSG_HELPER_COMMAND_CREDITS);
            printf("\n\n");
            printf("  %s\t\t%s", COMMAND_EXIT,         MSG_HELPER_COMMAND_E);
            printf("\n\n");
            printf("%s",         MSG_HELPER_NOTE_GENERAL);
            printf("\n");
        }
        else if (strcmp(fede_command, COMMAND_PROTOCOLS) == 0) {
            helperHeaderline(MSG_HELPER_TYPE_PROT);
            printf("  %s\t%s", PROTOCOL_RIDDLE,     MSG_HELPER_PROT_RIDDLE);
            printf("\n\n");
            printf("  %s\t%s", PROTOCOL_CRUCIVERBA, MSG_HELPER_PROT_CRUCIVERBA);
            printf("\n\n");
            printf("  %s\t%s", PROTOCOL_CHESS,      MSG_HELPER_PROT_CHESS);
            printf("\n\n");
            printf("  %s\t%s", PROTOCOL_SONG,       MSG_HELPER_PROT_SONG);
            printf("\n");
        }
        else if (strcmp(fede_command, COMMAND_CODE_REQUEST) == 0) {
            printf("\n");
            printf(MSG_COMMAND_CODE_REQUEST);

            while (!(strcmp(fede_command, COMMAND_CODE_QUIT) == 0)) {
                printf("\n");
                printf(MSG_PROTOCOL_USER_REQ, COMMAND_CODE_QUIT);
                scanf("%s", &fede_command);
                if (strcmp(fede_command, PROTOCOL_RIDDLE) == 0) {
                    char prot[DIM_PROTOCOL] =   PROTOCOL_RIDDLE;
                    char prot_code[DIM_CODE] =  PROTOCOL_RIDDLE_CODE_SEC;
                    char prot_check[DIM_CODE] = PROTOCOL_RIDDLE_CODE_CHECK;
                    //&prot =       PROTOCOL_RIDDLE;
                    //&prot_code =  PROTOCOL_RIDDLE_CODE_SEC;
                    //&prot_check = PROTOCOL_RIDDLE_CODE_CHECK;
                    protocolCodeRequest(&prot, &prot_code, &prot_check);
                }
                else if (strcmp(fede_command, PROTOCOL_CRUCIVERBA) == 0) {
                    char prot[DIM_PROTOCOL] =   PROTOCOL_CRUCIVERBA;
                    char prot_code[DIM_CODE] =  PROTOCOL_CRUCIVERBA_CODE_SEC;
                    char prot_check[DIM_CODE] = PROTOCOL_CRUCIVERBA_CODE_CHECK;
                    //prot =       PROTOCOL_CRUCIVERBA;
                    //prot_code =  PROTOCOL_CRUCIVERBA_CODE_SEC;
                    //prot_check = PROTOCOL_CRUCIVERBA_CODE_CHECK;
                    protocolCodeRequest(&prot, &prot_code, &prot_check);
                }
                else if (strcmp(fede_command, PROTOCOL_CHESS) == 0) {
                    char prot[DIM_PROTOCOL] =   PROTOCOL_CHESS;
                    char prot_code[DIM_CODE] =  PROTOCOL_CHESS_CODE_SEC;
                    char prot_check[DIM_CODE] = PROTOCOL_CHESS_CODE_CHECK;
                    //prot =       PROTOCOL_CHESS;
                    //prot_code =  PROTOCOL_CHESS_CODE_SEC;
                    //prot_check = PROTOCOL_CHESS_CODE_CHECK;
                    protocolCodeRequest(&prot, &prot_code, &prot_check);
                }
                else if (strcmp(fede_command, PROTOCOL_SONG) == 0) {
                    char prot[DIM_PROTOCOL] =   PROTOCOL_SONG;
                    char prot_code[DIM_CODE] =  PROTOCOL_SONG_CODE_SEC;
                    char prot_check[DIM_CODE] = PROTOCOL_SONG_CODE_CHECK;
                    //prot =       PROTOCOL_SONG;
                    //prot_code =  PROTOCOL_SONG_CODE_SEC;
                    //prot_check = PROTOCOL_SONG_CODE_CHECK;
                    protocolCodeRequest(&prot, &prot_code, &prot_check);
                }
                else if (strcmp(fede_command, COMMAND_CODE_QUIT) == 0) {
                    printf("\n");
                    printf(MSG_COMMAND_CODE_QUIT);
                }
                else {
                    printf("\n");
                    printf(MSG_PROTOCOL_DENIED);
                }
            }
        }
        else if (strcmp(fede_command, COMMAND_CREDITS) == 0) {
            creditsPrint();
        }
        else if (strcmp(fede_command, COMMAND_EXIT) == 0) {
            exitFedeConsole = true;
            printf("\n");
            printf(MSG_COMMAND_EXIT);
            scanf("%c", &gen_imput);
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





            //if (protocolIsPresent){
            //    protocolCodeRequest(&prot, &prot_code, &prot_check);
            //}

            /*codeAdminVerified = false;
            while (!codeAdminVerified && !(strcmp(fede_command, COMMAND_CODE_QUIT) == 0)) {
                scanf("%s", &fede_command);
                if (strcmp(fede_command, DEFAULT_CODE_ADMIN) == 0) {
                    codeAdminVerified = true;
                    printf("\n");
                    printf(MSG_PROTOCOL_CODE_SEC_ACCEPTED, PROTOCOL_RIDDLE, DEFAULT_CODE_CHECK);
                }
                else if (strcmp(fede_command, COMMAND_CODE_QUIT) == 0) {
                    printf("\n");
                    printf(MSG_COMMAND_CODE_QUIT);
                }
                else {
                    printf("\n");
                    printf(MSG_COMMAND_CODE_DENIED);
                }
            }*/