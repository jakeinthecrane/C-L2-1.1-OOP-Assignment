// 1.1 Assignment OOP C++ LVL2.cpp : This file contains the 'main' function. Program execution begins and ends there. //
//

#include <iostream>
#include <string>

using namespace std;

// Our base object written in PascalCase. //
class Musicians
{
public:
	// virtual method as an abstract class //
	virtual void Help() const = 0;
};

class RockBand : public Musicians // Here we inherit Musicians class. The semi-colon to initialize inheritence //
{
private:

	string name; // Attributes //
	int health;



public:
	// Default constructor to set memory asside. //
	RockBand(): health(100) // Every musician has a health meter of 100 points. //
	{}

	// Setter method for name as musicianName in camelCase so that we can distiguish between variables and Objects.  
	void setName(const string& musicianName) /* We use the ampersand to reference rather than copy dada for efficiency.
		                                       MusicanName is set const so that it cannot alter the state of the object */
	{
		name = musicianName;
	}                        

	// Getter for name and we declare the variable constant indicating to programmers and the compiler to ensure data integrity. //
	string getName()const
	{
		return name; // first fetches from the object then returns name back to main to where it is called. //
	}


	virtual int attack() const // attack override method in the base class returning 10 musical energy points by default. //
	{
		return 100; 
	}


	void setHealth(int newHealth) //setHealth method taking in an int parameter calling it newHealth. //
	{
		if (newHealth < 0) // is statement with a conditional to check if newHealth is less than 0. //
		{
			health = 0; // health is set to 0 if true. //
			cout << getName() << ": This musician is jammed out" << endl; // prints expired message to the console. //
		}
		else // else block as a result of the if condition being false. //
		{
			health = newHealth; // newHealth is assigned to the health member with given value. //
			cout << getName() << "'s health is: " << health << endl;
		}
	}

	int getHealth()const // getter method for health. //
	{
		return health; // returns health value back to main.. //
	}


	// Overloaded Talk method #1.  Takes place at compile time and can make optimizations during compilation. Faster debugging benefit, no overhead //
	void Talk(string stuffToSay) // (downdsides: decisions are rigid, large projects are slower to compile, and you need to fix your errors before running them.. //
	{
		cout << getName() << stuffToSay << endl; 
	}

	// Overloaded Talk method #2 using the same name... demonstrating function reusabily. // 
	void Talk(string name, string stuffToSay) 
	{
		cout << getName() << " to " << name << ": " << stuffToSay << endl;
	}

	void Help() const override
	{}
	
};

class Bassist : public RockBand
{
public:
	void playingTheBass() // Methods that I think are comparible to throwing ninja stars and swinging swords. // 
	{

		cout << getName() << " is playing the bass." << endl;
	}

	int attack() const override  // Attack override demonstrating attack energy.  How they attack their instruments. //
	{
		return 98; // returning a 98 point instrument attack because he gets down. //
	}

	void Help() const override
	{
		cout << getName << " says: Let met help fill in while you switch guitars.' " << endl;
	}


};

class Guitarist : public RockBand
{
public:

	void playingTheGuitar()
	{
		cout << getName() << " is playing the guitar." << endl;
	}

	int attack() const override // 2nd attack override demonstration. //
	{
		return 97;
	}

	void Help() const override
	{
		cout << getName() << " says: thanks man! " << endl;
	}

};

int main()
{
	Bassist bassist; // here we create our objects for the bassist and guitarist //
	Guitarist guitarist;

	bassist.setName("Flea"); // we set our musicians names here. //
	guitarist.setName("John");

	bassist.playingTheBass(); // here we call method to demonstrate the characters musical tools.. //
	guitarist.playingTheGuitar(); 



	// calling the setHealth method //
	bassist.setHealth(13); // setting the bassist health to 13. //
	guitarist.setHealth(-10);  // setting the guitarists health to -10. //


	// Calling the talk method for the objects. bassist exibits Talk #1 and guitarist exibits Talk #2. //
	bassist.Talk(": Hey, Around the World is up next. I'm going to drop that fat bass line, follow me! "); 
	guitarist.Talk("Flea", "I'm ready, fire it up!");

	// Calling Attack override methods //
	cout << bassist.getName() << "'s musical attack: " << bassist.attack() << " points. " << endl;
	cout << guitarist.getName() << "'s musical attack: " << guitarist.attack() << " points. " << endl;

	// calling the Help override methods //
	bassist.Help();
	guitarist.Help();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
