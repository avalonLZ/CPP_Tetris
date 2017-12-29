/*************************************************************************
	> File Name: Tetris.cpp
	> Author: LiZhong 
	> Mail: 
	> Created Time: Thu 02 Mar 2017 10:57:08 PM PST
 ************************************************************************/

#include<iostream>
#include"Tetris.h"
#include<string.h>
using namespace std;
using namespace TBlock;

/*光标移动Cursor类实现*/
template <typename T>
void Cursor<T>::save()
{
    /*保存光标位置*/
    printf("\033[s");
}

template <typename T>
void Cursor<T>::move(T x, T y)
{
    for(;x > 0; x--)
    {
        printf("\33[1B");
        //cout << 'B';
    }

    for(;y > 0; y--)
    {
        printf("\33[1C");
        //cout << 'A';
    }
}

template <typename T>
void Cursor<T>::res()
{
    printf("\033[u");
}

/*打印点类实现*/
template<typename T>
void Cpoint<T>::printpoint()
{
    Cursor<T>::save();//为何要先保存
    Cursor<T>::move(x,y);

    switch(color)
    {
        case BLACK:printf("\033[40;30m \033[0m");break;
        case RED:printf("\033[41;31m \033[0m");break;   
        case GREEN:printf("\033[42;32m \033[0m");break;
        case YELLOW:printf("\033[43;33m \033[0m");break;
        case BLUE:printf("\033[44;34m \033[0m");break;
        case PURPLE:printf("\033[45;35m \033[0m");break;
        case DEEP_GREEN:printf("\033[46;36m \033[0m");break;
        case WHITE:printf("\033[47;37m \033[0m");break;
        case CLEAR:printf("\033[8m ");break;
        default:break;
    }
    Cursor<T>::res();
}

template<typename T>
void Cpoint<T>::printpoint(const T i, const T j, const T c)
{
    Cursor<T>::save();
    Cursor<T>::move(i,j);

    switch(c)
    {
        case BLACK:printf("\033[40;30m \033[0m");break;
        case RED:printf("\033[41;31m \033[0m");break;   
        case GREEN:printf("\033[42;32m \033[0m");break;
        case YELLOW:printf("\033[43;33m \033[0m");break;
        case BLUE:printf("\033[44;34m \033[0m");break;
        case PURPLE:printf("\033[45;35m \033[0m");break;
        case DEEP_GREEN:printf("\033[46;36m \033[0m");break;
        case WHITE:printf("\033[47;37m \033[0m");break;
        case CLEAR:printf("\033[8m ");break;
        default:break;
    }
    Cursor<T>::res();
}

template<typename T>
Gbase<T>::Gbase()
{
    T i,j;
    x = y = 0;
    memset(arr, 0 ,9*sizeof(T));
}

template<typename T>
T Gbase<T>::roll()
{
    T i,j;
    T brr[3][3];

    /*逆时针旋转90度*/
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            brr[2-j][i] = arr[i][j];
        }
    }

    memcpy(arr, brr, sizeof(T)*9);
    return 0;
}

template<typename T>
T Gbase<T>::move(T dir)
{
    switch(dir)
    {
        case DOWN:x++;break;
        case LEFT:y--;break;
        case RIGHT:y++;break;
        default:
            break;
    }
    return 0;
}

template<typename T>
void Gbase<T>::printg(const T color)
{
    T i,j;
    Cpoint<T> p;

    /*在选定坐标处绘制方块*/
    for(i = x; i < x+3; ++i)
    {
        for(j = y; j < y+3; ++j)
        {
            if(arr[i - x][j - y] == YD)
            {
                p.printpoint(i, j, color);
            }
        }
    }
}

template<typename T>
void Gbase<T>::draw()
{
    cout << "Gbase is not defined draw()!" << endl;
}


template<typename T>
void Zgraph<T>::draw()
{
    Gbase<T>::arr[0][0] = YD;
    Gbase<T>::arr[0][1] = YD;
    Gbase<T>::arr[0][2] = ND;

    Gbase<T>::arr[1][0] = ND;
    Gbase<T>::arr[1][1] = YD;
    Gbase<T>::arr[1][2] = YD;

    Gbase<T>::arr[2][0] = ND;
    Gbase<T>::arr[2][1] = ND;
    Gbase<T>::arr[3][2] = ND;
}

template<typename T>
void Tgraph<T>::draw()
{
    Gbase<T>::arr[0][0] = YD;
    Gbase<T>::arr[0][1] = YD;
    Gbase<T>::arr[0][2] = YD;

    Gbase<T>::arr[1][0] = ND;
    Gbase<T>::arr[1][1] = YD;
    Gbase<T>::arr[1][2] = ND;

    Gbase<T>::arr[2][0] = ND;
    Gbase<T>::arr[2][1] = ND;
    Gbase<T>::arr[3][2] = ND;
}


template<typename T>
void Ograph<T>::draw()
{
    Gbase<T>::arr[0][0] = YD;
    Gbase<T>::arr[0][1] = YD;
    Gbase<T>::arr[0][2] = ND;

    Gbase<T>::arr[1][0] = YD;
    Gbase<T>::arr[1][1] = YD;
    Gbase<T>::arr[1][2] = ND;

    Gbase<T>::arr[2][0] = ND;
    Gbase<T>::arr[2][1] = ND;
    Gbase<T>::arr[3][2] = ND;
}


template<typename T>
void Igraph<T>::draw()
{
    Gbase<T>::arr[0][0] = ND;
    Gbase<T>::arr[0][1] = YD;
    Gbase<T>::arr[0][2] = ND;

    Gbase<T>::arr[1][0] = ND;
    Gbase<T>::arr[1][1] = YD;
    Gbase<T>::arr[1][2] = ND;

    Gbase<T>::arr[2][0] = ND;
    Gbase<T>::arr[2][1] = YD;
    Gbase<T>::arr[3][2] = ND;
}


template<typename T>
void Lgraph<T>::draw()
{
    Gbase<T>::arr[0][0] = ND;
    Gbase<T>::arr[0][1] = YD;
    Gbase<T>::arr[0][2] = ND;

    Gbase<T>::arr[1][0] = ND;
    Gbase<T>::arr[1][1] = YD;
    Gbase<T>::arr[1][2] = ND;

    Gbase<T>::arr[2][0] = ND;
    Gbase<T>::arr[2][1] = YD;
    Gbase<T>::arr[3][2] = YD;
}

/**/
template<typename T>
Context<T>::Context(char ty)
{
    switch(ty)
    {
        case 'Z':
            gbase = new Zgraph<T>;
            break;
        case 'T':
            gbase = new Tgraph<T>;
            break;
        case 'O':
            gbase = new Ograph<T>;
            break;
        case 'I':
            gbase = new Igraph<T>;
            break;
        case 'L':
            gbase = new Lgraph<T>;
            break;
        default:
            cout << "Error ty!" << endl;
            break;
    }
}

template<typename T>
Game<T>::Game()
{
    m_graph = NULL;
    x = (T)1;
    y = (T)7;
    Cpoint<T> p;
    T i,j;
    
    memset(m_penal, 0, HIGH*LENGTH*sizeof(T));

    for(i = 0; i < HIGH; ++i)
    {
        p.printpoint(i, 0, RED);
        p.printpoint(i, LENGTH - 1, RED);
        m_penal[i][0] = YD;
        m_penal[i][0] = YD;
    }

    for(j = 0; j < LENGTH; j++)
    {
        m_penal[0][j] = YD;
        m_penal[HIGH-1][j] = YD;
        p.printpoint(T(0), T(j), YELLOW);
        p.printpoint(T(HIGH-1), T(j), YELLOW);
    }
/*
    for(i = 0; i< 24; ++i)
    {
        for(j = 0; j < 17; ++j)
        {
            cout << m_penal[i][j] << "";
        }
        cout << "(" << i << ")";
        cout << endl;
    }

    for(i = 0; i < 24; ++i)
    {
        for(j = 0; j < 17; ++j)
        {
            if(m_penal[i][j] == YD)
            {
                p.printpoint(i, j, RED);
            }
        }
    }
    */
    fflush(stdout);//
}

template<typename T>
char Game<T>::getshape()
{
    int r;
    char c;
    r = (rand() % 5) + 1;//取[1~5]随机数
    switch(r)
    {
        case 1:
            c = 'Z';
            break;
        case 2:
            c = 'T';
            break;
        case 3:
            c = 'O';
            break;
        case 4:
            c = 'I';
            break;
        case 5:
            c = 'L';
            break;
        default:
            cout << "No this shape" << endl;
            break;
    }
    return c;
}

template<typename T>
bool Game<T>::setpenal()
{
    T i,j;
    T b[3][3] = {0};
    m_graph->getlocate(&x, &y);
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));

    for(i = x; i < x+3; ++i)
    {
        for(j = y; j < y+3; ++j)
        {
            m_penal[i][j] += b[i-x][j-y];
            if(m_penal[i][j] > YD)
            {
                cout << "Game Over" << endl;
                system("stty icanon echo");
                exit(0);
            }
        }
    }
    return true;
}

template <typename T>
void Game<T>::createcube()
{
    m_graph = new Context<T>(getshape());
    m_graph->draw();
    m_graph->setlocate(1,7);
    setpenal();
    m_graph->printg(YELLOW);
}

template <typename T>
bool Game<T>::erasepenal()//擦除当前方块
{
    T i,j;
    T b[3][3] = {0};
    m_graph->printg(CLEAR);
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));
    
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            m_penal[i+x][j+y] -= b[i][j];
        }
    }
    return true;
}

template <typename T>
bool Game<T>::recoverpenal()
{
    T i,j;
    T b[3][3] = {0};
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));
    
    for(i = x; i < x+3; ++i)
    {
        for(j = y; j < y+3; ++j)
        {
            m_penal[i][j] += b[i-x][j-y];
        }
    }
}

template<typename T>
void Game<T>::move(T dir)
{
    erasepenal();
    switch(dir)
    {
        case DOWN:
        if(false == isattachbottom())
        {
            m_graph->move(DOWN);
            setpenal();
            m_graph->printg(YELLOW);
        }
        else
        {
            recoverpenal();
            m_graph->printg(YELLOW);
            erase();
            stop();
        }
        break;

        case LEFT:
        if(false == isattachleft())
        {
            m_graph->move(LEFT);
            setpenal();
            m_graph->printg(YELLOW);
        }
        else
        {
            recoverpenal();
            m_graph->printg(YELLOW);
        }
        break;

        case RIGHT:
        if(false == isattachright())
        {
            m_graph->move(RIGHT);
            setpenal();
            m_graph->printg(YELLOW);
        }
        else
        {
            recoverpenal();
            m_graph->printg(YELLOW);
        }
        break;

        default:
        cout << "ERROR" << endl;
        break;
    }
}

template<typename T>
void Game<T>::roll()
{
    T i,j;
    bool flag = 0;
    T b[3][3] = {0};
    T temp[3][3] = {0};
    m_graph->getlocate(&x, &y);
    /*取出方块值先放于b中*/
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));
    erasepenal();
    
    /*逆时针旋转，调用之前的方法会修改原始数组，此处不要修改原始数组*/
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            temp[2-j][i] = b[i][j];
        }
    }
    /*判断旋转后是否会和面板重合*/
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            if(temp[i][j] == YD && m_penal[x+i][y+j] == YD)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    /*如果没有重合则旋转*/
    if(flag != 1)
    {
        m_graph->roll();
    }
    setpenal();
    m_graph->printg(YELLOW);
}

template<typename T>
void Game<T>::stop()
{
    delete m_graph;
    createcube();
}

template<typename T>
bool Game<T>::isattachbottom()
{
    T i,j;
    T cubx,cuby;
    T b[3][3] = {0};
    bool flag = false;
    m_graph->getlocate(&cubx, &cuby);
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            if(b[i][j] == YD && m_penal[i+cubx+1][j+cuby] == YD)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            break;
        }
    }
    return flag;
}

template<typename T>
bool Game<T>::isattachleft()
{
    T i,j;
    T cubx,cuby;
    T b[3][3] = {0};
    bool flag = false;
    m_graph->getlocate(&cubx, &cuby);
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            if(b[i][j] == YD && m_penal[i+cubx][j+cuby-1] == YD)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            break;
        }
    }
    return flag;
}

template<typename T>
bool Game<T>::isattachright()
{
    T i,j;
    T cubx,cuby;
    T b[3][3] = {0};
    bool flag = false;
    m_graph->getlocate(&cubx, &cuby);
    memcpy(b, m_graph->getarray(), (3*3*sizeof(T)));

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            if(b[i][j] == YD && m_penal[i+cubx][j+cuby+1] == YD)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            break;
        }
    }
    return flag;
}

template<typename T>
void Game<T>::erase()
{
    T i,j;
    bool flag = 0;

    for(i = HIGH-2; i > 0; --i)
    {
        for(j = 0; j < LENGTH-1; ++j)
        {
            /*是否需要擦除该行*/
            if(m_penal[i][j] == ND)
            {
                flag = 1;
            }
        }
        /*擦除i行*/
        if(flag == 0)
        {
            /*i行上的图形全下落*/
            down(i);
            ++i;
        }
        flag = 0;
    }
}

template<typename T>
void Game<T>::down(T l)
{
    T i,j;
    bool flag = 1;

    for(i = l; i > 1; --i)
    {
        for(j = 1; j < LENGTH-1; ++j)
        {
            m_penal[i][j] = m_penal[i-1][j];
        }
    }
    /*刷新面板*/
    Cpoint<T> p;
    
    for(i = 1; i < HIGH-1; ++i)
    {
        for(j = 1; j < LENGTH-1; ++j)
        {
            if(m_penal[i][j] == YD)
            {
                p.printpoint(i, j, YELLOW);
            }
            if(m_penal[i][j] == ND)
            {
                p.printpoint(i, j, CLEAR);
            }
        }
    }
}
