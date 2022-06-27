/* 
* Name: Lokesh Patil
* Roll number: cs20b047
* Type your code below this line
* There are no testcases. Mentor TA and Student will play to verify it!
*/
#include<stdio.h>
char board[3][3]; 
char player[2]={'X','O'};// player 1 given X and player 2 given O.
void showconfig(); //prints the array in proper configuration
int checkwin(); //checks if the game results in win or draw.
int checklegal(int,int); //checks for legal input from user.
void putsymbol(int,int,char); //inserts the move in the array.
void init() //all elements of 2D array initialised to blank.
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      board[i][j]=' ';
    }
  }
}
int p=0; //player number
int main()
{
  init();
  showconfig();
  while(1) //runs till a game results in a win or draw.
  {
    int i,j;
    if(p==0 )printf("LOKESH MAKE YOUR MOVE:");
    else printf("ANOOP SIR MAKE YOUR MOVE:");
    scanf("%d %d",&i,&j);
    if(checklegal(i,j)==0) 
    {
      printf("Incorrect move!!\n");
      continue;
    }
    putsymbol(i,j,player[p]);
    int flag=checkwin();
    showconfig();
    if(flag==1 && p==0) 
    {
      printf("LOKESH WON");
      break;
    }
    if(flag==1 && p==1) 
    {
      printf("ANOOP SIR WON");
      break;
    }
    if(flag==2) 
    {
      printf("GAME TIED");
      break;
    }
    p=(p+1)%2;
  }

}
void showconfig()
{
  printf("-------------\n");
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("| %c ",board[i][j]);
    }
    printf("|");
    printf("\n");
    printf("-------------\n");

  }
}

int checklegal(int i,int j)
{
  if(board[i-1][j-1]==' ') return 1;
  else return 0; 
}

void putsymbol(int i,int j, char c)
{
  board[i-1][j-1]=c;
}

int checkwin()
{
  int i,j;
  for(i=0;i<3;i++)//checks rows
  {
    for(j=0;j<3;j++)
    {
      if(board[i][j]!=player[p]) break;
    } 
    if(j==3) return 1;
  }
  for(i=0;i<3;i++) //checks columns
  {
    for(j=0;j<3;j++)
    {
      if(board[j][i]!=player[p]) break;
    }
    if(j==3) return 1;
  }
  //checking diagonals
  for(int i=0;i<3;i++) 
  {
    if(board[i][i]!=player[p]) break;
    if(i==2) return 1;
  }
  for(int i=0;i<3;i++)
  {
    if(board[i][2-i]!=player[p]) break;
    if(i==2) return 1;
  }
  int count=0;
  for(int i=0;i<3;i++) //for checking if game draws.
  {
    for(int j=0;j<3;j++)
    {
     if(board[i][j]!=' ') count++;
    }
  }
  if(count==9) return 2;
  return 0;
}
