#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Group 
{
private:
	string name;
	int numberOfPeople;
	map<string, list<pair<string, string>>> plan;

public:
	Group(string name, int numberOfPeople) : name(name), numberOfPeople(numberOfPeople) {}

	void addSubject(string subjectName, string date, string time) 
	{
		plan[subjectName].push_back(make_pair(date, time));
	}

	void checkCollision(Group& otherGroup) 
	{
		for (auto subject : plan)
		{
			for (auto dateTime : subject.second) 
			{
				for (auto otherSubject : otherGroup.plan)
				{
					for (auto otherDateTime : otherSubject.second) 
					{
						if (subject.first == otherSubject.first && dateTime.first == otherDateTime.first && dateTime.second == otherDateTime.second) 
						{
							cout << "Collision detected between group " << name << " and group " << otherGroup.name << " for subject " << subject.first << " on " << dateTime.first << " at " << dateTime.second << endl;
						}
					}
				}
			}
		}
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() 
{
	Group group1("WSB1", 30);
	group1.addSubject("Math", "Monday", "9:00");
	group1.addSubject("Physics", "Wednesday", "11:00");

	Group group2("WSB2", 25);
	group2.addSubject("Math", "Monday", "9:00");
	group2.addSubject("Biology", "Tuesday", "12:00");

	group1.checkCollision(group2);

	return 0;
}