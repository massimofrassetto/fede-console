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
#define DEFAULT_CODE_CHECK               "4s74-r10n-f4sk-1f0"           //Querto codice viene restituito soltanto se viene fornito il codice "DEFAULT_CODE_ADMIN"

// NON TRADURRE LA SEZIONE DEI COMANDI
#define COMMAND_HELP                     "help"
#define COMMAND_CODE_REQUEST             "codereq"
#define COMMAND_PROTOCOLS                "protocols"
#define COMMAND_CREDITS                  "credits"
#define COMMAND_EXIT                     "exit"
#define COMMAND_CODE_QUIT                "/quit"

#define PROTOCOL_RIDDLE                  "INDOVINELLI"
#define PROTOCOL_CRUCIVERBA              "CRUCIVERBA"
#define PROTOCOL_CHESS                   "SCACCHI"
#define PROTOCOL_SONG                    "CANZONE"

#define PROTOCOL_RIDDLE_CODE_SEC         "AB"				// In attesa di marconi
#define PROTOCOL_RIDDLE_CODE_CHECK       "4s74"
#define PROTOCOL_CRUCIVERBA_CODE_SEC     "DE"				// In attesa di rachele
#define PROTOCOL_CRUCIVERBA_CODE_CHECK   "r10n"
#define PROTOCOL_CHESS_CODE_SEC          "HI"				// In attesa di sangiorgi
#define PROTOCOL_CHESS_CODE_CHECK        "f4sk"
#define PROTOCOL_SONG_CODE_SEC           "credente"
#define PROTOCOL_SONG_CODE_CHECK         "1f0"

#define MSG_IDLE                         "[Press enter to boot console.]"
#define MSG_STARTING                     "Inizializzazione sistema in corso..."
#define MSG_READY                        "Sistema pronto!"
#define MSG_SEPARATOR_LINE               "-----------------------------------------------------------------------------------------\n"

#define MSG_WAITING_COMMAND              "Inserire comando ('%s' per ulteriori info): "

enum MSG_HELPER_TYPE {
	MSG_HELPER_TYPE_CMD,                  // 0 - Command
	MSG_HELPER_TYPE_PROT,                 // 1 - Protocols
};

#define MSG_HELPER_ERROR_HEADER          "[ERROR] Tipologia header %i non trovata! Verificare codice. "

#define MSG_HELPER_COMMAND_H             "Elenco dei comandi disponibili e la relativa descrizione."
#define MSG_HELPER_COMMAND_C             "Comando per accedere ai moduli di richiesta dei codici di controllo alfanumerici dei singoli protocolli."
#define MSG_HELPER_COMMAND_P             "Elenco dei protocolli disponibili."
#define MSG_HELPER_COMMAND_CREDITS       "Info sui creatori."
#define MSG_HELPER_COMMAND_E             "Termina la console."
#define MSG_HELPER_NOTE_GENERAL          "----\n! ATTENZIONE !\tLa console e' Case Sensitive.\n\tTutti i COMANDI sono in minuscolo e tutti i codici di SICUREZZA sono in maiuscolo."

#define MSG_HELPER_PROT_RIDDLE           "Il protocollo consiste nel rispondere correttamente ad una serie di domande di 'cultura generale'."
#define MSG_HELPER_PROT_CRUCIVERBA       "Il protocollo consiste nel risolvere un cruciverba. Attenzione ad alcune caselle!"
#define MSG_HELPER_PROT_CHESS            "Il protocollo consiste nel rispondere correttamente ad una certa situazione sulla scacchiera."
#define MSG_HELPER_PROT_SONG             "Il protocollo consiste nel cantare interamente una canzone, già tradotta professionalmente, e indovinandone il nome."

#define MSG_COMMAND_CODE_REQUEST         "Avviata procedura per la richiesta dei codici di controllo."
#define MSG_PROTOCOL_ACCEPTED            "Protocollo richiesto presente nel sistema."
#define MSG_PROTOCOL_USER_REQ            "Inserire il PROTOCOLLO desiderato ('%s' per annullare): "
#define MSG_PROTOCOL_DENIED              "[ERROR] Protocollo non presente nel sistema. Richiesta NEGATA!"

#define MSG_PROTOCOL_CODE_SEC_USER_REQ   "Inserire codice di SICUREZZA per il protocollo '%s' ('%s' per annullare): "
#define MSG_PROTOCOL_CODE_SEC_ACCEPTED   "Codice di sicurezza per il protocollo %s verificato con successo.\n\tDi seguito il codice di controllo relativo: \t[ %s ]"
#define MSG_PROTOCOL_CODE_SEC_DENIED     "[ERROR] Codice di sicurezza errato! Provare nuovamente."
#define MSG_PROTOCOL_AUTOMATIC_RETURN    "Ritorno automaticamente al menu precedente..."


#define MSG_COMMAND_CODE_DENIED          "[ERROR] Codice di controllo non presente nel sistema!\nInserire codice di controllo del protocollo richiesto: "
#define MSG_COMMAND_EXIT                 "Console terminata con successo!\nPremere enter per chiudere la finestra."
#define MSG_COMMAND_DEFAULT              "[ERROR] Comando non riconosciuto. Richiesta NEGATA!"

#define MSG_COMMAND_CODE_QUIT            "Richiesta annullata dall'utente. Ritorno al menu precedente..."

// NON TRADURRE LA SEZIONE DEI CREDITS
#define MSG_CREDITS_BORDERS                 "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
#define MSG_CREDITS_LINE_0                  "\tConsole creata da Frassetto Massimo in data 01/04/2024.\n"
#define MSG_CREDITS_LINE_1                  "\tL'applicazione e' stata creata per festeggiare la Laurea di Federica Bugnoli.\n"
#define MSG_CREDITS_LINE_2                  "\tI Ringraziamenti vanno a\n"
#define MSG_CREDITS_LINE_3                  "\t\t - Bartolini Rachele\n"
#define MSG_CREDITS_LINE_4                  "\t\t - Marconi Silvia\n"
#define MSG_CREDITS_LINE_5                  "\t\t - Sangiorgi Silvia\n"
#define MSG_CREDITS_LINE_6                  "\tPer aver testato il programma e consigliato."


#ifdef DEBUG
	void scriviMonitor();
#endif // DEBUG

void logoPrint();
void creditsPrint();
void emulateProgressBar(int barWidth, float increment, int time_load);
void helperHeaderline(int type);
void protocolCodeRequest(char (*protocol_name)[DIM_PROTOCOL], char (*protocol_code)[DIM_CODE], char (*protocol_check_code)[DIM_CODE]);