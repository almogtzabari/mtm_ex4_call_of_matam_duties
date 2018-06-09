#include <iostream>
#include "Game.h"
#include "cassert"
#include <fstream>
using std::ofstream;
using std::cout;
using std::endl;

Game InputTest() {
    cout << "cheak input Test" << endl;
    Game game(6);
    (game.addPlayer("itai", "lazer gun", LEVEL, 5) == SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.addPlayer("sean", "light saver", LIFE, 6) == SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.addPlayer("liad", "pirate sword", STRENGTH, 7) == SUCCESS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
    (game.addPlayer("ari", "lazer gun", LEVEL, 5) == SUCCESS)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    (game.addPlayer("sean", "TNT", LEVEL, 5) == NAME_ALREADY_EXISTS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;
    (game.addPlayer("ari", "TNT", LEVEL, 5) == NAME_ALREADY_EXISTS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.addPlayer("yuval", "ATOM", LEVEL, 10) == SUCCESS)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    (game.addPlayer("yuval", "ATOM", LEVEL, 10) == NAME_ALREADY_EXISTS)?cout<<"pass test 8"<<endl:cout<<"failed test 8"<<endl;
    (game.addPlayer("seana", "ATOM", LIFE, 10) == SUCCESS)?cout<<"pass test 9"<<endl:cout<<"failed test 9"<<endl;
    (game.addPlayer("orr", "ATOM", LIFE, 100) == GAME_FULL)?cout<<"pass test 10"<<endl:cout<<"failed test 10"<<endl;
    (game.addPlayer("sean", "ATOM", LIFE, 100) == GAME_FULL)?cout<<"pass test 11"<<endl:cout<<"failed test 11"<<endl;
    return game;
}

void nextLevelTest(Game &game) {
    cout << "cheak nextLevelTest" << endl;
    (game.nextLevel("ari")==SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.nextLevel("itai")==SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.nextLevel("itai")==SUCCESS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
    (game.nextLevel("liad")==SUCCESS)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    (game.nextLevel("yuval")==SUCCESS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;
    (game.nextLevel("liad")==SUCCESS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.nextLevel("orr")==NAME_DOES_NOT_EXIST)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    (game.nextLevel("sean")==SUCCESS)?cout<<"pass test 8"<<endl:cout<<"failed test 8"<<endl;
    (game.nextLevel("seana")==SUCCESS)?cout<<"pass test 9"<<endl:cout<<"failed test 9"<<endl;
    (game.nextLevel("Yuval")==NAME_DOES_NOT_EXIST)?cout<<"pass test 10"<<endl:cout<<"failed test 11"<<endl;
}
void makeStepTest(Game &game) {
    cout << "cheak makeStep" << endl;
    (game.makeStep("ari")==SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.makeStep("itai")==SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.makeStep("itai")==SUCCESS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
    (game.makeStep("liad")==SUCCESS)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    (game.makeStep("yuval")==SUCCESS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;
    (game.makeStep("liad")==SUCCESS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.makeStep("orr")==NAME_DOES_NOT_EXIST)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    (game.makeStep("sean")==SUCCESS)?cout<<"pass test 8"<<endl:cout<<"failed test 8"<<endl;
    (game.makeStep("seana")==SUCCESS)?cout<<"pass test 9"<<endl:cout<<"failed test 9"<<endl;
    (game.makeStep("Yuval")==NAME_DOES_NOT_EXIST)?cout<<"pass test 10"<<endl:cout<<"failed test 10"<<endl;
}
void addLife(Game &game) {
    cout << "cheak addLife" << endl;
    (game.addLife("ari")==SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.addLife("itai")==SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.addLife("itai")==SUCCESS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
    (game.addLife("liad")==SUCCESS)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    (game.addLife("yuval")==SUCCESS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;
    (game.addLife("liad")==SUCCESS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.addLife("orr")==NAME_DOES_NOT_EXIST)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    (game.addLife("sean")==SUCCESS)?cout<<"pass test 8"<<endl:cout<<"failed test 8"<<endl;
    (game.addLife("seana")==SUCCESS)?cout<<"pass test 9"<<endl:cout<<"failed test 9"<<endl;
    (game.addLife("Yuval")==NAME_DOES_NOT_EXIST)?cout<<"pass test 10"<<endl:cout<<"failed test 10"<<endl;
}

void addStrength(Game &game){
    cout << "cheak addStrength " << endl;
    (game.addStrength("ari",1)==SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.addStrength("itai",1)==SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.addStrength("itai",2)==SUCCESS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
    (game.addStrength("liad",-5)==INVALID_PARAM)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    (game.addStrength("yuval",0)==SUCCESS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;
    (game.addStrength("liad",1)==SUCCESS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.addStrength("orr",10)==NAME_DOES_NOT_EXIST)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    (game.addStrength("sean",2)==SUCCESS)?cout<<"pass test 8"<<endl:cout<<"failed test 8"<<endl;
    (game.addStrength("seana",2)==SUCCESS)?cout<<"pass test 9"<<endl:cout<<"failed test 9"<<endl;
    (game.addStrength("Yuval",3)==NAME_DOES_NOT_EXIST)?cout<<"pass test 10"<<endl:cout<<"failed test 10"<<endl;
}

void remove(Game &game,int num){
    cout << "cheak remove " << endl;
    (!game.removeAllPlayersWithWeakWeapon(0))?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;

    (!game.removeAllPlayersWithWeakWeapon(5))?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;

    (game.removeAllPlayersWithWeakWeapon(15))?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;

}
void inputTest2(Game &game){
    cout << "cheak input after remove " << endl;
    (game.addPlayer("tomer", "ak47", LIFE, 10) == SUCCESS)?cout<<"pass test 1"<<endl:cout<<"failed test 1"<<endl;
    (game.addPlayer("sagiv", "m16", LEVEL, 10) == SUCCESS)?cout<<"pass test 2"<<endl:cout<<"failed test 2"<<endl;
    (game.addPlayer("sean", "m16", LEVEL, 10) == NAME_ALREADY_EXISTS)?cout<<"pass test 3"<<endl:cout<<"failed test 3"<<endl;
}
void firstFight(Game &game) {

    cout << "cheak fight " << endl;
    (game.fight("tomer", "sean") == FIGHT_FAILED) ? cout << "pass test 1"
                                                         << endl : cout
            << "failed test 1" << endl;
    (game.fight("tomer", "ari") == NAME_DOES_NOT_EXIST) ? cout << "pass test 2"
                                                               << endl : cout
            << "failed test 2" << endl;
    (game.fight("sagiv", "tomer") == SUCCESS) ? cout << "pass test 3" << endl :
    cout << "failed test 3" << endl;
}
void secondFight(Game &game){
    GameStatus status;
    status=game.makeStep("tomer");
    assert(status==SUCCESS);
    (game.fight("tomer","seana")==FIGHT_FAILED)?cout<<"pass test 4"<<endl:cout<<"failed test 4"<<endl;
    for (int i = 0; i <15; i++) {
        status=game.addLife("sean");
        assert(status==SUCCESS);
    }
    (game.fight("tomer","sean")==SUCCESS)?cout<<"pass test 5"<<endl:cout<<"failed test 5"<<endl;

}
void Test(){
    ofstream outputFile("TestOutPut");

    Game game=InputTest();
    outputFile<<"INPUT RESULT"<<endl;
    outputFile <<game ;

    nextLevelTest(game);
    makeStepTest(game);
    addLife(game);
    addStrength(game);


    remove(game,2);
    outputFile<<"REMOVE RESULT"<<endl;
    outputFile <<game;


    inputTest2(game);
    outputFile<<"INPUT AFTER REMOVE RESULT"<<endl;
    outputFile <<game;

    firstFight(game);
    outputFile<<"FIRST FIGHT"<<endl;
    outputFile <<game;
    secondFight(game);
    outputFile<<"SECOND FIGHT"<<endl;
    outputFile <<game;
    (game.fight("tomer","sean")==SUCCESS)?cout<<"pass test 6"<<endl:cout<<"failed test 6"<<endl;
    (game.fight("tomer","sean")==NAME_DOES_NOT_EXIST)?cout<<"pass test 7"<<endl:cout<<"failed test 7"<<endl;
    outputFile<<"FINALE FIGHT"<<endl;
    outputFile <<game;
    cout<<"GOOD LUCK ON INFI 2.0"<<endl;
}



int main() {



    Test();
    return 0;

}