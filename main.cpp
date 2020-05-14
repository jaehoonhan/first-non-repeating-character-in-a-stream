#include <iostream>
#include "Queue.h"
#include <cstdlib>

using namespace std;
const int MAX_CHAR = 26; 
void firstnonrepeating(char str[]) 
{ 
    queue<char> q;  //queue of char type
    int charCount[MAX_CHAR] = { 0 }; //hash array for freq
  
    // traverse whole stream 
    for (int i = 0; str[i]; i++) { //for each element in string
  
        // push each character in queue 
        q.enqueue(str[i]); 
  
        // increment the frequency count 
        charCount[str[i] - 'a']++; //convert lowercase # to numerical value
  
        // loop to check each letter before enqueueing next one
        while (!q.isEmpty()) { 
            if (charCount[q.peek() - 'a'] > 1) 
                q.dequeue(); //remove element if not freq > 1
            else { 
                cout << q.peek() << " "; 
                break; 
            } 
        } 
  
        if (q.isEmpty()) //if no nonrepeating numbers, output -1
            cout << -1 << " "; 
    } 
    cout << endl; 
} 

int main()
{
 
    int n;
    cout<< "Input string size: ";
    cin>>n;
    char *a=new char[n]; 
    for(int i=0;i<n;i++)
         {
             cin>>a[i];
         }  
    cout<<"First nonrepeating lowercase characters: ";

    firstnonrepeating(a); 
    return 0; 
 
}
