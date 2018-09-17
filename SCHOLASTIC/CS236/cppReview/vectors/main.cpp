#include <iostream>
#include <vector>

using namespace std;

int main() 
{ 
    vector<int> g1; 
    // Built in Iterators for Vectors

    cout << "BUILT IT ITERATORS FOR VECTORS!!!" << endl;
    cout << "#################################" << endl << endl;
    cout << "Vector has elements 1-5 in that order" << endl;
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Output of begin() and end(): "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of cbegin() and cend(): "; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of rbegin() and rend(): "; 
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 
  
    cout << "\nOutput of crbegin() and crend() : "; 
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
        cout << *ir << " ";

    cout << endl << endl;
    cout << "#################################" << endl;

    //BUILT IN CAPACITY FUNCTIONS

    cout << "BUILT IN CAPACITY FUNCTIONS!!!" << endl;
    cout << "##############################" << endl << endl;

    vector<int> v2;

    for(int i = 1; i <=6; i++)
      v2.push_back(i);
    
    cout << "Size: " << v2.size() << endl;
    cout << "Capacity: " << v2.capacity() << endl; // Increments of 8 bytes
    cout << "Max Size: " << v2.max_size() << endl;

    v2.resize(5);
    cout << "Size After resize(5): " << v2.size() << endl;

    if(v2.empty() == false)
      cout << "VECTOR NOT EMPTY!" << endl;
    else
      cout << "VECTORE IS EMPTY!" << endl;

    v2.shrink_to_fit();
    cout << "After shrink_to_fit, vec elements are: " << endl;
    for(auto it = v2.begin(); it != v2.end(); it++)
      cout << *it << " " << endl;

    cout << endl;
    cout << "##########################" << endl;
    // ELEMENT ACCESS FOR VECTORS
    cout << "ELEMENT ACCESS fOR VECTORS!!!" << endl;
    cout << "#############################" << endl << endl;

    vector<int> v3;

    for(int i = 1; i <=10; i++)
      v3.push_back(i);

    cout << "Reference Operator [g]: v3[2] = " << v3[2] << endl;
    cout << "at: v3.at(4) = " << v3.at(4) << endl;
    cout << "front() : v3.front() = " << v3.front() << endl;
    cout << "back() : v3.back() = " << v3.back() << endl;

    //Pointer to first element
    int* pos = v3.data();
    cout << "Pointer to First Element: " << pos << endl;
    cout << "The first element is: " << *pos << endl;

    cout << endl;
    cout << "###########################" << endl;

    //MODIFYING VECTOR ELEMENTS
    cout << "MODIFIERS!!!" << endl;
    cout << "##########################" << endl << endl;

    vector<int> v4;

    // fill with 10 five times
    v4.assign(5, 10);
    cout << "(vec.assign(5,10) - Vec elements are: ";
    for(int i = 0; i < v4.size(); i++)
      cout << v4[i] << " ";
    cout << endl;

    // insert 15 to last pos
    v4.push_back(15);
    int n = v4.size();
    cout << "After push_back(15) - The last element is: " << v4[n - 1] << endl;

    v4.pop_back();
    cout << "After pop_back(): ";
    for(int i = 0; i < v4.size(); i++)
      cout << v4[i] << " ";
    cout << endl;

    v4.insert(v4.begin(), 5);
    cout << "After inset(vec.begin(), #) - the first element is: " << v4[0] << endl;

    v4.erase(v4.begin());
    cout << "After vec.erase(vec.begin()) - the first element is: " << v4[0] << endl;

    v4.emplace(v4.begin(), 5);
    cout << "After emplace(vec.begin(), #) - first elemnent is: " << v4[0] << endl;

    v4.emplace_back(20);
    n = v4.size();
    cout << "After emplace_back(#) - the last element is: " << v4[n - 1] << endl;

    v4.clear();
    cout << "After vec.clear()- the vector size is: " << v4.size() << endl;

    cout << "Vector does have a swap function. See the docs if you need to use it" << endl;
    cout << endl;
    cout << "##############################" << endl;
    
    return 0;
    
} 
