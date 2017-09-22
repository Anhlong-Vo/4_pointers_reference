// pointer_reference_intro.cpp
#include <iostream>

//pass by value
void func1(int ival){
	ival=27;
}

//pass by reference
//note the address of operator &
//if iVal is changed in the function then
//the change follows iVal out of function
void func2(int &ival){
	ival=27;
}

//pass by pointer
void func3(int *ival){

	//must check to see if null (0)
	//if dereference a null pointer *ival
	//and ival =0 then program could crash
	if (ival ==0)
		return;

	//alternate
	if (!ival)
		return;

	//change the value
	*ival=27;
}

//dereference null pointer - CRASH!
void funcDontCheckForNull(int *ival){
	//change the value without check
	//DO NOT DEREFERENCE A NULL POINTER
	*ival=27;
}


int myint =1;

int main(){
	//*************************************************************************************
	//pass by value,
	//like Java, values passed in are COPIED
	//when exit function, original value remains
	int ival	=10;
	func1(ival);

	//*************************************************************************************
	//references
	int i		=10;
	int &iRef	=i;		//must initialize, cannot change it, cannot be 0
	iRef		=3;

	//not used much above way & (address of) used a lot in functions
	ival		=10;
	func2(ival);		//note you don't need & here, its in the function definition
						//when this returns ival will = 27

						//add an ival watch - data
						//then an &ival watch - memory address

	//*************************************************************************************
	//pointers
	//like a souped up reference
	//can be 0(must verify that they are not 0 before dereferencing)
	//should be initialized (either to 0 or to &addressofsomething)
	//can be reassigned

	ival		=56;
	int * pval	=0;		//set to 0 (null) on creation otherwise its
						//initiliazed to random data
						//this burns you because you often check to see
						//if a pointer has been initialized by the following

	pval	= &ival;	//reassign pointer to point to ival
	*pval	= 33;		//change value of what pval points to (changes ival)

	ival	=10;
	func3(&ival);		//note you need to take the address of the int here

	ival	=10;		//reset
	func3(pval);		//but not the pointer

	//set this symbol in Project Properties -> C/C++ -> preprocessor -> Preprocessor Definitions
#ifdef SHOW_NULL_POINTER_EXCEPTION
	int *pNull = 0;		//what happens when you dereference a null pointer
	funcDontCheckForNull(pNull);
#endif

	//pointer verses reference?
	//look at memory footprint
	pval		=&ival;
	int &myRef	=ival;

	//EXTRA pointer arithmatic
	//pointers can be repointed
	//Here I will use a pointer to iterate over an array use a pointer
	//and set values
	int myIntArray[10];
	pval = &myIntArray[0];

	for(int i=0; i<10;i++){
		*pval = i;
		pval++;	//this will increment pval by the SIZE of int (4) NOT 1 see below
	}

	//why 4? how big is an int?
	int iIntSize = sizeof(int);
	//4 bytes= 32 bits
	//all 0s convert to hex 0x00000000
	//so the following pointer will be initialized to point to 0x00000000 on my machine
}

//if (pval == 0)
//	std::cout <<"pval is null";
//else
//	std::cout <<"pval is NOT null";
