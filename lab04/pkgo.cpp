#include <iostream>
#include <iomanip>

using namespace std;

class Pokemon
{
public:
  Pokemon();
  void setName(string newName);
  void setNumber(int number);
  void takeDamage(int damageAmt);
private:
  string name const;
  int number const;
  int hp const;
};

Pokemon::Pokemon()
{
  cout << "The constructor is running" < endl;
  name = "Missisingo";
  number = 0;
  hp = 10;
}

void Pokemon::setName(string newName)
{
  name = newName;
}

void Pokemon::takeDamage(int damageAmt)
{
  hp = hp - damageAmt;
  if (hp < 0)
    {
      hp = 0;
    }
}
string Pokemon::getName const()
{
  return name;
}

int Pokemmon::setNumber const()
{
   number = newNumber;
}

int Pokemon::getHp const()
{
  return hp;
}


int main()
{
  Pokemon theGreatest;
  //theGreatest.setName = "Magikarp";
  cout << "The name is " << theGreatest.getName() << endl;
  return 0;
}
