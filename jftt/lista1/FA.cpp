#include <iostream> 
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <fstream>

void finiteAutomationMatcher(std::string text, int paternLenght, int** moveFunction, std::map<char, int> placeInAlphabet)
{
    auto n = text.length();
    auto q = 0;
    for(auto i = 0; i < n; i++)
    {
        q = moveFunction[q][placeInAlphabet[text[i]]];
        if(q == paternLenght)
        {
            auto s = i + 1 - paternLenght;
            std::cout<<"Wzorzec występuje z przesunięciem: " << s << std::endl;
        }
    }
}

int** computeTransitionFunction(std::string pattern, std::string alphabet, std::map<char, int> placeInAlphabet)
{
    int patternLenght = pattern.length();
    int** moveFunction = new int*[pattern.length()+1];
    for(auto i = 0; i < pattern.length()+1; i++)
    {
        moveFunction[i] = new int[alphabet.length()];
    }
    for(auto q = 0; q <= patternLenght; q++)
    {
        for(auto a : alphabet)
        {
            auto k = std::min(patternLenght + 1, q + 2);
            int i = 0;
            do{

                --k;
                auto subPattern = pattern.substr(0, k);
                std::string subPatternAndChar;
                if(k != 0)
                {
                    subPatternAndChar = pattern.substr(i, k - 1) + a;
                }
                else
                {
                    subPatternAndChar = pattern.substr(i, 0);
                }
                
                // std::cout <<"k="<<k<<", subPattern: "<<subPattern<<", SubPatternAndChar: "<<subPatternAndChar<<std::endl;
                if(subPattern == subPatternAndChar)
                {
                    break;
                }
                ++i;
            }while(k > 0);
            moveFunction[q][placeInAlphabet[a]] = k;
        }
    }
    return moveFunction;

}


int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout<<"wywołanie programu powinno wyglądać następująco: Fa.cpp <wzorzec> <nazwa pliku>"<<std::endl;
    }

    // std::string text = "abababacaba";
    // std::string pattern = "ababaca";
    std::ifstream file(argv[2]);
    if (!file)
    {
        std::cerr << "Nie można otworzyć pliku: " << argv[2] << std::endl;
        return 1;
    }
    std::string text((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    file.close();
    std::string pattern = argv[1];

    std::set<char> unique_chars(text.begin(), text.end());
    std::string alphabet(unique_chars.begin(), unique_chars.end());
    std::sort(alphabet.begin(), alphabet.end());

    std::map<char, int> placeInAlphabet;
    for(auto i = 0; i < alphabet.length(); i++)
    {
        placeInAlphabet.insert(std::make_pair(alphabet[i], i));
    }

    auto moveFunction = computeTransitionFunction(pattern, alphabet, placeInAlphabet);
    // std::cout<<"          ";
    // for(auto a : alphabet)
    // {
    //     std::cout<<a<<"  ";
    // }
    // std::cout<<std::endl;
    // for(int i = 0; i < pattern.length(); i++)
    // {
    //     std::cout<<"State: " << i;
    //     for(int j = 0; j < alphabet.length(); j++)
    //     {
    //         std::cout<<"  " <<moveFunction[i][j];
    //     }
    //     std::cout<<std::endl;
    // }
    
    // std::cout<<"Miejsce znaku 'a': " <<placeInAlphabet['a']<<std::endl;

    // std::cout<<"Unikalne znaki: " << alphabet <<std::endl;
    std::cout<<"Text: " <<text <<std::endl;
    std::cout<<"Pattern: " <<pattern<<std::endl;

    finiteAutomationMatcher(text, pattern.length(), moveFunction, placeInAlphabet);


}