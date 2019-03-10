#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class ListeningIn
{
public:
  string probableMatch(string typed, string phrase) {
    string droppings;
    for( int i = 0; i < phrase.size(); )
    {
      if( phrase[i] != typed[i] )
      {
        droppings += phrase[i];
        phrase.erase( i, 1 );
      }
      else
        i++;
    }
    if( phrase != typed )return "UNMATCHED";
    else return droppings;
  }




};

int main(){
    ListeningIn *li;
    string res = li -> probableMatch("back to base","back to base") ;
    cout << "caso1 iguales" << endl;
    cout << res << endl;
    res = li -> probableMatch("back  to base","back to base") ;
    cout << "caso2 diferentes" << endl;
    cout << res << endl;
    return 0;
}

