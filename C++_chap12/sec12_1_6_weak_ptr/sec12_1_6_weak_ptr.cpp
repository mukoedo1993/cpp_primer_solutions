//A weak_ptr is a smart pointer that does not control the lifetime of the object to which it points.

// Instead, a weak_ptr points to an object that is managed by a shared_ptr.

//Binding a weak_ptr to a shared_ptr does not change the reference count of the shared_ptr.

//Once the last shared_ptr pointing to the object goes away, the object itself will be deleted.

//The object will be deleted even if there are weak_ptrs pointing to it--hence the name weak_ptr, which 
//captures the idea that a weak_ptr shares its object weakly.

#include<memory>
#include<iostream>
#include<vector>
#include<stdexcept>
#include"Blob_ver2.h"
using std::weak_ptr;
using std::shared_ptr;
using std::make_shared;

//StrBlobPtr will have two data members:
//1:wptr, which is either null, or a weak_ptr<std::vector<std::string>>
//2: curr, the index of the element that this object currently denotes.
//3: a check member: to verify it is safe to dereference the StrBlobPtr:

int main()
{
	//When we created a weak_ptr, we weakly shares with p; we count in p is unchanged.
	auto p = make_shared<int>(42);
	weak_ptr<int>wp(p);// wp weakly shared with p; use count in p is unchanged.

	std::cout << " *(wp.lock()): " << *(wp.lock()) << std::endl;//42

	//w.reset(): make w null
	//w.use_count():The number of shared_ptrs that share ownership with w
	//w.expired(): Returns  true if w.use_count() is zero, false otherwise
	//w.lock() if expired is true, returns a null shared_ptr.
	//otherwise returns a shared_ptr to the object to which w points.

	if (shared_ptr<int>np = wp.lock())//true if np is not null
	{
		//inside the if,np shares its object with p.
		std::cout << "wp.use_count()inside the if_block: " << wp.use_count() << std::endl;//2
	}
	std::cout << "wp.use_count() outside the if_block: " << wp.use_count() << std::endl;//1
}