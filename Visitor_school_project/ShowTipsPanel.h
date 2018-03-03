#include "ShowPanel.h"

void ShowTipsPanel(vector<Tip*>&tip)
{
    int a, go_forward;
    int number = 0;
	Tip* pom;
	vector<Tip*>::iterator it;
    while(1)
    {
        if(tip.size() != 0)
        {
            do
            {
                ClearScreen();
                ShowTipsList(tip);
                cout<<"Where do you want to add a new tip?"<<endl;
                cout<<"Choose a number from 1 to "<< tip.size() + 1 <<endl;
                cin >> number;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            while(cin.fail() || number <= 0 || number > tip.size() + 1);
        }

        int i=0;
        for(it=tip.begin() ; it < tip.end(); it++,i++ )
        {
            if(i == number-1) break;
        }

        do
        {
            ClearScreen();
            ShowTips();
            cin >> a;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        while(cin.fail() || a <= 0 || a > 11);

        switch(a)
        {
        case 1:
            cout<<"The sharp turn right"<<endl;
			pom=new SharpTurnRight();
			tip.insert(it, pom);
            return;
        case 2:
            cout<<"The sharp turn left"<<endl;
            pom=new SharpTurnLeft();
			tip.insert(it, pom);
            return;
        case 3:
            cout<<"Go straight on"<<endl;
            go_forward=GoForward();
            if(go_forward == -1) return;
            pom=new GoStraightOn(go_forward);
			tip.insert(it, pom);
            return;
        case 4:
            cout<<"Turn left"<<endl;
            pom=new TurnLeft();
			tip.insert(it, pom);
            return;
        case 5:
            cout<<"Turn right"<<endl;
            pom=new TurnRight();
			tip.insert(it, pom);
            return;
        case 6:
            cout<<"Rondo"<<endl;
            pom=new Rondo(Rondo_exit() );
			tip.insert(it, pom);
            return;
        case 7:
            cout<<"At the crossroads go straight on"<<endl;
            pom=new CrossroadsGoStraightOn();
			tip.insert(it, pom);
            return;
        case 8:
            cout<<"At the crossroads turn right"<<endl;
            pom=new CrossroadsTurnRight();
			tip.insert(it, pom);
            return;
        case 9:
            cout<<"At the crossroads turn left"<<endl;
            pom=new CrossroadsTurnLeft();
			tip.insert(it, pom);
            return;
        case 10:
            cout<<"Turn back"<<endl;
            pom=new TurnBack();
			tip.insert(it, pom);
            return;
        case 11:
            cout<<"Go back to interface"<<endl;
            return;
        }
    }
}

