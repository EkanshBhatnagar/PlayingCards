#ifndef CARDSTACK_H
#define CARDSTACK_H\

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include<algorithm>

using namespace std;

enum suit{hearts,spades,diamonds, clubs};



struct Card
{
    suit suit_name;
    int face; // 1-13

    Card(){
    }

    Card(suit suit_name, int face){
        this->face = face;
        this->suit_name = suit_name;
    }

    Card(const Card& c){
        this->face = c.face;
        this->suit_name = c.suit_name;
    }
};


class CardStack
{
    public:
        CardStack();
        virtual ~CardStack();

    protected:

    public:
        vector<Card> cards;

        void make_full_deck(){
            for(int i=1; i<=13; i++){
                //cout << i << " ";
                Card a(hearts, i) ;
                Card b(diamonds,i);
                Card c(clubs, i);
                Card d(spades, i);
                cards.push_back(c);
                cards.push_back(a);
                cards.push_back(b);
                cards.push_back(d);
            }
//            for(auto i=cards.begin(); i!=cards.end(); ++i){
//                cout << i->suit_name << " " << i->face<< endl;
//            }
        }

        string get_suit(suit x){
            switch(x){
                case 0: return "hearts";
                break;
        case 1: return "spades";
                break;
        case 2: return "diamonds";
                break;
        case 3: return "clubs";
                break;
    }
}

        void card_shuffle(){
            auto rng = default_random_engine {};
            std::shuffle(begin(cards), end(cards), rng);
        }

        void print_deck(){
             for(auto i=cards.begin(); i!=cards.end(); ++i){
                    cout << get_suit(i->suit_name) << " " << i->face<< endl;
            }
        }

        void deal(CardStack &full_deck, int num){
            for(int i = 0; i <num; i++){
                cards.push_back(full_deck.cards.back());
                full_deck.cards.pop_back();
            }
        }

};

#endif // CARDSTACK_H
