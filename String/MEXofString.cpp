//Shortest continous string not present in a string;
string mexStr(string S) {
    vector<string> strings = {""};
    while (true) {
        vector<string> nstrings;
        for (auto &str : strings)
            for (int c = 0; c < 26; c++) {
                string nstr = str + char('a' + c);
                nstrings.push_back(nstr); 
                if (S.find(nstr) == string::npos)
                    return nstr;
            } 
        strings.swap(nstrings);
    }
}
