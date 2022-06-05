#include<string>
using namespace std;
bool oneEditAway(string first, string second) {
    int lenFir = first.size();
    int lenSec = second.size();
    if (lenFir - lenSec == 1 || lenFir - lenSec == -1) {
        string longer = lenFir > lenSec ? first : second;
        string shorter = lenFir < lenSec ? first : second;
        int diff = 0;
        int iLong = 0, iShort = 0;
        while (iLong < longer.size() && iShort < shorter.size()) {
            if (diff > 1) {
                return false;
            }
            if (longer[iLong] != shorter[iShort]) {
                iLong++;
                diff++;
            }
            else {
                iLong++;
                iShort++;
            }
        }
        return diff <= 1 ? true : false;
    }
    else if (lenFir == lenSec) {
        int diff = 0;
        for (int i = 0; i < lenFir; i++) {
            if (diff > 1) {
                return false;
            }
            if (first[i] != second[i]) {
                diff++;
            }
        }
        return diff <= 1 ? true : false;
    }
    else {
        return false;
    }
}