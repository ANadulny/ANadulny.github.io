#include "Visitor.h"
#include<fstream>
using namespace std;
class SharpTurnRight: public Tip {	 // Specific element class #1
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=1;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(SharpTurnRight));
	}
};

class SharpTurnLeft: public Tip {	 // Specific element class #2
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=2;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(SharpTurnLeft));
	}
};

class GoStraightOn: public Tip {	 // Specific element class #3
private:
    int number;
public:
    int GetNumber() const{return number;};

    GoStraightOn(int n=0):number(n){}
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=3;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(GoStraightOn));
	}
};

class TurnLeft: public Tip {	 // Specific element class #4
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=4;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(TurnLeft));
	}
};

class TurnRight: public Tip {	 // Specific element class #5
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=5;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(TurnRight));
	}
};

class Rondo: public Tip {         // Specific element class #6
private:
    int number;
public:
    int GetNumber() const{return number;};

    Rondo(int n=1):number(n){}

    void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=6;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(Rondo));
	}
};

class CrossroadsGoStraightOn: public Tip {	 // Specific element class #7
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=7;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(CrossroadsGoStraightOn));
	}
};

class CrossroadsTurnRight: public Tip {	 // Specific element class #8
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=8;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(CrossroadsTurnRight));
	}
};

class CrossroadsTurnLeft: public Tip {	 // Specific element class #9
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=9;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(CrossroadsTurnLeft));
	}
};

class TurnBack: public Tip {	 // Specific element class #10
public:
	void accept(AbstractVisitor &dispatcher) override {
		dispatcher.dispatch(*this);
	}
	void save(ofstream& out)
	{
		int a=10;
		out.write((char*)&a,sizeof(int));
		out.write((char*)&(*this),sizeof(TurnBack));
	}
};
