#include "lifter.h"
using namespace std;

int lifter::getComps() {
  return maxDate - minDate;
}

string lifter::getLastName() {
  string temp = "";
  int lastSpace = name.find_last_of(" ");
  temp = name.substr(lastSpace+1);
  return temp;
}

string lifter::getRace() {
  return race;
}

void lifter::addComp() {
  comps++;
}

void lifter::addRace(string r) {
  race = r;
}

void lifter::setMinDate(int d) {
  minDate = d;
}

void lifter::setMaxDate(int d) {
  maxDate = d;
}
void lifter::raceFinder(map<string,string>& m) {
  myReader.open("testingDataSet-1.csv");
  if (!myReader.is_open()) {
    cout << "No" << endl;
  }
  string line;
  int space = 0;
  string lname;
  string race;
  int x = 0;
  while (getline(myReader, line)) {
        x = 0;
        while (x < line.length()) {
            if (line[x] == ' ') {
                space = x + 1;
            }
            if (line[x] == ',') {
                lname = line.substr(space, x - space);
                //cout << lname << endl;
                break;
            }
            x++;
        }
    for (int o = 0; o < lname.length(); o++) {
      lname[o] = toupper(lname[o]);
    }
    //cout << "lname " << lname << " ";
    ifstream my2Reader;
    my2Reader.open("last_nameRaceProbs.csv");
    if (!my2Reader.is_open()) {
      cout << "Mo";
    }
    string line2;
    while (getline(my2Reader, line2)) {
      int comma = 0;
      string com;
      double white = 0;
      double black = 0;
      double asian = 0;
      double hispanic = 0;
      double other = 0;
      int index = line2.find(',');
      com = line2.substr(comma, index - comma);
      comma = index;
        if (com == lname) {
          for (int i = index + 1; i < line2.length(); i++) {
            if (line2[i] == ',') {
              string check = line2.substr(comma + 1, i - comma);
              comma = i;
              if (stod(check)) {
                if (white == 0) {
                  white = stod(check);
                }
                else if (black == 0) {
                  black = stod(check);
                }
                else if (hispanic == 0) {
                  hispanic = stod(check);
                }
                else if (asian == 0) {
                  asian = stod(check);
                }
                else if (other == 0) {
                  other = stod(check);
                }
              }
            }
          }
          double largest = white;
          race = "white";
          if (black > largest) {
            largest = black;
            race = "black";
                        }
          if (hispanic > largest) {
            largest = hispanic;
            race = "hispanic";
                        }
          if (asian > largest) {
            largest = asian;
            race = "asian";
                        }
          if (other > largest) {
            largest = other;
            race = "other";
                        }
          my2Reader.close(); 
          m[lname] = race;
          //cout << race << endl;
          break;  
                    }
                }
            }
  myReader.close();
        }
void lifter::compFinder(map<string,int>& m) {
  myReader.open("testingDataSet-1.csv");
  string line;
  string name;
  string lastname;
  int biggest = 0;
  int smallest = 0;
  int sl = 0;
  int date = 0;
  int years = 0;
  vector<int> v;
  while (getline(myReader, line)) {
    sl = line.find('/');
    sl = line.find('/', sl + 1);
    try {
      date = stoi(line.substr(sl+1, 4));
    }
      catch (invalid_argument &e) {
       cerr << "First Line with examples" << endl; 
      }
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
          name = line.substr(0,i);
          break;
        }
      }
    if (lastname == name) {
      m[lastname]++;
      v.push_back(date);
    }
    else {
      m[name]++;
      if (!v.empty()) {
        biggest = v[0];
        smallest = v[0];
        for (int i = 0; i < v.size(); i++) {
          //cout << v[i] << endl;
          if (biggest < v[i]) {
            biggest = v[i];
            //cout << "Big: " << biggest << endl;
          }
          if (smallest > v[i]) {
            smallest = v[i];
            //cout << "Small: " << smallest << endl;
          }
        }
        cout << endl;
        years = biggest - smallest;
        biggest = 0;
        smallest = 10000;
        //cout << years << endl;
        v.clear();
      }
      v.push_back(date);
    }
    lastname = name;
  }
}
