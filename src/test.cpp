// #include <iostream>
// #include <forward_list>
// #include <memory>

// using namespace std;

// int main(){
// 	//todo build a 2D pointer list
// 	forward_list<shared_ptr <int>> int_ptr_l{};
	
// 	for (int i{0}; i<10; ++i){
// 		int_ptr_l.push_front(make_shared<int>(2*i));
// 	}

// 	forward_list<shared_ptr <const int>> int_pl{};
	
// 	for (forward_list<shared_ptr <int>>::const_iterator it{int_ptr_l.cbegin()}; it != int_ptr_l.cend(); ++it){
// 		cout <<"a: " << **it << endl;
// 		int_pl.push_front(*it);
// 	}

// 	cout << "the int pointer list (positions):" << endl;
// 	for (const shared_ptr <const int> i : int_pl){
// 		cout << "b: " << (*i) << endl;
// 	}

// 	forward_list<forward_list<shared_ptr <const int>>> int_pll{};
// 	for (int i{0}; i < 10 ; ++i){
// 		int_pll.push_front(int_pl);
// 	}

// 	for (shared_ptr <int> p:int_ptr_l){
// 		*p = 1;
// 	}

// 	cout << "the int pointer list list:" << endl;
// 	for (forward_list<shared_ptr <const int>> pl: int_pll){
// 		for (shared_ptr <const int> p: pl){
// 			cout << *p << ", ";
// 		}
// 		cout << endl;
// 	}

// 	// for (const int* i : int_pl){
// 	// 	cout << "c: " << (*i) << endl;
// 	// }
// 	// forward_list<int>::const_pointer cp;
// 	// cp = &int_l.front();
// 	// cout << *cp << endl;
// 	return 0;
// }
