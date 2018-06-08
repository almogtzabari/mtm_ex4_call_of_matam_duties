#include "Game.h"
#include "test_utilities.h"

using std::getline;
using std::fstream;

void GameAddPlayerTest() {
  _print_mode_name("Testing GameAddPlayer function");
  Game game = Game(2);
  test(game.addPlayer("Censor", "integral", LIFE, 3) != SUCCESS,
       "GameAddPlayer doesn't return SUCCESS on successful addition",
       __LINE__);
  test(game.addPlayer("Censor", "integral", LIFE, 3) != NAME_ALREADY_EXISTS,
       "GameAddPlayer doesn't return NAME_ALREADY_EXISTS error",
       __LINE__);
  game.addPlayer("Alex", "derivative", LIFE, 3);
  test(game.addPlayer("Aliza", "Matrix", LIFE, 5) != GAME_FULL,
       "GameAddPlayer doesn't return GAME_FULL on error",
       __LINE__);
}

void GameNextLevelTest() {
  _print_mode_name("Testing GameNextLevel function");
  Game game = Game(1);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
  test(game.nextLevel("Linoy") != SUCCESS,
       "GameNextLevel doesn't return SUCCESS on successful increase of lvl",
       __LINE__);
  test(game.nextLevel("Moshe") != NAME_DOES_NOT_EXIST,
       "GameNextLevel doesn't return NAME_DOES_NOT_EXIST on player which doesn't exists.",
       __LINE__);
}

void GameMakeStepTest() {
  _print_mode_name("Testing GameMakeStep function");
  Game game = Game(1);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
  test(game.makeStep("Linoy") != SUCCESS,
       "GameMakeStep doesn't return SUCCES on successful step.",
       __LINE__);
  test(game.makeStep("Chris") != NAME_DOES_NOT_EXIST,
       "GameMakeStep doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
       __LINE__);
}

void GameAddLifeTest() {
  _print_mode_name("Testing GameAddLife function");
  Game game = Game(1);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
  test(game.addLife("Linoy") != SUCCESS,
       "GameAddLife doesn't return SUCCESS on successful step.",
       __LINE__);
  test(game.addLife("Chris") != NAME_DOES_NOT_EXIST,
       "GameAddLife doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
       __LINE__);
}

void GameAddStrengthTest() {
  _print_mode_name("Testing GameAddStrength function");
  Game game = Game(1);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
  test(game.addStrength("Linoy", 5) != SUCCESS,
       "GameAddLife doesn't return SUCCESS on successful step.",
       __LINE__);
  test(game.addStrength("Chris", 5) != NAME_DOES_NOT_EXIST,
       "GameAddStrength doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
       __LINE__);
  test(game.addStrength("Linoy", -1) != INVALID_PARAM,
       "GameAddStrength doesn't return INVALID_PARAM on negative strength input.",
       __LINE__);
}

void GameRemoveAllPlayersWIthWeakWeaponTest() {
  _print_mode_name("Testing GameRemoveAllPlayersWIthWeakWeapon function");
  Game game = Game(6);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
  game.addPlayer("Nazar", "lazer gun", LEVEL, 7);
  game.addPlayer("Max", "lazer gun", LIFE, 3);
  game.addPlayer("Guy", "lazer gun", STRENGTH, 4);
  game.removeAllPlayersWithWeakWeapon(6);
  test(game.addPlayer("Linoy", "lazer gun", LEVEL, 5) != SUCCESS,
       "GameRemoveAllPlayersWIthWeakWeapon didn't remove the player correctly.",
       __LINE__);
  test(game.addPlayer("Nazar", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
       "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
       __LINE__);
  test(game.addPlayer("Max", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
       "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
       __LINE__);
  test(game.addPlayer("Guy", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
       "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
       __LINE__);
}

void GameFightTest() {
  _print_mode_name("Testing GameFight function");
  Game game = Game(10);
  game.addPlayer("Linoy", "lazer gun", LEVEL, 1);
  game.addPlayer("Terry", "lazer gun", LIFE, 1);
  game.addPlayer("Markus", "lazer gun", STRENGTH, 1);
  game.addPlayer("Kevin", "lazer gun", STRENGTH, 2);
  game.addPlayer("Roi", "lazer gun", LIFE, 2);
  game.addPlayer("Nazar", "lazer gun", LEVEL, 2);
  game.addPlayer("Max", "lazer gun", LIFE, 2);
  game.addPlayer("Guy", "lazer gun", STRENGTH, 2);
  game.makeStep("Markus");
  game.makeStep("Linoy");
  game.makeStep("Nazar");
  game.makeStep("Kevin");
  game.makeStep("Terry");
  game.makeStep("Roi");
  game.makeStep("Max");
  game.makeStep("Max");
  cout << game;
  game.fight("Terry", "Roi");
  game.fight("Markus", "Kevin");
  cout << game;
  test(game.fight("Linoy", "Nazar") != SUCCESS,
       "GameFight didn't return SUCCESS on valid fight.",
       __LINE__);
  test(game.fight("Linoy", "Nazar") != NAME_DOES_NOT_EXIST,
       "GameFight didn't return NAME_DOES_NOT_EXIST when one of the players is dead(Lvl = 0).",
       __LINE__);
  test(game.addPlayer("Linoy", "lazer gun", LEVEL, 1) != SUCCESS,
       "GameFight didn't remove dead player after fight(Linoy) died due to Level = 0.",
       __LINE__);
  test(game.addPlayer("Terry", "lazer gun", LEVEL, 1) != SUCCESS,
       "GameFight didn't remove dead player after fight(Terry) died due to Life = 0.",
       __LINE__);
  test(game.addPlayer("Markus", "lazer gun", LEVEL, 1) != SUCCESS,
       "GameFight didn't remove dead player after fight(Markus) died due to Strength = 0.",
       __LINE__);
  test(game.fight("Nazar", "Max") != FIGHT_FAILED,
       "GameFight didn't return FIGHT_FAILED when 2 players were in different cells.",
       __LINE__);
  test(game.fight("Player1", "Max") != NAME_DOES_NOT_EXIST,
       "GameFight didn't return NAME_DOES_NOT_EXIST when name of player one isn't an existing player name",
       __LINE__);
  test(game.fight("Max", "Player1") != NAME_DOES_NOT_EXIST,
       "GameFight didn't return NAME_DOES_NOT_EXIST when player two isn't an existing player name.",
       __LINE__);
}

void memoryTestUnit() {
  { // block check if assignment free's memory of weapon a after re-assignment
    Weapon gun = Weapon("gun", LIFE, 5);
    Weapon knife = Weapon("knife", LIFE, 5);
    gun = knife;
    gun = gun; //self assignment check
    Weapon fork = Weapon(knife);
  }
  { // block check if assignment free's memory of player after re-assignment
    Weapon gun = Weapon("gun", LIFE, 5);
    Weapon knife = Weapon("knife", LIFE, 5);
    Player max = Player("Max", gun);
    Player dan = Player("Max", knife);
    Player dave = Player(max);
    max = dan;
    max = max; //self assignment check
  }
  { //self assignment check/cp'ctor
    Game game = Game(1);
    Game game2 = Game(2);
    game2.addPlayer("Linoy", "lazer gun", LEVEL, 1);
    game = game2; //assignment test
    game = game;
  }
}

int main() {
  cout <<
       "\tWelcome to the homework 4 mtmflix tests, "
       "written by Vova Parakhin.\n\n\t---Passing those tests won't"
       " guarantee you a good grade---\nBut they might get you closer"
       ",make some tests yourself to be sure.\n\n";
  cout << "You can change w/e you want in the file itself"
          " but make sure \nto contact me if you want to upload";
  cout << " \'upgraded version\' of the file.\n" << endl;
  cout << "Press ENTER to start the tests:. ";
  getchar();
  GameAddPlayerTest();
  GameNextLevelTest();
  GameMakeStepTest();
  GameAddLifeTest();
  GameAddStrengthTest();
  GameRemoveAllPlayersWIthWeakWeaponTest();
  GameFightTest();
  memoryTestUnit();
  print_grade();
  return 0;
}
