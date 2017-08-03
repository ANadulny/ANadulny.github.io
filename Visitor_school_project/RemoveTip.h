//*******************//usuwanie elementow
void RemoveTip(vector<Tip*>& tip)
{
    int number;

    if(tip.size() == 0)
    {
        do
        {
            ClearScreen();
            cout<<"There are no tips to remove"<<endl;
            cout<<"[1]Go back to interface"<<endl;
            cin >> number;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        while(cin.fail() || number != 1);
        return;
    }

    if(tip.size() == 1)
    {
        tip.pop_back();
        return;
    }

    do
    {
        ClearScreen();
        ShowTipsList(tip);
        cout<<"What do you choose?"<<endl;
        cout<<"[1]Remove one tip"<<endl;
        cout<<"[2]Remove all tips"<<endl;
        cout<<"[3]Go back to interface"<<endl;
        cin >> number;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    while(cin.fail() || number <= 0 || number > 3);

    if(number==1)
    {
        unsigned a;
        do
        {
            ClearScreen();
            ShowTipsList(tip);
            cout<<"Which number do you want to remove?"<<endl;
            cout<<"Choose a number from 1 to "<< tip.size() <<endl;
            cin >> a;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        while(cin.fail() || a <= 0 || a > tip.size());
        tip.erase (tip.begin() + a - 1);
    }

    if(number==2)  clear(tip);
    return;
}
