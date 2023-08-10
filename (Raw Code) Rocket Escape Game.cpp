#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<dos.h>
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<graphics.h>
#include <windows.h>
#include <pthread.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
int DELAY = 40, borderColor = GREEN, margin = 120, topMargin = 50;
using namespace std;
void rectangle()
{
    setcolor(borderColor);
    rectangle(46,topMargin-4,654,654);
    rectangle(50,topMargin,650,650);
    rectangle(48,topMargin-2,652,652);

}
class ROCKET
{
public:
    int  cp, init, op1, op2, op3, op4, op5, op6,op7, op8,op9,op10;
    ROCKET()
    {
        cp = 300;
        init = 0;
        op1 = -5;
        op2 = -10;
        op3 = -15;
        op4= -20;
        op5= -40;
        op6= -30;
        op7=-60;
        op8=-70;
        op9=-90;
        op10=-95;
    }
} rocket;

int randx( void )
{
    int x ;
    x = rand() % 601;
    return ( x );
}

void right()
{
    if ( rocket.cp < 605 )
        rocket.cp += 15;
}

void left()
{
    if ( rocket.cp > 55 )
        rocket.cp -= 15;
}

int rocketWide = 26, rocketLength = 80;
int rocketTop = 333, rocketDown = rocketTop+rocketLength;
int halfWide = rocketWide/2, halfLength = rocketLength/2;
int headWide = halfLength-5;
int wingWide = 13;
int topWingLength = 38, downWingLength = 40;

void Rocket()
{
    int rocketLeft = rocket.cp, rocketRight = rocket.cp + rocketWide;
    // Rocket body
    setcolor(WHITE);
    rectangle(rocketLeft, rocketTop, rocketRight, rocketDown);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketLeft+3, rocketTop+3, 15);
    // Rocket head
    line(rocketLeft, rocketTop, rocketLeft + halfWide, rocketTop - headWide);//left
    line(rocketLeft + halfWide, rocketTop - headWide, rocketRight, rocketTop);//right
    line(rocketLeft, rocketTop, rocketRight, rocketTop);//planeline
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(rocketLeft+3, rocketTop-3, 15);
    // Rocket left up wing
    setfillstyle(SOLID_FILL, BLUE);
    line(rocketLeft, rocketTop, rocketLeft, rocketTop + topWingLength);//perpendicular
    line(rocketLeft - wingWide, rocketTop + topWingLength, rocketLeft, rocketTop + topWingLength);//plane
    line(rocketLeft - wingWide, rocketTop + topWingLength, rocketLeft, rocketTop);//hypotenuse
    floodfill(rocketLeft-2, rocketTop + topWingLength-2, 15);
    // Rocket right up wing
    setfillstyle(SOLID_FILL, BLUE);
    line(rocketRight, rocketTop + topWingLength, rocketRight + wingWide, rocketTop + topWingLength);//plane
    line(rocketRight, rocketTop, rocketRight + wingWide, rocketTop + topWingLength);//hypotenuse
    line(rocketRight, rocketTop, rocketRight, rocketTop + topWingLength);//perpendicular
    floodfill(rocketRight+2, rocketTop + topWingLength-2, 15);
    // Rocket left down wing
    setfillstyle(SOLID_FILL, BLUE);
    line(rocketLeft, rocketDown - downWingLength, rocketLeft, rocketDown - downWingLength);//perpendicular
    line(rocketLeft - wingWide, rocketDown, rocketLeft, rocketDown);//plane
    line(rocketLeft - wingWide, rocketDown, rocketLeft, rocketDown - downWingLength);//hypotenuse
    floodfill(rocketLeft-2, rocketDown-2, 15);
    // Rocket right down wing
    setfillstyle(SOLID_FILL, BLUE);
    line(rocketRight, rocketDown, rocketRight + wingWide, rocketDown);//plane
    line(rocketRight, rocketDown - downWingLength, rocketRight + wingWide, rocketDown);//hypotenuse
    line(rocketRight, rocketDown - downWingLength, rocketRight, rocketDown);//perpendicular
    floodfill(rocketRight+2, rocketDown-2, 15);
    //Rocket fire
    int minfireLength = 15, fireLength = minfireLength + rand()%(halfLength+halfWide);
    line(rocketLeft, rocketDown, rocketLeft + halfWide, rocketDown + fireLength);//left
    line(rocketLeft + halfWide, rocketDown + fireLength, rocketRight, rocketDown);//right
    line(rocketLeft, rocketDown, rocketRight, rocketDown);//planeline
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(rocketLeft+halfWide, rocketDown+1, WHITE);
}

void opp1( int x1 )
{
    if ( x1 >= 50 && x1+30 <= 650 && rocket.op1 < 600 )
    {
        rocket.op1 += 5;
        setfillstyle( 1, 1 );
        bar3d( x1, rocket.op1+topMargin, x1 + 30, rocket.op1 + 30, 2, 3 );
    }
    else
        rocket.op1 = 0;
}

void opp2( int x2 )
{
    if ( x2 >= 50 && x2+30 <= 650 && rocket.op2 < 600 )
    {
        rocket.op2 += 7;
        setfillstyle( 1, 2 );
        bar3d( x2, rocket.op2, x2 + 30, rocket.op2 + 30, 2, 3 );
    }
    else
        rocket.op2 = 0;
}

void opp3( int x3 )
{
    if ( x3 >= 50 && x3+30 <= 650 && rocket.op3 < 600 )
    {
        rocket.op3 += 7;
        setfillstyle( 1, 3 );
        bar3d( x3, rocket.op3, x3 + 30, rocket.op3 + 30, 2, 3 );
    }
    else
        rocket.op3 = 0;
}

void opp4( int x4 )
{
    if ( x4 >= 50 && x4+50 <= 650 && rocket.op4 < 600 )
    {
        rocket.op4 += 5;
        setfillstyle( 1, 4 );
        bar3d( x4, rocket.op4, x4 + 50, rocket.op4 + 30, 2, 3 );
    }
    else
        rocket.op4 = 0;
}

void opp5( int x5 )
{
    if ( x5+220 < 650 && x5+180 > 50 && rocket.op5 < 600 )
    {
        rocket.op5 += 5;
        setfillstyle( 1, WHITE );
        setcolor( WHITE );
        //bar3d( x5, rocket.op5, x5 + 7, rocket.op5 + 30, 2, 3 );
        line(200+x5,100+rocket.op5-margin,205+x5,120+rocket.op5-margin);
        line(200+x5,100+rocket.op5-margin,195+x5,120+rocket.op5-margin);

        line(195+x5,120+rocket.op5-margin,180+x5,125+rocket.op5-margin);
        line(180+x5,125+rocket.op5-margin,195+x5,130+rocket.op5-margin);
        line(195+x5,130+rocket.op5-margin,200+x5,150+rocket.op5-margin);
        line(200+x5,150+rocket.op5-margin,205+x5,130+rocket.op5-margin);

        line(205+x5,130+rocket.op5-margin,220+x5,125+rocket.op5-margin);
        line(220+x5,125+rocket.op5-margin,205+x5,120+rocket.op5-margin);
        floodfill(x5+200, rocket.op5+120-margin, WHITE);

    }
    else
        rocket.op5 = 0;
}

void opp7( int x7 )
{
    if ( x7 >= 50 && x7+30 <= 650 && rocket.op7 < 600 )
    {
        rocket.op7 += 10;
        setfillstyle( 1, 7 );
        bar3d( x7, rocket.op7, x7 + 30, rocket.op7 + 30, 2, 3 );
    }
    else
        rocket.op7 = 0;
}

int checkStar(int x, int op, int cp)
{
    if(op+150-margin <=433 && op+120-margin >= 300 && x+180 <= cp+37 && x+220 >= cp)
        return 1;
    return 0;
}

int check( int x, int op, int cp )
{
    int a[ 31 ], b[ 31 ], c[ 40 ], d[ 50 ];

    for ( int i = 0; i < 30; i++ )
        a[ i ] = x + i;

    for ( int i = 0; i < 30; i++ )
        b[ i ] = op + i;

    for (int i = 0; i < 40; i++ )
        c[ i ] = cp + i;

    for (int i = 0; i < 50; i++ )
        d[ i ] = 300 + i;

    for (int i = 0; i < 40; i++ )
        for ( int j = 0; j < 50; j++ )
            for ( int k = 0; k < 30; k++ )
                if ( a[ k ] == c[ i ] && b[ k ] == d[ j ] )
                    return 1;

    return 0;
}

void logo ()
{
    int page = 0;

    for ( int i = 1; i < 10; i++ )
    {
        setactivepage(page);
        setvisualpage(page^1);
        cleardevice();
        int p;
        setcolor( 2 );
        setfillstyle( SOLID_FILL, LIGHTBLUE );
        settextstyle( 8, HORIZ_DIR,3 );
        outtextxy(150,150,"  ROCKET ESCAPE GAME " );
        setcolor( WHITE );
        settextstyle( 8, HORIZ_DIR, 1.8 );
        outtextxy(10,250, "PRESENTED TO : DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING " );
        outtextxy(130,300, "PRESENTED BY : ABDULLAH AL MANSUR ");
        outtextxy(200,350,"ID: CE16030");

        if(i == 9)
        {
            outtextxy(130,500,"\n\n\t\t\tPlease, Press any key to continue\n");
            page ^= 1;
            setactivepage(page);
            break;
        }

        page ^= 1;
    }
    delay( 2000 );
    setvisualpage(page^1);
    getch();
}

void over( int score )
{
    Beep(2000,300);
    Beep(2500,500);
    Beep(3000,800);
    char a[50];
    sprintf(a, "%d", score);
    int n = 0;
    FILE* f;
    f = fopen("score.txt", "r");

    if(f!=NULL)
    {
        if(!feof(f))
            fscanf(f,"%d",&n);
        fclose(f);
    }
    int newHigh=0;

    if(score>n)
    {
        f = fopen("score.txt", "w");
        fprintf(f, "%d",score);
        newHigh=1;
        fclose(f);
    }
    int page = 0;

    for ( int i = 1; i < 35; i++ )
    {
        setactivepage(page);
        setvisualpage(page^1);
        cleardevice();
        settextstyle( 8, 0, 4 );
        setcolor( RED );

        if(newHigh==1)
        {
            outtextxy(150,250,"Congratulations");
            outtextxy(150,300,"New High Score");
        }
        setcolor(GREEN);
        outtextxy( 150, 100, "!!!GAME OVER!!!" );
        outtextxy(150,165,"Your score = ");
        outtextxy(400,165,a);
        page ^= 1;
    }
    delay( 2000 );
}

int lifeBar(int x, int y)
{
    double r = (x*1.0)/y;
    int l = r*100;
    setcolor(WHITE);
    rectangle(10, 10, 114, 30);

    if(l > 80)
    {
        setcolor(GREEN);
        rectangle(12, 12, 12+l, 28);
        setfillstyle(1, GREEN);
        floodfill(15, 15, GREEN);
    }
    else if(l > 60)
    {
        setcolor(BLUE);
        rectangle(12, 12, 12+l, 28);
        setfillstyle(1, BLUE);
        floodfill(15, 15, BLUE);
    }
    else if(l > 40)
    {
        setcolor(DARKGRAY);
        rectangle(12, 12, 12+l, 28);
        setfillstyle(1, DARKGRAY);
        floodfill(15, 15, DARKGRAY);
    }
    else if(l > 20)
    {
        setcolor(YELLOW);
        rectangle(12, 12, 12+l, 28);
        setfillstyle(1, YELLOW);
        floodfill(15, 15, YELLOW);
    }
    else if(l > 0)
    {
        setcolor(RED);
        rectangle(12, 12, 12+l, 28);
        setfillstyle(1, RED);
        floodfill(15, 15, RED);
    }
}

int gameOver;

void *keyPress(void *id)
{
    int m;

    while(true)

    {
        if(gameOver)
            break;
        m = getch();
        switch ( m )
        {
        case LEFT:
            left();
            break;
        case RIGHT:
            right();
            break;
        case 'q':
            exit( 0 );
        }
    }
    pthread_exit(NULL);
}

int play( void )
{
    int score = 0, iniLife = 10, life = iniLife, m, x1, x2, x3,x4,x5,x6,x7,x8,x9,x10,s;
    int n = 0;
    FILE* f;
    f = fopen("score.txt", "r");

    if(f!=NULL)
    {
        if(!feof(f))
            fscanf(f,"%d",&n);
        fclose(f);
    }
    char arr3[50];
    sprintf(arr3,"High score : %d",n);
    char arr[50], arr2[50];
    sprintf(arr,"Life : %d",life);
    int color[] = {0, 9, 5, 10, 6, 11, 7, 12, 8, 13};
    int numColor = sizeof(color)/sizeof(int);
    static int changeRecColor = 0, colorDelay = 0;
    pthread_t th;
    pthread_create(&th, NULL, keyPress, (void *)&th);
    int page = 0;

    while(life)
        while (true)
        {
            setactivepage(page);
            setvisualpage(page^1);
            cleardevice();
            rectangle();
            setfillstyle(SOLID_FILL,color[changeRecColor]);
            floodfill(300,300,borderColor);
            colorDelay++;

            if(colorDelay % DELAY == 0)
            {
                changeRecColor++;
                changeRecColor %= numColor;
            }
            if ( rocket.op1 == 0 ) //
            {

                rocket.op1+=50;
                x1 = randx();
            }
            else if ( rocket.op1 < 1 )
                rocket.op1++;
            else
                opp1( x1 );

            if ( rocket.op2 == 0 )
            {
                rocket.op2+=50;
                x2 = randx();
            }
            else if ( rocket.op2 < 1 )
                rocket.op2++;
            else
                opp2( x2 );

            if ( rocket.op3 == 0 )
            {
                rocket.op3+=50;
                x3 = randx();
            }
            else if ( rocket.op3 < 1 )
                rocket.op3++;
            else
                opp3( x3 );

            if ( rocket.op4 == 0 )
            {
                x4 = randx();
                rocket.op4+=50;
            }
            else if ( rocket.op4 < 1 )
                rocket.op4++;
            else
                opp4( x4 );

            if ( rocket.op5 == 0 )
            {
                x5 = randx();
                rocket.op5+=50;
            }
            else if ( rocket.op5 < 1 )
                rocket.op5++;
            else
                opp5( x5 );

            if ( rocket.op6 == 0 )
            {
                rocket.op6+=50;
                x6 = randx();
            }
            else if ( rocket.op6 < 1 )
                rocket.op6++;

            if ( rocket.op7 == 0 )
            {
                rocket.op7+=50;
                x7 = randx();

            }
            else if ( rocket.op7 < 1 )
            {
                rocket.op7++;
            }
            else
                opp7( x7 );

            setcolor( 10 );
            Rocket();
            settextstyle( 8, 0, 3 );
            sprintf(arr2,"Score : %d",score);
            outtextxy(180,10,arr3);
            outtextxy(470,10,arr2);

            if((checkStar(x5,rocket.op5,rocket.cp)))
            {
                score+=500;
                rocket.op5 = -55;
            }
            if ( check( x2, rocket.op2, rocket.cp ) || check( x1, rocket.op1, rocket.cp ) || check( x3, rocket.op3, rocket.cp ) || check( x4, rocket.op4, rocket.cp )|| check( x6, rocket.op6, rocket.cp )||check( x7, rocket.op7, rocket.cp )||check( x8, rocket.op8, rocket.cp )||check( x9, rocket.op9, rocket.cp )||check( x10, rocket.op10, rocket.cp ))
            {
                life--;
                Beep(1000,300);

                if ( life == 0 )
                {
                    lifeBar(life, iniLife);
                    setvisualpage(page);
                    gameOver = 1;
                    break;
                }
                if ( life == 1 )
                {
                    rocket.op1 = 0;
                    rocket.op2 = -25;
                    rocket.op3 = -45;
                    rocket.op4 = -10;
                    rocket.op5 = -25;
                    rocket.op6 = -60;
                    rocket.op7 = -37;
                    rocket.op8 = -75;
                    rocket.op9 = -90;
                    rocket.op10 = -95;

                }
                if ( life == 2 )
                {
                    rocket.op1 = 0;
                    rocket.op2 = -5;
                    rocket.op3 = -15;
                    rocket.op4 = -25;
                    rocket.op5 = -63;
                    rocket.op6 = -50;
                    rocket.op7 = -37;
                    rocket.op8 = -45;
                    rocket.op9 = -80;
                    rocket.op10 = -95;

                }
                rocket.op1 = 1;
                rocket.op2 = -35;
                rocket.op3 = -45;
                rocket.op4 = -40;
                rocket.op6 = -60;
                rocket.op7 = -70;
                rocket.op8 = -80;
                rocket.op9 = -90;
                rocket.op10 = -95;
                page ^= 1;
                break;
            }
            lifeBar(life, iniLife);
            delay(10);
            page ^= 1;
        }
    over(score);
}

void menu()
{
    int t = 0, p = 140, s = 1, a = 0;
    do
    {
        int page = 0;

        do
        {
            setactivepage(page);
            cleardevice();
            setcolor( 11 );
            settextstyle( 8, 0, 4 );
            outtextxy( 230, 30, "MENU" );
            settextstyle( 8, 0, 1 );
            setcolor( 10 );
            outtextxy( 220, 137, "PLAY GAME" );
            outtextxy( 220,167, "DEVELOPERS" );
            outtextxy( 220,197, "EXIT" );
            setcolor( RED );
            rectangle( 200, p, 350, p + 20 );
            setvisualpage(page);
            a = getch();

            switch ( a )
            {
            case UP:
                if ( p > 140 )
                {
                    p -= 30;
                    s--;
                }
                break;

            case DOWN:
                if ( p < 180 )
                {
                    p += 30;
                    s++;
                }
                break;

            case ENTER:
                a = 1;
                break;

            default:
                break;
            }
            page ^= 1;
        }
        while ( a != 1 );

        switch ( s )
        {
        case 1:
            gameOver = 0;
            play();
            break;

        case 2:
            logo();
            break;

        case 3:
            exit( 0 );
            break;
        }
    }
    while ( t == 0 );
}

int main()
{
    int gdriver = DETECT, gmode;
    initwindow(700,750);
    logo();
    menu();
    getch();
    return 0;
}
