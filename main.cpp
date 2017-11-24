#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <list>


using namespace std;

class ArrayList{
    const int INIT_SIZE = 1000;
    int* array;
    int currentSize;
    int allocatedSize;
    
    void fillNewArray(int* newArray){
        for (int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
    }
    
    void addNotFullArray(int n){
        array[currentSize] = n;
        currentSize++;
    }
    // if array full reacreator array in new size
    void addFullArray(int n){
        int* newArray = new int (allocatedSize *2);
        allocatedSize*=2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
        addNotFullArray(n);
    }

public:
    ArrayList(){
    array = new int[INIT_SIZE];
    currentSize = 0;
    allocatedSize = INIT_SIZE;
    }
	// function add number
    void add (int n){
        if (currentSize < allocatedSize){
            addNotFullArray(n);
        } else {
            addFullArray(n);
        }
    }

  
	// fuction add number for index
    void add (int n, int index){
       //check for occurrence in the range of allowed values
        if (index >= currentSize){
            cout<<"Index of bound"<<endl;
            return;
        }
        //if the array is small, increase the size
        if ( currentSize >= allocatedSize) {
            int* newArray = new int (allocatedSize  *2);
            allocatedSize*=2;
            fillNewArray(newArray);
            delete []array;
            array = newArray;
        }
        //copy (shift) the array from the tail to the desired index
        for (int i=currentSize; i>index; i--) {
            array[i] = array[i-1];
            }
        array[index]=n;
        currentSize++;
    }  
	// function trim array
    void trimTpSize(){
       int *newArray = new int (currentSize);
        allocatedSize=currentSize;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
    }
	// funtion remove for index 
    void remove(int index){
        
        //checking an array for an empty value
        if (currentSize == 0) {
           cout<<"Not found element form delete";
           return; 
        } 
        
        //delete element without shifting the elements
        if (index == currentSize) {
            currentSize--;
            return;
        }
        
        //delete element with shifting of elements
        currentSize--;
        for (int i=index-1; i<currentSize; i++) {
            array[i] = array[i+1];
        }
        
    }		
	//function gets number fo index
    int getIndex(int index) {
        if (index >= currentSize){
            cout<<"Index of bound"<<endl;
            return -1;
        }
        return array[index];
    }
	// function print array
    void print(){
        for (int i = 0; i < currentSize; i++){
            cout<<array[i]<<"  ";
        }
    }
};


int main()
{
ArrayList* list = new ArrayList();
    for (int i = 0 ; i < 20; i++){
        list->add(i);
    }
list->print();

cout<<list->getIndex(6)<<endl;

list->remove(4);
    for (int i = 0 ; i < 20; i++){
    }
list->print();

}
