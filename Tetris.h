/*************************************************************************
	> File Name: Tetris.h
	> Author: LiZhong
	> Mail: 
	> Created Time: Thu 02 Mar 2017 10:57:17 PM PST
 ************************************************************************/

#ifndef _TETRIS_H
#define _TETRIS_H

#include<stdio.h>
#include<stdlib.h>

#define LENGTH (17)
#define HIGH (24)

namespace TBlock{
    enum COLOR{
        CLEAR = 0,
        BLACK = 30,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        PURPLE,
        DEEP_GREEN,
        WHITE
    };
    enum DRAW{
        ND = 0,
        YD = 1,
        CD,
    };
    enum MOVE{
        DOWN,
        LEFT,
        RIGHT,
    };

    /*声明光标移动类*/
    template<typename T> class Cursor{
        public:
            void save();
            void move(T x, T y);
            void res();
    };
    
    /*声明打印点类，继承于光标移动*/
    template<typename T> class Cpoint : public Cursor<T>{
        private:
            T color;
            T x;
            T y;            
            void setlocate(const T i, const T j){x = i; y = j;}
            void setcolor(const T c){color = c;}
        public:
            Cpoint(){color = CLEAR; x = 0; y = 0;}
            Cpoint(const T i, const T j, const T c)
            {
                x = i;
                y = j;
                color = c;
            }
            
            T getcolor(){return color;}
            void getlocate(T &i, T &j){i = x; j = y;};

            void printpoint();
            void printpoint(const T i, const T j, const T c);
    };

    template<typename T>
    class Gbase
    {
        protected:
            T x;
            T y;
            T arr[3][3];
        public:
            Gbase();
            T move(T dir);

            virtual T roll();
            virtual void draw();

            void setlocate(const T &a, const T &b){x = a;y = b;}
            void getlocate(T *a, T *b){*a = x;*b = y;}
            void printg(const T color);
            void *getarray(){return (void *)arr;}
    };

    template<typename T>
    class Zgraph : public Gbase<T>
    {
        public:
            void draw();
    };

    template<typename T>
    class Tgraph : public Gbase<T>
    {
        public:
            void draw();
    };

    template<typename T>
    class Ograph : public Gbase<T>
    {
        public:
            void draw();
            virtual T roll(){};///////////////////
    };

    template<typename T>
    class Igraph : public Gbase<T>
    {
        public:
            void draw();
    };

    template<typename T>
    class Lgraph : public Gbase<T>
    {
        public:
            void draw();
    };

    template<typename T>
    class Context
    {
        private:
            Gbase<T> *gbase;
        public:
            ~Context(){delete gbase;}
            Context(char ty);
            T move(T dir){return gbase->move(dir);}
            T roll(){return gbase->roll();}
            void draw(){gbase->draw();}
            void setlocate(T a, T b){gbase->setlocate(a, b);}
            void getlocate(T *a, T*b){gbase->getlocate(a, b);}
            void *getarray(){return gbase->getarray();}
            void printg(T color){gbase->printg(color);}
    };

    /**/
    template<typename T>
    class Game
    {
        private:
            T m_penal[HIGH][LENGTH];
            Context<T> *m_graph;
            T x;
            T y;
        
            bool recoverpenal();
            bool isattachbottom();
            bool isattachleft();
            bool isattachright();
            char getshape();//随机获得方块
            bool setpenal();
            bool erasepenal();

        public:
            Game();
            void createcube();
            void move(T dir);
            void roll();
            void stop();
            void erase();
            void down(T level);
    };
}







#endif
