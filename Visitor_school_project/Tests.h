int TestSharpTurnRight();
int TestSharpTurnLeft();
int TestGoStraightOn();
int TestTurnLeft();
int TestTurnRight();
int TestRondo();
int TestCrossroadsGoStraightOn();
int TestCrossroadsTurnRight();
int TestCrossroadsTurnLeft();
int TestTurnBack();
int TestRondoExitFirst();
int TestRondoExitFourth();
int TestGoStraightOnFourKm();
int TestGoStraightOnTwentyKm();
int TestGoStraightOnKm();
int TestNumberOfTurnLeft();
int TestNumberOfTurnLeftWithZero();
int TestRemoveOne();
int TestRemoveAll();


int Test()
{
    cout<<"VisitorTests\n\n";

    if(TestSharpTurnRight()) cout<<"1. Test passed\n\n";
    else cout<<"1. Test failed\n\n";

    if(TestSharpTurnLeft()) cout<<"2. Test passed\n\n";
    else cout<<"2. Test failed\n\n";

    if(TestGoStraightOn()) cout<<"3. Test passed\n\n";
    else cout<<"3. Test failed\n\n";

    if(TestTurnLeft()) cout<<"4. Test passed\n\n";
    else cout<<"4. Test failed\n\n";

    if(TestTurnRight()) cout<<"5. Test passed\n\n";
    else cout<<"5. Test failed\n\n";

    if(TestRondo()) cout<<"6. Test passed\n\n";
    else cout<<"6. Test failed\n\n";

    if(TestCrossroadsGoStraightOn()) cout<<"7. Test passed\n\n";
    else cout<<"7. Test failed\n\n";

    if(TestCrossroadsTurnRight()) cout<<"8. Test passed\n\n";
    else cout<<"8. Test failed\n\n";

    if(TestCrossroadsTurnLeft()) cout<<"9. Test passed\n\n";
    else cout<<"9. Test failed\n\n";

    if(TestTurnBack()) cout<<"10. Test passed\n\n";
    else cout<<"10. Test failed\n\n";

    if(TestRondoExitFirst()) cout<<"11. Test passed\n\n";
    else cout<<"11. Test failed\n\n";

    if(TestRondoExitFourth()) cout<<"12. Test passed\n\n";
    else cout<<"12. Test failed\n\n";

    if(TestGoStraightOnFourKm()) cout<<"13. Test passed\n\n";
    else cout<<"13. Test failed\n\n";

    if(TestGoStraightOnTwentyKm()) cout<<"14. Test passed\n\n";
    else cout<<"14. Test failed\n\n";

    if(TestGoStraightOnKm()) cout<<"15. Test passed\n\n";
    else cout<<"15. Test failed\n\n";

    if(TestNumberOfTurnLeft()) cout<<"16. Test passed\n\n";
    else cout<<"16. Test failed\n\n";

    if(TestNumberOfTurnLeftWithZero()) cout<<"17. Test passed\n\n";
    else cout<<"17. Test failed\n\n";

    if(TestRemoveOne()) cout<<"18. Test passed\n\n";
    else cout<<"18. Test failed\n\n";

    if(TestRemoveAll()) cout<<"19. Test passed\n\n";
    else cout<<"19. Test failed\n\n";

    return 0;
}

int TestSharpTurnRight()
{
    cout<<"SharpTurnRight\n";
    SharpTurnRight sharp_turn_right;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_right);
    if( typeid(SharpTurnRight) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestSharpTurnLeft()
{
    cout<<"SharpTurnLeft\n";
    SharpTurnLeft sharp_turn_left;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_left);
    if( typeid(SharpTurnLeft) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestGoStraightOn()
{
    cout<<"GoStraightOn\n";
    GoStraightOn go_straight_on;
    std::vector<Tip*> tips;
    tips.push_back(&go_straight_on);
    if( typeid(GoStraightOn) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestTurnLeft()
{
    cout<<"TurnLeft\n";
    TurnLeft turn_left;
    std::vector<Tip*> tips;
    tips.push_back(&turn_left);
    if( typeid(TurnLeft) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestTurnRight()
{
    cout<<"TurnRight\n";
    TurnRight turn_right;
    std::vector<Tip*> tips;
    tips.push_back(&turn_right);
    if( typeid(TurnRight) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestRondo()
{
    cout<<"Rondo\n";
    Rondo rondo;
    std::vector<Tip*> tips;
    tips.push_back(&rondo);
    if( typeid(Rondo) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestCrossroadsGoStraightOn()
{
    cout<<"CrossroadsGoStraightOn\n";
    CrossroadsGoStraightOn crossroads_go_straight_on;
    std::vector<Tip*> tips;
    tips.push_back(&crossroads_go_straight_on);
    if( typeid(CrossroadsGoStraightOn) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestCrossroadsTurnRight()
{
    cout<<"CrossroadsTurnRight\n";
    CrossroadsTurnRight crossroads_turn_right;
    std::vector<Tip*> tips;
    tips.push_back(&crossroads_turn_right);
    if( typeid(CrossroadsTurnRight) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestCrossroadsTurnLeft()
{
    cout<<"CrossroadsTurnLeft\n";
    CrossroadsTurnLeft crossroads_turn_left;
    std::vector<Tip*> tips;
    tips.push_back(&crossroads_turn_left);
    if( typeid(CrossroadsTurnLeft) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestTurnBack()
{
    cout<<"TurnBack\n";
    TurnBack turn_back;
    std::vector<Tip*> tips;
    tips.push_back(&turn_back);
    if( typeid(TurnBack) == typeid(*tips[0]) ) return 1;
    else return 0;
}

int TestRondoExitFirst()
{
    cout<<"RondoExitFirst\n";
    Rondo rondo(2);
    if( rondo.GetNumber() == 2 ) return 1;
    else return 0;
}

int TestRondoExitFourth()
{
    cout<<"RondoExitFourth\n";
    Rondo rondo(4);
    if( rondo.GetNumber() == 4 ) return 1;
    else return 0;
}

int TestGoStraightOnFourKm()
{
    cout<<"GoStraightOnFourKm\n";
    GoStraightOn go_straight_on4(4);
    if( go_straight_on4.GetNumber() == 4 ) return 1;
    else return 0;
}

int TestGoStraightOnTwentyKm()
{
    cout<<"GoStraightOnTwentyKm\n";
    GoStraightOn go_straight_on20(20);
    if( go_straight_on20.GetNumber() == 20 ) return 1;
    else return 0;
}

int TestGoStraightOnKm()
{
    cout<<"GoStraightOnKm\n";
    GoStraightOn go_straight_on(0);
    if( go_straight_on.GetNumber() == 0 ) return 1;
    else return 0;
}

int TestNumberOfTurnLeft()
{
    cout<<"NumberOfTurnLeft\n";
    int number = 0;
    SharpTurnRight sharp_turn_right;
    SharpTurnLeft sharp_turn_left;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_right);
    tips.push_back(&sharp_turn_left);
    tips.push_back(&sharp_turn_left);
    for(int i=0; i<tips.size(); i++)
    {
            if( typeid(SharpTurnLeft) == typeid(*tips[i]) ) number++;
            else if( typeid(TurnLeft) == typeid(*tips[i]) ) number++;
            else if( typeid(CrossroadsTurnLeft) == typeid(*tips[i]) ) number++;
    }
    if( number == 2 ) return 1;
    else return 0;
}

int TestNumberOfTurnLeftWithZero()
{
    cout<<"NumberOfTurnLeftWithZero\n";
    int number = 0;
    SharpTurnRight sharp_turn_right;
    Rondo rondo;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_right);
    tips.push_back(&rondo);
    tips.push_back(&sharp_turn_right);
    for(int i=0; i<tips.size(); i++)
    {
            if( typeid(SharpTurnLeft) == typeid(*tips[i]) ) number++;
            else if( typeid(TurnLeft) == typeid(*tips[i]) ) number++;
            else if( typeid(CrossroadsTurnLeft) == typeid(*tips[i]) ) number++;
    }
    if( number == 0 ) return 1;
    else return 0;
}

int TestRemoveOne()
{
    cout<<"RemoveOne\n";
    SharpTurnRight sharp_turn_right;
    Rondo rondo;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_right);
    tips.push_back(&rondo);
    tips.push_back(&sharp_turn_right);
    tips.push_back(&rondo);
    tips.erase (tips.begin() + 2 );
    if( typeid(Rondo) == typeid(*tips[2]) ) return 1;
    else return 0;
}

int TestRemoveAll()
{
    cout<<"RemoveAll\n";
    SharpTurnRight sharp_turn_right;
    SharpTurnLeft sharp_turn_left;
    Rondo rondo;
    std::vector<Tip*> tips;
    tips.push_back(&sharp_turn_right);
    tips.push_back(&rondo);
    tips.push_back(&sharp_turn_right);
    tips.push_back(&rondo);
    tips.clear();
    tips.push_back(&sharp_turn_left);
    if( typeid(SharpTurnLeft) == typeid(*tips[0]) ) return 1;
    else return 0;
}

