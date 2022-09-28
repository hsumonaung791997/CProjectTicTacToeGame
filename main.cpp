#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<dos.h>
#include<string.h>

char user1[50], user2[50];
char x, o ;//user choose sign
char boardarr[10] = {'1','2','3','4','5','6','7','8','9'};//to make board design
int player = 1; //to switch player

void rule();
char choosesign();
void gameboard();

int main(){
	
	int a;//to start the game
	int choicenum;
	char symbol;

	
	system("cls");
	
	
	//call the game rule function
	rule();
	
	printf("\n\n\n \t\t\t\t\t Choose 1 to start the game.\n\n \t\t\t\t\t Choose 2 to see the winners.\n\n \t\t\t\t\t Choose 3 to exist.\n\n");
	
	printf("\n \t\t\t\t\t Choose number to go to the page : ");
	scanf("%d", &a);
	printf("\n\n \t\t\t\t *****************************************************************************************************************");

	
	//choose user make decision to play the game
	if(a == 1)
	{
		label1:
			
		FILE *f;
    	f = fopen("winner.dat","a+");
		
		printf("\n\n\n \t\t\t\t\t Enter user1 name : ");
		scanf("%s",&user1);
		fprintf(f, "%s", user1);
	 
		
		printf("\n \t\t\t\t\t Enter user2 name : ");
		scanf("%s",&user2);
		fprintf(f, "%s", user2);
		
	 
		fclose(f);
		
		//check usernameone and usernametwo
		
		if(strcmp(user1,user2)==0){
			
			printf("\n \n \t\t\t\t\t Enter different players names : \n");
			goto label1;
		}
		else{
			
		//call choosesign function

		choosesign();
			
		}
		
		gameboard();
		
		//to switch plyer for user1 and user2
		int j;
//		do{
			
			
			player = ( player % 2) ? 1 : 2 ;
			
			if(player == 1){
				
				printf("%s Choose any digit number 1 - 9 to fill your square : ", user1);
			}
			else{
				
				printf("%s Choose any digit number 1 - 9 to fill your square : ", user2);
				
			}
			
			scanf("%d",&choicenum);
			
			symbol = (player == 1) ? x : o;
			
			
			if(choicenum == 1 && boardarr[0] == '1'){
				
				boardarr[0] = symbol;
			}
			
			else if(choicenum == 2 &&  boardarr[1] == '2'){
				
				boardarr[1] = symbol;
				
			}
			else if(choicenum == 3 &&  boardarr[2] == '3'){
				
				boardarr[2] = symbol;
				
			}
			
			else if(choicenum == 4 &&  boardarr[3] == '4'){
				
				boardarr[3] = symbol;
				
			}
			
			else if(choicenum == 5 &&  boardarr[4] == '5'){
				
				boardarr[4] = symbol;
				
			}
			
			else if(choicenum == 6 &&  boardarr[5] == '6'){
				
				boardarr[5] = symbol;
				
			}
			
			else if(choicenum == 7 &&  boardarr[6] == '7'){
				
				boardarr[6] = symbol;
				
			}
			
			else if(choicenum == 8 &&  boardarr[7] == '8'){
				
				boardarr[7] = symbol;
				
			}
			
			else if(choicenum == 9 &&  boardarr[8] == '9'){
				
				boardarr[8] = symbol;
				
			}
			else{
				
				printf("\n \n \t\t\t\t\t\t\t Wrong Number Choice !");
				
			}
			
			
			
			
			
			
			
			
//		}while()
		
		
		
		
	}
	
	else if( a == 2 )
	{
		printf("2");
	}
	
	else if(a == 3)
	{
		system("cls");
		exit(0);
	}
	
	else
	{
		printf("\n  \t\t\t\t\t Wrong Number! Please Choose 1 or 2 or 3.");
	}
}



//game rules
void rule()
{

	time_t currenttime;
	
	struct tm*timeinfo;
	time(&currenttime);
	
	timeinfo = localtime(&currenttime);
	
	system("color E");
	printf("\n\n \t\t\t\t\t\t\t\t Local Current Time : %s",asctime(timeinfo));
	
	printf("\n\n \t\t\t\t\t\t\t\t\t RULES FOR TIC-TAC-TOE GAME\n");
	printf("\n \t\t\t\t\t\t\t\t *****************************************");
	printf("\n\n \t\t\t\t\t 1.The game is played on a grid that is 3 squares by 3 squares.");
	printf("\n\n \t\t\t\t\t 2.You are X, your friend is O. Players take turns putting their marks in empty squares.");
	printf("\n\n \t\t\t\t\t 3.The first player to get 3 of her marks in a row is ( up or down or cross or diagonally) is the winner.");
	printf("\n\n \t\t\t\t\t 4.When all 9 squares are full, the game is over. If no player has 3 marks in a row the game is end.");
	printf("\n\n \t\t\t\t *****************************************************************************************************************");

}


//choose sign for user one
char choosesign(){
	
	char sign;
	
	userchoosesign:
	
	printf("\n \t\t\t\t\t Player 1 %s choose the sign X or O : ",user1);
	
	sign  = getche();
	//scanf("%c",&sign);
	
	if(sign == 'x' || sign == 'X')
	{
		
		x = 'X';
		o = 'O';
		
	//	return x;	
		
	}
	
	else if( sign == 'o' || sign == 'O')
	{
		
		x = 'O';
		o = 'X';
		
		//return x;
	}
	
	else{
		
		printf("\n \n\t\t\t\t\t Please Enter X or O only! \n \n");
		goto userchoosesign;
	}
		
}

//poe X hsu O

void gameboard(){
	
	system("cls");
	
	system("color A");
	
	printf("\n \n \t\t\t\t\t\t\t\t WELCOME TO  TIC-TAC-TOE GAME \n\n");
	printf("\n \t\t\t\t\t\t\t ********************************************** \n");
	printf("\n \n\t\t\t\t\t\t\t %s - (%c) and %s - (%c) \n\n\n",user1,x,user2,o);
	
	printf("\n \n\t\t\t\t\t\t\t  %c |  %c  |  %c \n",boardarr[0],boardarr[1],boardarr[2]);
	printf("\t\t\t\t\t\t            |     |     \n");
	printf("\t\t\t\t\t\t\t ___|_____|____ \n");
	printf("\t\t\t\t\t\t\t  %c |  %c  |  %c \n",boardarr[3],boardarr[4],boardarr[5]);
	printf("\t\t\t\t\t\t            |     |     \n");
	printf("\t\t\t\t\t\t\t ___|_____|____ \n");
	printf("\t\t\t\t\t\t\t  %c |  %c  |  %c \n",boardarr[6],boardarr[7],boardarr[8]);
	printf("\t\t\t\t\t\t            |     |     \n");

 	
}


