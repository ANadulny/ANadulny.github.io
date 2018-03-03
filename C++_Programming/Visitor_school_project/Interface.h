#include <limits>
#include <typeinfo>
#include <vector>
#include "ShowTipsPanel.h"
#include "Rondo.h"
#include "GoForward.h"
#include "RemoveTip.h"
#include "NumberOfTurnLeft.h"
#include "FileWrite.h"
#include "FileLoad.h"

void ShowPanel();
void ShowTips();
void ShowTipsPanel(vector<Tip*>& tip);
void ShowTipsList(vector<Tip*>& tip);
int Rondo_exit();
//*****************
int GoForwardPanel();
int GoForward();
int GoForwardGiveDistance();
//*****************
void RemoveTip(vector<Tip*>& tip);
//*****************
void NumberOfTurnLeft(vector<Tip*>& tipss);

vector<Tip*> Interface()
{
    std::vector<Tip*> tips;
    int a;
    while(1)
    {
        do
        {
            ClearScreen();
            ShowTipsList(tips);
            ShowPanel();
            cin >> a;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        while(cin.fail());

        switch(a)
        {
        case 1:
            ShowTipsPanel(tips); //add new tips
            break;
        case 2:
            RemoveTip(tips); //remove a tip
            break;
        case 3:
            cout<<"Save the road binary to the file"<<endl;
            FileWrite(tips);
            break;
        case 4:
            cout<<"Load the binary code of road  from the file"<<endl;
			FileLoad(tips);
            break;
        case 5:
            NumberOfTurnLeft(tips);
            break;
        case 6:
            ClearScreen();
            cout<<"The end of program work"<<endl;
            clear(tips);
            return tips;
        }
    }
}
