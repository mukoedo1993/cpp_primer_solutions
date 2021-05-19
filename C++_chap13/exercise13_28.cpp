#include<iostream>
using std::string;

class TreeNode {
private:
	string value;
	int count;
	TreeNode* left;
	TreeNode* right;
	
public:
	
	TreeNode():count(0),value(string(""))
	{
		left = nullptr;
		right = nullptr;
		
	}
	
	TreeNode& operator=( TreeNode& rhs)
	{
		rhs.count++;
		value = rhs.value;
		count = rhs.count;
		if (rhs.left != nullptr)
			left = new TreeNode(*rhs.left);
		else
			left = nullptr;
		if (rhs.right != nullptr)
			right = new TreeNode(*rhs.right);
		else
			right = nullptr;

		return *this;
	}

	 TreeNode(const TreeNode& rhs)
	{
		
		 count = rhs.count;
		 count++;
		 value = rhs.value;
		 if (rhs.left != nullptr)
			 left = new TreeNode(*rhs.left);
		 else
			 left = nullptr;
		 if (rhs.right != nullptr)
			 right = new TreeNode(*rhs.right);
		 else
			 right = nullptr;
	}
	~TreeNode()
	{
		if (left != nullptr)
			delete left; left = nullptr;
		if (right != nullptr)
			delete right; right = nullptr;
		
	}

};

class BinStrTree {
private: TreeNode* root;
public:
	   BinStrTree()
	   {
		   root = nullptr;
	   }

	   
	  
	   BinStrTree(const BinStrTree &orig)
	   {
		   if (orig.root != nullptr)
			   root = orig.root;
		   else
			   root = nullptr;
			  
	   }
	   BinStrTree& operator=(const BinStrTree& orig)
	   {
		   if (orig.root != nullptr)
			   root = orig.root;
		   else
			   root = nullptr;
		   return *this;
	   }
	   ~BinStrTree()
	   {
		   if (root != nullptr)
			   delete root; root = nullptr;
	   }
};

int main()
{
	//Part A:
	string str1 = "dojo";
	int i = 7;
	TreeNode NodeA, NodeB(NodeA), NodeC;
	NodeC = NodeA;
	//Part B:
	BinStrTree BinA, BinB(BinA), BinC;
	BinC = BinA
		;
}