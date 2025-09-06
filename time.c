#include<stdio.h> 
#include<time.h>
#include<unistd.h>
int main(){
  printf("Current Time\n");
  while(1){
    time_t currentTime;
    time(&currentTime);
    struct tm *t=localtime(&currentTime);
    int hour=t->tm_hour;
    if(hour>12){
      hour=hour-12;
    }
    int min=t->tm_min;
    int sec=t->tm_sec;
    printf("%02d:",hour);
    printf("%02d:",min);
    printf("%02d\r",sec);
    usleep(10000);
  }
  printf("showing your cursor\n");
  return 0;
}
