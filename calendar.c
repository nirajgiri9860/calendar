#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int i, j, error=0, n, m=0, day, nlast, monthd, md, yd, days[40];
    long int totald, rst;
    char z, temp[20];
    char mc1[] = "January", mc2[] = "February", mc3[] = "March", mc4[] = "April", mc5[] = "May", mc6[] = "June";
    char mc7[] = "July", mc8[] = "August", mc9[] = "September", mc10[] = "October", mc11[] = "November", mc12[] = "December";
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the month in integer: ");
    scanf("%d", &md);
    printf("Enter year: ");
    scanf("%d", &yd);
    if(md==1){
        strcpy(temp, mc1);
        monthd = 31;
        nlast = 31;}
    else if(md==2){
        strcpy(temp, mc2);
        if(yd%4==0){
            nlast = 29;
            monthd = 60;
        }
        else{
            nlast = 28;
            monthd = 59;
        }
    }
    else if(md==3){
        strcpy(temp, mc3);
        if(yd%4==0){
            monthd = 91;
        }else{
            monthd = 90;
        }
        nlast = 31;}
    else if(md==4){
        strcpy(temp, mc4);
        if(yd%4==0){
            monthd = 121;
        }else{
            monthd = 120;
        }
        nlast = 30;}
    else if(md==5){
        strcpy(temp, mc5);
        if(yd%4==0){
            monthd = 152;
        }else{
            monthd = 151;
        }
        nlast = 31;}
    else if(md==6){
        strcpy(temp, mc6);
        if(yd%4==0){
            monthd = 182;
        }else{
            monthd = 181;
        }
        nlast = 30;}
    else if(md==7){
        strcpy(temp, mc7);
        if(yd%4==0){
            monthd = 213;
        }else{
            monthd = 212;
        }
        nlast = 31;}
    else if(md==8){
        strcpy(temp, mc8);
        if(yd%4==0){
            monthd = 244;
        }else{
            monthd = 243;
        }
        nlast = 31;}
    else if(md==9){
        strcpy(temp, mc9);
        if(yd%4==0){
            monthd = 274;
        }else{
            monthd = 273;
        }
        nlast = 30;}
    else if(md==10){
        strcpy(temp, mc10);
        if(yd%4==0){
            monthd = 305;
        }else{
            monthd = 304;
        }
        nlast = 31;}
    else if(md==11){
        strcpy(temp, mc11);
        if(yd%4==0){
            monthd = 335;
        }else{
            monthd = 334;
        }
        nlast = 30;}
    else if(md==12){
        strcpy(temp, mc2);
        if(yd%4==0){
            monthd = 366;
        }else{
            monthd = 365;
        }
        nlast = 31;}
    if(day>nlast){
        printf("\n* Error in data: Day\n");
        error++;
    }
    if(md>12){
        printf("\n* Error in data: Month\n");
        error++;
    }

    if(error!=0){
        exit(0);
    }

    printf("\n----------------------------------------------------\n");
    printf("\t\t   %s %d ", temp, yd);
    printf("\n----------------------------------------------------\n\n");
    printf(" Sun\tMon\tTue\tWed\tThu\tFri\tSat \n");

    //calculating
    n = 0;
    totald = (365*(yd-1)) + ((yd-1)/4) + monthd - nlast + n;
    rst = totald%7;
    //storing value in array
    for(i=0; i<40; i++){
        if(i>=rst){
            m++;
        }
        days[i] = 0 + m;
        if(days[i]>32){
            break;
        }
    }
    //printing array value
    for(j=0; days[j]<=nlast; j++){
        if(days[j]==0){
            printf(" \t");
        }
        else if(days[j]==day){
            printf("%d\t", days[j]);
        }
        else{
            printf(" %d\t", days[j]);
        }
        if((j+1)%7==0){
            printf("\n");
        }
    }
    printf("\n\n");
    printf("Exiting the program in ");
    for(i=3; i>=0; i--){
        printf("%d ", i);
        sleep(1);
    }
    return 0;
}
