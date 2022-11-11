#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/* Algoritihm
    1. Start loop, check to see if valid sequence
    2. Search for start codon and stop codon, set indexes
    3. Make string between the codons, return

    1. If invalid sequence, return "INVALID SEQUENCE"
    2. If no start codon, return ""
    3. If there is no stop codon, show entire sequence from start codon to end
*/
string dnaRead(vector<string> dna)
{
    bool found_start = false;
    bool found_end = false;
    int start_index = -1;
    int stop_index = -1;
    string output;

    for (int i = 0; i < dna.size(); i++)
    {
        string sequence = dna.at(i);

        // Check if valid strings in vectors and the start and stop indexes
        
        if (sequence.length() != 3)
        {
            return "Invalid sequence.";
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (sequence[j] != 'A' && sequence[j] != 'C' && sequence[j] != 'G' && sequence[j] != 'T')
                {
                    return "Invalid sequence.";
                }
            }

            if (sequence == "ATG" && found_start == false)
            {
                found_start = true;
                start_index = i;
            }

            if (sequence == "TAA" || sequence == "TAG" || sequence == "TGA" && found_end == false)
            {
                found_end = true;
                stop_index = i;
            }
        }
        if (found_end == true)
        {
            i = dna.size();
        }
    }

    // Check start and stop index have been found

    if (found_start == false)
    {
        return "";
    }
    else if (found_end == false)
    {
        for (int i = start_index + 1; i < dna.size(); i++)
        {
            output += dna.at(i);
        }
        return output;
    }
    else
    {
        for (int i = start_index + 1; i < stop_index; i++)
        {
            output += dna.at(i);
        }
        return output;
    }
}

int main()
{
    // Standard case
    vector<string> dna{"ATG", "TCA", "GCA", "TAC", "TGA"};
    assert(dnaRead(dna) == "TCAGCATAC");

    // Improper sequence
    vector<string> dna2{"ATG", "WCA", "GCA", "TAC", "TGA"};
    assert(dnaRead(dna2) == "Invalid sequence.");

    // Imporoper sequence 2
    vector<string> dna3{"ATG", "TC", "GCA", "TAC", "TGA"};
    assert(dnaRead(dna3) == "Invalid sequence.");

    // No start codon
    vector<string> dna4{"TCA", "TCA", "GCA", "TAC", "TGA"};
    assert(dnaRead(dna4) == "");

    // No stop codon
    vector<string> dna5{"ATG", "TCA", "GCA", "TAC", "GCA"};
    assert(dnaRead(dna5) == "TCAGCATACGCA");

    // Lowercase
    vector<string> dna6{"ATG", "gca", "GCA", "TAC", "TGA"};
    assert(dnaRead(dna6) == "Invalid sequence.");

    // Multiple stop codons
    vector<string> dna7{"ATG", "TCA", "TAG", "TAC", "TGA"};
    assert(dnaRead(dna7) == "TCA");

}