//#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_COMMAND 16

#define MSG_IDLE                 "[Press enter to boot console.]"
#define MSG_STARTING             "Inizializzazione sistema in corso..."
#define MSG_READY                "Sistema pronto!"
#define MSG_WAITING_COMMAND      "Inserire comando ('help' per ulteriori info): "
#define MSG_COMMAND_HELP         "Di seguiti comandi disponibili:\n\n  help\t\tElenco comandi.\n\n  codereq\tPermette di richiedere il codice di controllo.\n\n  exit\t\tChiude la console.\n\n"
#define MSG_COMMAND_CODE_REQUEST "Avviata procedura per la richiesta del codice di controllo.\nInserire CODICE AMMINISTRATORE:"
#define MSG_COMMAND_EXIT         "Console terminata con successo!\nPremere enter per chiudere la finestra."
#define MSG_COMMAND_DEFAULT      "Comando non riconosciuto. Richiesta NEGATA!"

#define COMMAND_HELP             "help"
#define COMMAND_CODE_REQUEST     "codereq"
#define COMMAND_EXIT             "exit"


void emulateProgressBar(int barWidth, float increment, int time_load);
void scriviMonitor();