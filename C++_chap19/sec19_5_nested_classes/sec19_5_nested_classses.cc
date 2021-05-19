#include<vector>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>


std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return(ctr > 1) ? word + ending : word;
}

class QueryResult;//declaration needed for return type in the query function
class TextQuery {
	using line_no = std::vector<std::string>::size_type;
	
public:
	class QueryResult;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;//input file
	//map of each word to the set of the lines in which the word appears
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};

//The TextQuery Constructor
//The TextQuery constructor takes an ifstream, which it reads a line at a time:

//read the input file and build the map of lines to line numbers
TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
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
				lines.reset(new std::set<line_no>);//allocate a new set
			lines->insert(n);//insert this line number to the set in wm.
		}
	}
}

//
class TextQuery::QueryResult {
	static int static_mem;
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
//no need to define QueryResult::line_no; a nested class can use a member of its
//enclosing class without needing to qualify the member's name.
	QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
private:
	std::string sought;//word this query represents
	std::shared_ptr<std::set<line_no>>lines;//lines it's on
	std::shared_ptr<std::vector<std::string>>file;//input file
};

int TextQuery::QueryResult::static_mem=1024;

//defining the member 

//return type must indicate that QueryResult is now a nested class
TextQuery::QueryResult
TextQuery::query(const std::string& sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm.
	auto loc = wm.find(sought);

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);//not found
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const TextQuery::QueryResult& qr)
{
	//if the word was found, print the count and all occurences
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines)//for every element in the set
		//don't confound the user with text lines starting at 0
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin()+num)<<std::endl;
	return os;
}
int main(){
	std::ifstream input("sec19_4_3i.txt");
	if(!input.is_open())exit(-1);
	TextQuery Read_in(input);
	std::string key_word;
	while(getline(std::cin,key_word)&&key_word!="$")
	{
		print(std::cout,Read_in.query(key_word));
	}
}

/*
(base) zcw@mukoedo1993:~/C++chap19$ g++ sec19_5_nested_classses.cc
(base) zcw@mukoedo1993:~/C++chap19$ ./a.out
China
China occurs 17 times
        (line 1)In 1951, an agreement between the People's Republic of China and representatives of the Dalai Lama was put into effect. Socialist reforms such as redistribution of land were delayed in Tibet proper. However, eastern Kham and Amdo (western Sichuan and Qinghai provinces in the Chinese administrative hierarchy) were outside the administration of the Tibetan government in Lhasa, and were thus treated more like other Chinese provinces, with land redistribution implemented in full. The Khampas and nomads of Amdo traditionally owned their own land.[13] Armed resistance broke out in Amdo and eastern Kham in June 1956.
        (line 2)Prior to the PLA invasion, relations between Lhasa and the Khampa chieftains had deteriorated, although the Khampa remained spiritually loyal to the Dalai Lama throughout. Because of these strained relations, the Khampa had actually assisted the Chinese in their initial invasion, before becoming the guerrilla resistance they are now known for.[14] Pandatsang Rapga, a pro Kuomintang and pro Republic of China revolutionary Khampa leader, offered the governor of Chamdo, Ngabo Ngawang Jigme, some Khampa fighters in exchange for the Tibetan government recognizing the independence of Kham. 
        (line 13)Despite their early friendship in the 1950s, relations between India and China rapidly degenerated over the unresolved state of their Himalayan border. The border lines, largely set by British surveyors, are unclear and heavily disputed—as was the status of Himalayan kingdoms such as Tibet, Sikkim, Bhutan, and Nepal. That led to a short war in 1962, won by China. China also backs Pakistan in its own disputes with India, and China’s Belt and Road Initiative has stirred Indian fears, especially the so-called China-Pakistan Economic Corridor, a collection of large infrastructure projects.
        (line 15)[For more analysis like this direct to your inbox, sign up for FP’s weekly newsletters South Asia Brief and China Brief.]
        (line 19)There have been no deaths—or shots fired—along the border since an Indian patrol was ambushed by a Chinese one in 1975.There have been no deaths—or shots fired—along the border since an Indian patrol was ambushed by a Chinese one in 1975. But China saw significant clashes with both India and the Soviet Union during the late 1960s, at the height of the Cultural Revolution. In India’s case, that culminated in a brief but bloody clash on the Sikkim-Tibet border, with around hundreds of dead and injured on each side. On the Soviet border, fighting along the Ussuri River saw similar numbers of dead, but tensions escalated far higher than with India, leading to fears of a full-blown war and a possible nuclear exchange that were only alleviated by the highest-level diplomacy. In part, those clashes were driven by political needs on the Chinese side; officers and soldiers alike felt the need to demonstrate their Maoist enthusiasm, leading to such actions as swimming across the river waving Mao Zedong’s Little Red Book.
        (line 21)A Chinese soldier gestures as he stands near an Indian soldier on the Chinese side of the ancient Nathu La border crossing between India and China on July 10, 2008.
        (line 22)Why India and China Are Sparring
        (line 26)India has announced that “both sides” are trying to de-escalate the situation, but it has accused China of deliberately violating the border and reneging on agreements made in recent talks between the two sides. China’s response was more demanding, accusing India of “deliberately initiating physical attacks” in a territory—the Galwan Valley in Ladakh that is claimed by both sides—that has “always been ours.” Army officers are meeting to try to resolve the situation.
        (line 27)While the 2017 Doklam crisis was successfully defused—and was followed by a summit between Chinese President Xi Jinping and Indian Prime Minister Narendra Modi in Wuhan, China—recent events could easily spiral out of control. If there are indeed a high number of deaths from Monday’s skirmish, pressure to react and exact revenge may build. The coronavirus has produced heightened political uncertainty in China, leading to a newly aggressive form of “Wolf Warrior” diplomacy—named after a Rambo-esque film that was a blockbuster in China but a flop elsewhere. Chinese officials are under considerable pressure to be performatively nationalist; moderation and restraint are becoming increasingly dangerous for careers.
        (line 28)On the Indian side, there is increasing nervousness about how Beijing has encircled the subcontinent. China counts Pakistan as a key ally; it has growing stakes in Sri Lanka and Nepal, two countries that have drifted away from India in recent years; and it has made huge infrastructure investments in Bangladesh. Meanwhile, much has changed since the last time India and China had deadly clashes in the 1960s and ’70s, when the two countries had similarly sized economies; today, China’s GDP is five times that of India, and it spends four times as much on defense.
        (line 29)There will likely be a business impact following the latest clash. Indians, for example, have recently mobilized to boycott Chinese goods, as evidenced by a recent app “Remove China Apps” that briefly topped downloads on India’s Google Play Store before the Silicon Valley giant stepped in to ban the app.
        (line 30)Heightened tensions also put Indians in China at risk. Although numbers are somewhat reduced due to the coronavirus crisis, there is a substantial business and student community in the country. During the Doklam crisis, the Beijing police lightly monitored and made home visits to Indians in the city.
        (line 34)China resolved its border squabbles with Russia and other Soviet successor states in the 1990s and 2000s through a serious diplomatic push on both sides and mass exchanges of territory, and they’ve been essentially a nonissue since then. But although the area involved was much larger, the Himalayan territorial disputes are much more sensitive and harder to resolve.
        (line 52)Why Is China Downplaying Its Border Clash With India?
        (line 53)Slaughter in the East China Sea
        (line 54)China Is Pushing India Closer to the United States
        (line 55)Why We Should Worry About China and India’s Border Skirmishes
$
*/