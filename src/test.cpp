// #include <iostream>
// #include <forward_list>

// using namespace std;

// main(){
// 	forward_list<int> int_l{0,1,2,3,4,5,6,7,8,9,10};
// 	forward_list<const int*> int_pl{};
	
// 	for (forward_list<int>::const_iterator it{int_l.cbegin()}; it != int_l.cend(); ++it){
// 		cout <<"a: " << *it << endl;
// 		int_pl.push_front(&*it);
// 	}

// 	cout << "the int pointer list (positions):" << endl;
// 	for (const int* i : int_pl){
// 		cout << "b: " << (*i) << endl;
// 	}

// 	int_pl.clear();
// 	for (int i : int_l){
// 		int_pl.push_front(&i);
// 	}

// 	for (const int* i : int_pl){
// 		cout << "c: " << (*i) << endl;
// 	}
// 	// forward_list<int>::const_pointer cp;
// 	// cp = &int_l.front();
// 	// cout << *cp << endl;
// }
