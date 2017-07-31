#include <stdio.h>
#include <time.h>
#include <windows.h>

#define Vpravo 77
#define Vlevo 75
#define Up 72
#define f1 59
#define f2 60
#define f3 61
#define f4 62
#define f5 63
#define s_save 115
#define y_continue 121
#define n_new 110
#define Esc_end_game 27

//static const int w = 2;

#define false 0
#define true 1

#define A 30   //y
#define B 20   //x

char mas[A][B]={0};
 
typedef struct st
{
     char  m[A][B];
} st_mas;

typedef struct st2
{
     int performance;
     int choice_car;
     int y_cars;
     int x_cars;
} st_flag;

void delay(int ms);
void na_ekran();
void pidhotovka_ekrana();
COORD coord={0,0};                                  
void gotoxy(int x,int y);
void my_car(int x, int y );
int cars(int x, int y, int fl, int k);
st_mas compared_cars();
int shot(int my_car_vpravo_vlevo);
void if_end(long int SCORE);
void save_game(st_flag fl[5]);



int main()
{
	//------------------------------
	HWND hwnd;     
    char Title[1024];
    GetConsoleTitle(Title, 1024); 
    hwnd=FindWindow(NULL, Title); 
    MoveWindow(hwnd,400,90,500,700,TRUE);
    //------------------------------------------

    register int i, j, k, x, y, rand_chislo, code;
    char c;
    int my_car_vpravo_vlevo=10;  
    int my_car_up_down = 24;  
    int fl_my_car, fl_cars;
    int counter_cars, between_cars = 10;
    int shot_y[10];
    long int SCORE = 0, fl_score, counter_while = 0;
    int speed = 50;
    long int read_score;
    st_mas mas_cars;  
    st_flag fl[5]; 
	 
    label1:
    		
	for(i=0; i<5; i++) 
	{
		fl[i].choice_car = 0;
		fl[i].performance = 0;
		fl[i].y_cars = 0;
		fl[i].x_cars = 0;
	}
	
		
	FILE *file;
	    file = fopen("SCORE.txt", "r");
	    
	    	if(file == NULL) 
				{
					read_score = 0;
				}
			else
			{
				 fscanf (file, "%d", &read_score);
			}
	    fclose(file);
	//----------------------< beginning of the game >---------------------------

	printf("continue the game - press y\n");
	printf("start a new game - press n\n");
	while(true)
	{
		srand(time(NULL));
		 code = getch(); 
		 if(code == y_continue ) 
		{
			 file = fopen("SAVE.txt", "r");
			 
				 if(file == NULL) 
					{
					printf("no saved games\nchoose by a new game\n"); 
					continue;
					}
			    
			    fscanf(file, "%d\n\n", &SCORE);
			    fscanf(file, "%d\n", &my_car_vpravo_vlevo);
			for(i=0; i<5; i++) 
			{
				fscanf(file, "%d\n", &fl[i].choice_car);
				fscanf(file, "%d\n", &fl[i].performance);
				fscanf(file, "%d\n", &fl[i].y_cars);
				fscanf(file, "%d\n\n", &fl[i].x_cars);
			}
			    
			fclose(file);
			
			break;
		}  
		if(code == n_new ) 
		{
			break;
		}	
	}

	 while(true)
	 {
		 pidhotovka_ekrana();
		 counter_cars--;
		//======================< in front of the cars >================================
		rand_chislo = rand() %100;
		//------------------------------------------------------------------------------
    	k = 0;
	
		if( (rand_chislo > 1 && rand_chislo < 29) && (fl[k].performance == false) && counter_cars < 0 )   
		{
			counter_cars = between_cars;
			fl[k].x_cars = cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
		
			fl[k].performance = true;
		}
    
	    if(fl[k].performance == true)
	    {
	    
			cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
			fl[k].y_cars++;
			if(fl[k].y_cars > 30)
			{
				fl[k].y_cars = 0;
				fl[k].performance = false;
			}
	    }
       //-----------------------------------------------------------------
    		k = 1;
		if( (rand_chislo > 30 && rand_chislo < 59) && (fl[k].performance == false) && counter_cars < 0 )   
		{
			counter_cars = between_cars;
			fl[k].x_cars = cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
		
			fl[k].performance = true;
		}
       
	    if(fl[k].performance == true)
	    {
	    
			cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
			fl[k].y_cars++;
			if(fl[k].y_cars > 30)
			{
				fl[k].y_cars = 0;
				fl[k].performance = false;
			}
	    }
        //----------------------------------------------------------
    	k = 2;
		if( (rand_chislo > 60 && rand_chislo < 69) && (fl[k].performance == false) && counter_cars < 0 )   
		{
			counter_cars = between_cars;
			fl[k].x_cars = cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
		
			fl[k].performance = true;
		}
       
	    if(fl[k].performance == true)
	    {
	    
			cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
			fl[k].y_cars++;
			if(fl[k].y_cars > 30)
			{
				fl[k].y_cars = 0;
				fl[k].performance = false;
			}
	    }
        //--------------------------------------------------------------
    	k = 3;
		if( (rand_chislo > 70 && rand_chislo < 79) && (fl[k].performance == false) && counter_cars < 0 )   
		{
			counter_cars = between_cars;
			fl[k].x_cars = cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
		
			fl[k].performance = true;
		}
       
	    if(fl[k].performance == true)
	    {
	    
			cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
			fl[k].y_cars++;
			if(fl[k].y_cars > 30)
			{
				fl[k].y_cars = 0;
				fl[k].performance = false;
			}
	    }
        //--------------------------------------------------------------
        k = 4;
		if( (rand_chislo > 80 && rand_chislo < 99) && (fl[k].performance == false) && counter_cars < 0 )   
		{
			counter_cars = between_cars;
			fl[k].x_cars = cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
		
			fl[k].performance = true;
		}
       
	    if(fl[k].performance == true)
	    {
	    
			cars( fl[k].x_cars, fl[k].y_cars, fl[k].performance, k );
			fl[k].y_cars++;
			if(fl[k].y_cars > 30)
			{
				fl[k].y_cars = 0;
				fl[k].performance = false;
			}
	    }
		//==========================================================
		mas_cars = compared_cars();   //write a framework for further comparison
		//=======================< my car >==============================	
	
		        if(kbhit()==1)
		        {
		           code = getch();
				   kbhit();   
		        }
		        
		if(code == Vpravo ) 
		{
			if(my_car_vpravo_vlevo<17)
			my_car_vpravo_vlevo++;
		} 
		if(code == Vlevo ) 
		{
			if(my_car_vpravo_vlevo > 2)
			my_car_vpravo_vlevo--;
		} 
		if(code == Up ) 
		{
			shot_y[0] = shot(my_car_vpravo_vlevo);
		
		
			if(shot_y[0] != 0)
			{
				shot_y[1] = shot_y[0] - 2;
				shot_y[2] = shot_y[0] - 3;
				shot_y[3] = shot_y[0] - 4;
				shot_y[4] = shot_y[0] - 5;
				shot_y[5] = shot_y[0] - 6;
			
				for(i=0; i<5; i++)
				{
					if(shot_y[1]==fl[i].y_cars || shot_y[2]==fl[i].y_cars ||
					 shot_y[3]==fl[i].y_cars || shot_y[4]==fl[i].y_cars || shot_y[5]==fl[i].y_cars )
					{
						fl[i].y_cars = 0;
						fl[i].performance = false;
						SCORE += 5;
						break;
					}
				}
			
			}
		} 
		if(code == f1 ) 
		{
			speed = 100;
		} 
		if(code == f2 ) 
		{
			speed = 70;
		} 
		if(code == f3 ) 
		{
			speed = 35;
		} 
		if(code == f4 ) 
		{
			speed = 15;
		} 
		if(code == f5 ) 
		{
			speed = 0;
		} 
		if(code == 32 )   //pause
		{
		    getch();
		} 
		if(code == Esc_end_game )   
		{
		     if_end(SCORE);
	         exit(0);
		} 
		if(code == s_save )   
		{
			    file = fopen("SAVE.txt", "w");
			    
			    fprintf(file, "%d\n\n", SCORE);
			    fprintf(file, "%d\n", my_car_vpravo_vlevo);
			for(i=0; i<5; i++) 
			{
				fprintf(file, "%d\n", fl[i].choice_car);
				fprintf(file, "%d\n", fl[i].performance);
				fprintf(file, "%d\n", fl[i].y_cars);
				fprintf(file, "%d\n\n", fl[i].x_cars);
			}
			    
			fclose(file);
			
			 if_end(SCORE);
		} 
	    //------------------------------------------------------
		my_car(my_car_vpravo_vlevo, my_car_up_down);
		code = 0;
		
	    //-------------------< Collision checking machines >-------------------------
		for(x=0; x<A; x++)
	    {
	        for(y=0; y<B; y++)
	        {
	        	fl_my_car = false;
				fl_cars = false;
				fl_score = false;
				if(mas_cars.m[x][y] == '=') fl_score = true;  
	        	if(mas_cars.m[x][y] == '#') fl_cars = true;
	        	if( mas[x][y] == 'x') fl_my_car = true;
	        	if(fl_cars == true && fl_my_car == true)
	            {
	            	//=======================================
	            	  if_end(SCORE);
	            	  //	exit(0);
	            	  goto label1;
	            	//======================================
	            }
	            if(fl_score == true && fl_my_car == true)
	            {
	            	SCORE += 10;
	            	fl[4].y_cars = 0;
					fl[4].performance = false;
	            }
	        }
	    }
	//------------------------------------------------
		gotoxy(0,0); 
		na_ekran();
		printf("\nSCORE: %d\n\n\n", SCORE);
		printf("best result: %d\n\n", read_score);
		printf("-> - right turn\n\n");
		printf("<- - left turn\n\n");
		printf("space - pause\n\n");
		printf("F1 - F5 - difficulty level\n\n");
		printf("s - save the game\n\n");
		printf("Esc - to end the game\n\n");
		delay(speed);
	//=======================
	 counter_while++;
	 if( counter_while > 100)
	 {
	 	SCORE++;
	 	counter_while = 0;
	 }
	//============================< end (while(true)) >===========================================   
	 }
}

//====================< functions >================================================================
 void if_end(long int SCORE)
 {
 	long int read_score;
 	
	FILE *file;
	    file = fopen("SCORE.txt", "r");
	    fscanf (file, "%d", &read_score);
	fclose(file);
 	
	if(read_score < SCORE)
	{
	    file = fopen("SCORE.txt", "w");
	    	fprintf(file, "%d", SCORE);
		fclose(file);
	}
 }
 //-------------------------------------------------------
 void gotoxy(int x,int y)
 {
	 coord.X=x;
	 coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 //----------------------------------------------------------
 
 int cars(int x, int y, int fl, int k)
 {	 
	 int rand_chislo;
	 char mas2[A][B]={0};
     register int x2, y2;
     int fl_apart;
     char str[255];
     register int i, j;
     char name_file[50] = {0};
     
     	if (k == 0)
     		strcpy (name_file, "cars.txt");
     		
     	if (k == 1)
     		strcpy (name_file, "cars.txt");
     		
     	if (k == 2)
     		strcpy (name_file, "tank.txt");
     		
     	if (k == 3)
     		strcpy (name_file, "motorcycle.txt");
     		
     	if (k == 4)
     		strcpy (name_file, "bonus.txt");
     	

	 if(fl == 0)
	 {
		rand_chislo = 2 + rand() %15;
		x = rand_chislo;
	 }
	 //-------------------------------------
	 FILE *file;
	    file = fopen(name_file, "r");
	    
	    	if(file == NULL) 
				{
					printf("Wrong\n");
					exit(0);
				}
		
				while(!feof(file))
				{
				fgets(str, 255, file); 
				//--------------------
					for(i=0; i<10; i++)
					{
						if(str[i] == '#' ||  str[i] == '=' )
						{
							mas[y][i+x] = str[i];
						}
					}
				//-------------------
				y++;
			    }
	    fclose(file);
	   
  return x;
 }
//--------------------------------------------

 int  bonus(int x, int y, int fl)
 {	 
    int fl2;
	st_mas mas_cars;
	mas_cars = compared_cars();
	int rand_chislo;
 	if(fl == 0)
	{
		rand_chislo = 2 + rand() %15;
		x = rand_chislo;
	}

   	mas[y][x] = '=';
	
    return x;
 }
//-------------------------------------
 void my_car(int x, int y )
 {
    char c = 'x';

    mas[y][x] = c;
    y++;
    mas[y][x+1] = c;
    mas[y][x-1] = c;
    mas[y][x] = c;
    y++;
    mas[y][x] = c;
    y++;
    mas[y][x+1] = c;
    mas[y][x-1] = c;
 }
//--------------------------------------

 void delay(int ms) 
 {
	  int c = clock() + ms;
	  while(clock() < c);
 }
//---------------------------------------------------

 void pidhotovka_ekrana()
 {
 	register int x, y;
	
	for(x=0; x<A; x++)
    {
        for(y=0; y<B; y++)
        {
           mas[x][y] = ' ';
           if(x==0 || y==0 || x==(A-1) || y==(B-1))  mas[x][y] = '+';
        }
    }
 }
//------------------------------------------------------------

 st_mas compared_cars()
 {
	st_mas mas_cars;
	register int x, y;
	
	for(x=0; x<A; x++)
    {
        for(y=0; y<B; y++)
        {
          mas_cars.m[x][y] = mas[x][y];
        }
    }
    
    return mas_cars;
}
//---------------------------------------------

 int shot(int my_car_vpravo_vlevo)
 {
	register int x, y;
	char c1 = '%';
	char c2 = '/';
	x =  my_car_vpravo_vlevo;
	
    for(y=24; y>0; y--)
    {
        
        if(mas[y][x] == '#')
        {
           	mas[y][x] = c2;
			mas[y-1][x] = c1;
			mas[y+1][x] = c1;
			mas[y][x+1] = c1;
			mas[y][x-1] = c1;
			mas[y-1][x+1] = c1;
			mas[y+1][x-1] = c1;
			mas[y-1][x-1] = c1;
			mas[y-1][x-1] = c1;
			mas[y+1][x+1] = c1;
			mas[y][x-2] = c1;
			mas[y][x+2] = c1;
			mas[y-2][x] = c1;
			mas[y+2][x] = c1;
			mas[y+2][x+2] = c2;
			mas[y+2][x-2] = c2;
			mas[y-2][x+2] = c2;
			mas[y-2][x-2] = c2;
           	
           	printf("\a");
           	return y;
        }
        mas[y][x] = ':';   
    }
    return 0;
 }
//-----------------------------------------

 void na_ekran()
 {
	 HANDLE consoleOutput; 
	 consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
 	 register int x, y;
	
	for(x=0; x<A; x++)
    {
        for(y=0; y<B; y++)
        {
	        switch ( mas[x][y] ) 
			{
			case ':':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_GREEN|FOREGROUND_RED);
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case '#':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_RED | FOREGROUND_INTENSITY); 
			  
			    mas[x][y] = 220;
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case '%':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
				mas[x][y] = 178; 
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case '/':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_RED|FOREGROUND_INTENSITY);
			    mas[x][y] = 177;
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case 'x':
				SetConsoleTextAttribute(consoleOutput,  FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case '+':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_RED);
			    mas[x][y] = 254;
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			case '=':
			    SetConsoleTextAttribute(consoleOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
			    mas[x][y] = 1;
	        	 printf("%c ", mas[x][y]);
			    break;
			    
			default:
			    printf("%c ", mas[x][y]);
			    break;
			}
        }
        printf("\n");
    }
}



