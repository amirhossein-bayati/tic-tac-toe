#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define print printf
#include <time.h>
//declare structure
struct introduction
{
	char name[10];  //name of player
	char last[20];  //last of player
	int age; // age of player

};
introduction s1={"PLAYER 1","GAMMER 1",18}; //player 1
introduction s2={"PLAYER 2","GAMMER 2",23}; //player 2

//declare functions
void menu (void); //menu func
void shape (void); //sructure of func
void enter (void); //to enter number func
void player (void); //shape of player func
void setting (void); //setting func
void end (void); //to show winner 
void check (void); //checkng char to be win func
void about (void); //about func
void repeat (void); //repeat game func
void finish (void); //the last display of game func
void ball (void); //ball display func
void icon (void); //players icon func
void bear (void); //bear display func
void loading (void); //first loading func
void loading2 (void); //second loading func
void single (void); //random num func
void intro (void);  //information



int count1=0, count2=0 ; //winning count
int no; //option number
int n=0; //player
int x=0;  //who win
int m; //menu num
int count=0; //draw count
int p;  //to display the winner
int q; //save question
int color; //game color
char target [10]={'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};  //	target
char player1='X';
char player2='O';
char playera=player1;	//player 1 icon
char playerb=player2;	//player 2 icon
char temp[10];	//jelogiri az vared kardan adad tekrari

//declare gotoxy
void gotoxy(int x,int y)
{
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
    if (INVALID_HANDLE_VALUE != hConsole)
    {
        COORD pos = {x, y};
        SetConsoleCursorPosition( hConsole, pos );
    }
}


//main -----------
int main ()
{
	system("color 0b");  //game color
	loading();  //the loading of game
	menu();  // game menu
	return 0;
}



// ---------------------------------------------- < functions > --------------------------------------------------------
//menu
void menu (void)
{
	//drawing the menu
	bear();
		
	gotoxy(57,13);
	printf("* TIC-TAC-TOE *");
	
	gotoxy(50,16);
	printf("1. PLAY GAME");

	gotoxy(50,17);
	printf("2. SETTING");

	gotoxy(50,18);
	printf("3. ABOUT");

	gotoxy(50,19);
	printf("0. EXIT");

	gotoxy(50,21);
	printf("ENTER NUM :");
	while(1)
	{
	//declare menu
		gotoxy(63,21);
		m=getche();
		switch(m)
		{
			//start the game
			case ('1'):
				loading2();
				shape();
			//setting	
			case ('2'):
				setting();
			//about game	
			case ('3'):
				about();
			//to exit the game	
			case '0':			
				finish();
				break;
				
		}
	}
}
//shape
void shape (void)
{
	//drawing the structure of game
	system ("cls");
	printf("\n		%s ( %c )								%s ( %c )\n",s1.name , player1 , s2.name , player2); //esm playaer ha
	printf("	    _____________________						     ____________________\n\n");
	printf("		     %d									      %d\n",count1 ,count2);
	
	printf("						   ___   ___   ___       \n");
	printf("						  /   \\ /   \\ /   \\   \n");
	printf("						 |  %c  |  %c  |  %c  |    \n", target[1], target[2], target[3] );
	printf("					   	  \\___/ \\___/ \\___/  \n");

	printf("						   ___   ___   ___       \n");
	printf("						  /   \\ /   \\ /   \\   \n");
	printf("						 |  %c  |  %c  |  %c  |    \n", target[4], target[5], target[6] );
	printf("					   	  \\___/ \\___/ \\___/  \n");

	printf("						   ___   ___   ___       \n");
	printf("						  /   \\ /   \\ /   \\   \n");
	printf("						 |  %c  |  %c  |  %c  |    \n", target[7], target[8], target[9] );
	printf("					   	  \\___/ \\___/ \\___/  \n");
	
	//return to menu
	gotoxy(43,20);
	printf(" press \"m\" to return to menu :)"); //menu
	gotoxy(51,4);
	printf("enter num :"); 
	gotoxy(50,20);
	enter ();
}

//enter the target
void enter(void)
{
	//to detect whoose turn
	n=n%2;
	//player 1
	if (n==0)
	{
		gotoxy(14,1);
		//to show turn of player
		printf("*");
		ball();
	}
	//player 2
	if (n==1)
	{
		gotoxy(86,1);
		//to show turn of player
		printf("*");
		ball();
		
	}
	//to get players target		
	while(1)
	{

		gotoxy(64,4);
		no=getche();
		
	
		switch(no)
		{
	
	
			case ('1'):
				//if target is 1 & first player
				if (target[1]=='1' && n==0)
				{
					target[1]= player1;
					count++;
				}	
				//if target is 1 & second player
				if (target[1]=='1' && n==1)
				{
					target[1]= player2;
					count++;
				}	
				//to check the house to not be used yet 
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '1')
						n--;
				}
				//to save house to be used
				temp[1]='1';
						
				break;
	
	
	
			case ('2'):
				if (target[2]=='2' && n==0)	
				{
					
					target[2]= player1;
					count++;
				}
				
				if (target[2]=='2' && n==1)
				{
					target[2]= player2;
					count++;
				}
	
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '2')
						n--;
						
				}
				//to save house to be used
				temp[2]='2';
				
				break;
	
	
	
			case ('3'):
				if (target[3]=='3' && n==0)	
				{
					target[3]= player1;
					count++;
				}
				
				if (target[3]=='3' && n==1)
				{
					target[3]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '3')
						n--;
						
				}
				//to save house to be used
				temp[3]='3';
	
				break;
	
	
	
			case ('4'):
				if (target[4]=='4' && n==0)	
				{
					target[4]= player1;
					count++;
				}
				
				if (target[4]=='4' && n==1)
				{
					target[4]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '4')
						n--;
						
				}
				//to save house to be used
				temp[4]='4';
	
				break;
	
	
	
			case ('5'):
				if (target[5]=='5' && n==0)	
				{
					
					target[5]= player1;
					count++;
				}
				
				if (target[5]=='5' && n==1)
				{
					target[5]= player2;
					count++;
				}	
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '5')
						n--;
						
				}
				//to save house to be used
				temp[5]='5';
	
				break;
	
	
	
			case ('6'):
				if (target[6]=='6' && n==0)	
				{
					target[6]= player1;
					count++;
				}	
				
				if (target[6]=='6' && n==1)
				{
					target[6]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '6')
						n--;
						
				}
				//to save house to be used
				temp[6]='6';
				break;
	
	
	
			case ('7'):
				if (target[7]=='7' && n==0)	
				{
					target[7]= player1;
					count++;
				}
				
				if (target[7]=='7' && n==1)
				{
					target[7]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '7')
						n--;
						
				}
				//to save house to be used
				temp[7]='7';
				break;
	
	
	
			case ('8'):
				if (target[8]=='8' && n==0)	
				{
					target[8]= player1;
					count++;
				}
				
				if (target[8]=='8' && n==1)
				{
					target[8]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '8')
						n--;
						
				}
				//to save house to be used
				temp[8]='8';
				break;
	
	
	
			case ('9'):
				if (target[9]=='9' && n==0)	
				{
					target[9]= player1;
					count++;
				}
				
				if (target[9]=='9' && n==1)
				{
					target[9]= player2;
					count++;
				}
				
				for(int y=1 ; y<10 ; y++)
				{
					if (temp[y] == '9')
						n--;
						
				}
				//to save house to be used
				temp[9]='9';
				break;
				
			//exit from playing game
			case('m'):
				gotoxy(45,22);
				printf("save game ? (y/n)  : ");
				while(1)
				{
				
					q=getche();
					switch(q)
					{
						case ('y'):  	
							menu();
						case ('n'):
							//to reset datas
							repeat();
							menu();
					}
				}
				Sleep(1000);
				break;
				
		}
		//for next player
		n++;
	// to check is some one win or not	
	check();
	// to draw the structure of game
	shape();
	}
	
}



//check---------------------------
void check(void)
{
	//to check the houses in row 1 for first person
	if (target[1]==player1 && target[2]==player1 && target[3]==player1 )
		x=1;
	//to check the houses in row 2
	if (target[4]==player1 && target[5]==player1 && target[6]==player1 )
		x=1;	
	//to check the houses in row 3
	if (target[7]==player1 && target[8]==player1 && target[9]==player1 )
		x=1;	
	//to check the houses in colmn 1
	if (target[1]==player1 && target[5]==player1 && target[9]==player1 )
		x=1;	
	//to check the houses in colmn 2
	if (target[7]==player1 && target[5]==player1 && target[3]==player1 )
		x=1;	
	//to check the houses in colmn 3
	if (target[1]==player1 && target[4]==player1 && target[7]==player1 )
		x=1;	
	if (target[8]==player1 && target[5]==player1 && target[2]==player1 )
		x=1;	
	if (target[3]==player1 && target[6]==player1 && target[9]==player1 )
		x=1;	
	
	//to check the houses in row 1 for second person
	if (target[1]==player2 && target[2]==player2 && target[3]==player2 )
		x=2;
	if (target[4]==player2 && target[5]==player2 && target[6]==player2 )
		x=2;	
	if (target[7]==player2 && target[8]==player2 && target[9]==player2 )
		x=2;	
	if (target[1]==player2 && target[5]==player2 && target[9]==player2 )
		x=2;	
	if (target[7]==player2 && target[5]==player2 && target[3]==player2 )
		x=2;	
	if (target[1]==player2 && target[4]==player2 && target[7]==player2 )
		x=2;	
	if (target[8]==player2 && target[5]==player2 && target[2]==player2 )
		x=2;	
	if (target[3]==player2 && target[6]==player2 && target[9]==player2 )
		x=2;	
	end();
	
}

//end
void end (void)
{
	//player 1 win
	if (x==1)
	{
		count1++;
		print ("\a\a");
		// ro show winner with effects
		while(p!=5)
		{
			system("cls");
			system("color 70");
			gotoxy(50,15);
			printf("player 1 win ");
			system("cls");
			system("color 07");
			gotoxy(50,15);
			printf("player 1 win");
			
	  		p++;
		}
		system("color 0b");
		//reset datas
		repeat();
	}
	//player 2 win 
	if (x==2)
	{
		print ("\a\a");
		count2++;
		// to show winner with effects
		while(p!=5)
		{
			system("cls");
			system("color 70");
			gotoxy(50,15);
			printf("player 2 win ");
			system("cls");
			system("color 07");
			gotoxy(50,15);
			printf("player 2 win ");
			
			p++;
		}
		system("color 0b");
		repeat();
	}
	//game draw
	if (count==9)
	{
	
		while(p!=5)
		{
			system("cls");
			system("color 70");
			gotoxy(60,15);
			printf("DRAW!!");
			system("cls");
			system("color 07");
			gotoxy(60,15);
			printf("DRAW!!");
			
			p++;
		}
		system("color 0b");
		//to repeat the game
		repeat();
	}
}

//player

void player (void)
{
	//change the player 1 shape
	printf("enter the shape of player 1 : ");
	player1=getche();
	Sleep(1000);
	system("cls");
	//change the player 2 shape
	printf("enter the shape of player 2 : ");
	player2=getche();
	Sleep(1000);
	system("cls");
}


//repeat---------------------------
void repeat (void)
{
	//reset arrays for new game
	for(int i=0 ; i<10 ; i++)
	temp[i]='0';
	target[1]='1';
	target[2]='2';
	target[3]='3';
	target[4]='4';
	target[5]='5';
	target[6]='6';
	target[7]='7';
	target[8]='8';
	target[9]='9';
	x=0;
	n=0;
	count=0;
	//save or not question
	if(q!='n')
		shape();
}


//finish----------------------------------------
void finish (void)
{
	//the last display of game
	system("cls");
	system("color 0b"); //background color
	printf("\n\n\n                                                              \n");
	printf("\t\t\t\t                /|  /|  ---------------------------			\n");
	printf("\t\t\t\t                ||__||  |                         |			\n");
	printf("\t\t\t\t               /   O O\\__  	GOOD GAME  	  |				\n");
	printf("\t\t\t\t              /          \\   	HAVE GOOD TIME    |			\n");
	printf("\t\t\t\t             /      \\     \\                       |		\n");
	printf("\t\t\t\t            /   _    \\     \\ ----------------------		\n");
	printf("\t\t\t\t           /    |\\____\\     \\      ||					\n");
	printf("\t\t\t\t          /     | | | |\\____/      ||						\n");
	printf("\t\t\t\t         /       \\| | | |/ |     __||						\n");
	printf("\t\t\t\t        /  /  \\   -------  |_____| ||						\n");
	printf("\t\t\t\t       /   |   |           |       --|						\n");
	printf("\t\t\t\t       |   |   |           |_____  --|						\n");
	printf("\t\t\t\t       |  |_|_|_|          |     \\----						\n");
	printf("\t\t\t\t       /\\                  |								\n");
	printf("\t\t\t\t      / /\\        |        /								\n");
	printf("\t\t\t\t     / /  |       |       |									  ");
	printf("\t\t\t\t ___/ /   |       |       |									  ");
	printf("\t\t\t\t|____/    c_c_c_C/ \\C_c_c_c								  ");
	gotoxy(80,21);
	Sleep(30);printf("d");
	Sleep(30);printf("i");
	Sleep(30);printf("r");
	Sleep(30);printf("e");
	Sleep(30);printf("c");
	Sleep(30);printf("t");
	Sleep(30);printf("e");
	Sleep(30);printf("d");
	Sleep(30);printf(" ");
	Sleep(30);printf("b");
	Sleep(30);printf("y");
	Sleep(30);printf(" ");
	Sleep(30);printf("A");
	Sleep(30);printf("M");
	Sleep(30);printf("I");
	Sleep(30);printf("R");
	Sleep(30);printf("H");
	Sleep(30);printf("B");
	Sleep(30);printf(" ");
	Sleep(30);printf(".");
	Sleep(30);printf(".");
	Sleep(30);printf(".");
	gotoxy(0,30);
	// to exit
	system("pause");
	exit(0);
	
}
//ball------------------------------------
void ball(void)
{
	//to draw ball turn
	int j;
	if (n==0)
		j=16;
	if (n==1)
		j=89;
	//get num while ball moving
	while(!kbhit())
	{
	gotoxy(j-1,26);
	printf("------------");
	
		for(int i=11 ; i<25 ; i++)
		{
			gotoxy(j,i-6);
			printf("           ");
			gotoxy(j,i-5);
			printf("    __     ");
			gotoxy(j,i-4);
			printf(" .'\".'\"'.  ");
			gotoxy(j,i-3);
			printf(":._.\"\"._.:  ");
			gotoxy(j,i-2);
			printf(":  \\__/  :   ");
			gotoxy(j,i-1);
			printf(" './  \\.'   ");
			gotoxy(j,i);
			printf("    \"\"   ");
			gotoxy(j,i+1);
			printf("          ");
			Sleep(30);
		}



		for(int i=24 ; i>10 ; i--)
		{
			gotoxy(j,i-6);
			printf("           ");
			gotoxy(j,i-5);
			printf("    __     ");
			gotoxy(j,i-4);
			printf(" .'\".'\"'.  ");
			gotoxy(j,i-3);
			printf(":._.\"\"._.:  ");
			gotoxy(j,i-2);
			printf(":  \\__/  :   ");
			gotoxy(j,i-1);
			printf(" './  \\.'   ");
			gotoxy(j,i);
			printf("    \"\"   ");
			gotoxy(j,i+1);
			printf("          ");
			Sleep(40);
		}
	}

}




//setting------------
void setting (void)
{
	//drwing the setting menu
	bear();
		
	gotoxy(60,13);
	printf("* SETTING *");
	
	gotoxy(50,16);
	printf("1. PLAYER ICON ");

	gotoxy(50,17);
	printf("2. PLAYER INFORMATION ");

	gotoxy(50,18);
	printf("0. BACK ");

	gotoxy(50,21);
	printf("ENTER NUM : ");
		
	while(1)
	{
		//to choose in setting
		gotoxy(63,21);
		m=getche();
		switch(m)
		{
			//chang icon
			case ('1'):
				icon();
				break;
			//change information of player
			case ('2'):
				intro();
				break;
			//go back menu
			case ('0'):
				menu();
				break;
		}
	}
}


//icon---------------
void icon (void)
{
	//drawing icon setting 
	bear();
		
	gotoxy(60,13);
	printf("* ICON *");
	
	gotoxy(50,16);
	printf("1. PLAYER 1 ");

	gotoxy(50,17);
	printf("2. PLAYER 2 ");


	gotoxy(50,18);
	printf("0. BACK ");

	gotoxy(50,21);
	printf("ENTER NUM : ");

	while(1)
	{
		//to change icon
		gotoxy(63,21);	
		m=getche();
		switch(m)
		{
			case ('1'):
				bear();
				gotoxy(55,13);
				printf("* change *");
				gotoxy(50,16);
				printf("enter new one : ");
				gotoxy(67,16);
				//to get new char of player 
				player1=getche();
				//to check the last positions
				for(int y=1 ; y<10 ; y++)
				{
					if (target[y] == playera)
						target[y] = player1;
						
				}
				playera=player1;
	
				icon();			
				break;
			case ('2'):
				bear();
				gotoxy(55,13);
				printf("* change *");
				gotoxy(50,16);
				printf("enter new one : ");
				gotoxy(67,16);
				//to get new char of player 
				player2=getche();
				//to check the last positions
				for(int y=1 ; y<10 ; y++)
				{
					if (target[y] == playerb)
						target[y] = player2;
						
				}
				playerb=player1;
				icon();			
				break;
			case ('0'):
				setting();
				break;
			
		}
	}
}


//about
void about (void)
{
	//about the game
	bear();
	gotoxy(60,13);
	printf("* ABOUT *");
	gotoxy(40,16);
	printf("The game is such that each house has a number and ");
	gotoxy(40,17);
	printf("you have to mark them with your own characters");
	gotoxy(40,18);
	printf("If your characters are in three positions ");
	gotoxy(40,19);
	printf("(horizontal, vertical, or diagonal), you win the game.");
	gotoxy(40,21);
	printf("press any key to go back ...");
	getch();
	menu();

}



//bear
void bear (void)
{
	//drawing the bear structure
	system("cls");
	

	printf("				                     ,---.           ,---.\n");
	printf("				                    / / . \\.--:::--./,\\ \\ \\\n");
	printf("				                    \\ \\    _       _    / /\n");
	printf("				                     `./  / __   __ \\  \\,'\n");
	printf("				                      /    /_O)_(_O\\    \\\n");
	printf("				                      |  .-'  ___  `-.  |\n");
	printf("				                   .--|       \\_/       |--.\n");
	printf("				                 ,'    \\   \\   |   /   /    `.\n");
	printf("				                /       `.  `--^--'  ,'       \\\n");
	printf("				             .-:::::-.    :--.___.--:    .-:::::-.\n");
	printf("				.-----------/         \\------------------/         \\--------------.\n");
	printf("				| .---------\\         /----------------- \\         /------------. |\n");
	printf("				| |          `-`--`--'                    `--'--'-'             | |\n");
	printf("				| |          `-`--`--'   		  `--'--'-'             | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |                			                        | |\n");
	printf("				| |             	   	                                | |\n");
	printf("				| |        				                        | |\n");
	printf("				| |                				                | |\n");
	printf("				| |                                           			| |\n");
	printf("				| |                		                                | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |                                                             | |\n");
	printf("				| |_____________________________________________________________| |\n");
	printf("				|_________________________________________________________________|\n");
	printf("				                   )__________|__|__________(\n");
	printf("				                  |            ||            |\n");
	
	
	
}




//loading--------------------------
void loading (void)
{
	//to draw the loading of game
	system("cls");
	gotoxy(55,13);
	printf("LOADING ...");
	
	for(int i=0 ; i<120 ; i++)
	{
		gotoxy(i,0);
		printf(">");
		Sleep(4);	
	}

	for(int j=1 ; j<30 ; j++)
	{
		gotoxy(118,j);
		printf("\\/");
		Sleep(4);	
	}


	for(int i=119 ; i>0 ; i--)
	{
		gotoxy(i,29);
		printf("<");
		Sleep(4);	
	}

	for(int j=29 ; j>0 ; j--)
	{
		gotoxy(0,j);
		printf("/\\");
		Sleep(4);
	}

}
 //loading-------------------
void loading2(void)
{
	//to draw second loading
	system("cls");
//	system("color f3");
	for (int r=0 ; r<3 ; r++)
	{
		gotoxy(60,15);
		print("LOADING ");
		for (int y=0 ; y<3 ; y++)
		{
			Sleep(300);
			print(".");
		}
		system("cls");
	}		
	gotoxy(60,15);
	print("START");
	Sleep(1000);
	system("cls");
}

// intro----------------
void intro (void)
{
	bear();
		
	gotoxy(56,13);
	printf("* INFORMATION *");
	
	gotoxy(50,16);
	printf("1. PLAYER 1 ");

	gotoxy(50,17);
	printf("2. PLAYER 2 ");


	gotoxy(50,18);
	printf("0. BACK ");

	gotoxy(50,21);
	printf("ENTER NUM : ");
	//to get information of player
	while(1)
	{
	
		gotoxy(60,21);
		int z=getche();
			switch (z)
			{
				case ('1'):
					bear();
					gotoxy(50,16);
					printf("enter your name : ");
					scanf("%s",&s1.name);
					bear();
					gotoxy(50,16);
					printf("enter your last name : ");
					scanf("%s",&s1.last);
					bear();
					gotoxy(50,16);
					printf("enter your age : ");
					scanf("%d",& s1.age);
					intro();
				case ('2'):
					bear();
					gotoxy(50,16);
					printf("enter your name : ");
					scanf("%s",&s2.name);
					bear();
					gotoxy(50,16);
					printf("enter your last name : ");
					scanf("%s",&s2.last);
					bear();
					gotoxy(50,16);
					printf("enter your age : ");
					scanf("%d",& s2.age);
					intro();
				case('0'):
					setting();
				
			}
	}	

}
