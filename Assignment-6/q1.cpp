#include<iostream>

using namespace std;

struct R{
    int count;
    int *p;
};

class myvector {
	//int *p; // base pointer of the vector
	unsigned int size; // size of the vector
	bool shallow;
	struct R *r;
	//flag indicating whether this is a shallow copy of another myvector
	public:
		/*create an empty vector */
		myvector(){
			this->r = (struct R*)malloc(sizeof(struct R));
		    this->r->count =1;
		    this->r->p = nullptr;
			this->size = 0;
			this->shallow = false;//since the newly created myvector objs, will not be copy of any other vector.
		}
		/* create a vector of length size initialized to 0 */
		myvector(unsigned int n){
			this->size = n;
                        this->r = (struct R*)malloc(sizeof(struct R));
		        this->r->count =1;
			this->r->p = new int[this->size];
            
			this->shallow = false; //all the newly created myvector objs, will not be copy of any other vector.
		}
		/*copy constructor. Can be shallow or deep depending on the option */
		myvector(myvector& v, bool shallow=true){
			this->shallow = shallow; //shallow is initialized
			this->size = v.get_size(); //size is initialized
			if(this->shallow){
			    this->r = v.r;
			    this->r->count +=1;
			}
			else{ //deep copy
                               this->r = (struct R*)malloc(sizeof(struct R));
		                this->r->count = 1;
				this->r->p = new int[this->size]; // will point to new block of memory
				for(int i = 0; i<this->size; ++i)
					this->r->p[i] = v.get(i); //copying the contents of the array v.p[] to the new array this->p[]
			    
			}
		}
		/* return the base pointer to the vector */
		int* get_ptr() const{
			return this->r->p;
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
			this->r->p[i] = val;
		}
		/*return the element at index i*/
		constexpr int get(unsigned int i) const{
			return this->r->p[i];
		}
		/*print the vector contents in the console */
		void print() const{
			for(int i = 0; i<this->size; ++i){
				cout << this->r->p[i] << " ";
			}
			cout << endl;
		}
		/*Expand the vector and insert a new value at the end.*/
		void push_back(int val){
			myvector copy(*this, false); //deep copy
			this->size = this->size+1; //size is increased by 1
			delete this->r->p;
			this->r->p = new int[this->size]; //newly block of memory will be allocated 
			for(int i = 0; i<this->size-1; ++i){ //copying all the contents of the previous array
				this->r->p[i] = copy.r->p[i]; 
			}
			this->r->p[this->size-1] = val; //assigning the new value at the en
			cout<< "Push back done" << endl;
		}
		~myvector(){
			if(r->count == 1){ //delete only for the deep copied objects, since shallow copies point to the same array base address.
				delete this->r->p;
				free(this->r);
				cout << "deleted p\n";
			}
			else{
			    r->count -=1;
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
