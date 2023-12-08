#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class lifter {
  private:
    string name, race;
    int comps, minDate, maxDate;

  public:
    string getLastName();
    string getRace();
    int getComps();
    int getExperience();
    void addComp();
    void setMinDate(int);
    void setMaxDate(int);
    void addRace(string);
    ifstream myReader;
    ofstream myWriter;
    void raceFinder(map<string, string>&);
    void compFinder(map<string,int>&);
};