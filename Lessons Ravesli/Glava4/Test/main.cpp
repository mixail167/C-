#include <iostream>
#include <string>
using namespace std;

enum class MonsterType
{
	OGRE,
	GOBLIN,
	SKELETON,
	ORC,
	TROLL
};

struct Monster
{
	MonsterType monsterType;
	string name;
	int health;
};

string getType(MonsterType type)
{
	switch (type)
	{
	case MonsterType::OGRE:
		return "OGRE";
	case MonsterType::GOBLIN:
		return "GOBLIN";
	case MonsterType::SKELETON:
		return "SKELETON";
	case MonsterType::ORC:
		return "ORC";
	case MonsterType::TROLL:
		return "TROLL";
	default:
		return "Unknown";
	}
}

void printInfo(Monster m)
{
	cout << "This " << getType(m.monsterType) << " is named " << m.name << " and has " << m.health << " health" << endl;
}

int main()
{
	Monster m1 = { MonsterType::GOBLIN, "John", 170 };
	Monster m2 = { MonsterType::ORC, "James", 35 };
	printInfo(m1);
	printInfo(m2);
	cin.clear();
	cin.get();
	return 0;
}