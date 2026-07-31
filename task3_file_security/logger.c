#include <stdio.h>
#include <time.h>
#include "logger.h"

void logAction(const char *action, const char *filename)
{
    FILE *logFile;
    time_t now;
    char *timeStr;

    logFile = fopen("audit_log.txt", "a");

    if (logFile == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    now = time(NULL);
    timeStr = ctime(&now);

    fprintf(logFile, "[%s] %s : %s\n", timeStr, action, filename);

    fclose(logFile);
}
