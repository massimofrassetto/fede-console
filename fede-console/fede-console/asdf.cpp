#include "asdf.h"

//===========[ Da mettere nel file "c" ]===================================================================

#ifdef DEBUG
    void scriviMonitor() {
        printf("ciaaaaaaaaaaaaaaao\n");
    }
#endif // DEBUG

void logoPrint() {
    printf("\n");
    printf(MSG_LOGO_LINE_0);
    printf(MSG_LOGO_LINE_1);
    printf(MSG_LOGO_LINE_2);
    printf(MSG_LOGO_LINE_3);
    printf(MSG_LOGO_LINE_4);
    printf("\n");
}

void creditsPrint() {
    printf("\n");
    printf(MSG_CREDITS_BORDERS);
    printf("\n\n");
    printf(MSG_CREDITS_LINE_0);
    printf(MSG_CREDITS_LINE_1);
    printf(MSG_CREDITS_LINE_2);
    printf(MSG_CREDITS_LINE_3);
    printf(MSG_CREDITS_LINE_4);
    printf(MSG_CREDITS_LINE_5);
    printf(MSG_CREDITS_LINE_6);
    printf("\n\n");
    printf(MSG_CREDITS_BORDERS);
    printf("\n");
}

void emulateProgressBar(int barWidth, float increment, int time_load) {
    // int barWidth = 70;
    // float increment = 0.01;
    // int time_load = 50;
    float progress = 0.0;
    int percentage = 0;
    while (progress <= 1.0 + increment) {
        printf("[");
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) printf("=");
            else if (i == pos) printf(">");
            else printf(" ");
        }
        percentage = int(100.0 * progress);
        printf("] %i%%\r", percentage);
        // std::cout.flush();

        progress += increment; // for demonstration only
        Sleep(time_load);
    }
    printf("\n");
}

void helperHeaderline(int header_type) {
    printf("\n");
    if (header_type == MSG_HELPER_TYPE_CMD) {
        printf("  COMMAND\tDESCRIPTION");
    }
    else if (header_type == MSG_HELPER_TYPE_PROT) {
        printf("  PROTOCOL\tDESCRIPTION");
    }
    else {
        printf(MSG_HELPER_ERROR_HEADER, header_type);
    }
    printf("\n\n");
}

void protocolCodeRequest(char (*protocol_name)[DIM_PROTOCOL], char (*protocol_code)[DIM_CODE], char (*protocol_check_code)[DIM_CODE]) {
    char user_command[DIM_COMMAND]{};
    bool protocolCodeVerified = false;

    printf("\n");
    printf(MSG_PROTOCOL_ACCEPTED);
    while (!protocolCodeVerified && !(strcmp(user_command, COMMAND_CODE_QUIT) == 0)) {
        printf("\n");
        printf(MSG_PROTOCOL_CODE_SEC_USER_REQ, *protocol_name, COMMAND_CODE_QUIT);
        scanf("%s", &user_command);
        if (strcmp(user_command, *protocol_code) == 0) {
            protocolCodeVerified = true;
            protocolCodeVerified = true;
            printf("\n");
            printf(MSG_PROTOCOL_CODE_SEC_ACCEPTED, *protocol_name, *protocol_check_code);
            printf("\n\n");
            printf(MSG_PROTOCOL_AUTOMATIC_RETURN);
            printf("\n");
        }
        else if (strcmp(user_command, COMMAND_CODE_QUIT) == 0) {
            printf("\n");
            printf(MSG_COMMAND_CODE_QUIT);
        }
        else {
            printf("\n");
            printf(MSG_PROTOCOL_CODE_SEC_DENIED);
        }
    }
    *user_command = ' ';
}

//void helperCommandSection(char command[], int dim_command, char description[], int dim_description) {
//    printf("%s\t\t%s", );
//
//}
