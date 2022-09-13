class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remaining = 0;
        // iterate each data and perform the following logic
        for (auto& x : data) {
            // case 1: there is no remaining segement left, 
            // then it means we should check the first segement of UTF-8 octet sequence
            // i.e. 0xxxxxxx (for no of. bytes = 1)
            // i.e. 110xxxxx (for no of. bytes = 2)
            // i.e. 1110xxxx (for no of. bytes = 3)
            // i.e. 11110xxx (for no of. bytes = 4)
            if (remaining == 0) {
                if ((x >> 5) == 0b110) {
                    // case 1.1 - shift `x` 5 bits to the right
                    // i.e making the first (8 - 5) = 3 bits left
                    // e.g (110xxxxx >> 5) becomes 110 (in binary format)
                    // if it is 0b110, 
                    // then it is only possible to form `110xxxxx 10xxxxxx` 
                    // so we set remaining to 1 to look for `10xxxxxx` later
                    remaining = 1;
                } else if ((x >> 4) == 0b1110) {
                    // case 1.2 -  shift `x` 4 bits to the right
                    // i.e making the first (8 - 4) = 4 bits left
                    // e.g (1110xxxx >> 4) becomes 1110 (in binary format)
                    // if it is 0b1110, 
                    // then it is only possible to form `1110xxxx 10xxxxxx 10xxxxxx`
                    // so we set remaining to 2 to look for `10xxxxxx 10xxxxxx` later
                     remaining = 2;
                } else if ((x >> 3) == 0b11110) {
                    // case 1.3 -  shift `x` 3 bits to the right
                    // i.e making the first (8 - 3) = 5 bits left
                    // e.g (11110xxx >> 5) becomes 11110 (in binary format)
                    // if it is 0b11110, 
                    // then it is only possible to form `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`
                    // so we set remaining to 3 to look for `10xxxxxx 10xxxxxx 10xxxxxx` later
                    remaining = 3;
                } else if ((x >> 7) != 0) {
                     // case 1.4 -  shift `x` 7 bits to the right
                    // i.e making the first (8 - 7) = 1 bit left
                    // e.g (0xxxxxxx >> 7) becomes 0 (in binary format)
                    // here we cover the last case which is when Number of Bytes = 1
                    // we need to make sure the first bit is 0
                    // otherwise, it is not valid
                    return false;
                }
            } else {
                // case 2: check 10xxxxxx
                // if we enter this part, that means it may be number of bytes 2, 3, or 4.
                // based on the table in problem statement, we know what's left is just `10xxxxxx`
                // therefore, we shift `x` 6 bits to the right
                // i.e making the first (8 - 6) = 2 bits left
                // e.g (10xxxxxx >> 6) becomes 10 (in binary format)
                // if the first 2 bits are not 10 (in binary format), then it is not valid
                if ((x >> 6) != 0b10) return false;
                // otherwise, this segement is ok so we decrease `remaining` by 1
                else remaining--;
            }
        }
        // at the end, remaining will be 0 if data can represent the octet sequence 
        return remaining == 0;
    }
};