#include <iostream>
#include<typeinfo>
#include<vector>
#include "CardStack.h"

using namespace std;

int winner_func(vector<Card> beech, Card trump_card){
    Card winner;
    int winner_index;
    int j=1;
    for(auto i= beech.begin(); i != beech.end(); i++){
        if(i==beech.begin()){
            winner.face = i->face;
            winner.suit_name = i->suit_name;
            winner_index = j;
        }
        if(i->suit_name == winner.suit_name){
            if(i->face > winner.face){
                winner.face = i->face;
                winner.suit_name = i->suit_name;
                winner_index = j;
            }
        } else if (i->suit_name == trump_card.suit_name){
            winner.face = i->face;
            winner.suit_name = i->suit_name;
            winner_index = j;
        }
        j++;
    }
    return winner_index;
}

void judgement_round(int no_of_players, int kitne_cards, CardStack &full_deck, vector<CardStack> &player_deck){
    vector<int> card_judge;
    Card trump = full_deck.cards.back();
    full_deck.cards.pop_back();
    for(int i=1; i<= no_of_players; i++){
        int num;
        cout << "Player " << i << ": Enter your judgment:";
        cin >> num;
        while(num > kitne_cards && !isdigit(num)){
            cout << "Wrong input.\n";
            cout << "Player " << i << ": Enter your judgment:";
            cin >> num;
        }
        card_judge.push_back(num);
    }

    // yahan tak sabki judgement mil gyi
    for(int i=0; i<kitne_cards; i++){
        vector<Card> beech_ke_cards;
        for(int player_no = 1; player_no <= no_of_players; player_no++){
            int card_no;
            cout << "Player " <<  player_no << " your cards are:" << endl;
            player_deck[player_no].print_deck();
            cout << "Enter your choice:";
            cin >> card_no;
            while(card_no > player_deck[player_no].cards.size() && card_no <= 0 && !isdigit(card_no) ) {
                    cout << "Wrong input." << endl;
                    cout << "Enter your choice:";
                    cin >> card_no;
            }
            beech_ke_cards.push_back(player_deck[player_no].cards[card_no-1]);
            //player_deck[player_no].cards.erase(card_no-1);
        }

        int winner_player_no = winner_func(beech_ke_cards, trump);
        cout << "Winner of this round is : " << winner_player_no << endl;
    }
}




void judgement(int no_of_players,int max_card){
    vector<CardStack> player_deck;
    for(int i=0; i< no_of_players; i++){
        CardStack player;
        player_deck.push_back(player);
    }
    CardStack full_deck;
    full_deck.make_full_deck();
    for(int i=1; i<=max_card; i++){
        for(auto j=player_deck.begin(); j!= player_deck.end(); j++){
            j->deal(full_deck,i);
        }
        judgement_round(no_of_players,i, full_deck, player_deck);
    }

}




int main()
{
    int a,b;
    cout << "Enter No of Player";
    cin >> a;
    cout << "Max card:";
    cin >> b;
    judgement(a,b);
    cout << "Hello World!" << endl;
    return 0;
}
