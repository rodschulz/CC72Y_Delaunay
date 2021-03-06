/**
 * Author: rodrigo
 * 2015
 */
#pragma once

#include <string>

using namespace std;

typedef enum DebugLevel
{
	NONE, LOW, MEDIUM, HIGH
} DebugLevel;

typedef enum WalkingMethod
{
	STANDARD, JUMP_AND_WALK
} WalkingMethod;

class Config
{
public:
	~Config();

	// Returns the instance of the singleton
	static Config *getInstance()
	{
		static Config *instance = new Config();
		return instance;
	}
	// Loads the configuration file
	static void load(const string &_filename);
	// Returns the current debug level
	static DebugLevel getDebugLevel();
	// Returns a boolean value indicating if inputs has to be randomized
	static bool randomizeInput();
	// Boolean indicating if ids have to be drawn in images
	static bool showIds();
	// Boolean indicating if the circumcircles have to be drawn
	static bool drawCircles();
	// Returns the walking method to be used
	static WalkingMethod getWalkingMethod();
	// Returns the number of the walk to be drawn
	static int getWalkNumber();

private:
	Config();
	// Parses the given value according to the given key
	static void parse(const string _key, const string _value);

	bool randomize;
	bool ids;
	bool circles;
	int walkNumber;
	DebugLevel debugLevel;
	WalkingMethod walkingMethod;
};

