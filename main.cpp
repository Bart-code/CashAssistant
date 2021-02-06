#include <iostream>
#include "CashAssistant.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

int main()
{
    CashAssistant cashAssistant;
    int userChoiceOption;
    while( true )
    {
        cashAssistant.showUserMenu();
        cout << "Your choice: ";
        cin >> userChoiceOption ;
        switch( userChoiceOption )
        {
            case 1:
                {
                    cashAssistant.logIn();
                    cashAssistant.incomesExpencesManagersInit();
                    int userLoggedChoiceOption;
                    while( cashAssistant.isUserLogged())
                    {
                        cashAssistant.showLoggedUserMenu();
                        cin >> userLoggedChoiceOption;
                        switch( userLoggedChoiceOption )
                        {
                        case 1:
                            cashAssistant.addIncome();
                                break;
                        case 2:
                            cashAssistant.addExpense();
                                break;
                        case 3:
                            cashAssistant.balanceSheetForCurrentMonth();
                                break;
                        case 4:
                            cashAssistant.balanceSheetForPreviousMonth();
                                break;
                        case 5:
                            cashAssistant.balanceSheetForCustomPeriod();
                                break;
                        case 6:
                            cashAssistant.changePassword();
                                break;
                        case 7:
                                cashAssistant.logout();
                                break;
                        case 8:
                                cashAssistant.showAllLoadedIncomes();
                                break;
                        default:
                            cout << "Your choice is not menu option" << endl;
                            system("pause");
                            break;
                        }
                    }
                    break;
                }

            case 2:
                    cashAssistant.registration();
                    break;
            case 3:
                    cashAssistant.showAllUsers();
                    system("pause");
                    break;
            case 9:
                    exit(0);
                    break;
            default:
                    cout << "Your choice is not menu option" << endl;
                    system("pause");
                    break;
        }
    }

    return 0;
}
