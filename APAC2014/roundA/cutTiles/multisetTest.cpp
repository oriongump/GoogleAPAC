#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
 int a[ 10 ] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
 int aSize = sizeof(a) / sizeof(int);
 std::multiset< int, std::less< int > > intMultiset(a, a + aSize);

 cout << "Printing out all the values in the multiset : ";
 multiset<int>::iterator it;
 for ( it = intMultiset.begin(); it != intMultiset.end(); ++it)
   cout << "  " << *it;
 cout << endl << endl;

 std::ostream_iterator< int > output( cout, " " );

 cout << "There are currently " << intMultiset.count( 15 )
      << " values of 15 in the multiset\n\n";

 intMultiset.insert( 15 );
 intMultiset.insert( 15 );

 cout << "After two inserts, there are currently " << intMultiset.count( 15 )
      << " values of 15 in the multiset\n\n";

 cout << "Printing out all the values in the multiset : ";
 for ( it = intMultiset.begin(); it != intMultiset.end(); ++it)
   cout << "  " << *it;
 cout << endl << endl;

 return 0;
}
