#pragma once
//exercise 13_34 and sec13_4_A
#ifndef MEASSGE_FOLDER_H
#define MEASSGE_FOLDER_H
#include<iostream>
#include<set>
#include<algorithm>
class Folder;
class Message {
	friend class Folder;
	friend void swap(Message&, Message& );
public:
	//folders is implicitly initialized to the empty set
	explicit Message(const std::string &str=""):
		contents(str){}
	//copy control to manage pointers to this Message
	Message(const Message&);//copy constructor
	Message& operator=(const Message&);//copy constructor

	void addfldr(Folder* fldr)
	{
		folders.insert(fldr);
	}
	void remfldr(Folder* fldr)
	{
		folders.erase(fldr);
	}

	void destroy_Message()
	{
		folders.clear();
	}
	~Message();//destructor
	//add/remove this Message from the specified Folder's set of messages
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;//actual message text
	std::set<Folder*>folders;//Folders that have this Message
	//utility functions used by copy constructor, assignment, and destructor
	//add this Message from every Folder in folders
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder {
	friend class Messages;
	//Folder() = default;
	std::set<Message*>Mssg;

public:
	void addMsg(Message* Mess)
	{
		Mssg.insert(Mess);
	}
	void remMsg(Message* Mess)
	{
		Mssg.erase(Mess);
	}
	void print_all_Messages()
	{
		std::cout << "The printer is working...\n";
		for (auto it : Mssg)
			std::cout << it->contents << " ";
		std::cout << std::endl;
		std::cout << "The printer finished works.\n\n";
	}
	void remove_from_messages()
	{
		for (auto it : Mssg)
			it->remfldr(this);
	}
	//void destroy_folder()
	//{
		//remove_from_messages();
	//}
	~Folder()
	{
		remove_from_messages();
		//destroy_folder();
	}
};

/*The save and remove members*/
void Message::save(Folder& f)
{
	folders.insert(&f);//add the given Folder to our list of Folders
	f.addMsg(this);//add this Message to f's set of Messages
}

void Message::remove(Folder& f)
{
	folders.erase(&f);//take the given Folder out of our list of Folders
	f.remMsg(this);//remove this Message to f's set of Messages
}

/*Copy Control for the Message Class*/
//When we copy a Message, the copy should appear in the same Folders as the original Message.
//As a result, we must traverse the set of Folder pointers adding a pointer to the new Message to each Folder 
//that points to the original Message.

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)//for each Folder that holds m
		f->addMsg(this);//add a pointer to this Message to that Folder
}

//The Message copy constructor copies the data members of the given object:
Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);//add this Message to the Folders that point to m
}

//The Message Destructor
//When a Message is destroyed, we must remove this Message from the Folders that point to it.
//This work is shared with the copy-assignment
void Message::remove_from_Folders()
{
	for (auto f : folders)//for each pointer in folders
	{
		f->remMsg(this);//remove this Message from that Folder
	}
	
}
//Given the remove_from_Folders function, writting the destructor is trivial:
Message::~Message()
{
	remove_from_Folders();
	//destroy_Message();
}

//
Message& Message::operator=(const Message& rhs)
{
	//handle self-assignment by removing pointers before inserting them
	remove_from_Folders();//update existing Folders
	contents = rhs.contents;//copy message contents from rhs
	folders = rhs.folders;//copy Folder pointers from rhs
	add_to_Folders(rhs);//add this Message to those Folders
	//Notice that if the left- and right- operands are the same object, then they have the same address.
	//Had we called remove_from_folders 
	return *this;
}



/*A swap Function for Message*/
//The library defines versions for both string and set.
//We need to einf our own versions for the contents and folders members.

void swap(Message& lhs, Message& rhs)
{
	using std::swap;//not strictly needed in this case, but good habit.
	//remove pointers to each Message from their original respective Folders
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	//swap the contents amd Folders pointer sets
	swap(lhs.folders, rhs.folders);//use swap(set&,set&)
	swap(lhs.contents, rhs.contents);//swap(string&,string&)
	//add pointers to each Message to their (new) respective Folders
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);

}

#endif