#include <stdio.h>
#include <string.h>

struct ddmm {
    char day[3];
    char month[3];
};

int strToInt(const char* str);

struct ddmm charToDdmm(const char* date);

int main() {
    char date[6];
    scanf("%5s", date);

    struct ddmm Date = charToDdmm(date);

    int dayInt = strToInt(Date.day);
    int monthInt = strToInt(Date.month);

    if ((monthInt == 12 && dayInt >= 25) || 
        (monthInt == 1 && dayInt <= 1)) {
        printf("Holiday\n");
    } else {
        printf("Not Holiday\n");
    }
    return 0;
}

int strToInt(const char* str){
    return (str[0] - '0') * 10 + (str[1] - '0');
}

struct ddmm charToDdmm(const char* date) {
    struct ddmm MyDate;
    strncpy(MyDate.day, date, 2);
    MyDate.day[2] = '\0';
    strncpy(MyDate.month, date + 3, 2);
    MyDate.month[2] = '\0';
    return MyDate;
}