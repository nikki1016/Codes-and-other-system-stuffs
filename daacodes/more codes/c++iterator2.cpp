#include<vector> // vector
#include<iterator> //iterators
#include<iostream> //cin cout
#include<algorithm> // sort
using namespace std;


int main ()
{

// create a vector to hold numbers typed in
vector<int> v;
cout << "Please enter numbers (ctrl-D) ends sequence" << endl;
istream_iterator<int> start (cin); //input iterator from stream
istream_iterator<int> end;
// end of stream iterator
back_insert_iterator<vector<int> > dest (v); // append integers to vector
copy (start, end, dest); // copy cin numbers to vector
sort(v.begin(), v.end()); // sort the vector
copy (v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
return 0;
}
