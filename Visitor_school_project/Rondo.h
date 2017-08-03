int Rondo_exit()
{
    int a;
    do
    {
        ClearScreen();
        cout<<"Which exit from rondo do you want to choose?"<<endl;
        cout<<"Choose the number from 1 to 8."<<endl;
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    while(cin.fail() || a <= 0 || a > 8);

    return a;
}
