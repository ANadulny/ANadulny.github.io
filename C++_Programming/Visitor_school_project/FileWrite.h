#include <fstream>
#include <string>


int FileWrite(vector<Tip*>& tip)
{
    ClearScreen();
    string file_name;
	char key[5]="abcd";
    cout<<"Please write a file name"<<endl;
    cin>>file_name;
    ofstream wy(file_name, ios::out | ios::binary);
	int size_of_file=tip.size();
	wy.write((char*)key,sizeof(key));
	wy.write((char*)&size_of_file,sizeof(int));
	for(auto it=tip.begin();it!=tip.end();++it)
	{
		(*it)->save(wy);
	}
    wy.close();
    return 0;
}
