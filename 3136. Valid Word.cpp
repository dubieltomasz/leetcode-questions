class Solution {
public:
    bool isValid(const std::string& word) {
        if(word.size() < 3) return false;

        char map[88], flags = 0;

        for(int i = 0; i < 13; ++i)
            map[i] = 4;
        for(int i = 13; i < 23; ++i)
            map[i] = 0;
        for(int i = 23; i < 30; ++i)
            map[i] = 4;
        for(int i = 30; i < 56; ++i)
            map[i] = 1;
        for(int i = 56; i < 62; ++i)
            map[i] = 4;
        for(int i = 62; i < 88; ++i)
            map[i] = 1;
        
        map['A'-35] = 2;
        map['a'-35] = 2;
        map['E'-35] = 2;
        map['e'-35] = 2;
        map['I'-35] = 2;
        map['i'-35] = 2;
        map['O'-35] = 2;
        map['o'-35] = 2;
        map['U'-35] = 2;
        map['u'-35] = 2;

        for(const char& character : word)
            flags |= map[character-35];
        
        return flags == 3;
    }
};
