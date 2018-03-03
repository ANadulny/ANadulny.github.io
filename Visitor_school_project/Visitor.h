class AbstractVisitor;	// Forward declare AbstractVisitor
using namespace std;
class Tip {
public:
	// This function accepts an object of any class derived from AbstractVisitor and must be implemented in all derived classes
	virtual void accept(AbstractVisitor &dispatcher) = 0;
	virtual void save(ofstream& out) = 0;
	virtual ~Tip(){};
};

class SharpTurnRight;
class SharpTurnLeft;
class GoStraightOn; //zmodyfikowac i zastanowic sie nad tym np prosto na skrzyzowaniu pierwszy zjazd; zrob f prosto i do niej dodaj np 2 warianty;
class TurnLeft;
class TurnRight;

class Rondo;

class CrossroadsGoStraightOn;
class CrossroadsTurnRight;
class CrossroadsTurnLeft;

class TurnBack;


class AbstractVisitor {	 // Declares the interface for the dispatcher
public:
	// Declare overloads for each kind of a tip to dispatch
	virtual void dispatch(SharpTurnRight &tip) = 0;
	virtual void dispatch(SharpTurnLeft &tip) = 0;
	virtual void dispatch(GoStraightOn &tip) = 0;
    virtual void dispatch(TurnLeft &tip) = 0;
	virtual void dispatch(TurnRight &tip) = 0;

    virtual void dispatch(Rondo &tip) = 0;

	virtual void dispatch(CrossroadsGoStraightOn &tip) = 0;
	virtual void dispatch(CrossroadsTurnRight &tip) = 0;
	virtual void dispatch(CrossroadsTurnLeft &tip) = 0;

	virtual void dispatch(TurnBack &tip) = 0;

};

