#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<Windows.h>
#include<MMSystem.h>
#include<iostream>
#include <stdlib.h>  //rand
#include <time.h>
#include <ctime>
#include <string.h>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;

void Start();
void Start2();


int n=1;
int n1=1;
//int nem = 0;

struct HighScoreStruct
{
    char name[100];
    int score;



    bool operator<(const HighScoreStruct& a) const
    {
        return score>a.score;
    }

};


void hs()
{
    HighScoreStruct hsr[100];
    int i=0,sc[100];
    char nm[100][30],scr[20];

    FILE *fp = fopen("hs.txt", "r");

    //while(fscanf(fp,"%s %d",nm[i], &sc[i])!=EOF);

    for(i=0; fscanf(fp,"%s %d",hsr[i].name, &hsr[i].score)!=EOF ; i++);


    vector<HighScoreStruct> myhs;
    for(int j = 0; j < i; j++)
    {
        myhs.push_back(hsr[j]);

    }

    sort(myhs.begin(), myhs.end());

    int ll=0;
    while(ll < i)
    {
        //settextstyle(style, HORIZ_DIR, 4);
        outtextxy(250,200+ll*20,myhs[ll].name);


        sprintf(scr,"%d",myhs[ll].score);

        outtextxy(400,200+ll*20,scr);

        ll++;

    }

}

int linkscore;


void hsw()
{
    int i=0,sc[100];

    int a;
    char hss[30];
    char nm[100][30],scr[50];

    readimagefile("Name.jpg", 0, 0, 650, 500);


    FILE *fp = fopen("hs.txt", "a");

    //scanf("%d", &a);

    while(1)
    {

        hss[i] = getch();


        printf("%d\n",hss[i]);

        if(hss[i]=='\b')
        {
            i--;
            hss[i]=='\0';
        }
        else
        {
            i++;
        }

        hss[i]='\0';

        readimagefile("Name.jpg", 0, 0, 650, 500);
        outtextxy(100,200, hss);

        if(hss[i-1]==13)
        {
            break;
        }

    }

    fprintf(fp,"%s %d\n",hss, linkscore);


    fclose(fp);


}



void copter()
{
    readimagefile("copter.gif", 250, 200, 400, 330);
    readimagefile("copter2.gif",  250, 200, 400, 330);
    readimagefile("copter3.gif",  250, 200, 400, 330);
}

void exp()
{

    int ex1 = 150, ey1 = 100, ex2=500, ey2=400;
    delay(70);
    //cleardevice();
    readimagefile("exp1.gif", ex1, ey1, ex2, ey2);
    delay(70);
    cleardevice();
    readimagefile("exp2.gif", ex1, ey1, ex2, ey2);
    delay(70);
    cleardevice();
    readimagefile("exp3.gif", ex1, ey1, ex2, ey2);
    delay(70);
    cleardevice();

}


void BG()
{

    readimagefile("MAINMENU.jpg", 0, 0, 700, 500);
    readimagefile("LOGO.gif", 80, 100, 550, 200);
    readimagefile("START.gif", 265, 350, 380, 380);
    readimagefile("HS.gif", 210, 395, 430, 425);
    readimagefile("QUIT.gif", 280, 440, 363, 470);
    readimagefile("help.gif", 5, 5, 45, 45);

}

void Intro()
{
    int i;
    int x1 = 250, y1=200, x2=400, y2=330;


    PlaySound("intro.WAV", NULL, NULL | SND_ASYNC);
    for(i=0; i<30; i++)
    {

        readimagefile("copter.gif", x1, y1, x2, y2);
        delay(40);
        cleardevice();

        x1= x1-15;
        x2= x2-15;

    }

    PlaySound("Null.wav", NULL, SND_LOOP| SND_ASYNC);

}

void Loading()
{

    delay(200);
    readimagefile("L1.jpg", 0, 0, 600, 500);
    delay(200);
    readimagefile("L2.jpg", 0, 0, 600, 500);
    delay(200);
    readimagefile("L3.jpg", 0, 0, 600, 500);
    delay(300);
    PlaySound("GBC.WAV", NULL, SND_LOOP| SND_ASYNC);

    cleardevice();
    delay(300);
    readimagefile("Level1.gif", 265, 250, 380, 280);
    delay(1100);
}

void help()
{

    int x, y;
    getmouseclick(WM_LBUTTONDOWN, x, y);

    delay(300);
    readimagefile("MainInstruction.jpg", 0, 0, 650, 500);
    readimagefile("back.gif", 15, 95, 50, 130);

    //return;

}


void Start2()
{
    int mx, my;

    srand(time(NULL));
    int ran = rand() % 400 + 1;
    int ran3 = rand() % 400 + 1;
    int ranx = rand() % 20 + 1;

    int i, bx1=0, by1=0, bx2=7500, by2=500,l;
    int px1 = 120, py1 = 200, px2 = 230, py2 = 290;
    int ox1 = 900, oy1 = ran + 0, ox2 = 1030, oy2 = ran + 100;

    int o1x1= 900, o1y1= ran3 + 0, o1x2 = 1030, o1y2 = ran3 +100;

    int z=7;
    int key;
    int nnn;
    double gg = 0;
    int nem=0;

    int rx1 =0, rx2=650, ry1=0, ry2=500;

    ran = 0;
    ran3 =0;

    int score=495;
    char scr[1000];

    for(i=0; i<1500; i=i+n)
    {

        readimagefile("Level2.jpg", bx1, by1, bx2, by2);
        readimagefile("player.gif", px1, py1, px2, py2);

        /////////////////////score//////////////////

        sprintf(scr,"%d",score);

        outtextxy(20,10,scr);


        if(nem!=1)
        {

            score++;

        }



        if((ox1==900)&&(ox2=1030))
        {
            srand(time(NULL));
            nnn = rand()%30+1;
        }

        if(nnn<=4)
        {
            readimagefile("Monster4.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=5 && nnn<=10)
        {
            readimagefile("Monster5.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=11 && nnn<=15)
        {
            readimagefile("Monster6.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=16 && nnn<=25)
        {
            readimagefile("Monster11.gif", ox1, oy1, ox2, oy2);
            readimagefile("Monster12.gif", o1x1, o1y1, o1x2, o1y2);
        }

        if(nnn>=26 && nnn<=30)
        {
            readimagefile("Monster13.gif", ox1, oy1, ox2, oy2);
            readimagefile("Monster6.gif", o1x1, o1y1, o1x2, o1y2);
        }


        bx1=bx1-7;
        bx2=bx2-7;

        py1 = py1+z;
        py2 = py2+z;

        z=z+2;

        ox1= ox1-20-gg;
        ox2= ox2-20-gg;

        if(ox1<900 && ox1>700){

            oy1=oy1-10;
            oy2=oy2-10;
        }

        if(ox1<700 && ox1>500){
            oy1=oy1+10;
            oy2=oy2+10;

        }

        if(ox1<500 && ox1>300){
            oy1=oy1-10;
            oy2=oy2-10;

        }

        if(ox1<300 && ox1>2){
            oy1=oy1+10;
            oy2=oy2+10;

        }

        o1x1 = o1x1 - 20 - ranx - gg;
        o1x2 = o1x2 - 20 - ranx - gg;

        //ranx = 0;

        gg = gg+0.05;


        if(ox1 < 2)
        {
            ox1=900;
            ox2=1030;


            o1x1=900;
            o1x2=1030;

            //srand(time(NULL));
            int ran = rand() % 400 + 1;
            int ran3 = rand() % 400 + 1;
            int ranx = rand() % 20 + 1;

            printf("%d\n", ran);

            oy1 = ran + 0;
            oy2 = ran + 100;


            o1y1=ran3 + 0;
            o1y2= ran3 + 100;

            ran = 0;
            ran3 = 0;
            //ranx = 0;

        }


        if (kbhit())
        {
            l = getch();

            while (l == 32)
            {
                if(py1>5)
                {
                    py1 = py1 -70;
                    py2 = py2 -70;
                }

                z=7;
                break;
            }
            while (l == 'p')
            {
                readimagefile("Pause.gif", 80, 150, 550, 300);
                while(1)
                {

                    if (kbhit())
                    {
                        l = getch();

                        break;
                    }

                }

            }
        }


        /////////////////AI/////////////////////////////
        if ((  ( ((px2-20>=ox1) && (px2<=ox2)) ||  ((px1>=ox1) && (px1<=ox2)) )   &&    (((py1>=oy1)&&(py1+40<=oy2)) || ((py2-20>=oy1)&&(py2<=oy2)))    ) ||
                (  ( ((px2-20>=o1x1) && (px2<=o1x2)) ||  ((px1>=o1x1) && (px1<=o1x2)) )   &&    (((py1>=o1y1)&&(py1+40<=o1y2)) || ((py2-20>=o1y1)&&(py2<=o1y2)))    ))
        {
            nem = 1;

            linkscore = score;

            int key;

            rx1=100;
            rx2=100;
            ry1=100;
            ry2=100;

            bx1=1000;
            bx2=1000;
            ox1=1500;
            ox2=1500;
            o1x1=1500;
            o1x2=1500;

            px1=0;
            px2=0;
            py1=0;
            py2=0;

            exp();

            hsw();


            readimagefile("GAMEOVER.jpg", 0, 0, 650, 500);

            if (kbhit())
            {
                key = getch();

                while (key == 13)
                {
                    nem = 0;
                    Start2();
                    break;
                }

            }

        }


        ////////////////////////////////////////////////

        if(py1 > 500)
        {
            py1 = 100000;


            nem = 1;
            linkscore = score;


            readimagefile("GAMEOVER.jpg", 0, 0, 650, 500);
            bx1=0;
            bx2=0;
            ox1=900;
            ox2=1030;

            o1x1=1500;
            o1x2=1500;

            rx1=100;
            rx2=100;
            ry1=100;
            ry2=100;

            if (kbhit())
            {
                l = getch();

                while (l == 13)
                {
                    nem = 0;
                    Start2();
                    break;
                }

               while (l == 27)
                {
                    closegraph();
                    initwindow(650, 500, "CHOPPER");

                    int x,y;
                    char k;


///////////////////////////////////////////////////////////////

                    PlaySound("NES.WAV", NULL, SND_LOOP | SND_ASYNC);

                                    BG();

                    while(1)
                    {

                        copter();


                        /////////////////////////////////////
                        if (kbhit())
                        {
                            k = getch();

                            while (k == 27)
                            {
                                closegraph();

                            }

                            while (k == 13)
                            {
                                PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                                delay(300);
                                Intro();
                                Loading();
                                Start();
                                break;
                            }
                        }

                        ////////////////////////////////


                        getmouseclick(WM_LBUTTONDOWN, x, y);


                        if (x>280 && x<370, y>350 && y<380)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(300);
                            Intro();
                            Loading();
                            Start();
                            break;
                        }

                        if (x>280 && x<370, y>440 && y<470)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(300);

                            closegraph();


                        }


                        /////////HS/////////////////


                        if(x>210 && x<430, y>395 && y<425)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(100);
                            readimagefile("MAINMENU.jpg", 0, 0, 700, 500);

                            while(1)
                            {

                                hs();

                                readimagefile("back.gif", 15, 95, 50, 130);
                                int kx, ky;

                                getmouseclick(WM_LBUTTONDOWN, kx, ky);

                                if (kx>15 && kx<50, ky>95 && ky<130)
                                {
                                    PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                                    delay(250);
                                    PlaySound("NES.WAV", NULL, SND_LOOP| SND_ASYNC);
                                    BG();
                                    break;
                                }
                            }
                        }

                        ///////////////////HELP/////////////////////////

                        if (x>5 && x<45, y>5 && y<45)
                        {

                            while(1)
                            {

                                help();

                                int hx,hy;
                                getmouseclick(WM_LBUTTONDOWN, hx, hy);

                                if (hx>15 && hx<50, hy>95 && hy<130)
                                {
                                    BG();
                                    break;
                                }

                            }

                        }

                        /////////////////////////////////////////////////
                    }
                    break;

                }

            }
        }


        //////////////////////WEATHER/////////////////////
        if((i>=100) && (i<175))
        {
            readimagefile("rain.gif",rx1, ry1, rx2, ry2);
        }

        if((i>150) && (i<153) )
        {
            readimagefile("storm.gif",rx1, ry1-100, rx2, ry2-300);
        }

        if((i>350) && (i<400) )
        {
            readimagefile("wind.gif",rx1, ry1, rx2, ry2);
        }


        ////////////////////////////////////////////////


        if(i==699)
        {

            i=0;
            bx1=0;
            bx2=7500;
            readimagefile("Level2.jpg", bx1, by1, bx2, by2);

        }

    }

}

//////////////////////////////////////////////////////////////////////

void Start()
{
    int mx, my;

    srand(time(NULL));
    int ran = rand() % 400 + 1;
    int ran3 = rand() % 400 + 1;
    int ranx = rand() % 20 + 1;

    int i, bx1=0, by1=0, bx2=7500, by2=500,l;
    int px1 = 120, py1 = 200, px2 = 230, py2 = 290;
    int ox1 = 900, oy1 = ran + 0, ox2 = 1030, oy2 = ran + 100;

    int o1x1= 900, o1y1= ran3 + 0, o1x2 = 1030, o1y2 = ran3 +100;

    int z=7;
    int key;
    int nnn;
    double gg = 0;

    int rx1 =0, rx2=650, ry1=0, ry2=500;

    ran = 0;
    ran3 =0;

    int score=0;
    char scr[1000];

    int nem = 0;


    for(i=0; i<1500; i=i+n)
    {

        readimagefile("Level1.jpg", bx1, by1, bx2, by2);
        readimagefile("player.gif", px1, py1, px2, py2);

//////////////////////score//////////////////


        sprintf(scr,"%d",score);

        outtextxy(20,10,scr);


        if(nem!=1)
        {
            score++;

        }


//////////////////////////////////////////////

        if((ox1==900)&&(ox2=1030))
        {
            srand(time(NULL));
            nnn = rand()%30+1;
        }

        if(nnn<=4)
        {
            readimagefile("Monster.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=5 && nnn<=10)
        {
            readimagefile("Monster2.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=11 && nnn<=15)
        {
            readimagefile("Monster3.gif", ox1, oy1, ox2, oy2);
            o1x1= 0, o1y1=  0, o1x2 =0, o1y2 =0;
        }

        if(nnn>=16 && nnn<=25)
        {
            readimagefile("Monster11.gif", ox1, oy1, ox2, oy2);
            readimagefile("Monster12.gif", o1x1, o1y1, o1x2, o1y2);
        }

        if(nnn>=26 && nnn<=30)
        {
            readimagefile("Monster13.gif", ox1, oy1, ox2, oy2);
            readimagefile("Alien.gif", o1x1, o1y1, o1x2, o1y2);
        }


        bx1=bx1-5;
        bx2=bx2-5;

        py1 = py1+z;
        py2 = py2+z;

        z=z+2;

        ox1= ox1-15-gg;
        ox2= ox2-15-gg;

        o1x1 = o1x1 - 15 - ranx - gg;
        o1x2 = o1x2 - 15 - ranx - gg;

        //ranx = 0;

        gg = gg+0.05;


        if(ox1 < 2)
        {
            ox1=900;
            ox2=1030;


            o1x1=900;
            o1x2=1030;

            //srand(time(NULL));
            int ran = rand() % 400 + 1;
            int ran3 = rand() % 400 + 1;
            int ranx = rand() % 20 + 1;

            printf("%d\n", ran);

            oy1 = ran + 0;
            oy2 = ran + 100;


            o1y1=ran3 + 0;
            o1y2= ran3 + 100;

            ran = 0;
            ran3 = 0;
            //ranx = 0;

        }


        if (kbhit())
        {
            int il;
            il = getch();

            while (il == 32)
            {
                if(py1>5)
                {
                    py1 = py1 -70;
                    py2 = py2 -70;
                }

                z=7;
                break;
            }

            while(il == 't')
            {

                i=494;
                break;

            }


            while (il == 'p')
            {
                readimagefile("Pause.gif", 80, 150, 550, 300);
                while(1)
                {

                    if (kbhit())
                    {
                        il = getch();

                        break;
                    }


                }


            }


        }


        /////////////////AI/////////////////////////////
        if ((  ( ((px2-20>=ox1) && (px2<=ox2)) ||  ((px1>=ox1) && (px1<=ox2)) )   &&    (((py1>=oy1)&&(py1+40<=oy2)) || ((py2-20>=oy1)&&(py2<=oy2)))    ) ||
                (  ( ((px2-20>=o1x1) && (px2<=o1x2)) ||  ((px1>=o1x1) && (px1<=o1x2)) )   &&    (((py1>=o1y1)&&(py1+40<=o1y2)) || ((py2-20>=o1y1)&&(py2<=o1y2)))    ))
        {


            nem = 1;

            linkscore = score;

            int key;

            rx1=100;
            rx2=100;
            ry1=100;
            ry2=100;

            bx1=1000;
            bx2=1000;
            ox1=1500;
            ox2=1500;
            o1x1=1500;
            o1x2=1500;

            px1=0;
            px2=0;
            py1=0;
            py2=0;

            exp();

            hsw();

            readimagefile("GAMEOVER.jpg", 0, 0, 650, 500);



            if (kbhit())
            {
                key = getch();

                while (key == 13)
                {
                    nem = 0;
                    Start();
                    break;
                }

            }

        }



        if(py1 > 500)
        {
            py1 = 10000;
            py2 = 10000;

            nem = 1;
            linkscore = score;



            bx1=0;
            bx2=0;
            ox1=900;
            ox2=1030;

            o1x1=1500;
            o1x2=1500;

            rx1=100;
            rx2=100;
            ry1=100;
            ry2=100;



            readimagefile("GAMEOVER.jpg", 0, 0, 650, 500);

            if (kbhit())
            {
                l = getch();

                while (l == 13)
                {
                    nem = 0;
                    Start();
                    break;
                }

                while (l == 27)
                {
                    closegraph();
                    initwindow(650, 500, "CHOPPER");

                    int x,y;
                    char k;


                    PlaySound("NES.WAV", NULL, SND_LOOP | SND_ASYNC);



                    BG();

                    while(1)
                    {

                        copter();


                        /////////////////////////////////////
                        if (kbhit())
                        {
                            k = getch();

                            while (k == 27)
                            {
                                closegraph();

                            }

                            while (k == 13)
                            {
                                PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                                delay(300);
                                Intro();
                                Loading();
                                Start();
                                break;
                            }
                        }

                        ////////////////////////////////


                        getmouseclick(WM_LBUTTONDOWN, x, y);


                        if (x>280 && x<370, y>350 && y<380)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(300);
                            Intro();
                            Loading();
                            Start();
                            break;
                        }

                        if (x>280 && x<370, y>440 && y<470)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(300);

                            //closegraph();
                            return;


                        }


                        /////////HS/////////////////


                        if(x>210 && x<430, y>395 && y<425)
                        {
                            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                            delay(100);
                            readimagefile("MAINMENU.jpg", 0, 0, 700, 500);

                            while(1)
                            {

                                hs();

                                readimagefile("back.gif", 15, 95, 50, 130);
                                int kx, ky;

                                getmouseclick(WM_LBUTTONDOWN, kx, ky);

                                if (kx>15 && kx<50, ky>95 && ky<130)
                                {
                                    PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                                    delay(250);
                                    PlaySound("NES.WAV", NULL, SND_LOOP| SND_ASYNC);
                                    BG();
                                    break;
                                }
                            }
                        }

                        ///////////////////HELP/////////////////////////

                        if (x>5 && x<45, y>5 && y<45)
                        {

                            while(1)
                            {

                                help();

                                int hx,hy;
                                getmouseclick(WM_LBUTTONDOWN, hx, hy);

                                if (hx>15 && hx<50, hy>95 && hy<130)
                                {
                                    BG();
                                    break;
                                }

                            }

                        }

                    }
                    break;

                }

            }
        }


        //////////////////////WEATHER/////////////////////
        if((i>=100) && (i<175))
        {
            readimagefile("rain.gif",rx1, ry1, rx2, ry2);
        }

        if((i>150) && (i<153) )
        {
            readimagefile("storm.gif",rx1, ry1-100, rx2, ry2-300);
        }

        if((i>350) && (i<400) )
        {
            readimagefile("wind.gif",rx1, ry1, rx2, ry2);
        }


        ////////////////////////////////////////////////

        if(i==495)
        {

            cleardevice();

            readimagefile("Level2.gif", 265, 250, 380, 280);
            delay(1000);
            cleardevice();
            PlaySound("HLK.WAV", NULL, SND_LOOP| SND_ASYNC);
            Start2();

        }

    }

}

int main()
{
    initwindow(650, 500, "CHOPPER");

    int x,y;
    char k;


///////////////////////////////////////////////////////////////

    PlaySound("NES.WAV", NULL, SND_LOOP | SND_ASYNC);


    BG();

    while(1)
    {

        copter();


        /////////////////////////////////////
        if (kbhit())
        {
            k = getch();

            while (k == 27)
            {
                closegraph();
                return 0;
            }

            while (k == 13)
            {
                PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                delay(300);
                Intro();
                Loading();
                Start();
                break;
            }
        }

        ////////////////////////////////


        getmouseclick(WM_LBUTTONDOWN, x, y);


        if (x>280 && x<370, y>350 && y<380)
        {
            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
            delay(300);
            Intro();
            Loading();
            Start();
            break;
        }

        if (x>280 && x<370, y>440 && y<470)
        {
            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
            delay(300);
            closegraph();
            return 0;
        }


        /////////HS/////////////////


        if(x>210 && x<430, y>395 && y<425)
        {
            PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
            delay(100);
            readimagefile("MAINMENU.jpg", 0, 0, 700, 500);

            while(1)
            {

                hs();

                readimagefile("back.gif", 15, 95, 50, 130);
                int kx, ky;

                getmouseclick(WM_LBUTTONDOWN, kx, ky);

                if (kx>15 && kx<50, ky>95 && ky<130)
                {
                    PlaySound("Select.WAV", NULL, NULL | SND_ASYNC);
                    delay(250);
                    PlaySound("NES.WAV", NULL, SND_LOOP| SND_ASYNC);
                    BG();
                    break;
                }
            }
        }


        ///////////////////HELP/////////////////////////

        if (x>5 && x<45, y>5 && y<45)
        {

            while(1)
            {

                help();

                int hx,hy;
                getmouseclick(WM_LBUTTONDOWN, hx, hy);

                if (hx>15 && hx<50, hy>95 && hy<130)
                {
                    BG();
                    break;
                }

            }

        }

    }


    return 0;
}
