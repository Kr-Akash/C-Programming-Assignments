#include<iostream>

using namespace std;

class myvector {
	int *p; // base pointer of the vector
	unsigned int size; // size of the vector
	bool shallow;
	//flag indicating whether this is a shallow copy of another myvector
	public:
		/*create an empty vector */
		myvector(){
			this->p = nullptr;
			this->size = 0;
			this->shallow = false;//since the newly created myvector objs, will not be copy of any other vector.
		}
		/* create a vector of length size initialized to 0 */
		myvector(unsigned int n){
			this->size = n;
			this->p = new int[this->size];
			this->shallow = false; //all the newly created myvector objs, will not be copy of any other vector.
		}
		/*copy constructor. Can be shallow or deep depending on the option */
		myvector(myvector& v, bool shallow=true){
			this->shallow = shallow; //shallow is initialized
			this->size = v.get_size(); //size is initialized
			if(this->shallow){
				this->p = v.get_ptr(); //shallow copy so same address will be pointed
			}
			else{ //deep copy
				this->p = new int[this->size]; // will point to new block of memory
				for(int i = 0; i<this->size; ++i)
					this->p[i] = v.get(i); //copying the contents of the array v.p[] to the new array this->p[]
			}
		}
		/* return the base pointer to the vector */
		int* get_ptr() const{
			return this->p;
		}
		/* return the size of the vector */
		constexpr unsigned int get_size() const{
			return this->size;
		}
		/* Return the shallow flag */
		bool is_shallow() const{
			return this->shallow;
		}
		/*update the element at index i with val*/
		void update(unsigned int i, int val){
			this->p[i] = val;
		}
		/*return the element at index i*/
		constexpr int get(unsigned int i) const{
			return this->p[i];
		}
		/*print the vector contents in the console */
		void print() const{
			for(int i = 0; i<this->size; ++i){
				cout << this->p[i] << " ";
			}
			cout << endl;
		}
		/*Expand the vector and insert a new value at the end.*/
		void push_back(int val){
			myvector copy(*this); //shallow copy
			this->size = this->size+1; //size is increased by 1
			this->p = new int[this->size]; //newly block of memory will be allocated 
			for(int i = 0; i<this->size-1; ++i){ //copying all the contents of the previous array
				this->p[i] = copy.p[i]; 
			}
			this->p[this->size-1] = val; //assigning the new value at the end
			
		}
		~myvector(){
			if(!this->is_shallow()){ //delete only for the deep copied objects, since shallow copies point to the same array base address.
				delete this->p;
			}
		}
};


int main(){
	myvector x(7); /*create a vector of size 7 initialized all to 0 */
	for (unsigned int i=0;i<7;i++)
	x.update(i,10+5*i);
	myvector v{x}; // shallow copy
	v.update(1,100);
	v.print();
	// print the contents of x and verify that x has also changed on updating v.
	x.print();
	myvector y {x,false}; // deep copy
	y.update(1,200);
	y.print();
	// print the contents of x and verify that x has NOT changed on updating y.
	x.print();
	// push_back 500 on y and verify
	y.push_back(500);
	y.print();
	return 0;
}
