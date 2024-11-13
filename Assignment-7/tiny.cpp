class Tiny{
   char v;
   void assign(int i) {
      if(i&~077) throw Bad_range(); v=i; 
   }
public:
   class Bad_range{ };
   Tiny(int i) { 
   	assign(i);
   }
   Tiny& operator=(int i){
  	 assign(i); 
   	return *this; 
   }
   operator int() const {
   	return v;
   }
};

int main(){
	Tiny c1 = 2; // Perform range check
	Tiny c2 = 62; // perform range check
	Tiny c3 = c2 - c1; // c3 = 60;
	Tiny c4 = c3; // no range check required
	int i = c1 + c2; // i = 64
	c1 = c1 + c2; // range error: c1 can’t be 64
	i = c3 - 64; //i = -4
	c2 = c3 - 64; // range error: c2 can’t be -4
	c3 = c4; // no range check required
}
