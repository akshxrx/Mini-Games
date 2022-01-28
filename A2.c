#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "list.h"

int bingoCorner(int m, int miniBoard[m])
{   
    if (miniBoard[0]==77 && miniBoard[4]==77 && miniBoard[20]==77 && miniBoard[24]==77){
            return 5;
    } return 0;
}

int bingoRow(int m, int miniBoard[m])
{
    int bingo=0;
    for (int u = 0; u<25; u+=5){
    for (int l = u; l < (u+5) ; l++){
        if (miniBoard[l] != 77){
                bingo=0;
                break;
        }
        else {
                bingo+=1;
        }}
    if (bingo == 5){
        return bingo;}
    } return 0;
}

int bingoColumn(int m, int miniBoard[m])
{
    int bingo;
    for (int u = 0; u<5; u++){

    for (int l = u; l < 25 ; l+=5){

            if (miniBoard[l] != 77){
                    bingo=0;
                    break;
            }
            else {
                    bingo+=1;
            }}
            if (bingo == 5){
                return bingo;
    }}return 0;
}

void printFile(int x)
{
  if (x == 0)
    {
        printf("0%im ", x);
    }
    else if (x < 10)
    {
        printf("0%i  ", x);
    } 
    else
    {
        printf("%i  ", x);
    }
}

void printFileM(int x)
{
  if (x == 0)
    {
        printf("0%im ", x);
    }
    else if (x < 10)
    {
        printf("0%im ", x);
    } 
    else
    {
        printf("%im ", x);
    }
}

int range(int i, int j, int val){
  if (i==2 && j==2 && val!=0)
  {
    return 1;
  }
  else if (j==0)
  {
    if(val < 1 || val > 15)
    {
        return 1;
    }   
  }
  else if (j==1)
  {
    if(val < 16 || val > 30)
    {
        return 1;
    }            
  } else if (j==2 && val!=0){  
    if(val < 31 || val > 45 )
    {
        return 1;
    }   
  } else if (j==3){
      if(val < 46 || val > 60)
      {
        return 1;    
      }   
  } else if (j==4){
      if(val < 61 || val > 75)
      {
          return 1;
      }   
  } else
  {
    return 0;
  }
  return 0;
}

int isInt(char *S){
    int i, length;
    length = strlen(S);
    for (i = 0; i < length; i++){
        if (!isdigit(S[i])) return 0;
    }
    return 1;
}

long int SizeOfFile(const char* file_name)
{
    struct stat size; /*declare stat variable*/

    if (stat(file_name, &size) == 0)
        return (size.st_size);
    else
        return -1;
}

int main(int argc, char *argv[]){
    const int x = 5;
    int count = 0;
    int counter = 0;
    int board[5][5];
    int miniBoard[25];
    long int size = 0;
    int winner = 0;
    List callList;
    initialize(&callList);
    int seed;
    char in[50];
    
    size = SizeOfFile(argv[2]);
    FILE * file;
    file = fopen(argv[2], "r");
    seed = atoi(argv[1]);
    srand(seed);

    // error checking
    if (argc != 3){
        fprintf(stderr, "Usage: %s <seed> <cardfile> \n", argv[0]);
        exit(1);
    }
    else if (!isInt(argv[1])){
        fprintf(stderr, "Expected integer seed, but got %s where %s is the user supplied seed\n", argv[1], argv[1]);
        exit(2);
    }
    else if (file == NULL){
        fprintf(stderr, "The %s file is nonexistent or unreadable.\n", argv[2]);
        exit(3); 
    }
    else if (size != 75) {
        fprintf(stderr, "The %s cardfile has incorrect format\n", argv[2]);
        exit(4);
    }

    // storing array & error checking  
    for(int i=0; i<x; i++) {
        for(int j=0; j<x; j++) 
        {   
            fscanf(file,"%d",&board[i][j]);
            miniBoard[count] = board[i][j];
            count++;
            int val = board[i][j];
            if (range(i, j, val) == 1)
            {
              fprintf(stderr, "The %s cardfile has incorrect format\n", argv[2]);
              exit(4);
            }}}
    count = 0;

    // error checking 
    for(int i=0; i<25; i++) {
      for(int j=0; j<25; j++) {
        if (miniBoard[i] == miniBoard[j])
        {
            counter++;
            if (counter > 1)
            {
              fprintf(stderr, "The %s cardfile has incorrect format\n", argv[2]);
              exit(4);
     }}} counter = 0;}

    // printing board
    system("clear");
    printf("%s\n","Calllist is: ");
    printf("\n%s\n","L   I   N   U   X");
    for(int i=0; i<x; i++) {
        for(int j=0; j<x; j++) {
                printFile(board[i][j]); 
    } printf("\n"); }
    while (winner != 1){
        printf("enter any non-enter key for Call (q to quit): ");
        fgets(in, 50, stdin);
        int i, random, len;
        len = strlen(in)-1;
        for (i=0;i<len;i++){
            if (in[i] == 'q'){
                    system("clear");
                    printf("%s","Calllist is: ");
                    print(callList);
                    printf("\n%s\n","L   I   N   U   X");
                    for(int i=0; i<5; i++) {
                        for(int j=0; j<5; j++) {
                            int x = board[i][j];
                            if (search(callList, x)){
                                printFileM(board[i][j]);
                            }
                            else{
                                printFile(board[i][j]);
                            }

                    } printf("\n"); }

                    exit(0);
            }
            random = ( rand()%75 ) + 1;
            while (search(callList, random)){
                random = ( rand()%75 ) + 1;
            }
            add(&callList, random);
        }
    system("clear");
    printf("%s","Calllist is: ");
    print(callList);
    printf("\n%s\n","L   I   N   U   X");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            int x = board[i][j];
            if (search(callList, x)){
                printFileM(board[i][j]);
            }
            else{
                printFile(board[i][j]);
            }} printf("\n"); }
    for (int i = 0; i < 25; i++)
    {
        miniBoard[12] = 77;
        int x = miniBoard[i];
        if (search(callList, x)){
            miniBoard[i] = 77;
        } 
    }
    if(bingoColumn(25, miniBoard) == 5 || bingoRow(25, miniBoard) == 5 || bingoCorner(25, miniBoard) == 5)
    {
        printf("WINNER\n");
        winner = 1;
    }}
    fclose(file);
    return 0;
}