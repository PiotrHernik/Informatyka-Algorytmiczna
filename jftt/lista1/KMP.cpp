#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <fstream>

class KMP
{
    public:
        KMP(std::string pattern, std::string text): pattern(pattern), text(text)
        {
            std::set<char> unique_chars(text.begin(), text.end());
            alphabet = std::string(unique_chars.begin(), unique_chars.end());
            std::sort(alphabet.begin(), alphabet.end());

            for(auto i = 0; i < alphabet.length(); i++)
            {
                placeInAlphabet.insert(std::make_pair(alphabet[i], i));
            }
            
        }

        void kmpMatcher()
{
    int n = text.length();
    int m = pattern.length();
    
    int* prefixFunction = computePrefixFunction(pattern);
    int q = 0;

    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = prefixFunction[q - 1];
        }

        if (pattern[q] == text[i])
        {
            q++;
        }

        if (q == m)
        {
            std::cout << "Pattern occurs with shift: " << i - m + 1 << std::endl;
            q = prefixFunction[q - 1];
        }
    }
    
    delete[] prefixFunction;
}
    private:
        std::string pattern;
        std::string text;
        std::string alphabet;
        std::map<char, int> placeInAlphabet;
        int* prefixFunction;

        int* computePrefixFunction(std::string pattern)
        {
            int m = pattern.length();
            int* prefixFunction = new int[m];
            prefixFunction[0] = 0;

            int k = 0;
            for (int q = 1; q < m; q++)
            {
                while (k > 0 && pattern[k] != pattern[q])
                {
                    k = prefixFunction[k - 1];
                }
                if (pattern[k] == pattern[q])
                {
                    k++;
                }
                prefixFunction[q] = k;
            }

            return prefixFunction;
        }
};

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout<<"wywołanie programu powinno wyglądać następująco: Fa.cpp <wzorzec> <nazwa pliku>"<<std::endl;
    }

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
    KMP kmp(pattern, text);
    kmp.kmpMatcher();

}