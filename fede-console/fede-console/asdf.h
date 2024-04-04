//#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_COMMAND                      33
#define DIM_PROTOCOL                     33
#define DIM_CODE                         33

#define MSG_LOGO_LINE_0                  "\t    ____         __                                   __    \n"
#define MSG_LOGO_LINE_1                  "\t   / __/__  ____/ /__    _________  ____  _________  / /__  \n"
#define MSG_LOGO_LINE_2                  "\t  / /_/ _ \\/ __  / _ \\  / ___/ __ \\/ __ \\/ ___/ __ \\/ / _ \\ \n"
#define MSG_LOGO_LINE_3                  "\t / __/  __/ /_/ /  __/ / /__/ /_/ / / / (__  ) /_/ / /  __/ \n"
#define MSG_LOGO_LINE_4                  "\t/_/  \\___/\\__,_/\\___/  \\___/\\____/_/ /_/____/\\____/_/\\___/  \n"

#define DEFAULT_CODE_ADMIN               "BRST18H"						//Questo codice è quello necessario per ottenere quello di controllo "DEFAULT_CODE_CHECK"
#define DEFAULT_CODE_CHECK               "4s74r10nf4sk1f0"				//Querto codice viene restituito soltanto se viene fornito il codice "DEFAULT_CODE_ADMIN"

#define COMMAND_HELP                     "help"
#define COMMAND_CODE_REQUEST             "codereq"
#define COMMAND_PROTOCOLS                "protocols"
#define COMMAND_EXIT                     "exit"
#define COMMAND_CODE_QUIT                "/quit"

#define PROTOCOL_RIDDLE                  "INDOVINELLI"
#define PROTOCOL_CRUCIVERBA              "CRUCIVERBA"
#define PROTOCOL_CHESS                   "SCACCHI"
#define PROTOCOL_SONG                    "CANZONE"

#define PROTOCOL_RIDDLE_CODE             "AB"
#define PROTOCOL_RIDDLE_CHECK            "CD"
#define PROTOCOL_CRUCIVERBA_CODE         "DE"
#define PROTOCOL_CRUCIVERBA_CHECK        "FG"
#define PROTOCOL_CHESS_CODE              "HI"
#define PROTOCOL_CHESS_CHECK             "LM"
#define PROTOCOL_SONG_CODE               "OS"
#define PROTOCOL_SONG_CHECK              "CAR"

#define MSG_IDLE                         "[Press enter to boot console.]"
#define MSG_STARTING                     "Inizializzazione sistema in corso..."
#define MSG_READY                        "Sistema pronto!"
#define MSG_SEPARATOR_LINE               "-----------------------------------------------------------------------------------------\n"
#define MSG_WAITING_COMMAND              "Inserire comando ('%s' per ulteriori info): "
#define MSG_HELPER_COMMAND_H             "Elenco dei comandi disponibili e la relativa descrizione."
#define MSG_HELPER_COMMAND_C             "Comando per accedere ai moduli di richiesta dei codici di controllo dei singoli protocolli."
#define MSG_HELPER_COMMAND_P             "Elenco dei protocolli disponibili."
#define MSG_HELPER_COMMAND_E             "Termina la console."
#define MSG_COMMAND_CODE_REQUEST         "Avviata procedura per la richiesta del codice di ritorno."
#define MSG_COMMAND_CODE_ACCEPTED        "Codice protocollo verificato con successo.\nCodice di controllo per il protocollo %s: %s"
#define MSG_PROTOCOL_CHECK_ACCEPTED      "Codice di controllo per il protocollo ''%s'' verificato con successo.\nCodice di ritorno: %s"
#define MSG_COMMAND_CODE_DENIED          "[ERROR] Codice di controllo non presente nel sistema!\nInserire codice di controllo del protocollo richiesto: "
#define MSG_COMMAND_CODE_QUIT            "Richiesta annullata dall'utente. Ritorno al menu precedente..."
#define MSG_COMMAND_EXIT                 "Console terminata con successo!\nPremere enter per chiudere la finestra."
#define MSG_COMMAND_DEFAULT              "[ERROR] Comando non riconosciuto. Richiesta NEGATA!"


#ifdef DEBUG
	void scriviMonitor();
#endif // DEBUG

void logoPrint();
void emulateProgressBar(int barWidth, float increment, int time_load);
void helperHeaderline();
void protocolCodeRequest(char (*protocol_name)[DIM_PROTOCOL], char (*protocol_code)[DIM_CODE], char (*protocol_check_code)[DIM_CODE]);