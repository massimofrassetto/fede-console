//#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_COMMAND                      17
#define DIM_MSG_HELP_DESCRIPTION_COMMAND 129

#define DEFAULT_CODE_ADMIN               "BRST18H"						//Questo codice è quello necessario per ottenere quello di controllo "DEFAULT_CODE_CHECK"
#define DEFAULT_CODE_CHECK               "3482AES5YB"					//Querto codice viene restituito soltanto se viene fornito il codice "DEFAULT_CODE_ADMIN"

#define COMMAND_HELP                     "help"
#define COMMAND_CODE_REQUEST             "codereq"
#define COMMAND_CODE_QUIT                "/quit"
#define COMMAND_EXIT                     "exit"

#define MSG_IDLE                  "[Press enter to boot console.]"
#define MSG_STARTING              "Inizializzazione sistema in corso..."
#define MSG_READY                 "Sistema pronto!"
#define MSG_SEPARATOR_LINE        "-----------------------------------------------------------------------------------------\n"
#define MSG_WAITING_COMMAND       "Inserire comando ('help' per ulteriori info): "
#define MSG_HELPER_COMMAND_H      "Elenco comandi."
#define MSG_HELPER_COMMAND_C      "Permette di richiedere il codice di controllo."
#define MSG_HELPER_COMMAND_E      "Chiude la console."
#define MSG_COMMAND_CODE_REQUEST  "Avviata procedura per la richiesta del codice di controllo ('/quit' per annullare).\nInserire CODICE AMMINISTRATORE:"
#define MSG_COMMAND_CODE_ACCEPTED "Codice amministratore verificato con successo.\nCodice di controllo: %s"
#define MSG_COMMAND_CODE_DENIED   "[ERROR] Codice amministratore non presente nel sistema.\nInserire nuovamente CODICE AMMINISTRATORE:"
#define MSG_COMMAND_CODE_QUIT     "Richiesta del codice di controllo annullata. Ritorno al menu precedente..."
#define MSG_COMMAND_EXIT          "Console terminata con successo!\nPremere enter per chiudere la finestra."
#define MSG_COMMAND_DEFAULT       "Comando non riconosciuto. Richiesta NEGATA!"


#ifdef DEBUG
	void scriviMonitor();
#endif // DEBUG

void emulateProgressBar(int barWidth, float increment, int time_load);
void helperHeaderline();