#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
//exercise 16_22.cpp
//Update: add a DebugDelete:
int i_global=0;
int j_global=0;
class DebugDelete{
    public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}
    template<class T>void operator()(T *p)const &
    {os<<"const & deleting unique_ptr"<<std::endl;delete p;i_global++;
    std::cout<<i_global;}
     template<class T>void operator()(T *p)&&
    {os<<"&& deleting unique_ptr"<<std::endl;delete p;j_global++;}

   

    private:
    std::ostream &os;
};

using line_no = std::vector<std::string>::size_type;
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
class TextQuery {
public:

	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};
TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>,DebugDelete())
{
	std::string text;
	while (getline(is, text))//for each line in the file
	{
		file->push_back(text);//remember this line of text
		unsigned n = file->size() - 1;//the current line number
		std::istringstream line(text);//separate the line into words
		std::string word;
		while (line >> word)//for each word in that line
		{
			//if word isn't already in wm, subscripting adds a new entry
			auto& lines = wm[word];//lines is a shared_ptr
			if (!lines)
				lines.reset(new std::set<line_no>,DebugDelete());//allocate a new set
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
        std::set<line_no>::iterator begin()const{return lines->begin();}
        std::set<line_no>::iterator cbegin()const{return lines->cbegin();}
          std::set<line_no>::iterator end()const{return lines->end();}
        std::set<line_no>::iterator cend()const{return lines->cend();}

        std::shared_ptr<std::vector<std::string>> get_file(){return file;}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
	std::shared_ptr<std::vector<std::string>>file;//input file
};

QueryResult
TextQuery::query(const std::string& sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm.
	auto loc = wm.find(sought);

	if (loc == wm.end())//Iterator to an element with key equivalent to key. 
    //If no such element is found, past-the-end (see end()) iterator is returned.
		return QueryResult(sought, nodata, file);//not found
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin()+num)<<std::endl;
	return os;
}


class Query_base{
    friend class Query;
    protected: 
    using line_no=TextQuery::line_no;//use in the eval functions
    virtual ~Query_base()=default;
    private:
    virtual QueryResult eval(const TextQuery&)const=0;
    virtual std::string rep()const=0;
};
class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t)const
    {return q->eval(t);}
    std::string rep()const {return q->rep();}
    private:
    Query(Query_base *query):q(query){}

    Query_base *q;
};

std::ostream& 
operator<<(std::ostream &os,const Query &query)
{
    return os<<query.rep();
}

class WordQuery: public Query_base{
    friend class Query;//Query uses the WordQuery constructor
    WordQuery(const std::string&s):query_word(s){}
    QueryResult eval(const TextQuery &t)const
    {return t.query(query_word);}
    std::string rep()const override{return query_word;}
    std::string query_word;//word for which to search

};
inline
Query::Query(const std::string&s):q(new WordQuery(s)){}

class NotQuery: public Query_base{
        friend Query operator~(const Query &);//here we are not the user for Query, so ok.
        NotQuery(const Query&q):query(q){}
        std::string rep()const{return "~("+query.rep()+")";}
        QueryResult eval(const TextQuery&)const;
        Query query;
};

inline Query operator~(const Query &operand)
{
    return (new NotQuery(operand));
}
class BinaryQuery: public Query_base{
    protected:
    BinaryQuery(const Query &l,const Query &r,std::string s):
    lhs(l),rhs(r),opSym(s){}
    std::string rep()const{return "("+lhs.rep()+" "
    +opSym+" "
      +rhs.rep()+")"; }
      Query lhs,rhs;//right_ and left_hand operands
      std::string opSym;//name of the operator
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query&left,const Query&right):
    BinaryQuery(left, right,"&"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query&lhs,const Query&rhs)
{
    return (new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):
    BinaryQuery(left,right,"|"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{ 
    return new OrQuery(lhs,rhs);
}

//OrQuery::eval
//A OrQuery represents the union of the results for its two operands, which
//we obtain by calling eval on each of its operands. Because these operands
//are Query objects, calling eval is to call to Query::eval, which in turn makes a 
//virtual call to eval on the underlying Query_base object. Each of these calls yields
//a QueryResult representing the line numbers in which its operand apperas. We'll combine
//this number in a new set:

//returns the union of its operands' result sets
QueryResult
OrQuery::eval(const TextQuery& text)const
{

   //virtual calls through the Query operands to get result sets for the operands
   auto left=lhs.eval(text),right=rhs.eval(text);
   //set to hold the intersection of lfet and right
   auto ret_lines=std::make_shared<std::set<line_no>>();
   //write the intersection of two two ranges to a destination iterator
   set_union(left.begin(),left.end(),
   right.begin(),right.end(),
   inserter(*ret_lines,ret_lines->begin()));
   return QueryResult(rep(),ret_lines,left.get_file());
}



/*AndQuery::eval*/
//The AndQuery version of eval is similar to OrQuery version, excpet it call a library algorithm
//to find the lines in common to both queries.
QueryResult
AndQuery::eval(const TextQuery& text)const
{
   //virtual calls through the Query operands to get result sets for the operands
   auto left=lhs.eval(text),right=rhs.eval(text);
   //set to hold the intersection of lfet and right
   auto ret_lines=std::make_shared<std::set<line_no>>();
   //write the intersection of two two ranges to a destination iterator
   set_intersection(left.begin(),left.end(),
   right.begin(),right.end(),
   inserter(*ret_lines,ret_lines->begin()));
   return QueryResult(rep(),ret_lines,left.get_file());
}

/*NotQuery::eval*/
//NotQuery finds each line of the text within which the operand is not found
//returns the lines not in its operand's result set
QueryResult
NotQuery::eval(const TextQuery& text)const
{
   //virtual call to eval through the Query operand
   auto result=query.eval(text);
   //start out with an empty result set
   
   //we have to iterate through the lines on which our operand appears
   auto beg=result.begin(),end=result.end();
   //for each line in the input file, if that line is not in result,
   //add that line number to ret_lines
   auto sz=result.get_file()->size();
   std::set<line_no>st1;
   for(line_no ln1=0;ln1<sz;ln1++)
   st1.insert(ln1);
   std::set<line_no>st2;
   set_difference(st1.begin(),st1.end(),beg,end,inserter(st2,st2.begin()));
   auto ret_lines=std::make_shared<std::set<line_no>>(st2);
      return QueryResult(rep(),ret_lines,result.get_file());
    }

//exercise 15_41: 
int main(){
    std::ifstream input1("ex16_22i.txt");
    if(!input1.is_open()){std::cerr<<"Error! File not found!\n";exit(-1);}
   
    std::ofstream output1("ex16_22o1.txt",std::ofstream::out| std::ofstream::app);
     output1<<std::endl<<"Our first requirement: "<<std::endl;
    output1<<"Time: "<<__TIME__<<"\nDate: "<<__DATE__<<"\n\n";
    TextQuery Ob1_(input1);
   
      Query Ob1("a"),Ob2("to"),Ob3("is");
    Query q(Ob1&Ob2|~(Ob3));
    Query q1(Ob1&Ob2&(~Ob3));
    QueryResult rslt1=q.eval(Ob1_);
       QueryResult rslt2=q1.eval(Ob1_);
    print(output1,rslt1);
    output1<<std::endl<<"Our second requirement: "<<std::endl;
    print(output1,rslt2); 
}

/*
const & deleting unique_ptr
1const & deleting unique_ptr
2const & deleting unique_ptr
3const & deleting unique_ptr
4const & deleting unique_ptr
5const & deleting unique_ptr
6const & deleting unique_ptr
7const & deleting unique_ptr
8const & deleting unique_ptr
9const & deleting unique_ptr
10const & deleting unique_ptr
11const & deleting unique_ptr
12const & deleting unique_ptr
13const & deleting unique_ptr
14const & deleting unique_ptr
15const & deleting unique_ptr
16const & deleting unique_ptr
17const & deleting unique_ptr
18const & deleting unique_ptr
19const & deleting unique_ptr
20const & deleting unique_ptr
21const & deleting unique_ptr
22const & deleting unique_ptr
23const & deleting unique_ptr
24const & deleting unique_ptr
25const & deleting unique_ptr
26const & deleting unique_ptr
27const & deleting unique_ptr
28const & deleting unique_ptr
29const & deleting unique_ptr
30const & deleting unique_ptr
31const & deleting unique_ptr
32const & deleting unique_ptr
33const & deleting unique_ptr
34const & deleting unique_ptr
35const & deleting unique_ptr
36const & deleting unique_ptr
37const & deleting unique_ptr
38const & deleting unique_ptr
39const & deleting unique_ptr
40const & deleting unique_ptr
41const & deleting unique_ptr
42const & deleting unique_ptr
43const & deleting unique_ptr
44const & deleting unique_ptr
45const & deleting unique_ptr
46const & deleting unique_ptr
47const & deleting unique_ptr
48const & deleting unique_ptr
49const & deleting unique_ptr
50const & deleting unique_ptr
51const & deleting unique_ptr
52const & deleting unique_ptr
53const & deleting unique_ptr
54const & deleting unique_ptr
55const & deleting unique_ptr
56const & deleting unique_ptr
57const & deleting unique_ptr
58const & deleting unique_ptr
59const & deleting unique_ptr
60const & deleting unique_ptr
61const & deleting unique_ptr
62const & deleting unique_ptr
63const & deleting unique_ptr
64const & deleting unique_ptr
65const & deleting unique_ptr
66const & deleting unique_ptr
67const & deleting unique_ptr
68const & deleting unique_ptr
69const & deleting unique_ptr
70const & deleting unique_ptr
71const & deleting unique_ptr
72const & deleting unique_ptr
73const & deleting unique_ptr
74const & deleting unique_ptr
75const & deleting unique_ptr
76const & deleting unique_ptr
77const & deleting unique_ptr
78const & deleting unique_ptr
79const & deleting unique_ptr
80const & deleting unique_ptr
81const & deleting unique_ptr
82const & deleting unique_ptr
83const & deleting unique_ptr
84const & deleting unique_ptr
85const & deleting unique_ptr
86const & deleting unique_ptr
87const & deleting unique_ptr
88const & deleting unique_ptr
89const & deleting unique_ptr
90const & deleting unique_ptr
91const & deleting unique_ptr
92const & deleting unique_ptr
93const & deleting unique_ptr
94const & deleting unique_ptr
95const & deleting unique_ptr
96const & deleting unique_ptr
97const & deleting unique_ptr
98const & deleting unique_ptr
99const & deleting unique_ptr
100const & deleting unique_ptr
101const & deleting unique_ptr
102const & deleting unique_ptr
103const & deleting unique_ptr
104const & deleting unique_ptr
105const & deleting unique_ptr
106const & deleting unique_ptr
107const & deleting unique_ptr
108const & deleting unique_ptr
109const & deleting unique_ptr
110const & deleting unique_ptr
111const & deleting unique_ptr
112const & deleting unique_ptr
113const & deleting unique_ptr
114const & deleting unique_ptr
115const & deleting unique_ptr
116const & deleting unique_ptr
117const & deleting unique_ptr
118const & deleting unique_ptr
119const & deleting unique_ptr
120const & deleting unique_ptr
121const & deleting unique_ptr
122const & deleting unique_ptr
123const & deleting unique_ptr
124const & deleting unique_ptr
125const & deleting unique_ptr
126const & deleting unique_ptr
127const & deleting unique_ptr
128const & deleting unique_ptr
129const & deleting unique_ptr
130const & deleting unique_ptr
131const & deleting unique_ptr
132const & deleting unique_ptr
133const & deleting unique_ptr
134const & deleting unique_ptr
135const & deleting unique_ptr
136const & deleting unique_ptr
137const & deleting unique_ptr
138const & deleting unique_ptr
139const & deleting unique_ptr
140const & deleting unique_ptr
141const & deleting unique_ptr
142const & deleting unique_ptr
143const & deleting unique_ptr
144const & deleting unique_ptr
145const & deleting unique_ptr
146const & deleting unique_ptr
147const & deleting unique_ptr
148const & deleting unique_ptr
149const & deleting unique_ptr
150const & deleting unique_ptr
151const & deleting unique_ptr
152const & deleting unique_ptr
153const & deleting unique_ptr
154const & deleting unique_ptr
155const & deleting unique_ptr
156const & deleting unique_ptr
157const & deleting unique_ptr
158const & deleting unique_ptr
159const & deleting unique_ptr
160const & deleting unique_ptr
161const & deleting unique_ptr
162const & deleting unique_ptr
163const & deleting unique_ptr
164const & deleting unique_ptr
165const & deleting unique_ptr
166const & deleting unique_ptr
167const & deleting unique_ptr
168const & deleting unique_ptr
169const & deleting unique_ptr
170const & deleting unique_ptr
171const & deleting unique_ptr
172const & deleting unique_ptr
173const & deleting unique_ptr
174const & deleting unique_ptr
175const & deleting unique_ptr
176const & deleting unique_ptr
177const & deleting unique_ptr
178const & deleting unique_ptr
179const & deleting unique_ptr
180const & deleting unique_ptr
181const & deleting unique_ptr
182const & deleting unique_ptr
183const & deleting unique_ptr
184const & deleting unique_ptr
185const & deleting unique_ptr
186const & deleting unique_ptr
187const & deleting unique_ptr
188const & deleting unique_ptr
189const & deleting unique_ptr
190const & deleting unique_ptr
191const & deleting unique_ptr
192const & deleting unique_ptr
193const & deleting unique_ptr
194const & deleting unique_ptr
195const & deleting unique_ptr
196const & deleting unique_ptr
197const & deleting unique_ptr
198const & deleting unique_ptr
199const & deleting unique_ptr
200const & deleting unique_ptr
201const & deleting unique_ptr
202const & deleting unique_ptr
203const & deleting unique_ptr
204const & deleting unique_ptr
205const & deleting unique_ptr
206const & deleting unique_ptr
207const & deleting unique_ptr
208const & deleting unique_ptr
209const & deleting unique_ptr
210const & deleting unique_ptr
211const & deleting unique_ptr
212const & deleting unique_ptr
213const & deleting unique_ptr
214const & deleting unique_ptr
215const & deleting unique_ptr
216const & deleting unique_ptr
217const & deleting unique_ptr
218const & deleting unique_ptr
219const & deleting unique_ptr
220const & deleting unique_ptr
221const & deleting unique_ptr
222const & deleting unique_ptr
223const & deleting unique_ptr
224const & deleting unique_ptr
225const & deleting unique_ptr
226const & deleting unique_ptr
227const & deleting unique_ptr
228const & deleting unique_ptr
229const & deleting unique_ptr
230const & deleting unique_ptr
231const & deleting unique_ptr
232const & deleting unique_ptr
233const & deleting unique_ptr
234const & deleting unique_ptr
235const & deleting unique_ptr
236const & deleting unique_ptr
237const & deleting unique_ptr
238const & deleting unique_ptr
239const & deleting unique_ptr
240const & deleting unique_ptr
241const & deleting unique_ptr
242const & deleting unique_ptr
243const & deleting unique_ptr
244const & deleting unique_ptr
245const & deleting unique_ptr
246const & deleting unique_ptr
247const & deleting unique_ptr
248const & deleting unique_ptr
249const & deleting unique_ptr
250const & deleting unique_ptr
251const & deleting unique_ptr
252const & deleting unique_ptr
253const & deleting unique_ptr
254const & deleting unique_ptr
255const & deleting unique_ptr
256const & deleting unique_ptr
257const & deleting unique_ptr
258const & deleting unique_ptr
259const & deleting unique_ptr
260const & deleting unique_ptr
261const & deleting unique_ptr
262const & deleting unique_ptr
263const & deleting unique_ptr
264const & deleting unique_ptr
265const & deleting unique_ptr
266const & deleting unique_ptr
267const & deleting unique_ptr
268const & deleting unique_ptr
269const & deleting unique_ptr
270const & deleting unique_ptr
271const & deleting unique_ptr
272const & deleting unique_ptr
273const & deleting unique_ptr
274const & deleting unique_ptr
275const & deleting unique_ptr
276const & deleting unique_ptr
277const & deleting unique_ptr
278const & deleting unique_ptr
279const & deleting unique_ptr
280const & deleting unique_ptr
281const & deleting unique_ptr
282const & deleting unique_ptr
283const & deleting unique_ptr
284const & deleting unique_ptr
285const & deleting unique_ptr
286const & deleting unique_ptr
287const & deleting unique_ptr
288const & deleting unique_ptr
289const & deleting unique_ptr
290const & deleting unique_ptr
291const & deleting unique_ptr
292const & deleting unique_ptr
293const & deleting unique_ptr
294const & deleting unique_ptr
295const & deleting unique_ptr
296const & deleting unique_ptr
297const & deleting unique_ptr
298const & deleting unique_ptr
299const & deleting unique_ptr
300const & deleting unique_ptr
301const & deleting unique_ptr
302const & deleting unique_ptr
303const & deleting unique_ptr
304const & deleting unique_ptr
305const & deleting unique_ptr
306const & deleting unique_ptr
307const & deleting unique_ptr
308const & deleting unique_ptr
309const & deleting unique_ptr
310const & deleting unique_ptr
311const & deleting unique_ptr
312const & deleting unique_ptr
313const & deleting unique_ptr
314const & deleting unique_ptr
315const & deleting unique_ptr
316const & deleting unique_ptr
317const & deleting unique_ptr
318const & deleting unique_ptr
319const & deleting unique_ptr
320const & deleting unique_ptr
321const & deleting unique_ptr
322const & deleting unique_ptr
323const & deleting unique_ptr
324const & deleting unique_ptr
325const & deleting unique_ptr
326const & deleting unique_ptr
327const & deleting unique_ptr
328const & deleting unique_ptr
329const & deleting unique_ptr
330const & deleting unique_ptr
331const & deleting unique_ptr
332const & deleting unique_ptr
333const & deleting unique_ptr
334const & deleting unique_ptr
335const & deleting unique_ptr
336const & deleting unique_ptr
337const & deleting unique_ptr
338const & deleting unique_ptr
339const & deleting unique_ptr
340const & deleting unique_ptr
341const & deleting unique_ptr
342const & deleting unique_ptr
343const & deleting unique_ptr
344const & deleting unique_ptr
345const & deleting unique_ptr
346const & deleting unique_ptr
347const & deleting unique_ptr
348const & deleting unique_ptr
349const & deleting unique_ptr
350const & deleting unique_ptr
351const & deleting unique_ptr
352const & deleting unique_ptr
353const & deleting unique_ptr
354const & deleting unique_ptr
355const & deleting unique_ptr
356const & deleting unique_ptr
357const & deleting unique_ptr
358const & deleting unique_ptr
359const & deleting unique_ptr
360const & deleting unique_ptr
361const & deleting unique_ptr
362const & deleting unique_ptr
363const & deleting unique_ptr
364const & deleting unique_ptr
365const & deleting unique_ptr
366const & deleting unique_ptr
367const & deleting unique_ptr
368const & deleting unique_ptr
369const & deleting unique_ptr
370const & deleting unique_ptr
371const & deleting unique_ptr
372const & deleting unique_ptr
373const & deleting unique_ptr
374const & deleting unique_ptr
375const & deleting unique_ptr
376const & deleting unique_ptr
377const & deleting unique_ptr
378const & deleting unique_ptr
379const & deleting unique_ptr
380const & deleting unique_ptr
381const & deleting unique_ptr
382const & deleting unique_ptr
383const & deleting unique_ptr
384const & deleting unique_ptr
385const & deleting unique_ptr
386const & deleting unique_ptr
387const & deleting unique_ptr
388const & deleting unique_ptr
389const & deleting unique_ptr
390const & deleting unique_ptr
391const & deleting unique_ptr
392const & deleting unique_ptr
393const & deleting unique_ptr
394const & deleting unique_ptr
395const & deleting unique_ptr
396const & deleting unique_ptr
397const & deleting unique_ptr
398const & deleting unique_ptr
399const & deleting unique_ptr
400const & deleting unique_ptr
401const & deleting unique_ptr
402const & deleting unique_ptr
403const & deleting unique_ptr
404const & deleting unique_ptr
405const & deleting unique_ptr
406const & deleting unique_ptr
407const & deleting unique_ptr
408const & deleting unique_ptr
409const & deleting unique_ptr
410const & deleting unique_ptr
411const & deleting unique_ptr
412const & deleting unique_ptr
413const & deleting unique_ptr
414const & deleting unique_ptr
415const & deleting unique_ptr
416const & deleting unique_ptr
417const & deleting unique_ptr
418const & deleting unique_ptr
419const & deleting unique_ptr
420const & deleting unique_ptr
421const & deleting unique_ptr
422const & deleting unique_ptr
423const & deleting unique_ptr
424const & deleting unique_ptr
425const & deleting unique_ptr
426const & deleting unique_ptr
427const & deleting unique_ptr
428const & deleting unique_ptr
429const & deleting unique_ptr
430const & deleting unique_ptr
431const & deleting unique_ptr
432const & deleting unique_ptr
433const & deleting unique_ptr
434const & deleting unique_ptr
435const & deleting unique_ptr
436const & deleting unique_ptr
437const & deleting unique_ptr
438const & deleting unique_ptr
439const & deleting unique_ptr
440const & deleting unique_ptr
441const & deleting unique_ptr
442const & deleting unique_ptr
443const & deleting unique_ptr
444const & deleting unique_ptr
445const & deleting unique_ptr
446const & deleting unique_ptr
447const & deleting unique_ptr
448const & deleting unique_ptr
449const & deleting unique_ptr
450const & deleting unique_ptr
451const & deleting unique_ptr
452const & deleting unique_ptr
453const & deleting unique_ptr
454const & deleting unique_ptr
455const & deleting unique_ptr
456const & deleting unique_ptr
457const & deleting unique_ptr
458const & deleting unique_ptr
459const & deleting unique_ptr
460const & deleting unique_ptr
461const & deleting unique_ptr
462const & deleting unique_ptr
463const & deleting unique_ptr
464const & deleting unique_ptr
465const & deleting unique_ptr
466const & deleting unique_ptr
467const & deleting unique_ptr
468const & deleting unique_ptr
469const & deleting unique_ptr
470const & deleting unique_ptr
471const & deleting unique_ptr
472const & deleting unique_ptr
473const & deleting unique_ptr
474const & deleting unique_ptr
475const & deleting unique_ptr
476const & deleting unique_ptr
477const & deleting unique_ptr
478const & deleting unique_ptr
479const & deleting unique_ptr
480const & deleting unique_ptr
481const & deleting unique_ptr
482const & deleting unique_ptr
483const & deleting unique_ptr
484const & deleting unique_ptr
485const & deleting unique_ptr
486const & deleting unique_ptr
487const & deleting unique_ptr
488const & deleting unique_ptr
489const & deleting unique_ptr
490const & deleting unique_ptr
491const & deleting unique_ptr
492const & deleting unique_ptr
493const & deleting unique_ptr
494const & deleting unique_ptr
495const & deleting unique_ptr
496const & deleting unique_ptr
497const & deleting unique_ptr
498const & deleting unique_ptr
499const & deleting unique_ptr
500const & deleting unique_ptr
501const & deleting unique_ptr
502const & deleting unique_ptr
503const & deleting unique_ptr
504const & deleting unique_ptr
505const & deleting unique_ptr
506const & deleting unique_ptr
507const & deleting unique_ptr
508const & deleting unique_ptr
509const & deleting unique_ptr
510const & deleting unique_ptr
511const & deleting unique_ptr
512const & deleting unique_ptr
513const & deleting unique_ptr
514const & deleting unique_ptr
515const & deleting unique_ptr
516const & deleting unique_ptr
517const & deleting unique_ptr
518const & deleting unique_ptr
519const & deleting unique_ptr
520const & deleting unique_ptr
521const & deleting unique_ptr
522const & deleting unique_ptr
523const & deleting unique_ptr
524const & deleting unique_ptr
525const & deleting unique_ptr
526const & deleting unique_ptr
527const & deleting unique_ptr
528const & deleting unique_ptr
529const & deleting unique_ptr
530const & deleting unique_ptr
531const & deleting unique_ptr
532const & deleting unique_ptr
533const & deleting unique_ptr
534const & deleting unique_ptr
535const & deleting unique_ptr
536const & deleting unique_ptr
537const & deleting unique_ptr
538const & deleting unique_ptr
539const & deleting unique_ptr
540const & deleting unique_ptr
541const & deleting unique_ptr
542const & deleting unique_ptr
543const & deleting unique_ptr
544const & deleting unique_ptr
545const & deleting unique_ptr
546const & deleting unique_ptr
547const & deleting unique_ptr
548const & deleting unique_ptr
549const & deleting unique_ptr
550const & deleting unique_ptr
551const & deleting unique_ptr
552const & deleting unique_ptr
553const & deleting unique_ptr
554const & deleting unique_ptr
555const & deleting unique_ptr
556const & deleting unique_ptr
557const & deleting unique_ptr
558const & deleting unique_ptr
559const & deleting unique_ptr
560const & deleting unique_ptr
561const & deleting unique_ptr
562const & deleting unique_ptr
563const & deleting unique_ptr
564const & deleting unique_ptr
565const & deleting unique_ptr
566const & deleting unique_ptr
567const & deleting unique_ptr
568const & deleting unique_ptr
569const & deleting unique_ptr
570const & deleting unique_ptr
571const & deleting unique_ptr
572const & deleting unique_ptr
573const & deleting unique_ptr
574const & deleting unique_ptr
575const & deleting unique_ptr
576const & deleting unique_ptr
577const & deleting unique_ptr
578const & deleting unique_ptr
579const & deleting unique_ptr
580const & deleting unique_ptr
581const & deleting unique_ptr
582const & deleting unique_ptr
583const & deleting unique_ptr
584const & deleting unique_ptr
585const & deleting unique_ptr
586const & deleting unique_ptr
587const & deleting unique_ptr
588const & deleting unique_ptr
589const & deleting unique_ptr
590const & deleting unique_ptr
591const & deleting unique_ptr
592const & deleting unique_ptr
593const & deleting unique_ptr
594const & deleting unique_ptr
595const & deleting unique_ptr
596const & deleting unique_ptr
597const & deleting unique_ptr
598const & deleting unique_ptr
599const & deleting unique_ptr
600const & deleting unique_ptr
601const & deleting unique_ptr
602const & deleting unique_ptr
603const & deleting unique_ptr
604const & deleting unique_ptr
605const & deleting unique_ptr
606const & deleting unique_ptr
607const & deleting unique_ptr
608const & deleting unique_ptr
609const & deleting unique_ptr
610const & deleting unique_ptr
611const & deleting unique_ptr
612const & deleting unique_ptr
613const & deleting unique_ptr
614const & deleting unique_ptr
615const & deleting unique_ptr
616const & deleting unique_ptr
617const & deleting unique_ptr
618const & deleting unique_ptr
619const & deleting unique_ptr
620const & deleting unique_ptr
621const & deleting unique_ptr
622const & deleting unique_ptr
623const & deleting unique_ptr
624const & deleting unique_ptr
625const & deleting unique_ptr
626const & deleting unique_ptr
627const & deleting unique_ptr
628const & deleting unique_ptr
629const & deleting unique_ptr
630const & deleting unique_ptr
631const & deleting unique_ptr
632const & deleting unique_ptr
633const & deleting unique_ptr
634const & deleting unique_ptr
635const & deleting unique_ptr
636const & deleting unique_ptr
637const & deleting unique_ptr
638const & deleting unique_ptr
639const & deleting unique_ptr
640const & deleting unique_ptr
641const & deleting unique_ptr
642const & deleting unique_ptr
643const & deleting unique_ptr
644const & deleting unique_ptr
645const & deleting unique_ptr
646const & deleting unique_ptr
647const & deleting unique_ptr
648const & deleting unique_ptr
649const & deleting unique_ptr
650const & deleting unique_ptr
651const & deleting unique_ptr
652const & deleting unique_ptr
653const & deleting unique_ptr
654const & deleting unique_ptr
655const & deleting unique_ptr
656const & deleting unique_ptr
657const & deleting unique_ptr
658const & deleting unique_ptr
659const & deleting unique_ptr
660const & deleting unique_ptr
661const & deleting unique_ptr
662const & deleting unique_ptr
663const & deleting unique_ptr
664const & deleting unique_ptr
665const & deleting unique_ptr
666const & deleting unique_ptr
667const & deleting unique_ptr
668const & deleting unique_ptr
669const & deleting unique_ptr
670const & deleting unique_ptr
671const & deleting unique_ptr
672const & deleting unique_ptr
673const & deleting unique_ptr
674const & deleting unique_ptr
675const & deleting unique_ptr
676const & deleting unique_ptr
677const & deleting unique_ptr
678const & deleting unique_ptr
679const & deleting unique_ptr
680const & deleting unique_ptr
681const & deleting unique_ptr
682const & deleting unique_ptr
683const & deleting unique_ptr
684const & deleting unique_ptr
685const & deleting unique_ptr
686const & deleting unique_ptr
687const & deleting unique_ptr
688const & deleting unique_ptr
689const & deleting unique_ptr
690const & deleting unique_ptr
691const & deleting unique_ptr
692const & deleting unique_ptr
693const & deleting unique_ptr
694const & deleting unique_ptr
695const & deleting unique_ptr
696const & deleting unique_ptr
697const & deleting unique_ptr
698const & deleting unique_ptr
699const & deleting unique_ptr
700const & deleting unique_ptr
701const & deleting unique_ptr
702const & deleting unique_ptr
703const & deleting unique_ptr
704const & deleting unique_ptr
705const & deleting unique_ptr
706const & deleting unique_ptr
707const & deleting unique_ptr
708const & deleting unique_ptr
709const & deleting unique_ptr
710const & deleting unique_ptr
711const & deleting unique_ptr
712const & deleting unique_ptr
713const & deleting unique_ptr
714const & deleting unique_ptr
715const & deleting unique_ptr
716const & deleting unique_ptr
717const & deleting unique_ptr
718const & deleting unique_ptr
719const & deleting unique_ptr
720const & deleting unique_ptr
721const & deleting unique_ptr
722const & deleting unique_ptr
723const & deleting unique_ptr
724const & deleting unique_ptr
725const & deleting unique_ptr
726const & deleting unique_ptr
727const & deleting unique_ptr
728const & deleting unique_ptr
729const & deleting unique_ptr
730const & deleting unique_ptr
731const & deleting unique_ptr
732const & deleting unique_ptr
733const & deleting unique_ptr
734const & deleting unique_ptr
735const & deleting unique_ptr
736const & deleting unique_ptr
737const & deleting unique_ptr
738const & deleting unique_ptr
739const & deleting unique_ptr
740const & deleting unique_ptr
741const & deleting unique_ptr
742const & deleting unique_ptr
743const & deleting unique_ptr
744const & deleting unique_ptr
745const & deleting unique_ptr
746const & deleting unique_ptr
747const & deleting unique_ptr
748const & deleting unique_ptr
749const & deleting unique_ptr
750const & deleting unique_ptr
751const & deleting unique_ptr
752const & deleting unique_ptr
753const & deleting unique_ptr
754const & deleting unique_ptr
755const & deleting unique_ptr
756const & deleting unique_ptr
757const & deleting unique_ptr
758const & deleting unique_ptr
759const & deleting unique_ptr
760const & deleting unique_ptr
761const & deleting unique_ptr
762const & deleting unique_ptr
763const & deleting unique_ptr
764const & deleting unique_ptr
765const & deleting unique_ptr
766const & deleting unique_ptr
767const & deleting unique_ptr
768const & deleting unique_ptr
769const & deleting unique_ptr
770const & deleting unique_ptr
771const & deleting unique_ptr
772const & deleting unique_ptr
773const & deleting unique_ptr
774const & deleting unique_ptr
775const & deleting unique_ptr
776const & deleting unique_ptr
777const & deleting unique_ptr
778const & deleting unique_ptr
779const & deleting unique_ptr
780const & deleting unique_ptr
781const & deleting unique_ptr
782const & deleting unique_ptr
783const & deleting unique_ptr
784const & deleting unique_ptr
785const & deleting unique_ptr
786const & deleting unique_ptr
787const & deleting unique_ptr
788const & deleting unique_ptr
789const & deleting unique_ptr
790const & deleting unique_ptr
791const & deleting unique_ptr
792const & deleting unique_ptr
793const & deleting unique_ptr
794const & deleting unique_ptr
795const & deleting unique_ptr
796const & deleting unique_ptr
797const & deleting unique_ptr
798const & deleting unique_ptr
799const & deleting unique_ptr
800const & deleting unique_ptr
801const & deleting unique_ptr
802const & deleting unique_ptr
803const & deleting unique_ptr
804const & deleting unique_ptr
805const & deleting unique_ptr
806const & deleting unique_ptr
807const & deleting unique_ptr
808const & deleting unique_ptr
809const & deleting unique_ptr
810const & deleting unique_ptr
811const & deleting unique_ptr
812const & deleting unique_ptr
813const & deleting unique_ptr
814const & deleting unique_ptr
815const & deleting unique_ptr
816const & deleting unique_ptr
817const & deleting unique_ptr
818const & deleting unique_ptr
819const & deleting unique_ptr
820const & deleting unique_ptr
821const & deleting unique_ptr
822const & deleting unique_ptr
823const & deleting unique_ptr
824const & deleting unique_ptr
825const & deleting unique_ptr
826const & deleting unique_ptr
827const & deleting unique_ptr
828const & deleting unique_ptr
829const & deleting unique_ptr
830const & deleting unique_ptr
831const & deleting unique_ptr
832const & deleting unique_ptr
833const & deleting unique_ptr
834const & deleting unique_ptr
835const & deleting unique_ptr
836const & deleting unique_ptr
837const & deleting unique_ptr
838const & deleting unique_ptr
839const & deleting unique_ptr
840const & deleting unique_ptr
841const & deleting unique_ptr
842const & deleting unique_ptr
843const & deleting unique_ptr
844const & deleting unique_ptr
845const & deleting unique_ptr
846const & deleting unique_ptr
847const & deleting unique_ptr
848const & deleting unique_ptr
849const & deleting unique_ptr
850const & deleting unique_ptr
851const & deleting unique_ptr
852const & deleting unique_ptr
853const & deleting unique_ptr
854const & deleting unique_ptr
855const & deleting unique_ptr
856const & deleting unique_ptr
857const & deleting unique_ptr
858const & deleting unique_ptr
859const & deleting unique_ptr
860const & deleting unique_ptr
861const & deleting unique_ptr
862const & deleting unique_ptr
863const & deleting unique_ptr
864const & deleting unique_ptr
865const & deleting unique_ptr
866const & deleting unique_ptr
867const & deleting unique_ptr
868const & deleting unique_ptr
869const & deleting unique_ptr
870const & deleting unique_ptr
871const & deleting unique_ptr
872const & deleting unique_ptr
873const & deleting unique_ptr
874const & deleting unique_ptr
875const & deleting unique_ptr
876const & deleting unique_ptr
877const & deleting unique_ptr
878const & deleting unique_ptr
879const & deleting unique_ptr
880const & deleting unique_ptr
881const & deleting unique_ptr
882const & deleting unique_ptr
883const & deleting unique_ptr
884const & deleting unique_ptr
885const & deleting unique_ptr
886const & deleting unique_ptr
887const & deleting unique_ptr
888const & deleting unique_ptr
889const & deleting unique_ptr
890const & deleting unique_ptr
891const & deleting unique_ptr
892const & deleting unique_ptr
893const & deleting unique_ptr
894const & deleting unique_ptr
895const & deleting unique_ptr
896const & deleting unique_ptr
897const & deleting unique_ptr
898const & deleting unique_ptr
899const & deleting unique_ptr
900const & deleting unique_ptr
901const & deleting unique_ptr
902const & deleting unique_ptr
903const & deleting unique_ptr
904const & deleting unique_ptr
905const & deleting unique_ptr
906const & deleting unique_ptr
907const & deleting unique_ptr
908const & deleting unique_ptr
909const & deleting unique_ptr
910const & deleting unique_ptr
911const & deleting unique_ptr
912const & deleting unique_ptr
913const & deleting unique_ptr
914const & deleting unique_ptr
915const & deleting unique_ptr
916const & deleting unique_ptr
917const & deleting unique_ptr
918const & deleting unique_ptr
919const & deleting unique_ptr
920const & deleting unique_ptr
921const & deleting unique_ptr
922const & deleting unique_ptr
923const & deleting unique_ptr
924const & deleting unique_ptr
925const & deleting unique_ptr
926const & deleting unique_ptr
927const & deleting unique_ptr
928const & deleting unique_ptr
929const & deleting unique_ptr
930const & deleting unique_ptr
931const & deleting unique_ptr
932const & deleting unique_ptr
933const & deleting unique_ptr
934const & deleting unique_ptr
935const & deleting unique_ptr
936const & deleting unique_ptr
937const & deleting unique_ptr
938const & deleting unique_ptr
939const & deleting unique_ptr
940const & deleting unique_ptr
941const & deleting unique_ptr
942const & deleting unique_ptr
943const & deleting unique_ptr
944const & deleting unique_ptr
945const & deleting unique_ptr
946const & deleting unique_ptr
947const & deleting unique_ptr
948const & deleting unique_ptr
949const & deleting unique_ptr
950const & deleting unique_ptr
951const & deleting unique_ptr
952const & deleting unique_ptr
953const & deleting unique_ptr
954const & deleting unique_ptr
955const & deleting unique_ptr
956const & deleting unique_ptr
957const & deleting unique_ptr
958const & deleting unique_ptr
959const & deleting unique_ptr
960const & deleting unique_ptr
961const & deleting unique_ptr
962const & deleting unique_ptr
963const & deleting unique_ptr
964const & deleting unique_ptr
965const & deleting unique_ptr
966const & deleting unique_ptr
967const & deleting unique_ptr
968const & deleting unique_ptr
969const & deleting unique_ptr
970const & deleting unique_ptr
971const & deleting unique_ptr
972const & deleting unique_ptr
973const & deleting unique_ptr
974const & deleting unique_ptr
975const & deleting unique_ptr
976const & deleting unique_ptr
977const & deleting unique_ptr
978const & deleting unique_ptr
979const & deleting unique_ptr
980const & deleting unique_ptr
981const & deleting unique_ptr
982const & deleting unique_ptr
983const & deleting unique_ptr
984const & deleting unique_ptr
985const & deleting unique_ptr
986const & deleting unique_ptr
987const & deleting unique_ptr
988const & deleting unique_ptr
989const & deleting unique_ptr
990const & deleting unique_ptr
991const & deleting unique_ptr
992const & deleting unique_ptr
993const & deleting unique_ptr
994const & deleting unique_ptr
995const & deleting unique_ptr
996const & deleting unique_ptr
997const & deleting unique_ptr
998const & deleting unique_ptr
999const & deleting unique_ptr
1000const & deleting unique_ptr
1001
*/