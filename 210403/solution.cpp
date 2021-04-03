#define MAX_WORD_NUMBER 25000
#define MAX_WORD_LENGTH 20
#define ASCII_a 97
#define HASH_RANGE 26

#define NOT_EXIST -1

typedef struct _Word{
    unsigned int usedNum;
    char word[20];
    char status;
}Word;

Word wordList[MAX_WORD_NUMBER];
unsigned int wordIndex = 0;

unsigned short expectedList[MAX_WORD_NUMBER];
unsigned short expectedListIndex = 0;

unsigned short hashMap[MAX_WORD_LENGTH][HASH_RANGE][MAX_WORD_NUMBER];
int hashMapIndex[MAX_WORD_LENGTH][HASH_RANGE]={0,};



int strlen(const char str[])
{
    int ret = 0;
    while(str[ret])
        ret++;

    return ret;
}

void strcpy(char dest[20], const char src[20])
{
    int index = 0;
    while(src[index])
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = 0;
}

unsigned short findExactWordIndex(const char *word)
{
    return 0;
}

unsigned short findNextSameCharIndex(unsigned short prevWordIndex, unsigned short index, const char str[20], const unsigned short length)
{
    unsigned short result = -1;
    unsigned short loopCnt = length;

    //TO-DO 
    // implement exception case like start and end loop
    while(loopCnt)
    {
        if(loopCnt ==1)
        {
            
        }
        else
        {

        }        
    }
    return result;
}

char* getExpectedWordList()
{
    expectedListIndex = 0;
}

void init()
{
    for(int i = 0; i<MAX_WORD_LENGTH; i++){
        for(int j=0; j<HASH_RANGE; j++)
        {
            while(hashMapIndex[i][j])
            {
                hashMap[i][j][hashMapIndex[i][j]] = 0;
                hashMapIndex[i][j]--;
            }
        }
    }

    wordIndex = 0;
}

void inputWord(const char mInput[20])
{
    //TO-DO 
    // implement logic to check already exist or not

    unsigned short wordIndex = NOT_EXIST;
    wordIndex = findExactWordIndex(mInput);

    if(wordIndex != NOT_EXIST)
    {
        wordList[wordIndex].usedNum++;
    }
    else
    {
        unsigned short length = strlen(mInput);

        wordList[wordIndex].status = 'a';
        wordList[wordIndex].usedNum = 1;
        strcpy(wordList[wordIndex].word, mInput);

        unsigned short hashValue;
        while(length)
        {
            hashValue = (unsigned short)mInput[length-1] - ASCII_a;
            hashMap[length-1][hashValue][hashMapIndex[length-1][hashValue]++] = wordIndex;        
            length--;
        }
        wordIndex++;
    }    
}

int recommand(const char mUser[20])
{
    return 0;
}
void banWord(const char mUser[20])
{
    unsigned short index = findExactWordIndex(mUser);
    wordList[index].status = 'b';
}
