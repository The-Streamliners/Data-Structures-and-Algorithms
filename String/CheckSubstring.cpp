// To check if input string 's' can form given string 'k' after removal of some alphabets

string check(string s,string k)
{
    int l=k.size(),j=0;
    fob(i,0,s.size())
    {
        if(s[i]==k[j])j++;
        if(j==l)return "YES";
    }
    return "NO";
}
