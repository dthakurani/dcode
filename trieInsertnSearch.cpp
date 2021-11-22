#include <iostream>
#include <string>
using namespace std;
const int RANGE = 26;

struct trieNode {
	struct trieNode *childNodes[RANGE];
	bool isEndOfWord;
};

struct trieNode* getNode() {
	struct trieNode* tempNode = new trieNode;
	tempNode->isEndOfWord = false;
	for(int i = 0; i < RANGE; i++)
		tempNode->childNodes[i] = NULL;
	return tempNode;
} 

void trieInsert(struct trieNode* root, string word) {
	struct trieNode* tempRoot = root;

	for(int i = 0; i < word.length(); i++) {
		int index = word[i] - 'a';
		if(!tempRoot->childNodes[index])
			tempRoot->childNodes[index] = getNode();
		tempRoot = tempRoot->childNodes[index];
	}
	tempRoot->isEndOfWord = true;
}

int main() {
	string products[] = {"mobile","mouse","moneypot","monitor","mousepad"};
	int n = sizeof(products) / sizeof(products[0]);

	struct trieNode* root = getNode();
	for(int i = 0; i < n; i++) 
		trieInsert(root, products[i]);

	return 0;
}