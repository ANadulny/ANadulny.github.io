#include <iostream>
#include "Tips_class.h"

class Dispatcher: public AbstractVisitor {	// Implements dispatching of all kind of elements (tip)
    std::ostream &out;

public:

    Dispatcher() : out( std::cout ){};
    Dispatcher(std::ostream &out): out(out) {};

	void dispatch(SharpTurnRight &tip) override {
		out << "The sharp turn right\n";//zamienic na stream
	}

	void dispatch(SharpTurnLeft &tip) override {
		out << "The sharp turn left\n";
	}

	void dispatch(GoStraightOn &tip) override {
        if(tip.GetNumber()==0)
            out << "Go straight on\n";
        else
            out << "Go straight on "<<tip.GetNumber()<<"km\n";
	}

	void dispatch(TurnLeft &tip) override {
		out << "Turn left\n";
	}

	void dispatch(TurnRight &tip) override {
		out << "Turn right\n";
	}

    void dispatch(Rondo &tip) override {
		out << "At the roundabout, take "<<tip.GetNumber()<<". exit\n";
	}

	void dispatch(CrossroadsGoStraightOn &tip) override {
		out << "At the crossroads go straight on\n";
	}

	void dispatch(CrossroadsTurnRight &tip) override {
		out << "At the crossroads turn right\n";
	}

	void dispatch(CrossroadsTurnLeft &tip) override {
		out << "At the crossroads turn left\n";
	}

	void dispatch(TurnBack &tip) override {
		out << "Turn back\n";
	}

};
