#include "highscore.h"

// Reads the lines from highscore text file
void HighScore::Read(void) {

    std::string line;
    std::string name;
    std::string score;
    std::string date; 
    Player player;

    std::ifstream stream(khighscorefile);
    if (stream.is_open()){
        while (std::getline(stream, line)){
            std::istringstream linestream(line);
            while (linestream >> name >> score >> date){ 
                player.setName(name);
                player.setScore(std::stoi(score));
                player.setDate(date); 
                
                _playerList.emplace_back(player);
            }
        }
    }
}

// Write new highscores to file 
void HighScore::Write(void) {

    // open highscore file as stream and put players in
    std::ofstream file;
    file.open (khighscorefile);
    for (std::vector<Player>::iterator iter = _playerList.begin(); iter != _playerList.end(); ++iter){
        file << iter->getName() << " " << iter->getScore() << " "<< iter->getDate() <<"\n"; 
    }
    file.close();
}

// After finishing the game print first print_N_highscores highscores
void HighScore::Print(void) {
    int i = 0;
    std::cout << "Highscores:  \n \n";
    
    // loop through list of players
    for (std::vector<Player>::iterator iter = _playerList.begin(); iter < _playerList.end(); ++iter) {
        i++;
        std::cout << "Rank " << i << ":\t" << iter->getName() << "\t" << iter->getScore() << "\t" << iter->getDate() << "\n"; 
        if (i >= print_N_highscores)
        {
            break;
        }
    }
    std::cout << "\n";
}

// Update Highscore
void HighScore::Update(std::string playerName, int score) {
    Player player;
    player.setName(playerName);
    player.setScore(score);

    // get current time
    time_t now = time(0);
    std::tm *ltm = localtime(&now);

    std::string year = std::to_string(1900 + ltm->tm_year) ;
    std::string month =  std::to_string(1 + ltm->tm_mon);
    std::string day =   std::to_string(ltm->tm_mday);

    std::string date = day + "." + month + "." + year;
    player.setDate(date);

    // Insert new highscore 
    if (score > _playerList.front().getScore()){
        _playerList.insert(_playerList.begin(), player);
    }
        
}
