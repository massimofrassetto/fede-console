#include "asdf.h"

//===========[ Da mettere nel file "c" ]===================================================================

#ifdef DEBUG

void scriviMonitor() {
    printf("ciaaaaaaaaaaaaaaao\n");
}

#endif // DEBUG

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