#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

#include<time.h>


void addnotes();

void viewnotes();

void editnotes();

void deletenotes();

void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void login()
{
	int a=0,i=0;
    SetColor(12);
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user01";
    char pass[10]="pass86";
    do
{
	
    printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
    printf(" \n                       ENTER USERNAME TO ACCESS WRITING NOTES:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD GIVEN:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user01")==0 && strcmp(pword,"pass86")==0)
	{
	printf("  \n\n\n *******************      WELCOME TO STUDENT SERVANT THAT HELPS YOU WITH YOUR NOTES !!!! LOGIN IS SUCCESSFUL");
	    printf("\n LOADING PLEASE WAIT... \n");
    for(i=0; i<3; i++)
    {
        printf(".");
        Sleep(500);
    }
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}


struct notes

{
    
    char periodtime[6];

    char subject[30];

    char topic[25];

    char lecturer[30];

    char note[1000];

} ;

int main()

{
	login();
	
	time_t t;
	
	time(&t);

	ClearConsoleToColors(17,15);

    int ch;

    printf("\n\n\t********************************\n");

    printf("\t: STUDENT SERVANT SMARTY IS AT YOUR SERVICE: SELECT HOW MAY I HELP YOU FROM MENU\n");

    printf("\t:************************************:");

    while(1)

    {

        printf("\n\n\t\t:MAIN MENU:");

        printf("\n\n\tPress 1 To ADD NOTES\t");

        printf("\n\tPress 2 To VIEW NOTES\t");

        printf("\n\tPress 3 To EDIT NOTES\t");

        printf("\n\tPress 4 To DELETE NOTES\t");

        printf("\n\tPress 5 To EXIT\t\t");
        
        printf("\n\n\tCurrent date and time : %s",ctime(&t));

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            addnotes();

            break;

        case 2:

            viewnotes();

            break;

        case 3:

            editnotes();

            break;

        case 4:

            deletenotes();

            break;


        case 5:

            printf("\n\n\t\t******THANK YOU FOR USING THE SOFTWARE ***********");

            getch();

            exit(0);

        default:

            printf("\nYOU ENTERED WRONG CHOICE     CHOOSE FROM MENU.");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();

            break;

        }

        system("cls");

    }

    return 0;

}

void addnotes( )

{

    system("cls");

    FILE *fp ;

    SetColorAndBackground(31,28);

    char next = 'Y' ,time[10];

    struct notes e ;

    char filename[15];

    int choice;

    printf("\n\n\t\t:::::::::::****************:::::::::::::::\n");

    printf("\t\t: WELCOME TO THE ADD MENU :");

    printf("\n\t\t:::::::::::****************::::::::::\n\n");

    printf("\n\n\tENTER DATE OF YOUR NOTE:[dd-mm-yyyy]:");

    fflush(stdin);

    gets(filename);

    fp = fopen ( filename , "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen( filename ,"wb+");

        if(fp==NULL)

        {

            printf("\n   OOPS ERROR: There has been an error in opening the file");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();

            return ;

        }

    }

    while ( next == 'Y'|| next =='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER PERIOD TIME:[hh:mm]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.periodtime,time)==0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS. YOU CAN EDIT IT IN EDIT MENU\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.periodtime,time);

            printf("\tENTER SUBJECT NAME:");

            fflush(stdin);

            gets(e.subject);

            fflush(stdin);

            printf("\tENTER TOPIC:");

            gets(e.topic);

            fflush(stdin);

            printf("\tENTER LECTURER NAME:");

            gets(e.lecturer);

            fflush(stdin);

            printf("\tNOTE:");

            gets(e.note);

            fwrite ( &e, sizeof ( e ), 1, fp ) ;

            printf("\nYOUR NOTE IS ADDED SUCCESSFULLY...\n");

        }

        printf ( "\n\tDO YOU WANT TO ADD ANOTHER NOTE...(Y/N) " ) ;

        fflush ( stdin ) ;

        next = getchar( ) ;

    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

}

void viewnotes( )

{

    FILE *fpte ;

    system("cls");

    struct notes a;

    char time[6],choice,filename[15];

    SetColorAndBackground(31,28);

    int ch;

    printf("\n\n\t\t::::::::********************::::::\n");

    printf("\t\t\t: VIEWING MENU :");

    printf("\n\t\t:::::::::::::*************:::::::\n\n");

    do

    {

        printf("\n\tENTER THE DATE OF THE NOTE TO BE VIEWED:[dd-mm-yyyy]:");

        fflush(stdin);

        gets(filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            getch();

            return ;

        }

        system("cls");

	printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1. NOTES WRITTEN FOR THE WHOLE DAY.");

        printf("\n\t2.NOT INTERESTED NOW, EXIT\n");

        printf("\n\t\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            printf("\nTHE WHOLE NOTE FOR %s IS:",filename);

            while ( fread ( &a, sizeof ( a ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\nPERIOD TIME: %s",a.periodtime);

                printf("\n SUBJECT: %s",a.subject);

                printf("\n TOPIC: %s",a.topic);

                printf("\n LECTURER: %s",a.lecturer);

                printf("\nNOTE: %s",a.note);

                printf("\n");

            }

            break;

        case 2:

            return;

        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING OTHER NOTES...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

       
}
void editnotes()

{

    system("cls");

    FILE *fpte ;

    SetColorAndBackground(31,28);

    struct notes e ;

    char time[6],choice,filename[14];

    int num,count=0;

    printf("\n\n\t\t::::::::::::************:::::::::::::\n");

    printf("\t\t\t: EDIT NOTES");

    printf("\n\t\t:::::::::::*********::::::::::::::::::::\n\n");


    do

    {

        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[dd-mm-yyyy]:");

        fflush(stdin);

        gets(filename);
	
	//printf("\n\tEnter Period Time:[hh:mm]:");

	//gets(time); 

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\n NOTE DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getch();

            return;

        }

        while ( fread ( &e, sizeof ( e ), 1, fpte ) == 1 )

        {

	                printf("\nYOUR OLD NOTE WAS AS:");

	                printf("\n PERIOD TIME: %s",e.periodtime);

	                printf("\n SUBJECT NAME: %s",e.subject);

	                printf("\n TOPIC: %s",e.topic);

	                printf("\n LECTURER: %s",e.lecturer);

	                printf("\nNOTE: %s",e.note);

	                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                        printf("\n1. PERIOD TIME.");

	                printf("\n2. SUBJECT NAME");
	
	                printf("\n3. TOPIC ");

	                printf("\n4. LECTURER");

	                printf("\n5.NOTE.");

	                printf("\n6.GO BACK TO MAIN MENU.");

	                do
	
        	        {

	                    printf("\n\tENTER YOUR CHOICE:");

	                    fflush(stdin);

	                    scanf("%d",&num);

	                    fflush(stdin);

	                    switch(num)

	                    {

	                    case 1:
        	                printf("\nENTER THE NEW DATA:");

	                        printf("\nNEW PERIOD TIME:[hh:mm]:");

	                        gets(e.periodtime);
		
	                        break;

	                    case 2:
        	                printf("\nENTER THE NEW DATA:");
	
        	                printf("\n NEW SUBJECT NAME: ");

	                        gets(e.subject);

	                        break;

	                    case 3:
	                        printf("\nENTER THE NEW DATA:");

	                        printf("\nNEW TOPIC:");

	                        gets(e.topic);

	                        break;

	                    case 4:
        	                printf("\nENTER THE NEW DATA:");
		
                	        printf("\n LECTURER:");

	                        gets(e.lecturer);

	                        break;

	                    case 5:
        	                printf("ENTER THE NEW DATA:");
	
        	                printf("\n NEW NOTE:");
	
        	                gets(e.note);

	                        break;


	                    case 6:
        	                printf("\nPRESS ANY KEY TO GO BACK...\n");

	                        getch();

	                        return ;

	                        break;

	                    default:
        	                printf("\nYOU SELECTED WRONG OPTION...TRY AGAIN\n");

	                        break;
	
        	            }

	                }
			while(num<1||num>7);

	                fseek(fpte,-(long int)sizeof(e),SEEK_CUR);

	                fwrite(&e,sizeof(e),1,fpte);

	                fseek(fpte,-(long int)sizeof(e),SEEK_CUR);

	                fread(&e,sizeof(e),1,fpte);

	                choice=10;

	                break;       

        }

        if(choice==10)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("---**********-------\n");

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE.(Y/N)");

            scanf("%c",&choice);

            count++;

        }
   	else

        {

            printf("\n THE NOTE DOES NOT EXIST TO EDIT:\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getch();
    

}
void deletenotes( )

{

    system("cls");

    FILE *fp,*fptr ;

    struct notes e ;

    SetColorAndBackground(31,28);

    char filename[15],another = 'Y' ,time[10];;

    int choice,check;

    printf("\n\n\t\t::::::***********************:::::::\n");

    printf("\t\t\t: DELETE NOTES :");

    printf("\n\t\t:********************:\n\n");

    while ( another == 'Y' )

    {

        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t1. DELETE  NOTES\t\t\t");

        printf("\n\t2. NOT INTERESTED, EXIT");

        do

        {

            printf("\n\t\tENTER YOU CHOICE:");

            scanf("%d",&choice);

            switch(choice)

            {

            case 1:

                printf("\n\tENTER THE DATE OF NOTE TO BE DELETED:[dd-mm-yyyy]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "wb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    getch();

                    return ;

                }

                fclose(fp);

                remove(filename);

                printf("\nDELETED SUCCESFULLY...");

                break;

            case 2:

                return;

            default:

                printf("\n\tYOU ENTERED WRONG CHOICE");

                break;

            }

        }
        while(choice<1||choice>2);

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER NOTE.(Y/N):");

        fflush(stdin);

        scanf("%c",&another);

    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

}

    