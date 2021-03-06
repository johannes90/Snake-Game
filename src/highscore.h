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

const int kMaxentries = 500;
const std::string khighscorefile = "../highscore.txt";
static const int print_N_highscores = 20;

class HighScore{
public:
    void Read(void);
    void Write(void);
    void Print(void);
    void Update(std::string playerName, int score);

private:
    std::vector<Player> _playerList;
     
};

bool compare_player_by_score(Player player1, Player player2);




