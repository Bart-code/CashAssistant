#include <iostream>
#include "CashAssistant.h"

using namespace std;

int main()
{
    CashAssistant cashAssistant;
    int userChoseOption = 0;

    cashAssistant.showUserMenu();
    cashAssistant.showAllUsers();
    //cashAssistant.registration();
    cashAssistant.logIn();


    return 0;
}
