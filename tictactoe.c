#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

int Print();
void loadScreen();
int record();
void ExitGame();
void playAgain();
void viewRecord();

int main()
{
    Print();
    // printf("%c", Print());
    loadScreen();
    ExitGame();
}

int Print()
{
    char in;
    system("cls");
    printf("Welcome to tictactoe!\n\n");
    printf("Game instructions:\n");
    printf("\nGet three 'X' in a row to win\n");
    printf("\nPress (1) for one player (2) for two player & (3) to quit...");
    in = getch();
    if(in == '3')
    {
        exit(0);
    }
    system("cls");
    return in;
}

void loadScreen()
{
    int r,q;
    printf("\n\tloading...\n\n");
    for(r=1; r<=26; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",1);
    }
    system("cls");
}

void ExitGame()
{
    printf("Awhhh, damn it! Next time : )\n\n");
    record();
    exit(1);
}

int record()
{
    char plname[20], charac, c;
    int i, j, px;
    FILE *info;
    info=fopen("record.txt","a+");
    printf("Enter your name: ");
    // scanf("%[^\n]",plname); // reads untill the end of the line or start of new line
    fgets(plname, 100, stdin);
    for(j=0; plname[j]!='\0'; j++) //to convert the first letter after space to capital
    {                              // \0 null checker
        plname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            plname[j]=toupper(plname[j]);
        }
    }
    
    time_t mytime;
    mytime = time(NULL);

    fprintf(info,"\nPlayer Name: %s",plname);
    fprintf(info,"Played Date: %s",ctime(&mytime));
    //fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
    fprintf(info, "___________________________________________________\n");
    fclose(info);
    viewRecord();
}

void viewRecord()
{
    char charac, c;
    FILE *info;
    printf("\nTo view past records press 'y' and 'n' otherwise");
    charac=getch();
    system("cls");
    if(charac=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info)); // printing
        }
        while(c!=EOF);
    } else if(charac=='n')
    {
        playAgain();
    } 
    fclose(info);

    printf("\n\nTo clear past records press 'y' and 'n' otherwise");
    charac=getch();
    system("cls");
    if(charac=='y')
    {
        printf("Cleared : )");
        fclose(fopen("record.txt", "w"));
        playAgain();

    } else if (charac == 'n')
    {
        playAgain();
        
    }
}

void playAgain()
{
    char charac;
    system("cls");
    printf("\nWould you like to play again? 'y' for yes and 'q' to quit: ");
    charac=getch();
    if (charac=='y')
    {
        system("cls");
        main();
    } else
    {
        printf("\n\nSee you next time : ) ");
        exit(0);
    }
}