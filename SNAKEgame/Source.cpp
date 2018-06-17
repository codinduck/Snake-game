#include<iostream>
#include<conio.h>
#include<windows.h>


using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x, y, flyX, flyY, score;
int buttX[100], buttY[100];
int butt;
char gsnake='@';
char gfly='%';
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void initialise()
{

  gameOver=false;
  dir=STOP;
  x=width/2;
  y=height/2;
  flyX= rand() % width;
  flyY= rand() % height;
  score=0;

}
void map()
{

	system("cls");
	for(int i=0; i<width+2; i++)
	{
		cout<<"#";
	}
	cout<<endl;
	
	for(int i=0; i<height; i++)
	{
		
		
		for(int j=0; j<width; j++)
		{
			
			if(j==0)
				cout<<"#"; 
			if(i==y && j==x)
				cout<<gsnake;
			else if(i==flyY && j==flyX)
				cout<<gfly;
			else
			{
				bool printbutt = false;
				for(int k=0; k<butt; k++)
				{
					
					if(buttX[k]==j && buttY[k]==i)
					{
						cout<<"o";
						printbutt = true;
					}
					
				}
					if(!printbutt)
						cout<<" ";
				
			}
			
			if(j==width-1)
				cout<<"#";
		}cout<<endl;
	}
	
	for(int i=0; i<width+2; i++)
	{
		cout<<"#";
	}
	cout<<endl;
    cout<<"SCORE:"<<score;
}
void controls()
{

	if(_kbhit())
	{
		switch(getch())
		{
		case 'w':
			dir=UP;
			break;
		case 's':
			dir=DOWN;
			break;
		case 'a':
			dir=LEFT;
			break;
		case 'd':
			dir=RIGHT;
			break;
		case 'x':
			gameOver=true;
			break;
		}

	}
}

void logic()
{
	int prevX = buttX[0];
	int prevY = buttY[0];
	int prev2X, prev2Y;
	buttX[0]=x;
	buttY[0]=y;
	for (int i=1; i< butt; i++)
	{
		
		prev2X = buttX[i];
		prev2Y = buttY[i];
		buttX[i]=prevX;
		buttY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir)
	{
	case UP:
		y=y-1;
		break;
	case DOWN:
		y=y+1;
		break;
	case LEFT:
		x=x-1;
		break;
	case RIGHT:
		x=x+1;
		break;
	}
	//if((x>width || x<0) || (y>height || y<0))
	//	gameOver=true;
	if(x>width)
		x=0;
	else if(x<0)
		x=width-1;
	if(y>height)
		y=0;
	else if(y<0)
		y=width-1;
	for(int i=0; i<butt; i++)
	{
		if(buttX[i]==x && buttY[i]==y)
			gameOver=true;
	}
	if(x==flyX && y==flyY)
	{
		score+=10;
	    flyX=rand() % width;
	    flyY=rand() % height;
		butt=butt+1;
	}



}
int main()
{
	int ans;
	int choice;
	do
	{
	   cout<<"\n\t\t SKINNY PETE";
	   cout<<"\n(1.)PLAY";
	   cout<<"\t\t\t CONTROLS:";
	   cout<<"\n(2.)EXIT";
	   cout<<"\t\t\t USE W,A,S,D TO MOVE UP,LEFT,DOWN,RIGHT RESPECTIVELY";
	   cout<<"\n ENTER YOUR CHOICE:";
	   cin>>choice;
	   switch(choice)
	   {
	   case 1:
	    initialise();
		while(!gameOver )
		{
		map();
		controls();
		logic();
		Sleep(80);
		}
		break;
	   case 2:
		   cout<<"\t\t EXITING...(press enter to exit)";
		   getch();
		   break;
	   }
	   if(score==4000)
		   cout<<"YOU WIN ! THAT'S ALL YOU CAN EVER EAT ! :p";
	   else
           cout<<"\n SEEMS LIKE YOU WERE STARVING TO HAVE EATEN YOURSELF OR WERE JUST NOT IN THE MOOD TO PLAY ^___^";
           getch();
		   cout<<"\n press 0 to exit";
		   cin>>ans;
	}while(ans!=0);
	system("cls");
	cout<<"\t\t====================================";
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\tGAME OVER !!!";
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t====================================";
    
	cout<<"\n press enter to exit to desktop!";
	getch();
}

