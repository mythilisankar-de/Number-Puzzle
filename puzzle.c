#include<stdio.h>
#include <stdlib.h>
void gamerules()
{
    printf("                                                  Instructions\n");
    printf("                            ***********   press '8' for moving upward               ***********\n");
    printf("                            ***********   press '2' for moving downward             ***********\n");
    printf("                            ***********   press '4' for moving left                 ***********\n");
    printf("                            ***********   press '6' for moving right                ***********\n");
}
void printmatrix(int matrix[100][100],int n,int move)
{
	system("cls");
	printf("\n\n");
	printf("                                                       *-*-*-*-*-*-*-*-*-*-*___PUZZLE GAME ___*-*-*-*-*-*-*-*-*-*-*-*");
	printf("\n\n\n");

	printf("                                                         ");
	for(int i=0;i<n;i++)
	{
		printf("  ****** *****");
	}
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		printf("                                                             ");
		printf(" |    ");
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==0)
			{
				printf("     |    ");
			}
			else if(matrix[i][j]>9)
			{
				printf("%d   |    ",matrix[i][j]);
			}
			else
			{
				printf("%d    |    ",matrix[i][j]);
			}
		}

		printf("\n");
		printf("                                                             ");
		for(int j=0;j<=n;j++)
			printf(" |        ");
			printf("\n");
		printf("                                                              ");
		for(int i=0;i<n;i++)
		printf("  **** ***");
		printf("\n\n");
	}

 }
int issortedmatrix(int mat[100][100],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
       if(mat[i][j]>mat[i][j+1]||mat[i][j]>mat[i+1][0]){
        return 0;
       }
    }
}
return 1;
}
 void arrange(int matrix[100][100],int n,int ind1,int ind2,int userinput){
     int t;
  if(userinput=='4'){
     t=matrix[ind1][ind2];
     matrix[ind1][ind2]=matrix[ind1][ind2-1];
     matrix[ind1][ind2-1]=t;
    }
 else if(userinput=='6'){
    t=matrix[ind1][ind2];
     matrix[ind1][ind2]=matrix[ind1][ind2+1];
     matrix[ind1][ind2+1]=t;}
 else if(userinput=='8'){
   t=matrix[ind1][ind2];
     matrix[ind1][ind2]=matrix[ind1-1][ind2];
     matrix[ind1-1][ind2]=t;
     }
 else if(userinput=='2'){
    t=matrix[ind1][ind2];
     matrix[ind1][ind2]=matrix[ind1+1][ind2];
     matrix[ind1+1][ind2]=t;
 }
 }
 int main(){
     int i,j,matrix[100][100],n=4,ind1,ind2;
     int choice;
     printf("\n\n    ****************************************************  WELCOME TO PUZZLE GAME  ****************************************************");
	printf("\n\n\n\n                                                  Choose the level you want : ");
	printf("\n\n                                                                  1.Easy          ");
	printf("\n\n                                                                  2.Medium        ");
	printf("\n\n                                                                  3.Hard          \n");
    scanf("%d",&choice);
    if(choice==1){
            n=3;
        matrix[0][0]=2;
        matrix[0][1]=4;
        matrix[0][2]=3;
        matrix[1][0]=1;
        matrix[1][1]=8;
        matrix[1][2]=5;
        matrix[2][0]=7;
        matrix[2][1]=6;
        matrix[2][2]=0;

}
    else if(choice==2){
            n=4;
 matrix[0][0]=7;
 matrix[0][1]=9;
 matrix[0][2]=6;
 matrix[0][3]=2;
 matrix[1][0]=1;
 matrix[1][1]=4;
 matrix[1][2]=11;
 matrix[1][3]=8;
 matrix[2][0]=12;
 matrix[2][1]=14;
 matrix[2][2]=3;
 matrix[2][3]=10;
 matrix[3][0]=0;
 matrix[3][1]=5;
 matrix[3][2]=13;
 matrix[3][3]=15;
    }
    else if(choice==3){
            n=5;
matrix[0][0]=1;
 matrix[0][1]=2;
 matrix[0][2]=3;
 matrix[0][3]=4;
 matrix[0][4]=5;
 matrix[1][0]=6;
 matrix[1][1]=7;
 matrix[1][2]=8;
 matrix[1][3]=9;
 matrix[1][4]=10;
 matrix[2][0]=11;
 matrix[2][1]=12;
 matrix[2][2]=13;
 matrix[2][3]=14;
 matrix[2][4]=15;
 matrix[3][0]=17;
 matrix[3][1]=18;
 matrix[3][2]=22;
 matrix[3][3]=19;
 matrix[3][4]=20;
 matrix[4][0]=16;
 matrix[4][1]=21;
 matrix[4][2]=23;
 matrix[4][3]=24;
 matrix[4][4]=0;
    }
    gamerules();
printf("\n\n                                                      Press 1 to Start the Game and Press 2 to End the Game");
scanf("%d",&choice);
	if(choice==1){
 int move=0;
  printmatrix(matrix,n,move);
 int result,k=10;
 char userinput;
 //scanf("%d",&userinput);
  while(1)
	{
    if(result==1){
            printf("!!Solved The Puzzle!!");
        break;
    }
    else{
        scanf("%c",&userinput);
        if(userinput=='e'){
            exit(0);
        }
            for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    ind1=i;
                    ind2=j;
                }
            }
        }
        arrange(matrix,n,ind1,ind2,userinput);
        printmatrix(matrix,n,move);
        result=issortedmatrix(matrix,n);
        move++;
    }
	}
 }
 else {
    exit(0);
 }
 }

