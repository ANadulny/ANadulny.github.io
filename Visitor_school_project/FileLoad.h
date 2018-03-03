#include <cstring>
int FileLoad(vector<Tip*>& tip)
{
    ClearScreen();
    string file_name;
	char w[5];
	char key[5]="abcd";
    cout<<"Please write a file name"<<endl;
    cin>>file_name;
    ifstream wej(file_name, ios::in | ios::binary);
    int size_of_file;
	wej.read((char*)w,sizeof(key));
	if(strcmp(w,key)==0)
        {wej.read((char*)&size_of_file,sizeof(int));
	int which;
	tip.clear();
	SharpTurnLeft p1;
	Rondo p2;
	GoStraightOn p3;
	Tip* pointer;
	for(int i=0;i<size_of_file;i++)
	{
		wej.read((char*)&which,sizeof(int));
		switch (which)
		{
		case 1:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new SharpTurnRight();
			tip.push_back(pointer);
			break;
		case 2:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new SharpTurnLeft();
			tip.push_back(pointer);
			break;
		case 3:
			wej.read((char*)&p3,sizeof(GoStraightOn));
			pointer=new GoStraightOn(p3);
			tip.push_back(pointer);
			delete pointer;
			break;
		case 4:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new TurnLeft();
			tip.push_back(pointer);
			break;
		case 5:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new TurnRight();
			tip.push_back(pointer);
			break;
		case 6:
			wej.read((char*)&p2,sizeof(Rondo));
			pointer=new Rondo(p2);
			tip.push_back(pointer);
			break;
		case 7:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new CrossroadsGoStraightOn();
			tip.push_back(pointer);
			break;
		case 8:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new CrossroadsTurnRight();
			tip.push_back(pointer);
			break;
		case 9:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new CrossroadsTurnLeft();
			tip.push_back(pointer);	
			break;
		case 10:
			wej.read((char*)&p1,sizeof(Tip));
			pointer=new TurnBack();
			tip.push_back(pointer);
			break;
		default:
			break;
		}
	}
	wej.clear();
    wej.close();
	}
	return 0;
}

