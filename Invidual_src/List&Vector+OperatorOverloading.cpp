#include <iostream>
#include <list> //good at modifying
#include <vector>//good at searching

using std::string;
using std::list;
using std::vector;

void displayRatings(const list<int>& playersRatings){
    for (list<int>::const_iterator it = playersRatings.begin(); it != playersRatings.end(); it++){
        std::cout << "Players rating: " << *it << std::endl;
    }
}

void insertPlayerIntoOrderedList(int newPlayerRating, list<int>& playersByRating){
    for (list<int>::iterator it = playersByRating.begin(); it != playersByRating.end(); it++){
        if(*it > newPlayerRating){
            playersByRating.insert(it, newPlayerRating);
            return;
        }
    }
    playersByRating.push_back(newPlayerRating);
}

//Operator Overloading(global function)
struct YoutubeChannel {
    string Name;
    int SubCount;

    YoutubeChannel(string name, int subCount){
        Name = name;
        SubCount = subCount;
    }
    bool operator==(const YoutubeChannel&channel) const{
        return this->Name == channel.Name;
    }
};
std::ostream& operator<<(std::ostream& COUT, YoutubeChannel& ytChannel){
    COUT<< "Name: " << ytChannel.Name << std::endl;
    COUT<< "Subs: " << ytChannel.SubCount << std::endl;
    return COUT;
}

struct MyCollection{
    list<YoutubeChannel>myChannels;

    void operator+=(YoutubeChannel& channel) {
        this->myChannels.push_back(channel);
    }
    void operator-=(YoutubeChannel& channel) {
        this->myChannels.remove(channel);
    }
};
std::ostream& operator<<(std::ostream& COUT, MyCollection& myCollection){
    for(YoutubeChannel ytChannel: myCollection.myChannels)
        COUT << ytChannel << std::endl;
    return COUT;
}

int main(void){
    YoutubeChannel yt1 = YoutubeChannel("CodeBeaty", 44500);
    YoutubeChannel yt2 = YoutubeChannel("Berkant", 3);
    std::cout << yt1 << yt2;
    operator<<(std::cout, yt1);

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;

    std::cout << myCollection;

    //normal lists
    list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(30);
    myList.erase(myList.begin()); // 30 just gone!
    
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++){
        std::cout << *it << std::endl;
    }

    list<int> allPlayers = {2,4,5,3,2,5,6,9,4,7,4};

    list<int> begginers;
    list<int> pros;

    for (list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++){
        int rating = *it;
        if(rating >= 1 && rating <=5)
            insertPlayerIntoOrderedList(rating, begginers);
        else if(rating >= 6 && rating <= 10)
            insertPlayerIntoOrderedList(rating, pros);
    }

    std::cout<< "Beginners: "<< std::endl;
    displayRatings(begginers);
    std::cout<< "Pros: "<< std::endl;
    displayRatings(pros);
    
    vector<string> svec;//Default initialization
    vector<string> svec2 (svec);
    vector<string> newSvec = svec;
    vector<string> svec {2,"ff"};
    vector<string> svec {22};
    svec.push_back("subscript");
    for(auto ch:svec)
        std::cout << ch <<" ";
        
    std::cin.get();
}