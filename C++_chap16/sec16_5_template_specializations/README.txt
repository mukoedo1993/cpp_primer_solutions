Part 2:
Our hash<Sales_data> definition starts with template<>, which indicates
that we are defining a fully specialized template. The template we're 
specializing is named hash and the specialized version is hash<Sales_data>.
The members of class follow directly from the requiremenets for specializing hash.

As with any other class, we can define the members of a specialization inside the class or out of it, as we did here.
The overloaded call operator must define a hashing function over the values of the given type. This function is required to return
the same result every time it is called for a given value. A good hash to return the same result every time it is called for
a given value. A good hash function will (almost always) yield different results for objects that are not equal.

We use an  (unnamed)hash<string>object to generate a hash code for bookNo, an object of type hash<unsigned>to generate a hash from units_sold, and
an object of type hash<unsigned> to generate a hash from units_sold, and an object of type hash<double> to generate a hash from revenue. We XOR these 
results to from an overall hash code for the given Sales_data object.

It is worth noting that we define our hash function to hash all these data members so that our hash function will be compatible with our
definition of operator== for Sales_data. By default, the unordered containers use the specialization of hash that corresponds to the key_type along
with the equality operator on the key type.

Read more:
https://en.cppreference.com/w/cpp/utility/hash
