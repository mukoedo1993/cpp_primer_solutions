using std::swap; //step 1
swap(...);//step 2
is better than using std::swap(...) directly.
Because the latter one allows us to choose a better swap(...).
User could overwrite a non-template swap which is not given by the compiler.
For example, if we have a class cls1 for which compiler doesn't specialize its swap function.
If we define a nontemplate swap for it, then, when we go to step 2, both the nontemplate swap and template swap
exactly match the type requirements. The nontemplate swap will gain the victory, even if the nontemplate swap might not belong to
the std namespace.
However, std::swap(...)will force us to use the one given in the namespace std, which probably is not the best one we want to choose.
