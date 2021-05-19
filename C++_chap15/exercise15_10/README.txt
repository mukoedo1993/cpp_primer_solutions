Q: Recalling the discussion from 8.1, explain how on page 317 that passed an ifstream to the Sales_data read function works.
A:The types ifstream and istringstream inherit from istream. The read function has a parameter, which is a reference to the istream, which is a base class.
We could bind a reference to a base class to the an object of ifstream, which derives from the base class istream.
