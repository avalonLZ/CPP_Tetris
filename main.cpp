/*************************************************************************
	> File Name: main.cpp
	> Author: LiZhong 
	> Mail: 
	> Created Time: Thu 02 Mar 2017 10:57:29 PM PST
 ************************************************************************/

#include<iostream>
#include<unistd.h>
//#include"Tetris.h"
#include"Tetris.cpp"//用到的cpp文件一定要包括进来
using namespace std;
using namespace TBlock;

void *FirstThread(void *temp)//线程回调函数固定格式
{
 while(1)
 {
    system("stty -icanon -echo");
   *(char*)temp = getchar();
    system("stty icanon echo");
 }
}

int main()
{
    char key = 0;
    pthread_t firstt;
    system("clear");

    Game<int> firstgame;
    firstgame.createcube();
    key = 'k';
    pthread_create(&firstt, NULL, FirstThread, (void*)(&key));

    //pthread_create(&firstt, NULL, FirstThread, (void*)&key);

    while(1)
    {
        fflush(stdout);
        usleep(500000);
        switch(key)
        {
            case 'j':
                firstgame.move(LEFT);
                //cout << "Left" << endl;
                //key = 'q';//quit
                break;
            
            case 'k':
                firstgame.move(DOWN);
                //cout << "Down" << endl;
                //key = 'q';
                break;

            case 'i':
                //cout << "Up" << endl;
                //key = 'q';
                break;

            case 'l':
                //cout << "Right" << endl;
                firstgame.move(RIGHT);
                //key = 'q';
                break;
            
            default:
                firstgame.move(DOWN);
                //cout << "Input Error" << endl;
                break;
        }
        firstgame.move(DOWN);
    }
    return 0;
}
