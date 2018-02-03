#ifndef __MYWRAPPER_H
#define __MYWRAPPER_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Menu Menu;

Menu* newMenu();
void Menu_MenuInit(Menu *v);
void Menu_setSocket(Menu *v,int i);
int Menu_getLoginChoice(Menu *v);
char* Menu_getUsername(Menu *v);
#ifdef __cplusplus
}
#endif
#endif
