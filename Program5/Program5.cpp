/*
* co-created with voojo :D
*/
#include <iostream>
#include <algorithm>
#include <vector> //vector class-template
#include <numeric>
#include <set>
#include <map>

using namespace std;

typedef multimap<int, string, less<int> >mp_type;

int main()
{
	vector<int> v;

	// add integers at the end of the vector

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(5);

	//1)
	v.insert(v.begin() + 1, 7);

	//2)
	v[0] = 9;

	//3)
	v.push_back(v[0]);
	v.push_back(v[1]);

	//4)
	vector<int>::iterator iter = find(v.begin(), v.end(), 3);
	if (iter != v.end())
		cout << "Element found in myvector: " << *iter << '\n';
	else
		cout << "Element not found in myints\n";

	//5)  
	v.erase(iter);

	//6)
	cout << "The smallest element is " << *min_element(v.begin(), v.end()) << '\n';

	//7)
	sort(v.begin(), v.end());

	//8)
	reverse(v.begin(), v.end());


	//9)
	cout << "Sum of elements 9 is: " << 9 * count(v.begin(), v.end(), 9) << endl;

	//10)
	cout << "Sum of 4 first elements: " << accumulate(v.begin(), v.begin() + 4, 0) << endl;

	cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();

	vector<int>::const_iterator it;
	cout << "\nThe content of v is: ";
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}


	//============================================================
	cout << endl;
	cout << "=========================================" << endl;

	set<int, less<int> > s;

	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(7);
	s.insert(5);

	//1)
	s.insert(7);

	//2)

	s.erase(2);
	s.insert(9);

	//4)
	set<int>::iterator iters = find(s.begin(), s.end(), 3);
	if (iters != s.end())
		cout << "Element found in mysector: " << *iters << '\n';
	else
		cout << "Element not found in myints\n";
	
	//5)
	s.erase(iters);
	
	//6)
	cout << "The smallest element is " << *min_element(s.begin(),s.end()) << '\n';
	
	//9)
	cout << "Sum of elements 9 is: " << 9 * count(s.begin(), s.end(), 9) << endl;
	
	//10)
	cout << "Sum of 4 first elements: " << accumulate(s.begin(), s.end(), 0) << endl;

	cout << "The size of s is: " << s.size() << endl;
	
	set<int>::iterator iter_set;
	cout << "\nThe content of s is: ";
	for (iter_set = s.begin(); iter_set != s.end(); iter_set++)
	{
		cout << *iter_set << " ";
	}



	//==============================================================
	cout << "\n=========================================" << endl;
	mp_type mp;
	mp_type::iterator iter_map;

	mp.insert(mp_type::value_type(2, "dwa"));
	mp.insert(mp_type::value_type(3, "trzy"));
	mp.insert(mp_type::value_type(4, "cztery"));
	mp.insert(mp_type::value_type(7, "siedem"));
	mp.insert(mp_type::value_type(5, "piec"));

	//1
	mp.insert(mp_type::value_type(7, "siedem"));

	//2
	mp.erase(mp.begin());
	mp.insert(mp_type::value_type(9, "dziewiec"));

	//3
	mp_type::iterator a = mp.begin();
	mp_type::iterator b = a++;
	mp.insert(mp_type::value_type(*a));
	mp.insert(mp_type::value_type(*b));

	//4
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> iter_map2 = mp.equal_range(3);

	//5
	mp.erase(3);

	//6
	cout << "The smallest element is " << (min_element(mp.begin(), mp.end())->first) << '\n';

	//9
	cout << "Sum of elements 9 is: " << 9 * mp.count(9) << endl;

	//10
	iter_map = mp.begin();
	int sum = 0;
	for (int i = 0; i < 4; i++, iter_map++)
	{
		sum += iter_map->first;
	}
	cout << "Sum of 4 first elements: " << sum << endl;
	
	cout << "\nThe content of s is: ";
	for (iter_map = mp.begin();iter_map != mp.end(); iter_map++)
	{
		cout << iter_map->first << " ";
	}

	cin.get();
	return 0;
}