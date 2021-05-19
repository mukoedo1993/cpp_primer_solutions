Classes:1. Message 2.Folder
To keep track of which Messages are in which Folders, each Message will store a set of pointers to the Folders in which it appears, and each Folder will contain a set
of pointers to its Messages.
Our Message class will provide save and remove operations to add or remove a Message from a specified Folder. 
To create a new Message, we will specify the contents of the message but no Folder. To put a Message in a particular Folder, we must call save.
When we copy a Message, the copy and the original will be distinct Messages, but both Messages should appear in the same set of Folders. Thus,copying a Message will copy the contents 
and the set of Foler pointers. It must also add a pointer to the newly created Message to each of those Folders.
When we destroy a Message, the Message no longer exists. Therefore, destroying a Message must remove pointers to that Message from the Folders that had contained that Message.
When we assign one Message to another, we'll replace the contents of the left-hand Message with those in the right-hand side. We must also update the set of Folders, removing
the left-hand Message from its previous Folders, removing the left-hand Message from its previous  Folders and adding that  Message to the Folders in which the right-hand Message appears.

Destructor and copy-assignment operator: remove the Message from the Folders that point to it.
Similarly, both the copy constructor and the copy-assignment operator add a Message to a given list of Folders.
