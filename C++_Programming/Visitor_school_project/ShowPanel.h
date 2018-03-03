using namespace std;
int Rondo_exit();
int GoForward();

void ClearScreen()
{
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

void ShowPanel()
{
    cout<<"The following options are available."<<endl;
    cout<<"[1] Add a new tip"<<endl;
    cout<<"[2] Remove the tip"<<endl;
    cout<<"[3] Save the road binary to the file"<<endl;
    cout<<"[4] Load the binary code of road from a file"<<endl;
    cout<<"[5] The number of turn left"<<endl;
    cout<<"[6] The end of program work"<<endl;
}

void ShowTips()
{
    cout<<"Please select the driving direction."<<endl;
    cout<<"[1]  The sharp turn right"<<endl;
    cout<<"[2]  The sharp turn left"<<endl;
    cout<<"[3]  Go straight on"<<endl;
    cout<<"[4]  Turn left"<<endl;
    cout<<"[5]  Turn right"<<endl;
    cout<<"[6]  Rondo"<<endl;
    cout<<"[7]  At the crossroads go straight on"<<endl;
    cout<<"[8]  At the crossroads turn right"<<endl;
    cout<<"[9]  At the crossroads turn left"<<endl;
    cout<<"[10] Turn back"<<endl;
    cout<<"[11] Go back to main panel"<<endl;
}

void ShowTipsList(vector<Tip*> &tipss)
{
    if(tipss.size()==0) return;

    cout<<"Current road:"<<endl;
    Dispatcher dispatcher;
    int i=1;
	for (Tip* tip : tipss) {
        cout<<i++<<")";
        tip->accept(dispatcher);
	}
	cout<<endl;
}

void clear(vector<Tip*> &tipss)
{
    if(tipss.size()==0) return;
    Dispatcher dispatcher;
    int i=1;
	for (Tip* tip : tipss) {
        tip->accept(dispatcher);
        delete tip;
	}
}
