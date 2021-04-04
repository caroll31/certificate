#include<iostream>

#define ALPHABET 26
#define WORD_MAX_NUM 25000
#define WORD_LENGTH 20
#define NOT_EXIST -1

void strcpy(char* dest, const char* src)
{
    int index = 0;    
    while(src[index] != '\0'){
        dest[index] = src[index];
        index++;
    }
    dest[index] ='\0';    
}

class Trie{
private:

    static unsigned int word_number;
    static bool word_ban_list[WORD_MAX_NUM];
    static unsigned int word_hit_count[WORD_MAX_NUM];
    static char word[WORD_MAX_NUM][WORD_LENGTH];

    Trie* children[ALPHABET];
    unsigned int word_id;
    unsigned short length;

    unsigned short char_to_num(char ch){
        return ch - 'a';
    }

public:
    Trie(int len){
        length = len;
        for (int i=0; i<ALPHABET; i++)
            children[i]=0;
    }

    void insert(const char *str, bool isBan){
        if(str[0] == '\0'){
            if(word_id == -1)
            {
                word_id = word_number++;
                strcpy(word[word_id], str);
                word_hit_count[word_id] = 0;
                word_ban_list[word_id] = isBan;
            }
            else word_hit_count[word_id]++;   

            return;
        }

        unsigned short n = char_to_num(str[0]);

        if(!children[n]){
            children[n] = new Trie(length + 1);
        }

        children[n]->insert(str + 1, isBan);
    }

    unsigned int find(const char *str, bool exceptBan){
        if(str[0] == '\0')
            return word_ban_list[word_id] ? NOT_EXIST : word_id;

        unsigned short n = char_to_num(str[0]);

        if(!children[n]){
            return NOT_EXIST;
        }
        else{
            return children[n]->find(str+1, exceptBan);
        }
    }

    void removeChildren()
    {
        for(int i;i<ALPHABET;i++)
        {
            if(!children[i])
            {
                children[i]->removeChildren();
                delete children[i];
            }
        }
    }

    static void init()
    {
        word_number = 0;
    }    
};

Trie* head = NULL;

void init()
{
    if(head){
        head->removeChildren();
        Trie::init();
    }
}

void inputWord(const char mInput[20])
{
    if(head)
        head = new Trie(0);
    head->insert(mInput, false);
}

int recommand(const char mUser[20])
{
    return 0;
}

void banWord(const char mUser[20])
{
    head->insert(mUser, true);
}