#include "menu.hpp"
#include "MyWrapper.hpp"
#include <iostream>
extern "C" {
        Menu* newMenu() {
                return new Menu();
        }

        void Menu_MenuInit(Menu *v)
        {
                v->menuInit();
        }
        void Menu_setSocket(Menu *v,int i)
        {
                v->setSocket(i);
        }
}
