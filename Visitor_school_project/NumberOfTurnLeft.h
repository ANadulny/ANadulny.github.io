void NumberOfTurnLeft(vector<Tip*>& tipss)
{
    int number = 0;
    int a;
	cout<<endl;

    for(int i=0; i<tipss.size(); i++)
    {
            if( typeid(SharpTurnLeft) == typeid(*tipss[i]) ) number++;
            else if( typeid(TurnLeft) == typeid(*tipss[i]) ) number++;
            else if( typeid(CrossroadsTurnLeft) == typeid(*tipss[i]) ) number++;
    }
    do
    {
        ClearScreen();
        cout<<"The number of turn left: "<<number<<endl;
        cout<<"[1]Go back to interface"<<endl;
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    while(cin.fail() || a != 1);
    return;
}
