#include<graphics.h>
#include<easyx.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#include <process.h> 
#include <stdio.h> 
#include"resource.h"

#pragma comment( lib, "MSIMG32.LIB")
#pragma comment (lib, "winmm.lib")

using namespace std;

int b;
int birdcolor;
int pipe_x = 288;
int pipe_yU;
int pipe_yD;
int sc1;
int sc2;
int score = 0;
double birdY = 220;
char ch;
char ch2;

MOUSEMSG MHIT;

IMAGE backgroundimg;
IMAGE button_play;
IMAGE title;
IMAGE land;
IMAGE tutorial;
IMAGE gameov;
IMAGE score_panel;
IMAGE bird1[4];
IMAGE bird2[4];
IMAGE bird3[4];
IMAGE pipeU; 
IMAGE pipeD;
IMAGE scoreimg1[4][10];


void transparentimage(IMAGE* dstimg, double x, double y, IMAGE* srcimg, UINT transparentcolor)
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

int loadbackg()
{
    initgraph(288, 512);

    srand((unsigned)time(NULL));
    b = rand() % 2;

    if (b > 0)
    {
        loadimage(&backgroundimg, L"png", MAKEINTRESOURCE(IDB_PNG1));
        loadimage(&pipeD, L"png", MAKEINTRESOURCE(IDB_PNG61));
        loadimage(&pipeU, L"png", MAKEINTRESOURCE(IDB_PNG62));
    }

    else
    {
        loadimage(&backgroundimg, L"png", MAKEINTRESOURCE(IDB_PNG2));
        loadimage(&pipeD, L"png", MAKEINTRESOURCE(IDB_PNG63));
        loadimage(&pipeU, L"png", MAKEINTRESOURCE(IDB_PNG64));
    }

    putimage(0, 0, &backgroundimg);
    loadimage(&button_play, L"png", MAKEINTRESOURCE(IDB_PNG19));
    loadimage(&title, L"png", MAKEINTRESOURCE(IDB_PNG68));
    transparentimage(NULL, 86, 412, &button_play, RGB(0,0,0));
    transparentimage(NULL, 55, 200, &title, RGB(0, 0, 0));
    return 0;
}

int loadscore()
{

    loadimage(&scoreimg1[1][0], L"png", MAKEINTRESOURCE(IDB_PNG24));
    loadimage(&scoreimg1[1][1], L"png", MAKEINTRESOURCE(IDB_PNG25));
    loadimage(&scoreimg1[1][2], L"png", MAKEINTRESOURCE(IDB_PNG26));
    loadimage(&scoreimg1[1][3], L"png", MAKEINTRESOURCE(IDB_PNG27));
    loadimage(&scoreimg1[1][4], L"png", MAKEINTRESOURCE(IDB_PNG28));
    loadimage(&scoreimg1[1][5], L"png", MAKEINTRESOURCE(IDB_PNG29));
    loadimage(&scoreimg1[1][6], L"png", MAKEINTRESOURCE(IDB_PNG30));
    loadimage(&scoreimg1[1][7], L"png", MAKEINTRESOURCE(IDB_PNG31));
    loadimage(&scoreimg1[1][8], L"png", MAKEINTRESOURCE(IDB_PNG32));
    loadimage(&scoreimg1[1][9], L"png", MAKEINTRESOURCE(IDB_PNG33));

    loadimage(&scoreimg1[2][0], L"png", MAKEINTRESOURCE(IDB_PNG40));
    loadimage(&scoreimg1[2][1], L"png", MAKEINTRESOURCE(IDB_PNG41));
    loadimage(&scoreimg1[2][2], L"png", MAKEINTRESOURCE(IDB_PNG42));
    loadimage(&scoreimg1[2][3], L"png", MAKEINTRESOURCE(IDB_PNG43));
    loadimage(&scoreimg1[2][4], L"png", MAKEINTRESOURCE(IDB_PNG44));
    loadimage(&scoreimg1[2][5], L"png", MAKEINTRESOURCE(IDB_PNG45));
    loadimage(&scoreimg1[2][6], L"png", MAKEINTRESOURCE(IDB_PNG46));
    loadimage(&scoreimg1[2][7], L"png", MAKEINTRESOURCE(IDB_PNG47));
    loadimage(&scoreimg1[2][8], L"png", MAKEINTRESOURCE(IDB_PNG48));
    loadimage(&scoreimg1[2][9], L"png", MAKEINTRESOURCE(IDB_PNG49));

    loadimage(&scoreimg1[2][0], L"png", MAKEINTRESOURCE(IDB_PNG51));
    loadimage(&scoreimg1[3][1], L"png", MAKEINTRESOURCE(IDB_PNG52));
    loadimage(&scoreimg1[3][2], L"png", MAKEINTRESOURCE(IDB_PNG53));
    loadimage(&scoreimg1[3][3], L"png", MAKEINTRESOURCE(IDB_PNG54));
    loadimage(&scoreimg1[3][4], L"png", MAKEINTRESOURCE(IDB_PNG55));
    loadimage(&scoreimg1[3][5], L"png", MAKEINTRESOURCE(IDB_PNG56));
    loadimage(&scoreimg1[3][6], L"png", MAKEINTRESOURCE(IDB_PNG57));
    loadimage(&scoreimg1[3][7], L"png", MAKEINTRESOURCE(IDB_PNG58));
    loadimage(&scoreimg1[3][8], L"png", MAKEINTRESOURCE(IDB_PNG59));
    loadimage(&scoreimg1[3][9], L"png", MAKEINTRESOURCE(IDB_PNG60));

    return 0;

}

int putscore()
{
    
    transparentimage(NULL, 180, 0, &scoreimg1[1][sc2], RGB(0, 0, 0));
    FlushBatchDraw();
    transparentimage(NULL, 180 - 24, 0, &scoreimg1[1][sc1], RGB(0, 0, 0));
    FlushBatchDraw();
    
    if (score > 99)
        score = 99;

    return 0;
}

int judgement()
{

   if (_kbhit())
   {
       ch2 = _getch();
       if (ch2 == ' ')
       {
           birdY -= 120;
       }
   }
      
    return 0;
}

int gameover()
{
    loadimage(&gameov, L"png", MAKEINTRESOURCE(IDB_PNG66));
    loadimage(&score_panel, L"png", MAKEINTRESOURCE(IDB_PNG65));
    putimage(0, 0, &backgroundimg);
    FlushBatchDraw();
    transparentimage(NULL, 40, 180, &gameov, RGB(0, 0, 0));
    FlushBatchDraw();
    Sleep(1000);
    putimage(0, 0, &backgroundimg);
    FlushBatchDraw();
    transparentimage(NULL, 30, 180, &score_panel, RGB(0, 0, 0));
    FlushBatchDraw();
    transparentimage(NULL, 180, 0, &scoreimg1[3][sc2], RGB(0, 0, 0));
    FlushBatchDraw();
    transparentimage(NULL, 180 - 24, 0, &scoreimg1[3][sc1], RGB(0, 0, 0));
    FlushBatchDraw();
    _getch();
    //Sleep(100000000);

    return 0;
}

int loadgame()
{
    srand((unsigned)time(NULL));
    birdcolor = rand() % 3;
    loadimage(&bird1[1], L"png", MAKEINTRESOURCE(IDB_PNG3));
    loadimage(&bird1[2], L"png", MAKEINTRESOURCE(IDB_PNG6));
    loadimage(&bird1[3], L"png", MAKEINTRESOURCE(IDB_PNG9));

    loadimage(&bird2[1], L"png", MAKEINTRESOURCE(IDB_PNG4));
    loadimage(&bird2[2], L"png", MAKEINTRESOURCE(IDB_PNG7));
    loadimage(&bird2[3], L"png", MAKEINTRESOURCE(IDB_PNG10));

    loadimage(&bird3[1], L"png", MAKEINTRESOURCE(IDB_PNG5));
    loadimage(&bird3[2], L"png", MAKEINTRESOURCE(IDB_PNG8));
    loadimage(&bird3[3], L"png", MAKEINTRESOURCE(IDB_PNG11));

    int Lx = 0;
    cleardevice();
    putimage(0, 0, &backgroundimg);
    loadimage(&tutorial, L"png", MAKEINTRESOURCE(IDB_PNG69));
    transparentimage(NULL, 78, 180, &tutorial, RGB(0, 0, 0));

    while(1)
    {
        loadimage(&land, L"png", MAKEINTRESOURCE(IDB_PNG34));

        Lx -= 12;
        if (Lx < -36)
        {
            Lx = 0;
        }

        transparentimage(NULL, Lx, 400, &land, RGB(0, 0, 0));
        transparentimage(NULL, 110, birdY, &bird1[birdcolor + 1], RGB(0, 0, 0));
        Sleep(100);
        transparentimage(NULL, 110, birdY, &bird2[birdcolor + 1], RGB(0, 0, 0));
        Sleep(100);
        transparentimage(NULL, 110, birdY, &bird3[birdcolor + 1], RGB(0, 0, 0));
        Sleep(100);
        ch2 = _getch();

        if (ch2 == ' ')break;
    }

    pipe_yD = rand() % 150;
    pipe_yU = pipe_yD + 100;

    loadscore();

    while (1)
    {

        birdY += 80; 
        judgement();

        if (pipe_x == 108)
            score++;

        sc2 = score % 10;
        sc1 = (score - sc2) / 10;
        pipe_x -= 12;

        if (pipe_x < 0)  
        {
            pipe_x = 288;
            pipe_yD = rand() % 150;
            pipe_yU = pipe_yD + 200;
        }

        BeginBatchDraw();
        putimage(0, 0, &backgroundimg);
        putscore();
        loadimage(&land, L"png", MAKEINTRESOURCE(IDB_PNG34));
        srand((unsigned)time(NULL));
        transparentimage(NULL, pipe_x, pipe_yD - 320, &pipeD, RGB(0, 0, 0));
        transparentimage(NULL, pipe_x, pipe_yU, &pipeU, RGB(0, 0, 0));

        Lx -= 12;
        if (Lx < -36)
        {
            Lx = 0;
        }

        transparentimage(NULL, Lx, 400, &land, RGB(0, 0, 0));
        transparentimage(NULL, 110, birdY, &bird1[birdcolor + 1], RGB(0, 0, 0));
        FlushBatchDraw();
        Sleep(100);
        transparentimage(NULL, 110, birdY, &bird2[birdcolor + 1], RGB(0, 0, 0));
        FlushBatchDraw();
        Sleep(100);
        transparentimage(NULL, 110, birdY, &bird3[birdcolor + 1], RGB(0, 0, 0));
        FlushBatchDraw();
        Sleep(50);

        if (birdY > 380)
            break;
       /* else if (birdY < 0)
            break;
        else if (birdY < pipe_yD && pipe_x < 155)
            break;
        else if (birdY > pipe_yU - 40 && pipe_x < 155)
            break;*/
        else
            continue;

    }
    return 0;
}



int main()
{

   /* WNDCLASSEX wc;
    wc.cbSize = sizeof(wc);

    wc.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
    wc.hIconSm = LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
    SendMessage(hWnd, WM_SETICON, (WPARAM)TRUE, (LPARAM)LoadIcon(GetModuleHandle(NULL), (LPCTSTR)IDI_ICON1));*/

    loadbackg();

    mciSendString(_T("open ..\\music\\0.mp3 alias music0"), NULL, 0, NULL);
    mciSendString(_T("play music0 repeat"), NULL, 0, NULL);

    while (!_kbhit())
    {
        if (_kbhit())
        {
            ch = _getch();
            if (13 == ch)
                break;
        }
    }

    loadgame();

    gameover();

    return 0;
}
