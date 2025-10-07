#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void displayClock(int hours, int minutes, int seconds);
void clear_console_flicker_free();
void clear_console_ansi();

int main() {

    time_t currentTime;
    currentTime = time(NULL); // Pass NULL to get the return value directly

    struct tm* localTimeInfo;
    localTimeInfo = localtime(&currentTime);
    
    int hours = localTimeInfo->tm_hour;
    int minutes = localTimeInfo->tm_min;
    int seconds = localTimeInfo->tm_sec;

    clock_t start_time, end_time;
    double cpu_time_used = 0.0;

    while (1==1) {
        
        // clear_console_flicker_free();
        displayClock(hours, minutes, seconds);
        start_time = clock();
        cpu_time_used = 0.0;

        seconds++;

        if(seconds == 60) {
            seconds = 0;
            minutes++;
        }

        if(minutes == 60) {
            minutes = 0;
            hours++;
        }

        if (hours == 24) {
            hours = 0;
        }

        while (cpu_time_used < 1.0)
        {
            end_time = clock();
            
            cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        }
    }

    return 0;
}

void displayClock(int hours, int minutes, int seconds) {
    printf("\r%02d:%02d:%02d", hours, minutes, seconds);
}

void clear_console_flicker_free() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0}; // Top-left corner
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with spaces
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Fill the entire screen with the current attributes
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Move the cursor to the top-left corner
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void clear_console_ansi() {
    // Clear screen and move cursor to home position
    printf("\x1b[2J\x1b[H"); 
    fflush(stdout); // Ensure the output is sent immediately
}