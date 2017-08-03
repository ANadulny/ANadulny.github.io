//****************//jechanie prosto

int GoForwardPanel()
{
    int a;
    do
    {
        ClearScreen();
        cout<<"Do you want to:"<<endl;
        cout<<"[1]Give distance in km"<<endl;
        cout<<"[2]Skip the road distance in km"<<endl;
        cout<<"[3]Go back to interface"<<endl;
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    while(cin.fail() || a <= 0 || a > 3);

    return a;
}

int GoForwardGiveDistance()
{
    int a;
    int b=0;
    do
    {
        ClearScreen();
        if(b>500) cout<<"Are you kidding?\nGive a sensible number.\n"<<endl;
        cout<<"Give distance in km"<<endl;
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        b=a;
    }
    while(cin.fail() || a <= 0 || a > 500);

    return a;
}

int GoForward()
{
    int a = GoForwardPanel();

    if(a == 1) return GoForwardGiveDistance();

    else if(a == 2) return 0;
    else return -1;
}
