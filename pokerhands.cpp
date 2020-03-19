#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string converter(string);
void reader(string);
void sortcards();
void cardswap();
bool straight();
bool handflush(string);
bool pairs();
int ofakind();
int handrank(string);
int play(string, string);
int rankmatch(int, int);
int handcompare(int, int, int, int);
int card[5]={}, high=0, total=0;

int main(){
	int p1win=0, p2win=0, win=0;
	string hands, hand1, hand2;
	
	ifstream file("poker.txt");
	while(getline(file, hands)){
		hand1 = hands.substr(0, 14); // 14 char for hand #1 , 15 for 2
		hand2 = hands.substr(15, 14);
		win = play(hand1, hand2);
		if (win == 1)
			p1win++;
		else
			p2win++;
	}
	cout << "Player 1 wins: " << p1win << endl;
	cout << "Player 2 wins: " << p2win << endl;
}

// converts all T,J,Q,K,A into numbers, Ace is high
string converter(string hand){
	char figures[5] = {'T','J','Q','K','A'};
	string figurenumbers[5] = {"10","11","12","13","14"};
	for(int i = 0; i <= hand.length()-2; i++){
		for(int j = 0; j <= 4; j++){
			if(hand[i] == figures[j])
				hand.replace(i, 1, figurenumbers[j]);
		}
	}
	return hand;
}

// reads hand d,c,h,s are card suits
void reader(string hand){
	string split;
	int j = 0, index = 0;
	total=0;
	for(int i=0; i<= hand.length()-1; i++){
		if(hand[i] == ' ')
			continue;
		if(hand[i] == 'D' || hand[i] == 'C' || hand[i] == 'H' || hand[i] == 'S'){
			card[index] = j;
			split = "";
			index++;
			continue;
		}
		split += (to_string(hand[i]-'0'));
		j = stoi(split);
	}
	for(int i=0; i<=4; i++){
        if(card[i] > total)
        	total = card[i];
    }
}

void sortcards(){
	int temp=0;
	for(int i=0; i<=4; i++){
		for(int j=i+1; j<=4; j++){
			if(card[j]<card[i]){
				temp = card[i];
				card[i] = card[j];
				card[j] = temp;
			}
		}
	}
}

// if three of a kind, replace 3 repeating cards in card with zeros
// remaining non-zero cards can then be checked for additional pair for full house
void cardswap(){
	for(int i=0; i<=3; i++){
		if(card[i] == card[i+1] && card[i+1] == card[i+2]){
			card[i] = 0; 
			card[i+1] = 0;
			card[i+2] = 0;
		}
	}
}

// check if straight
bool straight(){
	for(int i=0; i<=2; i++){
		if(card[i] == card[i+1]-1)
			continue;
		else 
			return false;
	}
	if(card[3]==5 && card[4]==14)
		return true;
	else if(card[3] == card[4]-1)
		return true;
	else
		return false;
}

// removes everything but suits from hand to see if flush
bool handflush(string hand){
	string temp = hand;
	temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
	temp.erase(remove_if(temp.begin(), temp.end(), ::isdigit), temp.end());
	for(int i=0; i<=3; i++){
		if(temp[i] == temp[i+1])
			continue;
		else 
			return false;	
	}
	return true;
}

// check amount for 3 or 4 of a kind
int ofakind(){
	int count=0;
	for(int i=0; i<=2; i++){
		if(card[i]==card[i+1]&&card[i+1]==card[i+2])
			count++;
	}
	if(count == 2){
		high = card[1];
		return 4;
	} 
	else if(count == 1){
		high = card[2];
		cardswap();
		sortcards();
		return 3;
	}
	return 0;
}

// check for pairs
bool pairs(){
	int count=0;
	for(int i=0; i<=3; i++){
		if(card[i] == 0){
			count++;
			continue;
		}
		if(card[i] == card[i+1]){
			if(count < 3)
				high = card[i];
			card[i] = 0; 
			card[i+1] = 0;
			return true;
		}
	}
	return false;
}


int handrank(string hand){
	bool flush = handflush(hand);
	//check for straight, straight flush, royal flush
	if(straight()){
		if(flush){
			if(card[0] == 10)
				return 9;
			else
				return 8;
		}
		else
			return 4;
	} 
	//check for flush
	else if(flush)
		return 5;
	//check for 3 of a kind, 4 of a kind, full house
	int kind = ofakind();
	if(kind == 4)
		return 7;
	else if(kind == 3){
		if(pairs())
			return 6;
		else
			return 3;
	} 
	//check for 1 pair, 2 pairs
	else if(pairs()){
		if(pairs())
			return 2;
		else
			return 1;
	}
	//rank zero = anything else
	else
		return 0;
}

// fnc plays both hands
int play(string hand1, string hand2){
	int rank1=0, rank2=0, win=0, hc1=0, 
	total1=0, hc2=0, total2=0;
	
	hand1 = converter(hand1);
	reader(hand1);
	sortcards();
	rank1 = handrank(hand1);
	hc1 = high, total1 = total;
	
	hand2 = converter(hand2);
	reader(hand2);
	sortcards();
	rank2 = handrank(hand2);
	hc2 = high, total2 = total;
		
	win = rankmatch(rank1, rank2);
	if(win == 3){
		return handcompare(hc1, total1, hc2, total2);
	}
	else
		return win;
}

int rankmatch(int rank1, int rank2){
	if(rank1 > rank2)
		return 1;
	else if(rank2 > rank1)
		return 2;
	else
		return 3;
}

// if hands are the same, high card wins
int handcompare(int hc1, int total1, int hc2, int total2){
	if(hc1 > hc2)
		return 1;
	else if(hc2 > hc1)
		return 2;
	else {
		if(total1 > total2)
			return 1;
		else
			return 2;
	}
}
