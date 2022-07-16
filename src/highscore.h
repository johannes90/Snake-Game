/*
    Highscore class parses the highscore from/to file and updates the internal playerlist
*/
#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime> // for date
#include "player.h"

const int kMaxentries = 100;
const std::string khighscorefile = "../highscore.txt";
static const int print_N_highscores = 5;

class HighScore{
public:
    void Read(void);
    void Write(void);
    void Print(void);
    void Update(std::string playerName, int score);

private:
    std::vector<Player> _playerList;
     
};





