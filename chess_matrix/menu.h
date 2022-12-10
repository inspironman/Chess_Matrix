#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "cm1.h"

class Menu
{
    public:
        Menu(){};
        void run();
    private:
         void menuWrite();
         void get();
         void set();
         void read();
         void write();
         void sum();
         void mul();

         cm1 a;
};

#endif // MENU_H_INCLUDED
